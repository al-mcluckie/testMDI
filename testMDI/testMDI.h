// testMDI.h : main header file for the testMDI application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CtestMDIApp:
// See testMDI.cpp for the implementation of this class
//

class CtestMDIApp : public CWinApp
{
public:
	CtestMDIApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CtestMDIApp theApp;