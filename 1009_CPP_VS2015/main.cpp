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

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main() {
	/*Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	My1009_CPP_VS2015::UserInterfaceForm form;
	Application::Run(%form);*/

	ICT1009::WebScrapping::InstagramScrapper scrapper;
	std::cout << "---Start---" << std::endl;
	//Parameters: Username, Password, profiles, PostCap, SaveFolderPath
	scrapper.scrapeByProfiles("hehebongesher", "Password12345", "realdonaldtrump;sgsitconfessions", 2, "C:\\Users\\user\\Desktop\\Json Export2");

	int block;
	std::cin >> block;
	//std::cout << "Folder exists: " << FileUtility::directoryExists("C:\\Users\\user\\Desktop\\Json Export32") << std::endl;
	return 0;
}