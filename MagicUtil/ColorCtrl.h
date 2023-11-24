#pragma once


// CColorCtrl

class CColorCtrl : public CButton
{
	DECLARE_DYNAMIC(CColorCtrl)

protected:
	COLORREF m_bgColor;

public:
	CColorCtrl();
	virtual ~CColorCtrl();

	void SetColor(COLORREF color);

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
};


