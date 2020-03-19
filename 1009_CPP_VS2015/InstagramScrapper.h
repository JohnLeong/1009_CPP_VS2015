#pragma once
#ifndef INSTAGRAM_SCRAPPER_H
#define INSTAGRAM_SCRAPPER_H
#define INSTAGRAM_NAMESPACE_START namespace ICT1009 { namespace WebScrapping {
#define INSTAGRAM_NAMESPACE_END } }
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

#define nullptr __nullptr
#include "json.hpp"
#undef nullptr

#include "macros.h"
#include "CurlObj.h"
#include "Bridge.h"
#include "curl\curl.h"
#include "ScrapeStorage.h"
using ICT1009::Utility::FileUtility;

INSTAGRAM_NAMESPACE_START
class InstagramScrapper
{
	

	PV_GET_SET(std::string, InstagramScrapper, username, Username)
	PV_GET_SET(std::string, InstagramScrapper, password, Password)
	PV_GET_SET(std::string, InstagramScrapper, hashtags, Hashtags)
	PV_GET_SET(std::string, InstagramScrapper, profiles, Profiles)

private:
	const std::string cookieFileName;
	const std::string profileTempFile;	
public:
	InstagramScrapper();
	~InstagramScrapper();

	int scrapeByHashTags(const std::string username, const std::string password,
		const std::string joinedHashTags, const double numberOfPosts, const std::string savePath);
	int scrapeByProfiles(const std::string username, const std::string password,
		const std::string joinedProfiles, const int numberOfposts, const std::string savePath);
};

INSTAGRAM_NAMESPACE_END
#endif