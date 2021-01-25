#pragma once
//---------------------------------------------------------------------------------------------
// ** ModelessDialog.h
//---------------------------------------------------------------------------------------------
#ifndef MODELESS_DIALOG_H
#define MODELESS_DIALOG_H
//---------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------
// ** Include files
//---------------------------------------------------------------------------------------------
#include <windows.h>


//---------------------------------------------------------------------------------------------
// ** Defines (i.e. dialog control ID's)
//---------------------------------------------------------------------------------------------
// #define IDC_BUTTON1      101
// #define IDC_BUTTON2      102
// #define IDC_EDIT1        103



//---------------------------------------------------------------------------------------------
// ** Function prototypes
//---------------------------------------------------------------------------------------------
LRESULT CALLBACK DialogProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void CreateDialogBox(HWND hWnd, HINSTANCE hInstance, const char *sTitle, int iWidth, int iHeight);
void RegisterDialogClass(HINSTANCE hInstance);
BOOL CALLBACK EnumDialogChildProc(HWND hWnd, LPARAM lParam);



//---------------------------------------------------------------------------------------------
#endif // MODELESS_DIALOG_H
//---------------------------------------------------------------------------------------------