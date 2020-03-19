#include "InstagramScrapper.h"

#ifndef INSTAGRAM_SCRAPPER_CPP
#define INSTAGRAM_SCRAPPER_CPP
INSTAGRAM_NAMESPACE_START


InstagramScrapper::InstagramScrapper()
	:cookieFileName(FileUtility::getCurrentWorkingDirectory()+"\\tmp\\instagram_cookies.txt"),
	profileTempFile(FileUtility::getCurrentWorkingDirectory()+"\\tmp\\tmp_instagram_profiles.txt")
{
}
InstagramScrapper::~InstagramScrapper()
{	

}

int InstagramScrapper::scrapeByProfiles(const std::string username, const std::string password,
	const std::string joinedProfiles, const int numberOfposts, const std::string savePath) {

	std::cout << this->cookieFileName << std::endl;
	std::cout << this->profileTempFile << std::endl;
	
	using json = nlohmann::json;
	
	using ICT1009::DataStorage::ScrapeStorage;
	using ICT1009::DataStorage::SocialMediaPostStorage;
	using ICT1009::DataStorage::InstagramPost;
	using ICT1009::DataStorage::SocialMediaPost;
	using ICT1009::DataStorage::SocialMediaComment;
	

	using ICT1009::WebScrapping::Bridge;
	using std::cout; using std::endl;
	using std::string; using std::remove;
	
	string cwd = FileUtility::getCurrentWorkingDirectory();
	remove(this->profileTempFile.c_str());

	Bridge bridge;
	const string mode = "instagram_profile";
	const string params = mode + " " + username + " " + password + " " +
		joinedProfiles + " " + std::to_string(numberOfposts);

	//Need to modify python script to accept parameters (Username, password, profile names and number of posts
	cout << "Executing script." << endl;
	int res =  bridge.executeScript("webbrowser.py", params);
	cout << "Res : " << res << endl;

	//	-1 Failed to execute script
	//	-2 Failed to retrieve instagram response file
	
	if (res != 0) 
		return -1;
	if (!FileUtility::fileExists(this->profileTempFile)) 
		return -2;
	
	std::ifstream i(this->profileTempFile); 
	//Parse into JSON object
	json j;	i >> j;

	typedef std::shared_ptr<ScrapeStorage> ScrapeStoragePtr;
	ScrapeStoragePtr storage(new ScrapeStorage);

	typedef std::shared_ptr<SocialMediaPostStorage> SocialMediaPostStoragePtr;
	SocialMediaPostStoragePtr profile(new SocialMediaPostStorage);

	typedef std::shared_ptr<InstagramPost> InstagramPostPtr;
	InstagramPostPtr instagramPost(new InstagramPost);

	//Profile mode wont scrape comments
	/*typedef std::shared_ptr<SocialMediaComment> SocialMediaCommentPtr;
	SocialMediaCommentPtr comment(new SocialMediaComment);*/

	storage->setMode(ScrapeStorage::PROFILE);
	storage->setScrapePlatform(ScrapeStorage::INSTAGRAM);
	
	for (auto &detail : j["details"]) {
		profile = SocialMediaPostStoragePtr(new SocialMediaPostStorage());
		profile->setScrapeTarget(detail["profile_name"].get<string>());
		profile->setTargetVisibility(detail["profile_is_viewable"].get<string>());

		if (profile->getTargetVisibility() != "viewable")
			goto nextiteration;	
		
		profile->setTargetDescription(detail["profile_description"].get<string>());
		profile->setPostsCount(detail["no_of_posts"].get<int>());
		profile->setFollowersCount(detail["no_of_followers"].get<int>());
		profile->setFollowingCount(detail["no_of_following"].get<int>());

		for (auto &post : detail["extracted_posts"]) {
			cout << "\n\n" << endl;
			instagramPost = InstagramPostPtr(new InstagramPost());
			instagramPost->setCaption(post["caption"].get<string>());
			instagramPost->setPostUrl(post["post_url"].get<string>());
			instagramPost->setImageUrl(post["display_image_url"].get<string>());
			instagramPost->setLikes(post["no_of_likes"].get<int>());
			instagramPost->setCommentsCount(post["no_of_comments"].get<int>());
			instagramPost->setType(post["is_video"].get<bool>() 
				? InstagramPost::PostType::VIDEO
				: InstagramPost::PostType::IMAGE);
			instagramPost->setTimeStamp(post["date_time"].get<string>());
			instagramPost->setLocation(post["location"].get<string>());	
			
			//instagramPost->printAttributes();
			profile->addPost(instagramPost);			
		}
nextiteration:
		storage->addDetails(profile);
	}
	
	cout << "Printing JSON details: \n\n" << endl;
	cout << storage->getJsonString() << endl;
	//Add error checks later...
	storage->saveToFile(savePath);
	return 0;
}

INSTAGRAM_NAMESPACE_END

#endif