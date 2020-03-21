#include "ScrapeStorage.h"

SCRAPE_STORAGE_NAMESPACE_START

ScrapeStorage::ScrapeStorage()
{	
}

//Load from a json file
ScrapeStorage::ScrapeStorage(string filePath)
{

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
