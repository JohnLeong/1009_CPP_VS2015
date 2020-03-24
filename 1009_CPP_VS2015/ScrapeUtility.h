#pragma once
#ifndef SCRAPE_UTILITY_H
#define SCRAPE_UTILITY_H

#include <string>

using std::string;

namespace ICT1009
{
	namespace WebScrapping
	{
		class ScrapeUtility
		{
		public:
			ScrapeUtility();
			~ScrapeUtility();

			virtual int scrapeByHashTags(const std::string username, const std::string password,
				const std::string joinedHashTags, const unsigned int numberOfPosts, const std::string savePath);
			virtual int scrapeByProfiles(const std::string username, const std::string password,
				const std::string joinedProfiles, const unsigned int numberOfPosts, const std::string savePath);
		};
	}
}

#endif