#include "AnalysedData.h"


namespace ICT1009
{
	namespace Analysis
	{
		AnalysedData::AnalysedData()
			: scrapeType("Hashtags"), numPosts(0), avgLikes(0.0f), avgWords(0.0f), avgChars(0.0f), avgHashtags(0.0f)
		{
		}

		vector<string>* AnalysedData::getScrapeTargets()
		{
			return &scrapeTargets;
		}

		unordered_map<string, unsigned int>* AnalysedData::getRelatedHashtags()
		{
			return &relatedHashtags;
		}
	}
}