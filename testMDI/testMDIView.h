// testMDIView.h : interface of the CtestMDIView class
//


#pragma once


class CtestMDIView : public CView
{
protected: // create from serialization only
	CtestMDIView();
	DECLARE_DYNCREATE(CtestMDIView)

// Attributes
public:
	CtestMDIDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CtestMDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in testMDIView.cpp
inline CtestMDIDoc* CtestMDIView::GetDocument() const
   { return reinterpret_cast<CtestMDIDoc*>(m_pDocument); }
#endif

