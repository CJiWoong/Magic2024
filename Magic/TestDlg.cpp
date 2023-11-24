// TestDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Magic.h"
#include "TestDlg.h"
#include "afxdialogex.h"


// CTestDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTestDlg, CGcUiDialog)

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CGcUiDialog(CTestDlg::IDD, pParent)
{

}

CTestDlg::~CTestDlg()
{
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CGcUiDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestDlg, CGcUiDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CTestDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTestDlg 메시지 처리기입니다.


void CTestDlg::OnBnClickedButton1()
{
	int rt;

	BeginEditorCommand();

	gds_point pt;
	// Get a point
	rt = gcedGetPoint(NULL, GCRX_T("\nEnter start point: "), pt);
if (rt == RTNORM)
	::MessageBox (NULL, _T("RTNORM"), _T("TESTDLG"), MB_OK);
else if (rt == RTCAN)
	::MessageBox (NULL, _T("RTCAN"), _T("TESTDLG"), MB_OK);
else if (rt == RTNONE)
	::MessageBox (NULL, _T("RTNONE"), _T("TESTDLG"), MB_OK);
else if (rt == RTERROR)
	::MessageBox (NULL, _T("RTERROR"), _T("TESTDLG"), MB_OK);
else if (rt == RTKWORD)
	::MessageBox (NULL, _T("RTKWORD"), _T("TESTDLG"), MB_OK);
else {
	CString cstr;
	cstr.Format (_T("other : %d"), rt);
	::MessageBox (NULL, cstr, _T("TESTDLG"), MB_OK);
}

	if (rt == RTNORM) {
		// If the point is good, continue
		CompleteEditorCommand ();
		CString cstr;
		cstr.Format (_T("%.2f, %.2f, %.2f"), pt[X], pt[Y], pt[Z]);
		SetDlgItemText (IDC_EDIT1, cstr);
		//m_valXPt = pt[X];
		//m_valYPt = pt[Y];
		//m_valZPt = pt[Z];
	} else {
		// otherwise cancel the command (including the dialog)
		CancelEditorCommand ();
	}
}
