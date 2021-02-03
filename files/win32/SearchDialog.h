#pragma once
//---------------------------------------------------------------------------------------------
// ** SearchDialog.h
//---------------------------------------------------------------------------------------------
#ifndef SEARCH_DIALOG_H
#define SEARCH_DIALOG_H
//---------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------
// ** Include files
//---------------------------------------------------------------------------------------------
#include <windows.h>


//---------------------------------------------------------------------------------------------
// ** Variables
//---------------------------------------------------------------------------------------------
extern int SearchList(char *str); // <-- function in another file


//---------------------------------------------------------------------------------------------
// ** Function prototypes
//---------------------------------------------------------------------------------------------
BOOL CALLBACK SearchDlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


//---------------------------------------------------------------------------------------------
#endif // SEARCH_DIALOG_H
//---------------------------------------------------------------------------------------------
