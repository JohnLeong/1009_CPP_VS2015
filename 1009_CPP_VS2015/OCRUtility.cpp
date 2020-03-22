#include "OCRUtility.h"

OCR_UTILITY_NAMESPACE_START

OCRUtility::OCRUtility()
	:executablePath("tesseract.exe"),				// Ensure that teserract is in same directory
		tempDownloadImage("tmp\\downloaded.jpg"),	// Tmp folder must also be there
		tempImageTextFile("tmp\\image")
{
	this->bridge = BridgePtr(new ICT1009::WebScrapping::Bridge());
	this->downloader = CurlObjPtr(new ICT1009::WebScrapping::CurlObj());
}


OCRUtility::~OCRUtility()
{
	/*
		Smart pointers will auto handle themselves
	*/
}

bool OCRUtility::downloadImage(const std::string imageUrl)
{
	//this->downloader->downloadImage(post["display_image_url"].get<std::string>(), tempDownloadImage);
	return this->downloader->downloadImage(imageUrl, tempDownloadImage);
}
std::string OCRUtility::getDownloadedImageText() {
	using ICT1009::Utility::FileUtility;
	this->bridge->execute(tempDownloadImage + " " + tempImageTextFile);
	if (FileUtility::fileExists(FileUtility::getCurrentWorkingDirectory()+"\\"+tempImageTextFile+".txt")) 
		return FileUtility::getFileAsString(tempImageTextFile+".txt");
	else 	
		return "Downloaded Image not found";
}


int OCRUtility::appendImagesTextToJson(std::string jsonPath)
{
	using json = nlohmann::json;
	using ICT1009::Utility::FileUtility;
	using std::remove;

	if (!FileUtility::fileExists(jsonPath))
		throw std::exception(("File: "+jsonPath+" does not exists").c_str());

	json j;
	try {
		std::ifstream i(jsonPath);  i >> j; i.close();
	} catch (...) {
		return -1; //Error opening file
	}
	
	/*	
		Remove temp downloaded image if possible
		Remove temp image text file if possible
	*/
	bridge->setExecutable(this->executablePath);

	for (auto &detail : j["details"]) {
		for (auto &post : detail["extracted_posts"]) {
			if (downloadImage(post["display_image_url"].get<std::string>())) {
				post["img_ocr_text"] = getDownloadedImageText();
			} else {
				post["img_ocr_text"] = "Unable to download file";
			}			
			remove(this->tempDownloadImage.c_str());
			remove((this->tempImageTextFile+".txt").c_str());
		}
	}

	try {
		std::ofstream o(jsonPath); o << j << std::endl; o.close();
	} catch (...) {
		return -2; //Unable to append to file
	}
	

	return 1;
}
OCR_UTILITY_NAMESPACE_END
