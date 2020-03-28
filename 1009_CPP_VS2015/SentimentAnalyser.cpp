#include "SentimentAnalyser.h"

#include "DataAnalyser.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <exception>

using std::exception;
using std::ifstream;
namespace fs = std::experimental::filesystem;

namespace ICT1009
{
	namespace Analysis
	{
		const string SentimentAnalyser::sentimentFilePath = "Sentiment";
		bool SentimentAnalyser::sentimentLoaded = false;
		vector<SentimentPair> SentimentAnalyser::sentiments;

		map<string, unsigned int> SentimentAnalyser::analyseSentiment(DataStorage::ScrapeStorage* data)
		{
			map<string, unsigned int> analysis;

			if (sentimentLoaded == false)
				loadSentiments();

			auto details = data->getScrapedDetails();
			for (int i = 0; i < details.size(); ++i)
			{
				//Get all posts for this scrape target
				auto posts = details.at(i).get()->getPostList();
				for (int j = 0; j < posts.size(); ++j)
				{
					string caption = posts.at(j).get()->getCaption();
					map<string, unsigned int> sentimentFrequency;
					for (int x = 0; x < sentiments.size(); ++x)
					{
						for (int y = 0; y < sentiments[x].words.size(); ++y)
						{
							string target = sentiments[x].words[y];
							if (caption.find(target) != string::npos)
							{
								if (sentimentFrequency.count(sentiments[x].name) < 1)
									sentimentFrequency[sentiments[x].name] = 1;
								else
									sentimentFrequency[sentiments[x].name] += 1;
							}
						}
					}

					string sentiment;
					if (sentimentFrequency.size() < 1)
						sentiment = "Neutral";
					else
					{
						int numWords = ICT1009::Analysis::DataAnalyser::CountWords(caption.c_str());
						int numFound = 0;
						for (auto it = sentimentFrequency.cbegin(); it != sentimentFrequency.cend(); ++it)
							numFound += it->second;

						sentimentFrequency["Neutral"] = (numWords / 3 - numFound) < 0 ? 0 : (numWords / 3 - numFound);

						//Find sentiment with the largest frequency
						auto largest = sentimentFrequency.cbegin();
						if (sentimentFrequency.size() > 1)
						{
							for (auto it = ++sentimentFrequency.cbegin(); it != sentimentFrequency.cend(); ++it)
							{
								if (it->second > largest->second)
									largest = it;
							}
						}
						sentiment = largest->first;
					}

					if (analysis.count(sentiment) < 1)
						analysis[sentiment] = 1;
					else
						analysis[sentiment] += 1;
				}
			}

			return analysis;
		}

		bool SentimentAnalyser::loadSentiments()
		{
			try
			{
				for (const auto & entry : fs::directory_iterator(sentimentFilePath))
				{
					//std::cout << entry.path() << std::endl;
					ifstream file(entry.path());
					if (file.is_open())
					{
						SentimentPair pair;
						pair.name = fs::path(entry.path()).stem().string();
						string line;
						while (getline(file, line))
						{
							pair.words.push_back(line);
							//std::cout << line;
						}
						file.close();
						sentiments.push_back(pair);
					}
				}
			}
			catch (exception e)
			{
				std::cout << e.what() << std::endl;
				return false;
			}

			sentimentLoaded = true;
			return true;
		}
	}
}