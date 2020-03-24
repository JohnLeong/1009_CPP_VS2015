#include "DataAnalyser.h"

#include <cctype>
#include <sstream>
#include <unordered_map>

using std::unordered_map;
using ICT1009::DataStorage::SocialMediaPostStorage;
using ICT1009::DataStorage::SocialMediaPost;

namespace ICT1009
{
	
	namespace Analysis
	{
		AnalysedData DataAnalyser::Analyse(DataStorage::ScrapeStorage* data)
		{
			AnalysedData analysedData;
			unsigned int totalWords = 0, totalChars = 0, totalLikes = 0;
			unordered_map<string, unsigned int>* related = &analysedData.getRelatedHashtags();

			//Set analysed data scrape type
			switch (data->getMode())
			{
			case DataStorage::ScrapeStorage::ScrapeMode::Hashtag:
				analysedData.setScrapeType("Hashtags");
			case DataStorage::ScrapeStorage::ScrapeMode::Profile:
				analysedData.setScrapeType("Profiles");
			default:
				break;
			}		

			for (vector<std::shared_ptr<SocialMediaPostStorage>>::iterator it = data->getScrapedDetails().begin(); 
				it != data->getScrapedDetails().end(); ++it)
			{
				//Add scrape target to analysed data
				analysedData.getScrapeTargets().push_back(it->get()->getScrapeTarget());
				//Add number of posts to analysed data
				analysedData.setNumPosts(analysedData.getNumPosts() + static_cast<unsigned int>(it->get()->getPostList().size()));

				//Get all posts for this scrape target
				vector<std::shared_ptr<SocialMediaPost>> posts = it->get()->getPostList();
				for (vector<std::shared_ptr<SocialMediaPost>>::iterator post = posts.begin(); post != posts.end(); ++post)
				{
					//Get all words in the post caption
					vector<string> words = getWordsInString(&post->get()->getCaption());
					for (vector<string>::iterator word = words.begin(); word != words.end(); ++word)
					{
						//Find hashtags
						if ((*word).at(0) == '#')
						{
							if (related->count(*word) == 0)
								(*related)[*word] = 1;
							else
								(*related)[*word] += 1;
						}
					}

					totalLikes += post->get()->getLikes();
					totalWords += static_cast<unsigned int>(words.size());
					totalChars += static_cast<unsigned int>(post->get()->getCaption().size());
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

			return analysedData;
		}

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

		vector<string> DataAnalyser::getWordsInString(string* str)
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