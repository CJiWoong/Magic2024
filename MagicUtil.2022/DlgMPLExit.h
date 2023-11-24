#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CDlgMPLExit ��ȭ �����Դϴ�.

class CDlgMPLExit : public CGcUiDialog
{
	DECLARE_DYNAMIC(CDlgMPLExit)

public:
	CDlgMPLExit(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgMPLExit();

// ��ȭ ���� �������Դϴ�.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
