// DlgDLS.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MagicCivil.h"
#include "DlgDLS.h"
#include "afxdialogex.h"
#include "StandardTable.h"
#include "HVScale.h"

const TCHAR* CDlgDLS::PROGY_NAME = _T("���� ���� ���");
const double CDlgDLS::DefaultTextH = 2.5;

// CDlgDLS ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgDLS, CGcUiDialog)

CDlgDLS::CDlgDLS(CWnd* pParent /*=NULL*/)
	: CGcUiDialog(CDlgDLS::IDD, pParent)
{
}


CDlgDLS::~CDlgDLS()
{
}


void CDlgDLS::DoDataExchange(CDataExchange* pDX)
{
	CGcUiDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_OPTONELINE, optOneLine);
	DDX_Control(pDX, IDC_OPTVARLINE, optVarLine);
	DDX_Control(pDX, IDC_TBXSCALE, tbXScale);
	DDX_Control(pDX, IDC_TBYSCALE, tbYScale);
	DDX_Control(pDX, IDC_TBLENGTH, tbLength);
	DDX_Control(pDX, IDC_TBDEGNINT, tbDegnInt);
	DDX_Control(pDX, IDC_CHKDEGNSLOP, chkDegnSlop);
	DDX_Control(pDX, IDC_TBSLOPTXTH, tbSlopTxtH);
	DDX_Control(pDX, IDC_TBNUM, tbNum);
	DDX_Control(pDX, IDC_CHKLAYER, chkLayer);
	DDX_Control(pDX, IDC_OPTSTA, optSTA);
	DDX_Control(pDX, IDC_OPTNO, optNO);
	DDX_Control(pDX, IDC_TBSTAINT, tbStaInt);
	DDX_Control(pDX, IDC_TBSTA, tbSTA);
	DDX_Control(pDX, IDC_TBTEXTH, tbTextH);
	DDX_Control(pDX, IDC_TBTBLNUM, tbTblNum);
	DDX_Control(pDX, IDC_CHKDEGNK, chkDegnK);
	DDX_Control(pDX, IDC_CHKDEGNTABLE, chkDegnTable);
	DDX_Control(pDX, IDC_CHKSTA, chkSTA);
	DDX_Control(pDX, IDC_CHKGH, chkGH);
	DDX_Control(pDX, IDC_CHKFH, chkFH);
	DDX_Control(pDX, IDC_CHKGAP, chkGap);
	DDX_Control(pDX, IDC_CBSCALE, cbScale);
	DDX_Control(pDX, IDC_CBGETTEXT1, cbGetText1);
	DDX_Control(pDX, IDC_CBGETTEXT2, cbGetText2);
	DDX_Control(pDX, IDC_CBROAD, cbRoad);
}


BEGIN_MESSAGE_MAP(CDlgDLS, CGcUiDialog)
	ON_BN_CLICKED(IDC_OPTONELINE, &CDlgDLS::OnClickedOneLine)
	ON_BN_CLICKED(IDC_OPTVARLINE, &CDlgDLS::OnClickedOneLine)
	ON_BN_CLICKED(IDC_CBSCALE, &CDlgDLS::OnBnClickedCbScale)
	ON_BN_CLICKED(IDC_CHKDEGNSLOP, &CDlgDLS::OnClickedChkDegnSlop)
	ON_BN_CLICKED(IDC_CBGETTEXT1, &CDlgDLS::OnBnClickedCbGetText1)
	ON_BN_CLICKED(IDC_CBGETTEXT2, &CDlgDLS::OnBnClickedCbGetText2)
	ON_BN_CLICKED(IDC_CBROAD, &CDlgDLS::OnBnClickedCbRoad)
	ON_BN_CLICKED(IDC_CBPLUSCHAIN, &CDlgDLS::OnBnClickedCbPlusChain)
	ON_BN_CLICKED(IDC_CBDESIGN, &CDlgDLS::OnBnClickedCbDesign)
	ON_BN_CLICKED(IDC_CBSTA, &CDlgDLS::OnBnClickedCbSTA)
	ON_BN_CLICKED(IDC_CBGHFH, &CDlgDLS::OnBnClickedCbGHFH)
	ON_BN_CLICKED(IDC_CBGAP, &CDlgDLS::OnBnClickedCbGap)
	ON_BN_CLICKED(IDC_CBDEL, &CDlgDLS::OnBnClickedCbDel)
	ON_BN_CLICKED(IDOK, &CDlgDLS::OnBnClickedOk)
	ON_BN_CLICKED(IDHELP, &CDlgDLS::OnBnClickedHelp)
END_MESSAGE_MAP()


// CDlgDLS �޽��� ó�����Դϴ�.

void CDlgDLS::GetItemPos(UINT id, int &x, int &y)
{
	CWnd *cwnd;
	CRect crec;

	cwnd = GetDlgItem (id);
	ASSERT(cwnd);
	cwnd->GetWindowRect(crec);
	ScreenToClient(crec);
	x = crec.left;
	y = crec.top;
}


void CDlgDLS::ShowDlgItem(UINT id, BOOL show)
{
	CWnd *cwnd;
	cwnd = GetDlgItem(id);
	ASSERT(cwnd);
	cwnd->ShowWindow((show) ? SW_SHOW: SW_HIDE);
}


void CDlgDLS::MoveDlgItem(UINT id, int x, int y)
{
	CWnd *cwnd;
	cwnd = GetDlgItem(id);
	ASSERT(cwnd);
	cwnd->SetWindowPos(NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE | SWP_NOZORDER);
}


void CDlgDLS::SizeDlgItem(UINT id, int w, int h)
{
	CWnd *cwnd;
	cwnd = GetDlgItem(id);
	ASSERT(cwnd);
	cwnd->SetWindowPos(NULL, 0, 0, w, h, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
}


double CDlgDLS::GetDlgItemDouble(UINT id)
{
	CString cStr;
	double dVal;

	if (!GetDlgItemText(id, cStr))
		return 0.0;

	cStr.Trim();
	dVal = _ttof(cStr);

	return dVal;
}


void CDlgDLS::SetCurveType()
{
	if (optOneLine.GetCheck()) {
		SetWindowPos(NULL, 0, 0, m_dlgSW + m_dlgFW, m_dlgSH + m_dlgFH, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);

		tbLength.EnableWindow(TRUE);

		ShowDlgItem (IDC_CBDEL, TRUE);
		ShowDlgItem (IDC_CBSTA, FALSE);
		ShowDlgItem (IDC_CBGHFH, FALSE);
		ShowDlgItem (IDC_CBGAP, FALSE);
		ShowDlgItem (IDC_TBCALK, TRUE);
		ShowDlgItem (IDC_TBCALKL, TRUE);

		MoveDlgItem(IDOK, m_bOKSX, m_bOKSY);
		MoveDlgItem(IDHELP, m_bHPSX, m_bHPSY);
		MoveDlgItem(IDC_CBROAD, m_bSTSX, m_bSTSY);
	}
	else {
		SetWindowPos(NULL, 0, 0, m_dlgLW + m_dlgFW, m_dlgLH + m_dlgFH, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);

		tbLength.EnableWindow(FALSE);

		ShowDlgItem (IDC_CBDEL, FALSE);
		ShowDlgItem (IDC_CBSTA, TRUE);
		ShowDlgItem (IDC_CBGHFH, TRUE);
		ShowDlgItem (IDC_CBGAP, TRUE);
		ShowDlgItem (IDC_TBCALK, FALSE);
		ShowDlgItem (IDC_TBCALKL, FALSE);

		MoveDlgItem(IDOK, m_bOKLX, m_bOKLY);
		MoveDlgItem(IDHELP, m_bHPLX, m_bHPLY);
		MoveDlgItem(IDC_CBROAD, m_bSTLX, m_bSTLY);
	}
}

void CDlgDLS::SetSTextState()
{
	if (chkDegnSlop.GetCheck()) {
		tbSlopTxtH.EnableWindow(TRUE);
		cbGetText1.EnableWindow(TRUE);
	}
	else {
		tbSlopTxtH.EnableWindow(FALSE);
		cbGetText1.EnableWindow(FALSE);
	}
}

void CDlgDLS::LoadSetting()
{
	BOOL check;

	check = m_regEdit.GetBoolean(_T("CurveType"), TRUE);
	CheckRadioButton(IDC_OPTONELINE, IDC_OPTVARLINE, (check) ? IDC_OPTONELINE: IDC_OPTVARLINE);
	//optOneLine.SetCheck(check); optVarLine.SetCheck(!check);
	tbXScale.SetWindowTextW(m_regEdit.GetString(_T("HScale"), _T("1200")));
	tbYScale.SetWindowTextW(m_regEdit.GetString(_T("VScale"), _T("200")));
	tbDegnInt.SetWindowTextW(m_regEdit.GetString(_T("CalcStep"), _T("1.0")));
	chkDegnSlop.SetCheck(m_regEdit.GetBoolean(_T("DispSText"), TRUE));
	tbSlopTxtH.SetWindowTextW(m_regEdit.GetString(_T("STextSize"), _T("3.0")));
	tbNum.SetWindowTextW(m_regEdit.GetString(_T("STextDigit"), _T("3")));
	chkLayer.SetCheck(m_regEdit.GetBoolean(_T("UseSLayer"), TRUE));
	check = m_regEdit.GetBoolean(_T("STAMark"), TRUE);
	CheckRadioButton(IDC_OPTSTA, IDC_OPTNO, (check) ? IDC_OPTSTA: IDC_OPTNO);
	//optSTA.SetCheck(check); optNO.SetCheck(!check);
	tbStaInt.SetWindowTextW(m_regEdit.GetString(_T("MPntStep"), _T("20")));
	tbSTA.SetWindowTextW(m_regEdit.GetString(_T("MPntBgn"), _T("0")));
	tbTextH.SetWindowTextW(m_regEdit.GetString(_T("MPntSize"), _T("2.5")));
	tbTblNum.SetWindowTextW(m_regEdit.GetString(_T("MPntDigi"), _T("2")));
	chkDegnK.SetCheck(m_regEdit.GetBoolean(_T("DispKVal"), TRUE));
	chkDegnTable.SetCheck(m_regEdit.GetBoolean(_T("DispCTable"), TRUE));
	chkSTA.SetCheck(m_regEdit.GetBoolean(_T("DispMPnt"), TRUE));
	chkGH.SetCheck(m_regEdit.GetBoolean(_T("DispGLevel"), TRUE));
	chkFH.SetCheck(m_regEdit.GetBoolean(_T("DispPLevel"), TRUE));
	chkGap.SetCheck(m_regEdit.GetBoolean(_T("DispGLevel"), TRUE));
}


void CDlgDLS::SaveSetting()
{
	CString cstr;

	m_regEdit.SetBoolean(_T("CurveType"), optOneLine.GetCheck());

	tbXScale.GetWindowTextW(cstr); m_regEdit.SetString(_T("HScale"), cstr);
	tbYScale.GetWindowTextW(cstr); m_regEdit.SetString(_T("VScale"), cstr);
	tbDegnInt.GetWindowTextW(cstr); m_regEdit.SetString(_T("CalcStep"), cstr);
	m_regEdit.SetBoolean(_T("DispSText"), chkDegnSlop.GetCheck());
	tbSlopTxtH.GetWindowTextW(cstr); m_regEdit.SetString(_T("STextSize"), cstr);
	tbNum.GetWindowTextW(cstr); m_regEdit.SetString(_T("STextDigit"), cstr);
	m_regEdit.SetBoolean(_T("UseSLayer"), chkLayer.GetCheck());
	m_regEdit.SetBoolean(_T("STAMark"), optSTA.GetCheck());
	tbStaInt.GetWindowTextW(cstr); m_regEdit.SetString(_T("MPntStep"), cstr);
	tbSTA.GetWindowTextW(cstr); m_regEdit.SetString(_T("MPntBgn"), cstr);
	tbTextH.GetWindowTextW(cstr); m_regEdit.SetString(_T("MPntSize"), cstr);
	tbTblNum.GetWindowTextW(cstr); m_regEdit.SetString(_T("MPntDigi"), cstr);
	m_regEdit.SetBoolean(_T("DispKVal"), chkDegnK.GetCheck());
	m_regEdit.SetBoolean(_T("DispCTable"), chkDegnTable.GetCheck());
	m_regEdit.SetBoolean(_T("DispMPnt"), chkSTA.GetCheck());
	m_regEdit.SetBoolean(_T("DispGLevel"), chkGH.GetCheck());
	m_regEdit.SetBoolean(_T("DispPLevel"), chkFH.GetCheck());
	m_regEdit.SetBoolean(_T("DispGLevel"), chkGap.GetCheck());
}


BOOL CDlgDLS::OnInitDialog()
{
	CWnd *cwnd;
	CRect crec;
	CSpinButtonCtrl *cSpin;

	CGcUiDialog::OnInitDialog();

	m_regEdit.SetKey(HKEY_CURRENT_USER, _T("SOFTWARE\\Magic\\MagicCivil\\DLS"));

	GetWindowRect(crec);
	m_dlgFW = crec.Width();
	m_dlgFH = crec.Height();
	GetClientRect(crec);
	m_dlgFW -= crec.Width();
	m_dlgFH -= crec.Height();

	GetItemPos(IDC_CBGHFH, m_bOKSX, m_bOKSY);
	GetItemPos(IDOK, m_bOKLX, m_bOKLY);
	GetItemPos(IDC_CBGAP, m_bHPSX, m_bHPSY);
	GetItemPos(IDHELP, m_bHPLX, m_bHPLY);
	GetItemPos(IDHELP, m_bSTSX, m_bSTSY);
	GetItemPos(IDC_CBROAD, m_bSTLX, m_bSTLY);

	cwnd = GetDlgItem(IDC_WINSIZE1);
	ASSERT(cwnd);
	cwnd->GetWindowRect(crec);
	m_dlgSW = crec.Width();
	m_dlgSH = crec.Height();
	cwnd = GetDlgItem(IDC_WINSIZE2);
	ASSERT(cwnd);
	cwnd->GetWindowRect(crec);
	m_dlgLW = crec.Width();
	m_dlgLH = crec.Height();

	cbScale.LoadBitmaps(IDB_TABLE, NULL, NULL, NULL);
	cbScale.SizeToContent();
	cbGetText1.LoadBitmaps(IDB_SELECT, NULL, NULL, NULL);
	cbGetText1.SizeToContent();
	cbGetText2.LoadBitmaps(IDB_SELECT, NULL, NULL, NULL);
	cbGetText2.SizeToContent();
	cbRoad.LoadBitmaps(IDB_SEARCH, NULL, NULL, NULL);
	cbRoad.SizeToContent();

	cSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPNBTN);
	cSpin->SetRange(0, 5);
	cSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPNTBLBTN);
	cSpin->SetRange(0, 3);

	LoadSetting();
	SetCurveType();
	SetSTextState();

	return TRUE;
}


void CDlgDLS::OnBnClickedCbScale()
{
	CHVScale hvScl;
	if (hvScl.DoModal () == IDOK) {
		tbXScale.SetWindowTextW(hvScl.tbXScale);
		tbYScale.SetWindowTextW(hvScl.tbYScale);
	}
}


void CDlgDLS::OnClickedChkDegnSlop()
{
	SetSTextState();
}


void CDlgDLS::OnBnClickedCbGetText1()
{
	GcDbEntity* entPtr;
	GcDbText* txtPtr;
	GcDbMText* mtxtPtr;
	CString cstr;

	BeginEditorCommand();

	entPtr = UserSelText(_T("\n���̸� ������ ���ڸ� �����Ͻʽÿ�: "), GcDb::kForRead);
	if (entPtr) {
		if (entPtr->isKindOf(GcDbText::desc())) {
			txtPtr = GcDbText::cast(entPtr);
			if (txtPtr) {
				cstr.Format(_T("%f"), txtPtr->height());
				TrimZeroStr(cstr.GetBuffer()); cstr.ReleaseBuffer();
				tbSlopTxtH.SetWindowTextW(cstr);
			}
		}
		else if (entPtr->isKindOf(GcDbMText::desc())) {
			mtxtPtr = GcDbMText::cast(entPtr);
			if (mtxtPtr) {
				cstr.Format(_T("%f"), mtxtPtr->textHeight());
				TrimZeroStr(cstr.GetBuffer()); cstr.ReleaseBuffer();
				tbSlopTxtH.SetWindowTextW(cstr);
			}
		}
		entPtr->close();
	}

	CompleteEditorCommand ();
}


void CDlgDLS::OnBnClickedCbGetText2()
{
	GcDbEntity* entPtr;
	GcDbText* txtPtr;
	GcDbMText* mtxtPtr;
	CString cstr;

	BeginEditorCommand();

	entPtr = UserSelText(_T("\n���̸� ������ ���ڸ� �����Ͻʽÿ�: "), GcDb::kForRead);
	if (entPtr) {
		if (entPtr->isKindOf(GcDbText::desc())) {
			txtPtr = GcDbText::cast(entPtr);
			if (txtPtr) {
				cstr.Format(_T("%f"), txtPtr->height());
				TrimZeroStr(cstr.GetBuffer()); cstr.ReleaseBuffer();
				tbTextH.SetWindowTextW(cstr);
			}
		}
		else if (entPtr->isKindOf(GcDbMText::desc())) {
			mtxtPtr = GcDbMText::cast(entPtr);
			if (mtxtPtr) {
				cstr.Format(_T("%f"), mtxtPtr->textHeight());
				TrimZeroStr(cstr.GetBuffer()); cstr.ReleaseBuffer();
				tbTextH.SetWindowTextW(cstr);
			}
		}
		entPtr->close();
	}

	CompleteEditorCommand ();
}


void CDlgDLS::OnBnClickedCbRoad()
{
	CStandardTable *sTable;
	CWnd *cWnd;
	
	cWnd = FindWindow(NULL, _T("���� ���� ����"));
	if (cWnd) {
		sTable = (CStandardTable *) cWnd;
		sTable->SetOwner(this);
		sTable->SetWindowPos(&CWnd::wndTop, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	}
	else {
		sTable = new CStandardTable(this);
		sTable->Create(CStandardTable::IDD);
	}

	sTable->ShowWindow(SW_SHOW);
}


void CDlgDLS::OnClickedOneLine()
{
	SetCurveType();
}

void CDlgDLS::AddCalsLayer()
{
	if (chkLayer.GetCheck()) {
		��ȹ�� = _T("CR-DEGN");
		���ڰ��� = _T("CR-TEXT");
		�׸��� = _T("CR-GRID");
		�׸��弼�� = _T("CR-GRID-VERT");
		���������� = _T("CR-TABL-LIN2");
		tbl������ = _T("CR-TABL-LIN1");
		tbl���¼� = _T("CR-TABL-LIN2");
		tbl������ = _T("CR-TABL-TEX1");
		tbl���빮�� = _T("CR-TABL-TEX2");
		ġ������ = _T("CR-DIMT");
		��ô�� = _T("CR-GSCL-LINE");
		��ô��Ÿ = _T("CR-GSCL-MISC");
		��ô���� = _T("CR-GSCL-TEXT");
	}
	else {
		��ȹ�� = _T("2");
		���ڰ��� = _T("3");
		�׸��� = _T("1");
		�׸��弼�� = _T("1");
		���������� = _T("1");
		tbl���빮�� = _T("3");
		tbl������ = _T("1");
		tbl������ = _T("1");
		tbl���¼� = _T("1");
		ġ������ = _T("3");
		��ô�� = _T("1");
		��ô��Ÿ = _T("1");
		��ô���� = _T("3");
	}

	AddNewLayer(��ȹ��, 7);
	AddNewLayer(���ڰ���, 3);
	AddNewLayer(�׸���, 1);
	AddNewLayer(�׸��弼��, 1);
	AddNewLayer(����������, 1);
	AddNewLayer(tbl���빮��, 3);
	AddNewLayer(tbl������, 4);
	AddNewLayer(tbl������, 6);
	AddNewLayer(tbl���¼�, 1);
	AddNewLayer(ġ������, 3);
	AddNewLayer(��ô��, 2);
	AddNewLayer(��ô��Ÿ, 1);
	AddNewLayer(��ô����, 3);
}


BOOL GetEL(double* dVal)
{
	GcGePoint3d vBase;
	GcDbObjectId vObjID;
	CString sKey;
	CString sNumeric;
	CString sGetEL; // ����EL
	GcDbObjectId entID;
	GcDbEntity* entPtr;
	GcDbText* txtPtr;
	GcDbMText* mtxtPtr;
	GcDbAttribute* attPtr;
	int rt;

	while (1) {
		rt = UserSelRealEnt(dVal, entID, _T("��� ���� E.L �Է� �Ǵ� ���� ����(Select) "), _T("���� ���� "));
		if (rt == 1)
			return TRUE;
		else if (rt == 2) {
			gcdbOpenObject(entPtr, entID, GcDb::kForRead);
			if (entPtr->isKindOf(GcDbText::desc())) {
				txtPtr = GcDbText::cast(entPtr);
				sNumeric = txtPtr->textString();
			}
			else if (entPtr->isKindOf(GcDbMText::desc())) {
				mtxtPtr = GcDbMText::cast(entPtr);
				sNumeric = mtxtPtr->text();
			}
			else if (entPtr->isKindOf(GcDbAttribute::desc())) {
				attPtr = GcDbAttribute::cast(entPtr);
				sNumeric = attPtr->textString();
			}
			else {
				gcutPrintf (_T("** ������ ��ü�� ���ڰ� �ƴմϴ� **"));
				continue;
			}
		
			if (IsNumStr(sNumeric))
				return TRUE;
			else
				gcutPrintf (_T("** ������ ���ڴ� ���ڰ� �ƴմϴ� **"));
		}
		else
			return FALSE;
	}
}


// �ڵ� �迭�� ���
void CDlgDLS::HandleToArray(LPCTSTR hdlStr)
{
	sHandle.Add(hdlStr);
}

void CDlgDLS::HandleToArray (GcDbEntity *entPtr)
{
	CString hdlStr;

	hdlStr = GetObjectHandleID(entPtr);
	sHandle.Add(hdlStr);
}


// LW�������� �׸���(���̾�� ���� �Բ� ����)
void CDlgDLS::DrawPolyLine(GcGePoint2dArray pntList, LPCTSTR plLayer, int plColor, BOOL bHandle, BOOL bOne)
{
	GcDbPolyline *polEnt;
	GcGePoint3d pnt3d;
	GcGePoint2d pnt2d;
	int pntNum;
	int i;
	CString hdlStr;
	resbuf rBuf;

	polEnt = new GcDbPolyline();

	pntNum = pntList.length();
	for (i = 0; i < pntNum; i ++)
		polEnt->addVertexAt(i, pntList[i]);

	//polEnt->setColor(GcColor::gcByLayer);
	AddNewLayer(plLayer, plColor);
	polEnt->setLayer(plLayer);

	AddCurrSpace(polEnt);
	polEnt->close();

	hdlStr = GetObjectHandleID(polEnt);

	if (bOne)
		HandleToArray(hdlStr);

	if (bHandle) {
		// �� �Լ��� �̿��� SUB���� �ٽ� �������� ���� �� �ֵ��� �ڵ���
		rBuf.restype = RTSTR;
		rBuf.resval.rstring = _tcsdup(hdlStr);
		gcedSetVar(_T("USERS4"), &rBuf);
		free(rBuf.resval.rstring);
	}

	TransUCSobj(polEnt);
}

void CDlgDLS::TableTextSetting(GcDbText* oText, GcGePoint3d vTextPnt,
				GcDb::TextHorzMode horMod, GcDb::TextVertMode verMod)
{
	oText->setHorizontalMode(horMod);
	oText->setVerticalMode(verMod);
	oText->setAlignmentPoint(vTextPnt);
	oText->setRotation(PI2);
	oText->setWidthFactor(1.0);
	oText->setLayer(tbl���빮��);
	TransUCSobj(oText);
}

// + ü�ο�
void CDlgDLS::WritePlus(GcDbEntity* oFH, GcDbEntity* oGR, GcGePoint3d vInsPnt, GcGePoint3d vTextPnt,
				GcGePoint3d vGLPnt, double dEL, int iOpt)
{
	GcDbPolyline *polEnt;
	GcDbPolyline* pFH;
	GcDbPolyline* pGR;
	GcDbObjectId entID;
	GcDbEntity* entPtr;
	CString sTblDec;
	double dDiv;
	GcGePoint3d dULow, dUMax;
	GcGePoint3d vULow, vUMax;
	GcGePoint3dArray pntArr;
	GcGePoint3d vCrossPnt;
	GcGePoint3d vIntPntGR;
	GcGePoint3d vIntPntFL;
	GcGePoint2dArray pntList;
	GcGePoint2d pnt2d;
	int iDec;
	CString cstr;
	double dText;

	tbTblNum.GetWindowTextW(cstr);
	iDec = _ttoi(cstr);
	sTblDec = GetFormat(iDec);

	// UCS������
	pFH = NULL;
	pGR = NULL;
	if (oGR == NULL) {
		pFH = GcDbPolyline::cast(oFH);
		pFH->getStartPoint(dULow);
		pFH->getEndPoint(dUMax);
	}
	else {
		pGR = GcDbPolyline::cast(oGR);
		pGR->getStartPoint(dULow);
		pGR->getEndPoint(dUMax);
	}
	gcdbWcs2Ucs(asDblArray(dULow), asDblArray(vULow), ::kTrue);
	gcdbWcs2Ucs(asDblArray(dUMax), asDblArray(vUMax), ::kTrue);

	if (vUMax[X] < vULow[X]) {
		if (pGR == NULL)
			ReverseCoordinates(pFH);
		else
			ReverseCoordinates(pGR);
		SwapVoidData(asDblArray(vULow), asDblArray(vUMax), sizeof(gds_point));
	}

	dXScale = 1000 / GetDlgItemDouble(IDC_TBXSCALE);
	dYScale = 1000 / GetDlgItemDouble(IDC_TBYSCALE);
	dTxtScale = GetDlgItemDouble(IDC_TBTEXTH) / DefaultTextH;
	dLength = fabs(vUMax[X] - vULow[X]) * (dTxtScale / 1000.0);

	// �׸� ��
	pntList.removeAll();
	pnt2d.set(vInsPnt[X], vTextPnt[Y] - (0.5 * dTxtScale));
	pntList.append(pnt2d);
	pnt2d.set(vInsPnt[X], vTextPnt[Y] + (0.5 * dTxtScale));
	pntList.append(pnt2d);
	DrawPolyLine(pntList, ����������, 1, TRUE);

	GetVariable(_T("USERS4"), cstr);
	entID = GetObjectByHandle(cstr);
	if (gcdbOpenObject(entPtr, entID, GcDb::kForRead) == Gcad::eOk) {
		polEnt = GcDbPolyline::cast(entPtr);
		polEnt->close();
	}
	else
		::MessageBox(NULL, _T("can not get Object by Handle"), _T("Error"), MB_OK);

	if (optSTA.GetCheck())
		dDiv = 1000.0;
	else
		dDiv = GetDlgItemDouble(IDC_TBSTAINT);

	switch (iOpt) {
	case 1: // ����:�������� ���������� �Ÿ�
		dText = (vInsPnt[0] - vULow[0]) * (GetDlgItemDouble(IDC_TBXSCALE) / 1000) + GetDlgItemDouble(IDC_TBSTA);
		if (dText >= dDiv)
			dText = fmod(dText, dDiv);
		sText.Format(_T("%.2f"), dText);
		break;
	case 2: // ���ݰ�
		pntArr.removeAll();
		if (polEnt->intersectWith(oGR, GcDb::kExtendThis, pntArr) == Gcad::eOk)
			gcdbWcs2Ucs(asDblArray(pntArr[0]), asDblArray(vCrossPnt), ::kTrue);

		dText = (vCrossPnt[Y] - vGLPnt[Y]) / dYScale + dEL;
		sText.Format(sTblDec, dText);
		break;
	case 3: // ��ȹ��
		pntArr.removeAll();
		if (polEnt->intersectWith(oFH, GcDb::kExtendThis, pntArr) == Gcad::eOk)
			gcdbWcs2Ucs(asDblArray(pntArr[0]), asDblArray(vCrossPnt), ::kTrue);

		dText = (vCrossPnt[Y] - vGLPnt[Y]) / dYScale + dEL;
		sText.Format(sTblDec, dText);
		break;
	case 4: // ������
		// ���ݼ� ������
		pntArr.removeAll();
		if (polEnt->intersectWith(oGR, GcDb::kExtendThis, pntArr) == Gcad::eOk)
			gcdbWcs2Ucs(asDblArray(pntArr[0]), asDblArray(vIntPntGR), ::kTrue);

		// ��ȹ�� ������
		pntArr.removeAll();
		if (polEnt->intersectWith(oFH, GcDb::kExtendThis, pntArr) == Gcad::eOk)
			gcdbWcs2Ucs(asDblArray(pntArr[0]), asDblArray(vIntPntFL), ::kTrue);

		// ������
		if (DoubleRound(vIntPntFL[Y] - vIntPntGR[Y], 2) >= 0) {
			dText = vIntPntFL[Y] / dYScale - vIntPntGR[Y] / dYScale;
			sText.Format(_T("+") + sTblDec, DoubleAbs(dText));
		}
		else {
			dText = vIntPntFL[Y] / dYScale - vIntPntGR[Y] / dYScale;
			sText.Format(_T("-") + sTblDec, DoubleAbs(dText));
		}
		break;
	}

	dTextPnt[X] = vInsPnt[X];
	dTextPnt[Y] = vTextPnt[Y];
	dTextPnt[Z] = 0.0;

	oText = new GcDbText(dTextPnt, sText);
	oText->setHeight(GetDlgItemDouble(IDC_TBTEXTH));
	AddCurrSpace(oText);
	TableTextSetting(oText, dTextPnt);
	oText->close();
}

// ���� ����׸���-����� �ٽö��� �и���(2007.12.7)
// ����,VIP,����,�������
void CDlgDLS::DrawCurve(GcGePoint3d vPntS, GcGePoint3d vPntI, GcGePoint3d vPntE, double dLength)
{
	double dDegnInt;
	double dDistSX;
	double dDistSY;
	double dDistEX;
	double dDistEY;
	double vSlopS;
	double vSlopE;
	GcGePoint2dArray dXYlist;
	int iCnt; // ��ǥ����
	int iNum;
	GcGePoint3d vInsPnt; // ������
	double vCal; // EL(��ȹ��-������)
	double dCalK; // ����� K
	CString sDec;
	int iColor;
	GcGePoint2d pnt2d;

	sDec = GetFormat(GetDlgItemInt(IDC_TBNUM));
	
	if (vPntS[X] > vPntE[X])
		SwapVoidData(&vPntS, &vPntE, sizeof(GcGePoint3d));

	dXScale = 1000 / GetDlgItemDouble(IDC_TBXSCALE);
	dYScale = 1000 / GetDlgItemDouble(IDC_TBYSCALE);
	dDegnInt = GetDlgItemDouble(IDC_TBDEGNINT);

	if (chkLayer.GetCheck()) {
		��ȹ�� = _T("CR-DEGN");
		iColor = 7;
	}
	else {
		��ȹ�� = _T("2");
		iColor = 2;
	}
	
	dDistSX = (vPntI[X] - vPntS[X]) * GetDlgItemDouble(IDC_TBXSCALE) / 1000;
	dDistSY = (vPntI[Y] - vPntS[Y]) * GetDlgItemDouble(IDC_TBYSCALE) / 1000;
	dDistEX = (vPntE[X] - vPntI[X]) * GetDlgItemDouble(IDC_TBXSCALE) / 1000;
	dDistEY = (vPntE[Y] - vPntI[Y]) * GetDlgItemDouble(IDC_TBYSCALE) / 1000;
	
	vSlopS = dDistSY * 100 / dDistSX;
	vSlopE = dDistEY * 100 / dDistEX;
	
	vInsPnt[X] = vPntI[X] - (dLength * dXScale) / 2;
	vInsPnt[Y] = vPntI[Y] - (dLength / 2 * vSlopS / 100) * dYScale;
	
	// ���ϴ� ��ǥ ������ 2��+����2-1
	// ReDim dXYlist(dLength / dDegnInt * 2 + 2 - 1)
	iNum = (int) ceil(dLength / dDegnInt) + 1;
	dXYlist.removeAll();
	GcGePlane plane;
	dXYlist.append(vInsPnt.convert2d(plane)); // ����
	for (iCnt = 1; iCnt < iNum; iCnt ++) {
		vCal = (vSlopS / 100 * dDegnInt * iCnt) -
			((vSlopS - vSlopE) / (200 * dLength) * DoubleDouble(dDegnInt * iCnt));
		pnt2d.set(vInsPnt[X] + (dDegnInt * iCnt * dXScale), vInsPnt[Y] + (vCal * dYScale));
		dXYlist.append(pnt2d);
	}
	
	DrawPolyLine(dXYlist, ��ȹ��, iColor, FALSE, TRUE);

	if (chkDegnSlop.GetCheck()) {
		dSlopF = DoubleRound((dDistSY / dDistSX) * 100, 4);
		dTextPnt[X] = (vPntS[X] + vPntI[X]) / 2;
		dTextPnt[Y] = (vPntS[Y] + vPntI[Y]) / 2 + GetDlgItemDouble(IDC_TBSLOPTXTH);
		dTextPnt[Z] = 0.0;

		sText.Format(_T("S=") + sDec + _T("%%"), dSlopF);
		oText = new GcDbText(dTextPnt, sText, NULL, GetDlgItemDouble(IDC_TBSLOPTXTH),
						atan((dDistSY * dYScale) / (dDistSX * dXScale)));
		AddCurrSpace(oText);
		oText->setAlignmentPoint(dTextPnt);
		oText->setVerticalMode(GcDb::kTextBottom);
		oText->setHorizontalMode(GcDb::kTextCenter);
		oText->setLayer(ġ������);
		TransUCSobj(oText);
		oText->close();
		HandleToArray(oText);
		
		dSlopS = DoubleRound((dDistEY / dDistEX) * 100, 4);
		dTextPnt[X] = (vPntI[X] + vPntE[X]) / 2;
		dTextPnt[Y] = (vPntI[Y] + vPntE[Y]) / 2 + GetDlgItemDouble(IDC_TBSLOPTXTH);
		dTextPnt[Z] = 0.0;

		sText.Format(_T("S=") + sDec + _T("%%"), dSlopS);
		oText = new GcDbText(dTextPnt, sText, NULL, GetDlgItemDouble(IDC_TBSLOPTXTH),
						atan((dDistEY * dYScale) / (dDistEX * dXScale)));
		AddCurrSpace(oText);
		oText->setAlignmentPoint(dTextPnt);
		oText->setVerticalMode(GcDb::kTextBottom);
		oText->setHorizontalMode(GcDb::kTextCenter);
		oText->setLayer(ġ������);
		TransUCSobj(oText);
		oText->close();
		HandleToArray(oText);

		dCalK = DoubleRound(dLength / DoubleAbs((dSlopS - dSlopF) * 100) * 100, 2);
		CString cstr;
		cstr.Format(_T("%.2f"), dCalK);
		SetDlgItemText(IDC_TBCALK, cstr);
	}

	GetDlgItem(IDC_CBDEL)->EnableWindow(TRUE);
}


void CDlgDLS::OnBnClickedCbPlusChain()
{
	CString sLock;
	GcDbEntity* oFH;
	GcDbEntity* oGR;
	GcGePoint3d vPntGL;
	GcGePoint3dArray vPlus;
	GcGePoint3d dULow, dUMax;
	GcGePoint3d vULow, vUMax;
	GcGePoint3d uPnt, vPnt;
	GcDbPolyline* pFH;
	GcDbPolyline* pGR;
	GcGePoint3d gePnt;
	GcGePoint3d vSTA;
	GcGePoint3d vGH;
	GcGePoint3d vFH;
	GcGePoint3d vGap;
	double dEL;
	CString cstr;
	int rt;

	if (!chkSTA.GetCheck() && !chkGH.GetCheck() &&
		!chkFH.GetCheck() && !chkGap.GetCheck()) {
		MessageBox(_T("����,���ݰ�,��ȹ��,������ �� ǥ�� ��� üũ �� �����Ͻʽÿ�"), _T("DLS"), MB_OK);
		return;
	}

	AddCalsLayer();
	sLock = LockBackUp();
	
	dXScale = 1000 / GetDlgItemDouble(IDC_TBXSCALE);
	dYScale = 1000 / GetDlgItemDouble(IDC_TBYSCALE);
	dTxtScale = GetDlgItemDouble(IDC_TBTEXTH) / DefaultTextH;

	oFH = NULL;
	oGR = NULL;
	pFH = NULL;
	pGR = NULL;

	BeginEditorCommand();

	if (chkGap.GetCheck() || chkGH.GetCheck() && chkFH.GetCheck()) {
		oGR = UserSelPLine(_T("���ݼ� ����:"), GcDb::kForRead);
		if (oGR == NULL)
			goto ErrorHandler;
		oGR->highlight();
		oFH = UserSelPLine(_T("��ȹ�� ����:"), GcDb::kForRead);
		if (oFH == NULL) {
			oGR->unhighlight();
			goto ErrorHandler;
		}
		oGR->unhighlight();
	}
	else if (chkGH.GetCheck()) {
		oGR = UserSelPLine(_T("���ݼ� ����:"), GcDb::kForRead);
		if (oGR == NULL)
			goto ErrorHandler;
		oGR->highlight();
	}
	else if (chkFH.GetCheck()) {
		oFH = UserSelPLine(_T("��ȹ�� ����:"), GcDb::kForRead);
		if (oFH == NULL)
			goto ErrorHandler;
		oFH->highlight();
	}
	else if (chkSTA.GetCheck()) {
		oGR = UserSelPLine(_T("���ݼ� ����:"), GcDb::kForRead);
		if (oGR == NULL)
			goto ErrorHandler;
		oGR->highlight();
	}

	if (oGR == NULL) {
		if (oFH->isKindOf(GcDbLine::desc()))
			oFH = ConvertPoly(oFH);
		pFH = GcDbPolyline::cast(oFH);
	}
	else {
		if (oGR->isKindOf(GcDbLine::desc()))
			oGR = ConvertPoly(oGR);
		pGR = GcDbPolyline::cast(oGR);
	}

	// UCS������
	if (pGR == NULL) {
		pFH->getStartPoint(dULow);
		pFH->getEndPoint(dUMax);
	}
	else {
		pGR->getStartPoint(dULow);
		pGR->getEndPoint(dUMax);
	}
	gcdbWcs2Ucs(asDblArray(dULow), asDblArray(vULow), ::kTrue);
	gcdbWcs2Ucs(asDblArray(dUMax), asDblArray(vUMax), ::kTrue);

	if (vUMax[X] < vULow[X]) {
		if (pGR == NULL)
			ReverseCoordinates(pFH);
		else
			ReverseCoordinates(pGR);
		SwapVoidData(asDblArray(vULow), asDblArray(vUMax), sizeof(gds_point));
	}

	if (chkGH.GetCheck() || chkFH.GetCheck()) {
		if (!GetEL(&dEL))
			goto ErrorHandler;
		gcedInitGet(RSG_OTHER, NULL);
		cstr.Format(_T("���� EL %.3fm�� �� ����:"), dEL);
		rt = gcedGetPoint(NULL, cstr, asDblArray(vPntGL));

		if (vUMax[X] > vULow[X])
			dSpnt[X] = vULow[X];
		else
			dSpnt[X] = vUMax[X];
		dSpnt[Y] = vPntGL[Y];
		dSpnt[Z] = 0;

		vPntGL = dSpnt;
	}

	// +ü�� ��� ������ �迭��
	while (1) {
		if (GetUcsPoint(NULL, _T("ǥ���� + ���� ��� ����:"), asDblArray(vPnt)) != RTNORM)
			break;
		vPlus.append(vPnt);
	}
	if (rt == RTCAN || vPlus.length() < 1)
		goto ErrorHandler;

	// ����,���ݰ�,��ȹ��,������ ǥ�� ��ġ
	if (chkSTA.GetCheck())
		GetUcsPoint(NULL, _T("������ ǥ���� ��ġ ����:"), asDblArray(vSTA));
	if (chkGH.GetCheck())
		GetUcsPoint(NULL, _T("���ݰ� ǥ���� ��ġ ����:"), asDblArray(vGH));
	if (chkFH.GetCheck())
		GetUcsPoint(NULL, _T("��ȹ�� ǥ���� ��ġ ����:"), asDblArray(vFH));
	if (chkGap.GetCheck())
		GetUcsPoint(NULL, _T("������ ǥ���� ��ġ ����:"), asDblArray(vGap));

	int i;
	for (i = 0; i < vPlus.length(); i ++) {
		if (chkSTA.GetCheck())
			WritePlus(oFH, oGR, vPlus[i], vSTA, vPntGL, dEL, 1);
		if (chkGH.GetCheck())
			WritePlus(oFH, oGR, vPlus[i], vGH, vPntGL, dEL, 2);
		if (chkFH.GetCheck())
			WritePlus(oFH, oGR, vPlus[i], vFH, vPntGL, dEL, 3);
		if (chkGap.GetCheck())
			WritePlus(oFH, oGR, vPlus[i], vGap, vPntGL, dEL, 4);
	}

ErrorHandler:
	LockRestore(sLock);
	if (oGR) {
		oGR->unhighlight();
		oGR->close();
	}
	if (oFH) {
		oFH->unhighlight();
		oFH->close();
	}

	CompleteEditorCommand ();
	gcedCommandS(RTSTR, _T("_REDRAW"), 0);
}

void CDlgDLS::OnBnClickedCbDesign()
{
	double dDegnInt; // ��갣��
	double dDistSX;
	double dDistSY;
	double dDistEX;
	double dDistEY;
	GcGePoint3d vPntS;
	GcGePoint3d vPntI;
	GcGePoint3d vPntE;
	GcGePoint2dArray dXYlist;
	GcGePoint2d pnt2d;
	int iCnt; // ��ǥ����
	GcGePoint3d vInsPnt; // ������
	double vCal; // EL(��ȹ��-������)
	double dCalK; // ����� K
	CString sDec;
	CString cstr;
	CString sLock;

	sDec = GetFormat(GetDlgItemInt(IDC_TBNUM));

	if (optOneLine.GetCheck()) {
		GetDlgItemText(IDC_TBLENGTH, cstr);
		cstr.Trim();
		if (cstr.IsEmpty() || _ttof(cstr) == 0) {
			::MessageBox(NULL, _T("��� ���� ���� �������� �ʾҽ��ϴ�."), _T("DLS"), MB_OK);
			tbLength.SetFocus();
			return;
		}
	}

	dXScale = 1000 / GetDlgItemDouble(IDC_TBXSCALE);
	dYScale = 1000 / GetDlgItemDouble(IDC_TBYSCALE);
	dDegnInt = GetDlgItemDouble(IDC_TBDEGNINT);

	// ����ũ��2.5�������� ��������Ƿ�
	// ����ũ��/2.5�� ������ ���̺�Ȯ��
	dTxtScale = GetDlgItemDouble(IDC_TBTEXTH) / DefaultTextH;

	int iColor;
	if (chkLayer.GetCheck()) {
		��ȹ�� = _T("CR-DEGN");
		iColor = 7;
	}
	else {
		��ȹ�� = _T("2");
		iColor = 2;
	}

	int rt;
	GcGePoint3d uPnt;

	AddCalsLayer();
	sLock = LockBackUp();

	BeginEditorCommand();

	if (optOneLine.GetCheck()) { // �ϳ��� ���;
		// �迭 �ʱ�ȭ
		sHandle.RemoveAll();

		if (GetUcsPoint(NULL, _T("���� ����:"), asDblArray(vPntS)) != RTNORM)
			goto ErrorHandler;

		gcedInitGet(RSG_DASH, NULL);
		if (GetUcsPoint(asDblArray(vPntS), _T("VIP �� ����:"), asDblArray(vPntI)) != RTNORM)
			goto ErrorHandler;
		
		gcedInitGet(RSG_DASH, NULL);
		if (GetUcsPoint(asDblArray(vPntI), _T("���� ����:"), asDblArray(vPntE)) != RTNORM)
			goto ErrorHandler;

		vDelS = vPntS; vDelI = vPntI; vDelE = vPntE;
		DrawCurve(vPntS, vPntI, vPntE, GetDlgItemDouble(IDC_TBLENGTH));
	}
	else { // ���ӵ� ���
		GcGeDoubleArray dAryL; // �Է¹��� ��� ���̸� ���� �迭
		GcGePoint2dArray dIP; // ������ IP XY���� �迭
		CString sKVal;
		GcGePoint3d vKTmp;
		double dGL;
		GcGePoint3d vTmpTable;
		int  iNum;
		int i, j;

		if (GetUcsPoint(NULL, _T("\n���� ���μ��� �� �ϴ� �� ����:"), asDblArray(vKTmp)) != RTNORM)
			goto ErrorHandler;
		rt = gcedGetReal(_T("\n���� ���μ��� �� �ϴ� �� �Է�:"), &dGL);

		if (chkDegnTable.GetCheck()) {
			if (GetUcsPoint(NULL, _T("\n���ܼ����� ǥ���� ���̺� ��� �� ����:"), asDblArray(vTmpTable)) != RTNORM)
				goto ErrorHandler;
		}

		j = 0;
		while (1) {
			if (GetUcsPoint(NULL, _T("\nIP ����:"), asDblArray(vPntS)) != RTNORM)
				break;
			GcGePlane plane;
			dIP.append(vPntS.convert2d(plane));

			rt = gcedGetReal(_T("\n��� ���� �Է�:"), &dLength);
			if (rt != RTNORM)
				break;
			dAryL.append(dLength);

			// ��� ���
			if (dIP.length() >= 2) {
				dDistSX = (dIP[j - 1].x - dIP[j - 2].x) / dXScale;
				dDistSY = (dIP[j - 1].y - dIP[j - 2].y) / dYScale;
				dDistEX = (dIP[j].x - dIP[j - 1].x) / dXScale;
				dDistEY = (dIP[j].y - dIP[j - 1].y) / dYScale;
				dSlopF = DoubleRound((dDistSY / dDistSX) * 100, 4);
				dSlopS = DoubleRound((dDistEY / dDistEX) * 100, 4);
				dCalK = DoubleRound(dAryL[j - 1] / DoubleAbs((dSlopS - dSlopF) * 100) * 100, 2);
				sKVal.Format(_T("L=%.2f K=%.2f"), dAryL[j - 1], dCalK);
			}
			
			if (j > 0) {
				if (dIP.length() < 3) {
					dDistEX = (dIP[j].x - dIP[j - 1].x) / dXScale;
					dDistEY = (dIP[j].y - dIP[j - 1].y) / dYScale;
					dSlopS = DoubleRound((dDistEY / dDistEX) * 100, 4);
				}
				if (chkDegnSlop.GetCheck()) {
					dTextPnt[X] = (dIP[j - 1].x + dIP[j].x) / 2;
					dTextPnt[Y] = ((dIP[j - 1].y + dIP[j].y) / 2) + GetDlgItemDouble(IDC_TBSLOPTXTH);
					dTextPnt[Z] = 0.0;

					sText.Format(_T("S=") + sDec + _T("%%"),  dSlopS);
					oText = new GcDbText(dTextPnt, sText, NULL, GetDlgItemDouble(IDC_TBSLOPTXTH),
									atan((dDistEY * dYScale) / (dDistEX * dXScale)));
					AddCurrSpace(oText);
					oText->setAlignmentPoint(dTextPnt);
					oText->setVerticalMode(GcDb::kTextBottom);
					oText->setHorizontalMode(GcDb::kTextCenter);
					oText->setLayer(ġ������);
					TransUCSobj(oText);
					oText->close();
				}
			}

			if (chkDegnK.GetCheck()) {
				if (j > 0) {
					if (dLength != 0) {
						dXYlist.removeAll();
						pnt2d.set(vPntS[0] - ((dLength / 2) * dXScale), vKTmp[Y] + 10);
						dXYlist.append(pnt2d);
						pnt2d.set(vPntS[0] + ((dLength / 2) * dXScale), vKTmp[Y] + 10);
						dXYlist.append(pnt2d);
						DrawPolyLine(dXYlist, tbl���¼�, 1, FALSE);
					}
					if (dIP.length() > 2) {
						dTextPnt[X] = dIP[j - 1].x;
						dTextPnt[Y] = vKTmp[Y] + 9;
						dTextPnt[Z] = 0.0;

						oText = new GcDbText(dTextPnt, sKVal, NULL, GetDlgItemDouble(IDC_TBTEXTH), 0.0);
						AddCurrSpace(oText);
						oText->setAlignmentPoint(dTextPnt);
						oText->setVerticalMode(GcDb::kTextTop);
						oText->setHorizontalMode(GcDb::kTextCenter);
						oText->setLayer(ġ������);
						TransUCSobj(oText);
						oText->close();
					}
				}
			}

			if (chkDegnTable.GetCheck()) {
				GcDbCircle* oCircle;
				GcGePoint3d dCenPnt;
				dCenPnt[X] = dIP[j].x;
				dCenPnt[Y] = vTmpTable[Y] - (7.5 * dTxtScale);
				dCenPnt[Z] = 0.0;
			
				oCircle = new GcDbCircle(dCenPnt, GcGeVector3d::kZAxis, (6.5 * dTxtScale));
				AddCurrSpace(oCircle);
				oCircle->setLayer(����������);
				//oCircle->setColorIndex(GcColor::gcByLayer);
				TransUCSobj(oCircle);
				oCircle->close();
				
				sText.Format(_T("%.3f"), dGL + ((vPntS[Y] - vKTmp[Y]) / dYScale));
				oText = new GcDbText(dCenPnt, sText, NULL, GetDlgItemDouble(IDC_TBTEXTH), PI2);
				AddCurrSpace(oText);
				oText->setAlignmentPoint(dCenPnt);
				oText->setVerticalMode(GcDb::kTextVertMid);
				oText->setHorizontalMode(GcDb::kTextCenter);
				oText->setLayer(tbl���빮��);
				oText->setWidthFactor(0.9);
				TransUCSobj(oText);
				oText->close();
				
				// ��缱
				if (dIP.length() > 1) {
					if (DoubleRound(dIP[j].y, 5) == DoubleRound(dIP[j - 1].y, 5)) {
						dXYlist.removeAll();
						pnt2d.set(dIP[j - 1].x + (6.5 * dTxtScale), vTmpTable[Y] - (7.5 * dTxtScale));
						dXYlist.append(pnt2d);
						pnt2d.set(dIP[j].x - 6.5, vTmpTable[Y] - (7.5 * dTxtScale));
						dXYlist.append(pnt2d);
						DrawPolyLine(dXYlist, ����������, 1, FALSE);
					}
					else if (dIP[j].y > dIP[j - 1].y) { // +���
						dXYlist.removeAll();
						pnt2d.set(dIP[j - 1].x, vTmpTable[Y] - (14 * dTxtScale));
						dXYlist.append(pnt2d);
						pnt2d.set(dIP[j].x, vTmpTable[Y] - (1 * dTxtScale));
						dXYlist.append(pnt2d);
						DrawPolyLine(dXYlist, ����������, 1, FALSE);
					}
					else if (dIP[j].y < dIP[j - 1].y) { // -���
						dXYlist.removeAll();
						pnt2d.set(dIP[j - 1].x, vTmpTable[Y] - (1 * dTxtScale));
						dXYlist.append(pnt2d);
						pnt2d.set(dIP[j].x, vTmpTable[Y] - (14 * dTxtScale));
						dXYlist.append(pnt2d);
						DrawPolyLine(dXYlist, ����������, 1, FALSE);
					}
					
					// tbl������ ��� ����
					dTextPnt[0] = (dIP[j].x + dIP[j - 1].x) / 2;
					dTextPnt[1] = vTmpTable[Y] - (3 * dTxtScale);
					dTextPnt[2] = 0.0;
					
					sText.Format(_T("S=%.4f%%"), dSlopS);
					oText = new GcDbText(dTextPnt, sText, NULL, GetDlgItemDouble(IDC_TBTEXTH), 0.0);
					AddCurrSpace(oText);
					oText->setAlignmentPoint(dTextPnt);
					oText->setVerticalMode(GcDb::kTextVertMid);
					oText->setHorizontalMode(GcDb::kTextCenter);
					oText->setLayer(tbl���빮��);
					TransUCSobj(oText);
					oText->close();
					
					dTextPnt[0] = (dIP[j].x + dIP[j - 1].x) / 2;
					dTextPnt[1] = vTmpTable[Y] - (12 * dTxtScale);
					dTextPnt[2] = 0.0;
					 
					sText.Format(_T("H=%.2f L=%.2f"), DoubleAbs(dDistEY), dDistEX);
					oText = new GcDbText(dTextPnt, sText, NULL, GetDlgItemDouble(IDC_TBTEXTH), 0.0);
					AddCurrSpace(oText);
					oText->setAlignmentPoint(dTextPnt);
					oText->setVerticalMode(GcDb::kTextVertMid);
					oText->setHorizontalMode(GcDb::kTextCenter);
					oText->setLayer(tbl���빮��);
					TransUCSobj(oText);
					oText->close();
				}
			}
			
			j ++;
		}
		
		if (dIP.length() >= 2) {
			// ����
			dXYlist.removeAll();
			dXYlist.append(dIP[0]);
			for (i = 1; i < dIP.length(); i ++) {
				dDistSX = (dIP[i].x - dIP[i - 1].x) / dXScale;
				dDistSY = (dIP[i].y - dIP[i - 1].y) / dYScale;
				dSlopF = (dDistSY / dDistSX) * 100;
				if (i < (dIP.length() - 1)) {
					dDistEX = (dIP[i + 1].x - dIP[i].x) / dXScale;
					dDistEY = (dIP[i + 1].y - dIP[i].y) / dYScale;
					dSlopS = (dDistEY / dDistEX) * 100;
				}
				else {
					dSlopS = dSlopF;
				}
					
				vInsPnt[X] = dIP[i].x - (dAryL[i] * dXScale) / 2;
				vInsPnt[Y] = dIP[i].y - (dAryL[i] / 2 * dSlopF / 100) * dYScale;
				vInsPnt[Z] = 0.0;
					
				// ���ϴ� ��ǥ ������ 2��+����2-1 + �����ִ밪
				//ReDim Preserve dXYlist(0 To dAryL(i / 2) / dDegnInt * 2 + 2 - 1 + iTmpMax)
				iNum = (int) ceil(dAryL[i] / dDegnInt) + 1;
				GcGePlane plane;
				dXYlist.append(vInsPnt.convert2d(plane));
				for (iCnt = 1; iCnt < iNum; iCnt ++) {
					vCal = (dSlopF / 100 * dDegnInt * iCnt) -
						((dSlopF - dSlopS) / (200 * dAryL[i]) * DoubleDouble(dDegnInt * iCnt));
					pnt2d.set(vInsPnt[X] + (dDegnInt * iCnt * dXScale), vInsPnt[Y] + (vCal * dYScale));
					dXYlist.append(pnt2d);
				}
			}
			DrawPolyLine(dXYlist, ��ȹ��, 7, FALSE);
		}
	}
	
ErrorHandler:
	LockRestore(sLock);
	CompleteEditorCommand ();
	gcedCommandS(RTSTR, _T("_REDRAW"), 0);
}


void CDlgDLS::OnBnClickedCbSTA()
{
	CString sLock;
	double dDiv;
	GcDbEntity* oPoly;
	GcGePoint3d dULow;
	GcGePoint3d dUMax;
	GcGePoint3d vULow;
	GcGePoint3d vUMax;
	GcDbPolyline *polEnt;
	GcGePoint3d vTmpSTA;
	double dText; // ����/��ȹ�� ��
	double dTmpVal;
	CString sKilo;
	double dFValue;
	int i;
	GcGePoint2d pnt2d;

	AddCalsLayer();
	sLock = LockBackUp();

	dXScale = 1000 / GetDlgItemDouble(IDC_TBXSCALE);
	dYScale = 1000 / GetDlgItemDouble(IDC_TBYSCALE);

	// ����ũ��2.5�������� ��������Ƿ�
	// ����ũ��/2.5�� ������ ���̺�Ȯ��
	dTxtScale = GetDlgItemDouble(IDC_TBTEXTH) / DefaultTextH;

	if (optSTA.GetCheck())
		dDiv = 1000.0;
	else
		dDiv = GetDlgItemDouble(IDC_TBSTAINT);

	BeginEditorCommand();

	oPoly = UserSelPLine(_T("���ݼ� ����:"), GcDb::kForRead);
	if (oPoly == NULL)
		goto ErrorHandler;
	if (oPoly->isKindOf(GcDbLine::desc()))
		oPoly = ConvertPoly(oPoly);

	// UCS������
	polEnt = GcDbPolyline::cast(oPoly);
	polEnt->getStartPoint(dULow);
	polEnt->getEndPoint(dUMax);
	gcdbWcs2Ucs(asDblArray(dULow), asDblArray(vULow), ::kTrue);
	gcdbWcs2Ucs(asDblArray(dUMax), asDblArray(vUMax), ::kTrue);

	if (vUMax[X] < vULow[X]) {
		ReverseCoordinates(polEnt);
		SwapVoidData(asDblArray(vULow), asDblArray(vUMax), sizeof(gds_point));
	}

	// ������ ���� X����(���ܱ���)
	dLength = DoubleAbs(vUMax[X] - vULow[X]) * (GetDlgItemDouble(IDC_TBXSCALE) / 1000);

	dSpnt[X] = vULow[X];
	dSpnt[Y] = 0.0;
	dSpnt[Z] = 0.0;

	// ���ڸ� ǥ���� �� ����..Y���� ��������
	if (GetUcsPoint(NULL, _T("������ ǥ���� �� ����:"), asDblArray(vTmpSTA)) != RTNORM)
		goto ErrorHandler;

	// ù���� ���������� ����� �ƴѰ�츦 ���
	dFValue = GetDlgItemDouble(IDC_TBSTAINT) -
			(GetDlgItemInt(IDC_TBSTA) % GetDlgItemInt(IDC_TBSTAINT)) +
			(GetDlgItemInt(IDC_TBSTA) - GetDlgItemInt(IDC_TBSTA));
	iSTA = (int)DoubleRound((dLength - dFValue) / GetDlgItemDouble(IDC_TBSTAINT), 0) + 1;

	for (i = 0; i <= iSTA; i ++) {
		// ������ �ƴϸ�
		if (i < iSTA) {
			if (i == 0) {
				dTmpVal = 0;
				dText = GetDlgItemDouble(IDC_TBSTA);
			}
			else if (i == 1) {
				// ù ������ �������� ����� �ƴѰ�� ���
				dTmpVal = (i * dFValue * dXScale);
				dText = GetDlgItemDouble(IDC_TBSTA) + dFValue;
			}
			else {
				dTmpVal = ((dFValue + (i - 1) * GetDlgItemDouble(IDC_TBSTAINT)) * dXScale);
				dText = GetDlgItemDouble(IDC_TBSTA) + dFValue + (i - 1) * GetDlgItemDouble(IDC_TBSTAINT);
			}
		}
		// �����̸�
		else {
			dTmpVal = (dLength * dXScale);
			dText = GetDlgItemDouble(IDC_TBSTA) + dLength;
		}

		dDrawPnt.removeAll();
		pnt2d.set(dSpnt[X] + dTmpVal, vTmpSTA[Y] - (0.5 * dTxtScale));
		dDrawPnt.append(pnt2d);
		pnt2d.set(dSpnt[X] + dTmpVal, vTmpSTA[Y] + (0.5 * dTxtScale));
		dDrawPnt.append(pnt2d);

		DrawPolyLine(dDrawPnt, ����������, 1, TRUE);

		sKilo.Format(_T("%d+"), (int) (dText / dDiv));
		// 1000�� �Ѿ�� 1000���� �и�
		if (dText >= dDiv)
			dText = fmod(dText, dDiv);

		dTextPnt[X] = dSpnt[X] + dTmpVal;
		dTextPnt[Y] = vTmpSTA[Y];
		dTextPnt[Z] = 0.0;

		sText.Format(_T("%.2f"), dText);
		oText = new GcDbText(dTextPnt, sText);
		oText->setHeight(GetDlgItemDouble(IDC_TBTEXTH));
		AddCurrSpace(oText);
		TableTextSetting(oText, dTextPnt);
		oText->close();

		if (i == 0) {
			dTextPnt[X] = dSpnt[X] - (4 * dTxtScale);
			dTextPnt[Y] = vTmpSTA[Y] - (14.5 * dTxtScale);
			dTextPnt[Z] = 0.0;
			
			oText = new GcDbText(dTextPnt, sKilo);
			oText->setHeight(GetDlgItemDouble(IDC_TBTEXTH));
			AddCurrSpace(oText);
			TableTextSetting(oText, dTextPnt, GcDb::kTextLeft, GcDb::kTextVertMid);
			oText->close();
		}
		else {
			if (fmod(dText, dDiv) == 0) {
				dTextPnt[X] = dSpnt[X] + dTmpVal - (4 * dTxtScale);
				dTextPnt[Y] = vTmpSTA[Y] - (14.5 * dTxtScale);
				dTextPnt[Z] = 0.0;
				
				oText = new GcDbText(dTextPnt, sKilo);
				oText->setHeight(GetDlgItemDouble(IDC_TBTEXTH));
				AddCurrSpace(oText);
				TableTextSetting(oText, dTextPnt, GcDb::kTextLeft, GcDb::kTextVertMid);
				oText->close();
			}
		}
	}

ErrorHandler:
	if (oPoly)
		oPoly->close();

	LockRestore(sLock);

	CompleteEditorCommand ();
	gcedCommandS(RTSTR, _T("_REDRAW"), 0);
}


// ���ݰ�/��ȹ�� ����
void CDlgDLS::OnBnClickedCbGHFH()
{
	CString sLock;
	CString sTblDec;
	GcDbEntity* oPoly;
	GcGePoint3d dULow;
	GcGePoint3d dUMax;
	GcGePoint3d vULow;
	GcGePoint3d vUMax;
	GcDbPolyline *polEnt;
	CString sKey;
	CString sPrompt;
	CString cstr;
	TCHAR sTable[256];
	TCHAR sVLine[256];
	GcGePoint3d vPntGL; // ���ݰ� x�� ����
	double dEL;
	GcGePoint3d vTextTmp;
	GcDbPolyline* oTmp;
	GcGePoint3d vCrossPnt;
	double dText; // ����/��ȹ�� ��
	double dTmpVal;
	double dFValue;
	GcDbObjectId entID;
	GcDbEntity *entPtr;
	GcGePoint3dArray pntArr;
	GcGePoint2dArray dPolePnt;
	GcGePoint2d pnt2d;
	GcGePoint3d dSoPnt1;
	GcGePoint3d dSoPnt2;
	GcGePoint3d dSoPnt3;
	GcGePoint3d dSoPnt4;
	GcDbSolid* oSolid;
	double dTmpPoleH;
	int iPoleH;
	int iTmpInt;
	int iPoleValue;
	int i;
	int k;

	AddCalsLayer();
	sLock = LockBackUp();

	sTblDec = GetFormat(GetDlgItemInt(IDC_TBTBLNUM));

	dXScale = 1000 / GetDlgItemDouble(IDC_TBXSCALE);
	dYScale = 1000 / GetDlgItemDouble(IDC_TBYSCALE);

	// ����ũ��2.5�������� ��������Ƿ�
	// ����ũ��/2.5�� ������ ���̺�Ȯ��
	dTxtScale = GetDlgItemDouble(IDC_TBTEXTH) / 2.5;

	BeginEditorCommand();

	oPoly = UserSelPLine(_T("\n���ݼ� �Ǵ� ��ȹ�� ����:"), GcDb::kForWrite);
	if (oPoly == NULL)
		goto ErrorHandler;
	if (oPoly->isKindOf(GcDbLine::desc()))
		oPoly = ConvertPoly(oPoly);

	// UCS������

	polEnt = GcDbPolyline::cast(oPoly);
	polEnt->getStartPoint(dULow);
	polEnt->getEndPoint(dUMax);
	gcdbWcs2Ucs(asDblArray(dULow), asDblArray(vULow), ::kTrue);
	gcdbWcs2Ucs(asDblArray(dUMax), asDblArray(vUMax), ::kTrue);

	if (vUMax[X] < vULow[X]) {
		ReverseCoordinates(polEnt);
		SwapVoidData(asDblArray(vULow), asDblArray(vUMax), sizeof(gds_point));
	}

	// ������ ���� X���� ���(���ܱ���)
	dLength = DoubleAbs(vUMax[X] - vULow[X]) * (GetDlgItemDouble(IDC_TBXSCALE) / 1000);

	// ���̺� �� ���μ� �׸��� ���� �Ǵ�

	sKey = _T("Y N");
	sPrompt = _T("\n���� ���̺��� �׸��ڽ��ϱ�? [Y/N]<N>: ");

	gcedInitGet(0, sKey); // 1�� �ϸ� Null ������
	gcedGetKword(sPrompt, sTable);

	sPrompt = _T("\n���� ���μ��� �׸��ڽ��ϱ�? [Y/N]<N>: ");

	gcedInitGet(0, sKey);
	gcedGetKword(sPrompt, sVLine);

	if (!GetEL(&dEL))
		goto ErrorHandler;
	gcedInitGet(RSG_OTHER, _T(""));
	sPrompt.Format(_T("���� EL %.3fm�� �� ����:"), dEL);
	if (GetUcsPoint(NULL, _T("���� EL "), asDblArray(vPntGL)) != RTNORM)
		goto ErrorHandler;

	// �׸��� ������ �������� ��ġ ���
	// ������ ����/��ȹ���� ������ X���� vPntGL�� Y���� �����´�.
	// ������ ����/��ȹ���� X�� ���� �� ���� �����̹Ƿ� �������� �����ͼ� X�� ����

	if (vUMax[X] > vULow[X])
		dSpnt[X] = vULow[X];
	else
		dSpnt[X] = vUMax[X];
	dSpnt[Y] = vPntGL[Y];
	dSpnt[Z] = 0.0;

	// �׸���
	//Dim dPolePnt(9) As Double

	// ���̺�
	if (_tcsicmp(sTable, _T("Y")) == 0) {
		// 6�� ��
		for (k = 0; k < 6; k ++) {
			dDrawPnt.removeAll();
			pnt2d.set(dSpnt[X] - (65 * dTxtScale),
					dSpnt[Y] - ((10 * dTxtScale) + ((15 * dTxtScale) * k)));
			dDrawPnt.append(pnt2d);
			pnt2d.set(dSpnt[X] + (dLength * dXScale) + (10 * dTxtScale),
					dSpnt[Y] - ((10 * dTxtScale) + ((15 * dTxtScale) * k)));
			dDrawPnt.append(pnt2d);
			DrawPolyLine(dDrawPnt, tbl������, 6, FALSE);
		}

		dDrawPnt.removeAll();
		pnt2d.set(dSpnt[X] - (65 * dTxtScale), dSpnt[Y] - (10 * dTxtScale));
		dDrawPnt.append(pnt2d);
		pnt2d.set(dSpnt[X] - (65 * dTxtScale), dSpnt[Y] - (85 * dTxtScale));
		dDrawPnt.append(pnt2d);
		DrawPolyLine(dDrawPnt, tbl������, 6, FALSE);

		dDrawPnt.removeAll();
		pnt2d.set(dSpnt[X] - (15 * dTxtScale), dSpnt[Y] - (10 * dTxtScale));
		dDrawPnt.append(pnt2d);
		pnt2d.set(dSpnt[X] - (15 * dTxtScale), dSpnt[Y] - (85 * dTxtScale));
		dDrawPnt.append(pnt2d);
		DrawPolyLine(dDrawPnt, tbl������, 6, FALSE);

		dDrawPnt.removeAll();
		pnt2d.set(dSpnt[X] + (dLength * dXScale) + (10 * dTxtScale), dSpnt[Y] - (10 * dTxtScale));
		dDrawPnt.append(pnt2d);
		pnt2d.set(dSpnt[X] + (dLength * dXScale) + (10 * dTxtScale), dSpnt[Y] - (85 * dTxtScale));
		dDrawPnt.append(pnt2d);
		DrawPolyLine(dDrawPnt, tbl������, 6, FALSE);

		// ���̺� ����
		// 5�� ����
		for (k = 0; k < 5; k ++) {
			switch(k) {
			case 0:
				sText = _T("���ܼ���");
				break;
			case 1:
				sText = _T("�� �� ��");
				break;
			case 2:
				sText = _T("�� ȹ ��");
				break;
			case 3:
				sText = _T("�� �� ��");
				break;
			case 4:
				sText = _T("��    ��");
				break;
			}

			dTextPnt[X] = dSpnt[X] - (40 * dTxtScale);
			dTextPnt[Y] = dSpnt[Y] - ((17.5 * dTxtScale) + ((15 * dTxtScale) * k));
			dTextPnt[Z] = 0.0;

			oText = new GcDbText(dTextPnt, sText, NULL, (8 * dTxtScale), 0.0);
			AddCurrSpace(oText);
			oText->setAlignmentPoint(dTextPnt);
			oText->setVerticalMode(GcDb::kTextVertMid);
			oText->setHorizontalMode(GcDb::kTextCenter);
			oText->setLayer(tbl������);
			oText->setTextStyle(GetTextStyle(_T("����ü")));
			oText->setWidthFactor(0.9);
			TransUCSobj(oText);
			oText->close();
		}

		// ����

		if (vUMax[X] > vULow[X])
			dTmpPoleH = vULow[Y];
		else
			dTmpPoleH = vUMax[Y];

		if (dSpnt[Y] > 0)
			iPoleH = (int)((dTmpPoleH - dSpnt[Y]) / dYScale + (15 * dTxtScale));
		else
			iPoleH = (int)((dTmpPoleH + DoubleAbs(dSpnt[Y])) / dYScale + (15 * dTxtScale));
		iPoleH = (int)((double) iPoleH / 10.0 + 0.9) * 10;

		iTmpInt = (iPoleH - (int)dEL);

		for (i = 0; i <= iTmpInt; i ++) {
			iPoleValue = i + (int)dEL;
			if (i < iTmpInt) {
				dPolePnt.removeAll();
				pnt2d.set(dSpnt[X] - (5 * dTxtScale), dSpnt[Y] + (i * dYScale));
				dPolePnt.append(pnt2d);
				pnt2d.set(dSpnt[X] - (5 * dTxtScale), dSpnt[Y] + (i * dYScale) + dYScale);
				dPolePnt.append(pnt2d);
				pnt2d.set(dSpnt[X] - (6 * dTxtScale), dSpnt[Y] + (i * dYScale) + dYScale);
				dPolePnt.append(pnt2d);
				pnt2d.set(dSpnt[X] - (6 * dTxtScale), dSpnt[Y] + (i * dYScale));
				dPolePnt.append(pnt2d);
				dPolePnt.append(dPolePnt[0]);
				DrawPolyLine(dPolePnt, ��ô��Ÿ, 1, FALSE);

				// �ָ���
				if ((iPoleValue % 2) == 0) {
					dSoPnt1[X] = dPolePnt[2].x;
					dSoPnt1[Y] = dPolePnt[2].y;
					dSoPnt1[Z] = 0.0;
					dSoPnt2[X] = dPolePnt[1].x;
					dSoPnt2[Y] = dPolePnt[1].y;
					dSoPnt2[Z] = 0.0;
					dSoPnt3[X] = dPolePnt[3].x;
					dSoPnt3[Y] = dPolePnt[3].y;
					dSoPnt3[Z] = 0.0;
					dSoPnt4[X] = dPolePnt[0].x;
					dSoPnt4[Y] = dPolePnt[0].y;
					dSoPnt4[Z] = 0.0;

					oSolid = new GcDbSolid(dSoPnt1, dSoPnt2, dSoPnt3, dSoPnt4);
					AddCurrSpace(oSolid);
					oSolid->setLayer(��ô��Ÿ);
					TransUCSobj(oSolid);
					oSolid->close();
				}
			}

			// ���밡�μ�
			if (i == 0) { // '�� �Ʒ� �� ���
				dDrawPnt.removeAll();
				pnt2d.set(dSpnt[X] - (16 * dTxtScale), dSpnt[Y] + (i * dYScale));
				dDrawPnt.append(pnt2d);
				pnt2d.set(dSpnt[X], dSpnt[Y] + (i * dYScale));
				dDrawPnt.append(pnt2d);
				DrawPolyLine(dDrawPnt, ��ô��Ÿ, 1, FALSE);
			}
			else {
				if ((iPoleValue % 10) == 0) {
					dDrawPnt.removeAll();
					pnt2d.set(dSpnt[X] - (16 * dTxtScale), dSpnt[Y] + (i * dYScale));
					dDrawPnt.append(pnt2d);
					pnt2d.set(dSpnt[X] - (5 * dTxtScale), dSpnt[Y] + (i * dYScale));
					dDrawPnt.append(pnt2d);
					DrawPolyLine(dDrawPnt, ��ô��, 1, FALSE);
				}
			}

			// ���� ���� ����
			if (((iPoleValue % 10) == 0) || (i == 0)) {
				sText.Format(_T("%.2f"), (double)iPoleValue);
				dTextPnt[X] = dSpnt[X] - (7 * dTxtScale);
				dTextPnt[Y] = dSpnt[Y] + (i * dYScale) + (2.75 * dTxtScale);
				dTextPnt[Z] = 0.0;
				oText = new GcDbText(dTextPnt, sText, NULL, GetDlgItemDouble(IDC_TBTEXTH), 0.0);
				AddCurrSpace(oText);
				oText->setAlignmentPoint(dTextPnt);
				oText->setVerticalMode(GcDb::kTextVertMid);
				oText->setHorizontalMode(GcDb::kTextRight);
				oText->setLayer(��ô����);
				oText->setWidthFactor(0.9);
				TransUCSobj(oText);
				oText->close();
			}
		}
	}
	i = 0;

	// ���ڸ� ǥ���� �� ����..Y���� ��������
	if (GetUcsPoint(NULL, _T("���ݰ� �Ǵ� ��ȹ�� ǥ���� �� ����:"), asDblArray(vTextTmp)) != RTNORM)
		goto ErrorHandler;

	// ������ �ϴܼ� �׸���.
	if (_tcsicmp(sVLine, _T("Y")) == 0) {
		dDrawPnt.removeAll();
		pnt2d.set(dSpnt[X], dSpnt[Y]);
		dDrawPnt.append(pnt2d);
		pnt2d.set(dSpnt[X] + (dLength * dXScale), dSpnt[Y]);
		dDrawPnt.append(pnt2d);
		DrawPolyLine(dDrawPnt, �׸���, 1, FALSE);
	}

	// ��ü����/���������� ��ȯ�ϸ鼭 ���ܼ��� �׸���
	// �������� ����� ����/��ȹ���� �˾Ƴ��� ����

	// ù���� ���������� ����� �ƴѰ�츦 ���
	dFValue = GetDlgItemInt(IDC_TBSTAINT) -
			(GetDlgItemInt(IDC_TBSTA) % GetDlgItemInt(IDC_TBSTAINT)) +
			(GetDlgItemInt(IDC_TBSTA) - (GetDlgItemInt(IDC_TBSTA)));

	iSTA = (int)DoubleRound((dLength - dFValue) / GetDlgItemDouble(IDC_TBSTAINT), 0) + 1;
	for (i = 0; i <= iSTA; i ++) {
		if (i < iSTA) {
			if (i == 0)
				dTmpVal = 0;
			else if (i == 1) // ù ������ �������� ����� �ƴѰ�� ���
				dTmpVal = (i * dFValue * dXScale);
			else
				dTmpVal = ((dFValue + (i - 1) * GetDlgItemDouble(IDC_TBSTAINT)) * dXScale);
		}
		else
			// �����̸�
			dTmpVal = (dLength * dXScale);

		// ���� ������ �׸��� ����/��ȹ���� �������� ���Ѵ�
		dDrawPnt.removeAll();
		pnt2d.set(dSpnt[X] + dTmpVal, vTextTmp[Y] - (0.5 * dTxtScale));
		dDrawPnt.append(pnt2d);
		pnt2d.set(dSpnt[X] + dTmpVal, vTextTmp[Y] + (0.5 * dTxtScale));
		dDrawPnt.append(pnt2d);
		DrawPolyLine(dDrawPnt, ����������, 1, TRUE);

		GetVariable(_T("USERS4"), cstr);
		entID = GetObjectByHandle(cstr);
		if (gcdbOpenObject(entPtr, entID, GcDb::kForRead) == Gcad::eOk) {
			oTmp = GcDbPolyline::cast(entPtr);
			oTmp->close();
		}
		else
			::MessageBox(NULL, _T("can not get Object by Handle"), _T("Error"), MB_OK);

		// �������� ã�´�
		pntArr.removeAll();
		if (oTmp->intersectWith(oPoly, GcDb::kExtendThis, pntArr) == Gcad::eOk)
			gcdbWcs2Ucs(asDblArray(pntArr[0]), asDblArray(vCrossPnt), ::kTrue);

		// ���� ���μ�
		if (_tcsicmp(sVLine, _T("Y")) == 0) {
			dDrawPnt.removeAll();
			pnt2d.set(dSpnt[X] + dTmpVal, dSpnt[Y]);
			dDrawPnt.append(pnt2d);
			pnt2d.set(vCrossPnt[X], vCrossPnt[Y]);
			dDrawPnt.append(pnt2d);
			DrawPolyLine(dDrawPnt, �׸��弼��, 1, FALSE);
		}

		// ���ݰ�/��ȹ�� ����
		dText = (vCrossPnt[Y] - dSpnt[Y]) / dYScale + dEL;
		dTextPnt[X] = dSpnt[X] + dTmpVal;
		dTextPnt[Y] = vTextTmp[Y];
		dTextPnt[Z] = 0.0;

		sText.Format(sTblDec, dText);
		oText = new GcDbText(dTextPnt, sText);
		oText->setHeight(GetDlgItemDouble(IDC_TBTEXTH));
		AddCurrSpace(oText);
		TableTextSetting(oText, dTextPnt);
		oText->close();
	}

ErrorHandler:
	if (oPoly)
		oPoly->close();

	LockRestore(sLock);

	CompleteEditorCommand ();
	gcedCommandS(RTSTR, _T("_REDRAW"), 0);
}


void CDlgDLS::OnBnClickedCbGap()
{
	CString sLock;
	GcDbEntity* oFH = NULL;
	GcDbEntity* oGR = NULL;
	CString sTblDec;
	GcDbPolyline* pFH;
	GcGePoint3d dULow, dUMax;
	GcGePoint3d vULow, vUMax;
	GcGePoint3d vTextTmp;
	GcDbPolyline* oTmp;
	GcGePoint3d vIntPntFL;
	GcGePoint3d vIntPntGR;
	double dText; // ������ ��
	double dTmpVal;
	double dFValue;
	GcGePoint2d pnt2d;
	GcDbObjectId entID;
	GcDbEntity *entPtr;
	GcGePoint3dArray pntArr;
	CString cstr;
	int i;

	AddCalsLayer();
	sLock = LockBackUp();

	sTblDec = GetFormat(GetDlgItemInt(IDC_TBTBLNUM));

	dXScale = 1000 / GetDlgItemDouble(IDC_TBXSCALE);
	dYScale = 1000 / GetDlgItemDouble(IDC_TBYSCALE);

	// ����ũ��2.5�������� ��������Ƿ�
	// ����ũ��/2.5�� ������ ���̺�Ȯ��
	dTxtScale = GetDlgItemDouble(IDC_TBTEXTH) / DefaultTextH;

	BeginEditorCommand();

	oGR = UserSelPLine(_T("���ݼ� ����:"), GcDb::kForRead);
	if (oGR == NULL)
		goto ErrorHandler;
	oGR->highlight();
	oFH = UserSelPLine(_T("��ȹ�� ����:"), GcDb::kForRead);
	if (oFH == NULL) {
		oGR->unhighlight();
		goto ErrorHandler;
	}
	oGR->unhighlight();
	oFH->highlight();

	if (oFH->isKindOf(GcDbLine::desc()))
		oFH = ConvertPoly(oFH);
	pFH = GcDbPolyline::cast(oFH);

	// UCS������
	pFH->getStartPoint(dULow);
	pFH->getEndPoint(dUMax);
	gcdbWcs2Ucs(asDblArray(dULow), asDblArray(vULow), ::kTrue);
	gcdbWcs2Ucs(asDblArray(dUMax), asDblArray(vUMax), ::kTrue);

	if (vUMax[X] < vULow[X]) {
		ReverseCoordinates(pFH);
		SwapVoidData(asDblArray(vULow), asDblArray(vUMax), sizeof(gds_point));
	}

	// ������ ���� X����(���ܱ���)
	dLength = DoubleAbs(vUMax[X] - vULow[X]) * (GetDlgItemDouble(IDC_TBXSCALE) / 1000);

	// �׸���
	// ���ڸ� ǥ���� �� ����..Y���� ��������
	if (GetUcsPoint(NULL, _T("������ ǥ���� �� ����:"), asDblArray(vTextTmp)) != RTNORM)
		goto ErrorHandler;
	oFH->unhighlight();

	// ��ü����/���������� ��ȯ�ϸ鼭 ����� ����

	// ù���� ���������� ����� �ƴѰ�츦 ���
	dFValue = GetDlgItemInt(IDC_TBSTAINT) -
			(GetDlgItemInt(IDC_TBSTA) % GetDlgItemInt(IDC_TBSTAINT)) +
			(GetDlgItemInt(IDC_TBSTA) - (GetDlgItemInt(IDC_TBSTA)));

	iSTA = (int)DoubleRound((dLength - dFValue) / GetDlgItemDouble(IDC_TBSTAINT), 0) + 1;
	for (i = 0; i <= iSTA; i ++) {
		// ������ �ƴϸ�
		if (i < iSTA) {
			if (i == 0)
				dTmpVal = 0;
			else if (i == 1) // ù ������ �������� ����� �ƴѰ�� ���
				dTmpVal = (i * dFValue * dXScale);
			else
				dTmpVal = ((dFValue + (i - 1) * GetDlgItemDouble(IDC_TBSTAINT)) * dXScale);
		}
		// �����̸�
		else
			dTmpVal = (dLength * dXScale);

		// ���� ������ �׸��� ����/��ȹ���� �������� ���Ѵ�
		dDrawPnt.removeAll();
		pnt2d.set(vULow[X] + dTmpVal, vTextTmp[Y] - (0.5 * dTxtScale));
		dDrawPnt.append(pnt2d);
		pnt2d.set(vULow[X] + dTmpVal, vTextTmp[Y] + (0.5 * dTxtScale));
		dDrawPnt.append(pnt2d);
		DrawPolyLine(dDrawPnt, ����������, 1, TRUE);

		GetVariable(_T("USERS4"), cstr);
		entID = GetObjectByHandle(cstr);
		if (gcdbOpenObject(entPtr, entID, GcDb::kForRead) == Gcad::eOk) {
			oTmp = GcDbPolyline::cast(entPtr);
			oTmp->close();
		}
		else
			::MessageBox(NULL, _T("can not get Object by Handle"), _T("Error"), MB_OK);

		// ���ݼ� �������� ã�´�
		pntArr.removeAll();
		if (oTmp->intersectWith(oGR, GcDb::kExtendThis, pntArr) == Gcad::eOk)
			gcdbWcs2Ucs(asDblArray(pntArr[0]), asDblArray(vIntPntGR), ::kTrue);

		// ��ȹ�� �������� ã�´�
		pntArr.removeAll();
		if (oTmp->intersectWith(oFH, GcDb::kExtendThis, pntArr) == Gcad::eOk)
			gcdbWcs2Ucs(asDblArray(pntArr[0]), asDblArray(vIntPntFL), ::kTrue);

		// ������ ����
		if (DoubleRound(vIntPntFL[Y] - vIntPntGR[Y], 2) >= 0) {
			dText = vIntPntFL[Y] / dYScale - vIntPntGR[Y] / dYScale;
			sText.Format(_T("+") + sTblDec, DoubleAbs(dText));
		}
		else {
			dText = vIntPntFL[Y] / dYScale - vIntPntGR[Y] / dYScale;
			sText.Format(_T("-") + sTblDec, DoubleAbs(dText));
		}

		dTextPnt[X] = vULow[X] + dTmpVal;
		dTextPnt[Y] = vTextTmp[Y];
		dTextPnt[Z] = 0.0;

		oText = new GcDbText(dTextPnt, sText, NULL, GetDlgItemDouble(IDC_TBTEXTH), PI2);
		AddCurrSpace(oText);
		oText->setAlignmentPoint(dTextPnt);
		oText->setVerticalMode(GcDb::kTextVertMid);
		oText->setHorizontalMode(GcDb::kTextRight);
		oText->setLayer(tbl���빮��);
		oText->setWidthFactor(1.0);
		TransUCSobj(oText);
		oText->close();
	}

ErrorHandler:
	LockRestore(sLock);
	if (oGR) {
		oGR->unhighlight();
		oGR->close();
	}
	if (oFH) {
		oFH->unhighlight();
		oFH->close();
	}

	CompleteEditorCommand ();
	gcedCommandS(RTSTR, _T("_REDRAW"), 0);
}


void CDlgDLS::OnBnClickedCbDel()
{
	int i;
	GcDbObjectId entID;
	GcDbEntity* entPtr;

	for (i = 0; i < sHandle.GetSize(); i ++) {
		entID = GetObjectByHandle(sHandle[i]);
		if (gcdbOpenObject(entPtr, entID, GcDb::kForWrite) == Gcad::eOk) {
			entPtr->erase();
			entPtr->close();
		}
	}

	DrawCurve(vDelS, vDelI, vDelE, GetDlgItemDouble(IDC_TBLENGTH));

	gcedCommandS(RTSTR, _T("_REDRAW"), 0);
}


void CDlgDLS::OnBnClickedOk()
{
	SaveSetting();
	CGcUiDialog::OnOK();
}


void CDlgDLS::OnBnClickedHelp()
{
	CString dllDir;
	::GetModuleFileName((HINSTANCE)&__ImageBase, dllDir.GetBuffer(_MAX_PATH), _MAX_PATH);
	dllDir.ReleaseBuffer();
	int loc = dllDir.ReverseFind('\\');
	if (loc >= 0)
		dllDir = dllDir.Left(loc);
	::ShellExecuteW(::GetDesktopWindow(), _T("open"), _T("Magic.chm"), 0, dllDir, SW_SHOWDEFAULT);
}

