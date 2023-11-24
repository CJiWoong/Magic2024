#pragma once

#include "../MagicUtil/ImageButton.h"
#include "../MagicUtil/RegEdit.h"
#include "../MagicUtil/GcadUtil.h"

// CDlgDLS ��ȭ �����Դϴ�.

class CDlgDLS : public CGcUiDialog
{
	DECLARE_DYNAMIC(CDlgDLS)

public:
	CDlgDLS(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgDLS();

// ��ȭ ���� �������Դϴ�.
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
	CString ��ȹ��;
	CString ���ڰ���;
	CString �׸���;
	CString �׸��弼��;
	CString ����������;
	CString tbl������;
	CString tbl���¼�;
	CString tbl������;
	CString tbl���빮��;
	CString ġ������;
	CString ��ô��;
	CString ��ô��Ÿ;
	CString ��ô����;

	double dXScale;
	double dYScale;
	double dLength;
	CString sText; // ���� ���� ��
	GcDbText* oText;
	GcGePoint2dArray dDrawPnt; // �׸� ��
	GcGePoint3d dTextPnt; // ���� ������
	int iSTA; // ��������
	GcGePoint3d dSpnt; // ������
	double dSlopF; // ����� ���
	double dSlopS;
	int iTmpOpt;
	double dTxtScale;
	CStringArray sHandle;
	int iCntHandle;
	GcGePoint3d vDelS; // ����� �ٽÿ� ������ �ޱ�
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
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
