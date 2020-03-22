#include "FileUtility.h"

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

std::string FileUtility::getFileAsString(const std::string filePath) {
	std::ifstream t(filePath);
	t.seekg(0, std::ios::end);
	size_t size = t.tellg();
	std::string buffer(size, ' ');
	t.seekg(0);
	t.read(&buffer[0], size);
	return buffer;
}

bool FileUtility::saveStringToFile(const std::string output, const std::string filePath) {
	try {
		std::ofstream file(filePath);
		if (file.is_open()) {
			file << output << std::endl;
			file.close();
			return true;
		} else {
			return false;
		}
	} catch (...){
		return false;
	}
	return false;
}

FILE_UTILITY_NAMESPACE_END