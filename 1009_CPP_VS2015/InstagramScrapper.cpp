#include "InstagramScrapper.h"


INSTAGRAM_NAMESPACE_START
InstagramScrapper::InstagramScrapper()
	:cookieFileName(FileUtility::getCurrentWorkingDirectory()+"\\tmp\\instagram_cookies.txt"),
	tempHashTagFile(FileUtility::getCurrentWorkingDirectory()+"\\tmp\\tmp_instagram_hashtags.txt"),
	tempProfileFile(FileUtility::getCurrentWorkingDirectory()+"\\tmp\\tmp_instagram_profiles.txt")
{
	this->bridge = BridgePtr(new ICT1009::WebScrapping::Bridge());
}
InstagramScrapper::~InstagramScrapper()
{	
	//Smart pointer does the job for us.
}

int InstagramScrapper::scrapeByHashTags(const std::string username, const std::string password,
	const std::string joinedHashTags, const double numberOfPosts, const std::string savePath) {
	using json = nlohmann::json;

	using ICT1009::DataStorage::ScrapeStorage;
	using ICT1009::DataStorage::SocialMediaPostStorage;
	using ICT1009::DataStorage::InstagramPost;
	using ICT1009::DataStorage::SocialMediaPost;
	using ICT1009::DataStorage::SocialMediaComment;

	using ICT1009::WebScrapping::Bridge;
	using std::cout; using std::endl;

	using std::string; using std::remove;
	remove(this->tempHashTagFile.c_str());
	
	const string mode = "instagram_hashtag";
	const string params = mode + " " + username + " " + password + " " +
		joinedHashTags + " " + std::to_string(numberOfPosts);

	std::cout << "Params: " << params << std::endl;
	int res =  this->bridge->executeScript("webbrowser.py", params);
	/*
		-1 Failed to execute script
		-2 Failed to retrieve instagram response file
	*/

	if (res != 0)
		return -1;
	if (!FileUtility::fileExists(this->tempHashTagFile))
		return -2;

	std::ifstream i(this->tempHashTagFile);
	//Parse into JSON object
	json j;	i >> j;

	typedef std::shared_ptr<ScrapeStorage> ScrapeStoragePtr;
	ScrapeStoragePtr storage(new ScrapeStorage);

	typedef std::shared_ptr<SocialMediaPostStorage> SocialMediaPostStoragePtr;
	SocialMediaPostStoragePtr hashTags(new SocialMediaPostStorage);

	typedef std::shared_ptr<InstagramPost> InstagramPostPtr;
	InstagramPostPtr instagramPost(new InstagramPost);

	storage->setMode(ScrapeStorage::ScrapeMode::Hashtag);
	storage->setScrapePlatform(ScrapeStorage::Platform::Instagram);

	for (auto &detail : j["details"]) {
		hashTags = SocialMediaPostStoragePtr(new SocialMediaPostStorage());
		hashTags->setScrapeTarget(detail["hash_tag"].get<string>());
		hashTags->setTargetVisibility(detail["hash_tag_is_valid"].get<string>());

		if (hashTags->getTargetVisibility() != "valid")
			goto nextiteration;


		hashTags->setPostsCount(detail["total_posts"].get<int>());	//change to total_posts

		for (auto &post : detail["extracted_posts"]) {
			//cout << "\n\n" << endl;
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
			hashTags->addPost(instagramPost);
		}
nextiteration:
		storage->addDetails(hashTags);
	}

	//cout << "Printing JSON details: \n\n" << endl;
	//cout << storage->getJsonString() << endl;

	//Add error checks later...
	storage->saveToFile(savePath);

	return 1;
}

/*-----------------------------------------------------------------*/

int InstagramScrapper::scrapeByProfiles(const std::string username, const std::string password,
	const std::string joinedProfiles, const int numberOfPosts, const std::string savePath) {

	std::cout << this->cookieFileName << std::endl;
	std::cout << this->tempProfileFile << std::endl;
	
	using json = nlohmann::json;
	
	using ICT1009::DataStorage::ScrapeStorage;
	using ICT1009::DataStorage::SocialMediaPostStorage;
	using ICT1009::DataStorage::InstagramPost;
	using ICT1009::DataStorage::SocialMediaPost;
	using ICT1009::DataStorage::SocialMediaComment;

	using ICT1009::WebScrapping::Bridge;
	using std::cout; using std::endl;
	using std::string; using std::remove;
	
	//string cwd = FileUtility::getCurrentWorkingDirectory();
	remove(this->tempProfileFile.c_str());

	Bridge bridge;
	const string mode = "instagram_profile";
	const string params = mode + " " + username + " " + password + " " +
		joinedProfiles + " " + std::to_string(numberOfPosts);

	//Need to modify python script to accept parameters (Username, password, profile names and number of posts

	int res =  bridge.executeScript("webbrowser.py", params);
	//	-1 Failed to execute script
	//	-2 Failed to retrieve instagram response file
	
	if (res != 0) 
		return -1;
	if (!FileUtility::fileExists(this->tempProfileFile))
		return -2;
	
	std::ifstream i(this->tempProfileFile); 
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
	
	storage->setMode(ScrapeStorage::Profile);
	storage->setScrapePlatform(ScrapeStorage::Instagram);
	
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
	return 1;
}
INSTAGRAM_NAMESPACE_END
