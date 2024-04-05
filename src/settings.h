// Last updated: <2024/04/04 10:21:33 +0900>

#ifndef __SETTINGS_H__
#define __SETTINGS_H__

#define _USE_MATH_DEFINES

#ifdef _WIN32
// Windows

#ifdef __GNUC__ 
#if __GNUC__ < 9
// MinGW gcc 6.3.0
// use SHGetSpecialFolderPath()
#define _WIN32_IE 0x0400
#endif
#endif

#include <shlobj.h>
#include <shlwapi.h>
#include <wchar.h>
#include <tchar.h>
#include <windows.h>
#include <scrnsave.h>
#include <mmsystem.h>

#endif

// Windows and Linux
#include <stdlib.h>
#include <math.h>
#include "resource.h"

// setting value
extern int waitValue;
extern int fps_display;
extern int enableDrawTree;
extern int enableDrawSlope;
extern int enableDrawBg;
extern int enableDrawBeam;
extern int enableGlErrChk;

#ifdef _WIN32
// Windows

// config ini file name and directory
#define INIDIR _T("ssp3droadgl")
#define INIFILENAME _T("ssp3droadgl.ini")

// ini file section name
#define SECNAME _T("ssp3droadgl_config")

// ----------------------------------------
// prototype declaration
BOOL getConfigFromIniFile(void);
void writeConfigToIniFile(void);
void getValueFromDialog(HWND hDlg);
void setValueOnDialog(HWND hDlg, int waitValue, int fps_display, int enableDrawTree, int enableDrawSlope, int enableDrawBg, int enableDrawBeam, int enableGlErrChk);

#endif

#endif
