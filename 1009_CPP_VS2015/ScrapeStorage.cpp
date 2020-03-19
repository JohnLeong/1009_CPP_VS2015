#include "ScrapeStorage.h"
#ifndef SCRAPE_STORAGE_CPP
#define SCRAPE_STORAGE_CPP
SCRAPE_STORAGE_NAMESPACE_START

ScrapeStorage::ScrapeStorage()
	: scrapePlatform(ScrapeStorage::INSTAGRAM), mode(ScrapeStorage::HASHTAG)
{	
}

//Load from a json file
ScrapeStorage::ScrapeStorage(string filePath)
	: scrapePlatform(ScrapeStorage::INSTAGRAM), mode(ScrapeStorage::HASHTAG)
{

}

ScrapeStorage::~ScrapeStorage()
{

}

json ScrapeStorage::getOutputJsonObject()
{
	json scrapeResult;
	json details;
	for (size_t i = 0; i < scrapedDetails.size();
		details.push_back(scrapedDetails[i++]->getProfileJson()));

	scrapeResult["platform"] = this->scrapePlatform == INSTAGRAM ?
		"instagram" :
		"twitter";
	scrapeResult["scrape_mode"] = this->mode == PROFILE ? "profiles" : "hashtags";
	scrapeResult["details"] = details;
	return scrapeResult;
}

bool ScrapeStorage::saveToFile(string folderPath)
{
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
		json j = getOutputJsonObject();
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
#endif