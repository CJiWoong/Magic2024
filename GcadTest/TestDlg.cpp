// TestDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "GcadTest.h"
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
	ON_BN_CLICKED(IDOK, &CTestDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTestDlg 메시지 처리기입니다.


void CTestDlg::OnBnClickedOk()
{
	gds_point vSpnt, vEpnt;
	int rt;

	BeginEditorCommand();

	rt = gcedGetPoint(NULL, _T("인쇄할 영역의 첫번째 모서리 점 지정:"), vSpnt);
	if (rt != RTNORM) {
		CompleteEditorCommand();
		return;
	}

	rt = gcedGetCorner(vSpnt, _T("인쇄할 영역의 두번째 모서리 점 지정:"), vEpnt);
	if (rt != RTNORM) {
		CompleteEditorCommand();
		return;
	}

	CompleteEditorCommand();
}
