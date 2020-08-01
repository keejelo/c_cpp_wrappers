#pragma once
//---------------------------------------------------------------------------------------------
// ** DebugConsole.h
//---------------------------------------------------------------------------------------------
#ifndef DEBUGCONSOLE_H
#define DEBUGCONSOLE_H
//---------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------
// ** Include files
//---------------------------------------------------------------------------------------------
#include <stdio.h>


//---------------------------------------------------------------------------------------------
// ** Variable
//---------------------------------------------------------------------------------------------
extern const bool DBGCON;  // extern to be able to put it elsewhere


//---------------------------------------------------------------------------------------------
// ** Function prototypes
//---------------------------------------------------------------------------------------------
int log(const char* format, ...);   // Wrapper for "printf", only outputs when DBGCON = true
bool EnableConsole();               // Call it once from another function to start it


//---------------------------------------------------------------------------------------------
#endif // DEBUGCONSOLE_H
//---------------------------------------------------------------------------------------------
