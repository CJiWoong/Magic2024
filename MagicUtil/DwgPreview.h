#pragma once


// CDwgPreview

class CDwgPreview : public CWnd
{
	DECLARE_DYNAMIC(CDwgPreview)

public:
	CDwgPreview();
	virtual ~CDwgPreview();

public:
	void SetBkgColor(unsigned long color);
	void SetDwgFile(LPCTSTR filPth);

protected:
	Gsoft::UInt32 m_bkgColor;
	CString m_dwgFile;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
};


