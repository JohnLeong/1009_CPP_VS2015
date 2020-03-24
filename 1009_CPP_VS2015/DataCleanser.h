#pragma once
#ifndef DATA_CLEANSER_H
#define DATA_CLEANSER_H
#include <string>
#include  <regex>
using std::string;
using std::regex;

namespace ICT1009
{
	namespace Utility
	{
		class DataCleanser
		{
		public:
			DataCleanser();
			static string removeSymbols(const string& str);
			static string removeExtraWhitespaces(const string& str);
			static string cleanseString(string str);
		};
	}

}



#endif


