#pragma once

#include "../MagicUtil/ImageButton.h"
#include "../MagicUtil/RegEdit.h"
#include "../MagicUtil/GcadUtil.h"

// CDlgDLS 대화 상자입니다.

class CDlgDLS : public CGcUiDialog
{
	DECLARE_DYNAMIC(CDlgDLS)

public:
	CDlgDLS(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgDLS();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DLS };

private:
	static const TCHAR* PROGY_NAME;
	static const double DefaultTextH;

	CRegEdit m_regEdit;
	int m_dlgFW, m_dlgFH;
	int m_dlgSW, m_dlgSH;
	int m_dlgLW, m_dlgLH;
	int m_bOKSX, m_bOKSY;
	int m_bOKLX, m_bOKLY;
	int m_bHPSX, m_bHPSY;
	int m_bHPLX, m_bHPLY;
	int m_bSTSX, m_bSTSY;
	int m_bSTLX, m_bSTLY;
	CString 계획선;
	CString 문자공통;
	CString 그리드;
	CString 그리드세로;
	CString 종단측점선;
	CString tbl굵은선;
	CString tbl가는선;
	CString tbl제목문자;
	CString tbl내용문자;
	CString 치수문자;
	CString 축척선;
	CString 축척기타;
	CString 축척문자;

	double dXScale;
	double dYScale;
	double dLength;
	CString sText; // 각종 문자 값
	GcDbText* oText;
	GcGePoint2dArray dDrawPnt; // 그릴 선
	GcGePoint3d dTextPnt; // 문자 삽입점
	int iSTA; // 측점간격
	GcGePoint3d dSpnt; // 시작점
	double dSlopF; // 계산한 경사
	double dSlopS;
	int iTmpOpt;
	double dTxtScale;
	CStringArray sHandle;
	int iCntHandle;
	GcGePoint3d vDelS; // 지우고 다시용 시종점 받기
	GcGePoint3d vDelI;
	GcGePoint3d vDelE;

protected:
	void GetItemPos(UINT id, int &x, int &y);
	void ShowDlgItem(UINT id, BOOL show);
	void MoveDlgItem(UINT id, int x, int y);
	void SizeDlgItem(UINT id, int w, int h);
	double GetDlgItemDouble(UINT id);
	void SetCurveType();
	void SetSTextState();
	void LoadSetting();
	void SaveSetting();
	void AddCalsLayer();
	void HandleToArray(LPCTSTR hdlStr);
	void HandleToArray (GcDbEntity *entPtr);
	void TableTextSetting(GcDbText* txtEnt, GcGePoint3d vTextPnt,
		GcDb::TextHorzMode horMod = GcDb::kTextRight, GcDb::TextVertMode verMod = GcDb::kTextVertMid);
	void DrawPolyLine(GcGePoint2dArray pntList, LPCTSTR plLayer, int plColor, BOOL bHandle, BOOL bOne = FALSE);
	void DrawCurve(GcGePoint3d vPntS, GcGePoint3d vPntI, GcGePoint3d vPntE, double dLength);
	void WritePlus(GcDbEntity* oFH, GcDbEntity* oGR, GcGePoint3d vInsPnt, GcGePoint3d vTextPnt,
				GcGePoint3d vGLPnt, double dEL, int iOpt);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	CButton optOneLine;
	CButton optVarLine;
	CEdit tbXScale;
	CEdit tbYScale;
	CEdit tbLength;
	CEdit tbDegnInt;
	CButton chkDegnSlop;
	CEdit tbSlopTxtH;
	CEdit tbNum;
	CButton chkLayer;
	CButton optSTA;
	CButton optNO;
	CEdit tbStaInt;
	CEdit tbSTA;
	CEdit tbTextH;
	CEdit tbTblNum;
	CButton chkDegnK;
	CButton chkDegnTable;
	CButton chkSTA;
	CButton chkGH;
	CButton chkFH;
	CButton chkGap;
	CBitmapButton cbScale;
	CBitmapButton cbGetText1;
	CBitmapButton cbGetText2;
	CBitmapButton cbRoad;
	afx_msg void OnClickedOneLine();
	afx_msg void OnBnClickedCbScale();
	afx_msg void OnClickedChkDegnSlop();
	afx_msg void OnBnClickedCbGetText1();
	afx_msg void OnBnClickedCbGetText2();
	afx_msg void OnBnClickedCbRoad();
	afx_msg void OnBnClickedCbPlusChain();
	afx_msg void OnBnClickedCbDesign();
	afx_msg void OnBnClickedCbSTA();
	afx_msg void OnBnClickedCbGHFH();
	afx_msg void OnBnClickedCbGap();
	afx_msg void OnBnClickedCbDel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedHelp();
};
