#pragma once
#ifndef SCRAPE_STORAGE_H
#define SCRAPE_STORAGE_H

#include "SocialMediaPostStorage.h"
#include <vector>

using std::vector;

namespace ICT1009
{
	namespace DataStorage
	{
		class ScrapeStorage
		{
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

		private:
			Platform platform;
			ScrapeMode scrapeMode;
			vector<SocialMediaPostStorage>* scrapedDetails;

		public:
			ScrapeStorage();
			ScrapeStorage(const string filePath);
			~ScrapeStorage();

			bool saveToFile(const string filePath);
			string getJsonString();

			Platform getPlatform();
			ScrapeMode getScrapeMode();
			vector<SocialMediaPostStorage>* getScrapedDetails();

			void setPlatform(Platform platform);
			void setScrapeMode(ScrapeMode scrapeMode);
		};
	}
}
#endif
