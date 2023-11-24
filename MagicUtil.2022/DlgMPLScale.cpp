// DlgMPLScale.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MagicUtil.h"
#include "DlgMPLScale.h"
#include "afxdialogex.h"

const TCHAR* CDlgMPLScale::PROGY_NAME = _T("Form 축척 보기");

// CDlgMPLScale 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgMPLScale, CGcUiDialog)

CDlgMPLScale::CDlgMPLScale(CWnd* pParent /*=NULL*/)
	: CGcUiDialog(CDlgMPLScale::IDD, pParent)
{
}

CDlgMPLScale::~CDlgMPLScale()
{
}

void CDlgMPLScale::DoDataExchange(CDataExchange* pDX)
{
	CGcUiDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TBNUM, tbNum);
	DDX_Control(pDX, IDC_COBFORM, cobForm);
	DDX_Control(pDX, IDC_TBA0, tbA0);
	DDX_Control(pDX, IDC_TBA1, tbA1);
	DDX_Control(pDX, IDC_TBA2, tbA2);
	DDX_Control(pDX, IDC_TBA3, tbA3);
	DDX_Control(pDX, IDC_TBA4, tbA4);
	DDX_Control(pDX, IDC_FRAME1, Frame1);
	DDX_Control(pDX, IDC_FRAME2, Frame2);
	DDX_Control(pDX, IDC_SBNUM, sbNum);
}


BEGIN_MESSAGE_MAP(CDlgMPLScale, CGcUiDialog)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SBNUM, &CDlgMPLScale::OnDeltaposSbnum)
	ON_BN_CLICKED(IDOK, &CDlgMPLScale::OnBnClickedOk)
	ON_EN_CHANGE(IDC_TBNUM, &CDlgMPLScale::OnChangeTbnum)
END_MESSAGE_MAP()


// CDlgMPLScale 메시지 처리기입니다.


void CDlgMPLScale::OnDeltaposSbnum(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


int CDlgMPLScale::GetFormIniPos(LPCTSTR sFormName)
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


void CDlgMPLScale::GetScale(int iSel, int iNum)
{
	CString sNum;
	CString cstr;
	CString nstr;
	double dHeight;
	double dWidth;

	sNum = GetFormat(iNum);
	nstr.Format(_T("%d"), iSel);

	cstr = m_regEdit.GetString(_T("PaperHeight") + nstr, _T("0"));
	dHeight = DoubleAbs(_ttof(cstr));
	cstr = m_regEdit.GetString(_T("PaperWidth") + nstr, _T("0"));
	dWidth = DoubleAbs(_ttof(cstr));
	Frame1.ShowWindow(SW_SHOW);
	cobForm.ShowWindow(SW_SHOW);

	if (dHeight > dWidth)
		SwapVoidData(&dHeight, &dWidth, sizeof(double));
	cstr.Format(sNum, dWidth / 1189.0); tbA0.SetWindowText(cstr);
	cstr.Format(sNum, dWidth / 841.0); tbA1.SetWindowText(cstr);
	cstr.Format(sNum, dWidth / 594.0); tbA2.SetWindowText(cstr);
	cstr.Format(sNum, dWidth / 420.0); tbA3.SetWindowText(cstr);
	cstr.Format(sNum, dWidth / 297.0); tbA4.SetWindowText(cstr);
}


void CDlgMPLScale::OnBnClickedOk()
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


BOOL CDlgMPLScale::OnInitDialog()
{
	CString sTemp;
	CStringArray strArr;
	CString cstr;
	int iNum;
	int iSel, iCnt;
	int i;

	CGcUiDialog::OnInitDialog();

	SetWindowText(PROGY_NAME);

	sbNum.SetRange(1, 8);

	m_regEdit.SetKey(HKEY_CURRENT_USER, _T("SOFTWARE\\Magic\\MagicUtil\\MPL"));

	iNum = m_regEdit.GetInteger(_T("Dec"), 4);
	SetDlgItemInt(IDC_TBNUM, iNum);

	sTemp = m_regEdit.GetString(_T("AddFormList"), _T(""));
	sTemp.Trim();
	if (!sTemp.IsEmpty()) {
		String2Array(sTemp, strArr, _T(","));
		iCnt = strArr.GetCount();
		for (i = 0; i < iCnt; i ++)
			cobForm.AddString(strArr[i]);
		cobForm.SetCurSel(0);

		GetComboText(&cobForm, cstr);
		iSel = GetFormIniPos(cstr);
		GetScale(iSel, iNum);
	}
	else {
		AfxMessageBox(_T("Form 등록을 먼저 해주십시오."), MB_OK | MB_ICONWARNING);
		GetComboText(&cobForm, cstr);
		iSel = GetFormIniPos(cstr);
		GetScale(iSel, iNum);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlgMPLScale::OnChangeTbnum()
{
	CString cstr;
	int iSel;
	int iNum;

	iNum = GetDlgItemInt(IDC_TBNUM);
	if (iNum < 1 || iNum > 8)
		return;

	if (cobForm.GetCount() > 0) {
		GetComboText(&cobForm, cstr);
		iSel = GetFormIniPos(cstr);
		GetScale(iSel, iNum);
	}
}
