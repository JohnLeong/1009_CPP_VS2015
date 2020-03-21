#include "Bridge.h"



BRIDGE_NAMESPACE_START
Bridge::Bridge()
	:pythonRelPath("\\python-3.8.2-embed-amd64\\python.exe"), instagramCookieFile("instagram_cookies.txt")
{
	//Upon initialization of this Class, check if python module exists if not throw exception
	using ICT1009::Utility::FileUtility;
	std::string executablePath = FileUtility::getCurrentWorkingDirectory() + pythonRelPath;
	std::cout << "executablePath: " << executablePath << std::endl;
	if (FileUtility::fileExists(executablePath)) {
		executable = executablePath;
	}
	else
	{	
		std::cout << "does not exists" << std::endl;
		throw "Executable: " + executablePath + " does not exists.";
	}
}

Bridge::~Bridge() 
{
	
}

int Bridge::executeScript(std::string scriptName, std::string parameters) {

	using ICT1009::Utility::FileUtility;
	// Checks if script exists first
	// The script must be at the same path as the debug/release path
	std::string scriptPath = FileUtility::getCurrentWorkingDirectory() + "\\" + scriptName;
	if (!FileUtility::fileExists(scriptPath))
		std::cout << "File: "  + scriptPath << "does not exits" << std::endl;
		//throw "File: " + scriptPath + " does not exists.";
	
	std::string command = "\"" + this->executable + "\" " + scriptName + " " + parameters;
	int res = system(command.c_str());
	return res;
}

int Bridge::execute(std::string parameters) {
	std::string command = this->executable + " " + parameters;
	std::cout << "command is : " << command << std::endl;
	int res = system(command.c_str());
	return res;
}

std::string Bridge::getCookies() {
	using ICT1009::Utility::FileUtility;
	std::string cookiePath = FileUtility::getCurrentWorkingDirectory() + "\\" + instagramCookieFile;
	return FileUtility::fileExists(cookiePath) ?
		FileUtility::getFileAsString(cookiePath) :	"";
}
BRIDGE_NAMESPACE_END
