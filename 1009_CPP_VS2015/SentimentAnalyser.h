#pragma once
#ifndef SENTIMENT_ANALYSER_H
#define SENTIMENT_ANALYSER_H

#include "ScrapeStorage.h"
#include <map>
#include <vector>
#include <string>

using std::map;
using std::vector;
using std::string;

namespace ICT1009
{
	namespace Analysis
	{
		class SentimentPair;

		class SentimentAnalyser
		{
		public:
			static map<string, unsigned int> analyseSentiment(DataStorage::ScrapeStorage* data);
		
		private:
			static bool loadSentiments();

			const static string sentimentFilePath;
			static bool sentimentLoaded;
			static vector<SentimentPair> sentiments;
		};

		class SentimentPair
		{
		public:
			vector<string> words;
			string name;
		};
	}
}
#endif
