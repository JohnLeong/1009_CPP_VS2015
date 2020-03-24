#pragma once
#ifndef TWITTER_SCRAPPER_H
#define TWITTER_SCRAPPER_H

#include "ScrapeUtility.h"

namespace ICT1009 
{
	namespace WebScrapping 
	{
		class TwitterScraper : public WebScrapping::ScrapeUtility
		{
		public:
			TwitterScraper();
			~TwitterScraper();

			int scrapeByHashTags(const std::string username, const std::string password,
				const std::string joinedHashTags, const unsigned int numberOfPosts, const std::string savePath);
			int scrapeByProfiles(const std::string username, const std::string password,
				const std::string joinedProfiles, const unsigned int numberOfPosts, const std::string savePath);

		private:
			const static std::string scrapingCommand;
			const static std::string hashTagModeString;
			const static std::string profileModeString;
		};
	}
}

#endif