//---------------------------------------------------------------------------------------------
// ** SearchDialog.cpp
//---------------------------------------------------------------------------------------------
// Modeless dialog created for search, based on "ModelessDialog.cpp", but more detailed and
// functional.
//---------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------
// ** Include files
//---------------------------------------------------------------------------------------------
#include "SearchDialog.h"
#include "Resource.h"      // <---- contains ID's
#include "Controls.h"      // <---- for creating controls easier
#include <commctrl.h>      // <---- SetWindowSubclass etc.


//---------------------------------------------------------------------------------------------
// ** Variables
//---------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------
// ** Dialogbox window procedure (message handler for dialog window)
//---------------------------------------------------------------------------------------------
LRESULT CALLBACK DialogProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    HWND hEdit = NULL;

    switch (msg)
    {
        case WM_CREATE:
        {
            // ** Create some controls
            hEdit = CreateEditCtrl(hWnd, ID_SEARCH_TXT, "", 10, 10, 100); // , 14, ES_WANTRETURN | ES_MULTILINE);
            CreateButtonCtrl(hWnd, ID_SEARCH_BTN_OK, "OK", 10, 50);
            CreateButtonCtrl(hWnd, ID_SEARCH_BTN_CANCEL, "Cancel", 130, 50);

            SetFocus(hEdit);  // Set focus to edit control when opening
            EnumChildWindows(hWnd, SetCtrlFont, 0);  // Set font to DEFAULT_GUI

            // ** Set custom message handler for control to grab ENTER keypress
            SetWindowSubclass(hEdit, EditProc, 0, 0);
        }
        break;

        case WM_COMMAND:             
            switch (wParam)
            {
                case ID_SEARCH_BTN_OK:
                    ValidateSearch(hWnd);
                    break;

                case ID_SEARCH_BTN_CANCEL:
                    SendMessage(hWnd, WM_CLOSE, NULL, NULL);
                    break;
            }
            break;

        case WM_CLOSE:
            // ** Reset the window proc to default
            RemoveWindowSubclass(hEdit, 0, 0);

            DestroyWindow(hWnd);
            break;
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
};
//---------------------------------------------------------------------------------------------
// ** END: Dialogbox window procedure
//---------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------
// ** Edit control window procedure (message handler for this control)
//---------------------------------------------------------------------------------------------
LRESULT CALLBACK EditProc(HWND hCtrlWnd, UINT msg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
{
    switch (msg)
    {
        case WM_KEYDOWN:
        {
            switch (wParam)
            {
                case VK_RETURN:
                    ValidateSearch(GetParent(hCtrlWnd));
                    break;

                case VK_ESCAPE:
                    SendMessage(GetParent(hCtrlWnd), WM_CLOSE, NULL, NULL);
                    break;
            }
        }
        break;
    }

    return DefSubclassProc(hCtrlWnd, msg, wParam, lParam);
};
//---------------------------------------------------------------------------------------------
// ** END: Edit control window procedure
//---------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------
// ** Register the dialog (window) 'class'
//---------------------------------------------------------------------------------------------
void RegisterDialogClass(HINSTANCE hInstance)
{
    WNDCLASSEX wc = { 0 };
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = (WNDPROC)DialogProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpszClassName = "DialogClass";

    // ** Register the window class
    if (!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Dialog window registration failed!", "Error", MB_ICONEXCLAMATION);
    }
};
//---------------------------------------------------------------------------------------------
// ** END: Register the dialog (window) 'class'
//---------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------
// ** Create Dialogbox
//---------------------------------------------------------------------------------------------
HWND CreateDialogBox(HWND hWndParent, HINSTANCE hInstance, const char *sTitle, int iWidth, int iHeight)
{
    // ** Get parent window dimensions, position dialog in parent center
    RECT rc = { 0 };
    GetWindowRect(hWndParent, &rc);
    int xPos = ((rc.left + rc.right) / 2) - (iWidth / 2);
    int yPos = ((rc.top + rc.bottom) / 2) - (iHeight / 2);

    // ** Create and show the dialog
    HWND hDlg = CreateWindowEx(
        WS_EX_DLGMODALFRAME| WS_EX_TOPMOST,
        "DialogClass", 
        sTitle,
        WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
        xPos, 
        yPos, 
        iWidth, 
        iHeight,
        NULL, 
        NULL,
        hInstance, 
        NULL);

    return hDlg;
};
//---------------------------------------------------------------------------------------------
// ** END: Create Dialogbox
//---------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------
// ** Set default gui font to all controls
//---------------------------------------------------------------------------------------------
// EnumChildWindows(hWnd, SetCtrlFont, 0);  // <--- Run this at the end of: WM_CREATE
//---------------------------------------------------------------------------------------------
BOOL CALLBACK SetCtrlFont(HWND hWnd, LPARAM lParam)
{
    HFONT hfDefault = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
    SendMessage(hWnd, WM_SETFONT, (WPARAM)hfDefault, MAKELPARAM(TRUE, 0));
    return TRUE;
};
//---------------------------------------------------------------------------------------------
// ** END: Set default gui font to all controls
//---------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------
// ** Validate search input
//---------------------------------------------------------------------------------------------
void ValidateSearch(HWND hWnd)
{
    char str[255] = { 0 };
    GetDlgItemText(hWnd, ID_SEARCH_TXT, str, sizeof(str));

    if (strlen(str) == 0)
    {
        MessageBox(hWnd, "Search string cannot be empty!", "Error", MB_ICONEXCLAMATION);
        SetFocus(GetDlgItem(hWnd, ID_SEARCH_TXT));
    }
    else
    {
        SendMessage(hWnd, WM_CLOSE, NULL, NULL);
        SearchList(str);  // <----- Extern function that searches for a string
    }
};
//---------------------------------------------------------------------------------------------
// ** END: Validate search input
//---------------------------------------------------------------------------------------------





///////////////////////////////////////////////////////////////////////////////////////////////
// ** HOW TO IMPLEMENT
///////////////////////////////////////////////////////////////////////////////////////////////
/*

// ** Do this in your main window procedure

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_CREATE:
        {
            RegisterDialogClass(g_hInstance);  // <-------  add this, "g_hInstance" is GLOBAL handle to instance
            break;
        }

        case WM_COMMAND:
        {
            // ** Parse menu selections
            switch (wParam)
            {
                case ID_FIND: // some menu item with control id: ID_FIND
                    // ** Create and open dialog when menu item is clicked, g_hMyDlg is GLOBAL handle to dialog (HWND g_hMyDlg)
                    g_hMyDlg = CreateDialogBox(hWnd, g_hInstance, "My find dialog", 238, 130);  // <-------  add this, "g_hInstance" is GLOBAL handle to instance
                    break;
            }
            break;
        }
        break;

        case WM_SIZE:
        {
            switch (wParam)
            {
                case SIZE_MINIMIZED:
                    ShowWindow(g_hMyDlg, SW_HIDE);  // <-------  add this, "g_hMyDlg" is GLOBAL handle to dialog (HWND g_hMyDlg)
                    break;

                case SIZE_RESTORED:
                    ShowWindow(g_hMyDlg, SW_SHOW);  // <-------  add this, "g_hMyDlg" is GLOBAL handle to dialog (HWND g_hMyDlg)
                    break;
            }
            break;
        }
        break;

        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }
    }
    return DefWindowProcW(hWnd, msg, wParam, lParam);
};
*/
