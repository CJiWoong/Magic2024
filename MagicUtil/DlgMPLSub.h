#pragma once

#include "RegEdit.h"
#include "GcadUtil.h"

// CDlgMPLSub ��ȭ �����Դϴ�.

class CDlgMPLSub : public CGcUiDialog
{
	DECLARE_DYNAMIC(CDlgMPLSub)

public:
	CDlgMPLSub(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgMPLSub();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MPLSUB };

private:
	static const TCHAR* PROGY_NAME;

	CRegEdit m_regEdit;

protected:
	void ControlEnable(BOOL bTrue);
	void SaveIni();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOptuser();
	afx_msg void OnBnClickedCbselwin();
	CButton optUser;
	CButton optSame;
	CButton cbSelWin;
	CEdit tbFX;
	CEdit tbFY;
	CEdit tbSX;
	CEdit tbSY;
	CButton Frame1;
	CStatic Label1;
	CStatic Label2;
	CStatic Label3;
	CStatic Label4;
	virtual BOOL OnInitDialog();
	virtual void OnOK();
};
