// DlgMPL.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MagicUtil.h"
#include "DlgMPL.h"
#include "afxdialogex.h"
#include "DlgMPLStyle.h"
#include "DlgMPLForm.h"
#include "DlgMPLScale.h"
#include "DlgMPLExit.h"

const TCHAR* CDlgMPL::PROGY_NAME = _T("���� �÷�");

// CDlgMPL ��ȭ �����Դϴ�.

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


// CDlgMPL �޽��� ó�����Դϴ�.


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

	// units �ٲ�ٰ� �ؼ� �߰���.. �̻���
	GetVariable(_T("INSUNITS"), iInsUnit);

	pLayout->getLayoutName(pLayName);

	GcDbLayoutManager* pLayoutManager = gcdbHostApplicationServices()->layoutManager();
	pLayoutManager->setCurrentLayout(pLayName);

	// �÷� ���� ������ ����.
	sErr = _T("�÷� ������ ���� ����");

	// �ڵ� �� ���� ��ô ����
	// ���� �Ʒ��� ���� ���
	sErr = _T("�ڵ� �� ���� ��ô ���� ����");
	if (tbScale.IsWindowEnabled()) {
		GetDlgItemText(IDC_TBSCALE, cstr);
		dScale = _ttof(cstr);
	}

	// get the plotsetttings class
	GcDbPlotSettingsValidator* pPlotSettingsValidator = gcdbHostApplicationServices()->plotSettingsValidator();
	pPlotSettingsValidator->refreshLists(pLayout);

	// ���� ����
	if (optDrawing.GetCheck()) {
			//es = pPlotSettingsValidator->setPlotCfgName(pLayout, szPrinterPath);  
		pLayout->getPlotSettingsName(sPlotter);
		if (_tcsicmp(sPlotter, _T("����")) == 0 || _tcsicmp(sPlotter, _T("none")) == 0)
			bSavePlot = FALSE;
		else
			bSavePlot = IsExistCombo(sPlotter, cboPlotter);

		if (!bSavePlot) {
			if (bActive || bModel || bSpecLayout) {
				bPlotErr = TRUE;
				LogErr(oPlotFile.Name + _T(" : ���鿡 ����� ��� ������ �����ϴ�."), FALSE);
				goto NextDwg;
			}
			else {
				if (iNext == iLayCnt) {
					if (!bPloted) {
						bPlotErr = TRUE;
						LogErr(oPlotFile.Name + _T(" : ���鿡 ����� ��� ������ �����ϴ�."), FALSE);
						goto NextDwg;
					}
				}
				goto NextLayout;
			}
		}
	}
	else {
		sErr = _T("�÷���, ����, ��Ÿ�� �������� ����\n��Ÿ���� STB�� �ƴ� CTB ���Ϸ� ������ �ֽʽÿ�");
		.ConfigName = cboPlotter; // �÷���
		.CanonicalMediaName = sName; // ����
		.PlotWithPlotStyles = TRUE; // �÷� ��Ÿ�� ��뿩��
		.PlotWithLineweights = TRUE;
		.StyleSheet = CStr(lvwDwg.ListItems(i).SubItems(1)); // �÷� ��Ÿ��


		// Ȥ�� ���� �ý����� �⺻ �÷� ��Ÿ���� ����ŷ� �ٲ۴�
		// sErr = "�⺻ �÷� ��Ÿ�� ���� ����"
		// acPref.DefaultPlotStyleTable = CStr(lvwDwg.ListItems(i).SubItems(1))
		// PlotWithPlotStyles = TRUE;

		// �÷� ��ô
		sErr = _T("�÷� ��ô ���� ����");
		if (chkFitScale.GetCheck())
			.StandardScale = acScaleToFit; // ������ ����
		if (tbScale.Enabled = True)
			.SetCustomScale(1, dScale); // ���� ��ô

		// �÷� ȸ��
		sErr = _T("�÷� ȸ�� ���� ����");
		if (optHor)
			.PlotRotation = ac90degrees; // ����
		else if (optVer)
			.PlotRotation = ac0degrees;

		// �÷� �߾�
		sErr = _T("�÷� �߾� ���� ����");
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

		// Extent, Limit, Layout ���
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

		// �÷� ���� ������ ���� ��� ������ ����
		// 1=inch , 0 = milimeter
		sErr = _T("��� ��ô ���� ����");

		// �׳� �и����ͷ� ��������
		.PaperUnits = acMillimeters;

		// �̰� �����ڵ�
		if (.PaperUnits == 1)
			dCorrect = 1;
		else
			dCorrect = 25.4;
		oPlotFile.Regen(acAllViewports);
	}

	// ������϶�
	if (bPlotWindow) {
		// �ܺ������� ���� ������ ������ �V
		Set oSel = dll.CreateSelSet("SelSet");

		// �־��� �̸��� �ܺ�����(��)�� ��� ����
		iGcode(0) = 2;
		vData(0) = sTemp;

		if (chkSelForm.GetCheck()) {
			CmdPrompt(_T("����(Form) ���� :"));
			oSel.SelectOnScreen(iGcode, vData);
		}
		else
			oSel.Select(acSelectionSetAll, , , iGcode, vData);

		Set oSel = CurSpaceEnt(oSel);

		iXrefCnt = oSel.Count - 1;
		if (iXrefCnt == -1) {
			if (bActive || bModel || bSpecLayout) {
				bPlotErr = TRUE;
				LogErr(oPlotFile.Name + _T(" : ���鿡 ������ �̸��� Form�� �����ϴ� - ") + sTemp, FALSE);
				goto NextDwg;
			}
			else {
				if (iNext == iLayCnt) {
					if (!bPloted) {
						bPlotErr = TRUE;
						LogErr(oPlotFile.Name + _T(" : ���鿡 ������ �̸��� Form�� �����ϴ� - ") + sTemp, FALSE);
						goto NextDwg;
					}
				}
				goto NextLayout;
			}
		}

		// �ܺ�����1�� �̻�� �μ�Ʈ ����Ʈ�� ��Ʈ
		sErr = _T("Form Sort ����");
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
				// �����μ�
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

		sErr = _T("�Ϻ� ��� �Է� ����");
		iPartS = CInt(Val(tbPartS));
		iPartE = CInt(Val(tbPartE));

		// �ѵ��� ���� ���� �� ��ȯ**************************************
		if (chkPLT.GetCheck())
			sPLT = tbPLT + sFileName;
		for (k = 0; k < iXrefCnt; k ++) {
			sFormName = oSel.Item(k).Name;
			iIniPos = GetFormIniPos(sFormName);

			// ���� ����
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

			// ��� ��� ������ ��� ��ȯ�Ǹ� ���� ���� ���
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
				bRotate = IsVerDwg(.Rotation); // false = ���ε���
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
				bRotate = IsVerDwg(.Rotation); // false = ���ε���
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

			// ���� ���� ���� �����̸� ���� ���� �����´�
			if (bRealVert)
				bRotate = !bRotate;

			// ������ ���� ���� ������ ũ������
			if (!bRotate) { // ȸ�� �ȵ� ����
				if (bVertical) {
					dDiff = dSelVer / dXWidth;
					// ����� ������(Two Array)
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
			// �����켳��.PlotType�� SetWindowToPlot �ڿ� ����� ��
			.SetWindowToPlot(dPlotMin, dPlotMax);
			.PlotType = acWindow;

			// ���� �������� ��찡 �����Ƿ� ������� ��ȯ�ϸ鼭 �Ʒ��� ���ľ� �Ѵ�.
			sErr = _T("Form ���� ����");
			if (chkFitScale.GetCheck()) // ������ ����
				.StandardScale = acScaleToFit;
			else if (chkAutoScaleA1.GetCheck()) // �ڵ� ����(A1����)
				.SetCustomScale(1, dScale * dDiff * dCorrect * dReScale);
			else // ������ ��ô
				.SetCustomScale(1, dScale * dDiff * dReScale);

			//With oPlotFile.Plot
			if (chkCopy.GetCheck())
				.NumberOfCopies = 1;
			else
				.NumberOfCopies = GetDlgItemInt(IDC_TBPLOTCNT); // �÷� �ż�

			if (bSelPreview) {
				.DisplayPlotPreview(acFullPreview); // �÷� �̸�����
				bPloted = TRUE;
			}
			else {
				if (chkPreviw.GetCheck()) {
					sErr = _T("�÷� �̸����� ����");
					.DisplayPlotPreview(acFullPreview); // '�÷� �̸�����
					bPloted = TRUE;
				}
				else {
					sErr = _T("�÷� ����");
					if (chkPLT.GetCheck()) {
						// ���� ��� ���ϳ��� ������ �������� �Ʒ����� ���� ������ k�� ��½�
						// ��ȣ�� �ٸ��� �������� ��ġ�ΰ�� ��ġ�ϳ��� ���� �ϳ���
						// �Ʒ� k�� ����ϴ� ��� ��ġ �ϳ��� ���� �Ѱ��� k�� ��� 0 �̵�
						// ���� iFileNum ������ �ΰ�
						// ���� ���� k �� �׳� ���
						// ��ġ�� ���� iFileNum �����ؼ� ���� �ٸ��� �Ѵ�
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
						.PlotToDevice(cboPlotter); // �÷�
					bPloted = TRUE;
				}
			}
			SetDelay (GetDlgItemInt(IDC_TBDELAY));
NextPart:
		// next k, End of �ѵ��鳻�� ������*********************************
		}
		goto NextDwg;
	} // End of �����

	if (bMPLCancel || bMPLExit)
		break;
	// ������ �����
	if (optWindow.GetCheck()) {
		bWinUser = m_regEdit.GetBoolean(_T("MPL"), _T("WinUser"), FALSE);

		// ����ڰ� ������ ����
		if (bWinUser) {
			sErr = _T("�μ� ���� ���� ����");
			//With thisDrawing.Utility
			vSpnt = .GetPoint(, _T("�μ��� ������ ù��° �𼭸� �� ����:"))
			if (IsEmpty(vSpnt)) {
				Me.Show 0;
				return;
			}

			.InitializeUserInput(32);
			vEpnt = .GetCorner(vSpnt, _T("�μ��� ������ �ι�° �𼭸� �� ����:"));
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
		else { // ������ ������
			sErr = _T("���� ������ ����");
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
		sErr = _T("������ ��� ����");
		.SetWindowToPlot(dPlotMin, dPlotMax);
		.PlotType = acWindow;
	} // End of ���������

	// �Ϲ���� ����(�� ����)
	if (!bPlotWindow) {
		if (!optDrawing.GetCheck()) {
			//With pLayout
			sErr = _T("���� ��� ���� ����");
			// ������ ����
			if (chkFitScale.GetCheck())
				.StandardScale = acScaleToFit;
			// �ڵ� ����(A1����)
			else if (chkAutoScaleA1.GetCheck())
				.SetCustomScale(1, dScale * dDiff * dCorrect * dReScale);
			// ������ ��ô
			else
				.SetCustomScale(1, dScale * dDiff * dReScale);
		}
		//With oPlotFile.Plot
		if (chkCopy.GetCheck())
			.NumberOfCopies = 1;
		else
			.NumberOfCopies = GetDlgItemInt(IDC_TBPLOTCNT); // �÷� �ż�

		if (bSelPreview) {
			.DisplayPlotPreview acFullPreview; // �÷� �̸�����
			bPloted = TRUE;
		}
		else {
			if (chkPreviw.GetCheck()) {
				sErr = _T("���� ��� �̸����� ����");
				.DisplayPlotPreview(acFullPreview); // �÷� �̸�����
				bPloted = TRUE;
			}
			else {
				sErr = _T("���� ��� �÷� ����");
				if (chkPLT.GetCheck())
					.PlotToFile(tbPLT);
				else {
					if (!optDrawing.GetCheck())
						.PlotToDevice(cboPlotter); // �÷�
					else
						.PlotToDevice();
					bPloted = TRUE;
				}
			}
		}
	}

	// ���� ������ ����� �̵�
NextDwg:
	// Ȱ��, ����, Ư�����̾ƿ��̸� �ѹ� ���� ����
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
					AfxMessageBox(_T("�׸� ���Ϸ� ����Ϸ��� [���Ϸ� �÷�]�� üũ�� �ֽʽÿ�"), MB_OK | MB_ICONINFORMATION);
					chkPLT.SetFocus();
					return;
				}
			}
		}
		if (sPlotterName.Find(_T("DWG TO PDF")) >= 0) {
			if (!chkPLT.GetCheck()) {
				if (!chkPreviw.GetCheck()) {
					AfxMessageBox(_T("PDF ���Ϸ� ����Ϸ��� [���Ϸ� �÷�]�� üũ�� �ֽʽÿ�"), MB_OK | MB_ICONINFORMATION);
					chkPLT.SetFocus();
					return;
				}
			}
		}
		if (sPlotterName.Find(_T("DWF6 EPLOT")) >= 0 || sPlotterName.Find(_T("DWFX EPLOT")) >= 0) {
			if (!chkPLT.GetCheck()) {
				if (!chkPreviw.GetCheck()) {
					AfxMessageBox(_T("DWF ���Ϸ� ����Ϸ��� [���Ϸ� �÷�]�� üũ�� �ֽʽÿ�"), MB_OK | MB_ICONINFORMATION);
					chkPLT.SetFocus();
					return;
				}
			}
		}
	}

	if (lvwDwg.GetItemCount() < 1) {
		AfxMessageBox(_T("��Ͽ� ����� ������ �����ϴ�"), MB_OK | MB_ICONINFORMATION);
		return;
	}

	GetComboText(&cboPlotter, cstr);
	if (cstr.CompareNoCase(_T("����")) == 0 || cstr.CompareNoCase(_T("none")) == 0) {
		if (!optDrawing.GetCheck()) {
			AfxMessageBox(_T("����� �÷��͸� �����Ͽ� �ֽʽÿ�"), MB_OK | MB_ICONINFORMATION);
			return;
		}
	}

	GetComboText(&cboPaper, cstr);
	if (cstr.CompareNoCase(_T("����")) == 0 || cstr.CompareNoCase(_T("none")) == 0) {
		if (!optDrawing.GetCheck()) {
			AfxMessageBox(_T("����� ������ �����Ͽ� �ֽʽÿ�"), MB_OK | MB_ICONINFORMATION);
			return;
		}
	}

	if (!bSelPreview) {
		if (chkPLT.GetCheck()) {
			tbPLT.GetWindowText(cstr);
			if (cstr == _T("")) {
				AfxMessageBox(_T("������ ������ ��ΰ� �������� �ʾҽ��ϴ�"), MB_OK | MB_ICONINFORMATION);
				cbFind.SetFocus();
				return;
			}
		}
	}

	if (optSpecLayout.GetCheck()) {
		tbLayout.GetWindowText(cstr);
		if (cstr == _T("")) {
			AfxMessageBox(_T("Layout �̸��� �������� �ʾҽ��ϴ�"), MB_OK | MB_ICONINFORMATION);
			tbLayout.SetFocus();
			return;
		}
	}

	if (chkAutoScaleA1.GetCheck()) {
		if (!IsAPaper()) {
			AfxMessageBox(_T("�ڵ� ���� �ɼ��� ����Ϸ��� ������ A �ø��� ������ �����Ͻðų�\n���� ���� ũ��� ����Ϸ��� �ڵ� ���� �ɼ��� ������ �ֽʽÿ�"), MB_OK | MB_ICONINFORMATION);
			chkAutoScaleA1.SetFocus();
			return;
		}
	}

	CString sTemp;
	if (optForm.GetCheck()) {
		sTemp = m_regEdit.GetString(_T("MPL"), _T("AddFormList"), _T(""));
		if (sTemp == _T("")) {
			AfxMessageBox(_T("��ϵ� Form(����)�� �����ϴ�\n[Form ���] ��ư�� ���� Form�� �߰��� �ֽʽÿ�"), MB_OK | MB_ICONINFORMATION);
			cbForm.SetFocus();
			return;
		}
	}

	tbTol.GetWindowTextW(cstr);
	if (cstr == _T("") || _ttof(cstr) <= 0) {
		AfxMessageBox(_T("Form ���� �������� 0 �̻� �������ֽʽÿ�"), MB_OK | MB_ICONINFORMATION);
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
	int iNext; // ���̾ƿ� ��ȯ��
	double dReScale;

	bActive = optActive.GetCheck();
	bModel = optModel.GetCheck();
	bOnlyLayout = optOnlyLayout.GetCheck();
	bModel_Lay = optModelLayout.GetCheck();
	bSpecLayout = optSpecLayout.GetCheck();

	// ��ô �̼� ����
	if (chkReScale.GetCheck()) {
		tbReScale.GetWindowTextW(cstr);
		if (_ttof(cstr) == 0)
			dReScale = 1.0;
		else
			dReScale = 100.0 / _ttof(cstr);
	}
	else
		dReScale = 1.0;

	// �޼��� ����
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

	// ����� ����.
	CDlgMPLExit dlgExit(this);
	dlgExit.Create(CDlgMPL::IDD);
	dlgExit.ShowWindow(SW_SHOWNORMAL);

	CString sErr;
	// ���鿡 ������ �����ΰ� �ƴϸ�
	if (!optDrawing.GetCheck()) {
		// ������ �����νİ����� ����(UserXXX)�� �ٽ� ����
		// ��� ���� ���� ��
		sErr = _T("���� ���� �������� ����");

		// ������ ��ȯ�ϸ鼭 �� ����� �̸��� ���� �޺��ڽ������ ���ؼ� ������ ���������� ����
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

		// ����½� ����� ����/���� ���� �Ǵ�
		// �÷��ͷ� ������ ���� ������ 0Degrees �� �������Ѵ�
		BOOL bHorPaper;
		double dX;
		double dY;
		// ���� ���� ���θ� �Ǵ��ϱ����� ���� ���̾ƿ��� ���� ����
		pPSV->setPlotCfgName(pPlotSettings, sPlotterName); // �÷���
		pPSV->setCanonicalMediaName(pPlotSettings, sName); // ����
		pPlotSettings->getPlotPaperSize(dX, dY);
		if (dX >= dY)
			bHorPaper = TRUE;
		else
			bHorPaper = FALSE;

		// �� ���� ������
		// ���� ������ �������� ������ ��ģ �� �̸� ���� �������� For~Next ���������� �̵�����
		double dPaperH;
		double dYHeight;
		double dXWidth;
		double dMin[2];
		double dMax[2];

		sErr = _T("Form �̸� �������� ����");
		sTemp = m_regEdit.GetString(_T("MPL"), _T("AddFormList"), _T(""));
	}

	// �� ����̸� ���߿� ���� ó���ϵ���
	BOOL bPlotWindow;
	if (optForm.GetCheck())
		bPlotWindow = TRUE;
	else
		bPlotWindow = FALSE;

	// ������ ���� ���� ������ ũ������
	// ���� ���� ���̹Ƿ� ���� ������ ������ ����� 1�� ����
	// ���� ���� �� ��� �κп��� ���� ���
	double dDiff;
	dDiff = 1;

	// ĳ�� ���� ��´�.
	sErr = _T("AutoCAD ���� �������� ����");
	double dVer;
	//dVer = CDbl(Left$(thisDrawing.Application.Version, 4))
	dVer = 16;

	BOOL bOpen; // ���� �ִ� �������� �˻��
	BOOL bPlotErr; // ����½� �� ���� ���� �˻��

	bPlotErr = FALSE;
	CStringArray sLog; // ����� ������ �� ���� ���� ��� ���

	int iInsUnit;
	BOOL bMPLCancel;
	BOOL bMPLExit;
	// ��� ��� �� �ʱ�ȭ
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
	CString sFileName; // ���� ��¿�
	int iFileNum; // ���� ��¿�
	BOOL bPloted; // '���� ���� ��ȯ�� �ѹ��̶� ��µǾ����� true => ����ǥ�� ����
	const GCHAR * sPlotter; // ���鿡 ����� �÷���

	int iCopy; // �μ�ż� ��ȯ��
	int iCopyNum; // �μ�ż� ��

	double dScale;
	BOOL bSavePlot; // ���鿡 ����� ������� ������
	BOOL bRotate; // ���� �����ΰ�?
	BOOL bRealVert; // ����ü�� ���� ����
	const TCHAR* sFormName; // ���V�� ���� ������ �� �̸�
	int iIniPos; // ini�� �� �̸� ��ġ
	long lngReply;

	// ������ �μ� �ż�
	if (chkCopy.GetCheck())
		iCopyNum = GetDlgItemInt(IDC_TBPLOTCNT);
	else
		iCopyNum = 1;
	if (chkPLT.GetCheck())
		iCopyNum = 1;

	int iPlotBack;
	// ���Ͻ� ��� ����
	SetVariable(_T("proxynotice"), 0);
	// AutoCAD 2005 �̻� ��׶��� �÷��� �����´�.
	// �������� PlotToDevice���� �ι�° ������� False ��ȯ���� �߻�
	sErr = _T("Disable BackGroundPlot ����");
	GetVariable(_T("BACKGROUNDPLOT"), iPlotBack);
	SetVariable(_T("BACKGROUNDPLOT"), 0);

	int i;
	int iCnt;
	for (iCopy = 0; iCopy < iCopyNum; iCopy ++) {
		// �̸������ �ѹ� ���� �� ����
		if (bSelPreview)
			iCopy = iCopyNum;

		iCnt = lvwDwg.GetItemCount();
		for (i = 0; i < iCnt; i ++) {
			// �̸������ ������ ���������� ����
			if (bSelPreview) {
				POSITION pos = lvwDwg.GetFirstSelectedItemPosition();
				if (pos)
					i = lvwDwg.GetNextSelectedItem(pos);
				else
					i = 0;
			}

			bSavePlot = TRUE;
			iFileNum = 0; // ���Ϸ� �÷� ī��Ʈ

			// ��� ��� ������ ��� ��ȯ�Ǹ� ���� ��� ���� ���
			if (bMPLCancel || bMPLExit)
				break;

			// �ʱ�ȭ
			bOpen = FALSE;
			bUCS = FALSE;
			bDview = FALSE;
			bPloted = FALSE;

			// �����
			sFileName = lvwDwg.GetItemText(i, 0);
			sDwg = lvwDwg.GetItemText(i, 2) + sFileName;
			int loc = sFileName.ReverseFind('.');
			if (loc >= 0)
				sFileName = sFileName.Right(sFileName.GetLength() - loc);

			// ������ �����ִ� ���� �ٽ� ���� ���� ���� ���� ���
			// ����Ʈ�� ������ ����
			sErr = _T("����Ʈ ���� ���� ����");
			oPlotFile = FindOpenDwg(sDwg);
			if (oPlotFile == NULL) {
				OpenDwgFile(sDwg);
				oPlotFile = FindOpenDwg(sDwg);
				if (oPlotFile == NULL) {
					bPlotErr = TRUE;
					cstr.Format(_T("%s : ������ �� �� �����ϴ�"), lvwDwg.GetItemText(i, 0));
					LogErr(cstr, FALSE);
					cstr.Format(_T("%s ������ �� �� �����ϴ�\n��� �����Ͻðڽ��ϱ�?"), lvwDwg.GetItemText(i, 0));
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
			// ���̾ƿ� ��ȯ��
			//Iterate through all the items in the dictionary
			for (; !pIter->done(); pIter->next()) {
				//With oPlotFile
				// units �ٲ�ٰ� �ؼ� �߰���.. �̻���
				GetVariable(_T("INSUNITS"), iInsUnit);

				// �÷��� ������ ���̾ƿ����� �缳��
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

					// �ɼǿ����� ���̾ƿ� �˻�
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
						// �׳� ����
					}
					else if (bSpecLayout) {
						GetDlgItemText(IDC_TBLAYOUT, cstr);
						pLayout = pLayoutManager->findLayoutNamed(cstr, true);
					}
				}

				pLayoutManager->setCurrentLayout(pLayName);

				// �÷� ���� ������ ����.
				sErr = _T("�÷� ������ ���� ����");
				//.Plot.QuietErrorMode = False

				// �ڵ� �� ���� ��ô ����
				// ���� �Ʒ��� ���� ���
				sErr = _T("�ڵ� �� ���� ��ô ���� ����");
				if (tbScale.IsWindowEnabled()) {
					GetDlgItemText(IDC_TBSCALE, cstr);
					dScale = _ttof(cstr);;
				}

				// ���� ����
				if (optDrawing.GetCheck()) {
					pLayout->getPlotSettingsName(sPlotter);
					if (_tcsicmp(sPlotter, _T("����")) == 0 || _tcsicmp(sPlotter, _T("none")) == 0)
						bSavePlot = FALSE;
					else
						bSavePlot = IsExistCombo(sPlotter, cboPlotter);

					if (!bSavePlot) {
						if (bActive || bModel || bSpecLayout) {
							bPlotErr = TRUE;
							LogErr(oPlotFile->fileName() + _T(" : ���鿡 ����� ��� ������ �����ϴ�."), FALSE);
							goto NextDwg;
						}
						else {
							if (pIter->done()) { // iNext = iLayCnt
								if (!bPloted) {
									bPlotErr = TRUE;
									LogErr(oPlotFile->fileName() + _T(" : ���鿡 ����� ��� ������ �����ϴ�."), FALSE);
									goto NextDwg;
								}
							}
							goto NextLayout;
						}
					}
				}
				else {
					//With oLayout
					sErr = _T("�÷���, ����, ��Ÿ�� �������� ����\n��Ÿ���� STB�� �ƴ� CTB ���Ϸ� ������ �ֽʽÿ�");

					// change the current layout plotter
					GetComboText(&cboPlotter, cstr);
					es = pPSV->setPlotCfgName(pPlotSettings, cstr);
					//.ConfigName = cboPlotter    '�÷���
					//.CanonicalMediaName = sName '����
					//.PlotWithPlotStyles = True  '�÷� ��Ÿ�� ��뿩��
					//.PlotWithLineweights = True
					//.StyleSheet = CStr(lvwDwg.ListItems(i).SubItems(1)) '�÷� ��Ÿ��

					// Ȥ�� ���� �ý����� �⺻ �÷� ��Ÿ���� ����ŷ� �ٲ۴�
					// sErr = "�⺻ �÷� ��Ÿ�� ���� ����"
					// acPref.DefaultPlotStyleTable = CStr(lvwDwg.ListItems(i).SubItems(1))
					// .PlotWithPlotStyles = True

					// �÷� ��ô
					sErr = _T("�÷� ��ô ���� ����");
					if (chkFitScale.GetCheck()) {
						es = pPSV->setUseStandardScale(pPlotSettings, ::kTrue);
						es = pPSV->setStdScaleType(pPlotSettings, GcDbPlotSettings::StdScaleType::kScaleToFit); // ������ ����
					}
					if (tbScale.IsWindowEnabled()) {
						es = pPSV->setUseStandardScale(pPlotSettings, ::kFalse);
						es = pPSV->setCustomPrintScale(pPlotSettings, 1, dScale); // ���� ��ô
					}

					// �÷� ȸ��
					sErr = _T("�÷� ȸ�� ���� ����");
					if (optHor.GetCheck())
						pPSV->setPlotRotation(pPlotSettings, GcDbPlotSettings::PlotRotation::k90degrees);
					else if (optVer.GetCheck())
						pPSV->setPlotRotation(pPlotSettings, GcDbPlotSettings::PlotRotation::k0degrees);

					// �÷� �߾�
					sErr = _T("�÷� �߾� ���� ����");
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

					// Extent, Limit, Layout ���
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

					// �÷� ���� ������ ���� ��� ������ ����
					// 1=inch , 0 = milimeter
					sErr = _T("��� ��ô ���� ����");

					// �׳� �и����ͷ� ��������
					pPSV->setPlotPaperUnits(pPlotSettings, GcDbPlotSettings::kMillimeters);

					// �̰� �����ڵ�
					//If .PaperUnits = 1 Then
					//	dCorrect = 1
					//Else
					//	dCorrect = 25.4
					//End If
					//oPlotFile.Regen acAllViewports
				}

				// ������϶�
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
						//CmdPrompt "����(Form) ���� :"
						//oSel.SelectOnScreen iGcode, vData
						while(1) {
							// Let the user select an INSERT (Block reference).
							if (gcedEntSel(L"\nForm�� �ش�Ǵ� ��ü�� ���� : ", ename, pt) != RTNORM)
								break;

							// Test the entity type.
							gcdbGetObjectId(objId, ename);
							if ((es = gcdbOpenGcDbEntity(pEnt, objId, GcDb::kForRead)) != Gcad::eOk) {
								AfxMessageBox (_T("������ ��ü�� �� �� �����ϴ�."), MB_OK | MB_ICONINFORMATION);
								continue;
							}

							pInsert = GcDbBlockReference::cast(pEnt);
							if (!pInsert) {
								AfxMessageBox (_T("������ ��ü�� INSERT�� �ƴմϴ�."), MB_OK | MB_ICONINFORMATION);
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
							LogErr(oPlotFile.Name + _T(" : ���鿡 ������ �̸��� Form�� �����ϴ� - ") + sTemp, FALSE);
							goto NextDwg;
						}
						else {
							if (iNext == iLayCnt) {
								if (!bPloted) {
									bPlotErr = TRUE;
									LogErr(oPlotFile.Name + _T(" : ���鿡 ������ �̸��� Form�� �����ϴ� - ") + sTemp, FALSE);
									goto NextDwg;
								}
							}
							goto NextLayout;
						}
					}

					double dtol;
					GetDlgItemText(IDC_TBTOL, cstr);
					dtol = _ttof(cstr);
					// �ܺ�����1�� �̻�� �μ�Ʈ ����Ʈ�� ��Ʈ
					sErr = _T("Form Sort ����");
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
							// �����μ�
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

					sErr = _T("�Ϻ� ��� �Է� ����");
					iPartS = GetDlgItemInt(IDC_TBPARTS);
					iPartE = GetDlgItemInt(IDC_TBPARTE);

					// �ѵ��� ���� ���� �� ��ȯ
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

						// ���� ����
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

						// ��� ��� ������ ��� ��ȯ�Ǹ� ���� ���� ���
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
							bRotate = IsVerDwg(pInsert->rotation()); // false = ���ε���
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

						// ���� ���� ���� �����̸� ���� ���� �����´�
						if (bRealVert)
							bRotate = !bRotate;

						// ������ ���� ���� ������ ũ������
						if (!bRotate) { // ȸ�� �ȵ� ����
							if (bVertical) {
								dDiff = dSelVer / dXWidth;
								// ����� ������(Two Array)
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
						// �����켳��.PlotType�� SetWindowToPlot �ڿ� ����� ��
						pPSV->setPlotWindowArea(pPlotSettings, dPlotMin[X], dPlotMin[Y], dPlotMax[X], dPlotMax[Y]);
						pPSV->setPlotType(pPlotSettings, GcDbPlotSettings::kWindow);

						// '���� �������� ��찡 �����Ƿ� ������� ��ȯ�ϸ鼭 �Ʒ��� ���ľ� �Ѵ�.
						sErr = _T("Form ���� ����");
						if (chkFitScale.GetCheck()) // ������ ����
							pPSV->setStdScaleType(pPlotSettings, GcDbPlotSettings::StdScaleType::kScaleToFit);
						else if (chkAutoScaleA1.GetCheck()) // �ڵ� ����(A1����)
							pPSV->setCustomPrintScale(pPlotSettings, 1, dScale * dDiff * dCorrect * dReScale);
						else // ������ ��ô
							pPSV->setCustomPrintScale(pPlotSettings, 1, dScale * dDiff * dReScale);

						//With oPlotFile.Plot
						//if (chkCopy.GetCheck())
						//	oPlotFile->NumberOfCopies = 1;
						//else
						//	pPlotSettings->NumberOfCopies = GetDlgItemInt(IDC_TBPLOTCNT); // �÷� �ż�

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


							.DisplayPlotPreview acFullPreview; // �÷� �̸�����
							bPloted = TRUE;
						}
						else {
							If chkPreviw = True Then
								sErr = "�÷� �̸����� ����"
								.DisplayPlotPreview acFullPreview '�÷� �̸�����
								bPloted = True
							Else
								sErr = "�÷� ����"
								If chkPLT Then
									'���� ��� ���ϳ��� ������ �������� �Ʒ����� ���� ������ k�� ��½�
									'��ȣ�� �ٸ��� �������� ��ġ�ΰ�� ��ġ�ϳ��� ���� �ϳ���
									'�Ʒ� k�� ����ϴ� ��� ��ġ �ϳ��� ���� �Ѱ��� k�� ��� 0 �̵�
									'���� iFileNum ������ �ΰ�
									'���� ���� k �� �׳� ���
									'��ġ�� ���� iFileNum �����ؼ� ���� �ٸ��� �Ѵ�
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
									.PlotToDevice cboPlotter      '�÷�
								End If
								bPloted = True
							End If
						End If
						SetDelay CLng(tbDelay)
NextPart:
					Next // End of �ѵ��鳻�� ������
					GoTo NextDwg
				End If // End of �����

				If bMPLCancle Or bMPLExit Then Exit For
				// ������ ����϶�
				If optWIndow Then
					bWinUser = ini.ReadIni(sPubPath, "MPL", "WinUser", False)

					'����ڰ� ������ ����
					If bWinUser Then
						sErr = "�μ� ���� ���� ����"
						With thisDrawing.Utility
							vSpnt = .GetPoint(, "�μ��� ������ ù��° �𼭸� �� ����:")
							If IsEmpty(vSpnt) Then Me.Show 0: Exit Sub

							On Error Resume Next
							.InitializeUserInput 32
							vEpnt = .GetCorner(vSpnt, "�μ��� ������ �ι�° �𼭸� �� ����:")
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

					'������ ������
					Else
						sErr = "���� ������ ����"
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
						sErr = "������ ��� ����"
						.SetWindowToPlot dPlotMin, dPlotMax
						.PlotType = acWindow
					End With

				End If // End of ���������

				// �Ϲ���� ����(�� ����)
				If Not bPlotWindow Then
					If Not optDrawing Then
						With oLayout
							sErr = "���� ��� ���� ����"
							'������ ����
							If chkFitScale = True Then
								.StandardScale = acScaleToFit
							'�ڵ� ����(A1����)
							ElseIf chkAutoScaleA1 = True Then
								.SetCustomScale 1, dScale * dDiff * dCorrect * dReScale
							'������ ��ô
							Else
								.SetCustomScale 1, dScale * dDiff * dReScale
							End If
						End With
					End If

					With oPlotFile.Plot
						If chkCopy Then
							.NumberOfCopies = 1
						Else
							.NumberOfCopies = CInt(tbPlotCnt) '�÷� �ż�
						End If

						If bSelPreview Then
							.DisplayPlotPreview acFullPreview   '�÷� �̸�����
							bPloted = True
						Else
							If chkPreviw Then
								sErr = "���� ��� �̸����� ����"
								.DisplayPlotPreview acFullPreview   '�÷� �̸�����
								bPloted = True
							Else
								sErr = "���� ��� �÷� ����"
								If chkPLT Then
									.PlotToFile tbPLT
								Else
									If Not optDrawing Then
										.PlotToDevice cboPlotter        '�÷�
									Else
										.PlotToDevice
									End If
									bPloted = True
								End If
							End If
						End If
					End With
				End If

			// ���� ������ ����� �̵�
NextDwg:
				// Ȱ��, ����, Ư�����̾ƿ��̸� �ѹ� ���� ����
				if (bActive || optModel || bSpecLayout)
					break;
NextLayout:
			} // Layout Iterator

////////////////////////////////////////////////////////////////////////////////
			// ���������� ���� �ʰ�, ViewUCS ������ ���󺹱�
			if (bOpen) {
				if (bDview)
					SetViewUcs(FALSE);
			}
			else
				oPlotFile.Close(FALSE);
			if (!bPlotWindow)
				SetDelay(GetDlgItemInt(IDC_TBDELAY));

			// �̸������ ������ ���������� ó�������� ��ȯ���� �ʰ� ����
			if (bSelPreview)
				break;
		} // next i, �������� ��
	} // next iCopy, �μ�ż�

	FormMPLExit.ShowWindow(SW_HIDE);

	// Ȥ�� ���� ÷���ߴ� �÷� ��Ÿ�� ����
	// sErr = "�÷� ��Ÿ�� ���� ����"
	// acPref.DefaultPlotStyleTable = sOldStyle

	oPlotFile = NULL;
	oLayout = NULL;
	acPref = NULL;

	// �ý��� �����ǵ���
	sErr = _T("�ý��� ���� �ǵ��� ����");
	//With thisDrawing
	if (dVer > 16)
		SetVariable(_T("BACKGROUNDPLOT"), iPlotBack);
	SetVariable(_T"Expert"), iExpert);
	SetVariable(_T"DWGCHECK"), iDwgCheck);
	sErr = _T("�÷� ����Ʈ �ۼ� ����");
	if (bPlotErr)
		PlotErrReport();

	if (chkPreviw.GetCheck())
		bMPLCancel = TRUE;
	if (!bMPLCancel && !bMPLExit)
		Unload Me; // �̸������ ��ҳ� ���� �ȴ������
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

// SelectionSet�� �ִ� Entity �߿��� CurrentSpace�� �ִ� Entity�� ����
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
	cmsg.Format(_T("�÷Ե��� ���� ������ �ֽ��ϴ�\nC:\\PlotError.txt ������ Ȯ���ϼ���"));
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


// ���� �߰�
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
		_T("�������� (*.dwg)|*.dwg|All Files(*.*)|*.*||"));
	filDlg.m_ofn.lpstrTitle = _T("���� �߰�"); 
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

		// ù��° �÷��� �����̸�, �ι�°�� �÷Խ�Ÿ��, ����°�� ���
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
		AfxMessageBox(_T("�̹� ��ϵ� ������ ���ܵǾ����ϴ�"), MB_OK | MB_ICONINFORMATION);

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
		msgStr.Format(_T("'%s' ������ �� �� �����ϴ�."), dirName);
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


// ���� �߰�
void CDlgMPL::OnBnClickedCbfolder()
{
	BROWSEINFO browInfo;
	LPITEMIDLIST itemList;
	TCHAR dirPath[MAX_PATH];

	memset(&browInfo, 0, sizeof (BROWSEINFO));
	browInfo.hwndOwner = m_hWnd;
	browInfo.lpszTitle = _T("�Է� ����");
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


// Ȱ�� ���� �߰�
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
		AfxMessageBox(_T("�̹� ��ϵ� ������ ���ܵǾ����ϴ�"), MB_OK | MB_ICONINFORMATION);
}


// ���� ���� �߰�
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
		AfxMessageBox(_T("�̹� ��ϵ� ������ ���ܵǾ����ϴ�"), MB_OK | MB_ICONINFORMATION);
}


// ���� �׸� ����
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


// ����Ʈ�� ���� �׸� ����
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


// ����Ʈ�� ��ü �׸� ����
void CDlgMPL::OnBnClickedCbdelall()
{
	lvwDwg.DeleteAllItems();
	lvwDwg.SetFocus();
	LabelMsg();
}


// ����Ʈ�� ������ �̵�
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


// ����Ʈ�� �ǾƷ��� �̵�
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


// ����Ʈ�� ���� �̵�
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


// ����Ʈ�� �Ʒ��� �̵�
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


// �÷� ��� �ؽ�Ʈ���Ϸ� ����
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
		AfxMessageBox(_T("��Ͽ� ������ ������ �����ϴ�"), MB_OK | MB_ICONINFORMATION);
		return;
	}

	sOldPath = m_regEdit.GetString(_T("MPL"), _T("SaveFolder"), _T("C:\\"));

	CFileDialog filDlg(FALSE, NULL, NULL, OFN_HIDEREADONLY,
		_T("�ؽ�Ʈ ���� (*.txt)|*.txt|All Files(*.*)|*.*||"));
	filDlg.m_ofn.lpstrTitle = _T("��� �ؽ�Ʈ ���� ����"); 
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


// �÷� ��� ����
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
		_T("�ؽ�Ʈ ���� (*.txt)|*.txt|All Files(*.*)|*.*||"));
	filDlg.m_ofn.lpstrTitle = _T("��� ��� �ؽ�Ʈ ���� ����"); 
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
		AfxMessageBox(_T("���� �÷� ���� ����� �ƴϰų� ���� ���������� �ۼ��� ����Դϴ�\n���� ������ ȣȯ���� �����Ƿ�\n���� �߰� ������� ������ �߰��� �ֽʽÿ�"), MB_OK | MB_ICONINFORMATION);
		fclose(fin);
		return;
	}

	while (_fgetts(sData, 1024, fin)) {
		cstr = sData;
		cstr.Trim();

		// ���ϸ�,���,��Ÿ��
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
		AfxMessageBox(_T("�̹� ��ϵ� ������ ���ܵǾ����ϴ�"), MB_OK | MB_ICONINFORMATION);
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


// ��� ����
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

	//// ����� ���� �����
	//For i = 1 To iCnt
	//	sItem(i) = .ListItems(i).Text & "?" & .ListItems(i).SubItems(1) & "?" & .ListItems(i).SubItems(2)
	//Next
	//If optAscend Then
	//	func.AlphanumSort sItem
	//Else
	//	func.AlphanumSort sItem, True
	//End If

	//// ��� ����
	//lvwDwg.DeleteAllItems();
	//.ListItems.Clear

	//'�ٽ� ��� �ø���
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
		cstr = _T("��Ͽ� ������ �߰��� �ֽʽÿ�");
	}
	else
		cstr.Format(_T("�� %d ���� ������ ��Ͽ� �߰���"), iCnt);

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
		cbOK.SetWindowText(_T("�̸�����"));
		chkSelForm.SetWindowText(_T("���鿡�� ������ Form�� �̸�����"));
	}
	else {
		cbOK.SetWindowText(_T("�� ��"));
		chkSelForm.SetWindowText(_T("���鿡�� ������ Form�� ���"));
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


// �÷��� ���濡 ���� �������� ����
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

	// ��������
	//oLayout.RefreshPlotDeviceInfo

	GetComboText(&cboPlotter, pltNam);
	if (pltNam.CompareNoCase(_T("����")) == 0 || pltNam.CompareNoCase(_T("none")) == 0) {
		cboPaper.AddString(_T("����"));
		cboPaper.SetCurSel(0);
		return;
	}

	CString cmsg;
	// ������ �÷��͸� ���� �÷��ͷ�
	if (pPSV->setPlotCfgName(oLayout, pltNam) != Gcad::eOk) {
		cmsg.Format(_T("%s ������ �߸��� PC3 ���� �Ǵ� ���ῡ �����ִ� �������Դϴ�\n�ٸ� �����͸� ������ �ֽʽÿ�"), pltNam);
		AfxMessageBox(cmsg, MB_OK | MB_ICONSTOP);
		return;
	}
	pPSV->refreshLists(oLayout);

	// ��� ���� ���� ��
	GcArray<const GCHAR *> mMediaList;
	const GCHAR *pLocaleName;
	CStringArray sPaper;
	int iCnt;
	int i;

	pPSV->canonicalMediaNameList(oLayout, mMediaList);

	// ������ ��ȯ�ϸ鼭 �� ����� �̸��� �ٽ� �޴´�
	// ���� ������ Userxxxx �� �����°� ����
	iCnt = mMediaList.length();
	for (i = 0; i < iCnt; i ++) {
		//get the localename
		pPSV->getLocaleMediaName(oLayout, mMediaList.at(i), pLocaleName);
		sPaper.Add(pLocaleName);
	}

	// ��Ʈ�ؼ� �޺��ڽ��� �ø�
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


// ������ ����
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


// �ڵ� ����(A1����)
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


// �÷� �߽�
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
		optSpecLayout.SetWindowText(_T("Ư�� Layout"));
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
			AfxMessageBox(_T("��� Layout ����� ��� WIndow �÷� ���� �ɼ��� ����� �� �����ϴ�\n�ٸ� �ɼ��� �������ֽʽÿ�"), MB_OK | MB_ICONSTOP);
			optForm.SetCheck(TRUE);
			return;
		}
		ControlEnable3();
	}
	else if (optModelLayout.GetCheck()) {
		optLimit.SetWindowText(_T("Limits �Ǵ� Layout"));
		if (optWindow.GetCheck()) {
			AfxMessageBox(_T("Model + ��� Layout ����� ��� WIndow �÷� ���� �ɼ��� ����� �� �����ϴ�\n�ٸ� �ɼ��� �������ֽʽÿ�"), MB_OK | MB_ICONSTOP);
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
		//cbScaleView.ControlTipText = "Form ��ô �� �̸� ����";
		OnBnClickedChkautoscalea1();
	}
	else if (optWindow.GetCheck()) {
		if (optOnlyLayout.GetCheck() || optModelLayout.GetCheck()) {
			AfxMessageBox(_T("��� Layout ����� ��� �� �ɼ��� ����� �� �����ϴ�\n�ٸ� �ɼ��� �������ֽʽÿ�"), MB_OK | MB_ICONSTOP);
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
		//cbScaleView.ControlTipText = "��� ���� ��ô ����"
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
	// ��ġ���� Layout�� ��������X, �÷��߽�X
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


// ���� �������� �˻�
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

	// ���̷� ��
	if (!bVert) { // ����
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


// ���� �߻��� �αױ��
void CDlgMPL::LogErr(LPCTSTR sError, BOOL bEnd)
{
	CString fNam;
	FILE *fp;
	int i, len;

	sLog.Add(sError);

	// ���ϱ��
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


void CDlgMPL::SetDelay(long lngCount) // ��
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
	//		.AddItem "����"
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

	// ȯ�漳�� ����
	LoadIni();

	OnCbnSelchangeCboplotter();

	// ��Ʈ�� Ȱ��
	tbPartS.ShowWindow(SW_HIDE);
	Label12.ShowWindow(SW_HIDE);
	tbPartE.ShowWindow(SW_HIDE);

	int sngWidth;
	CRect crec;
	lvwDwg.GetClientRect(crec);
	sngWidth = crec.Width();

	lvwDwg.ModifyStyle (0, LVS_REPORT | LVS_SHOWSELALWAYS);
	lvwDwg.SetExtendedStyle (LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	lvwDwg.InsertColumn (0, _T("���ϸ�"), LVCFMT_LEFT, sngWidth * 6 / 10, 0);
	lvwDwg.InsertColumn (1, _T("�÷Խ�Ÿ��"), LVCFMT_LEFT, sngWidth * 4 / 10, 0);
	lvwDwg.InsertColumn (2, _T("��ü���"), LVCFMT_LEFT, 0, 0);

	if (lvwDwg.GetItemCount() < 1)
		lblCount.SetWindowTextW(_T("��Ͽ� ������ �߰��� �ֽʽÿ�"));

	cbScaleView.SubclassDlgItem(IDC_CBSCALEVIEW, this);
	cbScaleView.SetImage(IDB_SEARCH);

	ThumbView.SubclassDlgItem(IDC_THUMBVIEW, this);
	ThumbView.SetBkgColor(0xffffff);

	OnBnClickedChkplotcenter();
	OnBnClickedChkplt();
	OnBnClickedChkrescale();

AppendDir(_T("C:\\Temp\\0000"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
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

