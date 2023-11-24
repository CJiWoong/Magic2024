#pragma once

#include "ImageButton.h"
#include "RegEdit.h"
#include "GcadUtil.h"

// CDlgMPLStyle 대화 상자입니다.

class CDlgMPLStyle : public CGcUiDialog
{
	DECLARE_DYNAMIC(CDlgMPLStyle)

public:
	CDlgMPLStyle(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgMPLStyle();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MPLSTYLE };

public:
	CString m_textDwg;
	CString m_textCurrent;
	CString m_selStyle;

private:
	static const TCHAR* PROGY_NAME;

	CRegEdit m_regEdit;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCbok();
	afx_msg void OnSelchangeCobstyle();
	CButton cbOK;
	afx_msg void OnBnClickedCbcancel();
	afx_msg void OnBnClickedCbhelp();
	virtual BOOL OnInitDialog();
	CComboBox cobStyle;
	CStatic lblDwg;
	CStatic lblCurrent;
};
