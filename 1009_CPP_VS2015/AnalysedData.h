#pragma once
#ifndef ANALYSED_DATA_H
#define ANALYSED_DATA_H

#include <string>
#include <vector>
#include <unordered_map>
#include "macros.h"

using std::string;
using std::vector;
using std::unordered_map;

namespace ICT1009
{
	namespace Analysis
	{
		class AnalysedData
		{
			PV_GET_SET(string, AnalysedData, scrapeType, ScrapeType)	//The type of scraping: hashtags/profile
			PV_GET_SET(unsigned int, AnalysedData, numPosts, NumPosts)	//The total number of posts
			PV_GET_SET(float, AnalysedData, avgLikes, AvgLikes)			//The average number of likes per post
			PV_GET_SET(float, AnalysedData, avgWords, AvgWords)			//The average number of words per post
			PV_GET_SET(float, AnalysedData, avgChars, AvgChars)			//The average number of characters per post
			PV_GET_SET(float, AnalysedData, avgHashtags, AvgHashtags)	//The average number of hashtags per post
		private:
			vector<string> scrapeTargets;								//The list containg all the scrape keywords
			unordered_map<string, unsigned int> relatedHashtags;		//The set of related hashtags and their frequency
		public:
			AnalysedData();
			vector<string>* getScrapeTargets();
			unordered_map<string, unsigned int>* getRelatedHashtags();
		};
	}
}

#endif