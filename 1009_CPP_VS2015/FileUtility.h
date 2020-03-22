#pragma once
#ifndef FILE_UTILITY_H
#define FILE_UTILITY_H

#define WINDOWS
#define FILE_MAX 260
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#define FILE_UTILITY_NAMESPACE_START namespace ICT1009 { namespace Utility {
#define FILE_UTILITY_NAMESPACE_END }}
#include <string>
#include <windows.h>
#include <fstream>

FILE_UTILITY_NAMESPACE_START

class FileUtility
{
public:
	FileUtility();
	~FileUtility();
	static std::string getCurrentWorkingDirectory();
	static bool fileExists(std::string filePath);
	static std::string getFileAsString(const std::string filePath);
	static bool directoryExists(const std::string folderPath);
	static bool saveStringToFile(const std::string output, const std::string filePath);
};

FILE_UTILITY_NAMESPACE_END

#endif