#pragma once

#include "ImageButton.h"
#include "RegEdit.h"
#include "GcadUtil.h"

// CDlgMPLStyle ��ȭ �����Դϴ�.

class CDlgMPLStyle : public CGcUiDialog
{
	DECLARE_DYNAMIC(CDlgMPLStyle)

public:
	CDlgMPLStyle(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgMPLStyle();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MPLSTYLE };

public:
	CString m_textDwg;
	CString m_textCurrent;
	CString m_selStyle;

private:
	static const TCHAR* PROGY_NAME;

	CRegEdit m_regEdit;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
