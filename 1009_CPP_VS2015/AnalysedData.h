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
			PV_GET_SET(string, AnalysedData, scrapeType, ScrapeType)
			PV_GET_SET(vector<string>, AnalysedData, scrapeTargets, ScrapeTargets)
			PV_GET_SET(unsigned int, AnalysedData, numPosts, NumPosts)
			PV_GET_SET(float, AnalysedData, avgLikes, AvgLikes)
			PV_GET_SET(float, AnalysedData, avgWords, AvgWords)
			PV_GET_SET(float, AnalysedData, avgChars, AvgChars)
			PV_GET_SET(float, AnalysedData, avgHashtags, AvgHashtags)
		private:
			unordered_map<string, unsigned int> relatedHashtags;
		public:
			AnalysedData();
			unordered_map<string, unsigned int> getRelatedHashtags();
		};
	}
}

#endif