import sys
import os
import time
import json
import requests
import re
import collections
from datetime import datetime
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
from selenium.common.exceptions import TimeoutException


class RequestParser:
	JS_ENTRY_DIR				= "entry_data/PostPage/0/"

	JS_ADD_NUM_OF_LIKES 		= "graphql/shortcode_media/edge_media_preview_like/count"	
	JS_ADD_IS_VIDEO 			= "graphql/shortcode_media/is_video"	
	JS_ADD_NUM_OF_VIDEO_VIEWS 	= "graphql/shortcode_media/video_view_count"	
	JS_ADD_NUM_OF_COMMENTS 		= "graphql/shortcode_media/edge_media_to_parent_comment/count"	
	JS_ADD_VIDEO_URL 			= "graphql/shortcode_media/video_url"	
	JS_ADD_IMAGE_DISPLAY_URL	= "graphql/shortcode_media/display_url"
	JS_ADD_CAPTION 				= "graphql/shortcode_media/edge_media_to_caption/edges/0/node/text"
	JS_ADD_TIMESTAMP 			= "graphql/shortcode_media/taken_at_timestamp" 		
	JS_ADD_LOCATION 			= "graphql/shortcode_media/location/name"	

	JS_NUM_OF_LIKES 		= JS_ENTRY_DIR + JS_ADD_NUM_OF_LIKES
	JS_IS_VIDEO 			= JS_ENTRY_DIR + JS_ADD_IS_VIDEO
	JS_NUM_OF_VIDEO_VIEWS 	= JS_ENTRY_DIR + JS_ADD_NUM_OF_VIDEO_VIEWS	
	JS_NUM_OF_COMMENTS 		= JS_ENTRY_DIR + JS_ADD_NUM_OF_COMMENTS
	JS_VIDEO_URL 			= JS_ENTRY_DIR + JS_ADD_VIDEO_URL
	JS_IMAGE_DISPLAY_URL	= JS_ENTRY_DIR + JS_ADD_IMAGE_DISPLAY_URL
	JS_CAPTION 				= JS_ENTRY_DIR + JS_ADD_CAPTION
	JS_TIMESTAMP 			= JS_ENTRY_DIR + JS_ADD_TIMESTAMP
	JS_LOCATION 			= JS_ENTRY_DIR + JS_ADD_LOCATION	

	RET_EMPTY_STRING		= "None"
	RET_INVALID_NUMBER		= 0

	REGEX_WIN_DATA = r'window\._sharedData = (.*);</script>'
	REGEX_WIN_ADD_DATA = r'window.__additionalDataLoaded(.*)(\{\"graphql.*)\);</script>'

	DATE_TIME_FORMAT = "yyyy-MM-dd'T'HH:mm:ss.SSS'Z'"

	def __init__(self, selenium_cookies):
		self.s = requests.Session()
		for cookie in selenium_cookies:
			self.s.cookies.set(cookie['name'], cookie['value'])

	def get_json_element(self, json_object, keys):
		if not len(keys) > 0:
			return None
		index = int(keys[0]) if keys[0].isdigit() else str(keys[0])

		if len(keys) == 1:
			try:
				return json_object[index]
			except Exception as e:
				return None
		else:
			try:
				return self.get_json_element(json_object[index], keys[1:])
			except Exception as e:
				return None


	def get_post_dict(self, url):
		try:
			html_response = self.s.get(url).text
		except requests.exceptions.HTTPError as err:
			return {}
		win_data = re.search(self.REGEX_WIN_DATA, html_response).group(1)
		win_add_data = re.search(self.REGEX_WIN_ADD_DATA, html_response).group(2)

		J = json.loads(win_data)
		J2 = json.loads(win_add_data)

		caption = self.get_json_element(J, self.JS_CAPTION.split("/"))
		display_image_url = self.get_json_element(J, self.JS_IMAGE_DISPLAY_URL.split("/"))
		no_of_likes = self.get_json_element(J, self.JS_NUM_OF_LIKES.split("/"))
		no_of_comments = self.get_json_element(J, self.JS_NUM_OF_COMMENTS.split("/"))
		is_video = self.get_json_element(J, self.JS_IS_VIDEO.split("/"))
		no_of_video_views = self.get_json_element(J, self.JS_NUM_OF_VIDEO_VIEWS.split("/"))
		date_time = self.get_json_element(J, self.JS_TIMESTAMP.split("/"))
		location = self.get_json_element(J, self.JS_LOCATION.split("/"))

		if caption is None: 
			caption = self.get_json_element(J2, self.JS_ADD_CAPTION.split("/"))
		if display_image_url is None:
			display_image_url = self.get_json_element(J2, self.JS_ADD_IMAGE_DISPLAY_URL.split("/"))
		if no_of_likes is None: 
			no_of_likes = self.get_json_element(J2, self.JS_ADD_NUM_OF_LIKES.split("/"))
		if no_of_comments is None: 
			no_of_comments = self.get_json_element(J2, self.JS_ADD_NUM_OF_COMMENTS.split("/"))
		if is_video is None: 
			is_video = self.get_json_element(J2, self.JS_ADD_IS_VIDEO.split("/"))
		if no_of_video_views is None: 
			no_of_video_views = self.get_json_element(J2, self.JS_ADD_NUM_OF_VIDEO_VIEWS.split("/"))
		if date_time is None: 
			date_time = self.get_json_element(J2, self.JS_ADD_TIMESTAMP.split("/"))
		if location is None: 
			location = self.get_json_element(J2, self.JS_ADD_LOCATION.split("/"))


		caption = self.RET_EMPTY_STRING if caption is None else caption
		display_image_url = self.RET_EMPTY_STRING if display_image_url is None else display_image_url
		no_of_likes = self.RET_INVALID_NUMBER if no_of_likes is None else int(no_of_likes)
		no_of_comments = self.RET_INVALID_NUMBER if no_of_comments is None else int(no_of_comments)
		is_video = self.RET_EMPTY_STRING if is_video is None else is_video
		no_of_video_views = self.RET_INVALID_NUMBER if no_of_video_views is None else no_of_video_views
		date_time = self.RET_INVALID_NUMBER if date_time is None else datetime.fromtimestamp(date_time).strftime("%Y-%m-%dT%H:%M:%S.%f%Z")
		location = self.RET_EMPTY_STRING if location is None else location

		return { 
			"caption":caption,
			"post_url":url,
			"display_image_url":display_image_url,
			"no_of_likes":no_of_likes,
			"no_of_comments":no_of_comments,
			"is_video":is_video,
			"no_of_video_views":no_of_video_views,
			"date_time":date_time,
			"location":location
		}


class WebDriver:
	GECKO_PATH = os.getcwd()+"\\geckodriver.exe"
	COOKIE_FILE = os.getcwd()+"\\instagram_cookies.txt"

	URL_INSTAGRAM_HOME 	= "https://www.instagram.com/"
	URL_INSTAGRAM_LOGIN = "https://www.instagram.com/accounts/login/"

	URL_INSTAGRAM_HASHTAG = URL_INSTAGRAM_HOME+"explore/tags/"

	CSS_LOGIN_USERNAME 	= ".HmktE input[name='username']"
	CSS_LOGIN_PASSWORD 	= ".HmktE input[name='password']"
	CSS_LOGIN_SUBMIT 	= ".HmktE button[type='submit']"
	CSS_VALID_PAGE_DIV 	= "div[id='react-root']"
	CSS_PRIVATE			= ".rkEop"

	CSS_PROFILE_DESCRIPTION	= "div[class='-vDIg']"
	CSS_PAGE_DETAILS 		= "span[class='g47SY ']"

	CSS_PROFILE_POSTS_SUB_URL 	= ".ySN3v a[href]"
	CSS_HASHTAG_POSTS_SUB_URL 	= ".KC1QD a[href]"


	TIMEOUT_ELEMENT	 = 5
	TIMEOUT_PAGE	 = 10
	TIMEOUT_REDIRECT = 10

	TMP_SAVE_PROFILE = os.getcwd()+"\\tmp\\tmp_instagram_profiles.txt"
	TMP_SAVE_HASHTAGS = os.getcwd()+"\\tmp\\tmp_instagram_hashtags.txt"

	COOKIES_SAVE_PATH = os.getcwd()+"\\tmp\\instagram_cookies.txt" 

	def __init__(self):
		self._open = True
		self.driver = webdriver.Firefox(executable_path=self.GECKO_PATH)
	
	def _safe_get_web_element(self, css_selector, time_out):
		try:
			WebDriverWait(self.driver, time_out).until(EC.presence_of_element_located((By.CSS_SELECTOR, css_selector)))
			return self.driver.find_element(By.CSS_SELECTOR, css_selector)
		except TimeoutException as e:
			return None

	def _safe_get_web_elements(self, css_selector, time_out):
		try:
			WebDriverWait(self.driver, time_out).until(EC.presence_of_element_located((By.CSS_SELECTOR, css_selector)))
			return self.driver.find_elements(By.CSS_SELECTOR, css_selector)
		except TimeoutException as e:
			return None

	def _selector_exists(self, css_selector):
		elements = self.driver.find_elements(By.CSS_SELECTOR, css_selector)
		return len(elements) != 0

	def _page_is_available(self, url):
		try:
			w_username = WebDriverWait(self.driver, self.TIMEOUT_PAGE).until(EC.presence_of_element_located((By.CSS_SELECTOR, self.CSS_VALID_PAGE_DIV)))
			return True
		except TimeoutException as e:
			return False
	def _profile_is_private(self, url):
		return self._page_is_available(url) and self._selector_exists(self.CSS_PRIVATE)

	def _scroll_to_page_bottom(self):
		self.driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")

	#######################################################################################################
	#
	#			private functions above					
	#			
	#######################################################################################################


	def get_profile_description(self):
		element = self._safe_get_web_element(self.CSS_PROFILE_DESCRIPTION, self.TIMEOUT_ELEMENT)
		if element is None:
			return "None"
		else:
			return element.text

	def get_number_of_posts_in_profile(self):
		elements = self._safe_get_web_elements(self.CSS_PAGE_DETAILS, self.TIMEOUT_ELEMENT)
		if elements is None:
			return 0
		else:
			ret = elements[0].text.replace(",","")
			if ret == "":
				return 0
			else:
				return int(ret)
			

	def get_number_of_followers_in_profile(self):
		elements = self._safe_get_web_elements(self.CSS_PAGE_DETAILS, self.TIMEOUT_ELEMENT)
		if elements is None:
			return 0
		else:
			ret = elements[1].get_attribute("title").replace(",","")
			if ret == "":
				return 0
			else:
				return int(ret)

	def get_number_of_following_in_profile(self):
		elements = self._safe_get_web_elements(self.CSS_PAGE_DETAILS, self.TIMEOUT_ELEMENT)
		if elements is None:
			return 0
		else:
			ret = elements[2].text.replace(",","")
			if ret == "":
				return 0
			else:
				return int(ret)
		
	def get_number_of_posts_in_hashtag(self):
		element  = self._safe_get_web_element(self.CSS_PAGE_DETAILS, self.TIMEOUT_ELEMENT)
		if element is None:
			return 0
		else:
			return int(element.text.replace(",", ""))



	def login_instagram(self, username, password):
		self.driver.get(self.URL_INSTAGRAM_LOGIN)

		try:
			w_username = WebDriverWait(self.driver, self.TIMEOUT_ELEMENT).until(EC.presence_of_element_located((By.CSS_SELECTOR, self.CSS_LOGIN_USERNAME)))
			w_password = WebDriverWait(self.driver, self.TIMEOUT_ELEMENT).until(EC.presence_of_element_located((By.CSS_SELECTOR, self.CSS_LOGIN_PASSWORD)))
			w_submit = WebDriverWait(self.driver, self.TIMEOUT_ELEMENT).until(EC.presence_of_element_located((By.CSS_SELECTOR, self.CSS_LOGIN_SUBMIT)))
		except TimeoutException as e:
			raise e

		e_username = self.driver.find_element_by_css_selector(self.CSS_LOGIN_USERNAME)
		e_password = self.driver.find_element_by_css_selector(self.CSS_LOGIN_PASSWORD)
		e_submit = self.driver.find_element_by_css_selector(self.CSS_LOGIN_SUBMIT)

		e_username.send_keys(username)
		e_password.send_keys(password)
		e_submit.click()

		try:
			w_redirect = WebDriverWait(self.driver, self.TIMEOUT_REDIRECT).until(EC.url_to_be(self.URL_INSTAGRAM_HOME))
		except TimeoutException as e:
			raise e

		self._is_logined = True

	def save_credentials_cookies(self):
		cookies_list = self.driver.get_cookies()
		cookies_dict = dict((cookie['name'],cookie['value']) for cookie in cookies_list)
		save_string = '; '.join(str(k+"="+v) for k, v in cookies_dict.items())+";"
		with open(self.COOKIES_SAVE_PATH, 'w') as writer:
			writer.write(save_string)


	def get_posts_url(self, post_cap, css_selector):
		# sub_urls = OrderedSet()
		sub_urls = {}
		url_count = post_cap if post_cap < int(self.get_number_of_posts_in_profile()) else int(self.get_number_of_posts_in_profile())
		while (len(sub_urls) < url_count):
			elements = self.driver.find_elements(By.CSS_SELECTOR, css_selector)
			soup = BeautifulSoup(self.driver.page_source, 'html.parser')
			elements = soup.select(css_selector)
			for element in elements:
				sub_urls[element['href']] = None
			self._scroll_to_page_bottom()
		return {x for i, x in enumerate(sub_urls.keys()) if i < url_count}


	def scrape_hashtags_suburls(self, username, password, joined_hashtags, post_cap):
		try:
			self.login_instagram(username, password)
		except Exception as e:
			return "Unable to login."

		time.sleep(1)

		# Layer1 
		hashtags = { "scrape_mode":"hashtags", "platform":"instagram", "details": []}

		parser = RequestParser(self.driver.get_cookies())

		for hashtag in joined_hashtags.split(";"):
			hashtag_url = self.URL_INSTAGRAM_HASHTAG + hashtag + "/"

			self.driver.get(hashtag_url)

			h_details = {}
			

			if (not self._page_is_available(hashtag_url)):
				h_details['hash_tag_is_valid'] = "invalid"
				hashtags['details'].append(h_details)
				continue
			else:
				h_details['hash_tag_is_valid'] = "valid"

			# Layer 2
			h_details['hash_tag'] = hashtag
			h_details['total_posts'] = int(self.get_number_of_posts_in_hashtag())
			h_details['extracted_posts'] = []

			print("Post cap before in: ", post_cap)
			
			posts_urls = self.get_posts_url(post_cap, self.CSS_HASHTAG_POSTS_SUB_URL)

			for url in posts_urls:
				h_details['extracted_posts'].append(
					parser.get_post_dict(str(self.URL_INSTAGRAM_HOME[:-1])+str(url))
					)

			hashtags['details'].append(h_details)

		with open(self.TMP_SAVE_HASHTAGS, 'w', encoding='utf-8') as outfile:
			json.dump(hashtags, outfile, ensure_ascii=False)

		print("done")
			# Layer 3
			# p_details["display_image_url"] = something
			# p_details["posted_by"] = something
			# p_details["no_of_comments"] = something
			# p_details["location"] = something
			# p_details["date_time"] = something

			
			# System.out.println("Putting number of likes");
			# if (likes > -1) {
			# 	post.put("no_of_likes", likes);
			# 	post.put("no_of_views", 0
			# 	post.put("type", "image")
			
			# else {
			# 	double numberOfViews = this.getNumberOfViewsInPost();
			# 	post.put("no_of_likes", 0);
			# 	post.put("no_of_views", numberOfViews)
			# 	post.put("type", "video")









	def scrape_profiles_suburls(self, username, password, joined_profiles, post_cap):		
		try:
			self.login_instagram(username, password)
		except Exception as e:
			return "Unable to login."

		time.sleep(1)
		# self.driver.get(self.URL_INSTAGRAM_HOME)
		profiles = { "scrape_mode":"profiles", "platform":"instagram", "details": []}

		parser = RequestParser(self.driver.get_cookies())

		for profile in joined_profiles.split(";"):			
			profile_url = self.URL_INSTAGRAM_HOME + profile + "/"
			self.driver.get(profile_url)

			p_details = {}

			p_details['profile_name'] = profile

			if (not self._page_is_available(profile_url)):
				p_details['profile_is_viewable'] = "unavailable"
				profiles['details'].append(p_details)
				continue
			elif (self._profile_is_private(profile_url)):
				p_details['profile_is_viewable'] = "private"
				profiles['details'].append(p_details)
				continue
			else:
				p_details['profile_is_viewable'] = "viewable"


			p_details['profile_description'] = self.get_profile_description()
			p_details['no_of_posts'] = int(self.get_number_of_posts_in_profile())
			p_details['no_of_followers'] = int(self.get_number_of_followers_in_profile())
			p_details['no_of_following'] = int(self.get_number_of_following_in_profile())

			p_sub_urls = self.get_posts_url(post_cap, self.CSS_PROFILE_POSTS_SUB_URL)
			# p_details['extracted_posts'] = [{'url':self.URL_INSTAGRAM_HOME + url} for url in p_sub_urls]
			p_details['extracted_posts'] = []
			for url in p_sub_urls:
				p_details['extracted_posts'].append(
					parser.get_post_dict(str(self.URL_INSTAGRAM_HOME[:-1])+str(url))
					)
			profiles['details'].append(p_details)

		with open(self.TMP_SAVE_PROFILE, 'w', encoding='utf-8') as outfile:
			json.dump(profiles, outfile, ensure_ascii=False)



	@property
	def logined(self): 
	    try:
	    	return self._is_logined
	    except NameError:
	    	return False   


	def _quit(self):
		if self._open:
			pid = self.driver.service.process.pid
			self.driver.quit()
			try:
				os.kill(pid, signal.SIGTERM)
			except Exception as e:
				pass
			self._open = False



	def __exit__(self, type, value, traceback):
		self._quit()

	def __del__(self):
		self._quit()


if __name__ == '__main__':
	
	# Use arg[0] and arg[1] ltr on 
	# 0 username
	# 1 password
	# 2 number of posts
	
	start = WebDriver()

	# try: 
	# 	start.scrape_profiles_suburls("hehebongesher", "Password12345", "realdonaldtrump;hehebongesh;niggascrack", 4)
	# except Exception as e:
	# 	raise e
	

	# try:
	# 	start.scrape_hashtags_suburls("hehebongesher", "Password12345", "wuhan", 4)
	# except Exception as e:
	# 	print(e)


	mode = sys.argv[1]
	if (mode == "instagram_profile" and (len(sys.argv)-2) >= 4):
		try:
			username, password, profiles, posts_cap = sys.argv[2], sys.argv[3], sys.argv[4], float(sys.argv[5])
			start.scrape_profiles_suburls(username, password, profiles, float(posts_cap))
		except Exception as e:
			print(e)
	elif (mode == "instagram_hashtag" and (len(sys.argv)-2) >= 4):
		try:
			username, password, hashtags, posts_cap =  sys.argv[2], sys.argv[3], sys.argv[4], float(sys.argv[5])
			start.scrape_hashtags_suburls(username, password, hashtags, float(posts_cap))
		except Exception as e:
			print(e)
	else:
		print("Invalid number of parameters")



	# start.login_instagram("hehebongesh", "Password12345")
	start.save_credentials_cookies()
	# del(start)



	
