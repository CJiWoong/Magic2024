// DlgMPLFName.cpp: 구현 파일입니다.
//

#include "stdafx.h"
#include "MagicUtil.h"
#include "DlgMPLFName.h"
#include "afxdialogex.h"
#include "CGcadApplication.h"
#include "CGcadDocument.h"


// CDlgMPLFName 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgMPLFName, CDialog)

CDlgMPLFName::CDlgMPLFName(CWnd* pParent /*=NULL*/)
	: CGcUiDialog(IDD_MPLFNAM, pParent)
{
	fNamSet = FALSE;
	fNumSX = 0;
	fNumSY = 0;
	fNumEX = 0;
	fNumEY = 0;
	fNamSX = 0;
	fNamSY = 0; 
	fNamEX = 0; 
	fNamEY = 0;
	fNumPre = "";
	fNumPos = "";
	fNamPre = "";
	fNamPos = "";
}

CDlgMPLFName::~CDlgMPLFName()
{
}

void CDlgMPLFName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHKFNAME, cbFName);
	DDX_Control(pDX, IDC_FNUMLOC, bnFNumLoc);
	DDX_Control(pDX, IDC_FNUMPOS, edFNumPos);
	DDX_Control(pDX, IDC_FNUMPRE, edFNumPre);
	DDX_Control(pDX, IDC_FNAMLOC, bnFNamLoc);
	DDX_Control(pDX, IDC_FNAMPOS, edFNamPos);
	DDX_Control(pDX, IDC_FNAMPRE, edFNamPre);
	DDX_Control(pDX, IDC_FNUMCB, cbFNumLoc);
	DDX_Control(pDX, IDC_FNAMCB, cbFNamLoc);
}


BEGIN_MESSAGE_MAP(CDlgMPLFName, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgMPLFName::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgMPLFName::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CHKFNAME, &CDlgMPLFName::OnBnClickedChkfname)
	ON_BN_CLICKED(IDC_FNUMLOC, &CDlgMPLFName::OnBnClickedFNumLoc)
	ON_BN_CLICKED(IDC_FNAMLOC, &CDlgMPLFName::OnBnClickedFNamLoc)
END_MESSAGE_MAP()


// CDlgMPLFName 메시지 처리기입니다.

BOOL CDlgMPLFName::OnInitDialog()
{
	CGcUiDialog::OnInitDialog();

	cbFName.SetCheck(fNamSet);

	bnFNumLoc.EnableWindow(fNamSet);
	edFNumPre.EnableWindow(fNamSet);
	edFNumPos.EnableWindow(fNamSet);
	bnFNamLoc.EnableWindow(fNamSet);
	edFNamPre.EnableWindow(fNamSet);
	edFNamPos.EnableWindow(fNamSet);

	if (fNumSX == 0 && fNumSY == 0 && fNumEX == 0 && fNumEY == 0)
		cbFNumLoc.SetCheck(FALSE);
	else
		cbFNumLoc.SetCheck(TRUE);
	if (fNamSX == 0 && fNamSY == 0 && fNamEX == 0 && fNamEY == 0)
		cbFNamLoc.SetCheck(FALSE);
	else
		cbFNamLoc.SetCheck(TRUE);

	edFNumPre.SetWindowTextW(fNumPre);
	edFNumPos.SetWindowTextW(fNumPos);
	edFNamPre.SetWindowTextW(fNamPre);
	edFNamPos.SetWindowTextW(fNamPos);

	return TRUE;  // return TRUE unless you set the focus to a control
// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlgMPLFName::OnBnClickedOk()
{
	fNamSet = cbFName.GetCheck();
	edFNumPre.GetWindowTextW(fNumPre);
	edFNumPos.GetWindowTextW(fNumPos);
	edFNamPre.GetWindowTextW(fNamPre);
	edFNamPos.GetWindowTextW(fNamPos);

	CGcUiDialog::OnOK();
}


void CDlgMPLFName::OnBnClickedCancel()
{
	CGcUiDialog::OnCancel();
}


void CDlgMPLFName::OnBnClickedChkfname()
{
	BOOL chk = cbFName.GetCheck();

	bnFNumLoc.EnableWindow(chk);
	edFNumPre.EnableWindow(chk);
	edFNumPos.EnableWindow(chk);
	bnFNamLoc.EnableWindow(chk);
	edFNamPre.EnableWindow(chk);
	edFNamPos.EnableWindow(chk);
}


void CDlgMPLFName::OnBnClickedFNumLoc()
{
	GcGePoint3d pnt1, pnt2, pnt3, pnt4;
	int rt;

	BeginEditorCommand();
	//GetParent()->ShowWindow(SW_HIDE);

	rt = gcedGetPoint(NULL, _T("도면번호 문자에 해당하는 첫번째 모서리 점 지정:"), asDblArray(pnt3));
	if (rt != RTNORM)
		goto ErrorHandler;

	rt = gcedGetCorner(asDblArray(pnt3), _T("도면번호 문자에 해당하는 두번째 모서리 점 지정:"), asDblArray(pnt4));
	if (rt != RTNORM)
		goto ErrorHandler;

	pnt1.x = (pnt3.x - formOrgX) / formSclX * cos(-formAng) - (pnt3.y - formOrgY) / formSclY * sin(-formAng);
	pnt1.y = (pnt3.x - formOrgX) / formSclX * sin(-formAng) + (pnt3.y - formOrgY) / formSclY * cos(-formAng);
	pnt2.x = (pnt4.x - formOrgX) / formSclX * cos(-formAng) - (pnt4.y - formOrgY) / formSclY * sin(-formAng);
	pnt2.y = (pnt4.x - formOrgX) / formSclX * sin(-formAng) + (pnt4.y - formOrgY) / formSclY * cos(-formAng);

	if (pnt1.x < pnt2.x) {
		fNumSX = pnt1.x;
		fNumEX = pnt2.x;
	}
	else {
		fNumSX = pnt2.x;
		fNumEX = pnt1.x;
	}
	if (pnt1.y < pnt2.y) {
		fNumSY = pnt1.y;
		fNumEY = pnt2.y;
	}
	else {
		fNumSY = pnt2.y;
		fNumEY = pnt1.y;
	}

	cbFNumLoc.SetCheck(TRUE);

ErrorHandler:

	//GetParent()->ShowWindow(SW_SHOWNORMAL);
	CompleteEditorCommand();

	gcedGetGcadTextCmdLine()->PostMessage(WM_CHAR, VK_ESCAPE, 0);
}

void CDlgMPLFName::OnBnClickedFNamLoc()
{
	GcGePoint3d pnt1, pnt2, pnt3, pnt4;
	int rt;

	BeginEditorCommand();
	//GetParent()->ShowWindow(SW_HIDE);

	rt = gcedGetPoint(NULL, _T("도면이름 문자에 해당하는 첫번째 모서리 점 지정:"), asDblArray(pnt3));
	if (rt != RTNORM)
		goto ErrorHandler;

	rt = gcedGetCorner(asDblArray(pnt3), _T("도면이름 문자에 해당하는 두번째 모서리 점 지정:"), asDblArray(pnt4));
	if (rt != RTNORM)
		goto ErrorHandler;

	pnt1.x = (pnt3.x - formOrgX) / formSclX * cos(-formAng) - (pnt3.y - formOrgY) / formSclY * sin(-formAng);
	pnt1.y = (pnt3.x - formOrgX) / formSclX * sin(-formAng) + (pnt3.y - formOrgY) / formSclY * cos(-formAng);
	pnt2.x = (pnt4.x - formOrgX) / formSclX * cos(-formAng) - (pnt4.y - formOrgY) / formSclY * sin(-formAng);
	pnt2.y = (pnt4.x - formOrgX) / formSclX * sin(-formAng) + (pnt4.y - formOrgY) / formSclY * cos(-formAng);

	if (pnt1.x < pnt2.x) {
		fNamSX = pnt1.x;
		fNamEX = pnt2.x;
	}
	else {
		fNamSX = pnt2.x;
		fNamEX = pnt1.x;
	}
	if (pnt1.y < pnt2.y) {
		fNamSY = pnt1.y;
		fNamEY = pnt2.y;
	}
	else {
		fNamSY = pnt2.y;
		fNamEY = pnt1.y;
	}

	cbFNamLoc.SetCheck(TRUE);

ErrorHandler:

	//GetParent()->ShowWindow(SW_SHOWNORMAL);
	CompleteEditorCommand();

	gcedGetGcadTextCmdLine()->PostMessage(WM_CHAR, VK_ESCAPE, 0);
}
