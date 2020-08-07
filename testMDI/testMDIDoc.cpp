// testMDIDoc.cpp : implementation of the CtestMDIDoc class
//

#include "stdafx.h"
#include "testMDI.h"

#include "testMDIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtestMDIDoc

IMPLEMENT_DYNCREATE(CtestMDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CtestMDIDoc, CDocument)
END_MESSAGE_MAP()


// CtestMDIDoc construction/destruction

CtestMDIDoc::CtestMDIDoc()
{
	// TODO: add one-time construction code here

}

CtestMDIDoc::~CtestMDIDoc()
{
}

BOOL CtestMDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CtestMDIDoc serialization

void CtestMDIDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CtestMDIDoc diagnostics

#ifdef _DEBUG
void CtestMDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CtestMDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CtestMDIDoc commands
