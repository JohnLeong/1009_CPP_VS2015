#include "DataAnalyser.h"

#include <cctype>
#include <sstream>
#include <unordered_map>
#include <fstream>

using std::unordered_map;
using ICT1009::DataStorage::SocialMediaPostStorage;
using ICT1009::DataStorage::SocialMediaPost;

namespace ICT1009
{

	namespace Analysis
	{
		const std::string DataAnalyser::wordmapCommand = "java -jar WordCloud/WordCloud.jar";

		/**
		* Analyses a data from a scraping procedure and generates a wordmap
		*
		* @param data		The data to analyse
		* @return			An AnalysedData object which contains all the annalysed properties
		*/
		AnalysedData DataAnalyser::Analyse(DataStorage::ScrapeStorage* data)
		{
			AnalysedData analysedData;
			unsigned int totalWords = 0, totalChars = 0, totalLikes = 0;
			unordered_map<string, unsigned int>* related = analysedData.getRelatedHashtags();

			vector<string> wordMapList;

			//Set analysed data scrape type
			switch (data->getMode())
			{
			case DataStorage::ScrapeStorage::ScrapeMode::Hashtag:
				analysedData.setScrapeType("Hashtags");
				break;
			case DataStorage::ScrapeStorage::ScrapeMode::Profile:
				analysedData.setScrapeType("Profiles");
				break;
			default:
				break;
			}

			auto details = data->getScrapedDetails();
			for (int i = 0; i < details.size(); ++i)
			{
				//Add scrape target to analysed data
				analysedData.getScrapeTargets()->push_back(details.at(i).get()->getScrapeTarget());

				//Add number of posts to analysed data
				analysedData.setNumPosts(analysedData.getNumPosts() + static_cast<unsigned int>(details.at(i).get()->getPostList().size()));

				//Get all posts for this scrape target
				auto posts = details.at(i).get()->getPostList();
				for (int j = 0; j < posts.size(); ++j)
				{
					//Get all words in the post caption
					vector<string> words = getWordsInString(&posts.at(j).get()->getCaption());
					for (int k = 0; k < words.size(); ++k)
					{
						//Find hashtags
						if (words.at(k).length() < 1)
							continue;

						if (words.at(k).at(0) == '#')
						{
							if (related->count(words.at(k)) < 1)
								(*related)[words.at(k)] = 1;
							else
								(*related)[words.at(k)] += 1;
						}
						wordMapList.push_back(words.at(k));
					}

					totalLikes += posts.at(j).get()->getLikes();
					totalWords += static_cast<unsigned int>(words.size());
					totalChars += static_cast<unsigned int>(posts.at(j).get()->getCaption().size());
				}
			}

			//Calculate average likes for analysed data
			analysedData.setAvgLikes(static_cast<float>(totalLikes) / static_cast<float>(analysedData.getNumPosts()));
			//Calculate average words for analysed data
			analysedData.setAvgWords(static_cast<float>(totalWords) / static_cast<float>(analysedData.getNumPosts()));
			//Calculate average chars for analysed data
			analysedData.setAvgChars(static_cast<float>(totalChars) / static_cast<float>(analysedData.getNumPosts()));
			//Calculate average hashtags for analysed data
			analysedData.setAvgHashtags(static_cast<float>(related->size()) / static_cast<float>(analysedData.getNumPosts()));

			//Create wordmap
			std::ofstream file;
			file.open("wordlist.txt");
			for (string s : wordMapList)
				file << s << "\n";
			file.close();

			WinExec(wordmapCommand.c_str(), SW_HIDE);
			//system(wordmapCommand.c_str());

			return analysedData;
		}

		/**
		* Counts the number of words in a string
		*
		* @param str		The target string
		* @return			The number of words in the string
		*/
		unsigned int DataAnalyser::CountWords(const char* str)
		{
			if (str == NULL)
				return 0;

			bool inSpaces = false;
			int numWords = 0;

			while (*str != '\0')
			{
				if (std::isspace(*str))
					inSpaces = true;
				else if (inSpaces)
				{
					numWords++;
					inSpaces = false;
				}
				++str;
			}

			return numWords;
		}

		/**
		* Splits a string into individual words
		*
		* @param str		The string to split
		* @return			A vector list containing the split words
		*/
		inline vector<string> DataAnalyser::getWordsInString(string* str)
		{
			string buf;
			std::stringstream ss(*str);
			vector<string> words;

			while (ss >> buf)
				words.push_back(buf);

			return words;
		}
	}
}