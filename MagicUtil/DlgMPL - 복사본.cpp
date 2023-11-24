// DlgMPL.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MagicUtil.h"
#include "DlgMPL.h"
#include "afxdialogex.h"
#include "DlgMPLStyle.h"
#include "DlgMPLForm.h"
#include "DlgMPLScale.h"
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
	DDX_Control(pDX, IDC_CBSORT, cbSort);
	DDX_Control(pDX, IDC_OPTASCEND, optAscend);
	DDX_Control(pDX, IDC_LBLCOUNT, lblCount);
	DDX_Control(pDX, IDC_TBPATH, tbPath);
	DDX_Control(pDX, IDC_OPTFORM, optForm);
	DDX_Control(pDX, IDC_OPTWINDOW, optWindow);
	DDX_Control(pDX, IDC_OPTEXTEND, optExtend);
	DDX_Control(pDX, IDC_OPTLIMIT, optLimit);
	DDX_Control(pDX, IDC_OPTDRAWING, optDrawing);
	DDX_Control(pDX, IDC_CBFORM, cbForm);
	DDX_Control(pDX, IDC_CBSCALEVIEW, cbScaleView);
	DDX_Control(pDX, IDC_CBWINDOW, cbWindow);
	DDX_Control(pDX, IDC_TBNAME, tbName);
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
	DDX_Control(pDX, IDC_LABEL14, Label14);
	DDX_Control(pDX, IDC_LABEL11, Label11);
	DDX_Control(pDX, IDC_CHKPART, chkPart);
	DDX_Control(pDX, IDC_TBPARTS, tbPartS);
	DDX_Control(pDX, IDC_TBPARTE, tbPartE);
	DDX_Control(pDX, IDC_LABEL5, Label5);
	DDX_Control(pDX, IDC_LABEL6, Label6);
	DDX_Control(pDX, IDC_LABEL12, Label12);
	DDX_Control(pDX, IDC_LABEL17, Label17);
	DDX_Control(pDX, IDC_LABEL18, Label18);
	DDX_Control(pDX, IDC_LABEL4, Label4);
}


BEGIN_MESSAGE_MAP(CDlgMPL, CGcUiDialog)
	ON_BN_CLICKED(IDC_CBPREVIEW, &CDlgMPL::OnBnClickedCbpreview)
	ON_BN_CLICKED(IDC_CBADD, &CDlgMPL::OnBnClickedCbadd)
	ON_BN_CLICKED(IDC_CBFOLDER, &CDlgMPL::OnBnClickedCbfolder)
	ON_BN_CLICKED(IDC_CBADDCUR, &CDlgMPL::OnBnClickedCbaddcur)
	ON_BN_CLICKED(IDC_CBADDOPEN, &CDlgMPL::OnBnClickedCbaddopen)
	ON_BN_CLICKED(IDC_CBSELOPEN, &CDlgMPL::OnBnClickedCbselopen)
	ON_BN_CLICKED(IDC_CBSELDEL, &CDlgMPL::OnBnClickedCbseldel)
	ON_BN_CLICKED(IDC_CBDELALL, &CDlgMPL::OnBnClickedCbdelall)
	ON_BN_CLICKED(IDC_CBFUP, &CDlgMPL::OnBnClickedCbfup)
	ON_BN_CLICKED(IDC_CBLDOWN, &CDlgMPL::OnBnClickedCbldown)
	ON_BN_CLICKED(IDC_CBUP, &CDlgMPL::OnBnClickedCbup)
	ON_BN_CLICKED(IDC_CBDOWN, &CDlgMPL::OnBnClickedCbdown)
	ON_BN_CLICKED(IDC_CBSAVE, &CDlgMPL::OnBnClickedCbsave)
	ON_BN_CLICKED(IDC_CBOPEN, &CDlgMPL::OnBnClickedCbopen)
	ON_BN_CLICKED(IDC_CBSORT, &CDlgMPL::OnBnClickedCbsort)
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
	ON_BN_CLICKED(IDC_CHKPART, &CDlgMPL::OnBnClickedChkpart)
	ON_BN_CLICKED(IDC_CHKPLT, &CDlgMPL::OnBnClickedChkplt)
	ON_BN_CLICKED(IDC_CHKRESCALE, &CDlgMPL::OnBnClickedChkrescale)
	ON_BN_CLICKED(IDOK, &CDlgMPL::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgMPL::OnBnClickedCancel)
	ON_BN_CLICKED(IDHELP, &CDlgMPL::OnClickedIdhelp)
//	ON_WM_CLOSE()
//ON_WM_DESTROY()
//ON_WM_CLOSE()
END_MESSAGE_MAP()


// CDlgMPL 메시지 처리기입니다.


void CDlgMPL::OnBnClickedOk()
{
	SaveIni();

	MultiplePlot(FALSE);
}


void CDlgMPL::OnBnClickedCbpreview()
{
	MultiplePlot(TRUE);
}


void CDlgMPL::PlotLayout(GcDbLayout* pLayout)
{
	CString sErr;
	CString cstr;

	// units 바뀐다고 해서 추가함.. 이상함
	GetVariable(_T("INSUNITS"), iInsUnit);

	pLayout->getLayoutName(pLayName);

	GcDbLayoutManager* pLayoutManager = gcdbHostApplicationServices()->layoutManager();
	pLayoutManager->setCurrentLayout(pLayName);

	// 플롯 에러 레포팅 끈다.
	sErr = _T("플롯 레포팅 끄기 에러");

	// 자동 및 수동 축척 결정
	// 폼은 아래서 따로 계산
	sErr = _T("자동 및 수동 축척 결정 에러");
	if (tbScale.IsWindowEnabled()) {
		GetDlgItemText(IDC_TBSCALE, cstr);
		dScale = _ttof(cstr);
	}

	// get the plotsetttings class
	GcDbPlotSettingsValidator* pPlotSettingsValidator = gcdbHostApplicationServices()->plotSettingsValidator();
	pPlotSettingsValidator->refreshLists(pLayout);

	// 각종 설정
	if (optDrawing.GetCheck()) {
			//es = pPlotSettingsValidator->setPlotCfgName(pLayout, szPrinterPath);  
		pLayout->getPlotSettingsName(sPlotter);
		if (_tcsicmp(sPlotter, _T("없음")) == 0 || _tcsicmp(sPlotter, _T("none")) == 0)
			bSavePlot = FALSE;
		else
			bSavePlot = IsExistCombo(sPlotter, cboPlotter);

		if (!bSavePlot) {
			if (bActive || bModel || bSpecLayout) {
				bPlotErr = TRUE;
				LogErr(oPlotFile.Name + _T(" : 도면에 저장된 출력 설정이 없습니다."), FALSE);
				goto NextDwg;
			}
			else {
				if (iNext == iLayCnt) {
					if (!bPloted) {
						bPlotErr = TRUE;
						LogErr(oPlotFile.Name + _T(" : 도면에 저장된 출력 설정이 없습니다."), FALSE);
						goto NextDwg;
					}
				}
				goto NextLayout;
			}
		}
	}
	else {
		sErr = _T("플로터, 용지, 스타일 가져오기 에러\n스타일을 STB가 아닌 CTB 파일로 선택해 주십시오");
		.ConfigName = cboPlotter; // 플로터
		.CanonicalMediaName = sName; // 용지
		.PlotWithPlotStyles = TRUE; // 플롯 스타일 사용여부
		.PlotWithLineweights = TRUE;
		.StyleSheet = CStr(lvwDwg.ListItems(i).SubItems(1)); // 플롯 스타일


		// 혹시 몰라 시스템의 기본 플롯 스타일을 현재거로 바꾼다
		// sErr = "기본 플롯 스타일 변경 에러"
		// acPref.DefaultPlotStyleTable = CStr(lvwDwg.ListItems(i).SubItems(1))
		// PlotWithPlotStyles = TRUE;

		// 플롯 축척
		sErr = _T("플롯 축척 설정 에러");
		if (chkFitScale.GetCheck())
			.StandardScale = acScaleToFit; // 용지에 맞춤
		if (tbScale.Enabled = True)
			.SetCustomScale(1, dScale); // 지정 축척

		// 플롯 회전
		sErr = _T("플롯 회전 설정 에러");
		if (optHor)
			.PlotRotation = ac90degrees; // 가로
		else if (optVer)
			.PlotRotation = ac0degrees;

		// 플롯 중앙
		sErr = _T("플롯 중앙 설정 에러");
		if (chkPlotCenter.GetCheck())
			.CenterPlot = TRUE;
		else {
			.CenterPlot = TRUE;
			if (dVer > 16) {
				dOrigin(0) = Val(tbPlotY);
				dOrigin(1) = Val(tbPlotX);
			}
			else {
				dOrigin(0) = Val(tbPlotY);
				dOrigin(1) = Val(tbPlotX);
			}
			.PlotOrigin = dOrigin;
		}

		// Extent, Limit, Layout 출력
		if (optExtend.GetCheck())
			.PlotType = acExtents;
		else if (optLimit.GetCheck()) {
			if (bOnlyLayout || bSpecLayout)
				.PlotType = acLayout;
			else {
				if (bActive) {
					if (LCase$(.Name) != "model")
						.PlotType = acLayout;
					else
						.PlotType = acLimits;
				}
				else
					.PlotType = acLimits;
			}
		}

		// 플롯 도면 단위에 대한 출력 스케일 보정
		// 1=inch , 0 = milimeter
		sErr = _T("출력 축척 보정 에러");

		// 그냥 밀리미터로 설정하자
		.PaperUnits = acMillimeters;

		// 이건 예전코드
		if (.PaperUnits == 1)
			dCorrect = 1;
		else
			dCorrect = 25.4;
		oPlotFile.Regen(acAllViewports);
	}

	// 폼출력일때
	if (bPlotWindow) {
		// 외부참조를 전부 선택한 셀렉션 셑
		Set oSel = dll.CreateSelSet("SelSet");

		// 주어진 이름의 외부참조(블럭)를 모두 선택
		iGcode(0) = 2;
		vData(0) = sTemp;

		if (chkSelForm.GetCheck()) {
			CmdPrompt(_T("도곽(Form) 선택 :"));
			oSel.SelectOnScreen(iGcode, vData);
		}
		else
			oSel.Select(acSelectionSetAll, , , iGcode, vData);

		Set oSel = CurSpaceEnt(oSel);

		iXrefCnt = oSel.Count - 1;
		if (iXrefCnt == -1) {
			if (bActive || bModel || bSpecLayout) {
				bPlotErr = TRUE;
				LogErr(oPlotFile.Name + _T(" : 도면에 지정한 이름의 Form이 없습니다 - ") + sTemp, FALSE);
				goto NextDwg;
			}
			else {
				if (iNext == iLayCnt) {
					if (!bPloted) {
						bPlotErr = TRUE;
						LogErr(oPlotFile.Name + _T(" : 도면에 지정한 이름의 Form이 없습니다 - ") + sTemp, FALSE);
						goto NextDwg;
					}
				}
				goto NextLayout;
			}
		}

		// 외부참조1개 이상시 인서트 포인트로 소트
		sErr = _T("Form Sort 에러");
		if (iXrefCnt > 0) {
			if (!chkReverse) {
				if (optSortLR.GetCheck())
					func.SortSelZ(oSel, _ttof(tbTol), dTwAng);
				else if (optSortLU.GetCheck())
					func.SortSelN(oSel, _ttof(tbTol), dTwAng);
				else if (optSortLD.GetCheck())
					func.SortSelIN(oSel, _ttof(tbTol), dTwAng);
				else
					func.SortSelIZ(oSel, _ttof(tbTol), dTwAng);
			}
			else {
				// 역순인쇄
				if (optSortLR.GetCheck())
					func.SortSelZ_R(oSel, _ttof(tbTol), dTwAng);
				else if (optSortLU.GetCheck())
					func.SortSelN_R(oSel, _ttof(tbTol), dTwAng);
				else if (optSortLD.GetCheck())
					func.SortSelIN_R(oSel, _ttof(tbTol), dTwAng);
				else
					func.SortSelIZ_R(oSel, _ttof(tbTol), dTwAng);
			}
		}

		sErr = _T("일부 출력 입력 에러");
		iPartS = CInt(Val(tbPartS));
		iPartE = CInt(Val(tbPartE));

		// 한도면 내의 여러 폼 순환**************************************
		if (chkPLT.GetCheck())
			sPLT = tbPLT + sFileName;
		for (k = 0; k < iXrefCnt; k ++) {
			sFormName = oSel.Item(k).Name;
			iIniPos = GetFormIniPos(sFormName);

			// 폼별 설정
			bRealVert = ini.ReadIni(sPubPath, "MPL", "RealVertical" & iIniPos, False)
			dPaperH = Abs(.ReadIni(sPubPath, "MPL", "PaperHeight" & iIniPos, 594))
			dYHeight = Abs(.ReadIni(sPubPath, "MPL", "Height" & iIniPos, 594))
			dXWidth = Abs(.ReadIni(sPubPath, "MPL", "Width" & iIniPos, 841))
			dMin(0) = .ReadIni(sPubPath, "MPL", "FromMinX" & iIniPos, 0)
			dMin(1) = .ReadIni(sPubPath, "MPL", "FromMinY" & iIniPos, 0)
			dMax(0) = .ReadIni(sPubPath, "MPL", "FromMaxX" & iIniPos, 841)
			dMax(1) = .ReadIni(sPubPath, "MPL", "FromMaxY" & iIniPos, 594)
			bVertical = ini.ReadIni(sPubPath, "MPL", "IsVertical" & iIniPos, False)
			if (tbScale.Enabled = False)
				dScale = GetPlotScaleByA1(dPaperH, bVertical);

			// 출력 취소 폼에서 취소 반환되면 현재 도면 취소
			if (bMPLCancel || bMPLExit)
				break;

			if (chkPart.GetCheck()) {
				if ((k + 1) < iPartS)
					goto NextPart;
				if ((k + 1) > iPartE)
					break;
			}

			if (bUCS) {
				//With oSel.Item(k)
				if (dTwAng != 0)
					.Rotate(dZero, dTwAng);
				bRotate = IsVerDwg(.Rotation); // false = 가로도면
				.GetBoundingBox(vMin, vMax);
				dSelVer = vMax(1) - vMin(1);
				dSelHor = vMax(0) - vMin(0);
				if (dTwAng != 0)
					.Rotate(dZero, -dTwAng);
				vMin = .PointRotateByBase(dZero, vMin, -dTwAng);
				vMax = .PointRotateByBase(dZero, vMax, -dTwAng);
			}
			else {
				//With oSel.Item(k)
				.GetBoundingBox(vMin, vMax);
				bRotate = IsVerDwg(.Rotation); // false = 가로도면
				dSelVer = vMax(1) - vMin(1);
				dSelHor = vMax(0) - vMin(0);
			}

			vMin = ToDCS(vMin);
			vMax = ToDCS(vMax);

			dZoomMin(0) = vMin(0);
			dZoomMin(1) = vMin(1);
			dZoomMin(2) = 0.0;
			dZoomMax(0) = vMax(0);
			dZoomMax(1) = vMax(1);
			dZoomMax(2) = 0.0;

			if (!bUCS)
				ZoomWindow(dZoomMin, dZoomMax);

			// 원래 폼이 세로 도면이면 가로 세로 뒤집는다
			if (bRealVert)
				bRotate = !bRotate;

			// 지정한 폼과 현재 폼과의 크기차이
			if (!bRotate) { // 회전 안된 도면
				if (bVertical) {
					dDiff = dSelVer / dXWidth;
					// 출력할 윈도우(Two Array)
					dPlotMin(0) = vMin(0) + dMin(0) * dDiff;
					dPlotMin(1) = vMin(1) + dMin(1) * dDiff;
					dPlotMax(0) = vMin(0) + dMax(1) * dDiff;
					dPlotMax(1) = vMin(1) + dMax(0) * dDiff;
				}
				else {
					dDiff = dSelVer / dYHeight;
					dPlotMin(0) = vMin(0) + dMin(0) * dDiff;
					dPlotMin(1) = vMin(1) + dMin(1) * dDiff;
					dPlotMax(0) = vMin(0) + dMax(0) * dDiff;
					dPlotMax(1) = vMin(1) + dMax(1) * dDiff;
				}
				if (optAuto.GetCheck()) {
					if (bHorPaper)
						pLayout.PlotRotation = ac0degrees;
					else
						pLayout.PlotRotation = ac90degrees;
				}
			}
			else {
				if (bVertical) {
					dDiff = dSelVer / dYHeight;
					dPlotMin(0) = vMin(0) + dMin(0) * dDiff;
					dPlotMin(1) = vMin(1) + dMin(1) * dDiff;
					dPlotMax(0) = vMin(0) + dMax(0) * dDiff;
					dPlotMax(1) = vMin(1) + dMax(1) * dDiff;
				}
				else {
					dDiff = dSelVer / dXWidth;
					dPlotMin(0) = vMin(0) + dMin(0) * dDiff;
					dPlotMin(1) = vMin(1) + dMin(1) * dDiff;
					dPlotMax(0) = vMin(0) + dMax(1) * dDiff;
					dPlotMax(1) = vMin(1) + dMax(0) * dDiff;
				}
				if (optAuto.GetCheck()) {
					if (bHorPaper)
						pLayout.PlotRotation = ac90degrees;
					else
						pLayout.PlotRotation = ac0degrees;
				}
			}

			//With pLayout
			// 윈도우설정.PlotType을 SetWindowToPlot 뒤에 써줘야 함
			.SetWindowToPlot(dPlotMin, dPlotMax);
			.PlotType = acWindow;

			// 폼이 여러개인 경우가 있으므로 폼출력은 순환하면서 아래를 거쳐야 한다.
			sErr = _T("Form 맞춤 에러");
			if (chkFitScale.GetCheck()) // 용지에 맞춤
				.StandardScale = acScaleToFit;
			else if (chkAutoScaleA1.GetCheck()) // 자동 맞춤(A1기준)
				.SetCustomScale(1, dScale * dDiff * dCorrect * dReScale);
			else // 지정한 축척
				.SetCustomScale(1, dScale * dDiff * dReScale);

			//With oPlotFile.Plot
			if (chkCopy.GetCheck())
				.NumberOfCopies = 1;
			else
				.NumberOfCopies = GetDlgItemInt(IDC_TBPLOTCNT); // 플롯 매수

			if (bSelPreview) {
				.DisplayPlotPreview(acFullPreview); // 플롯 미리보기
				bPloted = TRUE;
			}
			else {
				if (chkPreviw.GetCheck()) {
					sErr = _T("플롯 미리보기 에러");
					.DisplayPlotPreview(acFullPreview); // '플롯 미리보기
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

						if (InStr(cboPlotter.Text, "jpg") >= 0)
							.PlotToFile(sPLT + "-" + iFileNum + ".jpg");
						else if (InStr(cboPlotter.Text, "png") >= 0)
							.PlotToFile(sPLT + "-" + iFileNum + ".png");
						else if (InStr(cboPlotter.Text, "pdf") >= 0)
							.PlotToFile(sPLT + "-" + iFileNum + ".pdf");
						else
							.PlotToFile(sPLT + "-" + iFileNum + ".plt");
					}
					else
						.PlotToDevice(cboPlotter); // 플롯
					bPloted = TRUE;
				}
			}
			SetDelay (GetDlgItemInt(IDC_TBDELAY));
NextPart:
		// next k, End of 한도면내의 여러폼*********************************
		}
		goto NextDwg;
	} // End of 폼출력

	if (bMPLCancel || bMPLExit)
		break;
	// 윈도우 출력일
	if (optWindow.GetCheck()) {
		bWinUser = m_regEdit.GetBoolean(_T("MPL"), _T("WinUser"), FALSE);

		// 사용자가 윈도우 선택
		if (bWinUser) {
			sErr = _T("인쇄 영역 선택 에러");
			//With thisDrawing.Utility
			vSpnt = .GetPoint(, _T("인쇄할 영역의 첫번째 모서리 점 지정:"))
			if (IsEmpty(vSpnt)) {
				Me.Show 0;
				return;
			}

			.InitializeUserInput(32);
			vEpnt = .GetCorner(vSpnt, _T("인쇄할 영역의 두번째 모서리 점 지정:"));
			if (IsEmpty(vEpnt)) {
				Me.Show 0;
				return;
			}

			vSpnt = ToDCS(vSpnt);
			vEpnt = ToDCS(vEpnt);

			if (vEpnt(2) < vSpnt(2))
				SwapVoidData(vSpnt, vEpnt, sizeof());

			dPlotMin(0) = vSpnt(0);
			dPlotMin(1) = vSpnt(1);
			dPlotMax(0) = vEpnt(0);
			dPlotMax(1) = vEpnt(1);
		}
		else { // 지정한 윈도우
			sErr = _T("지정 윈도우 에러");
			//With ini
			dPlotMin(0) = m_regEdit.GetString(_T("MPL"), _T("WinMinX"), _T("0"));
			dPlotMin(1) = m_regEdit.GetString(_T("MPL"), _T("WinMinY"), _T("0"));
			dPlotMax(0) = m_regEdit.GetString(_T("MPL"), _T("WinMaxX"), _T("841"));
			dPlotMax(1) = m_regEdit.GetString(_T("MPL"), _T("WinMaxY"), _T("594"));
			vSpnt = ZeroPoint;
			vEpnt = ZeroPoint;
			vSpnt(0) = dPlotMin(0);
			vSpnt(1) = dPlotMin(1);
			vEpnt(0) = dPlotMax(0);
			vEpnt(1) = dPlotMax(1);
			vSpnt = ToDCS(ToWCS(vSpnt));
			vEpnt = ToDCS(ToWCS(vEpnt));
			dPlotMin(0) = vSpnt(0);
			dPlotMin(1) = vSpnt(1);
			dPlotMax(0) = vEpnt(0);
			dPlotMax(1) = vEpnt(1);
		}

		//With pLayout
		sErr = _T("윈도우 출력 에러");
		.SetWindowToPlot(dPlotMin, dPlotMax);
		.PlotType = acWindow;
	} // End of 윈도우출력

	// 일반출력 공통(폼 제외)
	if (!bPlotWindow) {
		if (!optDrawing.GetCheck()) {
			//With pLayout
			sErr = _T("공통 출력 맞춤 에러");
			// 용지에 맞춤
			if (chkFitScale.GetCheck())
				.StandardScale = acScaleToFit;
			// 자동 맞춤(A1기준)
			else if (chkAutoScaleA1.GetCheck())
				.SetCustomScale(1, dScale * dDiff * dCorrect * dReScale);
			// 지정한 축척
			else
				.SetCustomScale(1, dScale * dDiff * dReScale);
		}
		//With oPlotFile.Plot
		if (chkCopy.GetCheck())
			.NumberOfCopies = 1;
		else
			.NumberOfCopies = GetDlgItemInt(IDC_TBPLOTCNT); // 플롯 매수

		if (bSelPreview) {
			.DisplayPlotPreview acFullPreview; // 플롯 미리보기
			bPloted = TRUE;
		}
		else {
			if (chkPreviw.GetCheck()) {
				sErr = _T("공통 출력 미리보기 에러");
				.DisplayPlotPreview(acFullPreview); // 플롯 미리보기
				bPloted = TRUE;
			}
			else {
				sErr = _T("공통 출력 플롯 에러");
				if (chkPLT.GetCheck())
					.PlotToFile(tbPLT);
				else {
					if (!optDrawing.GetCheck())
						.PlotToDevice(cboPlotter); // 플롯
					else
						.PlotToDevice();
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

	pLayout.PaperUnits = acMillimeters;
	SetVariable(_T("INSUNITS"), iInsUnit);

}


void CDlgMPL::MultiplePlot(BOOL bSelPreview)
{
	CString sPlotterName;
	CString cstr;

	SetVariable(_T("cmdecho"), 1);

	GetComboText(&cboPlotter, sPlotterName);
	sPlotterName.MakeUpper();

	if (!bSelPreview) {
		if (sPlotterName.Find(_T("PUBLISHTOWEB")) >= 0) {
			if (!chkPLT.GetCheck()) {
				if (!chkPreviw.GetCheck()) {
					AfxMessageBox(_T("그림 파일로 출력하려면 [파일로 플롯]에 체크해 주십시오"), MB_OK | MB_ICONINFORMATION);
					chkPLT.SetFocus();
					return;
				}
			}
		}
		if (sPlotterName.Find(_T("DWG TO PDF")) >= 0) {
			if (!chkPLT.GetCheck()) {
				if (!chkPreviw.GetCheck()) {
					AfxMessageBox(_T("PDF 파일로 출력하려면 [파일로 플롯]에 체크해 주십시오"), MB_OK | MB_ICONINFORMATION);
					chkPLT.SetFocus();
					return;
				}
			}
		}
		if (sPlotterName.Find(_T("DWF6 EPLOT")) >= 0 || sPlotterName.Find(_T("DWFX EPLOT")) >= 0) {
			if (!chkPLT.GetCheck()) {
				if (!chkPreviw.GetCheck()) {
					AfxMessageBox(_T("DWF 파일로 출력하려면 [파일로 플롯]에 체크해 주십시오"), MB_OK | MB_ICONINFORMATION);
					chkPLT.SetFocus();
					return;
				}
			}
		}
	}

	if (lvwDwg.GetItemCount() < 1) {
		AfxMessageBox(_T("목록에 출력할 도면이 없습니다"), MB_OK | MB_ICONINFORMATION);
		return;
	}

	GetComboText(&cboPlotter, cstr);
	if (cstr.CompareNoCase(_T("없음")) == 0 || cstr.CompareNoCase(_T("none")) == 0) {
		if (!optDrawing.GetCheck()) {
			AfxMessageBox(_T("출력할 플로터를 선택하여 주십시오"), MB_OK | MB_ICONINFORMATION);
			return;
		}
	}

	GetComboText(&cboPaper, cstr);
	if (cstr.CompareNoCase(_T("없음")) == 0 || cstr.CompareNoCase(_T("none")) == 0) {
		if (!optDrawing.GetCheck()) {
			AfxMessageBox(_T("출력할 용지를 선택하여 주십시오"), MB_OK | MB_ICONINFORMATION);
			return;
		}
	}

	if (!bSelPreview) {
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

	CString sTemp;
	if (optForm.GetCheck()) {
		sTemp = m_regEdit.GetString(_T("MPL"), _T("AddFormList"), _T(""));
		if (sTemp == _T("")) {
			AfxMessageBox(_T("등록된 Form(도곽)이 없습니다\n[Form 등록] 버튼을 눌러 Form을 추가해 주십시오"), MB_OK | MB_ICONINFORMATION);
			cbForm.SetFocus();
			return;
		}
	}

	tbTol.GetWindowTextW(cstr);
	if (cstr == _T("") || _ttof(cstr) <= 0) {
		AfxMessageBox(_T("Form 정렬 오차값을 0 이상 지정해주십시오"), MB_OK | MB_ICONINFORMATION);
		tbTol.SetFocus();
		return;
	}

	if (GetDlgItemInt(IDC_TBPLOTCNT) < 1)
		SetDlgItemInt(IDC_TBPLOTCNT, 1);
	if (chkPLT.GetCheck()) {
		if (!chkPreviw.GetCheck())
			SetDlgItemInt(IDC_TBPLOTCNT, 1);
	}
	if (GetDlgItemInt(IDC_TBDELAY) < 0)
		SetDlgItemInt(IDC_TBDELAY, 0);

	//BeginEditorCommand();
	ShowWindow(SW_HIDE);

	BOOL bModel;
	BOOL bOnlyLayout;
	BOOL bModel_Lay;
	BOOL bSpecLayout;
	int iLayCnt;
	int iNext; // 레이아웃 순환용
	double dReScale;

	bActive = optActive.GetCheck();
	bModel = optModel.GetCheck();
	bOnlyLayout = optOnlyLayout.GetCheck();
	bModel_Lay = optModelLayout.GetCheck();
	bSpecLayout = optSpecLayout.GetCheck();

	// 축척 미세 조정
	if (chkReScale.GetCheck()) {
		tbReScale.GetWindowTextW(cstr);
		if (_ttof(cstr) == 0)
			dReScale = 1.0;
		else
			dReScale = 100.0 / _ttof(cstr);
	}
	else
		dReScale = 1.0;

	// 메세지 제어
	int iExpert;
	int iDwgCheck;
	GetVariable(_T("EXPERT"), iExpert);
	if (iExpert == 0)
		SetVariable(_T("EXPERT"), 1);

	GetVariable(_T("DWGCHECK"), iDwgCheck);
	if (iDwgCheck == 1)
		SetVariable(_T("DWGCHECK"), 0);

	// get current layout
	gcdbOpenObject(oLayout, gcdbHostApplicationServices()->workingDatabase()->currentLayoutId(), GcDb::kForRead);
	//Set acPref = .Application.Preferences.Output

	// 취소폼 띄운다.
	CDlgMPLExit dlgExit(this);
	dlgExit.Create(CDlgMPL::IDD);
	dlgExit.ShowWindow(SW_SHOWNORMAL);

	CString sErr;
	// 도면에 설정된 저장대로가 아니면
	if (!optDrawing.GetCheck()) {
		// 용지를 실제인식가능한 용지(UserXXX)로 다시 변경
		// 모든 용지 종류 얻어서
		sErr = _T("용지 종류 가져오기 에러");

		// 용지를 순환하면서 각 요소의 이름과 용지 콤보박스내용과 비교해서 맞으면 실제용지로 설정
		GcArray<const TCHAR*> sPaper;
		//CStringArray sPaper;
		CString sName;
		CString vElement;
		CString sSelPaper;
		const GCHAR* localName;
		int i;
		int iCnt;

		GetComboText(&cboPaper, sSelPaper);

		pPSV->refreshLists(pPlotSettings);
		pPSV->canonicalMediaNameList(pPlotSettings, sPaper);
		//sPaper = oLayout.GetCanonicalMediaNames()
		iCnt = sPaper.length();
		for (i = 0; i < iCnt; i ++) {
			pPSV->getLocaleMediaName(pPlotSettings, sPaper[i], localName);
			if (sSelPaper.CompareNoCase(localName) == 0) {
				sName = sPaper[i];
				break;
			}
		}

		// 폼출력시 사용할 가로/세로 용지 판단
		// 플로터로 보낼때 가로 용지는 0Degrees 로 보내야한다
		BOOL bHorPaper;
		double dX;
		double dY;
		// 용지 가로 세로를 판단하기위해 먼저 레이아웃에 용지 설정
		pPSV->setPlotCfgName(pPlotSettings, sPlotterName); // 플로터
		pPSV->setCanonicalMediaName(pPlotSettings, sName); // 용지
		pPlotSettings->getPlotPaperSize(dX, dY);
		if (dX >= dY)
			bHorPaper = TRUE;
		else
			bHorPaper = FALSE;

		// 폼 설정 가져옴
		// 폼을 여러개 가져오는 것으로 고친 후 이름 제외 나머지는 For~Next 구문안으로 이동했음
		double dPaperH;
		double dYHeight;
		double dXWidth;
		double dMin[2];
		double dMax[2];

		sErr = _T("Form 이름 가져오기 에러");
		sTemp = m_regEdit.GetString(_T("MPL"), _T("AddFormList"), _T(""));
	}

	// 폼 출력이면 나중에 따로 처리하도록
	BOOL bPlotWindow;
	if (optForm.GetCheck())
		bPlotWindow = TRUE;
	else
		bPlotWindow = FALSE;

	// 지정한 폼과 현재 폼과의 크기차이
	// 폼을 위한 것이므로 폼을 제외한 나머지 출력은 1로 설정
	// 폼의 경우는 폼 출력 부분에서 따로 계산
	double dDiff;
	dDiff = 1;

	// 캐드 버전 얻는다.
	sErr = _T("AutoCAD 버전 가져오기 에러");
	double dVer;
	//dVer = CDbl(Left$(thisDrawing.Application.Version, 4))
	dVer = 16;

	BOOL bOpen; // 열려 있는 도면인지 검사용
	BOOL bPlotErr; // 폼출력시 폼 없는 에러 검사용

	bPlotErr = FALSE;
	CStringArray sLog; // 폼출력 에러시 폼 없는 도면 목록 담기

	int iInsUnit;
	BOOL bMPLCancel;
	BOOL bMPLExit;
	// 출력 취소 값 초기화
	bMPLCancel = FALSE;
	bMPLExit = FALSE;

	CString sDwg;
	GcApDocument* oPlotFile;
	GCHAR *pLayName;
	GcDbLayout* pLayout;
	BOOL bVertical;
	double dOrigin[2];
	double dCorrect;
	//Dim oSel		As GcadSelectionSet
	long iXrefCnt;
	GcGePoint3d vMin;
	GcGePoint3d vMax;
	double dPlotMin[2];
	double dPlotMax[2];
	double dZoomMin[3];
	double dZoomMax[3];
	int iPartS;
	int iPartE;
	int k;
	CString sPLT;
	double dSelVer;
	double dSelHor;
	BOOL bWinUser;
	GcGePoint3d vSpnt;
	GcGePoint3d vEpnt;
	int iGcode[1];
	Dim vData[1]	As Variant;
	GcGePoint3d dZero;
	double dTwAng;
	BOOL bUCS;
	BOOL bDview;
	CString sFileName; // 파일 출력용
	int iFileNum; // 파일 출력용
	BOOL bPloted; // '여러 도면 순환시 한번이라도 출력되었으면 true => 에러표시 방지
	const GCHAR * sPlotter; // 도면에 저장된 플로터

	int iCopy; // 인쇄매수 순환용
	int iCopyNum; // 인쇄매수 값

	double dScale;
	BOOL bSavePlot; // 도면에 저장된 설정대로 에러용
	BOOL bRotate; // 폼이 가로인가?
	BOOL bRealVert; // 폼자체가 원래 세로
	const TCHAR* sFormName; // 셀셑의 현재 선택한 폼 이름
	int iIniPos; // ini의 폼 이름 위치
	long lngReply;

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

	int i;
	int iCnt;
	for (iCopy = 0; iCopy < iCopyNum; iCopy ++) {
		// 미리보기면 한번 실행 후 종료
		if (bSelPreview)
			iCopy = iCopyNum;

		iCnt = lvwDwg.GetItemCount();
		for (i = 0; i < iCnt; i ++) {
			// 미리보기면 선택한 아이템으로 지정
			if (bSelPreview) {
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
			sDwg = lvwDwg.GetItemText(i, 2) + sFileName;
			int loc = sFileName.ReverseFind('.');
			if (loc >= 0)
				sFileName = sFileName.Right(sFileName.GetLength() - loc);

			// 도면이 열려있는 경우면 다시 열지 말고 열린 도면 사용
			// 리스트의 도면을 열고
			sErr = _T("리스트 도면 열기 에러");
			oPlotFile = FindOpenDwg(sDwg);
			if (oPlotFile == NULL) {
				OpenDwgFile(sDwg);
				oPlotFile = FindOpenDwg(sDwg);
				if (oPlotFile == NULL) {
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
				gcDocManager->activateDocument(oPlotFile);
				bOpen = TRUE;
			}

			//iLayCnt = oPlotFile.Layouts.Count;
			dTwAng = -GetTWAng();
			if (!IsWCS())
				bUCS = TRUE;
			else {
				if (dTwAng != 0) {
					bDview = TRUE;
					SetViewUcs(TRUE);
					bUCS = TRUE;
				}
			}

			GcDbLayoutManager* pLayoutManager = gcdbHostApplicationServices()->layoutManager();

			GcDbDictionary *pDict = NULL;
			gcdbHostApplicationServices()->workingDatabase()->getLayoutDictionary(pDict, GcDb::kForRead);

			GcDbDictionaryIterator *pIter = pDict->newIterator();
			GcDbObject *pObj;
			const TCHAR* pLayName;

////////////////////////////////////////////////////////////////////////////////
			// 레이아웃 순환됨
			//Iterate through all the items in the dictionary
			for (; !pIter->done(); pIter->next()) {
				//With oPlotFile
				// units 바뀐다고 해서 추가함.. 이상함
				GetVariable(_T("INSUNITS"), iInsUnit);

				// 플롯할 도면의 레이아웃으로 재설정
				if (bActive) {
					// Active Layout
					const GCHAR* layoutName = pLayoutManager->findActiveLayout(true);
					// get the current layout
					pLayout = pLayoutManager->findLayoutNamed(layoutName, true);

					// Active Layout
					GcDbLayoutManager* pLayoutManager = gcdbHostApplicationServices()->layoutManager(); 
					GcDbObjectId btrId = pLayoutManager->getActiveLayoutBTRId();
					GcDbBlockTableRecord* pBTR;
					gcdbOpenObject(pBTR, btrId, GcDb::kForRead);
					GcDbObjectId layoutId = pBTR->getLayoutId();
					gcdbOpenObject(pLayout, layoutId, GcDb::kForRead);
				}
				else {
					pIter->getObject(pObj,GcDb::kForRead);
					GcDbLayout *pLayout = GcDbLayout::cast(pObj);
					pLayout->getLayoutName(pLayName);

					// 옵션에따라 레이아웃 검사
					if (bModel) {
						// get the model layout
						if (_tcsicmp(pLayName, _T("model")) != 0)
							goto NextLayout;
					}
					else if (bOnlyLayout) {
						if (_tcsicmp(pLayName, _T("model")) == 0)
							goto NextLayout;
					}
					else if (bModel_Lay) {
						// 그냥 진행
					}
					else if (bSpecLayout) {
						GetDlgItemText(IDC_TBLAYOUT, cstr);
						pLayout = pLayoutManager->findLayoutNamed(cstr, true);
					}
				}

				pLayoutManager->setCurrentLayout(pLayName);

				// 플롯 에러 레포팅 끈다.
				sErr = _T("플롯 레포팅 끄기 에러");
				//.Plot.QuietErrorMode = False

				// 자동 및 수동 축척 결정
				// 폼은 아래서 따로 계산
				sErr = _T("자동 및 수동 축척 결정 에러");
				if (tbScale.IsWindowEnabled()) {
					GetDlgItemText(IDC_TBSCALE, cstr);
					dScale = _ttof(cstr);;
				}

				// 각종 설정
				if (optDrawing.GetCheck()) {
					pLayout->getPlotSettingsName(sPlotter);
					if (_tcsicmp(sPlotter, _T("없음")) == 0 || _tcsicmp(sPlotter, _T("none")) == 0)
						bSavePlot = FALSE;
					else
						bSavePlot = IsExistCombo(sPlotter, cboPlotter);

					if (!bSavePlot) {
						if (bActive || bModel || bSpecLayout) {
							bPlotErr = TRUE;
							LogErr(oPlotFile->fileName() + _T(" : 도면에 저장된 출력 설정이 없습니다."), FALSE);
							goto NextDwg;
						}
						else {
							if (pIter->done()) { // iNext = iLayCnt
								if (!bPloted) {
									bPlotErr = TRUE;
									LogErr(oPlotFile->fileName() + _T(" : 도면에 저장된 출력 설정이 없습니다."), FALSE);
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
					es = pPSV->setPlotCfgName(pPlotSettings, cstr);
					//.ConfigName = cboPlotter    '플로터
					//.CanonicalMediaName = sName '용지
					//.PlotWithPlotStyles = True  '플롯 스타일 사용여부
					//.PlotWithLineweights = True
					//.StyleSheet = CStr(lvwDwg.ListItems(i).SubItems(1)) '플롯 스타일

					// 혹시 몰라 시스템의 기본 플롯 스타일을 현재거로 바꾼다
					// sErr = "기본 플롯 스타일 변경 에러"
					// acPref.DefaultPlotStyleTable = CStr(lvwDwg.ListItems(i).SubItems(1))
					// .PlotWithPlotStyles = True

					// 플롯 축척
					sErr = _T("플롯 축척 설정 에러");
					if (chkFitScale.GetCheck()) {
						es = pPSV->setUseStandardScale(pPlotSettings, ::kTrue);
						es = pPSV->setStdScaleType(pPlotSettings, GcDbPlotSettings::StdScaleType::kScaleToFit); // 용지에 맞춤
					}
					if (tbScale.IsWindowEnabled()) {
						es = pPSV->setUseStandardScale(pPlotSettings, ::kFalse);
						es = pPSV->setCustomPrintScale(pPlotSettings, 1, dScale); // 지정 축척
					}

					// 플롯 회전
					sErr = _T("플롯 회전 설정 에러");
					if (optHor.GetCheck())
						pPSV->setPlotRotation(pPlotSettings, GcDbPlotSettings::PlotRotation::k90degrees);
					else if (optVer.GetCheck())
						pPSV->setPlotRotation(pPlotSettings, GcDbPlotSettings::PlotRotation::k0degrees);

					// 플롯 중앙
					sErr = _T("플롯 중앙 설정 에러");
					if (chkPlotCenter.GetCheck())
						pPSV->setPlotCentered(pPlotSettings, true);
					else {
						double oX, oY;
						pPSV->setPlotCentered(pPlotSettings, false);
						GetDlgItemText(IDC_TBPLOTX, cstr);
						oX = _ttof(cstr);
						GetDlgItemText(IDC_TBPLOTY, cstr);
						oY = _ttof(cstr);
						pPSV->setPlotOrigin(pPlotSettings, oX, oY);
					}

					// Extent, Limit, Layout 출력
					if (optExtend.GetCheck())
						pPSV->setPlotType(pPlotSettings, GcDbPlotSettings::kExtents);
					else if (optLimit.GetCheck()) {
						if (bOnlyLayout || bSpecLayout)
							pPSV->setPlotType(pPlotSettings, GcDbPlotSettings::kLayout);
						else {
							if (bActive) {
								if (_tcsicmp(pLayName, _T("model")) != 0)
									pPSV->setPlotType(pPlotSettings, GcDbPlotSettings::kLayout);
								else
									pPSV->setPlotType(pPlotSettings, GcDbPlotSettings::kLimits);
							}
							else
								pPSV->setPlotType(pPlotSettings, GcDbPlotSettings::kLimits);
						}
					}

					// 플롯 도면 단위에 대한 출력 스케일 보정
					// 1=inch , 0 = milimeter
					sErr = _T("출력 축척 보정 에러");

					// 그냥 밀리미터로 설정하자
					pPSV->setPlotPaperUnits(pPlotSettings, GcDbPlotSettings::kMillimeters);

					// 이건 예전코드
					//If .PaperUnits = 1 Then
					//	dCorrect = 1
					//Else
					//	dCorrect = 25.4
					//End If
					//oPlotFile.Regen acAllViewports
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

							gcedSSAdd(NULL, ssname, ssname);
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
							LogErr(oPlotFile.Name + _T(" : 도면에 지정한 이름의 Form이 없습니다 - ") + sTemp, FALSE);
							goto NextDwg;
						}
						else {
							if (iNext == iLayCnt) {
								if (!bPloted) {
									bPlotErr = TRUE;
									LogErr(oPlotFile.Name + _T(" : 도면에 지정한 이름의 Form이 없습니다 - ") + sTemp, FALSE);
									goto NextDwg;
								}
							}
							goto NextLayout;
						}
					}

					double dtol;
					GetDlgItemText(IDC_TBTOL, cstr);
					dtol = _ttof(cstr);
					// 외부참조1개 이상시 인서트 포인트로 소트
					sErr = _T("Form Sort 에러");
					if (iXrefCnt > 0) {
						if (!chkReverse) {
							if (optSortLR.GetCheck())
								SortSelZ(ssname, dtol, dTwAng);
							else if (optSortLU.GetCheck())
								SortSelN(ssname, dtol, dTwAng);
							else if (optSortLD.GetCheck())
								SortSelIN(ssname, dtol, dTwAng);
							else
								SortSelIZ(ssname, dtol, dTwAng);
						}
						else {
							// 역순인쇄
							if (optSortLR.GetCheck())
								SortSelZ_R(ssname, dtol, dTwAng);
							else if (optSortLU.GetCheck())
								SortSelN_R(ssname, dtol, dTwAng);
							else if (optSortLD.GetCheck())
								SortSelIN_R(ssname, dtol, dTwAng);
							else
								SortSelIZ_R(ssname, dtol, dTwAng);
						}
					}

					sErr = _T("일부 출력 입력 에러");
					iPartS = GetDlgItemInt(IDC_TBPARTS);
					iPartE = GetDlgItemInt(IDC_TBPARTE);

					// 한도면 내의 여러 폼 순환
					if (chkPLT.GetCheck()) {
						GetDlgItemText(IDC_TBPLT, cstr);
						sPLT = cstr & sFileName;
					}
					for(k = 0; k ++; k < iXrefCnt) {
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
						if (bMPLCancle || bMPLExit)
							break;

						if (chkPart.GetCheck()) {
							if ((k + 1) < iPartS)
								goto NextPart;
							if ((k + 1) > iPartE)
								break;
						}

						GcDbExtents extents;
						if (bUCS) {
							//With oSel.Item(k)
							if (dTwAng != 0)
								Rotate(dZero, dTwAng);
							bRotate = IsVerDwg(pInsert->rotation()); // false = 가로도면
							pInsert->geomExtentsBestFit(extents);
							vMin = extents.minPoint();
							vMax = extents.maxPoint();
							dSelVer = vMax[Y] - vMin[Y];
							dSelHor = vMax[X] - vMin[X];
							if (dTwAng != 0)
								Rotate(dZero, -dTwAng);
							vMin = .PointRotateByBase(dZero, vMin, -dTwAng);
							vMax = .PointRotateByBase(dZero, vMax, -dTwAng);
						}
						else {
							//With oSel.Item(k)
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
							ZoomWindow(dZoomMin, dZoomMax);

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
								dPlotMax[X] = vMin[X] + dMax[X] * dDiff;
								dPlotMax[Y] = vMin[Y] + dMax[Y] * dDiff;
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
									pPSV->setPlotRotation(pPlotSettings, GcDbPlotSettings::PlotRotation::k0degrees);
								else
									pPSV->setPlotRotation(pPlotSettings, GcDbPlotSettings::PlotRotation::k90degrees);
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
									pPSV->setPlotRotation(pPlotSettings, GcDbPlotSettings::PlotRotation::k90degrees);
								else
									pPSV->setPlotRotation(pPlotSettings, GcDbPlotSettings::PlotRotation::k0degrees);
							}
						}

						//With oLayout
						// 윈도우설정.PlotType을 SetWindowToPlot 뒤에 써줘야 함
						pPSV->setPlotWindowArea(pPlotSettings, dPlotMin[X], dPlotMin[Y], dPlotMax[X], dPlotMax[Y]);
						pPSV->setPlotType(pPlotSettings, GcDbPlotSettings::kWindow);

						// '폼이 여러개인 경우가 있으므로 폼출력은 순환하면서 아래를 거쳐야 한다.
						sErr = _T("Form 맞춤 에러");
						if (chkFitScale.GetCheck()) // 용지에 맞춤
							pPSV->setStdScaleType(pPlotSettings, GcDbPlotSettings::StdScaleType::kScaleToFit);
						else if (chkAutoScaleA1.GetCheck()) // 자동 맞춤(A1기준)
							pPSV->setCustomPrintScale(pPlotSettings, 1, dScale * dDiff * dCorrect * dReScale);
						else // 지정한 축척
							pPSV->setCustomPrintScale(pPlotSettings, 1, dScale * dDiff * dReScale);

						//With oPlotFile.Plot
						//if (chkCopy.GetCheck())
						//	oPlotFile->NumberOfCopies = 1;
						//else
						//	pPlotSettings->NumberOfCopies = GetDlgItemInt(IDC_TBPLOTCNT); // 플롯 매수

						if (bSelPreview) {
							GcPlPlotEngine* pEngine = NULL;
							if(Gcad::eOk == GcPlPlotFactory::createPreviewEngine(pEngine)) {
								pEngine->beginPlot(NULL);

								GcPlPlotPageInfo pageInfo;
								GcPlPlotInfo plotInfo;

								plotInfo.setLayout(pLayout);

								plotInfo.setOverrideSettings(pPlotSettings);

								GcPlPlotInfoValidator validator;
								validator.setMediaMatchingPolicy(GcPlPlotInfoValidator::kMatchEnabled);
								es = validator.validate(plotInfo);

								const TCHAR *szDocName = oPlotFile->fileName();

								es = pEngine->beginDocument(plotInfo, szDocName);
								es = pEngine->beginPage(pageInfo, plotInfo, true);
								es = pEngine->beginGenerateGraphics();
								es = pEngine->endGenerateGraphics();
								es = pEngine->endPage();
								es = pEngine->endDocument();
								es = pEngine->endPlot();

								pEngine->destroy();
								pEngine = NULL;
							}
							else
								AfxMessageBox(_T("Plot Engine is Busy..."));


							.DisplayPlotPreview acFullPreview; // 플롯 미리보기
							bPloted = TRUE;
						}
						else {
							If chkPreviw = True Then
								sErr = "플롯 미리보기 에러"
								.DisplayPlotPreview acFullPreview '플롯 미리보기
								bPloted = True
							Else
								sErr = "플롯 에러"
								If chkPLT Then
									'모델인 경우 모델하나에 도곽이 여러개면 아래에서 도곽 개수인 k로 출력시
									'번호가 다르게 나오지만 배치인경우 배치하나당 폼이 하나면
									'아래 k로 출력하는 경우 배치 하나당 폼이 한개라 k는 계속 0 이됨
									'따라서 iFileNum 변수를 두고
									'모델인 경우는 k 값 그냥 사용
									'배치인 경우는 iFileNum 증분해서 값을 다르게 한다
									If bActive Or bModel Then
										iFileNum = k + 1
									Else
										iFileNum = iFileNum + 1
									End If

									If InStr(cboPlotter.Text, "jpg") <> 0 Then
										.PlotToFile sPLT & "-" & iFileNum & ".jpg"
									ElseIf InStr(cboPlotter.Text, "png") <> 0 Then
										.PlotToFile sPLT & "-" & iFileNum & ".png"
									ElseIf InStr(cboPlotter.Text, "pdf") <> 0 Then
										.PlotToFile sPLT & "-" & iFileNum & ".pdf"
									Else
										.PlotToFile sPLT & "-" & iFileNum & ".plt"
									End If
								Else
									.PlotToDevice cboPlotter      '플롯
								End If
								bPloted = True
							End If
						End If
						SetDelay CLng(tbDelay)
NextPart:
					Next // End of 한도면내의 여러폼
					GoTo NextDwg
				End If // End of 폼출력

				If bMPLCancle Or bMPLExit Then Exit For
				// 윈도우 출력일때
				If optWIndow Then
					bWinUser = ini.ReadIni(sPubPath, "MPL", "WinUser", False)

					'사용자가 윈도우 선택
					If bWinUser Then
						sErr = "인쇄 영역 선택 에러"
						With thisDrawing.Utility
							vSpnt = .GetPoint(, "인쇄할 영역의 첫번째 모서리 점 지정:")
							If IsEmpty(vSpnt) Then Me.Show 0: Exit Sub

							On Error Resume Next
							.InitializeUserInput 32
							vEpnt = .GetCorner(vSpnt, "인쇄할 영역의 두번째 모서리 점 지정:")
							If IsEmpty(vEpnt) Then Me.Show 0: Exit Sub
						End With

						vSpnt = ToDCS(vSpnt)
						vEpnt = ToDCS(vEpnt)

						On Error GoTo ErrorHandler
						If vEpnt(2) < vSpnt(2) Then func.SwapData vSpnt, vEpnt

						dPlotMin(0) = vSpnt(0)
						dPlotMin(1) = vSpnt(1)
						dPlotMax(0) = vEpnt(0)
						dPlotMax(1) = vEpnt(1)

					'지정한 윈도우
					Else
						sErr = "지정 윈도우 에러"
						With ini
							dPlotMin(0) = .ReadIni(sPubPath, "MPL", "WinMinX", 0#)
							dPlotMin(1) = .ReadIni(sPubPath, "MPL", "WinMinY", 0#)
							dPlotMax(0) = .ReadIni(sPubPath, "MPL", "WinMaxX", 841#)
							dPlotMax(1) = .ReadIni(sPubPath, "MPL", "WinMaxY", 594#)
						End With
						vSpnt = ZeroPoint
						vEpnt = ZeroPoint
						vSpnt(0) = dPlotMin(0)
						vSpnt(1) = dPlotMin(1)
						vEpnt(0) = dPlotMax(0)
						vEpnt(1) = dPlotMax(1)
						vSpnt = ToDCS(ToWCS(vSpnt))
						vEpnt = ToDCS(ToWCS(vEpnt))
						dPlotMin(0) = vSpnt(0)
						dPlotMin(1) = vSpnt(1)
						dPlotMax(0) = vEpnt(0)
						dPlotMax(1) = vEpnt(1)
					End If

					With oLayout
						sErr = "윈도우 출력 에러"
						.SetWindowToPlot dPlotMin, dPlotMax
						.PlotType = acWindow
					End With

				End If // End of 윈도우출력

				// 일반출력 공통(폼 제외)
				If Not bPlotWindow Then
					If Not optDrawing Then
						With oLayout
							sErr = "공통 출력 맞춤 에러"
							'용지에 맞춤
							If chkFitScale = True Then
								.StandardScale = acScaleToFit
							'자동 맞춤(A1기준)
							ElseIf chkAutoScaleA1 = True Then
								.SetCustomScale 1, dScale * dDiff * dCorrect * dReScale
							'지정한 축척
							Else
								.SetCustomScale 1, dScale * dDiff * dReScale
							End If
						End With
					End If

					With oPlotFile.Plot
						If chkCopy Then
							.NumberOfCopies = 1
						Else
							.NumberOfCopies = CInt(tbPlotCnt) '플롯 매수
						End If

						If bSelPreview Then
							.DisplayPlotPreview acFullPreview   '플롯 미리보기
							bPloted = True
						Else
							If chkPreviw Then
								sErr = "공통 출력 미리보기 에러"
								.DisplayPlotPreview acFullPreview   '플롯 미리보기
								bPloted = True
							Else
								sErr = "공통 출력 플롯 에러"
								If chkPLT Then
									.PlotToFile tbPLT
								Else
									If Not optDrawing Then
										.PlotToDevice cboPlotter        '플롯
									Else
										.PlotToDevice
									End If
									bPloted = True
								End If
							End If
						End If
					End With
				End If

			// 폼이 없을때 여기로 이동
NextDwg:
				// 활성, 모형, 특정레이아웃이면 한번 돌고 종료
				if (bActive || optModel || bSpecLayout)
					break;
NextLayout:
			} // Layout Iterator

////////////////////////////////////////////////////////////////////////////////
			// 열린도면은 닫지 않고, ViewUCS 했으면 원상복구
			if (bOpen) {
				if (bDview)
					SetViewUcs(FALSE);
			}
			else
				oPlotFile.Close(FALSE);
			if (!bPlotWindow)
				SetDelay(GetDlgItemInt(IDC_TBDELAY));

			// 미리보기면 선택한 아이템으로 처리했으니 순환하지 않고 종료
			if (bSelPreview)
				break;
		} // next i, 도면한장 끝
	} // next iCopy, 인쇄매수

	FormMPLExit.ShowWindow(SW_HIDE);

	// 혹시 몰라 첨가했던 플롯 스타일 복원
	// sErr = "플롯 스타일 복원 에러"
	// acPref.DefaultPlotStyleTable = sOldStyle

	oPlotFile = NULL;
	oLayout = NULL;
	acPref = NULL;

	// 시스템 변수되돌림
	sErr = _T("시스템 변수 되돌림 에러");
	//With thisDrawing
	if (dVer > 16)
		SetVariable(_T("BACKGROUNDPLOT"), iPlotBack);
	SetVariable(_T"Expert"), iExpert);
	SetVariable(_T"DWGCHECK"), iDwgCheck);
	sErr = _T("플롯 레포트 작성 에러");
	if (bPlotErr)
		PlotErrReport();

	if (chkPreviw.GetCheck())
		bMPLCancel = TRUE;
	if (!bMPLCancel && !bMPLExit)
		Unload Me; // 미리보기시 취소나 종료 안누른경우
	if (bMPLExit)
		Unload Me;
	if (bMPLCancel)
		Me.Show 0;
	return;

ErrorHandler:
	if (Err) {
		MsgBox Err.Description & vbCrLf & sErr, vbInformation, PROGY_NAME;
		Err.Clear;
	}

	Unload FormMPLExit
'	 acPref.DefaultPlotStyleTable = sOldStyle

	oPlotFile = NULL;
	oLayout = NULL;
	acPref = NULL;

	//With thisDrawing
	if (dVer > 16)
		SetVariable(_T"BACKGROUNDPLOT"), iPlotBack);
	SetVariable(_T("Expert"), iExpert);
	SetVariable(_T("DWGCHECK"), iDwgCheck);

	if (bPlotErr)
		PlotErrReport();
	Unload Me;
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
	CString filPth, filNam, filDir;
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
		if (i >= 0) {
			filNam = filPth.Right(filPth.GetLength() - i - 1);
			filDir = filPth.Left(i + 1);
		}
		else {
			filNam = filPth;
			filDir = _T("\\");
		}

		// 첫번째 컬럼은 파일이름, 두번째는 플롯스타일, 세번째는 경로
		if (IsDupListView(filPth, &lvwDwg))
			bDup = TRUE;
		else {
			i = lvwDwg.GetItemCount();
			i = lvwDwg.InsertItem(i, filNam);
			lvwDwg.SetItemText(i, 1, styNam);
			lvwDwg.SetItemText(i, 2, filDir);
			lvwDwg.SetItemData(i, i);
		}
	}

	LabelMsg();
	if (bDup)
		AfxMessageBox(_T("이미 등록된 도면은 제외되었습니다"), MB_OK | MB_ICONINFORMATION);

	//lvwDwg.Refresh
}


void CDlgMPL::AppendDir(LPCTSTR dirName)
{
	WIN32_FIND_DATA findData;
	HANDLE hFind;
	CString filPath, filNam, filDir;
	CString msgStr;
	CString styNam;
	int i;

	filPath.Format(_T("%s\\*.*"), dirName);
	if ((hFind = FindFirstFile (filPath, &findData)) == INVALID_HANDLE_VALUE) {
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
				AppendDir(filPath);
			}
		}
		else if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)) {
			filNam = findData.cFileName;
			filDir = dirName;
			if (filDir.Right(1) != _T("\\"))
				filDir += _T("\\");
			i = lvwDwg.GetItemCount();
			i = lvwDwg.InsertItem(i, filNam);
			lvwDwg.SetItemText(i, 1, styNam);
			lvwDwg.SetItemText(i, 2, filDir);
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

	AppendDir(dirPath);

	LabelMsg();
}


// 활성 도면 추가
void CDlgMPL::OnBnClickedCbaddcur()
{
	GcApDocument* doc;
	BOOL bDup;
	CString filNam, filDir;
	CString filPth;
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
		if (i >= 0) {
			filNam = filPth.Right(filPth.GetLength() - i - 1);
			filDir = filPth.Left(i + 1);
		}
		else {
			filNam = filPth;
			filDir = _T("\\");
		}

		i = lvwDwg.GetItemCount();
		i = lvwDwg.InsertItem(i, filNam);
		lvwDwg.SetItemText(i, 1, styNam);
		lvwDwg.SetItemText(i, 2, filDir);
		lvwDwg.SetItemData(i, i);
	}

	LabelMsg();
	if (bDup)
		AfxMessageBox(_T("이미 등록된 도면은 제외되었습니다"), MB_OK | MB_ICONINFORMATION);
}


// 열린 도면 추가
void CDlgMPL::OnBnClickedCbaddopen()
{
	GcApDocument* doc;
	BOOL bDup;
	int i;
	CString filPth, filNam, filDir;
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
			if (i >= 0) {
				filNam = filPth.Right(filPth.GetLength() - i - 1);
				filDir = filPth.Left(i + 1);
			}
			else {
				filNam = filPth;
				filDir = _T("\\");
			}

			i = lvwDwg.GetItemCount();
			i = lvwDwg.InsertItem(i, filNam);
			lvwDwg.SetItemText(i, 1, styNam);
			lvwDwg.SetItemText(i, 2, filPth);
			lvwDwg.SetItemData(i, i);
		}
		Iter->step();
	}
	delete Iter;

	LabelMsg();
	if (bDup)
		AfxMessageBox(_T("이미 등록된 도면은 제외되었습니다"), MB_OK | MB_ICONINFORMATION);
}


// 선택 항목 열기
void CDlgMPL::OnBnClickedCbselopen()
{
	POSITION pos;
	int loc;
	CString filPth;
	GcApDocument* doc;

	if (lvwDwg.GetItemCount() < 1)
		return;

	gcedCommand(RTSTR, _T("filedia"), RTSTR, _T("0"), RTNONE);

	pos = lvwDwg.GetFirstSelectedItemPosition();
	while (pos) {
		loc = lvwDwg.GetNextSelectedItem(pos);
		filPth = lvwDwg.GetItemText(loc, 2) + lvwDwg.GetItemText(loc, 0);
		doc = FindOpenDwg(filPth);
		if (doc)
			gcDocManager->activateDocument(doc);
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
	LabelMsg();
}


// 리스트뷰 전체 항목 삭제
void CDlgMPL::OnBnClickedCbdelall()
{
	lvwDwg.DeleteAllItems();
	lvwDwg.SetFocus();
	LabelMsg();
}


// 리스트뷰 맨위로 이동
void CDlgMPL::OnBnClickedCbfup()
{
	CString sTemp1;
	CString sTemp2;
	CString sTemp3;
	int iCnt;
	int i, j, k;

	iCnt = lvwDwg.GetItemCount();
	if (iCnt < 1)
		return;

	k = 0;
	for (i = 1; i < iCnt; i ++) {
		if (lvwDwg.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED) {
			sTemp1 = lvwDwg.GetItemText(i, 0);
			sTemp2 = lvwDwg.GetItemText(i, 1);
			sTemp3 = lvwDwg.GetItemText(i, 2);
			lvwDwg.DeleteItem(i);
			j = lvwDwg.InsertItem(k, sTemp1);
			lvwDwg.SetItemText(j, 1, sTemp2);
			lvwDwg.SetItemText(j, 2, sTemp3);
			lvwDwg.SetItemState (j, LVIS_SELECTED, LVIS_SELECTED);
			k ++;
		}
	}

	lvwDwg.SetFocus();
}


// 리스트뷰 맨아래로 이동
void CDlgMPL::OnBnClickedCbldown()
{
	CString sTemp1;
	CString sTemp2;
	CString sTemp3;
	int iCnt;
	int i, j, k;

	iCnt = lvwDwg.GetItemCount();
	if (iCnt < 1)
		return;

	k = 0;
	for (i = iCnt - 2; i >= 0; i --) {
		if (lvwDwg.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED) {
			sTemp1 = lvwDwg.GetItemText(i, 0);
			sTemp2 = lvwDwg.GetItemText(i, 1);
			sTemp3 = lvwDwg.GetItemText(i, 2);
			lvwDwg.DeleteItem(i);
			j = lvwDwg.InsertItem(iCnt - k, sTemp1);
			lvwDwg.SetItemText(j, 1, sTemp2);
			lvwDwg.SetItemText(j, 2, sTemp3);
			lvwDwg.SetItemState (j, LVIS_SELECTED, LVIS_SELECTED);
			k ++;
		}
	}

	lvwDwg.SetFocus();
}


// 리스트뷰 위로 이동
void CDlgMPL::OnBnClickedCbup()
{
	CString sTemp1;
	CString sTemp2;
	CString sTemp3;
	int iCnt;
	int i, j;

	iCnt = lvwDwg.GetItemCount();
	if (iCnt < 1)
		return;

	for (i = 1; i < iCnt; i ++) {
		if (lvwDwg.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED) {
			sTemp1 = lvwDwg.GetItemText(i, 0);
			sTemp2 = lvwDwg.GetItemText(i, 1);
			sTemp3 = lvwDwg.GetItemText(i, 2);
			lvwDwg.DeleteItem(i);
			j = lvwDwg.InsertItem(i - 1, sTemp1);
			lvwDwg.SetItemText(j, 1, sTemp2);
			lvwDwg.SetItemText(j, 2, sTemp3);
			lvwDwg.SetItemState (j, LVIS_SELECTED, LVIS_SELECTED);
		}
	}

	lvwDwg.SetFocus();
}


// 리스트뷰 아래로 이동
void CDlgMPL::OnBnClickedCbdown()
{
	CString sTemp1;
	CString sTemp2;
	CString sTemp3;
	int iCnt;
	int i, j;

	iCnt = lvwDwg.GetItemCount();
	if (iCnt < 1)
		return;

	for (i = iCnt - 2; i >= 0; i --) {
		if (lvwDwg.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED) {
			sTemp1 = lvwDwg.GetItemText(i, 0);
			sTemp2 = lvwDwg.GetItemText(i, 1);
			sTemp3 = lvwDwg.GetItemText(i, 2);
			lvwDwg.DeleteItem(i);
			j = lvwDwg.InsertItem(i + 1, sTemp1);
			lvwDwg.SetItemText(j, 1, sTemp2);
			lvwDwg.SetItemText(j, 2, sTemp3);
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

	_ftprintf(fout, _T("[Dream MPL Plot List]\n"));
	for (i = 0; i < iCnt; i ++)
		_ftprintf(fout, _T("%s,%s,%s\n"), lvwDwg.GetItemText(i, 0), lvwDwg.GetItemText(i, 2), lvwDwg.GetItemText(i, 1));
	
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
	if (cstr.CompareNoCase(_T("[dream mpl plot list]")) != 0) {
		AfxMessageBox(_T("다중 플롯 파일 목록이 아니거나 이전 버전에의해 작성된 목록입니다\n현재 버전과 호환되지 않으므로\n도면 추가 기능으로 파일을 추가해 주십시오"), MB_OK | MB_ICONINFORMATION);
		fclose(fin);
		return;
	}

	while (_fgetts(sData, 1024, fin)) {
		cstr = sData;
		cstr.Trim();

		// 파일명,경로,스타일
		String2Array(cstr, strArr, _T(","));
		sPath = strArr[1] + strArr[0];
		if (IsDupListView(sPath, &lvwDwg))
			bDup = TRUE;
		else {
			i = lvwDwg.GetItemCount();
			i = lvwDwg.InsertItem(i, strArr[0]);
			lvwDwg.SetItemText(i, 1, strArr[2]);
			lvwDwg.SetItemText(i, 2, strArr[1]);
			lvwDwg.SetItemData(i, i);
		}
	}

	fclose(fin);

	LabelMsg();
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
void CDlgMPL::OnBnClickedCbsort()
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

	if (optAscend.GetCheck())
		lvwDwg.SortItems(ListSortAscend, (LPARAM)&lvwDwg);
	else
		lvwDwg.SortItems(ListSortDescend, (LPARAM)&lvwDwg);

	//// 목록을 새로 만든다
	//For i = 1 To iCnt
	//	sItem(i) = .ListItems(i).Text & "?" & .ListItems(i).SubItems(1) & "?" & .ListItems(i).SubItems(2)
	//Next
	//If optAscend Then
	//	func.AlphanumSort sItem
	//Else
	//	func.AlphanumSort sItem, True
	//End If

	//// 모두 삭제
	//lvwDwg.DeleteAllItems();
	//.ListItems.Clear

	//'다시 목록 올린다
	//If optAscend Then
	//	For i = 1 To iCnt
	//		sTemp = Split(sItem(i), "?")
	//		With lvwDwg
	//			k = .ListItems.Count
	//			.ListItems.Add , , sTemp(0)
	//			.ListItems(k + 1).SubItems(1) = sTemp(1)
	//			.ListItems(k + 1).SubItems(2) = sTemp(2)
	//		End With
	//	Next
	//Else
	//	For i = 0 To iCnt - 1
	//		sTemp = Split(sItem(i), "?")
	//		With lvwDwg
	//			k = .ListItems.Count
	//			.ListItems.Add , , sTemp(0)
	//			.ListItems(k + 1).SubItems(1) = sTemp(1)
	//			.ListItems(k + 1).SubItems(2) = sTemp(2)
	//		End With
	//	Next
	//End If
}


void CDlgMPL::LabelMsg()
{
	CString cstr;
	int iCnt;

	iCnt = lvwDwg.GetItemCount();
	if (iCnt < 1) {
		tbPath.SetWindowText(_T(""));
		ThumbView.SetDwgFile(_T(""));
		cstr = _T("목록에 도면을 추가해 주십시오");
	}
	else
		cstr.Format(_T("총 %d 개의 파일이 목록에 추가됨"), iCnt);

	lblCount.SetWindowText(cstr);
}


void CDlgMPL::OnBnClickedCbwindow()
{
	//Me.hide
	//FormMPLSub.Show 0
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

	tbPath.SetWindowTextW(lvwDwg.GetItemText(index, 2));
	ThumbView.SetDwgFile(lvwDwg.GetItemText(index, 2) + lvwDwg.GetItemText(index, 0));

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
	const GCHAR* localName;
	const GCHAR* pCurName;
	int i;
	int iCnt;

	pPSV->refreshLists(pPlotSettings);
	pPSV->canonicalMediaNameList(pPlotSettings,MediaList);

	cboPaper.ResetContent();
	iCnt = MediaList.length();
	for (i = 0; i < iCnt; i ++) {
		pPSV->getLocaleMediaName(pPlotSettings, MediaList[i], localName);
		cboPaper.AddString(localName);
	}

	pPlotSettings->getCanonicalMediaName(pCurName);
	pPSV->getLocaleMediaName(pPlotSettings, pCurName, localName);
	SelectComboText(&cboPaper, localName);
}


void CDlgMPL::RefreshDevices()
{
	GcArray<const TCHAR*> deviceList;// Temporary device array
	const TCHAR* plotCfgchar;
	int i;
	int iCnt;

	// Set the list of available devices on the system

	cboPlotter.ResetContent();// Clear the Combo Box
	pPSV->refreshLists(pPlotSettings);
	pPSV->plotDeviceList(deviceList);// Fill the temporary array,
	// and copy the Combo Box and mirror with the results.
	iCnt = deviceList.length();
	for (i = 0; i < iCnt; i ++)
		cboPlotter.AddString(deviceList[i]);

	// Set the current selection to reflect the current output device.
	pPlotSettings->getPlotCfgName (plotCfgchar);
	SelectComboText(&cboPlotter, plotCfgchar);
}


void CDlgMPL::RefreshPlotStyle()
{
	GcArray<const TCHAR*> StyleList;
	int i;
	int iCnt;

	cboStyle.ResetContent();
	pPSV->refreshLists(pPlotSettings);
	pPSV->plotStyleSheetList(StyleList);

	iCnt = StyleList.length();
	for (i = 0; i < iCnt; i ++)
		cboStyle.AddString(StyleList[i]);

	if (cboStyle.GetCount() > 0)
		cboStyle.SetCurSel(0);
}


// 플로터 변경에 따른 용지종류 변경
void CDlgMPL::OnCbnSelchangeCboplotter()
{
	CString pltNam;
	GetComboText(&cboPlotter, pltNam);

	Gcad::ErrorStatus es = pPSV->setPlotCfgName(pPlotSettings, pltNam);

	RefreshMediaNames();

	return;

	//refresh the Plot Config list
	//pPSV->refreshLists(oLayout);

	GcArray<const TCHAR*> deviceList;// Temporary device array

	cboPaper.ResetContent();// Clear the Combo Box
	pPSV->refreshLists(pPlotSettings);
	pPSV->plotDeviceList(deviceList);// Fill the temporary array,

	// and copy the Combo Box and mirror with the results.
	for(int c=0; c <deviceList.length(); c ++)
		cboPaper.AddString(deviceList[c]);

	// Set the current selection to reflect the current output device.
	const TCHAR* plotCfgchar;
	pPlotSettings->getPlotCfgName (plotCfgchar);
	SelectComboText(&cboPaper, plotCfgchar);

	return;





	cboPaper.Clear();

	//Set oLayout = thisDrawing.ActiveLayout;
	//cboPaper.Clear

	// 리프레쉬
	//oLayout.RefreshPlotDeviceInfo

	GetComboText(&cboPlotter, pltNam);
	if (pltNam.CompareNoCase(_T("없음")) == 0 || pltNam.CompareNoCase(_T("none")) == 0) {
		cboPaper.AddString(_T("없음"));
		cboPaper.SetCurSel(0);
		return;
	}

	CString cmsg;
	// 지정한 플로터를 현재 플로터로
	if (pPSV->setPlotCfgName(oLayout, pltNam) != Gcad::eOk) {
		cmsg.Format(_T("%s 파일은 잘못된 PC3 파일 또는 연결에 문제있는 프린터입니다\n다른 프린터를 선택해 주십시오"), pltNam);
		AfxMessageBox(cmsg, MB_OK | MB_ICONSTOP);
		return;
	}
	pPSV->refreshLists(oLayout);

	// 모든 용지 종류 얻어서
	GcArray<const GCHAR *> mMediaList;
	const GCHAR *pLocaleName;
	CStringArray sPaper;
	int iCnt;
	int i;

	pPSV->canonicalMediaNameList(oLayout, mMediaList);

	// 용지를 순환하면서 각 요소의 이름을 다시 받는다
	// 로터 용지가 Userxxxx 로 나오는것 방지
	iCnt = mMediaList.length();
	for (i = 0; i < iCnt; i ++) {
		//get the localename
		pPSV->getLocaleMediaName(oLayout, mMediaList.at(i), pLocaleName);
		sPaper.Add(pLocaleName);
	}

	// 소트해서 콤보박스에 올림
	SortStringArray(sPaper, TRUE);

	iCnt = sPaper.GetCount();
	for (i = 0; i < iCnt; i ++)
		cboPaper.AddString(sPaper[i]);
}


void CDlgMPL::OnCbnSelchangeCbostyle()
{
	int i;
	int iCnt;
	CString styNam;
	POSITION pos;

	cbAdd.SetFocus();

	//With lvwDwg
	iCnt = lvwDwg.GetItemCount();
	if (iCnt < 1)
		return;

	GetComboText(&cboStyle, styNam);
	Gcad::ErrorStatus es = pPSV->setCurrentStyleSheet(pPlotSettings, styNam);

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
	//FormMPLform.Show();
}


void CDlgMPL::OnBnClickedCbfind()
{
	CString cstr;

	CFileDialog filDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY,
		_T("Pdf (*.pdf)|*.pdf|All Files(*.*)|*.*||"));

	if (filDlg.DoModal() == IDOK) {
		cstr = filDlg.GetFileName();
		if (cstr.Right(1).Compare(_T("\\")))
			cstr = cstr + _T("\\");
		tbPLT.SetWindowText(cstr);
	}
}


// 용지에 맞춤
void CDlgMPL::OnBnClickedChkfitscale()
{
	BOOL bTrue;

	bTrue = chkFitScale.GetCheck() ? FALSE: TRUE;

	if (chkAutoScaleA1.GetCheck())
		chkAutoScaleA1.SetCheck(bTrue);

	Label4.EnableWindow(bTrue);
	tbScale.EnableWindow(bTrue);
	chkReScale.EnableWindow(bTrue);
	//if (bTrue)
	//	tbScale.BackColor = &H80000005
	//Else
	//	tbScale.BackColor = &H8000000F
	//End If
}


// 자동 맞춤(A1기준)
void CDlgMPL::OnBnClickedChkautoscalea1()
{
	BOOL bTrue;

	bTrue = chkAutoScaleA1.GetCheck() ? FALSE: TRUE;

	if (chkFitScale.GetCheck())
		chkFitScale.SetCheck(bTrue);

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
	CDlgMPLScale dlgScale(this);
	dlgScale.m_optForm = optForm.GetCheck();
	if (dlgScale.DoModal() == IDOK) {
	}
}


void CDlgMPL::OnBnClickedOptactive()
{
	if (optSpecLayout.GetCheck()) {
		tbLayout.ShowWindow(SW_SHOW);
		optSpecLayout.SetWindowText(_T("Layout:"));
	}
	else {
		tbLayout.ShowWindow(SW_HIDE);
		optSpecLayout.SetWindowText(_T("특정 Layout"));
	}

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
			AfxMessageBox(_T("모든 Layout 출력인 경우 WIndow 플롯 영역 옵션을 사용할 수 없습니다\n다른 옵션을 선택해주십시오"), MB_OK | MB_ICONSTOP);
			optForm.SetCheck(TRUE);
			return;
		}
		ControlEnable3();
	}
	else if (optModelLayout.GetCheck()) {
		optLimit.SetWindowText(_T("Limits 또는 Layout"));
		if (optWindow.GetCheck()) {
			AfxMessageBox(_T("Model + 모든 Layout 출력인 경우 WIndow 플롯 영역 옵션을 사용할 수 없습니다\n다른 옵션을 선택해주십시오"), MB_OK | MB_ICONSTOP);
			optForm.SetCheck(TRUE);
			return;
		}
		ControlEnable3();
	}
	else if (optSpecLayout.GetCheck()) {
		if (optSpecLayout.GetCheck()) {
			tbLayout.SetFocus();
			//.ZOrder 0
		}
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
		//cbScaleView.top = 9
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
		//cbScaleView.top = 26

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
	tbTol.EnableWindow(bTrue);
	Label11.EnableWindow(bTrue);
	Label14.EnableWindow(bTrue);
	chkPart.EnableWindow(bTrue);
	tbPartS.EnableWindow(bTrue);
	tbPartE.EnableWindow(bTrue);
	optSortLR.EnableWindow(bTrue);
	optSortLU.EnableWindow(bTrue);
	optSortLD.EnableWindow(bTrue);
	optSortIZ.EnableWindow(bTrue);
	chkReverse.EnableWindow(bTrue);
	chkSelForm.EnableWindow(bTrue);
	if (!bTrue) {
		if (chkSelForm.GetCheck())
			chkSelForm.SetCheck(FALSE);
	}
}


void CDlgMPL::ControlEnable2(BOOL bTrue)
{
	chkFitScale.EnableWindow(bTrue);
	OnBnClickedChkplotcenter();

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
			chkPlotCenter.SetCheck(FALSE);
			chkPlotCenter.EnableWindow(FALSE);
		}
	}
}


void CDlgMPL::OnBnClickedChkpart()
{
	BOOL bTrue;

	bTrue = chkPart.GetCheck();
	tbPartS.ShowWindow(bTrue ? SW_SHOW: SW_HIDE);
	Label12.ShowWindow(bTrue ? SW_SHOW: SW_HIDE);
	tbPartE.ShowWindow(bTrue ? SW_SHOW: SW_HIDE);
	if (bTrue)
		tbPartS.SetFocus();
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
GcApDocument* CDlgMPL::FindOpenDwg(LPCTSTR sName)
{
	GcApDocument* doc;

	GcApDocumentIterator *Iter = gcDocManager->newAcApDocumentIterator();
	while (!Iter->done()) {
		doc = Iter->document();
		if (_tcsicmp(doc->fileName(), sName) == 0) {
			delete Iter;
			return doc;
		}
		Iter->step();
	}
	delete Iter;

	return NULL;
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
	cstr = m_regEdit.GetString(_T("MPL"), _T("Paper"), _T(""));
	SelectComboText(&cboPaper, cstr);
	cstr = m_regEdit.GetString(_T("MPL"), _T("Style"), _T(""));
	SelectComboText(&cboStyle, cstr);

	//i = ini.ReadIni(sPubPath, "MPL", "Paper", 0)
	//If cboPlotter.ListIndex <> 0 Then
	//	If i < 0 Then i = 0
	//	With cboPaper
	//		If .ListCount <= i Then
	//			.ListIndex = 0
	//		Else
	//			.ListIndex = i
	//		End If
	//	End With
	//Else
	//	With cboPaper
	//		.AddItem "없음"
	//		.ListIndex = 0
	//	End With
	//End If

	opt = m_regEdit.GetInteger(_T("MPL"), _T("AreaType"), 0);
	CheckRadioButton(IDC_OPTFORM, IDC_OPTDRAWING, opt + IDC_OPTFORM);
	//optForm = .ReadIni(sPubPath, "MPL", "optForm", True)
	//optWIndow = .ReadIni(sPubPath, "MPL", "optWIndow", False)
	//optExtend = .ReadIni(sPubPath, "MPL", "optExtend", False)
	//optLimit = .ReadIni(sPubPath, "MPL", "optLimit", False)
	//optDrawing = .ReadIni(sPubPath, "MPL", "optDrawing", False)

	opt = m_regEdit.GetInteger(_T("MPL"), _T("SortType"), 0);
	CheckRadioButton(IDC_OPTASCEND, IDC_OPTDESCEND, opt + IDC_OPTASCEND);
	//optAscend = .ReadIni(sPubPath, "MPL", "Ascend", True)
	//optDescend = .ReadIni(sPubPath, "MPL", "Descend", False)

	opt = m_regEdit.GetInteger(_T("MPL"), _T("TargetType"), 0);
	CheckRadioButton(IDC_OPTACTIVE, IDC_OPTSPECLAYOUT, opt + IDC_OPTACTIVE);
	//optActive = .ReadIni(sPubPath, "MPL", "OnlyActive", True)
	//optModel = .ReadIni(sPubPath, "MPL", "OnlyModel", False)
	//optOnlyLayout = .ReadIni(sPubPath, "MPL", "OnlyLayout", False)
	//optModelLayout = .ReadIni(sPubPath, "MPL", "ModelLayout", False)
	//optSpecLayout = .ReadIni(sPubPath, "MPL", "SpecLayout", False)

	tbLayout.SetWindowTextW(m_regEdit.GetString(_T("MPL"), _T("LayoutName"), _T("")));
	tbTol.SetWindowTextW(m_regEdit.GetString(_T("MPL"), _T("Tolerance"), _T("10")));
	chkFitScale.SetCheck(m_regEdit.GetBoolean(_T("MPL"), _T("FitScale"), FALSE));
	chkAutoScaleA1.SetCheck(m_regEdit.GetBoolean(_T("MPL"), _T("AutoScale"), TRUE));
	tbScale.SetWindowTextW(m_regEdit.GetString(_T("MPL"), _T("Scale"), _T("1")));
	chkPlotCenter.SetCheck(m_regEdit.GetBoolean(_T("MPL"), _T("PlotCenter"), TRUE));
	tbPlotX.SetWindowTextW(m_regEdit.GetString(_T("MPL"), _T("PlotX"), _T("0")));
	tbPlotY.SetWindowTextW(m_regEdit.GetString(_T("MPL"), _T("PlotY"), _T("0")));

	opt = m_regEdit.GetInteger(_T("MPL"), _T("DirType"), 0);
	CheckRadioButton(IDC_OPTSORTLR, IDC_OPTSORTIZ, opt + IDC_OPTSORTLR);
	//optSortLR = .ReadIni(sPubPath, "MPL", "SortLR", True)
	//optSortLU = .ReadIni(sPubPath, "MPL", "SortLU", False)
	//optSortLD = .ReadIni(sPubPath, "MPL", "SortLD", False)
	//optSortIZ = .ReadIni(sPubPath, "MPL", "SortIZ", False)

	tbDelay.SetWindowTextW(m_regEdit.GetString(_T("MPL"), _T("Delay"), _T("0")));
	chkPLT.SetCheck(m_regEdit.GetBoolean(_T("MPL"), _T("PLT"), FALSE));
	tbReScale.SetWindowTextW(m_regEdit.GetString(_T("MPL"), _T("ReScale"), _T("100")));

	opt = m_regEdit.GetInteger(_T("MPL"), _T("LayType"), 0);
	CheckRadioButton(IDC_OPTSORTLR, IDC_OPTSORTIZ, opt + IDC_OPTSORTLR);
	//optAuto = .ReadIni(sPubPath, "MPL", "Auto", True)
	//optHor = .ReadIni(sPubPath, "MPL", "Hor", False)
	//optVer = .ReadIni(sPubPath, "MPL", "Ver", False)
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
	m_regEdit.SetInteger(_T("MPL"), _T("SortType"),
		GetCheckedRadioButton(IDC_OPTASCEND, IDC_OPTDESCEND) - IDC_OPTASCEND);
	m_regEdit.SetInteger(_T("MPL"), _T("TargetType"),
		GetCheckedRadioButton(IDC_OPTACTIVE, IDC_OPTSPECLAYOUT) - IDC_OPTACTIVE);
	GetComboText(&cboPlotter, cstr); m_regEdit.SetString(_T("MPL"), _T("Plotter"), cstr);
	GetComboText(&cboPaper, cstr); m_regEdit.SetString(_T("MPL"), _T("Paper"), cstr);
	GetComboText(&cboStyle, cstr); m_regEdit.SetString(_T("MPL"), _T("Style"), cstr);
	tbLayout.GetWindowTextW(cstr); m_regEdit.SetString(_T("MPL"), _T("LayoutName"), cstr);
	tbTol.GetWindowTextW(cstr); m_regEdit.SetString(_T("MPL"), _T("Tolerance"), cstr);
	m_regEdit.SetBoolean(_T("MPL"), _T("FitScale"), chkFitScale.GetCheck());
	m_regEdit.SetBoolean(_T("MPL"), _T("AutoScale"), chkAutoScaleA1.GetCheck());
	tbScale.GetWindowTextW(cstr); m_regEdit.SetString(_T("MPL"), _T("Scale"), cstr);
	m_regEdit.SetBoolean(_T("MPL"), _T("PlotCenter"), chkPlotCenter.GetCheck());
	tbPlotX.GetWindowTextW(cstr); m_regEdit.SetString(_T("MPL"), _T("PlotX"), cstr);
	tbPlotY.GetWindowTextW(cstr); m_regEdit.SetString(_T("MPL"), _T("PlotY"), cstr);
	m_regEdit.SetInteger(_T("MPL"), _T("DirType"),
		GetCheckedRadioButton(IDC_OPTSORTLR, IDC_OPTSORTIZ) - IDC_OPTSORTLR);
	tbDelay.GetWindowTextW(cstr); m_regEdit.SetString(_T("MPL"), _T("Delay"), cstr);
	m_regEdit.SetBoolean(_T("MPL"), _T("PLT"), chkPLT.GetCheck());
	tbReScale.GetWindowTextW(cstr); m_regEdit.SetString(_T("MPL"), _T("ReScale"), cstr);
	m_regEdit.SetInteger(_T("MPL"), _T("LayType"),
		GetCheckedRadioButton(IDC_OPTSORTLR, IDC_OPTSORTIZ) - IDC_OPTSORTLR);
}


BOOL CDlgMPL::OnInitDialog()
{
	CGcUiDialog::OnInitDialog();

	m_regEdit.SetKey(HKEY_CURRENT_USER, _T("SOFTWARE\\Magic\\MagicUtil"));

	//SetWindowText(ProgName);
	//.cbCancle.Cancel = True

	// get current layout
	gcdbOpenObject(oLayout, gcdbHostApplicationServices()->workingDatabase()->currentLayoutId(), GcDb::kForRead);
	pPlotSettings = new GcDbPlotSettings(oLayout->modelType());
	pPSV = gcdbHostApplicationServices()->plotSettingsValidator();

	RefreshDevices();
	RefreshPlotStyle();
	//OnCbnSelchangeDevices();

	// 환경설정 열기
	LoadIni();

	OnCbnSelchangeCboplotter();

	// 컨트롤 활성
	tbPartS.ShowWindow(SW_HIDE);
	Label12.ShowWindow(SW_HIDE);
	tbPartE.ShowWindow(SW_HIDE);

	int sngWidth;
	CRect crec;
	lvwDwg.GetClientRect(crec);
	sngWidth = crec.Width();

	lvwDwg.ModifyStyle (0, LVS_REPORT | LVS_SHOWSELALWAYS);
	lvwDwg.SetExtendedStyle (LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	lvwDwg.InsertColumn (0, _T("파일명"), LVCFMT_LEFT, sngWidth * 6 / 10, 0);
	lvwDwg.InsertColumn (1, _T("플롯스타일"), LVCFMT_LEFT, sngWidth * 4 / 10, 0);
	lvwDwg.InsertColumn (2, _T("전체경로"), LVCFMT_LEFT, 0, 0);

	if (lvwDwg.GetItemCount() < 1)
		lblCount.SetWindowTextW(_T("목록에 도면을 추가해 주십시오"));

	cbScaleView.SubclassDlgItem(IDC_CBSCALEVIEW, this);
	cbScaleView.SetImage(IDB_SEARCH);

	ThumbView.SubclassDlgItem(IDC_THUMBVIEW, this);
	ThumbView.SetBkgColor(0xffffff);

	OnBnClickedChkplotcenter();
	OnBnClickedChkplt();
	OnBnClickedChkrescale();

AppendDir(_T("C:\\Temp\\0000"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL CDlgMPL::DestroyWindow()
{
	delete pPlotSettings;

	if (oLayout)
		oLayout->close();

	return CGcUiDialog::DestroyWindow();
}


void CDlgMPL::OnCbnSelchangeCbopaper()
{
	GcArray<const GCHAR *> MediaList;
	const GCHAR* locNam;
	const GCHAR* canNam;
	CString papNam;
	int i;
	int iCnt;

	GetComboText(&cboPaper, papNam);

	MediaList.removeAll();
	pPSV->canonicalMediaNameList(pPlotSettings, MediaList);

	iCnt = MediaList.length();
	for (i = 0; i < iCnt; i ++) {
		canNam = MediaList.at(i);
		pPSV->getLocaleMediaName(pPlotSettings, canNam, locNam);
		if (_tcsicmp(papNam, locNam) == 0) {
			pPSV->setCanonicalMediaName(pPlotSettings, canNam);
			pPSV->setZoomToPaperOnUpdate(pPlotSettings, ::kTrue);
#ifdef _DEBUG
			const GCHAR *pCurName;
			pPlotSettings->getCanonicalMediaName(pCurName);
#endif
			break;
		}
	}
	//CalcExtents();
}

