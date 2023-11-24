// TestDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "GcadTest.h"
#include "TestDlg.h"
#include "afxdialogex.h"


// CTestDlg ��ȭ �����Դϴ�.

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


// CTestDlg �޽��� ó�����Դϴ�.


void CTestDlg::OnBnClickedOk()
{
	gds_point vSpnt, vEpnt;
	int rt;

	BeginEditorCommand();

	rt = gcedGetPoint(NULL, _T("�μ��� ������ ù��° �𼭸� �� ����:"), vSpnt);
	if (rt != RTNORM) {
		CompleteEditorCommand();
		return;
	}

	rt = gcedGetCorner(vSpnt, _T("�μ��� ������ �ι�° �𼭸� �� ����:"), vEpnt);
	if (rt != RTNORM) {
		CompleteEditorCommand();
		return;
	}

	CompleteEditorCommand();
}
