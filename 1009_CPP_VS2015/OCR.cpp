#include "OCR.h"

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


int OCRUtility::imageUrlToText(std::string imageUrl) 
{
	return 0;
}

void OCRUtility::appendImagesTextToJson(std::string jsonPath)
{
	using json = nlohmann::json;
	using ICT1009::Utility::FileUtility;
	using std::remove;

	if (!FileUtility::fileExists(jsonPath))
		throw std::exception(("File: "+jsonPath+" does not exists").c_str());

	std::ifstream i(jsonPath); json j; i >> j; i.close();
	/*	
		Remove temp downloaded image if possible
		Remove temp image text file if possible
	*/
	remove(this->tempDownloadImage.c_str());
	remove((this->tempImageTextFile+".txt").c_str());

	bridge->setExecutable(this->executablePath);

	for (auto &detail : j["details"]) {
		for (auto &post : detail["extracted_posts"]) {
			this->downloader->downloadImage(post["display_image_url"].get<std::string>(), this->tempDownloadImage);
			this->bridge->execute(this->tempDownloadImage + " " + this->tempImageTextFile);
			if (FileUtility::fileExists(FileUtility::getCurrentWorkingDirectory()+"\\"+tempImageTextFile+".txt")) {
				std::cout << "Managed to insert text" << std::endl;
				post["img_ocr_text"] = FileUtility::getFileAsString(this->tempImageTextFile+".txt");
			} else {
				std::cout << "Failed to get text" << std::endl;
				post["img_ocr_text"] = "Error";
			}
		}
	}
	remove(this->tempDownloadImage.c_str());
	remove((this->tempImageTextFile+".txt").c_str());
	std::ofstream o(jsonPath); o << j << std::endl; o.close();

}
OCR_UTILITY_NAMESPACE_END
