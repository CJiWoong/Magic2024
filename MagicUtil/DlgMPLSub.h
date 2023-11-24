#pragma once

#include "RegEdit.h"
#include "GcadUtil.h"

// CDlgMPLSub 대화 상자입니다.

class CDlgMPLSub : public CGcUiDialog
{
	DECLARE_DYNAMIC(CDlgMPLSub)

public:
	CDlgMPLSub(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgMPLSub();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MPLSUB };

private:
	static const TCHAR* PROGY_NAME;

	CRegEdit m_regEdit;

protected:
	void ControlEnable(BOOL bTrue);
	void SaveIni();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
