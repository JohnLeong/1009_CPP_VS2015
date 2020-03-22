#pragma once
#ifndef OCR_UTILITY_H
#define OCR_UTILITY_H
#include <memory>
#include <string>
#include "Bridge.h"
#include "FileUtility.h"
#include "CurlObj.h"


#define nullptr __nullptr
#include "json.hpp"
#undef nullptr

#define OCR_UTILITY_NAMESPACE_START namespace ICT1009 { namespace TextRecognition {
#define OCR_UTILITY_NAMESPACE_END }}
OCR_UTILITY_NAMESPACE_START
class OCRUtility
{
private:
	typedef std::shared_ptr<ICT1009::WebScrapping::Bridge> BridgePtr;
	BridgePtr bridge;					// To execute Tessearct Executable.

	typedef std::shared_ptr<ICT1009::WebScrapping::CurlObj> CurlObjPtr;
	CurlObjPtr downloader;

	const std::string executablePath;	// Executable 
	const std::string tempDownloadImage; // To store downloaded image
	const std::string tempImageTextFile;	// Image text stored location
	

	bool downloadImage(const std::string imageUrl);		
	std::string getDownloadedImageText();
public:
	OCRUtility();
	~OCRUtility();
	int appendImagesTextToJson(std::string jsonPath);

};

OCR_UTILITY_NAMESPACE_END
#endif