#include "DateTimeUtility.h"

#ifndef DATE_TIME_UTILITY_CPP
#define DATE_TIME_UTILITY_CPP

namespace ICT1009
{
	namespace Utility
	{
		DateTimeUtility::DateTimeUtility()
		{

		}
		DateTimeUtility::~DateTimeUtility()
		{

		}

		std::string DateTimeUtility::getCurrentDateTime(std::string formatString)
		{
			time_t theTime = time(0);
			struct tm *timeinfo;
			timeinfo = localtime(&theTime);
			formatString += '\a'; 
			std::string buffer;
			buffer.resize(formatString.size());
			int len = strftime(&buffer[0], buffer.size(), formatString.c_str(), timeinfo);
			while (len == 0) {
				buffer.resize(buffer.size()*2);
				len = strftime(&buffer[0], buffer.size(), formatString.c_str(), timeinfo);
			}
			buffer.resize(len-1); 
			return buffer;
		}
	}
}



#endif