// DlgMPL.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MagicUtil.h"
#include "DlgMPL.h"
#include "afxdialogex.h"
#include "DlgMPLStyle.h"
#include "DlgMPLForm.h"
#include "DlgMPLScale.h"
#include "DlgMPLWScale.h"
#include "DlgMPLSub.h"
#include "DlgMPLExit.h"

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
	DDX_Control(pDX, IDCANCEL, cbCancle);
	DDX_Control(pDX, IDHELP, cbHelp);
	DDX_Control(pDX, IDC_LABEL5, Label5);
	DDX_Control(pDX, IDC_LABEL6, Label6);
	DDX_Control(pDX, IDC_LABEL17, Label17);
	DDX_Control(pDX, IDC_LABEL18, Label18);
	DDX_Control(pDX, IDC_LABEL4, Label4);
	DDX_Control(pDX, IDC_TBSTATE, tbState);
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


void CDlgMPL::PlotLayout(BOOL previewPlot, CGcadLayout* pLayout)
{
}


void CDlgMPL::MultiplePlot(BOOL previewPlot)
{
	CString cstr;
	int i;

	BOOL bOpen; // drawing is opened already
	int iInsUnit;

	CStringArray sLog;
	CGcadDocument iPlotFile;


	long iLayCnt;
	long iNext; // 레이아웃 순환용
	double dReScale;
	double dPaperH;
	double dYHeight;
	double dXWidth;
	double dMin[2];
	double dMax[2];
	BOOL bHorPaper;
	double dX;
	double dY;

	if (lvwDwg.GetItemCount() < 1) {
		AfxMessageBox(_T("목록에 출력할 도면이 없습니다"), MB_OK | MB_ICONINFORMATION);
		return;
	}

	SetVariable(_T("cmdecho"), 1);

	CString plotterName;
	GetComboText(&cboPlotter, plotterName);
	BOOL filePlot = chkPLT.GetCheck();

	if (!previewPlot) {
		cstr = plotterName;
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
	}

	if (plotterName.CompareNoCase(_T("없음")) == 0 || plotterName.CompareNoCase(_T("none")) == 0) {
		if (!optDrawing.GetCheck()) {
			AfxMessageBox(_T("출력할 플로터를 선택하여 주십시오"), MB_OK | MB_ICONINFORMATION);
			return;
		}
	}

	CString paperName;
	GetComboText(&cboPaper, paperName);
	if (paperName.CompareNoCase(_T("없음")) == 0 || paperName.CompareNoCase(_T("none")) == 0) {
		if (!optDrawing.GetCheck()) {
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


	CString formList;
	if (optForm.GetCheck()) {
		formList = m_regEdit.GetString(_T("MPL"), _T("AddFormList"), _T(""));
		formList.Trim();
		if (formList.IsEmpty()) {
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

	BOOL bActive = optActive.GetCheck();
	BOOL bModel = optModel.GetCheck();
	BOOL bOnlyLayout = optOnlyLayout.GetCheck();
	BOOL bModel_Lay = optModelLayout.GetCheck();
	BOOL bSpecLayout = optSpecLayout.GetCheck();

	// re-scale for plotting scale
	if (chkReScale.GetCheck()) {
		tbReScale.GetWindowTextW(cstr);
		if (_ttof(cstr) == 0)
			dReScale = 1.0;
		else
			dReScale = 100.0 / _ttof(cstr);
	}
	else
		dReScale = 1.0;

	// do not show message
	int iExpert;
	GetVariable(_T("EXPERT"), iExpert);
	if (iExpert == 0)
		SetVariable(_T("EXPERT"), 1);

	int iDwgCheck;
	GetVariable(_T("DWGCHECK"), iDwgCheck);
	if (iDwgCheck == 1)
		SetVariable(_T("DWGCHECK"), 0);

	// get active document's layout
	IDispatch *pDisp = gcedGetGcadWinApp()->GetIDispatch(TRUE);
	CGcadApplication iApp;
	iApp.AttachDispatch(pDisp);
	pDisp = iApp.get_ActiveDocument();
	CGcadDocument iDoc;
	iDoc.AttachDispatch(pDisp);
	pDisp = iDoc.get_ActiveLayout(); 
	CGcadLayout iLayout;
	iLayout.AttachDispatch(pDisp);

	BeginEditorCommand();

	// Show CancelDialog
	CDlgMPLExit dlgExit(GetParent());
	dlgExit.Create(CDlgMPLExit::IDD);
	dlgExit.ShowWindow(SW_SHOWNORMAL);
	dlgExit.UpdateWindow();

	CString sErr;
	// 도면에 설정된 저장대로가 아니면
	if (!optDrawing.GetCheck()) {
		// get paper name from plotter device
		iLayout.put_ConfigName(plotterName);
		iLayout.RefreshPlotDeviceInfo();
		VARIANT var = iLayout.GetCanonicalMediaNames();
		CStringArray paperList;
		Variant2Array(&var, paperList);

		int iCnt = paperList.GetCount();
		for (i = 0; i < iCnt; i ++) {
			CString locName = iLayout.GetLocaleMediaName(paperList[i]);
			if (paperName.CompareNoCase(locName) == 0)
				break;
		}
		if (i == iCnt) {
			AfxMessageBox(_T("플로터에서 선택한 용지를 찾을 수 없습니다."), MB_OK | MB_ICONWARNING);
			return;
		}

		// get paper size
		iLayout.put_CanonicalMediaName(paperName);
		iLayout.GetPaperSize(&dX, &dY);
		if (dX >= dY)
			bHorPaper = TRUE;
		else
			bHorPaper = FALSE;
	}

	BOOL bPlotWindow;
	if (optForm.GetCheck())
		bPlotWindow = TRUE;
	else
		bPlotWindow = FALSE;

	double dDiff = 1;
	BOOL bPlotErr = FALSE;

	BOOL bMPLCancel = FALSE;
	BOOL bMPLExit = FALSE;

	CString sDwg;
	CString pLayName;
	BOOL bVertical;
	double dOrigin[2];
	double dCorrect;
	long iXrefCnt;
	GcGePoint3d vMin;
	GcGePoint3d vMax;
	double dPlotMin[2];
	double dPlotMax[2];
	GcGePoint3d dZoomMin;
	GcGePoint3d dZoomMax;
	int k;
	CString sPLT;
	double dSelVer;
	double dSelHor;
	BOOL bWinUser;
	GcGePoint3d vSpnt;
	GcGePoint3d vEpnt;
	GcGePoint3d dZero;
	double dTwAng;
	BOOL bUCS;
	BOOL bDview;
	CString sFileName;
	int iFileNum;
	BOOL bPloted;
	CString sPlotter;

	int iCopy;
	int iCopyNum;

	double dScale;
	BOOL bSavePlot; // 도면에 저장된 설정대로 에러용
	BOOL bRotate; // 폼이 가로인가?
	BOOL bRealVert; // 폼자체가 원래 세로
	const TCHAR* sFormName; // 셀셑의 현재 선택한 폼 이름
	int iIniPos; // ini의 폼 이름 위치
	//long lngReply;

	CGcadLayouts oLayouts;
	GcDbExtents extents;
	CGcadPlot IPlot;
	int iCnt;
	int i;

	// 도면의 인쇄 매수
	if (chkCopy.GetCheck())
		iCopyNum = GetDlgItemInt(IDC_TBPLOTCNT);
	else
		iCopyNum = 1;
	if (chkPLT.GetCheck())
		iCopyNum = 1;

	int iPlotBack;
	// 프록시 경고 끄기
	SetVariable(_T("proxynotice"), 0);
	// AutoCAD 2005 이상 백그라운드 플롯을 꺼놓는다.
	// 켜있으면 PlotToDevice에서 두번째 도면부터 False 반환에러 발생
	sErr = _T("Disable BackGroundPlot 에러");
	GetVariable(_T("BACKGROUNDPLOT"), iPlotBack);
	SetVariable(_T("BACKGROUNDPLOT"), 0);

	for (iCopy = 0; iCopy < iCopyNum; iCopy ++) {
		// 미리보기면 한번 실행 후 종료
		if (previewPlot)
			iCopy = iCopyNum;

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

			bSavePlot = TRUE;
			iFileNum = 0; // 파일로 플롯 카운트

			// 출력 취소 폼에서 취소 반환되면 이후 모든 도면 취소
			if (bMPLCancel || bMPLExit)
				break;

			// 초기화
			bOpen = FALSE;
			bUCS = FALSE;
			bDview = FALSE;
			bPloted = FALSE;

			// 도면명
			sFileName = lvwDwg.GetItemText(i, 0);
			sDwg = lvwDwg.GetItemText(i, 3);
			int loc = sFileName.ReverseFind('.');
			if (loc >= 0)
				sFileName = sFileName.Left(loc);

			// 도면이 열려있는 경우면 다시 열지 말고 열린 도면 사용
			// 리스트의 도면을 열고
			sErr = _T("리스트 도면 열기 에러");
			if (!FindOpenDwg(sDwg, oPlotFile)) {
				OpenDwgFile(sDwg);
				if (!FindOpenDwg(sDwg, oPlotFile)) {
					bPlotErr = TRUE;
					cstr.Format(_T("%s : 도면을 열 수 없습니다"), lvwDwg.GetItemText(i, 0));
					LogErr(cstr, FALSE);
					cstr.Format(_T("%s 도면을 열 수 없습니다\n계속 진행하시겠습니까?"), lvwDwg.GetItemText(i, 0));
					if (AfxMessageBox(cstr, MB_YESNO | MB_ICONQUESTION) == IDYES)
						goto NextDwg;
					else
						goto ErrorHandler;
				}
				bOpen = FALSE;
			}
			else {
				oPlotFile.Activate();
				bOpen = TRUE;
			}

			//iLayCnt = oPlotFile.Layouts.Count;
			dTwAng = GetTWAng();
			if (dTwAng != 0)
				dTwAng = - dTwAng;
			if (!IsWCS())
				bUCS = TRUE;
			else {
				if (dTwAng != 0) {
					bDview = TRUE;
					SetViewUcs(TRUE);
					bUCS = TRUE;
				}
			}

			pDisp = oPlotFile.get_Layouts();
			oLayouts.AttachDispatch(pDisp);
			iLayCnt = oLayouts.get_Count();

			// 레이아웃 순환됨
			//Iterate through all the items in the dictionary
			for (iNext = 0; iNext < iLayCnt; iNext ++) {
				//SafeArrayGetElement(mLayArr.parray, &iNext, &bstrName);
				//With oPlotFile
				// units 바뀐다고 해서 추가함.. 이상함
				GetVariable(_T("INSUNITS"), iInsUnit);

				// 플롯할 도면의 레이아웃으로 재설정
				if (bActive) {
					pDisp = oPlotFile.get_ActiveLayout(); 
					oLayout.AttachDispatch(pDisp);
					pLayName = oLayout.get_Name();
				}
				else {
					pDisp = oLayouts.Item(_variant_t(iNext));
					oLayout.AttachDispatch(pDisp);
					pLayName = oLayout.get_Name();

					// 옵션에따라 레이아웃 검사
					if (bModel) {
						// get the model layout
						if (pLayName.CompareNoCase(_T("model")) != 0)
							goto NextLayout;
					}
					else if (bOnlyLayout) {
						if (pLayName.CompareNoCase(_T("model")) == 0)
							goto NextLayout;
					}
					else if (bModel_Lay) {
						// 그냥 진행
					}
					else if (bSpecLayout) {
						GetDlgItemText(IDC_TBLAYOUT, cstr);
						pDisp = oLayouts.Item(_variant_t(cstr));
						oLayout.AttachDispatch(pDisp);
						pLayName = oLayout.get_Name();
					}
					oPlotFile.put_ActiveLayout(oLayout);
				}

				// 플롯 에러 레포팅 끈다.
				sErr = _T("플롯 레포팅 끄기 에러");
				pDisp = oPlotFile.get_Plot();
				IPlot.AttachDispatch(pDisp);
				IPlot.put_QuietErrorMode(FALSE);

				// 자동 및 수동 축척 결정
				// 폼은 아래서 따로 계산
				sErr = _T("자동 및 수동 축척 결정 에러");
				if (tbScale.IsWindowEnabled()) {
					GetDlgItemText(IDC_TBSCALE, cstr);
					dScale = _ttof(cstr);;
				}

				// 각종 설정
				if (optDrawing.GetCheck()) {
					sPlotter = oLayout.get_ConfigName();
					if (sPlotter.CompareNoCase(_T("없음")) == 0 || sPlotter.CompareNoCase(_T("none")) == 0)
						bSavePlot = FALSE;
					else
						bSavePlot = IsExistCombo(sPlotter, &cboPlotter);

					if (!bSavePlot) {
						if (bActive || bModel || bSpecLayout) {
							bPlotErr = TRUE;
							LogErr(oPlotFile.get_Name() + _T(" : 도면에 저장된 출력 설정이 없습니다."), FALSE);
							goto NextDwg;
						}
						else {
							if (iNext == (iLayCnt - 1)) {
								if (!bPloted) {
									bPlotErr = TRUE;
									LogErr(oPlotFile.get_Name() + _T(" : 도면에 저장된 출력 설정이 없습니다."), FALSE);
									goto NextDwg;
								}
							}
							goto NextLayout;
						}
					}
				}
				else {
					//With oLayout
					sErr = _T("플로터, 용지, 스타일 가져오기 에러\n스타일을 STB가 아닌 CTB 파일로 선택해 주십시오");

					// change the current layout plotter
					GetComboText(&cboPlotter, cstr);
					oLayout.put_ConfigName(cstr); // 플로터
					oLayout.put_CanonicalMediaName(sName); // 용지
					oLayout.put_PlotWithPlotStyles(TRUE); // 플롯 스타일 사용여부
					oLayout.put_PlotWithLineweights(TRUE);
					cstr = lvwDwg.GetItemText(i, 1);
					oLayout.put_StyleSheet(cstr); // 플롯 스타일

					// 혹시 몰라 시스템의 기본 플롯 스타일을 현재거로 바꾼다
					// sErr = "기본 플롯 스타일 변경 에러"
					// acPref.DefaultPlotStyleTable = CStr(lvwDwg.ListItems(i).SubItems(1))
					// .PlotWithPlotStyles = True

					// 플롯 축척
					sErr = _T("플롯 축척 설정 에러");
					if (chkFitScale.GetCheck()) {
						oLayout.put_UseStandardScale(TRUE);
						oLayout.put_StandardScale(acScaleToFit);
					}
					if (tbScale.IsWindowEnabled()) {
						oLayout.put_UseStandardScale(FALSE);
						oLayout.SetCustomScale(1, dScale); // 지정 축척
					}

					// 플롯 회전
					sErr = _T("플롯 회전 설정 에러");
					if (optHor.GetCheck())
						oLayout.put_PlotRotation(ac90degrees);
					else if (optVer.GetCheck())
						oLayout.put_PlotRotation(ac0degrees);

					// 플롯 중앙
					sErr = _T("플롯 중앙 설정 에러");
					if (chkPlotCenter.GetCheck())
						oLayout.put_CenterPlot(TRUE);
					else {
						oLayout.put_CenterPlot(FALSE);
						GetDlgItemText(IDC_TBPLOTX, cstr);
						dOrigin[0] = _ttof(cstr);
						GetDlgItemText(IDC_TBPLOTY, cstr);
						dOrigin[1] = _ttof(cstr);
						VARIANT var;
						Point2d2Array(&var, dOrigin);
						oLayout.put_PlotOrigin(var);
					}

					// Extent, Limit, Layout 출력
					if (optExtend.GetCheck())
						oLayout.put_PlotType(acExtents);
					else if (optLimit.GetCheck()) {
						if (bOnlyLayout || bSpecLayout)
							oLayout.put_PlotType(acLayout);
						else {
							if (bActive) {
								if (pLayName.CompareNoCase(_T("model")) != 0)
									oLayout.put_PlotType(acLayout);
								else
									oLayout.put_PlotType(acLimits);
							}
							else
								oLayout.put_PlotType(acLimits);
						}
					}

					// 플롯 도면 단위에 대한 출력 스케일 보정
					// 1=inch , 0 = milimeter
					sErr = _T("출력 축척 보정 에러");

					// 그냥 밀리미터로 설정하자
					oLayout.put_PaperUnits(acMillimeters);

					// 이건 예전코드
					//If .PaperUnits = 1 Then
					dCorrect = 1;
					//Else
					//	dCorrect = 25.4
					//End If
					oPlotFile.Regen(acAllViewports);
				}

				// 폼출력일때
				if (bPlotWindow) {
					gds_name ssname; 
					gds_name ename;
					gds_point pt;
					GcDbObjectId objId;
					GcDbEntity* pEnt;
					GcDbBlockReference* pInsert;
					Gcad::ErrorStatus es;

					if (chkSelForm.GetCheck()) {
						gcedSSAdd(NULL, NULL, ssname);
						//CmdPrompt "도곽(Form) 선택 :"
						//oSel.SelectOnScreen iGcode, vData
						while(1) {
							// Let the user select an INSERT (Block reference).
							if (gcedEntSel(L"\nForm에 해당되는 객체를 선택 : ", ename, pt) != RTNORM)
								break;

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
					}
					else {
						struct resbuf rb1, rb2;
						TCHAR sbuf[10] = _T("INSERT"); 
						TCHAR snam[256]; 
						//_tcscpy(sbuf, _T("INSERT")); 
						_tcscpy(snam, sTemp);

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
					gcedSSLength(ssname, &iXrefCnt);
					if (iXrefCnt < 1) {
						if (bActive || bModel || bSpecLayout) {
							bPlotErr = TRUE;
							LogErr(oPlotFile.get_Name() + _T(" : 도면에 지정한 이름의 Form이 없습니다 - ") + sTemp, FALSE);
							goto NextDwg;
						}
						else {
							if (iNext == iLayCnt) {
								if (!bPloted) {
									bPlotErr = TRUE;
									LogErr(oPlotFile.get_Name() + _T(" : 도면에 지정한 이름의 Form이 없습니다 - ") + sTemp, FALSE);
									goto NextDwg;
								}
							}
							goto NextLayout;
						}
					}

					sErr = _T("일부 출력 입력 에러");

					// 한도면 내의 여러 폼 순환
					if (chkPLT.GetCheck()) {
						GetDlgItemText(IDC_TBPLT, cstr);
						sPLT = cstr + sFileName;
					}
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
						GcDbObjectId blockDefId;
						blockDefId = pInsert->blockTableRecord();
						GcDbBlockTableRecord *pBlkRecord;
						gcdbOpenObject(pBlkRecord, blockDefId, GcDb::kForRead);
						es = pBlkRecord->getName(sFormName);

						iIniPos = GetFormIniPos(sFormName);
						CString nstr;
						nstr.Format(_T("%d"), iIniPos);

						// 폼별 설정
						bRealVert = m_regEdit.GetBoolean(_T("MPL"), _T("RealVertical") + nstr, FALSE);
						dPaperH = m_regEdit.GetDouble(_T("MPL"), _T("PaperHeight") + nstr, _T("594"));
						dYHeight = m_regEdit.GetDouble(_T("MPL"), _T("Height") + nstr, _T("594"));
						dXWidth = m_regEdit.GetDouble(_T("MPL"), _T("Width") + nstr, _T("841"));
						dMin[X] = m_regEdit.GetDouble(_T("MPL"), _T("FromMinX") + nstr, _T("0"));
						dMin[Y] = m_regEdit.GetDouble(_T("MPL"), _T("FromMinY") + nstr, _T("0"));
						dMax[X] = m_regEdit.GetDouble(_T("MPL"), _T("FromMaxX") + nstr, _T("841"));
						dMax[Y] = m_regEdit.GetDouble(_T("MPL"), _T("FromMaxY") + nstr, _T("594"));
						bVertical = m_regEdit.GetBoolean(_T("MPL"), _T("IsVertical") + nstr, FALSE);
						if (!tbScale.IsWindowEnabled())
							dScale = GetPlotScaleByA1(dPaperH, bVertical);

						// 출력 취소 폼에서 취소 반환되면 현재 도면 취소
						if (bMPLCancel || bMPLExit)
							break;

						if (bUCS) {
							//With oSel.Item(k)
							if (dTwAng != 0)
								Rotate(pInsert, dZero, dTwAng);
							bRotate = IsVerDwg(pInsert->rotation()); // false = 가로도면
							pInsert->geomExtentsBestFit(extents);
							vMin = extents.minPoint();
							vMax = extents.maxPoint();
							dSelVer = vMax[Y] - vMin[Y];
							dSelHor = vMax[X] - vMin[X];
							if (dTwAng != 0)
								Rotate(pInsert, dZero, -dTwAng);
							vMin = GetRotPnt(dZero, vMin, -dTwAng);
							vMax = GetRotPnt(dZero, vMax, -dTwAng);
						}
						else {
							//With oSel.Item(k)
							bRotate = FALSE;
							pInsert->geomExtentsBestFit(extents);
							vMin = extents.minPoint();
							vMax = extents.maxPoint();
							dSelVer = vMax[Y] - vMin[Y];
							dSelHor = vMax[X] - vMin[X];
						}

						vMin = ToDCS(vMin);
						vMax = ToDCS(vMax);

						dZoomMin[X] = vMin[X];
						dZoomMin[Y] = vMin[Y];
						dZoomMin[Z] = 0.0;
						dZoomMax[X] = vMax[X];
						dZoomMax[Y] = vMax[Y];
						dZoomMax[Z] = 0.0;

						if (!bUCS)
							//ZoomWindow(dZoomMin, dZoomMax);
							gcedCommand(RTSTR, _T("_ZOOM"), RTSTR, _T("_W"),
								RTPOINT, asDblArray(dZoomMin),
								RTPOINT, asDblArray(dZoomMax), RTNONE);

						// 원래 폼이 세로 도면이면 가로 세로 뒤집는다
						if (bRealVert)
							bRotate = !bRotate;

						// 지정한 폼과 현재 폼과의 크기차이
						if (!bRotate) { // 회전 안된 도면
							if (bVertical) {
								dDiff = dSelVer / dXWidth;
								// 출력할 윈도우(Two Array)
								dPlotMin[X] = vMin[X] + dMin[X] * dDiff;
								dPlotMin[Y] = vMin[Y] + dMin[Y] * dDiff;
								dPlotMax[X] = vMin[X] + dMax[Y] * dDiff;
								dPlotMax[Y] = vMin[Y] + dMax[X] * dDiff;
							}
							else {
								dDiff = dSelVer / dYHeight;
								dPlotMin[X] = vMin[X] + dMin[X] * dDiff;
								dPlotMin[Y] = vMin[Y] + dMin[Y] * dDiff;
								dPlotMax[X] = vMin[X] + dMax[X] * dDiff;
								dPlotMax[Y] = vMin[Y] + dMax[Y] * dDiff;
							}
							if (optAuto.GetCheck()) {
								if (bHorPaper)
									oLayout.put_PlotRotation(ac0degrees);
								else
									oLayout.put_PlotRotation(ac90degrees);
							}
						}
						else {
							if (bVertical) {
								dDiff = dSelVer / dYHeight;
								dPlotMin[X] = vMin[X] + dMin[X] * dDiff;
								dPlotMin[Y] = vMin[Y] + dMin[Y] * dDiff;
								dPlotMax[X] = vMin[X] + dMax[X] * dDiff;
								dPlotMax[Y] = vMin[Y] + dMax[Y] * dDiff;
							}
							else {
								dDiff = dSelVer / dXWidth;
								dPlotMin[X] = vMin[X] + dMin[X] * dDiff;
								dPlotMin[Y] = vMin[Y] + dMin[Y] * dDiff;
								dPlotMax[X] = vMin[X] + dMax[Y] * dDiff;
								dPlotMax[Y] = vMin[Y] + dMax[X] * dDiff;
							}
							if (optAuto.GetCheck()) {
								if (bHorPaper)
									oLayout.put_PlotRotation(ac90degrees);
								else
									oLayout.put_PlotRotation(ac0degrees);
							}
						}

						//With oLayout
						// 윈도우설정.PlotType을 SetWindowToPlot 뒤에 써줘야 함
						VARIANT var1, var2;
						Point2d2Array(&var1, dPlotMin);
						Point2d2Array(&var2, dPlotMax);
						oLayout.SetWindowToPlot(var1, var2);
						oLayout.put_PlotType(acWindow);

						// '폼이 여러개인 경우가 있으므로 폼출력은 순환하면서 아래를 거쳐야 한다.
						sErr = _T("Form 맞춤 에러");
						if (chkFitScale.GetCheck()) { // 용지에 맞춤
							oLayout.put_UseStandardScale(TRUE);
							oLayout.put_StandardScale(acScaleToFit);
						}
						else if (chkAutoScaleA1.GetCheck()) { // 자동 맞춤(A1기준)
							oLayout.put_UseStandardScale(FALSE);
							oLayout.SetCustomScale(1, dScale * dDiff * dCorrect * dReScale);
						}
						else { // 지정한 축척
							oLayout.put_UseStandardScale(FALSE);
							oLayout.SetCustomScale(1, dScale * dDiff * dReScale);
						}

						//With oPlotFile.Plot
						if (chkCopy.GetCheck())
							IPlot.put_NumberOfCopies(1);
						else
							IPlot.put_NumberOfCopies(GetDlgItemInt(IDC_TBPLOTCNT)); // 플롯 매수

						if (previewPlot) {
							IPlot.DisplayPlotPreview(acFullPreview); // 플롯 미리보기
							bPloted = TRUE;
						}
						else {
							if (chkPreviw.GetCheck()) {
								sErr = _T("플롯 미리보기 에러");
								IPlot.DisplayPlotPreview(acFullPreview); // 플롯 미리보기
								bPloted = TRUE;
							}
							else {
								sErr = _T("플롯 에러");
								if (chkPLT.GetCheck()) {
									// 모델인 경우 모델하나에 도곽이 여러개면 아래에서 도곽 개수인 k로 출력시
									// 번호가 다르게 나오지만 배치인경우 배치하나당 폼이 하나면
									// 아래 k로 출력하는 경우 배치 하나당 폼이 한개라 k는 계속 0 이됨
									// 따라서 iFileNum 변수를 두고
									// 모델인 경우는 k 값 그냥 사용
									// 배치인 경우는 iFileNum 증분해서 값을 다르게 한다
									if (bActive || bModel)
										iFileNum = k + 1;
									else
										iFileNum = iFileNum + 1;

									GetComboText(&cboPlotter, cstr);
									cstr.MakeUpper();
									if (cstr.Find(_T(".JPG")) >= 0)
										cstr.Format(_T("%s-%d.%s"), sPLT, iFileNum, _T("jpg"));
									else if (cstr.Find(_T(".PNG")) >= 0)
										cstr.Format(_T("%s-%d.%s"), sPLT, iFileNum, _T("png"));
									else if (cstr.Find(_T(".PDF")) >= 0)
										cstr.Format(_T("%s-%d.%s"), sPLT, iFileNum, _T("pdf"));
									else
										cstr.Format(_T("%s-%d.%s"), sPLT, iFileNum, _T("plt"));
									IPlot.PlotToFile(cstr, _variant_t(sPlotterName));
								}
								else {
									GetComboText(&cboPlotter, cstr);
									IPlot.PlotToDevice(_variant_t(cstr)); // 플롯
								}
								bPloted = TRUE;
							}
						}
						int dTim = GetDlgItemInt(IDC_TBDELAY);
						if (dTim > 0)
							Sleep(dTim * 1000);
					} // End of 한도면내의 여러폼
					goto NextDwg;
				} // End of 폼출력

				if (bMPLCancel || bMPLExit)
					break;
				// 윈도우 출력일때
				if (optWindow.GetCheck()) {
					bWinUser = m_regEdit.GetBoolean(_T("MPL"), _T("WinUser"), FALSE);

					// 사용자가 윈도우 선택
					if (bWinUser) {
						sErr = _T("인쇄 영역 선택 에러");
						if (gcedGetPoint(NULL, _T("인쇄할 영역의 첫번째 모서리 점 지정:"), asDblArray(vSpnt)) != RTNORM) {
							ShowWindow(SW_HIDE);
							return;
						}

						if (gcedGetCorner(asDblArray(vSpnt), _T("인쇄할 영역의 두번째 모서리 점 지정:"), asDblArray(vEpnt)) != RTNORM) {
							ShowWindow(SW_HIDE);
							return;
						}

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
						sErr = _T("지정 윈도우 에러");
						dPlotMin[X] = m_regEdit.GetDouble(_T("MPL"), _T("WinMinX"), 0.0);
						dPlotMin[Y] = m_regEdit.GetDouble(_T("MPL"), _T("WinMinY"), 0.0);
						dPlotMax[X] = m_regEdit.GetDouble(_T("MPL"), _T("WinMaxX"), 841.0);
						dPlotMax[Y] = m_regEdit.GetDouble(_T("MPL"), _T("WinMaxY"), 594.0);
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

					sErr = _T("윈도우 출력 에러");
					VARIANT var1, var2;
					Point2d2Array(&var1, dPlotMin);
					Point2d2Array(&var2, dPlotMax);
					oLayout.SetWindowToPlot(var1, var2);
					oLayout.put_PlotType(acWindow);
				} // End of 윈도우출력

				// 일반출력 공통(폼 제외)
				if (!bPlotWindow) {
					if (!optDrawing) {
						sErr = _T("공통 출력 맞춤 에러");
						// 용지에 맞춤
						if (chkFitScale.GetCheck()) {
							oLayout.put_UseStandardScale(TRUE);
							oLayout.put_StandardScale(acScaleToFit);
						}
						// 자동 맞춤(A1기준)
						else if (chkAutoScaleA1.GetCheck()) {
							oLayout.put_UseStandardScale(FALSE);
							oLayout.SetCustomScale(1, dScale * dDiff * dCorrect * dReScale);
						}
						// 지정한 축척
						else {
							oLayout.put_UseStandardScale(FALSE);
							oLayout.SetCustomScale(1, dScale * dDiff * dReScale);
						}
					}

					if (chkCopy.GetCheck())
						IPlot.put_NumberOfCopies(1);
					else
						IPlot.put_NumberOfCopies(GetDlgItemInt(IDC_TBPLOTCNT)); // 플롯 매수

					if (previewPlot) {
						IPlot.DisplayPlotPreview(acFullPreview); // 플롯 미리보기
						bPloted = TRUE;
					}
					else {
						if (chkPreviw.GetCheck()) {
							sErr = _T("공통 출력 미리보기 에러");
							IPlot.DisplayPlotPreview(acFullPreview); // 플롯 미리보기
							bPloted = TRUE;
						}
						else {
							sErr = _T("공통 출력 플롯 에러");
							if (chkPLT.GetCheck()) {
								GetDlgItemText(IDC_TBPLT, cstr);
								IPlot.PlotToFile(cstr, _variant_t(sPlotterName));
							}
							else {
								if (!optDrawing.GetCheck()) {
									GetComboText(&cboPlotter, cstr);
									IPlot.PlotToDevice(_variant_t(cstr)); // 플롯
								}
								else
									IPlot.PlotToDevice(_variant_t(sPlotterName));
								bPloted = TRUE;
							}
						}
					}
				}

			// 폼이 없을때 여기로 이동
NextDwg:
				// 활성, 모형, 특정레이아웃이면 한번 돌고 종료
				if (bActive || optModel || bSpecLayout)
					break;
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
				oPlotFile.Close(saveChanges, fileName);
			}
			if (!bPlotWindow) {
				int dTim = GetDlgItemInt(IDC_TBDELAY);
				if (dTim > 0)
					Sleep(dTim * 1000);
			}

			// 미리보기면 선택한 아이템으로 처리했으니 순환하지 않고 종료
			if (previewPlot)
				break;
		} // next i, 도면한장 끝
	} // next iCopy, 인쇄매수

	dlgExit.ShowWindow(SW_HIDE);
	CompleteEditorCommand();

	// 혹시 몰라 첨가했던 플롯 스타일 복원
	// sErr = "플롯 스타일 복원 에러"
	// acPref.DefaultPlotStyleTable = sOldStyle

	//oPlotFile = NULL;
	//oLayout = NULL;
	//acPref = NULL;

	// 시스템 변수되돌림
	sErr = _T("시스템 변수 되돌림 에러");
	//With thisDrawing
	if (dVer > 16)
		SetVariable(_T("BACKGROUNDPLOT"), iPlotBack);
	SetVariable(_T("Expert"), iExpert);
	SetVariable(_T("DWGCHECK"), iDwgCheck);
	sErr = _T("플롯 레포트 작성 에러");
	if (bPlotErr)
		PlotErrReport();

	if (chkPreviw.GetCheck())
		bMPLCancel = TRUE;
	if (!bMPLCancel && !bMPLExit)
		CGcUiDialog::OnCancel(); // 미리보기시 취소나 종료 안누른경우
	if (bMPLExit)
		CGcUiDialog::OnCancel();
	if (bMPLCancel)
		CGcUiDialog::OnCancel();
	return;

ErrorHandler:
	//if (bPlotErr)
	//	AfxMessageBox(sErr, MB_OK | MB_ICONERROR);

	dlgExit.ShowWindow(SW_HIDE);
	CompleteEditorCommand();
	// acPref.DefaultPlotStyleTable = sOldStyle

	oPlotFile = NULL;
	oLayout = NULL;
	// acPref = NULL;

	//With thisDrawing
	if (dVer > 16)
		SetVariable(_T("BACKGROUNDPLOT"), iPlotBack);
	SetVariable(_T("Expert"), iExpert);
	SetVariable(_T("DWGCHECK"), iDwgCheck);

	if (bPlotErr)
		PlotErrReport();

	CGcUiDialog::OnCancel();
}


int CDlgMPL::GetFormIniPos(LPCTSTR sFormName)
{
	CString s;
	CString n;
	int i;

	for (i = 1; i <= 6; i ++) {
		n.Format(_T("FormName%d"), i);
		s = m_regEdit.GetString(_T("MPL"), n, _T(""));
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


void CDlgMPL::PlotErrReport()
{
	LogErr(_T(""), TRUE);
	CString cmsg;
	cmsg.Format(_T("플롯되지 않은 도면이 있습니다\nC:\\PlotError.txt 파일을 확인하세요"));
	AfxMessageBox(cmsg, MB_OK | MB_ICONINFORMATION);
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


// 도면 추가
void CDlgMPL::OnBnClickedCbadd()
{
	CString sOldPath;
	CString filPth, filNam;
	CString styNam;
	BOOL bDup;
	POSITION pos;
	int i;

	sOldPath = m_regEdit.GetString(_T("MPL"), _T("PrevFolder"), _T("C:\\"));

	CFileDialog filDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY,
		_T("도면파일 (*.dwg)|*.dwg|All Files(*.*)|*.*||"));
	filDlg.m_ofn.lpstrTitle = _T("파일 추가"); 
	filDlg.m_ofn.lpstrInitialDir = sOldPath;
	filDlg.m_ofn.Flags = OFN_EXPLORER | OFN_LONGNAMES | OFN_CREATEPROMPT |
						OFN_NODEREFERENCELINKS | OFN_ALLOWMULTISELECT;
	if (filDlg.DoModal() != IDOK)
		return;

	sOldPath = filDlg.GetFolderPath();
	m_regEdit.SetString(_T("MPL"), _T("PrevFolder"), sOldPath);

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

	//lvwDwg.Refresh
}


void CDlgMPL::AppendDir(LPCTSTR dirName, LPCTSTR findName)
{
	WIN32_FIND_DATA findData;
	HANDLE hFind;
	CString filPath, filNam;
	CString msgStr;
	CString styNam;
	int i;

	filPath.Format(_T("%s\\%s"), dirName, findName);
	if ((hFind = FindFirstFile(filPath, &findData)) == INVALID_HANDLE_VALUE) {
		msgStr.Format(_T("'%s' 폴더를 열 수 없습니다."), dirName);
		AfxMessageBox (msgStr, MB_OK | MB_ICONSTOP);
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
			filNam = findData.cFileName;
			filPath.Format(_T("%s\\%s"), dirName, findData.cFileName);
			i = lvwDwg.GetItemCount();
			i = lvwDwg.InsertItem(i, filNam);
			lvwDwg.SetItemText(i, 1, styNam);
			lvwDwg.SetItemText(i, 3, filPath);
			lvwDwg.SetItemData(i, i);
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
		if (FindOpenDwg(filPth, iDoc))
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
		if (FindOpenDwg(filPth, iDoc))
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
}


// 리스트뷰 전체 항목 삭제
void CDlgMPL::OnBnClickedCbdelall()
{
	lvwDwg.DeleteAllItems();
	lvwDwg.SetFocus();
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

	sOldPath = m_regEdit.GetString(_T("MPL"), _T("SaveFolder"), _T("C:\\"));

	CFileDialog filDlg(FALSE, NULL, NULL, OFN_HIDEREADONLY,
		_T("텍스트 파일 (*.txt)|*.txt|All Files(*.*)|*.*||"));
	filDlg.m_ofn.lpstrTitle = _T("목록 텍스트 파일 저장"); 
	filDlg.m_ofn.lpstrInitialDir = sOldPath;
	if (filDlg.DoModal() != IDOK)
		return;

	sOpenFile = filDlg.GetPathName();
	sOldPath = filDlg.GetFolderPath();
	m_regEdit.SetString(_T("MPL"), _T("SaveFolder"), sOldPath);

	fout = _tfopen(sOpenFile, _T("w"));
	if (fout == NULL)
		return;

	_ftprintf(fout, _T("[Magic Plot List]\n"));
	for (i = 0; i < iCnt; i ++)
		_ftprintf(fout, _T("%s,%s,%s\n"), lvwDwg.GetItemText(i, 3), lvwDwg.GetItemText(i, 0), lvwDwg.GetItemText(i, 1));
	
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

	sOldPath = m_regEdit.GetString(_T("MPL"), _T("OpenFolder"), _T("C:\\"));

	CFileDialog filDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY,
		_T("텍스트 파일 (*.txt)|*.txt|All Files(*.*)|*.*||"));
	filDlg.m_ofn.lpstrTitle = _T("출력 목록 텍스트 파일 열기"); 
	filDlg.m_ofn.lpstrInitialDir = sOldPath;
	if (filDlg.DoModal() != IDOK)
		return;

	sOpenFile = filDlg.GetPathName();
	sOldPath = filDlg.GetFolderPath();
	m_regEdit.SetString(_T("MPL"), _T("OpenFolder"), sOldPath);

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
}


int CALLBACK ListSortAscend(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	CListCtrl* pListCtrl = (CListCtrl*)lParamSort;

	CString strItem1 = pListCtrl->GetItemText(lParam1, 0);
	CString strItem2 = pListCtrl->GetItemText(lParam2, 0);

	return _tcsicmp(strItem1, strItem2);
}


int CALLBACK ListSortDescend(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	CListCtrl* pListCtrl = (CListCtrl*)lParamSort;

	CString strItem1 = pListCtrl->GetItemText(lParam1, 0);
	CString strItem2 = pListCtrl->GetItemText(lParam2, 0);

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


void CDlgMPL::RefreshMediaNames()
{
	GcArray<const TCHAR*> MediaList;
	CStringArray sPaper;
	int iCnt;
	int i;
	VARIANT var;

	//pPSV->refreshLists(pPlotSettings);
	//pPSV->canonicalMediaNameList(pPlotSettings,MediaList);
	oLayout.RefreshPlotDeviceInfo();
	var = oLayout.GetCanonicalMediaNames();
	Variant2Array(&var, sPaper);
	////////////////////

	cboPaper.ResetContent();
	//iCnt = MediaList.length();
	iCnt = sPaper.GetCount();
	for (i = 0; i < iCnt; i ++) {
		cboPaper.AddString(sPaper[i]);
	}

	//pPlotSettings->getCanonicalMediaName(pCurName);
	//pPSV->getLocaleMediaName(pPlotSettings, pCurName, localName);
	//SelectComboText(&cboPaper, localName);
}


void CDlgMPL::RefreshDevices()
{
	VARIANT var;
	CStringArray sPlotter;
	int iCnt;
	int i;

	var = oLayout.GetPlotDeviceNames();
	Variant2Array(&var, sPlotter);

	cboPlotter.ResetContent();
	iCnt = sPlotter.GetCount();
	for (i = 0; i < iCnt; i ++)
		cboPlotter.AddString(sPlotter[i]);
}


void CDlgMPL::RefreshPlotStyle()
{
	VARIANT var;
	CStringArray sStyle;
	int iCnt;
	int i;

	var = oLayout.GetPlotStyleTableNames();
	Variant2Array(&var, sStyle);

	cboStyle.ResetContent();
	iCnt = sStyle.GetCount();
	for (i = 0; i < iCnt; i ++)
		cboStyle.AddString(sStyle[i]);
}


// 플로터 변경에 따른 용지종류 변경
void CDlgMPL::OnCbnSelchangeCboplotter()
{
	CString sPlotterName;

	cboPaper.Clear();

	GetComboText(&cboPlotter, sPlotterName);
	if (sPlotterName.CompareNoCase(_T("없음")) == 0 || sPlotterName.CompareNoCase(_T("none")) == 0) {
		cboPaper.AddString(_T("없음"));
		cboPaper.SetCurSel(0);
		return;
	}

	// 지정한 플로터를 현재 플로터로
	oLayout.put_ConfigName(sPlotterName);
	oLayout.RefreshPlotDeviceInfo();

	CStringArray sPaper;
	CString sName;
	int iCnt;
	int i;
	VARIANT var;

	// 모든 용지 종류 얻어서
	var = oLayout.GetCanonicalMediaNames();
	Variant2Array(&var, sPaper);

	// 용지를 순환하면서 각 요소의 이름을 다시 받는다
	// 플로터 용지가 Userxxxx 로 나오는것 방지
	iCnt = sPaper.GetCount();
	for (i = 0; i < iCnt; i ++) {
		sName = oLayout.GetLocaleMediaName(sPaper[i]);
		cboPaper.AddString(sName);
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
	int len;

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

	len = _tcslen(dirPath);
	if (len < 1)
		return;

	if (dirPath[len - 1] != '\\')
		_tcscat(dirPath, _T("\\"));

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
		chkPreviw.SetCheck(!bTrue);
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
BOOL CDlgMPL::FindOpenDwg(LPCTSTR sName, CGcadDocument& IDoc)
{
	IDispatch *pDisp;
	CGcadApplication IApp;
	CGcadDocuments IDocs;

	pDisp = gcedGetGcadWinApp()->GetIDispatch(TRUE);
	IApp.AttachDispatch(pDisp);

	pDisp = IApp.get_Documents();
	IDocs.AttachDispatch(pDisp);

	long docNum;
	docNum = IDocs.get_Count();
	CString pFullName;
	BOOL found = FALSE;
	for (long i = 0; i < docNum; i++) {
		pDisp = IDocs.Item(COleVariant(i));
		IDoc.AttachDispatch(pDisp);
		pFullName = IDoc.get_FullName();
		if (pFullName.CompareNoCase(sName) == 0) {
			return TRUE;
		}
	}

	return FALSE;
}
//If AcadDoc.Path & "\" & AcadDoc.Name = sName Then


double CDlgMPL::GetPlotScaleByA1(double dVal, BOOL bVert)
{
	CString papNam;
	double rVal;

	GetComboText(&cboPaper, papNam);

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

	return DoubleRound(dVal, 2);
}


BOOL CDlgMPL::IsAPaper()
{
	CString papNam;

	GetComboText(&cboPaper, papNam);

	if (papNam.Find(_T("A0")) >= 0 ||
		papNam.Find(_T("A1")) >= 0 ||
		papNam.Find(_T("A2")) >= 0 ||
		papNam.Find(_T("A3")) >= 0 ||
		papNam.Find(_T("A4")) >= 0)
		return TRUE;
	else
		return FALSE;
}


// 에러 발생시 로그기록
void CDlgMPL::LogErr(LPCTSTR sError, BOOL bEnd)
{
	CString fNam;
	FILE *fp;
	int i, len;

	sLog.Add(sError);

	// 파일기록
	if (bEnd) {
		fNam = _T("C:\\temp\\PlotError.txt");
		fp = _tfopen(fNam, _T("w"));
		len = sLog.GetCount();
		for (i = 0; i < len; i ++)
			_fputts(sLog[i], fp);
		fclose(fp);

		sLog.RemoveAll();
	}
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
	//::HtmlHelp(NULL, _T("magic.chm"), 0, 0);
}


void CDlgMPL::LoadIni()
{
	CString cstr;
	int opt;

	cstr = m_regEdit.GetString(_T("MPL"), _T("Plotter"), _T(""));
	SelectComboText(&cboPlotter, cstr);
	OnCbnSelchangeCboplotter();

	cstr = m_regEdit.GetString(_T("MPL"), _T("Paper"), _T(""));
	SelectComboText(&cboPaper, cstr);
	cstr = m_regEdit.GetString(_T("MPL"), _T("Style"), _T(""));
	SelectComboText(&cboStyle, cstr);

	opt = m_regEdit.GetInteger(_T("MPL"), _T("AreaType"), 0);
	CheckRadioButton(IDC_OPTFORM, IDC_OPTDRAWING, opt + IDC_OPTFORM);
	OnBnClickedOptform();

	opt = m_regEdit.GetInteger(_T("MPL"), _T("TargetType"), 0);
	CheckRadioButton(IDC_OPTACTIVE, IDC_OPTSPECLAYOUT, opt + IDC_OPTACTIVE);
	tbLayout.ShowWindow(((opt + IDC_OPTACTIVE) == IDC_OPTSPECLAYOUT) ? SW_SHOW: SW_HIDE);

	tbLayout.SetWindowTextW(m_regEdit.GetString(_T("MPL"), _T("LayoutName"), _T("")));
	chkFitScale.SetCheck(m_regEdit.GetBoolean(_T("MPL"), _T("FitScale"), FALSE));
	tbScale.EnableWindow(chkFitScale.GetCheck() ? FALSE: TRUE);
	chkAutoScaleA1.SetCheck(m_regEdit.GetBoolean(_T("MPL"), _T("AutoScale"), TRUE));
	tbScale.SetWindowTextW(m_regEdit.GetString(_T("MPL"), _T("Scale"), _T("1")));
	chkPlotCenter.SetCheck(m_regEdit.GetBoolean(_T("MPL"), _T("PlotCenter"), TRUE));
	tbPlotX.SetWindowTextW(m_regEdit.GetString(_T("MPL"), _T("PlotX"), _T("0")));
	tbPlotY.SetWindowTextW(m_regEdit.GetString(_T("MPL"), _T("PlotY"), _T("0")));

	opt = m_regEdit.GetInteger(_T("MPL"), _T("PlotDir"), 0);
	CheckRadioButton(IDC_OPTSORTLR, IDC_OPTSORTIZ, opt + IDC_OPTSORTLR);

	tbDelay.SetWindowTextW(m_regEdit.GetString(_T("MPL"), _T("Delay"), _T("0")));
	chkPLT.SetCheck(m_regEdit.GetBoolean(_T("MPL"), _T("PLT"), FALSE));
	tbReScale.SetWindowTextW(m_regEdit.GetString(_T("MPL"), _T("ReScale"), _T("100")));

	opt = m_regEdit.GetInteger(_T("MPL"), _T("PaperDir"), 0);
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

	m_regEdit.SetInteger(_T("MPL"), _T("AreaType"),
		GetCheckedRadioButton(IDC_OPTFORM, IDC_OPTDRAWING) - IDC_OPTFORM);
	m_regEdit.SetInteger(_T("MPL"), _T("TargetType"),
		GetCheckedRadioButton(IDC_OPTACTIVE, IDC_OPTSPECLAYOUT) - IDC_OPTACTIVE);
	GetComboText(&cboPlotter, cstr); m_regEdit.SetString(_T("MPL"), _T("Plotter"), cstr);
	GetComboText(&cboPaper, cstr); m_regEdit.SetString(_T("MPL"), _T("Paper"), cstr);
	GetComboText(&cboStyle, cstr); m_regEdit.SetString(_T("MPL"), _T("Style"), cstr);
	tbLayout.GetWindowTextW(cstr); m_regEdit.SetString(_T("MPL"), _T("LayoutName"), cstr);
	m_regEdit.SetBoolean(_T("MPL"), _T("FitScale"), chkFitScale.GetCheck());
	m_regEdit.SetBoolean(_T("MPL"), _T("AutoScale"), chkAutoScaleA1.GetCheck());
	tbScale.GetWindowTextW(cstr); m_regEdit.SetString(_T("MPL"), _T("Scale"), cstr);
	m_regEdit.SetBoolean(_T("MPL"), _T("PlotCenter"), chkPlotCenter.GetCheck());
	tbPlotX.GetWindowTextW(cstr); m_regEdit.SetString(_T("MPL"), _T("PlotX"), cstr);
	tbPlotY.GetWindowTextW(cstr); m_regEdit.SetString(_T("MPL"), _T("PlotY"), cstr);
	m_regEdit.SetInteger(_T("MPL"), _T("PlotDir"),
		GetCheckedRadioButton(IDC_OPTSORTLR, IDC_OPTSORTIZ) - IDC_OPTSORTLR);
	tbDelay.GetWindowTextW(cstr); m_regEdit.SetString(_T("MPL"), _T("Delay"), cstr);
	m_regEdit.SetBoolean(_T("MPL"), _T("PLT"), chkPLT.GetCheck());
	tbReScale.GetWindowTextW(cstr); m_regEdit.SetString(_T("MPL"), _T("ReScale"), cstr);
	m_regEdit.SetInteger(_T("MPL"), _T("PaperDir"),
		GetCheckedRadioButton(IDC_OPTAUTO, IDC_OPTVER) - IDC_OPTAUTO);
}


BOOL CDlgMPL::OnInitDialog()
{
	CGcUiDialog::OnInitDialog();

	m_regEdit.SetKey(HKEY_CURRENT_USER, _T("SOFTWARE\\Magic\\MagicUtil"));

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
	oLayout.AttachDispatch(pDisp);

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
	lvwDwg.InsertColumn (0, _T("도면"), LVCFMT_LEFT, sngWidth * 5.8 / 10.0, 0);
	lvwDwg.InsertColumn (1, _T("스타일"), LVCFMT_LEFT, sngWidth * 3.0 / 10.0, 0);
	lvwDwg.InsertColumn (3, _T("상태"), LVCFMT_CENTER, sngWidth * 1.2 / 10.0, 0);
	lvwDwg.InsertColumn (3, _T("파일경로"), LVCFMT_LEFT, 0, 0);
	lvwDwg.InsertColumn (4, _T("플롯상태"), LVCFMT_LEFT, 0, 0);

	cbScaleView.SubclassDlgItem(IDC_CBSCALEVIEW, this);
	cbScaleView.SetImage(IDB_SEARCH);

	ThumbView.SubclassDlgItem(IDC_THUMBVIEW, this);
	ThumbView.SetBkgColor(0);

	OnBnClickedChkplotcenter();
	OnBnClickedChkplt();
	OnBnClickedChkrescale();

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

