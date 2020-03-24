#include "ScrapeStorage.h"

SCRAPE_STORAGE_NAMESPACE_START

using json = nlohmann::json;
using ICT1009::Utility::FileUtility;
using std::remove;

ScrapeStorage::ScrapeStorage()
{

}

//Load from a json file
ScrapeStorage::ScrapeStorage(string filePath)
{
	if (!FileUtility::fileExists(filePath))
		throw std::exception(("File: " + filePath + " does not exists").c_str());

	json jsonObject;
	try
	{
		std::ifstream i(filePath);  
		i >> jsonObject; i.close();
	}
	catch (...)
	{
		std::cout << "Error loading file" << std::endl;
	}


	//Set platform and scrape modee
	std::string platform = jsonObject["platform"].get<std::string>();
	scrapePlatform = platform == "twitter" ? Platform::Twitter : Platform::Instagram;
	std::string scrapeMode = jsonObject["scrape_mode"].get<std::string>();
	mode = scrapeMode == "hashtags" ? ScrapeMode::Hashtag : ScrapeMode::Profile;


	std::string scrapeTargetStr = scrapeMode == "hashtags" ? "hash_tag" : "profile_name";
	typedef std::shared_ptr<SocialMediaPost> SocialMediaPostPtr;

	for (auto &detail : jsonObject["details"]) 
	{
		SocialMediaPostStoragePtr postStorage(new SocialMediaPostStorage);
		postStorage.get()->setScrapeTarget(detail[scrapeTargetStr].get<std::string>());
		for (auto &post : detail["extracted_posts"]) 
		{
			SocialMediaPostPtr new_post(new SocialMediaPost);
			new_post.get()->setCaption(post["caption"].get<std::string>());
			postStorage.get()->getPostListPtr()->push_back(new_post);
			new_post.get()->setLikes(post["no_of_likes"].get<int>());
		}
		scrapedDetails.push_back(postStorage);
	}
}

ScrapeStorage::~ScrapeStorage()
{

}

nlohmann::json ScrapeStorage::getOutputJsonObject()
{
	using json = nlohmann::json;
	json scrapeResult; json details;
	
	for (size_t i = 0; i < scrapedDetails.size();
		details.push_back(scrapedDetails[i++]->getTargetJson(scrapePlatform, mode)));

	scrapeResult["platform"] = this->scrapePlatform == Platform::Instagram ? "instagram" : "twitter";
	scrapeResult["scrape_mode"] = this->mode == ScrapeMode::Profile ? "profiles" : "hashtags";
	scrapeResult["details"] = details;
	return scrapeResult;
}

bool ScrapeStorage::saveToFile(string folderPath)
{
	using json = nlohmann::json;
	using ICT1009::Utility::FileUtility;
	using ICT1009::Utility::DateTimeUtility;
	if (!FileUtility::directoryExists(folderPath))
		return false;
	else {
		try {
			string savePath = folderPath + "\\"
				+ DateTimeUtility::getCurrentDateTime("%d-%m-%Y_%H-%M-%S") + ".txt";
			std::ofstream o(savePath);
			json j = getOutputJsonObject();
			o << j << std::endl;
			o.close();
			return true;
		} catch (...) {
			return false;
		}
	}	
}


//Convert all details into a json string
string ScrapeStorage::getJsonString()
{
	try {
		nlohmann::json j = getOutputJsonObject();
		return j.dump();
	} catch (...) {
		return "";
	}
	
}

bool ScrapeStorage::addDetails(SocialMediaPostStoragePtr details)
{
	try {
		this->scrapedDetails.push_back(details);
		return true;
	} catch (...) {
		return false;
	}				
}
SCRAPE_STORAGE_NAMESPACE_END
