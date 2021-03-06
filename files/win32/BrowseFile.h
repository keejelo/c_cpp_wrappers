#pragma once
//---------------------------------------------------------------------------------------------
// ** BrowseFile.h
//---------------------------------------------------------------------------------------------
#ifndef BROWSEFILE_H
#define BROWSEFILE_H
//---------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------
// ** Include files
//---------------------------------------------------------------------------------------------
#include <windows.h>
#include <string>


//---------------------------------------------------------------------------------------------
// ** Function prototypes
//---------------------------------------------------------------------------------------------
std::string BrowseFile(HWND hWndParent, bool bOpenOrSave = true, std::string strInitialDir = "");


//---------------------------------------------------------------------------------------------
#endif // BROWSEFILE_H
//---------------------------------------------------------------------------------------------
