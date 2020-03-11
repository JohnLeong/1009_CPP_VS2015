#include "ScrapeUtility.h"

#ifndef SCRAPE_UTILITY_CPP
#define SCRAPE_UTILITY_CPP

namespace ICT1009
{
	namespace Scrapper
	{
		ScrapeUtility::ScrapeUtility() {

		}
		ScrapeUtility::~ScrapeUtility() {

		}

		void ScrapeUtility::testFunction() {
			curl_global_init(CURL_GLOBAL_DEFAULT);
			CURL *curl = curl_easy_init();
			if (curl) {
				CURLcode res;
				curl_easy_setopt(curl, CURLOPT_URL, "http://www.dynamsoft.com");
				res = curl_easy_perform(curl);
				curl_easy_cleanup(curl);
			}
			curl_global_cleanup();
			printf("Press any key to continue\n");
			getchar();
		}

	}
}



#endif