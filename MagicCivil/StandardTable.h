#pragma once


// CStandardTable 대화 상자입니다.

class CStandardTable : public CDialogEx
{
	DECLARE_DYNAMIC(CStandardTable)

public:
	CStandardTable(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CStandardTable();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_STANDARDTABLE };

public:
	CStatic m_normalTable;
	CStatic m_smallTable;
	CButton m_showSmall;

protected:
	void SetShowSmall();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual void PostNcDestroy();
	afx_msg void OnClickedShowsmall();
	virtual void OnOK();
	virtual void OnCancel();
};
