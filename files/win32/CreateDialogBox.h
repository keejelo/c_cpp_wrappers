#pragma once
//---------------------------------------------------------------------------------------------
// ** CreateDialogBox.h
//---------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------
// ** Defines
//---------------------------------------------------------------------------------------------
#ifndef CREATE_DIALOG_BOX_H
#define CREATE_DIALOG_BOX_H
//---------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------
// ** Include files
//---------------------------------------------------------------------------------------------
#include <windows.h>


//---------------------------------------------------------------------------------------------
// ** Variables
//---------------------------------------------------------------------------------------------

// ** Struct to hold modal dialog info for passing in LPARAM pointer ( (LPARAM)&modalinfo )
struct MODALINFO { const char *title; int x; int y; int w; int h; };


//---------------------------------------------------------------------------------------------
// ** Function prototypes
//---------------------------------------------------------------------------------------------

// ** CreateDialogBox | shorthand: DlgBox( ... ) 
HWND CreateDialogBox(HWND hWndParent, const char *sTitle, int iWidth, int iHeight, DLGPROC DlgProc, bool bModal = false, int xPos = 0, int yPos = 0, bool bCenterWindow = true);

// ** DlgBox | shorthand for: CreateDialogBox ( ... )
HWND DlgBox(HWND hWndParent, const char *sTitle, int iWidth, int iHeight, DLGPROC DlgProc, bool bModal = false, int xPos = 0, int yPos = 0, bool bCenterWindow = true);



//---------------------------------------------------------------------------------------------
#endif // CREATE_DIALOG_BOX_H
//---------------------------------------------------------------------------------------------
