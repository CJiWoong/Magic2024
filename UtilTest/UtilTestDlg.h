
// UtilTestDlg.h : ��� ����
//

#pragma once

#include "../MagicUtil/RegEdit.h"

// CUtilTestDlg ��ȭ ����
class CUtilTestDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CUtilTestDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_UTILTEST_DIALOG };

protected:
	CRegEdit m_regEdit;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRun();
};
