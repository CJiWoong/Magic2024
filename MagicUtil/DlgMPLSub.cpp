// DlgMPLSub.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MagicUtil.h"
#include "DlgMPLSub.h"
#include "afxdialogex.h"

const TCHAR* CDlgMPLSub::PROGY_NAME = _T("PLOT Window 설정");

// CDlgMPLSub 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgMPLSub, CGcUiDialog)

CDlgMPLSub::CDlgMPLSub(CWnd* pParent /*=NULL*/)
	: CGcUiDialog(CDlgMPLSub::IDD, pParent)
{

}

CDlgMPLSub::~CDlgMPLSub()
{
}

void CDlgMPLSub::DoDataExchange(CDataExchange* pDX)
{
	CGcUiDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_OPTUSER, optUser);
	DDX_Control(pDX, IDC_OPTSAME, optSame);
	DDX_Control(pDX, IDC_CBSELWIN, cbSelWin);
	DDX_Control(pDX, IDC_TBFX, tbFX);
	DDX_Control(pDX, IDC_TBFY, tbFY);
	DDX_Control(pDX, IDC_TBSX, tbSX);
	DDX_Control(pDX, IDC_TBSY, tbSY);
	DDX_Control(pDX, IDC_FRAME1, Frame1);
	DDX_Control(pDX, IDC_LABEL1, Label1);
	DDX_Control(pDX, IDC_LABEL2, Label2);
	DDX_Control(pDX, IDC_LABEL3, Label3);
	DDX_Control(pDX, IDC_LABEL4, Label4);
}


BEGIN_MESSAGE_MAP(CDlgMPLSub, CGcUiDialog)
	ON_BN_CLICKED(IDC_OPTUSER, &CDlgMPLSub::OnBnClickedOptuser)
	ON_BN_CLICKED(IDC_OPTSAME, &CDlgMPLSub::OnBnClickedOptuser)
	ON_BN_CLICKED(IDC_CBSELWIN, &CDlgMPLSub::OnBnClickedCbselwin)
END_MESSAGE_MAP()


// CDlgMPLSub 메시지 처리기입니다.


void CDlgMPLSub::ControlEnable(BOOL bTrue)
{
	cbSelWin.EnableWindow(bTrue);
	Frame1.EnableWindow(bTrue);
	Label1.EnableWindow(bTrue);
	Label2.EnableWindow(bTrue);
	Label3.EnableWindow(bTrue);
	Label4.EnableWindow(bTrue);
	tbFX.EnableWindow(bTrue);
	tbFY.EnableWindow(bTrue);
	tbSX.EnableWindow(bTrue);
	tbSY.EnableWindow(bTrue);
}

void CDlgMPLSub::OnBnClickedOptuser()
{
	if (optUser.GetCheck())
		ControlEnable(FALSE);
	else
		ControlEnable(TRUE);
}


void CDlgMPLSub::OnBnClickedCbselwin()
{
	double dTwAng;
	GcGePoint3d vSpnt;
	GcGePoint3d vEpnt;
	CString fstr;
	CString cstr;
	int rt;

	dTwAng = GetTWAng();
	if (dTwAng != 0)
		dTwAng = - dTwAng;
	if (IsWCS()) {
		if (dTwAng != 0) {
			AfxMessageBox(_T("현재 도면은 Dview 적용된 도면입니다.\nDview 적용된 도면에서는 영역을 제대로 가져올 수 없으므로\nUCS로 만들거나 다른 도면에서 영역을 설정해 주십시오"), MB_OK | MB_ICONWARNING);
			return;
		}
	}

	BeginEditorCommand();

	rt = gcedGetPoint(NULL, _T("인쇄할 영역의 첫번째 모서리 점 지정:"), asDblArray(vSpnt));
	if (rt != RTNORM) {
		CompleteEditorCommand();
		return;
	}

	rt = gcedGetCorner(asDblArray(vSpnt), _T("인쇄할 영역의 두번째 모서리 점 지정:"), asDblArray(vEpnt));
	if (rt != RTNORM) {
		CompleteEditorCommand();
		return;
	}

	if (vEpnt[Y] < vSpnt[Y])
		SwapVoidData(&vSpnt, &vEpnt, sizeof(GcGePoint3d));

	vSpnt = ToUCS(vSpnt);
	vEpnt = ToUCS(vEpnt);

	fstr = GetFormat(5);
	cstr.Format(fstr, vSpnt[X], 5); tbFX.SetWindowTextW(cstr);
	cstr.Format(fstr, vSpnt[Y], 5); tbFY.SetWindowTextW(cstr);
	cstr.Format(fstr, vEpnt[X], 5); tbSX.SetWindowTextW(cstr);
	cstr.Format(fstr, vEpnt[Y], 5); tbSY.SetWindowTextW(cstr);

	CompleteEditorCommand();
}


void CDlgMPLSub::SaveIni()
{
	CString cstr;
	
	tbFX.GetWindowText(cstr); m_regEdit.SetString(_T("WinMinX"), cstr);
	tbFY.GetWindowText(cstr); m_regEdit.SetString(_T("WinMinY"), cstr);
	tbSX.GetWindowText(cstr); m_regEdit.SetString(_T("WinMaxX"), cstr);
	tbSY.GetWindowText(cstr); m_regEdit.SetString(_T("WinMaxY"), cstr);
	m_regEdit.SetBoolean(_T("WinUser"), optUser.GetCheck() ? TRUE: FALSE);
}


BOOL CDlgMPLSub::OnInitDialog()
{
	CString cstr;

	CGcUiDialog::OnInitDialog();

	SetWindowText(PROGY_NAME);

	m_regEdit.SetKey(HKEY_CURRENT_USER, _T("SOFTWARE\\Magic\\MagicUtil\\MPL"));

	cstr = m_regEdit.GetString(_T("WinMinX"), _T("0")); tbFX.SetWindowTextW(cstr);
	cstr = m_regEdit.GetString(_T("WinMinY"), _T("0")); tbFY.SetWindowTextW(cstr);
	cstr = m_regEdit.GetString(_T("WinMaxX"), _T("841")); tbSX.SetWindowTextW(cstr);
	cstr = m_regEdit.GetString(_T("WinMaxY"), _T("594")); tbSY.SetWindowTextW(cstr);
	if (m_regEdit.GetBoolean(_T("WinUser"), FALSE))
		CheckRadioButton(IDC_OPTUSER, IDC_OPTSAME, IDC_OPTUSER);
	else
		CheckRadioButton(IDC_OPTUSER, IDC_OPTSAME, IDC_OPTSAME);
	OnBnClickedOptuser();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlgMPLSub::OnOK()
{
	SaveIni();

	CGcUiDialog::OnOK();
}
