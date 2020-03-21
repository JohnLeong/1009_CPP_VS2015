#pragma once
#ifndef BRIDGE_H
#define BRIDGE_H

#define BRIDGE_NAMESPACE_START namespace ICT1009 { namespace WebScrapping {
#define BRIDGE_NAMESPACE_END } }
#include <string>
#include <iostream>
#include "FileUtility.h"
#include "macros.h"

BRIDGE_NAMESPACE_START
/*
	The Bridge class will be used by our scrapper modules to iteract with 
	external resourses like selenium through python.
*/
class Bridge
{

	PV_GET_SET(std::string, Bridge, executable, Executable)
	PV_GET_SET(std::string, Bridge, pythonRelPath, PythonRelPath)
	PV_GET_SET(std::string, Bridge, instagramCookieFile, InstagramCookieFile)
	
public:
	Bridge();
	~Bridge();

	int executeScript(std::string scriptName, std::string parameters);
	int execute(std::string paremeters);
	std::string getCookies();

};
BRIDGE_NAMESPACE_END
#endif