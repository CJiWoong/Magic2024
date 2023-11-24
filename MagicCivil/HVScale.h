#pragma once


// CHVScale 대화 상자입니다.

class CHVScale : public CDialogEx
{
	DECLARE_DYNAMIC(CHVScale)

public:
	CHVScale(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CHVScale();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_HVSCALE };

public:
	CString tbXScale;
	CString tbYScale;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_scaleList;
	virtual BOOL OnInitDialog();
	afx_msg void OnClickScalelist(NMHDR *pNMHDR, LRESULT *pResult);
};
