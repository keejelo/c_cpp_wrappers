//---------------------------------------------------------------------------------------------
// ** Tooltip.cpp
//---------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------
// ** Include files
//---------------------------------------------------------------------------------------------
#include "Tooltip.h"
#include <CommCtrl.h>


/*
//---------------------------------------------------------------------------------------------
// ** Enable visual style on controls (initialize common controls)
//---------------------------------------------------------------------------------------------
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
//---------------------------------------------------------------------------------------------
*/


//---------------------------------------------------------------------------------------------
// ** Create a tooltip for a control
//---------------------------------------------------------------------------------------------
HWND CreateToolTip(HWND hParentWnd, /*int toolID,*/ HWND hWndCtrl, PTSTR pszText)
{
    // ** Max-width (pixels) before newline occurs
    int iMaxWidth = 200;

    // ** Delay time (seconds) before the tooltip disappears
    int iDelayTime = 2;
        
    // ** Get the control to set the tooltip to
    HWND hWndTool = hWndCtrl;  /* HWND hWndTool = GetDlgItem(hParentWnd, toolID); */

    // ** Create tooltip
    HWND hWndTip = NULL;
    
    hWndTip = CreateWindowEx(
        NULL, 
        TOOLTIPS_CLASS,
        NULL,
        //WS_POPUP | TTS_ALWAYSTIP | TTS_BALLOON, 
        WS_POPUP | TTS_NOPREFIX | TTS_ALWAYSTIP,
        CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT,
        hParentWnd,
        NULL, 
        (HINSTANCE)GetWindowLongPtr(hParentWnd, GWLP_HINSTANCE),	// Handle to the instance of the module
        NULL);

    if (!hWndTool || !hWndTip)
    {
        return (HWND)NULL;
    }                              

    // ** Associate the tooltip with control
    TOOLINFO toolInfo = { 0 };
    toolInfo.cbSize = sizeof(toolInfo);
    toolInfo.hwnd = hParentWnd;
    toolInfo.uFlags = TTF_IDISHWND | TTF_SUBCLASS;
    toolInfo.uId = (UINT_PTR)hWndTool;
    toolInfo.lpszText = pszText;
    SendMessage(hWndTip, TTM_ADDTOOL, 0, (LPARAM)&toolInfo);
    
    // ** Set the default max-width
    SendMessage(hWndTip, TTM_SETMAXTIPWIDTH, 0, iMaxWidth);

    // ** Set the default delay time
    SendMessage(hWndTip, TTM_SETDELAYTIME, TTDT_AUTOPOP, MAKELPARAM((iDelayTime * 1000), (0)));

    // ** Can help if tooltip disappear under other windows when hovering etc.
    SetWindowPos(hWndTip, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);

    // ** Return
    return hWndTip;
};
//---------------------------------------------------------------------------------------------
// ** END: Create a tooltip for a control
//---------------------------------------------------------------------------------------------


/*
// EXAMPLE USAGE:

#include "Tooltip.h"

    // ... 

void OnCreate(HWND hWnd)
{
    // ** First create a control
    HWND myBtn = CreateWindow( ...blablabla );

    // ** Then create a tooltip and attach it to the control you just created
    HWND hTooltip = CreateToolTip(hWnd, myBtn, (PTSTR)"This is a button");

    // Done!
};


*/
