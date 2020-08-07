// testMDIView.cpp : implementation of the CtestMDIView class
//

#include "stdafx.h"
#include "testMDI.h"

#include "testMDIDoc.h"
#include "testMDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtestMDIView

IMPLEMENT_DYNCREATE(CtestMDIView, CView)

BEGIN_MESSAGE_MAP(CtestMDIView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CtestMDIView construction/destruction

CtestMDIView::CtestMDIView()
{
	// TODO: add construction code here

}

CtestMDIView::~CtestMDIView()
{
}

BOOL CtestMDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CtestMDIView drawing

void CtestMDIView::OnDraw(CDC* /*pDC*/)
{
	CtestMDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CtestMDIView printing

BOOL CtestMDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CtestMDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CtestMDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CtestMDIView diagnostics

#ifdef _DEBUG
void CtestMDIView::AssertValid() const
{
	CView::AssertValid();
}

void CtestMDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CtestMDIDoc* CtestMDIView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtestMDIDoc)));
	return (CtestMDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CtestMDIView message handlers
