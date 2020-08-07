#if !defined(MainFrameSub__INCLUDED_)
#define MainFrameSub__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainFrameSub.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMainFrameSub window

class CMainFrameSub : public CWnd
{
// Construction
public:
	CMainFrameSub();
	WNDPROC* GetSuperWndProcAddr();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrameSub)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrameSub();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrameSub)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(MainFrameSub__INCLUDED_)
