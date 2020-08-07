//////////////////////////////////////////////////////////////////////
//	File:		MainFrameSub.cpp : implementation file
//
//	Desc:		CWnd derived class to allow CMainFrame to be subclassed
//				and attach a CWnd to it allowing overriding of painting
//				functions such as background etc
//
//
//	Date		Ver		SIR		Description
//	----		------	----	-----------
//
//	10.12.07	3.01	NONE	AJM Created
//
//
//////////////////////////////////////////////////////////////////////


#include "stdafx.h"
#include "testMDI.h"
#include "MainFrameSub.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrameSub

CMainFrameSub::CMainFrameSub()
{
}

CMainFrameSub::~CMainFrameSub()
{
}


BEGIN_MESSAGE_MAP(CMainFrameSub, CWnd)
	//{{AFX_MSG_MAP(CMainFrameSub)
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMainFrameSub message handlers

WNDPROC* CMainFrameSub::GetSuperWndProcAddr()
{
	static WNDPROC NEAR pfnSuper = NULL;
	return &pfnSuper;
} 

BOOL CMainFrameSub::OnEraseBkgnd(CDC* pDC) 
{
	// CtestMDIApp *pApp = (CtestMDIApp*)AfxGetApp();

	// Set brush to desired background color
	COLORREF rgb;
	COLORREF rgbtxt;

	rgb = RGB(150,200,150); //pApp->g_rgbDBColour;
	rgbtxt = RGB(0,0,0); //pApp->g_rgbDBtxtColour;

	CBrush backBrush(rgb);

	// Save old brush
	CBrush* pOldBrush = pDC->SelectObject(&backBrush);

	CRect rect;
	pDC->GetClipBox(&rect);     // Erase the area needed

	pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(),
	  PATCOPY);

	//pDC->GetWindow()->GetWindowRect(&rect);
	this->GetWindowRect(&rect);
	ScreenToClient(&rect);
	CFont font;
	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));       // zero out structure
	lf.lfHeight = 62;                      // request a nn-pixel-height font
	CString sFont("Times New Roman");
	strcpy_s(lf.lfFaceName, sizeof(lf.lfFaceName) - 1, sFont.GetBuffer(sFont.GetLength()));
	sFont.ReleaseBuffer();
	lf.lfWeight = FW_BOLD;
	lf.lfItalic = TRUE;
	VERIFY(font.CreateFontIndirect(&lf));  // create the font
	CFont* def_font = pDC->SelectObject(&font);

//	int rnd = 0;
//	srand( (unsigned)time( NULL ) );
//	rnd = (rand() % 256); //0..255
	pDC->SetBkColor(rgb);
	pDC->SetTextColor(rgbtxt);
	pDC->SetTextAlign(TA_TOP | TA_RIGHT);	//top right corner point
	pDC->TextOut(rect.right-20,rect.top+10, CString("TEST"));

	//display global msg under main user defined screen message 
	pDC->SelectObject(def_font);
	font.DeleteObject();	// Done with the font. Delete the font object.
	lf.lfHeight = 28;
	VERIFY(font.CreateFontIndirect(&lf));  // create the font
	pDC->SelectObject(&font);

	pDC->SetTextAlign(TA_TOP | TA_LEFT);	//top left for DrawText() DT_RIGHT to work
	rect.top+=80;
	rect.right-=20;
	pDC->DrawText((LPCTSTR)"Test message\nNew line\0",-1, &rect, DT_RIGHT | DT_WORDBREAK );

	pDC->SelectObject(def_font);
	font.DeleteObject();	// Done with the font. Delete the font object.

	pDC->SelectObject(pOldBrush);

	return TRUE;
	  
//	return CWnd::OnEraseBkgnd(pDC);
}


void CMainFrameSub::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);
	
	// AJM
	//Added invalidate to allow text g_sDBTitle to be redrawn without corruption
	InvalidateRect(NULL);
	
}

