// DlgMPLWScale.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MagicUtil.h"
#include "DlgMPLWScale.h"
#include "afxdialogex.h"

const TCHAR* CDlgMPLWScale::PROGY_NAME = _T("Window 축척 보기");

// CDlgMPLWScale 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgMPLWScale, CGcUiDialog)

CDlgMPLWScale::CDlgMPLWScale(CWnd* pParent /*=NULL*/)
	: CGcUiDialog(CDlgMPLWScale::IDD, pParent)
{
}

CDlgMPLWScale::~CDlgMPLWScale()
{
}

void CDlgMPLWScale::DoDataExchange(CDataExchange* pDX)
{
	CGcUiDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TBNUM, tbNum);
	DDX_Control(pDX, IDC_TBA0, tbA0);
	DDX_Control(pDX, IDC_TBA1, tbA1);
	DDX_Control(pDX, IDC_TBA2, tbA2);
	DDX_Control(pDX, IDC_TBA3, tbA3);
	DDX_Control(pDX, IDC_TBA4, tbA4);
	DDX_Control(pDX, IDC_FRAME2, Frame2);
	DDX_Control(pDX, IDC_SBNUM, sbNum);
}


BEGIN_MESSAGE_MAP(CDlgMPLWScale, CGcUiDialog)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SBNUM, &CDlgMPLWScale::OnDeltaposSbnum)
	ON_BN_CLICKED(IDOK, &CDlgMPLWScale::OnBnClickedOk)
	ON_EN_CHANGE(IDC_TBNUM, &CDlgMPLWScale::OnChangeTbnum)
END_MESSAGE_MAP()


// CDlgMPLWScale 메시지 처리기입니다.


void CDlgMPLWScale::OnDeltaposSbnum(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


int CDlgMPLWScale::GetFormIniPos(LPCTSTR sFormName)
{
	CString cstr;
	CString nstr;
	int i;

	for (i = 1; i <= 6; i ++) {
		nstr.Format(_T("%d"), i);
		cstr = m_regEdit.GetString(_T("FormName") + nstr, _T(""));
		cstr.Trim();
		if (!cstr.IsEmpty()) {
			if (cstr.CompareNoCase(sFormName) == 0)
				return i;
		}
	}

	return 0;
}


void CDlgMPLWScale::GetScale(int iSel, int iNum)
{
	CString sNum;
	CString cstr;
	CString nstr;
	double dHeight;
	double dWidth;
	double dFX;
	double dFY;
	double dSX;
	double dSY;

	sNum = GetFormat(iNum);
	nstr.Format(_T("%d"), iSel);

	cstr = m_regEdit.GetString(_T("WinMinX") + nstr, _T("0"));
	dFX = DoubleAbs(_ttof(cstr));
	cstr = m_regEdit.GetString(_T("WinMinY") + nstr, _T("0"));
	dFY = DoubleAbs(_ttof(cstr));
	cstr = m_regEdit.GetString(_T("WinMaxX") + nstr, _T("841"));
	dSX = DoubleAbs(_ttof(cstr));
	cstr = m_regEdit.GetString(_T("WinMaxY") + nstr, _T("594"));
	dSY = DoubleAbs(_ttof(cstr));
	dHeight = DoubleAbs(dSY - dFY);
	dWidth = DoubleAbs(dSX - dFX);

	if (dHeight > dWidth)
		SwapVoidData(&dHeight, &dWidth, sizeof(double));
	cstr.Format(sNum, dWidth / 1189.0); tbA0.SetWindowText(cstr);
	cstr.Format(sNum, dWidth / 841.0); tbA1.SetWindowText(cstr);
	cstr.Format(sNum, dWidth / 594.0); tbA2.SetWindowText(cstr);
	cstr.Format(sNum, dWidth / 420.0); tbA3.SetWindowText(cstr);
	cstr.Format(sNum, dWidth / 297.0); tbA4.SetWindowText(cstr);
}


void CDlgMPLWScale::OnBnClickedOk()
{
	int iNum;

	iNum = GetDlgItemInt(IDC_TBNUM);
	if (iNum < 1)
		iNum = 1;
	if (iNum > 8)
		iNum = 8;
	m_regEdit.SetInteger(_T("Dec"), iNum);

	CGcUiDialog::OnOK();
}


BOOL CDlgMPLWScale::OnInitDialog()
{
	CString sTemp;
	CStringArray strArr;
	CString cstr;
	int iNum;

	CGcUiDialog::OnInitDialog();

	SetWindowText(PROGY_NAME);

	sbNum.SetRange(1, 8);

	m_regEdit.SetKey(HKEY_CURRENT_USER, _T("SOFTWARE\\Magic\\MagicUtil\\MPL"));

	iNum = m_regEdit.GetInteger(_T("Dec"), 4);
	SetDlgItemInt(IDC_TBNUM, iNum);

	GetScale(0, iNum);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlgMPLWScale::OnChangeTbnum()
{
	CString cstr;
	int iNum;

	iNum = GetDlgItemInt(IDC_TBNUM);
	if (iNum < 1 || iNum > 8)
		return;

	GetScale(0, iNum);
}
