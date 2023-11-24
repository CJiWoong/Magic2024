// DlgMPLForm.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MagicUtil.h"
#include "DlgMPLForm.h"
#include "DlgMPLFName.h"
#include "afxdialogex.h"

const TCHAR* CDlgMPLForm::PROGY_NAME = _T("Form 등록/변경");

// CDlgMPLForm 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgMPLForm, CGcUiDialog)

CDlgMPLForm::CDlgMPLForm(CWnd* pParent /*=NULL*/)
	: CGcUiDialog(CDlgMPLForm::IDD, pParent)
{

}

CDlgMPLForm::~CDlgMPLForm()
{
}

void CDlgMPLForm::DoDataExchange(CDataExchange* pDX)
{
	CGcUiDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TBFORM1, tbForm1);
	DDX_Control(pDX, IDC_TBFORM2, tbForm2);
	DDX_Control(pDX, IDC_TBFORM3, tbForm3);
	DDX_Control(pDX, IDC_TBFORM4, tbForm4);
	DDX_Control(pDX, IDC_TBFORM5, tbForm5);
	DDX_Control(pDX, IDC_TBFORM6, tbForm6);
	DDX_Control(pDX, IDC_CBFORM1, cbForm1);
	DDX_Control(pDX, IDC_CBFORM2, cbForm2);
	DDX_Control(pDX, IDC_CBFORM3, cbForm3);
	DDX_Control(pDX, IDC_CBFORM4, cbForm4);
	DDX_Control(pDX, IDC_CBFORM5, cbForm5);
	DDX_Control(pDX, IDC_CBFORM6, cbForm6);
	DDX_Control(pDX, IDC_CBEDT1, cbEdt1);
	DDX_Control(pDX, IDC_CBEDT2, cbEdt2);
	DDX_Control(pDX, IDC_CBEDT3, cbEdt3);
	DDX_Control(pDX, IDC_CBEDT4, cbEdt4);
	DDX_Control(pDX, IDC_CBEDT5, cbEdt5);
	DDX_Control(pDX, IDC_CBEDT6, cbEdt6);
	DDX_Control(pDX, IDC_CBDEL1, cbDel1);
	DDX_Control(pDX, IDC_CBDEL2, cbDel2);
	DDX_Control(pDX, IDC_CBDEL3, cbDel3);
	DDX_Control(pDX, IDC_CBDEL4, cbDel4);
	DDX_Control(pDX, IDC_CBDEL5, cbDel5);
	DDX_Control(pDX, IDC_CBDEL6, cbDel6);
}


BEGIN_MESSAGE_MAP(CDlgMPLForm, CGcUiDialog)
	ON_BN_CLICKED(IDC_CBFORM1, &CDlgMPLForm::OnBnClickedCbform1)
	ON_BN_CLICKED(IDC_CBFORM2, &CDlgMPLForm::OnBnClickedCbform2)
	ON_BN_CLICKED(IDC_CBFORM3, &CDlgMPLForm::OnBnClickedCbform3)
	ON_BN_CLICKED(IDC_CBFORM4, &CDlgMPLForm::OnBnClickedCbform4)
	ON_BN_CLICKED(IDC_CBFORM5, &CDlgMPLForm::OnBnClickedCbform5)
	ON_BN_CLICKED(IDC_CBFORM6, &CDlgMPLForm::OnBnClickedCbform6)
	ON_BN_CLICKED(IDC_CBEDT1, &CDlgMPLForm::OnBnClickedCbedt1)
	ON_BN_CLICKED(IDC_CBEDT2, &CDlgMPLForm::OnBnClickedCbedt2)
	ON_BN_CLICKED(IDC_CBEDT3, &CDlgMPLForm::OnBnClickedCbedt3)
	ON_BN_CLICKED(IDC_CBEDT4, &CDlgMPLForm::OnBnClickedCbedt4)
	ON_BN_CLICKED(IDC_CBEDT5, &CDlgMPLForm::OnBnClickedCbedt5)
	ON_BN_CLICKED(IDC_CBEDT6, &CDlgMPLForm::OnBnClickedCbedt6)
	ON_BN_CLICKED(IDC_CBDEL1, &CDlgMPLForm::OnBnClickedCbdel1)
	ON_BN_CLICKED(IDC_CBDEL2, &CDlgMPLForm::OnBnClickedCbdel2)
	ON_BN_CLICKED(IDC_CBDEL3, &CDlgMPLForm::OnBnClickedCbdel3)
	ON_BN_CLICKED(IDC_CBDEL4, &CDlgMPLForm::OnBnClickedCbdel4)
	ON_BN_CLICKED(IDC_CBDEL5, &CDlgMPLForm::OnBnClickedCbdel5)
	ON_BN_CLICKED(IDC_CBDEL6, &CDlgMPLForm::OnBnClickedCbdel6)
	ON_BN_CLICKED(IDC_CBEXIT, &CDlgMPLForm::OnBnClickedCbexit)
END_MESSAGE_MAP()


// CDlgMPLForm 메시지 처리기입니다.


void CDlgMPLForm::OnBnClickedCbform1()
{
	GetForm(1);
}


void CDlgMPLForm::OnBnClickedCbform2()
{
	GetForm(2);
}


void CDlgMPLForm::OnBnClickedCbform3()
{
	GetForm(3);
}


void CDlgMPLForm::OnBnClickedCbform4()
{
	GetForm(4);
}


void CDlgMPLForm::OnBnClickedCbform5()
{
	GetForm(5);
}


void CDlgMPLForm::OnBnClickedCbform6()
{
	GetForm(6);
}


void CDlgMPLForm::OnBnClickedCbedt1()
{
	EdtForm(1);
}


void CDlgMPLForm::OnBnClickedCbedt2()
{
	EdtForm(2);
}


void CDlgMPLForm::OnBnClickedCbedt3()
{
	EdtForm(3);
}


void CDlgMPLForm::OnBnClickedCbedt4()
{
	EdtForm(4);
}


void CDlgMPLForm::OnBnClickedCbedt5()
{
	EdtForm(5);
}


void CDlgMPLForm::OnBnClickedCbedt6()
{
	EdtForm(6);
}


void CDlgMPLForm::OnBnClickedCbdel1()
{
	DelForm(1);
}


void CDlgMPLForm::OnBnClickedCbdel2()
{
	DelForm(2);
}


void CDlgMPLForm::OnBnClickedCbdel3()
{
	DelForm(3);
}


void CDlgMPLForm::OnBnClickedCbdel4()
{
	DelForm(4);
}


void CDlgMPLForm::OnBnClickedCbdel5()
{
	DelForm(5);
}


void CDlgMPLForm::OnBnClickedCbdel6()
{
	DelForm(6);
}


void CDlgMPLForm::GetForm(int iSel)
{
	gds_name ename;
	gds_point pt;
	GcDbObjectId objId;
	GcDbEntity *pEnt;
	GcDbBlockReference *pInsert;
	Gcad::ErrorStatus es;
	GcDbExtents extents;
	GcGePoint3d vMin;
	GcGePoint3d vMax;
	BOOL bLock;
	CString sLayer;
	GcGePoint3d dZero;
	//double dTwAng;
	//BOOL bRotate;
	GcDbObjectId blockDefId;
	GcDbLayerTableRecord* layPtr;
	//BOOL bVert;
	//BOOL bRealVert;
	//double dWidth;
	//double dHeight;
	GcGePoint3d vTmpPnt1;
	GcGePoint3d vTmpPnt2;
	GcGePoint3d vTmpPnt3;
	double ang;
	OdGePoint3d org;
	OdGeScale3d scl;
	CString nstr;
	CString cstr;
	//int rt;
	CEdit* edtLst[] = {&tbForm1, &tbForm2, &tbForm3, &tbForm4, &tbForm5, &tbForm6};

	layPtr = NULL;
	bLock = FALSE;

	nstr.Format(_T("%d"), iSel);

	BeginEditorCommand();
	//GetParent()->ShowWindow(SW_HIDE);

	// Let the user select an INSERT (Block reference).
	if (gcedEntSel(L"\nForm에 해당되는 객체를 선택 : ", ename, pt) != RTNORM)
		goto ErrorHandler;

	// Test the entity type.
	gcdbGetObjectId(objId, ename);
	if ((es = gcdbOpenGcDbEntity(pEnt, objId, GcDb::kForRead)) != Gcad::eOk) {
		AfxMessageBox (_T("선택한 객체를 열 수 없습니다."), MB_OK | MB_ICONINFORMATION);
		goto ErrorHandler;
	}

	pInsert = GcDbBlockReference::cast(pEnt);
	if (!pInsert) {
		AfxMessageBox (_T("선택한 객체는 INSERT가 아닙니다."), MB_OK | MB_ICONINFORMATION);
		pEnt->close();
		goto ErrorHandler;
	}

	org = pInsert->position();
	scl = pInsert->scaleFactors();
	ang = pInsert->rotation();

	// Get the objectID of the block definition.
	blockDefId = pInsert->blockTableRecord();

	// Close the selected INSERT.
	pInsert->close();

	// Open the block definition.
	GcDbBlockTableRecord *pBlkRecord;
	if ((es = gcdbOpenObject(pBlkRecord, blockDefId, GcDb::kForRead)) != Gcad::eOk) {
		AfxMessageBox (_T("BLOCK 정의를 열 수 없습니다."), MB_OK | MB_ICONINFORMATION);
		goto ErrorHandler;
	}

	// Get the name of the block definition.
	const TCHAR* sFormName;
	es = pBlkRecord->getName(sFormName);
	pBlkRecord->close();
	if ((Gcad::eOk != es) || !sFormName) {
		AfxMessageBox (_T("BLOCK 정의 이름을 구할 수 없습니다."), MB_OK | MB_ICONINFORMATION);
		goto ErrorHandler;
	}

	if (Dup_Check(sFormName, iSel))
		goto ErrorHandler;

	edtLst[iSel - 1]->SetWindowTextW(sFormName);

	m_regEdit.SetString(_T("FormName") + nstr, sFormName);

	cstr.Format(_T("%f"), org.x);
	m_regEdit.SetString(_T("FormOrgX") + nstr, cstr);
	cstr.Format(_T("%f"), org.y);
	m_regEdit.SetString(_T("FormOrgY") + nstr, cstr);
	cstr.Format(_T("%f"), scl.sx);
	m_regEdit.SetString(_T("FormSclX") + nstr, cstr);
	cstr.Format(_T("%f"), scl.sy);
	m_regEdit.SetString(_T("FormSclY") + nstr, cstr);
	cstr.Format(_T("%f"), ang);
	m_regEdit.SetString(_T("FormAng") + nstr, cstr);

	/* 2018.06.29 Do not use Form Area */
/*
	dZero.set(0, 0, 0);

	dTwAng = GetTWAng();
	if (dTwAng != 0)
		dTwAng = - dTwAng;
	bLock = FALSE;

	sLayer = pEnt->layer();
	layPtr = GetLayerObj(sLayer, GcDb::kForWrite);
	if (layPtr->isLocked()) {
		layPtr->setIsLocked(FALSE);
		bLock = TRUE;
	}

	if (dTwAng != 0)
		pInsert->setRotation(dTwAng);
	pInsert->geomExtentsBestFit(extents);
	bRotate = IsVerDwg(pInsert->rotation());
	if (dTwAng != 0)
		pInsert->setRotation(-dTwAng);

	vMin = extents.minPoint();
	vMax = extents.maxPoint();

	dWidth = vMax.x - vMin.x;
	dHeight = vMax.y - vMin.y;

	cstr.Format(_T("%f"), DoubleAbs(dWidth)); m_regEdit.SetString(_T("Width") + nstr, cstr);
	cstr.Format(_T("%f"), DoubleAbs(dHeight)); m_regEdit.SetString(_T("Height") + nstr, cstr);

	rt = gcedGetPoint(NULL, _T("인쇄할 영역의 첫번째 모서리 점 지정:"), asDblArray(vTmpPnt1));
	if (rt != RTNORM)
		goto ErrorHandler;

	rt = gcedGetCorner(asDblArray(vTmpPnt1), _T("인쇄할 영역의 두번째 모서리 점 지정:"), asDblArray(vTmpPnt2));
	if (rt != RTNORM)
		goto ErrorHandler;

	if (dTwAng != 0) {
		vTmpPnt1 = GetRotPnt(dZero, vTmpPnt1, dTwAng);
		vTmpPnt2 = GetRotPnt(dZero, vTmpPnt2, dTwAng);
	}

	// func.RegionRULD vTmpPnt1, vTmpPnt2

	if (vTmpPnt2[Y] < vTmpPnt1[Y])
		SwapVoidData(&vTmpPnt1, &vTmpPnt2, sizeof(GcGePoint3d));

	dHeight = DoubleAbs(vTmpPnt2[Y] - vTmpPnt1[Y]);
	dWidth = DoubleAbs(vTmpPnt2[X] - vTmpPnt1[X]);
	if (dHeight > dWidth)
		bVert = TRUE;
	else
		bVert = FALSE;

	if (!bRotate && bVert)
		bRealVert = TRUE;
	else {
		if (bRotate && !bVert)
			bRealVert = TRUE;
		else
			bRealVert = FALSE;
	}

	m_regEdit.SetBoolean(_T("RealVertical") + nstr, bRealVert);
	m_regEdit.SetBoolean(_T("IsVertical") + nstr, bVert);
	cstr.Format(_T("%f"), dHeight); m_regEdit.SetString(_T("PaperHeight") + nstr, cstr);
	cstr.Format(_T("%f"), dWidth); m_regEdit.SetString(_T("PaperWidth") + nstr, cstr);
*/

ErrorHandler:
	if (bLock)
		layPtr->setIsLocked(TRUE);
	if (layPtr)
		layPtr->close();

	//GetParent()->ShowWindow(SW_SHOWNORMAL);
	CompleteEditorCommand();

	gcedGetGcadTextCmdLine()->PostMessage(WM_CHAR, VK_ESCAPE, 0);
}

void CDlgMPLForm::EdtForm(int iSel)
{
	CString nstr;
	CString cstr;
	BOOL fnamSet = FALSE;
	double formOrgX, formOrgY, formSclX, formSclY, formAng;
	double fnumSX, fnumSY, fnumEX, fnumEY;
	double fnamSX, fnamSY, fnamEX, fnamEY;
	CString fnumPre, fnumPos;
	CString fnamPre, fnamPos;

	CEdit* edtLst[] = { &tbForm1, &tbForm2, &tbForm3, &tbForm4, &tbForm5, &tbForm6 };

	nstr.Format(_T("%d"), iSel);

	formOrgX = _wtof(m_regEdit.GetString(_T("FormOrgX") + nstr, _T("0")));
	formOrgY = _wtof(m_regEdit.GetString(_T("FormOrgY") + nstr, _T("0")));
	formSclX = _wtof(m_regEdit.GetString(_T("FormSclX") + nstr, _T("1")));
	formSclY = _wtof(m_regEdit.GetString(_T("FormSclY") + nstr, _T("1")));
	formAng = _wtof(m_regEdit.GetString(_T("FormAng") + nstr, _T("0")));

	cstr = m_regEdit.GetString(_T("FNamSet") + nstr, _T("0"));
	fnamSet = (cstr == "0") ? FALSE: TRUE;
	if (fnamSet) {
		fnumSX = _wtof(m_regEdit.GetString(_T("FnumSX") + nstr, _T("0")));
		fnumSY = _wtof(m_regEdit.GetString(_T("FnumSY") + nstr, _T("0")));
		fnumEX = _wtof(m_regEdit.GetString(_T("FnumEX") + nstr, _T("0")));
		fnumEY = _wtof(m_regEdit.GetString(_T("FnumEY") + nstr, _T("0")));
		fnumPre = m_regEdit.GetString(_T("FnumPre") + nstr, _T(""));
		fnumPos = m_regEdit.GetString(_T("FnumPos") + nstr, _T(""));
		fnamSX = _wtof(m_regEdit.GetString(_T("FnamSX") + nstr, _T("0")));
		fnamSY = _wtof(m_regEdit.GetString(_T("FnamSY") + nstr, _T("0")));
		fnamEX = _wtof(m_regEdit.GetString(_T("FnamEX") + nstr, _T("0")));
		fnamEY = _wtof(m_regEdit.GetString(_T("FnamEY") + nstr, _T("0")));
		fnamPre = m_regEdit.GetString(_T("FnamPre") + nstr, _T(""));
		fnamPos = m_regEdit.GetString(_T("FnamPos") + nstr, _T(""));
	}
	else {
		fnumSX = 0.0;
		fnumSY = 0.0;
		fnumEX = 0.0;
		fnumEY = 0.0;
		fnamSX = 0.0;
		fnamSY = 0.0;
		fnamEX = 0.0;
		fnamEY = 0.0;
	}

	CDlgMPLFName dlgFName(this);
	dlgFName.formOrgX = formOrgX;
	dlgFName.formOrgY = formOrgY;
	dlgFName.formSclX = formSclX;
	dlgFName.formSclY = formSclY;
	dlgFName.formAng = formAng;
	dlgFName.fNamSet = fnamSet;
	dlgFName.fNumSX = fnumSX;
	dlgFName.fNumSY = fnumSY;
	dlgFName.fNumPre = fnumPre;
	dlgFName.fNumPos = fnumPos;
	dlgFName.fNamSX = fnamSX;
	dlgFName.fNamSY = fnamSY;
	dlgFName.fNamPre = fnamPre;
	dlgFName.fNamPos = fnamPos;

	if (dlgFName.DoModal() == IDOK) {
		m_regEdit.SetString(_T("FNamSet") + nstr, dlgFName.fNamSet ? _T("1"): _T("0"));
		
		cstr.Format(_T("%f"), dlgFName.fNumSX);
		m_regEdit.SetString(_T("FNumSX") + nstr, cstr);
		cstr.Format(_T("%f"), dlgFName.fNumSY);
		m_regEdit.SetString(_T("FNumSY") + nstr, cstr);
		cstr.Format(_T("%f"), dlgFName.fNumEX);
		m_regEdit.SetString(_T("FNumEX") + nstr, cstr);
		cstr.Format(_T("%f"), dlgFName.fNumEY);
		m_regEdit.SetString(_T("FNumEY") + nstr, cstr);
		m_regEdit.SetString(_T("FNumPre") + nstr, dlgFName.fNumPre);
		m_regEdit.SetString(_T("FNumPos") + nstr, dlgFName.fNumPos);

		cstr.Format(_T("%f"), dlgFName.fNamSX);
		m_regEdit.SetString(_T("FNamSX") + nstr, cstr);
		cstr.Format(_T("%f"), dlgFName.fNamSY);
		m_regEdit.SetString(_T("FNamSY") + nstr, cstr);
		cstr.Format(_T("%f"), dlgFName.fNamEX);
		m_regEdit.SetString(_T("FNamEX") + nstr, cstr);
		cstr.Format(_T("%f"), dlgFName.fNamEY);
		m_regEdit.SetString(_T("FNamEY") + nstr, cstr);
		m_regEdit.SetString(_T("FNamPre") + nstr, dlgFName.fNamPre);
		m_regEdit.SetString(_T("FNamPos") + nstr, dlgFName.fNamPos);
	}
}

void CDlgMPLForm::DelForm(int iSel)
{
	CString nstr;
	CEdit* edtLst[] = {&tbForm1, &tbForm2, &tbForm3, &tbForm4, &tbForm5, &tbForm6};

	nstr.Format(_T("%d"), iSel);

	edtLst[iSel - 1]->SetWindowTextW(_T(""));

	m_regEdit.SetString(_T("FormName") + nstr, _T(""));
	m_regEdit.SetString(_T("Height") + nstr, _T(""));
	m_regEdit.SetString(_T("Width") + nstr, _T(""));
	m_regEdit.SetString(_T("RealVertical") + nstr, _T(""));
	m_regEdit.SetString(_T("IsVertical") + nstr, _T(""));
	m_regEdit.SetString(_T("PaperHeight") + nstr, _T(""));
	m_regEdit.SetString(_T("PaperWidth") + nstr, _T(""));
}

BOOL CDlgMPLForm::IsVerDwg(double dRotation)
{
	if (dRotation < (PI2 / 2))
		return FALSE;

	if (dRotation > (TPI - (PI2 / 2)))
		return FALSE;

	return TRUE;
}

BOOL CDlgMPLForm::Dup_Check(LPCTSTR sName, int iSel)
{
	CString cstr;
	int i;
	CEdit* edtLst[] = {&tbForm1, &tbForm2, &tbForm3, &tbForm4, &tbForm5, &tbForm6};

	for (i = 0; i < 6; i ++) {
		if (iSel == i)
			continue;

		edtLst[i]->GetWindowText(cstr);
		cstr.Trim();
		if (cstr.CompareNoCase(sName) == 0) {
			AfxMessageBox(_T("이미 등록된 이름이 있습니다\n이미 등록된 이름과 추가하려는 이름이 같을 수 없습니다"), MB_OK | MB_ICONINFORMATION);
			return TRUE;
		}
	}

	return FALSE;
}


void CDlgMPLForm::SaveIni()
{
	CString cstr;
	CString fstr;
	int i;
	CEdit* edtLst[] = {&tbForm1, &tbForm2, &tbForm3, &tbForm4, &tbForm5, &tbForm6};

	for (i = 0; i < 6; i ++) {
		edtLst[i]->GetWindowText(cstr);
		cstr.Trim();
		if (!cstr.IsEmpty()) {
			if (!fstr.IsEmpty())
				fstr += _T(",");
			fstr += cstr;
		}
	}

	m_regEdit.SetString(_T("AddFormList"), fstr);
}

void CDlgMPLForm::LoadIni()
{
	CString cstr;
	CString fnam;
	int i, j;
	CEdit* edtLst[] = {&tbForm1, &tbForm2, &tbForm3, &tbForm4, &tbForm5, &tbForm6};

	j = 0;
	for (i = 0; i < 6; i ++) {
		fnam.Format(_T("FormName%d"), i + 1);
		cstr = m_regEdit.GetString(fnam, _T(""));
		cstr.Trim();
		if (!cstr.IsEmpty()) {
			edtLst[j]->SetWindowText(cstr);
			j ++;
		}
	}
}

void CDlgMPLForm::OnBnClickedCbexit()
{
	SaveIni();

	CGcUiDialog::OnOK();
}


BOOL CDlgMPLForm::OnInitDialog()
{
	CGcUiDialog::OnInitDialog();

	m_regEdit.SetKey(HKEY_CURRENT_USER, _T("SOFTWARE\\Magic\\MagicUtil\\MPL"));

	cbForm1.SubclassDlgItem(IDC_CBFORM1, this);
	cbForm1.SetImage(IDB_ADD);
	cbForm2.SubclassDlgItem(IDC_CBFORM2, this);
	cbForm2.SetImage(IDB_ADD);
	cbForm3.SubclassDlgItem(IDC_CBFORM3, this);
	cbForm3.SetImage(IDB_ADD);
	cbForm4.SubclassDlgItem(IDC_CBFORM4, this);
	cbForm4.SetImage(IDB_ADD);
	cbForm5.SubclassDlgItem(IDC_CBFORM5, this);
	cbForm5.SetImage(IDB_ADD);
	cbForm6.SubclassDlgItem(IDC_CBFORM6, this);
	cbForm6.SetImage(IDB_ADD);
	cbEdt1.SubclassDlgItem(IDC_CBEDT1, this);
	cbEdt1.SetImage(IDB_EDT);
	cbEdt2.SubclassDlgItem(IDC_CBEDT2, this);
	cbEdt2.SetImage(IDB_EDT);
	cbEdt3.SubclassDlgItem(IDC_CBEDT3, this);
	cbEdt3.SetImage(IDB_EDT);
	cbEdt4.SubclassDlgItem(IDC_CBEDT4, this);
	cbEdt4.SetImage(IDB_EDT);
	cbEdt5.SubclassDlgItem(IDC_CBEDT5, this);
	cbEdt5.SetImage(IDB_EDT);
	cbEdt6.SubclassDlgItem(IDC_CBEDT6, this);
	cbEdt6.SetImage(IDB_EDT);
	cbDel1.SubclassDlgItem(IDC_CBDEL1, this);
	cbDel1.SetImage(IDB_DEL);
	cbDel2.SubclassDlgItem(IDC_CBDEL2, this);
	cbDel2.SetImage(IDB_DEL);
	cbDel3.SubclassDlgItem(IDC_CBDEL3, this);
	cbDel3.SetImage(IDB_DEL);
	cbDel4.SubclassDlgItem(IDC_CBDEL4, this);
	cbDel4.SetImage(IDB_DEL);
	cbDel5.SubclassDlgItem(IDC_CBDEL5, this);
	cbDel5.SetImage(IDB_DEL);
	cbDel6.SubclassDlgItem(IDC_CBDEL6, this);
	cbDel6.SetImage(IDB_DEL);

	LoadIni();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

