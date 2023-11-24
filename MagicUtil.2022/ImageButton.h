#pragma once


// CImageButton

class CImageButton : public CButton
{
	DECLARE_DYNAMIC(CImageButton)

protected:
	CBitmap m_iBitmap;
	int m_bmpW;
	int m_bmpH;

public:
	CImageButton();
	virtual ~CImageButton();

	void SetImage(UINT bID);

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
};


