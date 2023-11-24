#pragma once

#include "RegEdit.h"
#include "GcadUtil.h"

// CDlgMPLWScale ��ȭ �����Դϴ�.

class CDlgMPLWScale : public CGcUiDialog
{
	DECLARE_DYNAMIC(CDlgMPLWScale)

public:
	CDlgMPLWScale(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgMPLWScale();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MPLWSCALE };

private:
	static const TCHAR* PROGY_NAME;

	CRegEdit m_regEdit;

protected:
	int GetFormIniPos(LPCTSTR sFormName);
	void GetScale(int iSel, int iNum);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
