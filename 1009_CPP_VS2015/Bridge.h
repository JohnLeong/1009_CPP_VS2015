#pragma once
#ifndef BRIDGE_H
#define BRIDGE_H

#define BRIDGE_NAMESPACE_START namespace ICT1009 { namespace WebScrapping {
#define BRIDGE_NAMESPACE_END } }
#include <string>
#include <iostream>
#include "FileUtility.h"

BRIDGE_NAMESPACE_START
/*
	The Bridge class will be used by our scrapper modules to iteract with 
	external resourses like selenium through python.
*/
class Bridge
{
private:
	std::string executable;
	std::string pythonRelPath;
	std::string instagramCookieFile;
public:
	Bridge();
	~Bridge();

	int executeScript(std::string scriptName, std::string parameters);
	std::string getCookies();

};
BRIDGE_NAMESPACE_END
#endif