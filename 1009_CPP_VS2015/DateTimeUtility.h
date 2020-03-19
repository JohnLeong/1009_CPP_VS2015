#pragma once
#ifndef DATE_TIME_UTILITY_H
#define DATE_TIME_UTILITY_H
#include <string>
#include <ctime>
namespace ICT1009 
{
	namespace Utility 
	{
		class DateTimeUtility
		{
		public:
			DateTimeUtility();
			~DateTimeUtility();
			static std::string getCurrentDateTime(std::string format);
		};
	}

}



#endif