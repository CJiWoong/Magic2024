// ImageButton.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageButton.h"


// CImageButton

IMPLEMENT_DYNAMIC(CImageButton, CButton)

CImageButton::CImageButton()
{
}

CImageButton::~CImageButton()
{
}


BEGIN_MESSAGE_MAP(CImageButton, CButton)
END_MESSAGE_MAP()


// CImageButton 메시지 처리기입니다.


void CImageButton::SetImage (UINT bID)
{
	m_iBitmap.LoadBitmap(bID);

	BITMAP bmp;
	m_iBitmap.GetObject(sizeof(BITMAP),&bmp);

	m_bmpW = bmp.bmWidth;
	m_bmpH = bmp.bmHeight;

	SetWindowPos(NULL, 0, 0, m_bmpW + 4, m_bmpH + 4,SWP_NOMOVE);
}


void CImageButton::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{
	ASSERT(lpDIS->CtlType == ODT_BUTTON);

	CDC *pDC = CDC::FromHandle (lpDIS->hDC);
	CRect rc (lpDIS->rcItem);
	int nIndexDC = pDC->SaveDC ();

	CBrush brush;
	brush.CreateSolidBrush (::GetSysColor (COLOR_BTNFACE));
	pDC->SetTextColor (::GetSysColor (COLOR_WINDOWTEXT));
	pDC->SetBkColor (::GetSysColor (COLOR_BTNFACE));
	pDC->FillRect (rc, &brush);

	int off;
	off = (lpDIS->itemState & ODS_SELECTED) ? 1: 0;

	CDC dc;
	dc.CreateCompatibleDC (pDC);
	CBitmap *pBitmap = dc.SelectObject (&m_iBitmap);

	pDC->BitBlt ((rc.Width () - m_bmpW) / 2 + rc.left + off,
				(rc.Height () - m_bmpH) / 2 + rc.top + off,
				m_bmpW, m_bmpH, &dc,
				0, 0, SRCCOPY);
	dc.SelectObject (pBitmap);

	//pDC->DrawEdge (rc, EDGE_ETCHED, BF_RECT);
	
	pDC->RestoreDC (nIndexDC);
}
