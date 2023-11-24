#pragma once

#include "ImageButton.h"
#include "RegEdit.h"
#include "GcadUtil.h"

// CDlgMPLFName 대화 상자입니다.

class CDlgMPLFName : public CGcUiDialog
{
	DECLARE_DYNAMIC(CDlgMPLFName)

public:
	CDlgMPLFName(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgMPLFName();

	// 대화 상자 데이터입니다.
	enum { IDD = IDD_MPLFNAM };

public:
	BOOL fNamSet;
	double formOrgX, formOrgY, formSclX, formSclY, formAng;
	double fNumSX, fNumSY, fNumEX, fNumEY;
	double fNamSX, fNamSY, fNamEX, fNamEY;
	CString fNumPre, fNumPos;
	CString fNamPre, fNamPos;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedChkfname();
	afx_msg void OnBnClickedFNumLoc();
	afx_msg void OnBnClickedFNamLoc();
	CButton cbFName;
	CButton bnFNumLoc;
	CEdit edFNumPos;
	CEdit edFNumPre;
	CButton bnFNamLoc;
	CEdit edFNamPos;
	CEdit edFNamPre;
	CButton cbFNumLoc;
	CButton cbFNamLoc;
};
