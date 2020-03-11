#include "ScrapeStorage.h"

namespace ICT1009
{
	namespace DataStorage
	{
		ScrapeStorage::ScrapeStorage()
			: platform(ScrapeStorage::INSTAGRAM), scrapeMode(ScrapeStorage::HASHTAG)
			, scrapedDetails(new vector<SocialMediaPostStorage>())
		{
		}

		//Load from a json file
		ScrapeStorage::ScrapeStorage(string filePath)
			: platform(ScrapeStorage::INSTAGRAM), scrapeMode(ScrapeStorage::HASHTAG)
			, scrapedDetails(new vector<SocialMediaPostStorage>())
		{

		}

		ScrapeStorage::~ScrapeStorage()
		{
			delete scrapedDetails;
		}

		bool ScrapeStorage::saveToFile(string filePath)
		{
			//If invalid file path
			//return false

			return true;
		}

		//Convert all details into a json string
		string ScrapeStorage::getJsonString()
		{
			return "json string here";
		}

		ScrapeStorage::Platform ScrapeStorage::getPlatform()
		{
			return platform;
		}

		ScrapeStorage::ScrapeMode ScrapeStorage::getScrapeMode()
		{
			return scrapeMode;
		}

		vector<SocialMediaPostStorage>* ScrapeStorage::getScrapedDetails()
		{
			return scrapedDetails;
		}

		void ScrapeStorage::setPlatform(Platform platform)
		{
			this->platform = platform;
		}

		void ScrapeStorage::setScrapeMode(ScrapeMode scrapeMode)
		{
			this->scrapeMode = scrapeMode;
		}
	}
}