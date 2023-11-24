#pragma once

#include "ImageButton.h"
#include "RegEdit.h"
#include "GcadUtil.h"
#include "DwgPreview.h"
#include "DlgMPLExit.h"
#include "CGcadApplication.h"
#include "CGcadDocument.h"
#include "CGcadDocuments.h"
#include "CGcadLayout.h"
#include "CGcadLayouts.h"
#include "CGcadPlot.h"
#include "afxwin.h"
#include "afxcmn.h"

// CDlgMPL 대화 상자입니다.

class CDlgMPL : public CGcUiDialog
{
	DECLARE_DYNAMIC(CDlgMPL)

public:
	CDlgMPL(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgMPL();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MPL };

private:
	static const TCHAR* PROGY_NAME;

	CRegEdit m_regEdit;

	CGcadDocument m_iDoc;
	CGcadLayout m_iLayout;
	CGcadPlot m_iPlot;
	CString m_plotterName;
	CString m_paperName;
	CString m_mediaName;
	CString m_styleName;

	BOOL m_bPlotWindow;
	BOOL m_bActive;
	BOOL m_bModel;
	BOOL m_bOnlyLayout;
	BOOL m_bModel_Lay;
	BOOL m_bSpecLayout;

	double m_dScale;
	double m_dReScale;
	double m_dTWAng;
	double m_dDiff;
	double m_dSTol;
	BOOL m_dSRev;
	BOOL m_bUCS;

	CString m_formList;
	CString m_fileName;
	int m_fileNum;

protected:
	int viewOX;
	int viewOY;
	int viewDY;

protected:
	void GetItemPos(UINT id, int &x, int &y);
	void MoveDlgItem(UINT id, int x, int y);
	int PlotLayout(BOOL bSelPreview, CString pLayName, CString& logStr, CDlgMPLExit* dlgExit);
	void MultiplePlot(BOOL bSelPreview);
	int GetFormIniPos(LPCTSTR sFormName);
	void CurSpaceEnt(gds_name oSel);
	BOOL IsVerDwg(double dRotation);
	void UpdatePlotState();
	void ResetPlotState();
	void AppendDir(LPCTSTR dirName, LPCTSTR findName);
	void ChangeStyle();
	void RefreshMediaNames();
	void RefreshDevices();
	void RefreshPlotStyle();
	void ControlEnable(BOOL bTrue);
	void ControlEnable2(BOOL bTrue);
	void ControlEnable3();
	BOOL FindOpenDwg(LPCTSTR sName, CGcadDocument* pDoc);
	double GetPlotScaleByA1(double dVal, BOOL bVert);
	BOOL IsAPaper();
	void SetDelay(long lngCount);
	int GetCheckedRadioButton(int idFirst, int idLast);
	void LoadIni();
	void SaveIni();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox cboPlotter;
	CComboBox cboPaper;
	CComboBox cboStyle;
	CButton chkStyle;
	CListCtrl lvwDwg;
	CButton cbAdd;
	CButton cbFolder;
	CButton cbAddCur;
	CButton cbAddOpen;
	CButton cbSelOpen;
	CButton cbSelDel;
	CButton cbDelAll;
	CButton cbFup;
	CButton cbUp;
	CButton cbDown;
	CButton cbLdown;
	CButton cbSave;
	CButton cbOpen;
	CButton cbSortA;
	CButton cbSortD;
	CEdit tbPath;
	CButton optForm;
	CButton optWindow;
	CButton optExtend;
	CButton optLimit;
	CButton optDrawing;
	CButton cbForm;
	CButton cbWindow;
	CButton optActive;
	CButton optModel;
	CButton optOnlyLayout;
	CButton optModelLayout;
	CButton optSpecLayout;
	CEdit tbLayout;
	CButton chkFitScale;
	CButton chkAutoScaleA1;
	CEdit tbScale;
	CButton chkPlotCenter;
	CEdit tbPlotX;
	CEdit tbPlotY;
	CDwgPreview ThumbView;
	CButton optSortLR;
	CButton optSortLU;
	CButton optSortLD;
	CButton optSortIZ;
	CEdit tbTol;
	CButton chkReverse;
	CButton chkSelForm;
	CButton chkPLT;
	CButton cbFind;
	CEdit tbPLT;
	CButton chkReScale;
	CEdit tbReScale;
	CButton optAuto;
	CButton optHor;
	CButton optVer;
	CEdit tbPlotCnt;
	CSpinButtonCtrl sbCount;
	CButton chkCopy;
	CEdit tbDelay;
	CSpinButtonCtrl sbDelay;
	CButton chkPreviw;
	CButton cbPreview;
	CButton cbOK;
	CButton cbCancel;
	CButton cbHelp;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCbpreview();
	afx_msg void OnBnClickedCbadd();
	afx_msg void OnBnClickedCbfolder();
	afx_msg void OnBnClickedCbaddcur();
	afx_msg void OnBnClickedCbaddopen();
	afx_msg void OnBnClickedCbselopen();
	afx_msg void OnBnClickedCbselmod();
	afx_msg void OnBnClickedCbseldel();
	afx_msg void OnBnClickedCbdelall();
	afx_msg void OnBnClickedCbfup();
	afx_msg void OnBnClickedCbldown();
	afx_msg void OnBnClickedCbup();
	afx_msg void OnBnClickedCbdown();
	afx_msg void OnBnClickedCbsave();
	afx_msg void OnBnClickedCbopen();
	afx_msg void OnBnClickedCbsorta();
	afx_msg void OnBnClickedCbsortd();
	afx_msg void OnBnClickedCbwindow();
	afx_msg void OnBnClickedChkpreviw();
	afx_msg void OnItemchangedLvwdwg(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDblclkLvwdwg(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeCboplotter();
	afx_msg void OnCbnSelchangeCbostyle();
	afx_msg void OnBnClickedCbform();
	afx_msg void OnBnClickedCbfind();
	afx_msg void OnBnClickedChkfitscale();
	afx_msg void OnBnClickedChkautoscalea1();
	afx_msg void OnBnClickedChkplotcenter();
	afx_msg void OnBnClickedOptactive();
	afx_msg void OnBnClickedOptform();
	CStatic Label5;
	CStatic Label6;
	afx_msg void OnBnClickedChkplt();
	afx_msg void OnBnClickedChkrescale();
	CStatic Label17;
	CStatic Label18;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnClickedIdhelp();
	virtual BOOL OnInitDialog();
	CStatic Label4;
	virtual BOOL DestroyWindow();
	afx_msg void OnCbnSelchangeCbopaper();
	afx_msg void OnClickLvwdwg(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit tbState;
	CStatic plotState;
};
