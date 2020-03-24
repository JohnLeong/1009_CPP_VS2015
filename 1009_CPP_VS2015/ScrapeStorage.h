#pragma once
#ifndef SCRAPE_STORAGE_H
#define SCRAPE_STORAGE_H
#define SCRAPE_STORAGE_NAMESPACE_START namespace ICT1009 { namespace DataStorage {
#define SCRAPE_STORAGE_NAMESPACE_END  } }
#include "SocialMediaPostStorage.h"
#include "FileUtility.h"
#include "DateTimeUtility.h"

using std::vector;

SCRAPE_STORAGE_NAMESPACE_START
class ScrapeStorage
{
	// Usage of smart pointers
	typedef std::shared_ptr<SocialMediaPostStorage> SocialMediaPostStoragePtr;

public:

	/*
		Enum in c++ dont use all caps will colide with macros naming.
	*/
	enum Platform {
		Instagram = 0,
		Twitter = 1
	};

	enum ScrapeMode {
		Hashtag = 0,
		Profile = 1
	};


	PV_GET_SET(Platform, ScrapeStorage, scrapePlatform, ScrapePlatform)
	PV_GET_SET(ScrapeMode, ScrapeStorage, mode, Mode)
	PV_GET_SET(vector<SocialMediaPostStoragePtr>, ScrapeStorage, scrapedDetails, ScrapedDetails)
	
public:
	ScrapeStorage();
	ScrapeStorage(const string filePath);
	~ScrapeStorage();

	bool saveToFile(const string filePath);
	string getJsonString();
	nlohmann::json getOutputJsonObject();

	//To append items into SocialMediaPost Vector
	bool addDetails(SocialMediaPostStoragePtr details);

};
SCRAPE_STORAGE_NAMESPACE_END
#endif
