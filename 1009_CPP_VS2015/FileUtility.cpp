#include "FileUtility.h"
#ifndef FILE_UTILITY_CPP
#define FILE_UTILITY_CPP

FILE_UTILITY_NAMESPACE_START

FileUtility::FileUtility()
{

}
FileUtility::~FileUtility()
{

}

std::string FileUtility::getCurrentWorkingDirectory() {
	char buff[FILE_MAX];
	GetCurrentDir(buff, FILE_MAX);
	std::string cwd(buff);
	return cwd;
}

bool FileUtility::fileExists(const std::string filePath) 
{
	std::fstream fs;
	bool fail = false;
	fs.open(filePath);
	fail = fs.fail();
	fs.close();
	return !fail;
}

bool FileUtility::directoryExists(const std::string folderPath) {
	DWORD ftyp = GetFileAttributesA(folderPath.c_str());
	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false; 
	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true; 
	return false;
}

std::string FileUtility::fileToString(const std::string filePath) {
	std::ifstream t(filePath);
	t.seekg(0, std::ios::end);
	size_t size = t.tellg();
	std::string buffer(size, ' ');
	t.seekg(0);
	t.read(&buffer[0], size);
	return buffer;
}

FILE_UTILITY_NAMESPACE_END
#endif