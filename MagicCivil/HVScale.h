#pragma once


// CHVScale ��ȭ �����Դϴ�.

class CHVScale : public CDialogEx
{
	DECLARE_DYNAMIC(CHVScale)

public:
	CHVScale(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CHVScale();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_HVSCALE };

public:
	CString tbXScale;
	CString tbYScale;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_scaleList;
	virtual BOOL OnInitDialog();
	afx_msg void OnClickScalelist(NMHDR *pNMHDR, LRESULT *pResult);
};
