#include "CurlObj.h"

CURL_NAMESPACE_START

CurlObj::CurlObj()
	:userAgent("Mozilla/5.0 (Windows; U; WindowsNT 5.1; en-US; rv1.8.1.6) Gecko/20070725 Firefox/2.0.0.6")
{
	
}

CurlObj::~CurlObj()
{
	curl_global_cleanup();
	delete this->handle;
}

void CurlObj::initializeScrapingOptions() {
	if (this->handle) {
		SETOPT(CURLOPT_USERAGENT, userAgent.c_str());
		SETOPT(CURLOPT_AUTOREFERER, 1);
		SETOPT(CURLOPT_HEADER, 1);
		SETOPT(CURLOPT_FOLLOWLOCATION, 1);
		SETOPT(CURLOPT_SSL_VERIFYPEER, 0);

		/*
		This is to ensure that the results of all execution will be stored into
		buffer variable.
		*/
		SETOPT(CURLOPT_WRITEFUNCTION, &CurlObj::bufferWriter);
		SETOPT(CURLOPT_WRITEDATA, &buffer);
	}	
}


void CurlObj::setCookies(std::string cookiesParameters) {
	SETOPT(CURLOPT_COOKIE, cookiesParameters.c_str());
}

void CurlObj::resetOptions() {
	curl_easy_reset(this->handle);
}

int CurlObj::bufferWriter(char *data, int size, int nmemb, std::string *buffer) {
	int result = 0;
	if (buffer != NULL) {
		buffer->append(data, size * nmemb);
		result = size * nmemb;
	}
	return result;
}

std::string CurlObj::getPageHtml(std::string url, std::string cookies) {
	curl_global_init(CURL_GLOBAL_ALL);
	handle = curl_easy_init();
	SETOPT(CURLOPT_URL, url.c_str());
	SETOPT(CURLOPT_USERAGENT, userAgent.c_str());
	/*SETOPT(CURLOPT_AUTOREFERER, 1);
	SETOPT(CURLOPT_HEADER, 1);
	SETOPT(CURLOPT_FOLLOWLOCATION, 1);
	SETOPT(CURLOPT_SSL_VERIFYPEER, 0);*/
	SETOPT(CURLOPT_COOKIE, cookies.c_str());
	/*
	This is to ensure that the results of all execution will be stored into
	buffer variable.
	*/
	/*SETOPT(CURLOPT_WRITEFUNCTION, &CurlObj::bufferWriter);
	SETOPT(CURLOPT_WRITEDATA, &buffer);*/
	
	curl_easy_perform(handle);
	curl_easy_cleanup(handle);
	curl_global_cleanup();

	return "";
}



bool CurlObj::downloadImage(std::string imageUrl, std::string savePath) {
	using std::cout; using std::endl;
	
	try {
		cout << savePath.c_str() << endl;
		FILE *file  = fopen(savePath.c_str(), "wb");
		if (file == NULL) {
			cout << "Unable to open file" << endl;
			return false;
		}
		CURLcode result;
		curl_global_init(CURL_GLOBAL_ALL);
		this->handle = curl_easy_init();			
			
		SETOPT(CURLOPT_URL, imageUrl.c_str());
		SETOPT(CURLOPT_WRITEDATA, file);

		result = curl_easy_perform(this->handle);

		fclose(file);

		curl_easy_cleanup(this->handle);
		curl_global_cleanup();

		if (result != CURLE_OK) {
			cout << "result != CURLE_OK" << endl;
			return false;
		}		
		return true;		
	} catch (...) {
		cout << "Exception at downloadImage" << endl;
		return false;
	}
}
CURL_NAMESPACE_END
