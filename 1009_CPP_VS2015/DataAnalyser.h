#pragma once
#ifndef DATA_ANALYSER_H
#define DATA_ANALYSER_H

#include "ScrapeStorage.h"
#include "AnalysedData.h"

namespace ICT1009 
{
	namespace Analysis 
	{
		class DataAnalyser
		{
		public:
			static AnalysedData Analyse(DataStorage::ScrapeStorage* data);
			static unsigned int CountWords(const char* str);
			static inline vector<string> getWordsInString(string* str);

		private:
			const static std::string wordmapCommand;
		};
	}
}
#endif