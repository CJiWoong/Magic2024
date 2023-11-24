// ImageButton.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ColorCtrl.h"


// CColorCtrl

IMPLEMENT_DYNAMIC(CColorCtrl, CButton)

CColorCtrl::CColorCtrl()
{
}

CColorCtrl::~CColorCtrl()
{
}


BEGIN_MESSAGE_MAP(CColorCtrl, CButton)
END_MESSAGE_MAP()


// CColorCtrl �޽��� ó�����Դϴ�.


void CColorCtrl::SetColor (COLORREF color)
{
	m_bgColor = color;
	Invalidate();
}


void CColorCtrl::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{
	ASSERT(lpDIS->CtlType == ODT_BUTTON);

	CDC *pDC = CDC::FromHandle (lpDIS->hDC);
	CRect rc (lpDIS->rcItem);

	pDC->FillSolidRect(1, 1, rc.Width() - 4, rc.Height() - 4, m_bgColor);

	pDC->DrawEdge (rc, EDGE_ETCHED, BF_RECT);
}
