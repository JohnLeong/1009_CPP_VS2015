#include "TwitterScraper.h"
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <Windows.h>

namespace ICT1009
{
	namespace WebScrapping
	{
		const std::string TwitterScraper::scrapingCommand = "java -jar TwitterCrawler/TwitterCrawler.jar";
		const std::string TwitterScraper::hashTagModeString = "hashtags";
		const std::string TwitterScraper::profileModeString = "profiles";

		TwitterScraper::TwitterScraper()
		{
		}

		TwitterScraper::~TwitterScraper()
		{

		}

		int TwitterScraper::scrapeByHashTags(const std::string username, const std::string password,
			const std::string joinedHashTags, const unsigned int numberOfPosts, const std::string savePath)
		{
			WinExec((scrapingCommand + " " + hashTagModeString + " " + std::to_string(numberOfPosts) + " \"" + savePath + "\" " + joinedHashTags).c_str(), SW_HIDE);
			//system((scrapingCommand + " " + hashTagModeString + " " + std::to_string(numberOfPosts) + " \"" + savePath + "\" " + joinedHashTags).c_str());
			return 1;
		}

		int TwitterScraper::scrapeByProfiles(const std::string username, const std::string password,
			const std::string joinedProfiles, const unsigned int numberOfPosts, const std::string savePath)
		{
			WinExec((scrapingCommand + " " + profileModeString + " " + std::to_string(numberOfPosts) + " \"" + savePath + "\" " + joinedProfiles).c_str(), SW_HIDE);
			//system((scrapingCommand + " " + profileModeString + " " + std::to_string(numberOfPosts) + " \"" + savePath + "\" " + joinedProfiles).c_str());
			return 1;
		}
	}
}