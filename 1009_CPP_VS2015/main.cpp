//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include "UserInterfaceForm.h"

#include <stdio.h>
#include <iostream>
#include "InstagramScrapper.h"
#include "FileUtility.h"
#include "Bridge.h"

#include <fstream>
#include "CurlObj.h"
#include "SocialMediaComment.h"
#include "FileUtility.h"
#include "DateTimeUtility.h"
#include "CurlObj.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main() {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	My1009_CPP_VS2015::UserInterfaceForm form;
	Application::Run(%form);


	//ICT1009::WebScrapping::InstagramScrapper scrapper;
	//std::cout << "---Start---" << std::endl;
	//Parameters: Username, Password, profiles, PostCap, SaveFolderPath
	//scrapper.scrapeByHashTags("hehebongesher", "Password12345", "apple;orange", 2, "C:\\Users\\user\\Desktop\\Json Export2");
	//scrapper.scrapeByProfiles("hehebongesher", "Password12345", "sgsitconfessions", 20, "C:\\Users\\user\\Desktop\\Json Export2");

	/*ICT1009::TextRecognition::OCRUtility test;
	test.appendImagesTextToJson("C:\\Users\\User\\Desktop\\Json Export2\\22-03-2020_01-06-28.txt");*/
	/*ICT1009::WebScrapping::CurlObj obj;
	if (obj.downloadImage("https://instagram.fsin2-1.fna.fbcdn.net/v/t51.2885-15/e35/90085970_142309450600811_4714120005388155425_n.jpg?_nc_ht=instagram.fsin2-1.fna.fbcdn.net&_nc_cat=1&_nc_ohc=yOgmTAg_enAAX_URou9&oh=b8f35dc4a3fbd7168566d828b38b4f79&oe=5E760813", "ocr.jpg")) {
		
	} else {
		std::cout << "failed" << std::endl;
	}*/

	/*int block;
	std::cin >> block;*/
	//std::cout << "Folder exists: " << FileUtility::directoryExists("C:\\Users\\user\\Desktop\\Json Export32") << std::endl;
	return 0;
}