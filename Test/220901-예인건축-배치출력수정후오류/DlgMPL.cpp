// DlgMPL.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MagicUtil.h"
#include "DlgMPL.h"
#include "afxdialogex.h"
#include "DlgMPLStyle.h"
#include "DlgMPLForm.h"
#include "DlgMPLScale.h"
#include <string.h>

#include "DlgMPLWScale.h"
#include "DlgMPLSub.h"

const TCHAR* CDlgMPL::PROGY_NAME = _T("다중 플롯");

// CDlgMPL 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgMPL, CGcUiDialog)

CDlgMPL::CDlgMPL(CWnd* pParent /*=NULL*/)
	: CGcUiDialog(CDlgMPL::IDD, pParent)
{

}

CDlgMPL::~CDlgMPL()
{
}

void CDlgMPL::DoDataExchange(CDataExchange* pDX)
{
	CGcUiDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CBOPLOTTER, cboPlotter);
	DDX_Control(pDX, IDC_CBOPAPER, cboPaper);
	DDX_Control(pDX, IDC_CBOSTYLE, cboStyle);
	DDX_Control(pDX, IDC_CHKSTYLE, chkStyle);
	DDX_Control(pDX, IDC_LVWDWG, lvwDwg);
	DDX_Control(pDX, IDC_CBADD, cbAdd);
	DDX_Control(pDX, IDC_CBFOLDER, cbFolder);
	DDX_Control(pDX, IDC_CBADDCUR, cbAddCur);
	DDX_Control(pDX, IDC_CBADDOPEN, cbAddOpen);
	DDX_Control(pDX, IDC_CBSELOPEN, cbSelOpen);
	DDX_Control(pDX, IDC_CBSELDEL, cbSelDel);
	DDX_Control(pDX, IDC_CBDELALL, cbDelAll);
	DDX_Control(pDX, IDC_CBFUP, cbFup);
	DDX_Control(pDX, IDC_CBUP, cbUp);
	DDX_Control(pDX, IDC_CBDOWN, cbDown);
	DDX_Control(pDX, IDC_CBLDOWN, cbLdown);
	DDX_Control(pDX, IDC_CBSAVE, cbSave);
	DDX_Control(pDX, IDC_CBOPEN, cbOpen);
	DDX_Control(pDX, IDC_CBSORTA, cbSortA);
	DDX_Control(pDX, IDC_CBSORTD, cbSortD);
	DDX_Control(pDX, IDC_TBPATH, tbPath);
	DDX_Control(pDX, IDC_OPTFORM, optForm);
	DDX_Control(pDX, IDC_OPTWINDOW, optWindow);
	DDX_Control(pDX, IDC_OPTEXTEND, optExtend);
	DDX_Control(pDX, IDC_OPTLIMIT, optLimit);
	DDX_Control(pDX, IDC_OPTDRAWING, optDrawing);
	DDX_Control(pDX, IDC_CBFORM, cbForm);
	DDX_Control(pDX, IDC_CBSCALEVIEW, cbScaleView);
	DDX_Control(pDX, IDC_CBWINDOW, cbWindow);
	DDX_Control(pDX, IDC_OPTACTIVE, optActive);
	DDX_Control(pDX, IDC_OPTMODEL, optModel);
	DDX_Control(pDX, IDC_OPTONLYLAYOUT, optOnlyLayout);
	DDX_Control(pDX, IDC_OPTMODELLAYOUT, optModelLayout);
	DDX_Control(pDX, IDC_OPTSPECLAYOUT, optSpecLayout);
	DDX_Control(pDX, IDC_TBLAYOUT, tbLayout);
	DDX_Control(pDX, IDC_CHKFITSCALE, chkFitScale);
	DDX_Control(pDX, IDC_CHKAUTOSCALEA1, chkAutoScaleA1);
	DDX_Control(pDX, IDC_TBSCALE, tbScale);
	DDX_Control(pDX, IDC_CHKPLOTCENTER, chkPlotCenter);
	DDX_Control(pDX, IDC_TBPLOTX, tbPlotX);
	DDX_Control(pDX, IDC_TBPLOTY, tbPlotY);
	DDX_Control(pDX, IDC_THUMBVIEW, ThumbView);
	DDX_Control(pDX, IDC_OPTSORTLR, optSortLR);
	DDX_Control(pDX, IDC_OPTSORTLU, optSortLU);
	DDX_Control(pDX, IDC_OPTSORTLD, optSortLD);
	DDX_Control(pDX, IDC_OPTSORTIZ, optSortIZ);
	DDX_Control(pDX, IDC_TBTOL, tbTol);
	DDX_Control(pDX, IDC_CHKREVERSE, chkReverse);
	DDX_Control(pDX, IDC_CHKSELFORM, chkSelForm);
	DDX_Control(pDX, IDC_CHKPLT, chkPLT);
	DDX_Control(pDX, IDC_CBFIND, cbFind);
	DDX_Control(pDX, IDC_TBPLT, tbPLT);
	DDX_Control(pDX, IDC_CHKRESCALE, chkReScale);
	DDX_Control(pDX, IDC_TBRESCALE, tbReScale);
	DDX_Control(pDX, IDC_OPTAUTO, optAuto);
	DDX_Control(pDX, IDC_OPTHOR, optHor);
	DDX_Control(pDX, IDC_OPTVER, optVer);
	DDX_Control(pDX, IDC_TBPLOTCNT, tbPlotCnt);
	DDX_Control(pDX, IDC_SBCOUNT, sbCount);
	DDX_Control(pDX, IDC_CHKCOPY, chkCopy);
	DDX_Control(pDX, IDC_TBDELAY, tbDelay);
	DDX_Control(pDX, IDC_SBDELAY, sbDelay);
	DDX_Control(pDX, IDC_CHKPREVIW, chkPreviw);
	DDX_Control(pDX, IDC_CBPREVIEW, cbPreview);
	DDX_Control(pDX, IDOK, cbOK);
	DDX_Control(pDX, IDCANCEL, cbCancel);
	DDX_Control(pDX, IDHELP, cbHelp);
	DDX_Control(pDX, IDC_LABEL5, Label5);
	DDX_Control(pDX, IDC_LABEL6, Label6);
	DDX_Control(pDX, IDC_LABEL17, Label17);
	DDX_Control(pDX, IDC_LABEL18, Label18);
	DDX_Control(pDX, IDC_LABEL4, Label4);
	DDX_Control(pDX, IDC_TBSTATE, tbState);
	DDX_Control(pDX, IDC_PLOTSTATE, plotState);
}


BEGIN_MESSAGE_MAP(CDlgMPL, CGcUiDialog)
	ON_BN_CLICKED(IDC_CBPREVIEW, &CDlgMPL::OnBnClickedCbpreview)
	ON_BN_CLICKED(IDC_CBADD, &CDlgMPL::OnBnClickedCbadd)
	ON_BN_CLICKED(IDC_CBFOLDER, &CDlgMPL::OnBnClickedCbfolder)
	ON_BN_CLICKED(IDC_CBADDCUR, &CDlgMPL::OnBnClickedCbaddcur)
	ON_BN_CLICKED(IDC_CBADDOPEN, &CDlgMPL::OnBnClickedCbaddopen)
	ON_BN_CLICKED(IDC_CBSELOPEN, &CDlgMPL::OnBnClickedCbselopen)
	ON_BN_CLICKED(IDC_CBSELMOD, &CDlgMPL::OnBnClickedCbselmod)
	ON_BN_CLICKED(IDC_CBSELDEL, &CDlgMPL::OnBnClickedCbseldel)
	ON_BN_CLICKED(IDC_CBDELALL, &CDlgMPL::OnBnClickedCbdelall)
	ON_BN_CLICKED(IDC_CBFUP, &CDlgMPL::OnBnClickedCbfup)
	ON_BN_CLICKED(IDC_CBLDOWN, &CDlgMPL::OnBnClickedCbldown)
	ON_BN_CLICKED(IDC_CBUP, &CDlgMPL::OnBnClickedCbup)
	ON_BN_CLICKED(IDC_CBDOWN, &CDlgMPL::OnBnClickedCbdown)
	ON_BN_CLICKED(IDC_CBSAVE, &CDlgMPL::OnBnClickedCbsave)
	ON_BN_CLICKED(IDC_CBOPEN, &CDlgMPL::OnBnClickedCbopen)
	ON_BN_CLICKED(IDC_CBSORTA, &CDlgMPL::OnBnClickedCbsorta)
	ON_BN_CLICKED(IDC_CBSORTD, &CDlgMPL::OnBnClickedCbsortd)
	ON_BN_CLICKED(IDC_CBWINDOW, &CDlgMPL::OnBnClickedCbwindow)
	ON_BN_CLICKED(IDC_CHKPREVIW, &CDlgMPL::OnBnClickedChkpreviw)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LVWDWG, &CDlgMPL::OnItemchangedLvwdwg)
	ON_NOTIFY(NM_CLICK, IDC_LVWDWG, &CDlgMPL::OnClickLvwdwg)
	ON_NOTIFY(NM_DBLCLK, IDC_LVWDWG, &CDlgMPL::OnDblclkLvwdwg)
	ON_CBN_SELCHANGE(IDC_CBOPLOTTER, &CDlgMPL::OnCbnSelchangeCboplotter)
	ON_CBN_SELCHANGE(IDC_CBOPAPER, &CDlgMPL::OnCbnSelchangeCbopaper)
	ON_CBN_SELCHANGE(IDC_CBOSTYLE, &CDlgMPL::OnCbnSelchangeCbostyle)
	ON_BN_CLICKED(IDC_CBFORM, &CDlgMPL::OnBnClickedCbform)
	ON_BN_CLICKED(IDC_CBFIND, &CDlgMPL::OnBnClickedCbfind)
	ON_BN_CLICKED(IDC_CHKFITSCALE, &CDlgMPL::OnBnClickedChkfitscale)
	ON_BN_CLICKED(IDC_CHKAUTOSCALEA1, &CDlgMPL::OnBnClickedChkautoscalea1)
	ON_BN_CLICKED(IDC_CHKPLOTCENTER, &CDlgMPL::OnBnClickedChkplotcenter)
	ON_BN_CLICKED(IDC_CBSCALEVIEW, &CDlgMPL::OnBnClickedCbscaleview)
	ON_BN_CLICKED(IDC_OPTACTIVE, &CDlgMPL::OnBnClickedOptactive)
	ON_BN_CLICKED(IDC_OPTMODEL, &CDlgMPL::OnBnClickedOptactive)
	ON_BN_CLICKED(IDC_OPTONLYLAYOUT, &CDlgMPL::OnBnClickedOptactive)
	ON_BN_CLICKED(IDC_OPTMODELLAYOUT, &CDlgMPL::OnBnClickedOptactive)
	ON_BN_CLICKED(IDC_OPTSPECLAYOUT, &CDlgMPL::OnBnClickedOptactive)
	ON_BN_CLICKED(IDC_OPTFORM, &CDlgMPL::OnBnClickedOptform)
	ON_BN_CLICKED(IDC_OPTWINDOW, &CDlgMPL::OnBnClickedOptform)
	ON_BN_CLICKED(IDC_OPTEXTEND, &CDlgMPL::OnBnClickedOptform)
	ON_BN_CLICKED(IDC_OPTLIMIT, &CDlgMPL::OnBnClickedOptform)
	ON_BN_CLICKED(IDC_OPTDRAWING, &CDlgMPL::OnBnClickedOptform)
	ON_BN_CLICKED(IDC_CHKPLT, &CDlgMPL::OnBnClickedChkplt)
	ON_BN_CLICKED(IDC_CHKRESCALE, &CDlgMPL::OnBnClickedChkrescale)
	ON_BN_CLICKED(IDOK, &CDlgMPL::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgMPL::OnBnClickedCancel)
	ON_BN_CLICKED(IDHELP, &CDlgMPL::OnClickedIdhelp)
END_MESSAGE_MAP()


// CDlgMPL 메시지 처리기입니다.


void CDlgMPL::GetItemPos(UINT id, int &x, int &y)
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


void CDlgMPL::MoveDlgItem(UINT id, int x, int y)
{
	CWnd *cwnd;
	cwnd = GetDlgItem(id);
	ASSERT(cwnd);
	cwnd->SetWindowPos(NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE | SWP_NOZORDER);
}


void CDlgMPL::OnBnClickedOk()
{
	SaveIni();

	MultiplePlot(FALSE);
}


void CDlgMPL::OnBnClickedCbpreview()
{
	MultiplePlot(TRUE);
}

typedef struct _FormArea {
	gds_name ename;
	double sx, sy, ex, ey;
} FormArea;

typedef struct _AreaList {
	int formNum;
	FormArea* formList;
} AreaList;

void AddFormArea(FormArea* &formList, int &num, FormArea* formData)
{
	if (num < 0)
		return;
	
	num ++;
	FormArea* newList = (FormArea*) malloc (sizeof(FormArea) * num);
	if (num > 1)
		memcpy(newList, formList, sizeof(FormArea) * (num - 1));
	if (formList)
		free(formList);
	formList = newList;

	memcpy(newList + (num - 1), formData, sizeof(FormArea));
}

void DelFormArea(FormArea* &formList, int &num, int loc)
{
	if (!formList)
		return;
	if (loc < 0 || loc >= num)
		return;
	if (num == 1) {
		num = 0;
		free(formList);
		formList = NULL;
		return;
	}

	num --;
	FormArea* newList = (FormArea*) malloc(sizeof(FormArea) * num);
	memcpy(newList, formList, sizeof(FormArea) * loc);
	memcpy(newList + loc, formList + (loc + 1), sizeof(FormArea) * (num - loc));

	free(formList);
	formList = newList;
}

void AddAreaList(AreaList* &areaList, int &num, FormArea* formData)
{
	if (num < 0)
		return;

	num ++;
	AreaList* newList = (AreaList *) malloc (sizeof(AreaList) * num);
	if (num > 1)
		memcpy(newList, areaList, sizeof(AreaList) * (num - 1));
	if (areaList)
		free(areaList);
	areaList = newList;

	areaList[num - 1].formNum = 1;
	areaList[num - 1].formList = new FormArea;
	memcpy(areaList[num - 1].formList, formData, sizeof(FormArea));
}

int static CompFormHN (const void* prev, const void* next)
{
	FormArea* pArea = (FormArea*) prev;
	FormArea* nArea = (FormArea*) next;

	if (pArea->sx > nArea->sx)
        return 1;
    else
        return -1;
}

int static CompListVN (const void* prev, const void* next)
{
	AreaList* pList = (AreaList*) prev;
	AreaList* nList = (AreaList*) next;

	if (pList->formList->sy > nList->formList->sy)
        return 1;
    else
        return -1;
}

int static CompListVR (const void* prev, const void* next)
{
	AreaList* pList = (AreaList*) prev;
	AreaList* nList = (AreaList*) next;

	if (pList->formList->sy < nList->formList->sy)
        return 1;
    else
        return -1;
}

int static CompFormVN (const void* prev, const void* next)
{
	FormArea* pArea = (FormArea*) prev;
	FormArea* nArea = (FormArea*) next;

	if (pArea->sy > nArea->sy)
        return 1;
    else
        return -1;
}

int static CompFormVR (const void* prev, const void* next)
{
	FormArea* pArea = (FormArea*) prev;
	FormArea* nArea = (FormArea*) next;

	if (pArea->sy < nArea->sy)
        return 1;
    else
        return -1;
}

int static CompListHN (const void* prev, const void* next)
{
	AreaList* pList = (AreaList*) prev;
	AreaList* nList = (AreaList*) next;

	if (pList->formList->sx > nList->formList->sx)
        return 1;
    else
        return -1;
}

void SortSelZ(gds_name ssname, double sTol, int sortDir, BOOL sortRev)
{
	long iXrefCnt;
	gcedSSLength(ssname, &iXrefCnt);

	gds_name ename;
	GcDbObjectId objId;
	GcDbEntity* pEnt;
	GcDbBlockReference* pInsert;
	Gcad::ErrorStatus es;
	int formNum = 0;
	FormArea* formList = NULL;
	int i, j;

	formNum = iXrefCnt;
	formList = (FormArea*) malloc(sizeof(FormArea) * formNum);

	for (i = 0; i < iXrefCnt; i ++) {
		gcedSSName(ssname, i, ename);
		gcdbGetObjectId(objId, ename);
		if (gcdbOpenGcDbEntity(pEnt, objId, GcDb::kForRead) != Gcad::eOk)
			continue;
		pInsert = GcDbBlockReference::cast(pEnt);
		if (!pInsert) {
			pEnt->close();
			continue;
		}

		GcDbObjectId blockDefId;
		blockDefId = pInsert->blockTableRecord();
		GcDbBlockTableRecord *pBlkRecord;
		gcdbOpenObject(pBlkRecord, blockDefId, GcDb::kForRead);
		const TCHAR* formName;
		es = pBlkRecord->getName(formName);

		GcDbExtents extents;
		GcGePoint3d vMin;
		GcGePoint3d vMax;

		pInsert->geomExtentsBestFit(extents);
		vMin = extents.minPoint();
		vMax = extents.maxPoint();

		gds_name_set(ename, formList[i].ename);
		formList[i].sx = vMin[X];
		formList[i].sy = vMin[Y];
		formList[i].ex = vMax[X];
		formList[i].ey = vMax[Y];

		pEnt->close();
	}

	// divide to rows
	int rowNum = 0;
	AreaList* rowList = NULL;
	FormArea formData;
	while (formNum > 0) {
		memcpy (&formData, formList, sizeof(FormArea));
		AddAreaList(rowList, rowNum, formList);
		DelFormArea(formList, formNum, 0);
		i = 0;
		while (i < formNum) {
			if (sortDir == 0 || sortDir == 3) {
				if (formData.sy <= formList[i].ey &&
					formData.ey >= formList[i].sy) {
					AddFormArea(rowList[rowNum - 1].formList, rowList[rowNum - 1].formNum, formList + i);
					DelFormArea(formList, formNum, i);
				}
				else
					i ++;
			}
			else {
				if (formData.sx <= formList[i].ex &&
					formData.ex >= formList[i].sx) {
					AddFormArea(rowList[rowNum - 1].formList, rowList[rowNum - 1].formNum, formList + i);
					DelFormArea(formList, formNum, i);
				}
				else
					i ++;
			}
		}
	}

	if (sortDir == 0) {
		for (i = 0; i < rowNum; i ++)
			qsort(rowList[i].formList, rowList[i].formNum, sizeof(FormArea), CompFormHN);
		qsort(rowList, rowNum, sizeof(AreaList), CompListVR);
	}
	else if (sortDir == 1) {
		for (i = 0; i < rowNum; i ++)
			qsort(rowList[i].formList, rowList[i].formNum, sizeof(FormArea), CompFormVN);
		qsort(rowList, rowNum, sizeof(AreaList), CompListHN);
	}
	else if (sortDir == 2) {
		for (i = 0; i < rowNum; i ++)
			qsort(rowList[i].formList, rowList[i].formNum, sizeof(FormArea), CompFormVR);
		qsort(rowList, rowNum, sizeof(AreaList), CompListHN);
	}
	else if (sortDir == 3) {
		for (i = 0; i < rowNum; i ++)
			qsort(rowList[i].formList, rowList[i].formNum, sizeof(FormArea), CompFormHN);
		qsort(rowList, rowNum, sizeof(AreaList), CompListVN);
	}

	gcedSSFree(ssname);
	if (sortRev) {
		for (i = (rowNum - 1); i >= 0; i --) {
			for (j = (rowList[i].formNum - 1); j >= 0; j --)
				gcedSSAdd(rowList[i].formList[j].ename, ssname, ssname);
			free(rowList[i].formList);
		}
	}
	else {
		for (i = 0; i < rowNum; i ++) {
			for (j = 0; j < rowList[i].formNum; j ++)
				gcedSSAdd(rowList[i].formList[j].ename, ssname, ssname);
			free(rowList[i].formList);
		}
	}
	if (rowList)
		free(rowList);
}

int CDlgMPL::PlotLayout(BOOL previewPlot, CString& logStr, CDlgMPLExit* dlgExit)
{
	CString cstr;

	logStr.Empty();

	if (optDrawing.GetCheck()) {
		// use plotter and paper specified in the layout
		m_plotterName = m_iLayout.get_ConfigName();
		BOOL insideSet;
		if (m_plotterName.CompareNoCase(_T("없음")) == 0 || m_plotterName.CompareNoCase(_T("none")) == 0)
			insideSet = FALSE;
		else
			insideSet = IsExistCombo(m_plotterName, &cboPlotter);

		if (!insideSet) {
			if (m_bActive || m_bModel || m_bSpecLayout) {
				logStr = _T("도면에 저장된 출력설정이 없음");
				return 1;
			}
			else {
/*
				if (iNext == (iLayCnt - 1)) {
					if (!bPloted) {
						bPlotErr = TRUE;
						LogErr(pDoc->get_Name() + _T(" : 도면에 저장된 출력 설정이 없습니다."), FALSE);
						return 1;
					}
				}
*/
				logStr = _T("도면에 저장된 출력설정이 없음");
				return 2;
			}
		}
	}
	else {
		// change the current layout plotter
		m_iLayout.put_ConfigName(m_plotterName);
		m_iLayout.put_CanonicalMediaName(m_mediaName);
		m_iLayout.put_StyleSheet(m_styleName);
		m_iLayout.put_PlotWithPlotStyles(TRUE);
		m_iLayout.put_PlotWithLineweights(TRUE);
		m_iLayout.RefreshPlotDeviceInfo();

		// plot scale
		if (chkFitScale.GetCheck()) {
			m_iLayout.put_UseStandardScale(TRUE);
			m_iLayout.put_StandardScale(acScaleToFit);
		}

		// plot orient
		if (optHor.GetCheck())
			m_iLayout.put_PlotRotation(ac90degrees);
		else if (optVer.GetCheck())
			m_iLayout.put_PlotRotation(ac0degrees);

		// plot center
		if (chkPlotCenter.GetCheck())
			m_iLayout.put_CenterPlot(TRUE);
		else {
			m_iLayout.put_CenterPlot(FALSE);

			double dOrigin[2];
			GetDlgItemText(IDC_TBPLOTX, cstr);
			dOrigin[0] = _ttof(cstr);
			GetDlgItemText(IDC_TBPLOTY, cstr);
			dOrigin[1] = _ttof(cstr);

			VARIANT var;
			Point2d2Array(&var, dOrigin);
			m_iLayout.put_PlotOrigin(var);
		}

		// plot area (Extent, Limit, Layout)
		if (optExtend.GetCheck()) {
			m_iLayout.put_PlotType(acExtents);
		}
		else if (optLimit.GetCheck()) {
			if (m_bOnlyLayout || m_bSpecLayout)
				m_iLayout.put_PlotType(acLayout);
			else {
				if (m_bActive) {
					CString pLayName = m_iLayout.get_Name();
					if (pLayName.CompareNoCase(_T("model")) != 0)
						m_iLayout.put_PlotType(acLayout);
					else
						m_iLayout.put_PlotType(acLimits);
				}
				else
					m_iLayout.put_PlotType(acLimits);
			}
		}

		m_iLayout.RefreshPlotDeviceInfo();
		// plot unit
		m_iLayout.put_PaperUnits(acMillimeters);
		m_iDoc.Regen(acAllViewports);
	}

	// plot form area
	if (m_bPlotWindow) {
		gds_name ssname; 
		gds_name ename, enames;
		gds_point pt1, pt2;
		GcDbObjectId objId;
		GcDbEntity* pEnt;
		GcDbBlockReference* pInsert;
		Gcad::ErrorStatus es;
		long sslen, i;
		int rt;

		if (chkSelForm.GetCheck()) {
			dlgExit->ShowWindow(SW_HIDE);

			gcedSSAdd(NULL, NULL, ssname);
			while(1) {
				// Let the user select an INSERT (Block reference).
				rt = gcedEntSel(_T("\nForm 선택"), ename, pt1);
				if (rt == RTCAN) // cancel or error
					break;
				if (pt1[X] == 0 && pt1[Y] == 0 && pt1[Z] == 0)
					break;

				if (rt == RTNORM) {
					// Test the entity type.
					gcdbGetObjectId(objId, ename);
					if ((es = gcdbOpenGcDbEntity(pEnt, objId, GcDb::kForRead)) != Gcad::eOk) {
						AfxMessageBox (_T("선택한 객체를 열 수 없습니다."), MB_OK | MB_ICONINFORMATION);
						continue;
					}

					pInsert = GcDbBlockReference::cast(pEnt);
					if (!pInsert) {
						AfxMessageBox (_T("선택한 객체는 INSERT가 아닙니다."), MB_OK | MB_ICONINFORMATION);
						pEnt->close();
						continue;
					}
					pEnt->close();

					gcedSSAdd(ename, ssname, ssname);
				}
				else {
					struct resbuf rb1, rb2;
					TCHAR sbuf[10] = _T("INSERT"); 
					TCHAR snam[256]; 
					_tcscpy(snam, m_formList);

					rb1.restype = 0; // entity name
					rb1.resval.rstring = sbuf; // _T("INSERT");
					rb1.rbnext = &rb2;
					rb2.restype = 2; // block name
					rb2.resval.rstring = snam;
					rb2.rbnext = NULL;

					gcedGetCorner(pt1, _T("\nForm 범위 선택"), pt2);
					// Select the entities that fall within the window.
					gcedSSGet(L"W", &pt1, &pt2, &rb1, enames);
 
					// Get the length of the selection set
					gcedSSLength(enames, &sslen);
					for (i = 0; i < sslen; i ++) {
						gcedSSName(enames, i, ename);
						gcdbGetObjectId(objId, ename);
						if ((es = gcdbOpenGcDbEntity(pEnt, objId, GcDb::kForRead)) != Gcad::eOk) {
							continue;
						}

						pInsert = GcDbBlockReference::cast(pEnt);
						if (!pInsert) {
							pEnt->close();
							continue;
						}
						pEnt->close();

						gcedSSAdd(ename, ssname, ssname);
					}
				}
			}

			dlgExit->ShowWindow(SW_SHOWNORMAL);
		}
		else {
			struct resbuf rb1, rb2;
			TCHAR sbuf[10] = _T("INSERT"); 
			TCHAR snam[256]; 
			_tcscpy(snam, m_formList);

			rb1.restype = 0; // entity name
			rb1.resval.rstring = sbuf; // _T("INSERT");
			rb1.rbnext = &rb2;
			rb2.restype = 2; // block name
			rb2.resval.rstring = snam;
			rb2.rbnext = NULL;

			// Retrieve all BlockReference.
			gcedSSGet(_T("X"), NULL, NULL, &rb1, ssname); 
		}

		//Set oSel = CurSpaceEnt(oSel)
		long iXrefCnt;
		gcedSSLength(ssname, &iXrefCnt);
		if (iXrefCnt < 1) {
			if (m_bActive || m_bModel || m_bSpecLayout) {
				logStr = _T("도면에 지정한 Form이 없음 : '") + m_formList + _T("'");
				return 1;
			}
			else {
/*
				if (iNext == iLayCnt) {
					if (!bPloted) {
						LogErr(iDoc.get_Name() + _T(" : 도면에 지정한 이름의 Form이 없습니다 - ") + sTemp, FALSE);
						return 1;
					}
				}
*/
				logStr = _T("도면에 지정한 Form이 없음 : '") + m_formList + _T("'");
				return 2;
			}
		}

		if (chkPLT.GetCheck()) {
			// plot to file
			CString fName = m_iDoc.get_Name();
			int loc = fName.ReverseFind('.');
			if (loc >= 0)
				fName = fName.Left(loc);

			GetDlgItemText(IDC_TBPLT, cstr);
			m_fileName = cstr;
			if (m_fileName.Right(1) != "\\")
				m_fileName += "\\";
			m_fileName += fName;
		}

        // 외부참조 1개 이상시 인서트 포인트로 소트
		if (iXrefCnt > 0) {
			GetDlgItemText(IDC_TBTOL, cstr);
			m_dSTol = _ttof(cstr);
			m_dSRev = chkReverse.GetCheck();
			int sortDir;

            if (optSortLR.GetCheck())
				sortDir = 0;
            else if (optSortLU.GetCheck())
				sortDir = 1;
            else if (optSortLD.GetCheck())
				sortDir = 2;
			else
				sortDir = 3;

			SortSelZ(ssname, m_dSTol, sortDir, m_dSRev);
		}

		int k;
		for (k = 0; k < iXrefCnt; k ++) {
			gcedSSName(ssname, k, ename);
			gcdbGetObjectId(objId, ename);
			if (gcdbOpenGcDbEntity(pEnt, objId, GcDb::kForRead) != Gcad::eOk)
				continue;
			pInsert = GcDbBlockReference::cast(pEnt);
			if (!pInsert) {
				pEnt->close();
				continue;
			}

			CString layNam;
			GcDbLayerTableRecord* layPtr;
			layNam = pEnt->layer();
			layPtr = GetLayerObj(layNam, GcDb::kForRead);
			bool layOff = layPtr->isOff();
			layPtr->close();
			if (layOff) {
				pEnt->close();
				continue;
			}

			GcDbObjectId blockDefId;
			blockDefId = pInsert->blockTableRecord();
			GcDbBlockTableRecord *pBlkRecord;
			gcdbOpenObject(pBlkRecord, blockDefId, GcDb::kForRead);
			const TCHAR* formName;
			es = pBlkRecord->getName(formName);

			if (!previewPlot)
				dlgExit->SetForm(formName);

			int iniPos = GetFormIniPos(formName);
			CString nstr;
			nstr.Format(_T("%d"), iniPos);

			// read settings stored
			BOOL bRealVert; // = m_regEdit.GetBoolean(_T("RealVertical") + nstr, FALSE);
			double dPaperH = m_regEdit.GetDouble(_T("PaperHeight") + nstr, _T("594"));
			/*
			if (m_paperName.Find(_T("A0")) >= 0)
				dPaperH = 1189.0;
			else if (m_paperName.Find(_T("A1")) >= 0)
				dPaperH = 841.0;
			else if (m_paperName.Find(_T("A2")) >= 0)
				dPaperH = 594.0;
			else if (m_paperName.Find(_T("A3")) >= 0)
				dPaperH = 420.0;
			else
				dPaperH = 297.0;
			*/
			dPaperH = 594.0;
			double dYHeight = m_regEdit.GetDouble(_T("Height") + nstr, _T("594"));
			double dXWidth = m_regEdit.GetDouble(_T("Width") + nstr, _T("841"));
			double dMin[2];
			double dMax[2];

			/* 2018.06.29 Do not use Form Area */
			/*
			dMin[X] = m_regEdit.GetDouble(_T("FromMinX") + nstr, _T("0"));
			dMin[Y] = m_regEdit.GetDouble(_T("FromMinY") + nstr, _T("0"));
			dMax[X] = m_regEdit.GetDouble(_T("FromMaxX") + nstr, _T("841"));
			dMax[Y] = m_regEdit.GetDouble(_T("FromMaxY") + nstr, _T("594"));
			*/
			GcDbExtents extents;
			GcGePoint3d vMin;
			GcGePoint3d vMax;
			pInsert->geomExtentsBestFit(extents);
			double rAng = pInsert->rotation();
			GcGeScale3d fScl = pInsert->scaleFactors();

			vMin = extents.minPoint();
			vMax = extents.maxPoint();
			dXWidth = (vMax[X] - vMin[X]) / fScl.sx;
			dYHeight = (vMax[Y] - vMin[Y]) / fScl.sy;

			dMin[X] = 0.0;
			dMin[Y] = 0.0;
			dMax[X] = dXWidth; // / fScl.sx;
			dMax[Y] = dYHeight; // / fScl.sy;

			BOOL bVertical = m_regEdit.GetBoolean(_T("IsVertical") + nstr, FALSE);

			if (tbScale.IsWindowEnabled()) {
				GetDlgItemText(IDC_TBSCALE, cstr);
				m_dScale = _ttof(cstr);

				m_iLayout.put_UseStandardScale(FALSE);
				m_iLayout.SetCustomScale(1, m_dScale); // 지정 축척
			}
			else if (chkAutoScaleA1.GetCheck())
				m_dScale = GetPlotScaleByA1(dYHeight, bVertical);
			else
				m_dScale = GetPlotScaleByA1(dPaperH, bVertical);

			if (!previewPlot) {
				dlgExit->Flush();
				if (dlgExit->m_bCancel) {
					logStr = _T("출력 중단");
					return 3;
				}
			}

			BOOL bRotate;
 			GcGePoint3d dZero(0, 0, 0);
			double dSelVer;
			double dSelHor;

			if (m_bUCS) {
				//With oSel.Item(k)
				if (m_dTWAng != 0)
					Rotate(pInsert, dZero, m_dTWAng);
				bRotate = IsVerDwg(pInsert->rotation());
				pInsert->geomExtentsBestFit(extents);
				vMin = extents.minPoint();
				vMax = extents.maxPoint();
				dSelVer = (vMax[Y] - vMin[Y]) * fScl.sy;
				dSelHor = (vMax[X] - vMin[X]) * fScl.sx;
				if (m_dTWAng != 0)
					Rotate(pInsert, dZero, -m_dTWAng);
				vMin = GetRotPnt(dZero, vMin, -m_dTWAng);
				vMax = GetRotPnt(dZero, vMax, -m_dTWAng);
			}
			else {
				//With oSel.Item(k)
				bRotate = FALSE;
				pInsert->geomExtentsBestFit(extents);
				vMin = extents.minPoint();
				vMax = extents.maxPoint();
				dSelVer = (vMax[Y] - vMin[Y]) * fScl.sy;
				dSelHor = (vMax[X] - vMin[X]) * fScl.sx;
			}

			// 추가 : 2018.06.22
			pInsert->close();

			vMin = ToDCS(vMin);
			vMax = ToDCS(vMax);

			//////////////////
			dYHeight = DoubleAbs(vMax[Y] - vMin[Y]);
			dXWidth = DoubleAbs(vMax[X] - vMin[X]);
			if (dYHeight > dXWidth)
				bVertical = TRUE;
			else
				bVertical = FALSE;

			if (!bRotate && bVertical)
				bRealVert = TRUE;
			else {
				if (bRotate && !bVertical)
					bRealVert = TRUE;
				else
					bRealVert = FALSE;
			}
			/////////////////

			GcGePoint3d dZoomMin;
			dZoomMin[X] = vMin[X];
			dZoomMin[Y] = vMin[Y];
			dZoomMin[Z] = 0.0;
			GcGePoint3d dZoomMax;
			dZoomMax[X] = vMax[X];
			dZoomMax[Y] = vMax[Y];
			dZoomMax[Z] = 0.0;

			if (!m_bUCS)
				//ZoomWindow(dZoomMin, dZoomMax);
				gcedCommand(RTSTR, _T("_ZOOM"), RTSTR, _T("_W"),
					RTPOINT, asDblArray(dZoomMin),
					RTPOINT, asDblArray(dZoomMax), RTNONE);

			// 원래 폼이 세로 도면이면 가로 세로 뒤집는다
			if (bRealVert)
				bRotate = !bRotate;

			double dX;
			double dY;
			m_iLayout.GetPaperSize(&dX, &dY);
			BOOL bHorPaper = (dX >= dY) ? TRUE: FALSE;

			// 지정한 폼과 현재 폼과의 크기차이
			double dPlotMin[2];
			double dPlotMax[2];

			if (!bRotate) { // 회전 안된 도면
				if (bVertical) {
					if ((dSelHor / dYHeight) > (dSelVer / dXWidth))
						m_dDiff = dSelHor / dYHeight;
					else
						m_dDiff = dSelVer / dXWidth;
					// 출력할 윈도우(Two Array)
					dPlotMin[X] = vMin[X] + dMin[X] * m_dDiff;
					dPlotMin[Y] = vMin[Y] + dMin[Y] * m_dDiff;
					dPlotMax[X] = vMin[X] + dMax[Y] * m_dDiff;
					dPlotMax[Y] = vMin[Y] + dMax[X] * m_dDiff;
				}
				else {
					if ((dSelVer / dYHeight) > (dSelHor / dXWidth))
						m_dDiff = dSelVer / dYHeight;
					else
						m_dDiff = dSelHor / dXWidth;
					dPlotMin[X] = vMin[X] + dMin[X] * m_dDiff;
					dPlotMin[Y] = vMin[Y] + dMin[Y] * m_dDiff;
					dPlotMax[X] = vMin[X] + dMax[X] * m_dDiff;
					dPlotMax[Y] = vMin[Y] + dMax[Y] * m_dDiff;
				}
				if (optAuto.GetCheck()) {
					if (bHorPaper)
						m_iLayout.put_PlotRotation(ac0degrees);
					else
						m_iLayout.put_PlotRotation(ac90degrees);
				}
			}
			else {
				if (bVertical) {
					if ((dSelHor / dXWidth) > (dSelVer / dYHeight))
						m_dDiff = dSelHor / dXWidth;
					else
						m_dDiff = dSelVer / dYHeight;
					dPlotMin[X] = vMin[X] + dMin[X] * m_dDiff;
					dPlotMin[Y] = vMin[Y] + dMin[Y] * m_dDiff;
					dPlotMax[X] = vMin[X] + dMax[X] * m_dDiff;
					dPlotMax[Y] = vMin[Y] + dMax[Y] * m_dDiff;
				}
				else {
					if ((dSelHor / dYHeight) > (dSelVer / dXWidth))
						m_dDiff = dSelHor / dYHeight;
					else
						m_dDiff = dSelVer / dXWidth;
					dPlotMin[X] = vMin[X] + dMin[X] * m_dDiff;
					dPlotMin[Y] = vMin[Y] + dMin[Y] * m_dDiff;
					dPlotMax[X] = vMin[X] + dMax[Y] * m_dDiff;
					dPlotMax[Y] = vMin[Y] + dMax[X] * m_dDiff;
				}
				if (optAuto.GetCheck()) {
					if (bHorPaper)
						m_iLayout.put_PlotRotation(ac90degrees);
					else
						m_iLayout.put_PlotRotation(ac0degrees);
				}
			}

			//With oLayout
			// 윈도우설정.PlotType을 SetWindowToPlot 뒤에 써줘야 함
			VARIANT var1, var2;
			Point2d2Array(&var1, dPlotMin);
			Point2d2Array(&var2, dPlotMax);
			m_iLayout.SetWindowToPlot(var1, var2);
			m_iLayout.put_PlotType(acWindow);

			// '폼이 여러개인 경우가 있으므로 폼출력은 순환하면서 아래를 거쳐야 한다.
			if (chkFitScale.GetCheck()) { // 용지에 맞춤
				m_iLayout.put_UseStandardScale(TRUE);
				m_iLayout.put_StandardScale(acScaleToFit);
			}
			else if (chkAutoScaleA1.GetCheck()) { // 자동 맞춤(A1기준)
				m_iLayout.put_UseStandardScale(FALSE);
				m_iLayout.SetCustomScale(1, m_dScale * m_dDiff * m_dReScale);
			}
			else { // 지정한 축척
				m_iLayout.put_UseStandardScale(FALSE);
				m_iLayout.SetCustomScale(1, m_dScale * m_dDiff * m_dReScale);
			}

			if (chkCopy.GetCheck())
				m_iPlot.put_NumberOfCopies(1);
			else
				m_iPlot.put_NumberOfCopies(GetDlgItemInt(IDC_TBPLOTCNT)); // 플롯 매수

			if (previewPlot)
				m_iPlot.DisplayPlotPreview(acFullPreview); // 플롯 미리보기
			else {
				if (chkPreviw.GetCheck())
					m_iPlot.DisplayPlotPreview(acFullPreview); // 플롯 미리보기
				else {
					if (chkPLT.GetCheck()) {
						// 모델인 경우 모델하나에 도곽이 여러개면 아래에서 도곽 개수인 k로 출력시
						// 번호가 다르게 나오지만 배치인경우 배치하나당 폼이 하나면
						// 아래 k로 출력하는 경우 배치 하나당 폼이 한개라 k는 계속 0 이됨
						// 따라서 iFileNum 변수를 두고
						// 모델인 경우는 k 값 그냥 사용
						// 배치인 경우는 iFileNum 증분해서 값을 다르게 한다
						if (m_bActive || m_bModel)
							m_fileNum = k + 1;
						else
							m_fileNum ++;

						GetComboText(&cboPlotter, cstr);
						cstr.MakeUpper();
						if (cstr.Find(_T(".JPG")) >= 0)
							cstr.Format(_T("%s-%d.%s"), m_fileName, m_fileNum, _T("jpg"));
						else if (cstr.Find(_T(".PNG")) >= 0)
							cstr.Format(_T("%s-%d.%s"), m_fileName, m_fileNum, _T("png"));
						else if (cstr.Find(_T(".PDF")) >= 0)
							cstr.Format(_T("%s-%d.%s"), m_fileName, m_fileNum, _T("pdf"));
						else
							cstr.Format(_T("%s-%d.%s"), m_fileName, m_fileNum, _T("plt"));
						m_iPlot.PlotToFile(cstr, _variant_t(m_plotterName));
					}
					else {
						GetComboText(&cboPlotter, cstr);
						m_iPlot.PlotToDevice(_variant_t(cstr)); // 플롯
					}
				}
			}
			int dTim = GetDlgItemInt(IDC_TBDELAY);
			if (dTim > 0)
				Sleep(dTim * 1000);
		} // End of 한도면내의 여러폼
	} // End of 폼출력
	else {
		if (!previewPlot)
			dlgExit->SetForm(_T(""));

		GetDlgItemText(IDC_TBSCALE, cstr);
		m_dScale = _ttof(cstr);
		m_dDiff = 1.0;

	}

	if (!previewPlot) {
		dlgExit->Flush();
		if (dlgExit->m_bCancel) {
			logStr = _T("출력 중단");
			return 3;
		}
	}

	// plot specified area
	if (optWindow.GetCheck()) {
		BOOL bWinUser = m_regEdit.GetBoolean(_T("WinUser"), FALSE);

		GcGePoint3d vSpnt;
		GcGePoint3d vEpnt;
		double dPlotMin[2];
		double dPlotMax[2];
		// 사용자가 윈도우 선택
		if (bWinUser) {
			dlgExit->ShowWindow(SW_HIDE);

			if (gcedGetPoint(NULL, _T("\n인쇄할 영역의 첫번째 모서리 점 지정:"), asDblArray(vSpnt)) != RTNORM) {
				logStr = _T("인쇄 영역 지정 취소");
				dlgExit->ShowWindow(SW_SHOWNORMAL);
				return 1;
			}

			if (gcedGetCorner(asDblArray(vSpnt), _T("\n인쇄할 영역의 두번째 모서리 점 지정:"), asDblArray(vEpnt)) != RTNORM) {
				logStr = _T("인쇄 영역 지정 취소");
				dlgExit->ShowWindow(SW_SHOWNORMAL);
				return 1;
			}

			dlgExit->ShowWindow(SW_SHOWNORMAL);

			vSpnt = ToDCS(vSpnt);
			vEpnt = ToDCS(vEpnt);

			if (vEpnt[Y] < vSpnt[Y])
				SwapVoidData(&vSpnt, &vEpnt, sizeof (GcGePoint3d));

			dPlotMin[X] = vSpnt[X];
			dPlotMin[Y] = vSpnt[Y];
			dPlotMax[X] = vEpnt[X];
			dPlotMax[Y] = vEpnt[Y];
		}
		else {
			// 지정한 윈도우
			dPlotMin[X] = m_regEdit.GetDouble(_T("WinMinX"), 0.0);
			dPlotMin[Y] = m_regEdit.GetDouble(_T("WinMinY"), 0.0);
			dPlotMax[X] = m_regEdit.GetDouble(_T("WinMaxX"), 841.0);
			dPlotMax[Y] = m_regEdit.GetDouble(_T("WinMaxY"), 594.0);
			//vSpnt = ZeroPoint;
			//vEpnt = ZeroPoint;
			vSpnt[X] = dPlotMin[X];
			vSpnt[Y] = dPlotMin[Y];
			vEpnt[X] = dPlotMax[X];
			vEpnt[Y] = dPlotMax[Y];
			vSpnt = ToDCS(ToWCS(vSpnt));
			vEpnt = ToDCS(ToWCS(vEpnt));
			dPlotMin[X] = vSpnt[X];
			dPlotMin[Y] = vSpnt[Y];
			dPlotMax[X] = vEpnt[X];
			dPlotMax[Y] = vEpnt[Y];
		}

		VARIANT var1, var2;
		Point2d2Array(&var1, dPlotMin);
		Point2d2Array(&var2, dPlotMax);
		m_iLayout.SetWindowToPlot(var1, var2);
		m_iLayout.put_PlotType(acWindow);
	} // End of 윈도우출력

	// 일반출력 공통(폼 제외)
	if (!m_bPlotWindow) {
		if (!optDrawing.GetCheck()) {
			// 용지에 맞춤
			if (chkFitScale.GetCheck()) {
				m_iLayout.put_UseStandardScale(TRUE);
				m_iLayout.put_StandardScale(acScaleToFit);
			}
			// 자동 맞춤(A1기준)
			else if (chkAutoScaleA1.GetCheck()) {
				m_iLayout.put_UseStandardScale(FALSE);
				m_iLayout.SetCustomScale(1, m_dScale * m_dDiff * m_dReScale);
			}
			// 지정한 축척
			else {
				m_iLayout.put_UseStandardScale(FALSE);
				m_iLayout.SetCustomScale(1, m_dScale * m_dDiff * m_dReScale);
			}
		}

		if (chkCopy.GetCheck())
			m_iPlot.put_NumberOfCopies(1);
		else
			m_iPlot.put_NumberOfCopies(GetDlgItemInt(IDC_TBPLOTCNT)); // 플롯 매수

		if (previewPlot)
			m_iPlot.DisplayPlotPreview(acFullPreview); // 플롯 미리보기
		else {
			if (chkPreviw.GetCheck())
				m_iPlot.DisplayPlotPreview(acFullPreview); // 플롯 미리보기
			else {
				if (chkPLT.GetCheck()) {
					GetDlgItemText(IDC_TBPLT, cstr);
					if (cstr.Right(1) != "\\")
						cstr += "\\";
					m_iPlot.PlotToFile(cstr, _variant_t(m_plotterName));
				}
				else {
/*
					if (optDrawing.GetCheck())
						m_iPlot.PlotToDevice(_variant_t(m_plotterName));
					else {
						GetComboText(&cboPlotter, cstr);
						m_iPlot.PlotToDevice(_variant_t(cstr));
					}
*/
					m_iPlot.PlotToDevice(_variant_t(m_plotterName));
				}
			}
		}
	}

	return 0;
}


void CDlgMPL::MultiplePlot(BOOL previewPlot)
{
	CString cstr;
	int iCnt;
	int i;

	CStringArray sLog;

	if (lvwDwg.GetItemCount() < 1) {
		AfxMessageBox(_T("목록에 출력할 도면이 없습니다"), MB_OK | MB_ICONINFORMATION);
		return;
	}

	ResetPlotState();

	SetVariable(_T("cmdecho"), 1);

	GetComboText(&cboPlotter, m_plotterName);
	GetComboText(&cboPaper, m_paperName);
	m_paperName.MakeUpper();
	int index = cboPaper.GetCurSel();
	m_mediaName = (TCHAR *)cboPaper.GetItemDataPtr(index);

	BOOL filePlot = chkPLT.GetCheck();

	if (!previewPlot) {
		cstr = m_plotterName;
		cstr.MakeUpper();
		if (cstr.Find(_T("PUBLISHTOWEB")) >= 0) {
			if (!filePlot) {
				if (!chkPreviw.GetCheck()) {
					AfxMessageBox(_T("그림 파일로 출력하려면 [파일로 플롯]에 체크해 주십시오"), MB_OK | MB_ICONINFORMATION);
					chkPLT.SetFocus();
					return;
				}
			}
		}
		if (cstr.Find(_T("DWG TO PDF")) >= 0) {
			if (!chkPLT.GetCheck()) {
				if (!chkPreviw.GetCheck()) {
					AfxMessageBox(_T("PDF 파일로 출력하려면 [파일로 플롯]에 체크해 주십시오"), MB_OK | MB_ICONINFORMATION);
					chkPLT.SetFocus();
					return;
				}
			}
		}
		if (cstr.Find(_T("DWF6 EPLOT")) >= 0 || cstr.Find(_T("DWFX EPLOT")) >= 0) {
			if (!chkPLT.GetCheck()) {
				if (!chkPreviw.GetCheck()) {
					AfxMessageBox(_T("DWF 파일로 출력하려면 [파일로 플롯]에 체크해 주십시오"), MB_OK | MB_ICONINFORMATION);
					chkPLT.SetFocus();
					return;
				}
			}
		}

		if (cstr.Find(_T("DWF6 EPLOT")) >= 0 || cstr.Find(_T("DWFX EPLOT")) >= 0) {
			if (!chkPLT.GetCheck()) {
				if (!chkPreviw.GetCheck()) {
					AfxMessageBox(_T("DWF 파일로 출력하려면 [파일로 플롯]에 체크해 주십시오"), MB_OK | MB_ICONINFORMATION);
					chkPLT.SetFocus();
					return;
				}
			}
		}
	}

	if (!optDrawing.GetCheck()) {
		if (m_plotterName.CompareNoCase(_T("없음")) == 0 || m_plotterName.CompareNoCase(_T("none")) == 0) {
			AfxMessageBox(_T("출력할 플로터를 선택하여 주십시오"), MB_OK | MB_ICONINFORMATION);
			return;
		}
		if (m_paperName.CompareNoCase(_T("없음")) == 0 || m_paperName.CompareNoCase(_T("none")) == 0) {
			AfxMessageBox(_T("출력할 용지를 선택하여 주십시오"), MB_OK | MB_ICONINFORMATION);
			return;
		}
	}

	if (!previewPlot) {
		if (chkPLT.GetCheck()) {
			tbPLT.GetWindowText(cstr);
			if (cstr == _T("")) {
				AfxMessageBox(_T("파일을 저장할 경로가 지정되지 않았습니다"), MB_OK | MB_ICONINFORMATION);
				cbFind.SetFocus();
				return;
			}
		}
	}

	if (optSpecLayout.GetCheck()) {
		tbLayout.GetWindowText(cstr);
		if (cstr == _T("")) {
			AfxMessageBox(_T("Layout 이름이 지정되지 않았습니다"), MB_OK | MB_ICONINFORMATION);
			tbLayout.SetFocus();
			return;
		}
	}

	if (chkAutoScaleA1.GetCheck()) {
		if (!IsAPaper()) {
			AfxMessageBox(_T("자동 맞춤 옵션을 사용하려면 용지를 A 시리즈 용지로 설정하시거나\n현재 용지 크기로 출력하려면 자동 맞춤 옵션을 해제해 주십시오"), MB_OK | MB_ICONINFORMATION);
			chkAutoScaleA1.SetFocus();
			return;
		}
	}


	if (optForm.GetCheck()) {
		m_formList = m_regEdit.GetString(_T("AddFormList"), _T(""));
		m_formList.Trim();
		if (m_formList.IsEmpty()) {
			AfxMessageBox(_T("등록된 Form(도곽)이 없습니다\n[Form 등록] 버튼을 눌러 Form을 추가해 주십시오"), MB_OK | MB_ICONINFORMATION);
			cbForm.SetFocus();
			return;
		}
	}

	if (GetDlgItemInt(IDC_TBPLOTCNT) < 1)
		SetDlgItemInt(IDC_TBPLOTCNT, 1);
	if (chkPLT.GetCheck()) {
		if (!chkPreviw.GetCheck())
			SetDlgItemInt(IDC_TBPLOTCNT, 1);
	}
	if (GetDlgItemInt(IDC_TBDELAY) < 0)
		SetDlgItemInt(IDC_TBDELAY, 0);

	m_bActive = optActive.GetCheck();
	m_bModel = optModel.GetCheck();
	m_bOnlyLayout = optOnlyLayout.GetCheck();
	m_bModel_Lay = optModelLayout.GetCheck();
	m_bSpecLayout = optSpecLayout.GetCheck();

	// re-scale for plotting scale
	if (chkReScale.GetCheck()) {
		tbReScale.GetWindowTextW(cstr);
		if (_ttof(cstr) == 0)
			m_dReScale = 1.0;
		else
			m_dReScale = 100.0 / _ttof(cstr);
	}
	else
		m_dReScale = 1.0;

	// do not show message
	int iExpert;
	GetVariable(_T("EXPERT"), iExpert);
	if (iExpert == 0)
		SetVariable(_T("EXPERT"), 1);

	int iDwgCheck;
	GetVariable(_T("DWGCHECK"), iDwgCheck);
	if (iDwgCheck == 1)
		SetVariable(_T("DWGCHECK"), 0);

	/*
	HKEY_CURRENT_USER\Software\Gstarsoft\GstarCAD\R15.0
	\ko-KR\Application
	*/
	CString regKey = _T("SOFTWARE\\Gstarsoft\\GstarCAD\\R15.0");
	CRegEdit regEdit;
	regEdit.SetKey(HKEY_CURRENT_USER, regKey);
	CString curVer = regEdit.GetString(_T("CurVer"), _T("ko-KR"));
	regKey = regKey + _T("\\") + curVer + _T("\\Application");
	regEdit.SetKey(HKEY_CURRENT_USER, regKey);
	int repProm = regEdit.GetInteger(_T("PromptReplaceFont"), 1);
	int repFont = regEdit.GetInteger(_T("ReplaceFont"), 1);

	regEdit.SetInteger(_T("PromptReplaceFont"), 0);
	regEdit.SetInteger(_T("ReplaceFont"), 0);

	BeginEditorCommand();

	// Show CancelDialog
	CDlgMPLExit dlgExit(this);
	if (!previewPlot) {
		dlgExit.Create(CDlgMPLExit::IDD);
		dlgExit.ShowWindow(SW_SHOWNORMAL);
		dlgExit.Flush();
	}

	if (optForm.GetCheck())
		m_bPlotWindow = TRUE;
	else
		m_bPlotWindow = FALSE;

	double dDiff = 1;

	BOOL bMPLCancel = FALSE;
	BOOL bMPLExit = FALSE;

	IDispatch *pDisp;
	CGcadLayouts iLayouts;

	// number of copies
	int iCopyNum;
	if (chkCopy.GetCheck())
		iCopyNum = GetDlgItemInt(IDC_TBPLOTCNT);
	else
		iCopyNum = 1;
	if (chkPLT.GetCheck())
		iCopyNum = 1;

	if (!previewPlot)
		dlgExit.SetRange(lvwDwg.GetItemCount() * iCopyNum);

	int iPlotBack;
	// show off proxy warning
	SetVariable(_T("proxynotice"), 0);
	// show of background plotting
	GetVariable(_T("BACKGROUNDPLOT"), iPlotBack);
	SetVariable(_T("BACKGROUNDPLOT"), 0);

	CString logStr;
	CString pLayName;
	int iCopy;
	int plotRet;
	BOOL plotErr;

	plotRet = 0;
	plotErr = FALSE;
	for (iCopy = 0; iCopy < iCopyNum; iCopy ++) {
		if (!previewPlot)
			dlgExit.SetCopy(iCopy + 1, iCopyNum);

		//iCnt = lvwDwg.GetItemCount(); //210729수정
		iCnt = lvwDwg.GetItemCount();
		for (i = 0; i < iCnt; i ++) {
			// 미리보기면 선택한 아이템으로 지정
			if (previewPlot) {
				POSITION pos = lvwDwg.GetFirstSelectedItemPosition();
				if (pos)
					i = lvwDwg.GetNextSelectedItem(pos);
				else
					i = 0;
			}
			else {
				dlgExit.StepIt();
				dlgExit.Flush();
			}

			m_fileNum = 0; // 파일로 플롯 카운트

			if (!previewPlot) {
				dlgExit.Flush();
				if (dlgExit.m_bCancel) {
					plotErr = TRUE;
					break;
				}
			}

			BOOL bDview = FALSE;
			BOOL bPloted = FALSE;
			BOOL bOpen = FALSE; // drawing is opened ?
			CString sDwg = lvwDwg.GetItemText(i, 3);

			if (!previewPlot)
				dlgExit.SetDraw(sDwg);

			bOpen = TRUE;
			if (!FindOpenDwg(sDwg, &m_iDoc)) {
				//if (!previewPlot)
				//	dlgExit.ShowWindow(SW_HIDE);
				OpenDwgFile(sDwg);

				//if (!previewPlot)
				//	dlgExit.ShowWindow(SW_SHOWNORMAL);
				if (!FindOpenDwg(sDwg, &m_iDoc)) {
					lvwDwg.SetItemText(i, 2, _T("X"));
					lvwDwg.SetItemText(i, 4, _T("도면을 열 수 없습니다"));

					cstr.Format(_T("%s 도면을 열 수 없습니다\n계속 진행하시겠습니까?"), lvwDwg.GetItemText(i, 0));
					if (AfxMessageBox(cstr, MB_YESNO | MB_ICONQUESTION) == IDYES)
						goto NextDwg;
					else
						goto ErrorHandler;
				}
				bOpen = FALSE;
			}
			else {
				m_iDoc.Activate();
			}

			m_bUCS = FALSE;
			m_dTWAng = GetTWAng();
			if (m_dTWAng != 0)
				m_dTWAng = - m_dTWAng;
			if (!IsWCS())
				m_bUCS = TRUE;
			else {
				if (m_dTWAng != 0) {
					bDview = TRUE;
					SetViewUcs(TRUE);
					m_bUCS = TRUE;
				}
			}

			pDisp = m_iDoc.get_Layouts();
			iLayouts.AttachDispatch(pDisp);

			// Iterate through all the items in the dictionary
			long iLayCnt = iLayouts.get_Count();
			long iNext;
			for (iNext = 0; iNext < iLayCnt; iNext ++) {
				if (m_bActive) {
					// plot active layout
					pDisp = m_iDoc.get_ActiveLayout(); 
					m_iLayout.AttachDispatch(pDisp);
					pLayName = m_iLayout.get_Name();
				}
				else {
					// plot a layout in the layout list
					pDisp = iLayouts.Item(_variant_t(iNext));
					m_iLayout.AttachDispatch(pDisp);
					pLayName = m_iLayout.get_Name();

					// check matching layout
					if (m_bModel) {
						// get the model layout
						if (pLayName.CompareNoCase(_T("model")) != 0)
							goto NextLayout;
					}
					else if (m_bOnlyLayout) {
						if (pLayName.CompareNoCase(_T("model")) == 0)
							goto NextLayout;
					}
					else if (m_bModel_Lay) {
						// 그냥 진행
					}
					else if (m_bSpecLayout) {
						GetDlgItemText(IDC_TBLAYOUT, cstr);
						long j;
						for (j = 0; j < iLayCnt; j ++) {
							pDisp = iLayouts.Item(COleVariant(j));
							m_iLayout.AttachDispatch(pDisp);
							pLayName = m_iLayout.get_Name();
							if (cstr.CompareNoCase(pLayName) == 0)
								break;
						}
						if (j == iLayCnt) {
							logStr = _T("지정한 Layout이 없음");
							plotRet = 1;
							goto FormErr;
						}
						//pDisp = iLayouts.Item(_variant_t(cstr));
						//m_iLayout.AttachDispatch(pDisp);
						//pLayName = m_iLayout.get_Name();
					}
					m_iDoc.put_ActiveLayout(m_iLayout);
				}
				if (!previewPlot)
					dlgExit.SetLayout(pLayName);

				// do not show plot error message
				pDisp = m_iDoc.get_Plot();
				m_iPlot.AttachDispatch(pDisp);
				m_iPlot.put_QuietErrorMode(FALSE);

				m_styleName = lvwDwg.GetItemText(i, 1);

				// return 1 = errors in the form
				// return 2 = errors in the layout
				plotRet = PlotLayout(previewPlot, logStr, &dlgExit);

FormErr:
				if (plotRet > 0)
					plotErr = TRUE;
				if (!previewPlot) {
					if (plotRet > 0) {
						lvwDwg.SetItemText(i, 2, _T("X"));
						lvwDwg.SetItemText(i, 4, logStr);
					}
					else {
						lvwDwg.SetItemText(i, 2, _T("O"));
						lvwDwg.SetItemText(i, 4, _T("출력 완료"));
					}
				}
				if (plotRet == 2)
					goto NextLayout;
				else if (plotRet == 3)
					break;

				// errors in the form
NextDwg:
				// 활성, 모형, 특정레이아웃이면 한번 돌고 종료
				if (previewPlot || m_bActive || optModel.GetCheck() || m_bSpecLayout)
					break;

				// errors in the layout
NextLayout:
				;
			} // Layout Iterator

////////////////////////////////////////////////////////////////////////////////
			// 열린도면은 닫지 않고, ViewUCS 했으면 원상복구
			if (bOpen) {
				if (bDview)
					SetViewUcs(FALSE);
			}
			else {
				VARIANT saveChanges,fileName;
				saveChanges.vt = VT_BOOL;
				saveChanges.boolVal = VARIANT_FALSE;
				fileName.vt = VT_ERROR;
				fileName.scode = DISP_E_PARAMNOTFOUND;
				m_iDoc.Close(saveChanges, fileName);
			}
			if (!m_bPlotWindow) {
				int dTim = GetDlgItemInt(IDC_TBDELAY);
				if (dTim > 0)
					Sleep(dTim * 1000);
			}

			// 미리보기면 선택한 아이템으로 처리했으니 순환하지 않고 종료
			if (previewPlot)
				break;
		} // next i, 도면한장 끝
	} // next iCopy, 인쇄매수

ErrorHandler:

	if (!previewPlot)
		dlgExit.ShowWindow(SW_HIDE);

	CompleteEditorCommand();

	UpdatePlotState();

	// 시스템 변수되돌림
	SetVariable(_T("BACKGROUNDPLOT"), iPlotBack);
	SetVariable(_T("Expert"), iExpert);
	SetVariable(_T("DWGCHECK"), iDwgCheck);

	regEdit.SetInteger(_T("PromptReplaceFont"), repProm);
	regEdit.SetInteger(_T("ReplaceFont"), repFont);

	if (previewPlot) {
		if (plotErr)
			AfxMessageBox(_T("미리보기에 다음과 같은 문제가 있습니다.\n") + logStr, MB_OK | MB_ICONWARNING);
	}
	else {
		if (plotErr)
			AfxMessageBox(_T("일부 도면이 출력되지 않았습니다.\n[X]로 표시된 목록을 선택하여 플롯상태를 확인하십시오."), MB_OK | MB_ICONWARNING);
		else
			AfxMessageBox(_T("모든 도면이 출력되었습니다."), MB_OK | MB_ICONINFORMATION);
	}
}


int CDlgMPL::GetFormIniPos(LPCTSTR sFormName)
{
	CString s;
	CString n;
	int i;

	for (i = 1; i <= 6; i ++) {
		n.Format(_T("FormName%d"), i);
		s = m_regEdit.GetString(n, _T(""));
		s.Trim();
		if (!s.IsEmpty()) {
			if (s.CompareNoCase(sFormName) == 0)
				return i;
		}
	}

	return 0;
}

// SelectionSet에 있는 Entity 중에서 CurrentSpace에 있는 Entity만 선택
void CDlgMPL::CurSpaceEnt(gds_name oSel)
{
	long iCnt;
	long i;
	GcDbObjectIdArray oEnt;
	GcDbObjectId iObjID;
	GcDbObjectId iOwnID;

	GcDbObjectId entID;
	GcDbEntity* entPtr;
	gds_name entNam;

	iObjID = gcdbHostApplicationServices()->workingDatabase()->currentSpaceId();
	iCnt = 0;
	gcedSSLength (oSel, &iCnt);
	for (i = 0; i < iCnt; i ++) {
		if (gcedSSName (oSel, i, entNam) != RTNORM)
			continue;
		gcdbGetObjectId(entID, entNam);
		gcdbOpenObject(entPtr, entID, GcDb::kForRead);
		if (iOwnID == entPtr->ownerId())
			oEnt.append(entID);
		entPtr->close();
	}

	gcedSSFree(oSel);

	iCnt = oEnt.length();
	for (i = 0; i < iCnt; i ++) {
		gcdbGetGdsName(entNam, oEnt[i]);
		gcedSSAdd(entNam, oSel, oSel);
	}
}


BOOL CDlgMPL::IsVerDwg(double dRotation)
{
//	 If Round(dRotation, 12) >= Round(pi * 2, 12) Then dRotation = Round(dRotation - pi * 2, 12)
//	 If dRotation > pi Then dRotation = dRotation - pi
//	 If dRotation > pi / 4 Then IsVerDwg = True
	if (dRotation < (PI / 4))
		return FALSE;
	if (dRotation > (TPI - (PI / 4)))
		return FALSE;

	return TRUE;
}


BOOL IsDupListView(LPCTSTR sName, CListCtrl *oList, int iCol = 2)
{
	CString sItem;
	int iCnt;
	int i;

	if (sName[0] == '\0')
		return FALSE;

	iCnt = oList->GetItemCount();
	for (i = 0; i < iCnt; i ++) {
		sItem = oList->GetItemText(i, iCol) + oList->GetItemText(i, 0);
		if (sItem.CompareNoCase(sName) == 0)
			return TRUE;
	}

	return FALSE;
}


void CDlgMPL::UpdatePlotState()
{
	int iCnt;
	int pCnt;
	int i;
	CString cstr;

	iCnt = lvwDwg.GetItemCount();
	pCnt = 0;
	for (i = 0; i < iCnt; i ++) {
		cstr = lvwDwg.GetItemText(i, 2);
		if (cstr.CompareNoCase(_T("O")) == 0)
			pCnt ++;
	}

	cstr.Format(_T("%d/%d"), pCnt, iCnt);
	plotState.SetWindowTextW(cstr);
}


void CDlgMPL::ResetPlotState()
{
	int iCnt;
	int i;
	CString cstr;

	iCnt = lvwDwg.GetItemCount();
	for (i = 0; i < iCnt; i ++) {
		lvwDwg.SetItemText(i, 2, _T(""));
		lvwDwg.SetItemText(i, 4, _T(""));
	}

	cstr.Format(_T("0/%d"), iCnt);
	plotState.SetWindowTextW(cstr);
}


// 도면 추가
void CDlgMPL::OnBnClickedCbadd()
{
	CString sOldPath;
	CString filPth, filNam;
	CString styNam;
	BOOL bDup;
	POSITION pos;
	int i;

	sOldPath = m_regEdit.GetString(_T("PrevFolder"), _T("C:\\"));

	CFileDialog filDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY,
		_T("도면파일 (*.dwg)|*.dwg|All Files(*.*)|*.*||"));
	filDlg.m_ofn.lpstrTitle = _T("파일 추가"); 
	filDlg.m_ofn.lpstrInitialDir = sOldPath;
	filDlg.m_ofn.Flags = OFN_EXPLORER | OFN_LONGNAMES | OFN_CREATEPROMPT |
						OFN_NODEREFERENCELINKS | OFN_ALLOWMULTISELECT;
	// 별도 버퍼를 지정하지 않으면 MultiSelect에서 선택된 파일이 다 넘어오지 않음
	TCHAR buff[65536];
	buff[0] = '\0';
	filDlg.m_ofn.lpstrFile = buff;
	filDlg.m_ofn.nMaxFile = 65536;

	if (filDlg.DoModal() != IDOK)
		return;

	sOldPath = filDlg.GetFolderPath();
	m_regEdit.SetString(_T("PrevFolder"), sOldPath);

	GetComboText(&cboStyle, styNam);

	bDup = FALSE;
	pos = filDlg.GetStartPosition();
	while (pos) {
		filPth = filDlg.GetNextPathName(pos);
		i = filPth.ReverseFind('\\');
		if (i >= 0)
			filNam = filPth.Right(filPth.GetLength() - i - 1);
		else
			filNam = filPth;

		if (IsDupListView(filPth, &lvwDwg))
			bDup = TRUE;
		else {
			i = lvwDwg.GetItemCount();
			i = lvwDwg.InsertItem(i, filNam);
			lvwDwg.SetItemText(i, 1, styNam);
			lvwDwg.SetItemText(i, 3, filPth);
			lvwDwg.SetItemData(i, i);
		}
	}

	if (bDup)
		AfxMessageBox(_T("이미 등록된 도면은 제외되었습니다"), MB_OK | MB_ICONINFORMATION);

	ResetPlotState();
}


void CDlgMPL::AppendDir(LPCTSTR dirName, LPCTSTR findName)
{
	WIN32_FIND_DATA findData;
	HANDLE hFind;
	CString filPath, filNam;
	CString msgStr;
	CString styNam;
	CString fileExt = _T(".DWG");
	int i;

	filPath.Format(_T("%s\\*"), dirName, findName);
	if ((hFind = FindFirstFile(filPath, &findData)) == INVALID_HANDLE_VALUE) {
		return;
	}

	GetComboText(&cboStyle, styNam);

	do {
		if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			if (((LPCTSTR)&findData.cFileName)[0] == '.')
				continue;
			else if (((LPCTSTR)&findData.cFileName)[0] == '..')
				continue;
			else {
				filPath.Format(_T("%s\\%s"), dirName, findData.cFileName);
				AppendDir(filPath, findName);
			}
		}
		else if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)) {
			filNam = findData.cFileName; //파일명을 찾는 변수, 모든 파일을 찾음
			filNam.MakeUpper();
			if (filNam.Find (fileExt) >= 0) {
				filPath.Format(_T("%s\\%s"), dirName, findData.cFileName);
				i = lvwDwg.GetItemCount();
				i = lvwDwg.InsertItem(i, findData.cFileName);
				lvwDwg.SetItemText(i, 1, styNam);
				lvwDwg.SetItemText(i, 3, filPath);
				lvwDwg.SetItemData(i, i);
			}
		}
	} while (FindNextFile (hFind, &findData));

	FindClose (hFind);
}

void _SHFree(void *p)
{
	IMalloc *pm;
	SHGetMalloc(&pm);
	if (pm) {
		pm->Free(p);
		pm->Release();
	}
}


static int CALLBACK SetInputDirProc (HWND hwnd, UINT uMsg,
			LPARAM lParam, LPARAM lpData)
{
	TCHAR szDir[MAX_PATH];

	switch (uMsg) {
	case BFFM_INITIALIZED:
		SendMessage (hwnd, BFFM_SETSELECTION, (WPARAM)TRUE, (LPARAM)lpData);
		break;
	case BFFM_SELCHANGED:
		if (SHGetPathFromIDList ((LPITEMIDLIST) lParam, szDir)) {
			SendMessage (hwnd, BFFM_SETSTATUSTEXT, 0, (LPARAM) szDir);
		}
		break;
	}

	return 0;
}


// 폴더 추가
void CDlgMPL::OnBnClickedCbfolder()
{
	BROWSEINFO browInfo;
	LPITEMIDLIST itemList;
	TCHAR dirPath[MAX_PATH];

	memset(&browInfo, 0, sizeof (BROWSEINFO));
	browInfo.hwndOwner = m_hWnd;
	browInfo.lpszTitle = _T("입력 폴더");
	browInfo.ulFlags = BIF_RETURNONLYFSDIRS | BIF_VALIDATE | BIF_STATUSTEXT;
	browInfo.lpfn = SetInputDirProc;
	browInfo.lParam = (LPARAM)(LPCSTR)dirPath;
	itemList = SHBrowseForFolder (&browInfo);
	if (!itemList)
		return;

	SHGetPathFromIDList(itemList, dirPath);
	_SHFree(itemList);

	AppendDir(dirPath, _T("*.dwg"));

	ResetPlotState();
}


// 활성 도면 추가
void CDlgMPL::OnBnClickedCbaddcur()
{
	GcApDocument* doc;
	BOOL bDup;
	CString filNam, filPth;
	CString styNam;
	int i;

	doc = gcDocManager->curDocument();
	if (doc == NULL)
		return;

	filPth = doc->fileName();
	GetComboText(&cboStyle, styNam);

	bDup = FALSE;
	if (IsDupListView(filPth, &lvwDwg))
		bDup = TRUE;
	else {
		i = filPth.ReverseFind('\\');
		if (i >= 0)
			filNam = filPth.Right(filPth.GetLength() - i - 1);
		else
			filNam = filPth;

		i = lvwDwg.GetItemCount();
		i = lvwDwg.InsertItem(i, filNam);
		lvwDwg.SetItemText(i, 1, styNam);
		lvwDwg.SetItemText(i, 3, filPth);
		lvwDwg.SetItemData(i, i);
	}

	if (bDup)
		AfxMessageBox(_T("이미 등록된 도면은 제외되었습니다"), MB_OK | MB_ICONINFORMATION);
}


// 열린 도면 추가
void CDlgMPL::OnBnClickedCbaddopen()
{
	GcApDocument* doc;
	BOOL bDup;
	int i;
	CString filPth, filNam;
	CString styNam;

	GetComboText(&cboStyle, styNam);

	bDup = FALSE;
	doc = NULL;
	GcApDocumentIterator *Iter = gcDocManager->newAcApDocumentIterator();
	while (!Iter->done()) {
		doc = Iter->document();
		filPth = doc->fileName();
		if (IsDupListView(filPth, &lvwDwg))
			bDup = TRUE;
		else {
			i = filPth.ReverseFind('\\');
			if (i >= 0)
				filNam = filPth.Right(filPth.GetLength() - i - 1);
			else
				filNam = filPth;

			i = lvwDwg.GetItemCount();
			i = lvwDwg.InsertItem(i, filNam);
			lvwDwg.SetItemText(i, 1, styNam);
			lvwDwg.SetItemText(i, 3, filPth);
			lvwDwg.SetItemData(i, i);
		}
		Iter->step();
	}
	delete Iter;

	if (bDup)
		AfxMessageBox(_T("이미 등록된 도면은 제외되었습니다"), MB_OK | MB_ICONINFORMATION);
}


// 선택 항목 열기
void CDlgMPL::OnBnClickedCbselopen()
{
	POSITION pos;
	int loc;
	CString filPth;
	CGcadDocument iDoc;

	if (lvwDwg.GetItemCount() < 1)
		return;

	gcedCommand(RTSTR, _T("filedia"), RTSTR, _T("0"), RTNONE);

	pos = lvwDwg.GetFirstSelectedItemPosition();
	while (pos) {
		loc = lvwDwg.GetNextSelectedItem(pos);
		filPth = lvwDwg.GetItemText(loc, 3);
		if (FindOpenDwg(filPth, &iDoc))
			iDoc.Activate();
		else
			OpenDwgFile(filPth);
	}

	gcedCommand(RTSTR, _T("filedia"), RTSTR, _T("1"), RTNONE);

	lvwDwg.SetFocus();
}


void CDlgMPL::OnBnClickedCbselmod()
{
	POSITION pos;
	int loc;
	CString filPth;
	CGcadDocument iDoc;

	if (lvwDwg.GetItemCount() < 1)
		return;

	gcedCommand(RTSTR, _T("filedia"), RTSTR, _T("0"), RTNONE);

	pos = lvwDwg.GetFirstSelectedItemPosition();
	while (pos) {
		loc = lvwDwg.GetNextSelectedItem(pos);
		filPth = lvwDwg.GetItemText(loc, 3);
		if (FindOpenDwg(filPth, &iDoc))
			iDoc.Activate();
		else
			OpenDwgFile(filPth);
	}

	gcedCommand(RTSTR, _T("filedia"), RTSTR, _T("1"), RTNONE);

	lvwDwg.SetFocus();
}


// 리스트뷰 선택 항목 삭제
void CDlgMPL::OnBnClickedCbseldel()
{
	int iCnt;
	int i;

	iCnt = lvwDwg.GetItemCount();
	if (iCnt < 1)
		return;

	for (i = iCnt - 1; i >= 0; i --) {
		if (lvwDwg.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
			lvwDwg.DeleteItem(i);
	}

	lvwDwg.SetFocus();

	ResetPlotState();
}


// 리스트뷰 전체 항목 삭제
void CDlgMPL::OnBnClickedCbdelall()
{
	lvwDwg.DeleteAllItems();
	lvwDwg.SetFocus();

	ResetPlotState();
}


// 리스트뷰 맨위로 이동
void CDlgMPL::OnBnClickedCbfup()
{
	CString sTemp0;
	CString sTemp1;
	CString sTemp2;
	CString sTemp3;
	CString sTemp4;
	int iCnt;
	int i, j, k;

	iCnt = lvwDwg.GetItemCount();
	if (iCnt < 1)
		return;

	k = 0;
	for (i = 1; i < iCnt; i ++) {
		if (lvwDwg.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED) {
			sTemp0 = lvwDwg.GetItemText(i, 0);
			sTemp1 = lvwDwg.GetItemText(i, 1);
			sTemp2 = lvwDwg.GetItemText(i, 2);
			sTemp3 = lvwDwg.GetItemText(i, 3);
			sTemp4 = lvwDwg.GetItemText(i, 4);
			lvwDwg.DeleteItem(i);
			j = lvwDwg.InsertItem(k, sTemp0);
			lvwDwg.SetItemText(j, 1, sTemp1);
			lvwDwg.SetItemText(j, 2, sTemp2);
			lvwDwg.SetItemText(j, 3, sTemp3);
			lvwDwg.SetItemText(j, 4, sTemp4);
			lvwDwg.SetItemState (j, LVIS_SELECTED, LVIS_SELECTED);
			k ++;
		}
	}

	lvwDwg.SetFocus();
}


// 리스트뷰 맨아래로 이동
void CDlgMPL::OnBnClickedCbldown()
{
	CString sTemp0;
	CString sTemp1;
	CString sTemp2;
	CString sTemp3;
	CString sTemp4;
	int iCnt;
	int i, j, k;

	iCnt = lvwDwg.GetItemCount();
	if (iCnt < 1)
		return;

	k = 0;
	for (i = iCnt - 2; i >= 0; i --) {
		if (lvwDwg.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED) {
			sTemp0 = lvwDwg.GetItemText(i, 0);
			sTemp1 = lvwDwg.GetItemText(i, 1);
			sTemp2 = lvwDwg.GetItemText(i, 2);
			sTemp3 = lvwDwg.GetItemText(i, 3);
			sTemp4 = lvwDwg.GetItemText(i, 4);
			lvwDwg.DeleteItem(i);
			j = lvwDwg.InsertItem(iCnt - k, sTemp0);
			lvwDwg.SetItemText(j, 1, sTemp1);
			lvwDwg.SetItemText(j, 2, sTemp2);
			lvwDwg.SetItemText(j, 3, sTemp3);
			lvwDwg.SetItemText(j, 4, sTemp4);
			lvwDwg.SetItemState (j, LVIS_SELECTED, LVIS_SELECTED);
			k ++;
		}
	}

	lvwDwg.SetFocus();
}


// 리스트뷰 위로 이동
void CDlgMPL::OnBnClickedCbup()
{
	CString sTemp0;
	CString sTemp1;
	CString sTemp2;
	CString sTemp3;
	CString sTemp4;
	int iCnt;
	int i, j;

	iCnt = lvwDwg.GetItemCount();
	if (iCnt < 1)
		return;

	for (i = 1; i < iCnt; i ++) {
		if (lvwDwg.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED) {
			sTemp0 = lvwDwg.GetItemText(i, 0);
			sTemp1 = lvwDwg.GetItemText(i, 1);
			sTemp2 = lvwDwg.GetItemText(i, 2);
			sTemp3 = lvwDwg.GetItemText(i, 3);
			sTemp4 = lvwDwg.GetItemText(i, 4);
			lvwDwg.DeleteItem(i);
			j = lvwDwg.InsertItem(i - 1, sTemp0);
			lvwDwg.SetItemText(j, 1, sTemp1);
			lvwDwg.SetItemText(j, 2, sTemp2);
			lvwDwg.SetItemText(j, 3, sTemp3);
			lvwDwg.SetItemText(j, 4, sTemp4);
			lvwDwg.SetItemState (j, LVIS_SELECTED, LVIS_SELECTED);
		}
	}

	lvwDwg.SetFocus();
}


// 리스트뷰 아래로 이동
void CDlgMPL::OnBnClickedCbdown()
{
	CString sTemp0;
	CString sTemp1;
	CString sTemp2;
	CString sTemp3;
	CString sTemp4;
	int iCnt;
	int i, j;

	iCnt = lvwDwg.GetItemCount();
	if (iCnt < 1)
		return;

	for (i = iCnt - 2; i >= 0; i --) {
		if (lvwDwg.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED) {
			sTemp0 = lvwDwg.GetItemText(i, 0);
			sTemp1 = lvwDwg.GetItemText(i, 1);
			sTemp2 = lvwDwg.GetItemText(i, 2);
			sTemp3 = lvwDwg.GetItemText(i, 3);
			sTemp4 = lvwDwg.GetItemText(i, 4);
			lvwDwg.DeleteItem(i);
			j = lvwDwg.InsertItem(i + 1, sTemp0);
			lvwDwg.SetItemText(j, 1, sTemp1);
			lvwDwg.SetItemText(j, 2, sTemp2);
			lvwDwg.SetItemText(j, 3, sTemp3);
			lvwDwg.SetItemText(j, 4, sTemp4);
			lvwDwg.SetItemState (j, LVIS_SELECTED, LVIS_SELECTED);
		}
	}

	lvwDwg.SetFocus();
}


// 플롯 목록 텍스트파일로 저장
void CDlgMPL::OnBnClickedCbsave()
{
	CString sOldPath;
	CString sOpenFile;
	int iCnt;
	int i;
	FILE *fout;
	CString cstr;

	iCnt = lvwDwg.GetItemCount();
	if (iCnt < 1) {
		AfxMessageBox(_T("목록에 저장할 도면이 없습니다"), MB_OK | MB_ICONINFORMATION);
		return;
	}

	sOldPath = m_regEdit.GetString(_T("SaveFolder"), _T("C:\\"));

	CFileDialog filDlg(FALSE, NULL, NULL, OFN_HIDEREADONLY,
		_T("텍스트 파일 (*.txt)|*.txt|All Files(*.*)|*.*||"));
	filDlg.m_ofn.lpstrTitle = _T("목록 텍스트 파일 저장"); 
	filDlg.m_ofn.lpstrInitialDir = sOldPath;
	if (filDlg.DoModal() != IDOK)
		return;

	sOpenFile = filDlg.GetPathName();
	sOldPath = filDlg.GetFolderPath();
	m_regEdit.SetString(_T("SaveFolder"), sOldPath);

	fout = _tfopen(sOpenFile, _T("w"));
	if (fout == NULL)
		return;

	_ftprintf(fout, _T("[Magic Plot List]\n"));
	for (i = 0; i < iCnt; i ++)
		_ftprintf(fout, _T("%s,%s,%s\n"), lvwDwg.GetItemText(i, 3), lvwDwg.GetItemText(i, 0), lvwDwg.GetItemText(i, 1)); //210729수정
		//_ftprintf(fout, _T("%s,%s,%s\n"), static_cast<CString>(lvwDwg.GetItemText(i, 3)), static_cast<CString>(lvwDwg.GetItemText(i, 0)), static_cast<CString>(lvwDwg.GetItemText(i, 1)));
	fclose(fout);
}


// 플롯 목록 열기
void CDlgMPL::OnBnClickedCbopen()
{
	CString sOldPath;
	CString sOpenFile;
	FILE *fin;
	CStringArray strArr;
	CString sPath;
	int i;
	BOOL bDup;
	TCHAR sData[1024];
	CString cstr;

	sOldPath = m_regEdit.GetString(_T("OpenFolder"), _T("C:\\"));

	CFileDialog filDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY,
		_T("텍스트 파일 (*.txt)|*.txt|All Files(*.*)|*.*||"));
	filDlg.m_ofn.lpstrTitle = _T("출력 목록 텍스트 파일 열기"); 
	filDlg.m_ofn.lpstrInitialDir = sOldPath;
	if (filDlg.DoModal() != IDOK)
		return;

	sOpenFile = filDlg.GetPathName();
	sOldPath = filDlg.GetFolderPath();
	m_regEdit.SetString(_T("OpenFolder"), sOldPath);

	fin = _tfopen(sOpenFile, _T("r"));
	if (fin == NULL)
		return;

	bDup = FALSE;

	if (_fgetts(sData, 1024, fin) == NULL) {
		fclose(fin);
		return;
	}
	cstr = sData;
	cstr.Trim();
	if (cstr.CompareNoCase(_T("[Magic Plot List]")) != 0) {
		AfxMessageBox(_T("다중 플롯 파일 목록이 아니거나 이전 버전에의해 작성된 목록입니다\n현재 버전과 호환되지 않으므로\n도면 추가 기능으로 파일을 추가해 주십시오"), MB_OK | MB_ICONINFORMATION);
		fclose(fin);
		return;
	}

	while (_fgetts(sData, 1024, fin)) {
		cstr = sData;
		cstr.Trim();

		// 파일명,경로,스타일
		String2Array(cstr, strArr, _T(","));
		sPath = strArr[0];
		if (IsDupListView(sPath, &lvwDwg))
			bDup = TRUE;
		else {
			i = lvwDwg.GetItemCount();
			i = lvwDwg.InsertItem(i, strArr[1]);
			lvwDwg.SetItemText(i, 1, strArr[2]);
			lvwDwg.SetItemText(i, 3, strArr[0]);
			lvwDwg.SetItemData(i, i);
		}
	}

	fclose(fin);

	if (bDup)
		AfxMessageBox(_T("이미 등록된 도면은 제외되었습니다"), MB_OK | MB_ICONINFORMATION);

	ResetPlotState();
}


int CALLBACK ListSortAscend(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	CListCtrl* pListCtrl = (CListCtrl*)lParamSort;

	//CString strItem1 = pListCtrl->GetItemText(lParam1, 0); //210729수정
	//CString strItem2 = pListCtrl->GetItemText(lParam2, 0); //210729수정
	
	CString strItem1 = pListCtrl->GetItemText(static_cast<int>(lParam1), 0);
	CString strItem2 = pListCtrl->GetItemText(static_cast<int>(lParam2), 0);

	return _tcsicmp(strItem1, strItem2);
}


int CALLBACK ListSortDescend(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	CListCtrl* pListCtrl = (CListCtrl*)lParamSort;

	//CString strItem1 = pListCtrl->GetItemText(lParam1, 0); //210729수정
	//CString strItem2 = pListCtrl->GetItemText(lParam2, 0); //210729수정
	CString strItem1 = pListCtrl->GetItemText(static_cast<int>(lParam1), 0);
	CString strItem2 = pListCtrl->GetItemText(static_cast<int>(lParam2), 0);

	return _tcsicmp(strItem2, strItem1);
}


// 목록 정렬
void CDlgMPL::OnBnClickedCbsorta()
{
	int iCnt;
	CStringArray sItem;
	CStringArray sTemp;
	int i;

	iCnt = lvwDwg.GetItemCount();
	if (iCnt < 1)
		return;

	for (i = 0; i < iCnt; i ++)
		lvwDwg.SetItemData(i, i);

	lvwDwg.SortItems(ListSortAscend, (LPARAM)&lvwDwg);
}


void CDlgMPL::OnBnClickedCbsortd()
{
	int iCnt;
	CStringArray sItem;
	CStringArray sTemp;
	int i;

	iCnt = lvwDwg.GetItemCount();
	if (iCnt < 1)
		return;

	for (i = 0; i < iCnt; i ++)
		lvwDwg.SetItemData(i, i);

	lvwDwg.SortItems(ListSortDescend, (LPARAM)&lvwDwg);
}


void CDlgMPL::OnBnClickedCbwindow()
{
	CDlgMPLSub dlgSub(this);
	if (dlgSub.DoModal() == IDOK) {
	}
}


void CDlgMPL::OnBnClickedChkpreviw()
{
	if (chkPLT.GetCheck())
		chkPLT.SetCheck(chkPreviw.GetCheck() ? FALSE: TRUE);
	if (chkPreviw.GetCheck()) {
		cbOK.SetWindowText(_T("미리보기"));
		chkSelForm.SetWindowText(_T("도면에서 선택한 Form만 미리보기"));
	}
	else {
		cbOK.SetWindowText(_T("출 력"));
		chkSelForm.SetWindowText(_T("도면에서 선택한 Form만 출력"));
	}
	cbOK.SetFocus();
}

void CDlgMPL::OnItemchangedLvwdwg(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	POSITION pos;
	int loc;

	pos = lvwDwg.GetFirstSelectedItemPosition();
	if (!pos)
		return;
	loc = lvwDwg.GetNextSelectedItem(pos);

	//tbPath.SetWindowTextW(lvwDwg.GetItemText(loc, 2));

	//ThumbView.SetDwgFile(lvwDwg.GetItemText(loc, 2) + lvwDwg.GetItemText(loc, 0));

	*pResult = 0;
}


void CDlgMPL::OnClickLvwdwg(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	NM_LISTVIEW* pNMView = (NM_LISTVIEW*)pNMHDR;
	int index = pNMView->iItem;

	tbPath.SetWindowTextW(lvwDwg.GetItemText(index, 3));
	ThumbView.SetDwgFile(lvwDwg.GetItemText(index, 3));
	tbState.SetWindowTextW(lvwDwg.GetItemText(index, 4));

	*pResult = 0;
}


void CDlgMPL::OnDblclkLvwdwg(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	ChangeStyle();

	*pResult = 0;
}


void CDlgMPL::ChangeStyle()
{
	POSITION pos;
	int loc;

	if (lvwDwg.GetItemCount() < 1)
		return;

	pos = lvwDwg.GetFirstSelectedItemPosition();
	if (!pos)
		return;
	loc = lvwDwg.GetNextSelectedItem(pos);

	CDlgMPLStyle dlgStyle(this);
	dlgStyle.m_textDwg = lvwDwg.GetItemText(loc, 0);
	dlgStyle.m_textCurrent = lvwDwg.GetItemText(loc, 1);
	if (dlgStyle.DoModal() == IDOK)
		lvwDwg.SetItemText(loc, 1, dlgStyle.m_selStyle);
}


void ResetComboBox(CComboBox *combo)
{
	TCHAR *sPtr;
	int num, i;

	num = combo->GetCount();
	for (i = 0; i < num; i ++) {
		sPtr = (TCHAR *)combo->GetItemDataPtr(i);
		if (sPtr)
			free(sPtr);
	}

	combo->ResetContent();
}


void CDlgMPL::RefreshMediaNames()
{
	GcArray<const TCHAR*> MediaList;
	CStringArray sPaper;
	int iCnt;
	int i;
	int index;
	VARIANT var;

	m_iLayout.RefreshPlotDeviceInfo();
	var = m_iLayout.GetCanonicalMediaNames();
	Variant2Array(&var, sPaper);

	ResetComboBox(&cboPaper);

	//iCnt = sPaper.GetCount(); //210729수정
	iCnt = static_cast<int>(sPaper.GetCount());
	for (i = 0; i < iCnt; i ++) {
		index = cboPaper.AddString(sPaper[i]);
		cboPaper.SetItemDataPtr(i, _tcsdup(sPaper[i]));
	}
}


void CDlgMPL::RefreshDevices()
{
	VARIANT var;
	CStringArray sPlotter;
	int iCnt;
	int i;

	var = m_iLayout.GetPlotDeviceNames();
	Variant2Array(&var, sPlotter);

	cboPlotter.ResetContent();
	//iCnt = sPlotter.GetCount();
	iCnt = static_cast<int>(sPlotter.GetCount());//210729수정
	for (i = 0; i < iCnt; i ++)
		cboPlotter.AddString(sPlotter[i]);
}


void CDlgMPL::RefreshPlotStyle()
{
	VARIANT var;
	CStringArray sStyle;
	int iCnt;
	int i;

	var = m_iLayout.GetPlotStyleTableNames();
	Variant2Array(&var, sStyle);

	cboStyle.ResetContent();
	//iCnt = sStyle.GetCount(); //210729수정
	iCnt = static_cast<int>(sStyle.GetCount());
	for (i = 0; i < iCnt; i ++)
		cboStyle.AddString(sStyle[i]);
}

// 플로터 변경에 따른 용지종류 변경
void CDlgMPL::OnCbnSelchangeCboplotter()
{
	CString sPlotterName;

	ResetComboBox(&cboPaper);

	GetComboText(&cboPlotter, sPlotterName);
	if (sPlotterName.CompareNoCase(_T("없음")) == 0 || sPlotterName.CompareNoCase(_T("none")) == 0) {
		cboPaper.AddString(_T("없음"));
		cboPaper.SetCurSel(0);
		return;
	}

	// 지정한 플로터를 현재 플로터로
	m_iLayout.put_ConfigName(sPlotterName);
	m_iLayout.RefreshPlotDeviceInfo();

	CStringArray sPaper;
	CString sName;
	int iCnt;
	int index;
	int i;
	VARIANT var;

	// 모든 용지 종류 얻어서
	var = m_iLayout.GetCanonicalMediaNames();
	Variant2Array(&var, sPaper);

	// 용지를 순환하면서 각 요소의 이름을 다시 받는다
	// 플로터 용지가 Userxxxx 로 나오는것 방지
	// put_CanonicalMediaName에서는 Userxxxx로 입력해야 하므로 값을 보관
	// LocaleMediaName을 사용하면 Invalid Input Error 발생
	//iCnt = sPaper.GetCount(); //210729수정
	iCnt = static_cast<int>(sPaper.GetCount());
	for (i = 0; i < iCnt; i ++) {
		CString cstr = sPaper[i];
		sName = m_iLayout.GetLocaleMediaName(sPaper[i]);
		index = cboPaper.AddString(sName);
		cboPaper.SetItemDataPtr(index, _tcsdup(sPaper[i]));
	}
	cboPaper.SetCurSel(0);
}


void CDlgMPL::OnCbnSelchangeCbostyle()
{
	CString styNam;
	POSITION pos;
	int iCnt;
	int i;

	cbAdd.SetFocus();

	iCnt = lvwDwg.GetItemCount();
	if (iCnt < 1)
		return;

	GetComboText(&cboStyle, styNam);

	if (chkStyle.GetCheck()) {
		for (i = 0; i < iCnt; i ++)
			lvwDwg.SetItemText(i, 1, styNam);
	}
	else {
		pos = lvwDwg.GetFirstSelectedItemPosition();
		while (pos) {
			i = lvwDwg.GetNextSelectedItem(pos);
			lvwDwg.SetItemText(i, 1, styNam);
		}
	}

	lvwDwg.SetFocus();
}


void CDlgMPL::OnBnClickedCbform()
{
	CDlgMPLForm dlgForm(this);
	if (dlgForm.DoModal() == IDOK) {
	}
}


void CDlgMPL::OnBnClickedCbfind()
{
	BROWSEINFO browInfo;
	LPITEMIDLIST itemList;
	TCHAR dirPath[MAX_PATH];

	memset(&browInfo, 0, sizeof (BROWSEINFO));
	browInfo.hwndOwner = m_hWnd;
	browInfo.lpszTitle = _T("PLOT 폴더");
	browInfo.ulFlags = BIF_RETURNONLYFSDIRS | BIF_VALIDATE | BIF_STATUSTEXT;
	browInfo.lpfn = SetInputDirProc;
	browInfo.lParam = (LPARAM)(LPCSTR)dirPath;
	itemList = SHBrowseForFolder (&browInfo);
	if (!itemList)
		return;

	SHGetPathFromIDList(itemList, dirPath);
	_SHFree(itemList);

	tbPLT.SetWindowText(dirPath);
}


// 용지에 맞춤
void CDlgMPL::OnBnClickedChkfitscale()
{
	BOOL bTrue;

	bTrue = chkFitScale.GetCheck() ? FALSE: TRUE;

	if (chkAutoScaleA1.GetCheck())
		chkAutoScaleA1.SetCheck(bTrue);

	if (!chkFitScale.IsWindowEnabled())
		bTrue = FALSE;

	Label4.EnableWindow(bTrue);
	tbScale.EnableWindow(bTrue);
	chkReScale.EnableWindow(bTrue);
}


// 자동 맞춤(A1기준)
void CDlgMPL::OnBnClickedChkautoscalea1()
{
	BOOL bTrue;

	bTrue = chkAutoScaleA1.GetCheck() ? FALSE: TRUE;

	if (chkFitScale.GetCheck()) {
		chkFitScale.SetCheck(bTrue);
		bTrue = FALSE;
	}

	Label4.EnableWindow(bTrue);
	tbScale.EnableWindow(bTrue);
	//if (bTrue)
	//	tbScale.BackColor = &H80000005
	//Else
	//	tbScale.BackColor = &H8000000F
}


// 플롯 중심
void CDlgMPL::OnBnClickedChkplotcenter()
{
	BOOL bTrue;

	bTrue = chkPlotCenter.GetCheck() ? FALSE: TRUE;

	Label5.EnableWindow(bTrue);
	Label6.EnableWindow(bTrue);
	tbPlotX.EnableWindow(bTrue);
	tbPlotY.EnableWindow(bTrue);

	//if (bTrue) {
	//	tbPlotX.BackColor = &H80000005;
	//	tbPlotY.BackColor = &H80000005;
	//}
	//else {
	//	tbPlotX.BackColor = &H8000000F;
	//	tbPlotY.BackColor = &H8000000F;
	//}
}


void CDlgMPL::OnBnClickedCbscaleview()
{
	if (optForm.GetCheck()) {
		CDlgMPLScale dlgScale(this);
		if (dlgScale.DoModal() == IDOK) {
		}
	}
	else {
		CDlgMPLWScale dlgWScale(this);
		if (dlgWScale.DoModal() == IDOK) {
		}
	}
}


void CDlgMPL::OnBnClickedOptactive()
{
	if (optSpecLayout.GetCheck())
		optSpecLayout.SetWindowText(_T("Layout:"));
	else
		optSpecLayout.SetWindowText(_T("특정 Layout"));
	if (optSpecLayout.GetCheck()) {
		tbLayout.ShowWindow(SW_SHOW);
		tbLayout.SetFocus();
	}
	else
		tbLayout.ShowWindow(SW_HIDE);

	if (optActive.GetCheck()) {
		optLimit.SetWindowText(_T("Limits"));
		ControlEnable3();
	}
	else if (optModel.GetCheck()) {
		optLimit.SetWindowText(_T("Limits"));
		ControlEnable3();
	}
	else if (optOnlyLayout.GetCheck()) {
		optLimit.SetWindowText(_T("Layout"));
		if (optWindow.GetCheck()) {
			AfxMessageBox(_T("모든 Layout 출력인 경우 Window 플롯 영역 옵션을 사용할 수 없습니다\n다른 옵션을 선택해주십시오"), MB_OK | MB_ICONSTOP);
			CheckRadioButton(IDC_OPTFORM, IDC_OPTDRAWING, IDC_OPTFORM);
			optForm.SetCheck(TRUE);
			OnBnClickedOptform();
			return;
		}
		ControlEnable3();
	}
	else if (optModelLayout.GetCheck()) {
		optLimit.SetWindowText(_T("Limits 또는 Layout"));
		if (optWindow.GetCheck()) {
			AfxMessageBox(_T("Model + 모든 Layout 출력인 경우 Window 플롯 영역 옵션을 사용할 수 없습니다\n다른 옵션을 선택해주십시오"), MB_OK | MB_ICONSTOP);
			CheckRadioButton(IDC_OPTFORM, IDC_OPTDRAWING, IDC_OPTFORM);
			OnBnClickedOptform();
			return;
		}
		ControlEnable3();
	}
	else if (optSpecLayout.GetCheck()) {
		optLimit.SetWindowText(_T("Layout"));
		ControlEnable3();
	}
}


void CDlgMPL::OnBnClickedOptform()
{
	if (optForm.GetCheck()) {
		cbForm.ShowWindow(SW_SHOW);
		cbWindow.ShowWindow(SW_HIDE);
		cbScaleView.ShowWindow(SW_SHOW);
		chkReScale.EnableWindow(TRUE);
		MoveDlgItem(IDC_CBSCALEVIEW, viewOX, viewOY);
		ControlEnable(TRUE);
		ControlEnable2(TRUE);
		//cbScaleView.ControlTipText = "Form 축척 및 이름 보기";
		OnBnClickedChkautoscalea1();
	}
	else if (optWindow.GetCheck()) {
		if (optOnlyLayout.GetCheck() || optModelLayout.GetCheck()) {
			AfxMessageBox(_T("모든 Layout 출력인 경우 이 옵션을 사용할 수 없습니다\n다른 옵션을 선택해주십시오"), MB_OK | MB_ICONSTOP);
			optForm.SetCheck(TRUE);
			return;
		}
		cbForm.ShowWindow(SW_HIDE);
		cbWindow.ShowWindow(SW_SHOW);
		cbScaleView.ShowWindow(SW_SHOW);
		chkReScale.EnableWindow(TRUE);
		MoveDlgItem(IDC_CBSCALEVIEW, viewOX, viewOY + viewDY);
		ControlEnable(FALSE);
		ControlEnable2(TRUE);
		//cbScaleView.ControlTipText = "출력 영역 축척 보기"
	}
	else if (optExtend.GetCheck()) {
		if (chkAutoScaleA1.GetCheck())
			chkAutoScaleA1.SetCheck(FALSE);

		cbForm.ShowWindow(SW_HIDE);
		cbWindow.ShowWindow(SW_HIDE);
		cbScaleView.ShowWindow(SW_HIDE);
		chkReScale.EnableWindow(TRUE);

		ControlEnable(FALSE);
		ControlEnable2(TRUE);
	}
	else if (optLimit.GetCheck()) {
		cbForm.ShowWindow(SW_HIDE);
		cbWindow.ShowWindow(SW_HIDE);
		cbScaleView.ShowWindow(SW_HIDE);
		chkReScale.EnableWindow(TRUE);

		ControlEnable(FALSE);
		ControlEnable2(TRUE);
		ControlEnable3();
	}
	else if (optDrawing.GetCheck()) {
		cbForm.ShowWindow(SW_HIDE);
		cbWindow.ShowWindow(SW_HIDE);
		cbScaleView.ShowWindow(SW_HIDE);
		chkReScale.EnableWindow(FALSE);
		chkReScale.SetCheck(FALSE);

		ControlEnable(FALSE);
		ControlEnable2(FALSE);
	}
}


void CDlgMPL::ControlEnable(BOOL bTrue)
{
	chkAutoScaleA1.ShowWindow(bTrue ? SW_SHOW: SW_HIDE);
	chkAutoScaleA1.SetCheck(bTrue);
	chkSelForm.EnableWindow(bTrue);
	if (!bTrue) {
		if (chkSelForm.GetCheck())
			chkSelForm.SetCheck(FALSE);
	}
}


void CDlgMPL::ControlEnable2(BOOL bTrue)
{
	chkFitScale.EnableWindow(bTrue);
	OnBnClickedChkfitscale();

	if (!optDrawing.GetCheck()) {
		chkPlotCenter.SetCheck(bTrue);
		chkPlotCenter.EnableWindow(bTrue);
	}
	else {
		chkPlotCenter.EnableWindow(FALSE);
		Label5.EnableWindow(FALSE);
		Label6.EnableWindow(FALSE);
		tbPlotX.EnableWindow(FALSE);
		tbPlotY.EnableWindow(FALSE);
		//tbPlotX.BackColor = &H8000000F
		//tbPlotY.BackColor = &H8000000F
		//tbScale.BackColor = &H8000000F
	}
}


void CDlgMPL::ControlEnable3()
{
	// 배치에서 Layout은 용지맞춤X, 플롯중심X
	if (optOnlyLayout.GetCheck() || optSpecLayout.GetCheck()) {
		if (optLimit.GetCheck()) {
			chkFitScale.SetCheck(FALSE);
			chkFitScale.EnableWindow(FALSE);
			OnBnClickedChkfitscale();
			chkPlotCenter.SetCheck(FALSE);
			chkPlotCenter.EnableWindow(FALSE);
		}
	}
}


void CDlgMPL::OnBnClickedChkplt()
{
	BOOL bTrue;

	bTrue = chkPLT.GetCheck();
	cbFind.ShowWindow(bTrue ? SW_SHOW: SW_HIDE);
	tbPLT.ShowWindow(bTrue ? SW_SHOW: SW_HIDE);

	if (chkPreviw.GetCheck())
		//chkPreviw.SetCheck(!bTrue); //210729수정
		chkPreviw.SetCheck(~bTrue);
	if (bTrue)
		tbPLT.SetFocus();
}


void CDlgMPL::OnBnClickedChkrescale()
{
	BOOL bTrue;

	bTrue = chkReScale.GetCheck();
	Label17.ShowWindow(bTrue ? SW_SHOW: SW_HIDE);
	Label18.ShowWindow(bTrue ? SW_SHOW: SW_HIDE);
	tbReScale.ShowWindow(bTrue ? SW_SHOW: SW_HIDE);
	if (bTrue)
		tbReScale.SetFocus();
}


//Private Sub sbCount_SpinDown()
//	If tbPlotCnt <= 1 Then tbPlotCnt = 1: Exit Sub
//	tbPlotCnt = tbPlotCnt - 1
//End Sub
//
//Private Sub sbCount_SpinUp()
//	tbPlotCnt = Val(tbPlotCnt) + 1
//End Sub
//
//Private Sub sbDelay_SpinDown()
//	If tbDelay <= 0 Then tbDelay = 0: Exit Sub
//	tbDelay = tbDelay - 1
//End Sub
//
//Private Sub sbDelay_SpinUp()
//	If tbDelay >= 10 Then Exit Sub
//	tbDelay = Val(tbDelay) + 1
//End Sub


// 열린 도면인지 검사
BOOL CDlgMPL::FindOpenDwg(LPCTSTR sName, CGcadDocument* pDoc)
{
	IDispatch *pDisp;
	pDisp = gcedGetGcadWinApp()->GetIDispatch(TRUE);
	CGcadApplication IApp;
	IApp.AttachDispatch(pDisp);

	pDisp = IApp.get_Documents();
	CGcadDocuments IDocs;
	IDocs.AttachDispatch(pDisp);

	BOOL found = FALSE;
	long docNum = IDocs.get_Count();
	for (long i = 0; i < docNum; i++) {
		pDisp = IDocs.Item(COleVariant(i));
		pDoc->AttachDispatch(pDisp);
		CString pFullName = pDoc->get_FullName();
		if (pFullName.CompareNoCase(sName) == 0) {
			return TRUE;
		}
	}

	return FALSE;
}


double CDlgMPL::GetPlotScaleByA1(double dVal, BOOL bVert)
{
	CString papNam;
	double rVal = 1.0;

	GetComboText(&cboPaper, papNam);
	papNam.MakeUpper();

	// 높이로 비교
	if (!bVert) { // 수평
		if (papNam.Find(_T("A0")) >= 0)
			rVal = dVal / 841;
		else if (papNam.Find(_T("A1")) >= 0)
			rVal = dVal / 594;
		else if (papNam.Find(_T("A2")) >= 0)
			rVal = dVal / 420;
		else if (papNam.Find(_T("A3")) >= 0)
			rVal = dVal / 297;
		else if (papNam.Find(_T("A4")) >= 0)
			rVal = dVal / 210;
	}
	else {
		if (papNam.Find(_T("A0")) >= 0)
			rVal = dVal / 1189;
		else if (papNam.Find(_T("A1")) >= 0)
			rVal = dVal / 841;
		else if (papNam.Find(_T("A2")) >= 0)
			rVal = dVal / 594;
		else if (papNam.Find(_T("A3")) >= 0)
			rVal = dVal / 420;
		else if (papNam.Find(_T("A4")) >= 0)
			rVal = dVal / 297;
	}

	return DoubleRound(rVal, 2);
}


BOOL CDlgMPL::IsAPaper()
{
	CString papNam;

	GetComboText(&cboPaper, papNam);
	papNam.MakeUpper();

	if (papNam.Find(_T("A0")) >= 0 ||
		papNam.Find(_T("A1")) >= 0 ||
		papNam.Find(_T("A2")) >= 0 ||
		papNam.Find(_T("A3")) >= 0 ||
		papNam.Find(_T("A4")) >= 0)
		return TRUE;
	else
		return FALSE;
}


void CDlgMPL::SetDelay(long lngCount) // 초
{
	Sleep(lngCount * 1000);
	//long lngStart;
	//lngStart = Timer
	//Do While Timer < lngStart + lngCount
	//	DoEvents
	//Loop
}


extern CDlgMPL* m_dlgMPL;


void CDlgMPL::OnBnClickedCancel()
{
	SaveIni();

	CGcUiDialog::OnCancel();

	delete this;

	m_dlgMPL = NULL;
}


void CDlgMPL::OnClickedIdhelp()
{
	CString dllDir;
	::GetModuleFileName((HINSTANCE)&__ImageBase, dllDir.GetBuffer(_MAX_PATH), _MAX_PATH);
	dllDir.ReleaseBuffer();
	int loc = dllDir.ReverseFind('\\');
	if (loc >= 0)
		dllDir = dllDir.Left(loc);
	::ShellExecuteW(::GetDesktopWindow(), _T("open"), _T("Magic.chm"), 0, dllDir, SW_SHOWDEFAULT);
}


void CDlgMPL::LoadIni()
{
	CString cstr;
	int opt;

	cstr = m_regEdit.GetString(_T("Plotter"), _T(""));
	SelectComboText(&cboPlotter, cstr);
	OnCbnSelchangeCboplotter();

	cstr = m_regEdit.GetString(_T("Paper"), _T(""));
	SelectComboText(&cboPaper, cstr);
	cstr = m_regEdit.GetString(_T("Style"), _T(""));
	SelectComboText(&cboStyle, cstr);

	opt = m_regEdit.GetInteger(_T("AreaType"), 0);
	CheckRadioButton(IDC_OPTFORM, IDC_OPTDRAWING, opt + IDC_OPTFORM);
	OnBnClickedOptform();

	opt = m_regEdit.GetInteger(_T("TargetType"), 0);
	CheckRadioButton(IDC_OPTACTIVE, IDC_OPTSPECLAYOUT, opt + IDC_OPTACTIVE);
	tbLayout.ShowWindow(((opt + IDC_OPTACTIVE) == IDC_OPTSPECLAYOUT) ? SW_SHOW: SW_HIDE);

	tbLayout.SetWindowTextW(m_regEdit.GetString(_T("LayoutName"), _T("")));
	chkFitScale.SetCheck(m_regEdit.GetBoolean(_T("FitScale"), FALSE));
	chkAutoScaleA1.SetCheck(m_regEdit.GetBoolean(_T("AutoScale"), TRUE));
	Label4.EnableWindow(chkAutoScaleA1.GetCheck() ? FALSE: TRUE);
	tbScale.EnableWindow(chkAutoScaleA1.GetCheck() ? FALSE: TRUE);
	tbScale.SetWindowTextW(m_regEdit.GetString(_T("Scale"), _T("1")));
	chkPlotCenter.SetCheck(m_regEdit.GetBoolean(_T("PlotCenter"), TRUE));
	tbPlotX.SetWindowTextW(m_regEdit.GetString(_T("PlotX"), _T("0")));
	tbPlotY.SetWindowTextW(m_regEdit.GetString(_T("PlotY"), _T("0")));

	opt = m_regEdit.GetInteger(_T("SortDir"), 0);
	CheckRadioButton(IDC_OPTSORTLR, IDC_OPTSORTIZ, opt + IDC_OPTSORTLR);
	tbTol.SetWindowTextW(m_regEdit.GetString(_T("SortTol"), _T("10.0")));
	chkReverse.SetCheck(m_regEdit.GetBoolean(_T("SortReverse"), FALSE));

	opt = m_regEdit.GetInteger(_T("PlotDir"), 0);
	CheckRadioButton(IDC_OPTAUTO, IDC_OPTVER, opt + IDC_OPTAUTO);

	tbDelay.SetWindowTextW(m_regEdit.GetString(_T("Delay"), _T("0")));
	chkPLT.SetCheck(m_regEdit.GetBoolean(_T("PLT"), FALSE));
	tbReScale.SetWindowTextW(m_regEdit.GetString(_T("ReScale"), _T("100")));

	opt = m_regEdit.GetInteger(_T("PaperDir"), 0);
	CheckRadioButton(IDC_OPTAUTO, IDC_OPTVER, opt + IDC_OPTAUTO);
}


int CDlgMPL::GetCheckedRadioButton(int idFirst, int idLast)
{
	int i;

	for (i = idFirst; i <= idLast; i ++) {
		if (IsDlgButtonChecked(i))
			return i;
	}

	return idFirst;
}


void CDlgMPL::SaveIni()
{
	CString cstr;

	m_regEdit.SetInteger(_T("AreaType"),
		GetCheckedRadioButton(IDC_OPTFORM, IDC_OPTDRAWING) - IDC_OPTFORM);
	m_regEdit.SetInteger(_T("TargetType"),
		GetCheckedRadioButton(IDC_OPTACTIVE, IDC_OPTSPECLAYOUT) - IDC_OPTACTIVE);
	GetComboText(&cboPlotter, cstr); m_regEdit.SetString(_T("Plotter"), cstr);
	GetComboText(&cboPaper, cstr); m_regEdit.SetString(_T("Paper"), cstr);
	GetComboText(&cboStyle, cstr); m_regEdit.SetString(_T("Style"), cstr);
	tbLayout.GetWindowTextW(cstr); m_regEdit.SetString(_T("LayoutName"), cstr);
	m_regEdit.SetBoolean(_T("FitScale"), chkFitScale.GetCheck());
	m_regEdit.SetBoolean(_T("AutoScale"), chkAutoScaleA1.GetCheck());
	tbScale.GetWindowTextW(cstr); m_regEdit.SetString(_T("Scale"), cstr);
	m_regEdit.SetBoolean(_T("PlotCenter"), chkPlotCenter.GetCheck());
	tbPlotX.GetWindowTextW(cstr); m_regEdit.SetString(_T("PlotX"), cstr);
	tbPlotY.GetWindowTextW(cstr); m_regEdit.SetString(_T("PlotY"), cstr);

	m_regEdit.SetInteger(_T("SortDir"),
		GetCheckedRadioButton(IDC_OPTSORTLR, IDC_OPTSORTIZ) - IDC_OPTSORTLR);
	tbTol.GetWindowTextW(cstr); m_regEdit.SetString(_T("SortTol"), cstr);
	m_regEdit.SetBoolean(_T("SortReverse"), chkReverse.GetCheck());

	m_regEdit.SetInteger(_T("PlotDir"),
		GetCheckedRadioButton(IDC_OPTAUTO, IDC_OPTVER) - IDC_OPTAUTO);
	tbDelay.GetWindowTextW(cstr); m_regEdit.SetString(_T("Delay"), cstr);
	m_regEdit.SetBoolean(_T("PLT"), chkPLT.GetCheck());
	tbReScale.GetWindowTextW(cstr); m_regEdit.SetString(_T("ReScale"), cstr);
	m_regEdit.SetInteger(_T("PaperDir"),
		GetCheckedRadioButton(IDC_OPTAUTO, IDC_OPTVER) - IDC_OPTAUTO);
}


BOOL CDlgMPL::OnInitDialog()
{
	CGcUiDialog::OnInitDialog();

	m_regEdit.SetKey(HKEY_CURRENT_USER, _T("SOFTWARE\\Magic\\MagicUtil\\MPL"));

	GetItemPos(IDC_CBSCALEVIEW, viewOX, viewOY);
	int x1, y1;
	int x2, y2;
	GetItemPos(IDC_OPTFORM, x1, y1);
	GetItemPos(IDC_OPTWINDOW, x2, y2);
	viewDY = y2 - y1;

	SetDlgItemInt(IDC_TBPLOTCNT, 1);
	sbCount.SetRange(1, 1000);
	sbDelay.SetRange(0, 10);
	sbDelay.SetBuddy(&tbDelay);

	IDispatch *pDisp;
	CGcadApplication IApp;
	CGcadDocument IDoc;
	pDisp = gcedGetGcadWinApp()->GetIDispatch(TRUE);
	IApp.AttachDispatch(pDisp);
	pDisp = IApp.get_ActiveDocument();
	IDoc.AttachDispatch(pDisp);
	pDisp = IDoc.get_ActiveLayout(); 
	m_iLayout.AttachDispatch(pDisp);

	RefreshDevices();
	RefreshPlotStyle();

	// 환경설정 열기
	LoadIni();

	lvwDwg.ShowScrollBar(SB_VERT);

	int sngWidth;
	CRect crec;
	lvwDwg.GetClientRect(crec);
	sngWidth = crec.Width();

	lvwDwg.ModifyStyle (0, LVS_REPORT | LVS_SHOWSELALWAYS);
	lvwDwg.SetExtendedStyle (LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	lvwDwg.InsertColumn (0, _T("도면"), LVCFMT_LEFT, (int)(sngWidth * 5.8 / 10.0), 0);
	lvwDwg.InsertColumn (1, _T("스타일"), LVCFMT_LEFT, (int)(sngWidth * 3.0 / 10.0), 0);
	lvwDwg.InsertColumn (3, _T("상태"), LVCFMT_CENTER, (int)(sngWidth * 1.2 / 10.0), 0);
	lvwDwg.InsertColumn (3, _T("파일경로"), LVCFMT_LEFT, 0, 0);
	lvwDwg.InsertColumn (4, _T("플롯상태"), LVCFMT_LEFT, 0, 0);

	cbScaleView.SubclassDlgItem(IDC_CBSCALEVIEW, this);
	cbScaleView.SetImage(IDB_SEARCH);

	ThumbView.SubclassDlgItem(IDC_THUMBVIEW, this);
	ThumbView.SetBkgColor(0);

	OnBnClickedChkplotcenter();
	OnBnClickedChkplt();
	OnBnClickedChkrescale();

	ResetPlotState();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL CDlgMPL::DestroyWindow()
{
	return CGcUiDialog::DestroyWindow();
}


void CDlgMPL::OnCbnSelchangeCbopaper()
{
}

