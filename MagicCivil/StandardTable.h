#pragma once


// CStandardTable ��ȭ �����Դϴ�.

class CStandardTable : public CDialogEx
{
	DECLARE_DYNAMIC(CStandardTable)

public:
	CStandardTable(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CStandardTable();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_STANDARDTABLE };

public:
	CStatic m_normalTable;
	CStatic m_smallTable;
	CButton m_showSmall;

protected:
	void SetShowSmall();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual void PostNcDestroy();
	afx_msg void OnClickedShowsmall();
	virtual void OnOK();
	virtual void OnCancel();
};
