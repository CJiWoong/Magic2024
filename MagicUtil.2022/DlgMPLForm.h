#pragma once

#include "ImageButton.h"
#include "RegEdit.h"
#include "GcadUtil.h"

// CDlgMPLForm 대화 상자입니다.

class CDlgMPLForm : public CGcUiDialog
{
	DECLARE_DYNAMIC(CDlgMPLForm)

public:
	CDlgMPLForm(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgMPLForm();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MPLFORM };

private:
	static const TCHAR* PROGY_NAME;

	CRegEdit m_regEdit;

protected:
	void SaveIni();
	void LoadIni();
	void GetForm(int iSel);
	void EdtForm(int iSel);
	void DelForm(int iSel);
	BOOL IsVerDwg(double dRotation);
	BOOL Dup_Check(LPCTSTR sName, int iSel);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCbform1();
	afx_msg void OnBnClickedCbform2();
	afx_msg void OnBnClickedCbform3();
	afx_msg void OnBnClickedCbform4();
	afx_msg void OnBnClickedCbform5();
	afx_msg void OnBnClickedCbform6();
	afx_msg void OnBnClickedCbedt1();
	afx_msg void OnBnClickedCbedt2();
	afx_msg void OnBnClickedCbedt3();
	afx_msg void OnBnClickedCbedt4();
	afx_msg void OnBnClickedCbedt5();
	afx_msg void OnBnClickedCbedt6();
	afx_msg void OnBnClickedCbdel1();
	afx_msg void OnBnClickedCbdel2();
	afx_msg void OnBnClickedCbdel3();
	afx_msg void OnBnClickedCbdel4();
	afx_msg void OnBnClickedCbdel5();
	afx_msg void OnBnClickedCbdel6();
	afx_msg void OnBnClickedCbexit();
	virtual BOOL OnInitDialog();
	CEdit tbForm1;
	CEdit tbForm2;
	CEdit tbForm3;
	CEdit tbForm4;
	CEdit tbForm5;
	CEdit tbForm6;
	CImageButton cbForm1;
	CImageButton cbForm2;
	CImageButton cbForm3;
	CImageButton cbForm4;
	CImageButton cbForm5;
	CImageButton cbForm6;
	CImageButton cbEdt1;
	CImageButton cbEdt2;
	CImageButton cbEdt3;
	CImageButton cbEdt4;
	CImageButton cbEdt5;
	CImageButton cbEdt6;
	CImageButton cbDel1;
	CImageButton cbDel2;
	CImageButton cbDel3;
	CImageButton cbDel4;
	CImageButton cbDel5;
	CImageButton cbDel6;
};
