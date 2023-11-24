#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CDlgMPLExit 대화 상자입니다.

class CDlgMPLExit : public CGcUiDialog
{
	DECLARE_DYNAMIC(CDlgMPLExit)

public:
	CDlgMPLExit(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgMPLExit();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MPLEXIT };

public:
	BOOL m_bCancel;

public:
	void SetRange(int num);
	void StepIt();
	void SetDraw(LPCTSTR draw);
	void SetLayout(LPCTSTR layout);
	void SetForm(LPCTSTR form);
	void SetCopy(int copy, int total);
	void Flush();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCbcancel();
	CProgressCtrl m_pbPlot;
	CEdit m_tbDraw;
	CEdit m_tbCopy;
	CEdit m_tbLayout;
	CEdit m_tbForm;
	virtual void OnCancel();
};
