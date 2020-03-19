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
	enum Platform
	{
		INSTAGRAM,
		TWITTER
	};
	enum ScrapeMode
	{
		HASHTAG,
		PROFILE
	};

	PV_GET_SET(Platform, ScrapeStorage, scrapePlatform, ScrapePlatform)
	PV_GET_SET(ScrapeMode, ScrapeStorage, mode, Mode)
	PV_GET_SET(vector<SocialMediaPostStoragePtr>, ScrapeStorage, scrapedDetails, ScrapedDetails)
	
public:
	ScrapeStorage();
	ScrapeStorage(const string filePath);
	~ScrapeStorage();

	//
	bool saveToFile(const string filePath);
	string getJsonString();
	json getOutputJsonObject();

	//To append items into SocialMediaPost Vector
	bool addDetails(SocialMediaPostStoragePtr details);

};
SCRAPE_STORAGE_NAMESPACE_END
#endif
