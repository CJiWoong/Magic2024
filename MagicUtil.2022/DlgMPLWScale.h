#pragma once

#include "RegEdit.h"
#include "GcadUtil.h"

// CDlgMPLWScale 대화 상자입니다.

class CDlgMPLWScale : public CGcUiDialog
{
	DECLARE_DYNAMIC(CDlgMPLWScale)

public:
	CDlgMPLWScale(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgMPLWScale();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MPLWSCALE };

private:
	static const TCHAR* PROGY_NAME;

	CRegEdit m_regEdit;

protected:
	int GetFormIniPos(LPCTSTR sFormName);
	void GetScale(int iSel, int iNum);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDeltaposSbnum(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnChangeTbnum();
	virtual BOOL OnInitDialog();
	CEdit tbNum;
	CEdit tbA0;
	CEdit tbA1;
	CEdit tbA2;
	CEdit tbA3;
	CEdit tbA4;
	CButton Frame2;
	CSpinButtonCtrl sbNum;
};
