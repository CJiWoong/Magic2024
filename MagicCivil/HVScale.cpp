// HVScale.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MagicCivil.h"
#include "HVScale.h"
#include "afxdialogex.h"


// CHVScale 대화 상자입니다.

IMPLEMENT_DYNAMIC(CHVScale, CDialogEx)

CHVScale::CHVScale(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHVScale::IDD, pParent)
{

}

CHVScale::~CHVScale()
{
}

void CHVScale::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCALELIST, m_scaleList);
}


BEGIN_MESSAGE_MAP(CHVScale, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_SCALELIST, &CHVScale::OnClickScalelist)
END_MESSAGE_MAP()


// CHVScale 메시지 처리기입니다.


BOOL CHVScale::OnInitDialog()
{
	static const _TCHAR *xsList[] = {
		_T("1000"), _T("1000"), _T("1000"), _T("1000"), _T("1200"), _T("1200"), _T("600")
	};
	static const _TCHAR *ysList[] = {
		_T("1000"), _T("200"), _T("400"), _T("166.6666667"), _T("200"), _T("400"), _T("200")
	};
	int i;

	CDialogEx::OnInitDialog();

	m_scaleList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_TRACKSELECT);
	m_scaleList.SetHoverTime (100);

	POINT pnt;
	GetCursorPos(&pnt);
	SetWindowPos(NULL, pnt.x, pnt.y, 0, 0, SWP_NOSIZE);

	CRect crec;
	m_scaleList.GetWindowRect(crec);

    m_scaleList.InsertColumn(0, _T("H 축척"), LVCFMT_LEFT, (crec.Width() - 4) / 2, 0);
    m_scaleList.InsertColumn(1, _T("V 축척"), LVCFMT_LEFT, (crec.Width() - 4) / 2, 0);

	for (i = 0; i < 7; i ++) {
		m_scaleList.InsertItem(i, xsList[i]);
		m_scaleList.SetItemText(i, 1, ysList[i]);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CHVScale::OnClickScalelist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	NM_LISTVIEW *pNMVIEW = (NM_LISTVIEW*)pNMHDR;
	UINT index = pNMVIEW->iItem;

	tbXScale = m_scaleList.GetItemText(index, 0);
	tbYScale = m_scaleList.GetItemText(index, 1);

	CDialogEx::OnOK();

	*pResult = 0;
}
