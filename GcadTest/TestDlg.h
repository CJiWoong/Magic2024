#pragma once

#include "../MagicUtil/GcadUtil.h"

// CTestDlg ��ȭ �����Դϴ�.

class CTestDlg : public CGcUiDialog
{
	DECLARE_DYNAMIC(CTestDlg)

public:
	CTestDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTestDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
