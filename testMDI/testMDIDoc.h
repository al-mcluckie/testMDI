// testMDIDoc.h : interface of the CtestMDIDoc class
//


#pragma once


class CtestMDIDoc : public CDocument
{
protected: // create from serialization only
	CtestMDIDoc();
	DECLARE_DYNCREATE(CtestMDIDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CtestMDIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


