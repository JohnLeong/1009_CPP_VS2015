#pragma once
#ifndef CURL_OBJ_H
#define CURL_OBJ_H

#include <string>
#include <iostream>
#include <memory>
#include "curl\curl.h"
#include "FileUtility.h"


#define CURL_NAMESPACE_START namespace ICT1009 { namespace WebScrapping {
#define CURL_NAMESPACE_END } } 
CURL_NAMESPACE_START

#define SETOPT(option, params) curl_easy_setopt(this->handle, option, params)

class CurlObj
{
	typedef std::shared_ptr<CURL> CurlPtr;

private:
	CURL* handle;
	const std::string userAgent;
	std::string buffer;
public:
	CurlObj();
	~CurlObj();
	void initializeScrapingOptions();
	void setCookies(std::string cookies);	
	void resetOptions();
	static int bufferWriter(char *data, int size, int nmemb, std::string *buffer);
	std::string getPageHtml(std::string url, std::string cookies);
	bool downloadImage(std::string imageUrl, std::string savePath);
};

CURL_NAMESPACE_END
#endif