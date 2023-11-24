// DwgPreview.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MagicUtil.h"
#include "DwgPreview.h"
#include "GcadUtil.h"


// CDwgPreview

IMPLEMENT_DYNAMIC(CDwgPreview, CWnd)

CDwgPreview::CDwgPreview()
{

}

CDwgPreview::~CDwgPreview()
{
}


void CDwgPreview::SetBkgColor(unsigned long color)
{
	m_bkgColor = color;
}


void CDwgPreview::SetDwgFile(LPCTSTR filPth)
{
	m_dwgFile = filPth;
	RedrawWindow();
}

BEGIN_MESSAGE_MAP(CDwgPreview, CWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDwgPreview 메시지 처리기입니다.

int CDwgPreview::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_bkgColor = 0xffffff;

	return 0;
}


void CDwgPreview::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CRect rc;
	CBrush brush;

	GetClientRect(rc);
	brush.CreateSolidBrush(m_bkgColor);
	dc.FillRect (rc, &brush);

	if (!m_dwgFile.IsEmpty())
		gcdbDisplayPreviewFromDwg(m_dwgFile, m_hWnd, &m_bkgColor);

	dc.DrawEdge(rc, EDGE_ETCHED, BF_RECT);
}
