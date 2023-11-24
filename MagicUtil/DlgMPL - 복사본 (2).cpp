// DlgMPL.cpp : ���� �����Դϴ�.
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


// CDlgMPL �޽��� ó�����Դϴ�.


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
	long iNext; // ���̾ƿ� ��ȯ��
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
		AfxMessageBox(_T("��Ͽ� ����� ������ �����ϴ�"), MB_OK | MB_ICONINFORMATION);
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
					AfxMessageBox(_T("�׸� ���Ϸ� ����Ϸ��� [���Ϸ� �÷�]�� üũ�� �ֽʽÿ�"), MB_OK | MB_ICONINFORMATION);
					chkPLT.SetFocus();
					return;
				}
			}
		}
		if (cstr.Find(_T("DWG TO PDF")) >= 0) {
			if (!chkPLT.GetCheck()) {
				if (!chkPreviw.GetCheck()) {
					AfxMessageBox(_T("PDF ���Ϸ� ����Ϸ��� [���Ϸ� �÷�]�� üũ�� �ֽʽÿ�"), MB_OK | MB_ICONINFORMATION);
					chkPLT.SetFocus();
					return;
				}
			}
		}
		if (cstr.Find(_T("DWF6 EPLOT")) >= 0 || cstr.Find(_T("DWFX EPLOT")) >= 0) {
			if (!chkPLT.GetCheck()) {
				if (!chkPreviw.GetCheck()) {
					AfxMessageBox(_T("DWF ���Ϸ� ����Ϸ��� [���Ϸ� �÷�]�� üũ�� �ֽʽÿ�"), MB_OK | MB_ICONINFORMATION);
					chkPLT.SetFocus();
					return;
				}
			}
		}
	}

	if (plotterName.CompareNoCase(_T("����")) == 0 || plotterName.CompareNoCase(_T("none")) == 0) {
		if (!optDrawing.GetCheck()) {
			AfxMessageBox(_T("����� �÷��͸� �����Ͽ� �ֽʽÿ�"), MB_OK | MB_ICONINFORMATION);
			return;
		}
	}

	CString paperName;
	GetComboText(&cboPaper, paperName);
	if (paperName.CompareNoCase(_T("����")) == 0 || paperName.CompareNoCase(_T("none")) == 0) {
		if (!optDrawing.GetCheck()) {
			AfxMessageBox(_T("����� ������ �����Ͽ� �ֽʽÿ�"), MB_OK | MB_ICONINFORMATION);
			return;
		}
	}

	if (!previewPlot) {
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


	CString formList;
	if (optForm.GetCheck()) {
		formList = m_regEdit.GetString(_T("MPL"), _T("AddFormList"), _T(""));
		formList.Trim();
		if (formList.IsEmpty()) {
			AfxMessageBox(_T("��ϵ� Form(����)�� �����ϴ�\n[Form ���] ��ư�� ���� Form�� �߰��� �ֽʽÿ�"), MB_OK | MB_ICONINFORMATION);
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
	// ���鿡 ������ �����ΰ� �ƴϸ�
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
			AfxMessageBox(_T("�÷��Ϳ��� ������ ������ ã�� �� �����ϴ�."), MB_OK | MB_ICONWARNING);
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
	BOOL bSavePlot; // ���鿡 ����� ������� ������
	BOOL bRotate; // ���� �����ΰ�?
	BOOL bRealVert; // ����ü�� ���� ����
	const TCHAR* sFormName; // ���V�� ���� ������ �� �̸�
	int iIniPos; // ini�� �� �̸� ��ġ
	//long lngReply;

	CGcadLayouts oLayouts;
	GcDbExtents extents;
	CGcadPlot IPlot;
	int iCnt;
	int i;

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

	for (iCopy = 0; iCopy < iCopyNum; iCopy ++) {
		// �̸������ �ѹ� ���� �� ����
		if (previewPlot)
			iCopy = iCopyNum;

		iCnt = lvwDwg.GetItemCount();
		for (i = 0; i < iCnt; i ++) {
			// �̸������ ������ ���������� ����
			if (previewPlot) {
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
			sDwg = lvwDwg.GetItemText(i, 3);
			int loc = sFileName.ReverseFind('.');
			if (loc >= 0)
				sFileName = sFileName.Left(loc);

			// ������ �����ִ� ���� �ٽ� ���� ���� ���� ���� ���
			// ����Ʈ�� ������ ����
			sErr = _T("����Ʈ ���� ���� ����");
			if (!FindOpenDwg(sDwg, oPlotFile)) {
				OpenDwgFile(sDwg);
				if (!FindOpenDwg(sDwg, oPlotFile)) {
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

			// ���̾ƿ� ��ȯ��
			//Iterate through all the items in the dictionary
			for (iNext = 0; iNext < iLayCnt; iNext ++) {
				//SafeArrayGetElement(mLayArr.parray, &iNext, &bstrName);
				//With oPlotFile
				// units �ٲ�ٰ� �ؼ� �߰���.. �̻���
				GetVariable(_T("INSUNITS"), iInsUnit);

				// �÷��� ������ ���̾ƿ����� �缳��
				if (bActive) {
					pDisp = oPlotFile.get_ActiveLayout(); 
					oLayout.AttachDispatch(pDisp);
					pLayName = oLayout.get_Name();
				}
				else {
					pDisp = oLayouts.Item(_variant_t(iNext));
					oLayout.AttachDispatch(pDisp);
					pLayName = oLayout.get_Name();

					// �ɼǿ����� ���̾ƿ� �˻�
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
						// �׳� ����
					}
					else if (bSpecLayout) {
						GetDlgItemText(IDC_TBLAYOUT, cstr);
						pDisp = oLayouts.Item(_variant_t(cstr));
						oLayout.AttachDispatch(pDisp);
						pLayName = oLayout.get_Name();
					}
					oPlotFile.put_ActiveLayout(oLayout);
				}

				// �÷� ���� ������ ����.
				sErr = _T("�÷� ������ ���� ����");
				pDisp = oPlotFile.get_Plot();
				IPlot.AttachDispatch(pDisp);
				IPlot.put_QuietErrorMode(FALSE);

				// �ڵ� �� ���� ��ô ����
				// ���� �Ʒ��� ���� ���
				sErr = _T("�ڵ� �� ���� ��ô ���� ����");
				if (tbScale.IsWindowEnabled()) {
					GetDlgItemText(IDC_TBSCALE, cstr);
					dScale = _ttof(cstr);;
				}

				// ���� ����
				if (optDrawing.GetCheck()) {
					sPlotter = oLayout.get_ConfigName();
					if (sPlotter.CompareNoCase(_T("����")) == 0 || sPlotter.CompareNoCase(_T("none")) == 0)
						bSavePlot = FALSE;
					else
						bSavePlot = IsExistCombo(sPlotter, &cboPlotter);

					if (!bSavePlot) {
						if (bActive || bModel || bSpecLayout) {
							bPlotErr = TRUE;
							LogErr(oPlotFile.get_Name() + _T(" : ���鿡 ����� ��� ������ �����ϴ�."), FALSE);
							goto NextDwg;
						}
						else {
							if (iNext == (iLayCnt - 1)) {
								if (!bPloted) {
									bPlotErr = TRUE;
									LogErr(oPlotFile.get_Name() + _T(" : ���鿡 ����� ��� ������ �����ϴ�."), FALSE);
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
					oLayout.put_ConfigName(cstr); // �÷���
					oLayout.put_CanonicalMediaName(sName); // ����
					oLayout.put_PlotWithPlotStyles(TRUE); // �÷� ��Ÿ�� ��뿩��
					oLayout.put_PlotWithLineweights(TRUE);
					cstr = lvwDwg.GetItemText(i, 1);
					oLayout.put_StyleSheet(cstr); // �÷� ��Ÿ��

					// Ȥ�� ���� �ý����� �⺻ �÷� ��Ÿ���� ����ŷ� �ٲ۴�
					// sErr = "�⺻ �÷� ��Ÿ�� ���� ����"
					// acPref.DefaultPlotStyleTable = CStr(lvwDwg.ListItems(i).SubItems(1))
					// .PlotWithPlotStyles = True

					// �÷� ��ô
					sErr = _T("�÷� ��ô ���� ����");
					if (chkFitScale.GetCheck()) {
						oLayout.put_UseStandardScale(TRUE);
						oLayout.put_StandardScale(acScaleToFit);
					}
					if (tbScale.IsWindowEnabled()) {
						oLayout.put_UseStandardScale(FALSE);
						oLayout.SetCustomScale(1, dScale); // ���� ��ô
					}

					// �÷� ȸ��
					sErr = _T("�÷� ȸ�� ���� ����");
					if (optHor.GetCheck())
						oLayout.put_PlotRotation(ac90degrees);
					else if (optVer.GetCheck())
						oLayout.put_PlotRotation(ac0degrees);

					// �÷� �߾�
					sErr = _T("�÷� �߾� ���� ����");
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

					// Extent, Limit, Layout ���
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

					// �÷� ���� ������ ���� ��� ������ ����
					// 1=inch , 0 = milimeter
					sErr = _T("��� ��ô ���� ����");

					// �׳� �и����ͷ� ��������
					oLayout.put_PaperUnits(acMillimeters);

					// �̰� �����ڵ�
					//If .PaperUnits = 1 Then
					dCorrect = 1;
					//Else
					//	dCorrect = 25.4
					//End If
					oPlotFile.Regen(acAllViewports);
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
							LogErr(oPlotFile.get_Name() + _T(" : ���鿡 ������ �̸��� Form�� �����ϴ� - ") + sTemp, FALSE);
							goto NextDwg;
						}
						else {
							if (iNext == iLayCnt) {
								if (!bPloted) {
									bPlotErr = TRUE;
									LogErr(oPlotFile.get_Name() + _T(" : ���鿡 ������ �̸��� Form�� �����ϴ� - ") + sTemp, FALSE);
									goto NextDwg;
								}
							}
							goto NextLayout;
						}
					}

					sErr = _T("�Ϻ� ��� �Է� ����");

					// �ѵ��� ���� ���� �� ��ȯ
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
						if (bMPLCancel || bMPLExit)
							break;

						if (bUCS) {
							//With oSel.Item(k)
							if (dTwAng != 0)
								Rotate(pInsert, dZero, dTwAng);
							bRotate = IsVerDwg(pInsert->rotation()); // false = ���ε���
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
						// �����켳��.PlotType�� SetWindowToPlot �ڿ� ����� ��
						VARIANT var1, var2;
						Point2d2Array(&var1, dPlotMin);
						Point2d2Array(&var2, dPlotMax);
						oLayout.SetWindowToPlot(var1, var2);
						oLayout.put_PlotType(acWindow);

						// '���� �������� ��찡 �����Ƿ� ������� ��ȯ�ϸ鼭 �Ʒ��� ���ľ� �Ѵ�.
						sErr = _T("Form ���� ����");
						if (chkFitScale.GetCheck()) { // ������ ����
							oLayout.put_UseStandardScale(TRUE);
							oLayout.put_StandardScale(acScaleToFit);
						}
						else if (chkAutoScaleA1.GetCheck()) { // �ڵ� ����(A1����)
							oLayout.put_UseStandardScale(FALSE);
							oLayout.SetCustomScale(1, dScale * dDiff * dCorrect * dReScale);
						}
						else { // ������ ��ô
							oLayout.put_UseStandardScale(FALSE);
							oLayout.SetCustomScale(1, dScale * dDiff * dReScale);
						}

						//With oPlotFile.Plot
						if (chkCopy.GetCheck())
							IPlot.put_NumberOfCopies(1);
						else
							IPlot.put_NumberOfCopies(GetDlgItemInt(IDC_TBPLOTCNT)); // �÷� �ż�

						if (previewPlot) {
							IPlot.DisplayPlotPreview(acFullPreview); // �÷� �̸�����
							bPloted = TRUE;
						}
						else {
							if (chkPreviw.GetCheck()) {
								sErr = _T("�÷� �̸����� ����");
								IPlot.DisplayPlotPreview(acFullPreview); // �÷� �̸�����
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
									IPlot.PlotToDevice(_variant_t(cstr)); // �÷�
								}
								bPloted = TRUE;
							}
						}
						int dTim = GetDlgItemInt(IDC_TBDELAY);
						if (dTim > 0)
							Sleep(dTim * 1000);
					} // End of �ѵ��鳻�� ������
					goto NextDwg;
				} // End of �����

				if (bMPLCancel || bMPLExit)
					break;
				// ������ ����϶�
				if (optWindow.GetCheck()) {
					bWinUser = m_regEdit.GetBoolean(_T("MPL"), _T("WinUser"), FALSE);

					// ����ڰ� ������ ����
					if (bWinUser) {
						sErr = _T("�μ� ���� ���� ����");
						if (gcedGetPoint(NULL, _T("�μ��� ������ ù��° �𼭸� �� ����:"), asDblArray(vSpnt)) != RTNORM) {
							ShowWindow(SW_HIDE);
							return;
						}

						if (gcedGetCorner(asDblArray(vSpnt), _T("�μ��� ������ �ι�° �𼭸� �� ����:"), asDblArray(vEpnt)) != RTNORM) {
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
						// ������ ������
						sErr = _T("���� ������ ����");
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

					sErr = _T("������ ��� ����");
					VARIANT var1, var2;
					Point2d2Array(&var1, dPlotMin);
					Point2d2Array(&var2, dPlotMax);
					oLayout.SetWindowToPlot(var1, var2);
					oLayout.put_PlotType(acWindow);
				} // End of ���������

				// �Ϲ���� ����(�� ����)
				if (!bPlotWindow) {
					if (!optDrawing) {
						sErr = _T("���� ��� ���� ����");
						// ������ ����
						if (chkFitScale.GetCheck()) {
							oLayout.put_UseStandardScale(TRUE);
							oLayout.put_StandardScale(acScaleToFit);
						}
						// �ڵ� ����(A1����)
						else if (chkAutoScaleA1.GetCheck()) {
							oLayout.put_UseStandardScale(FALSE);
							oLayout.SetCustomScale(1, dScale * dDiff * dCorrect * dReScale);
						}
						// ������ ��ô
						else {
							oLayout.put_UseStandardScale(FALSE);
							oLayout.SetCustomScale(1, dScale * dDiff * dReScale);
						}
					}

					if (chkCopy.GetCheck())
						IPlot.put_NumberOfCopies(1);
					else
						IPlot.put_NumberOfCopies(GetDlgItemInt(IDC_TBPLOTCNT)); // �÷� �ż�

					if (previewPlot) {
						IPlot.DisplayPlotPreview(acFullPreview); // �÷� �̸�����
						bPloted = TRUE;
					}
					else {
						if (chkPreviw.GetCheck()) {
							sErr = _T("���� ��� �̸����� ����");
							IPlot.DisplayPlotPreview(acFullPreview); // �÷� �̸�����
							bPloted = TRUE;
						}
						else {
							sErr = _T("���� ��� �÷� ����");
							if (chkPLT.GetCheck()) {
								GetDlgItemText(IDC_TBPLT, cstr);
								IPlot.PlotToFile(cstr, _variant_t(sPlotterName));
							}
							else {
								if (!optDrawing.GetCheck()) {
									GetComboText(&cboPlotter, cstr);
									IPlot.PlotToDevice(_variant_t(cstr)); // �÷�
								}
								else
									IPlot.PlotToDevice(_variant_t(sPlotterName));
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
				;
			} // Layout Iterator

////////////////////////////////////////////////////////////////////////////////
			// ���������� ���� �ʰ�, ViewUCS ������ ���󺹱�
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

			// �̸������ ������ ���������� ó�������� ��ȯ���� �ʰ� ����
			if (previewPlot)
				break;
		} // next i, �������� ��
	} // next iCopy, �μ�ż�

	dlgExit.ShowWindow(SW_HIDE);
	CompleteEditorCommand();

	// Ȥ�� ���� ÷���ߴ� �÷� ��Ÿ�� ����
	// sErr = "�÷� ��Ÿ�� ���� ����"
	// acPref.DefaultPlotStyleTable = sOldStyle

	//oPlotFile = NULL;
	//oLayout = NULL;
	//acPref = NULL;

	// �ý��� �����ǵ���
	sErr = _T("�ý��� ���� �ǵ��� ����");
	//With thisDrawing
	if (dVer > 16)
		SetVariable(_T("BACKGROUNDPLOT"), iPlotBack);
	SetVariable(_T("Expert"), iExpert);
	SetVariable(_T("DWGCHECK"), iDwgCheck);
	sErr = _T("�÷� ����Ʈ �ۼ� ����");
	if (bPlotErr)
		PlotErrReport();

	if (chkPreviw.GetCheck())
		bMPLCancel = TRUE;
	if (!bMPLCancel && !bMPLExit)
		CGcUiDialog::OnCancel(); // �̸������ ��ҳ� ���� �ȴ������
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
	CString filPth, filNam;
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
		AfxMessageBox(_T("�̹� ��ϵ� ������ ���ܵǾ����ϴ�"), MB_OK | MB_ICONINFORMATION);

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

	AppendDir(dirPath, _T("*.dwg"));
}


// Ȱ�� ���� �߰�
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
		AfxMessageBox(_T("�̹� ��ϵ� ������ ���ܵǾ����ϴ�"), MB_OK | MB_ICONINFORMATION);
}


// ���� ���� �߰�
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
		AfxMessageBox(_T("�̹� ��ϵ� ������ ���ܵǾ����ϴ�"), MB_OK | MB_ICONINFORMATION);
}


// ���� �׸� ����
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
}


// ����Ʈ�� ��ü �׸� ����
void CDlgMPL::OnBnClickedCbdelall()
{
	lvwDwg.DeleteAllItems();
	lvwDwg.SetFocus();
}


// ����Ʈ�� ������ �̵�
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


// ����Ʈ�� �ǾƷ��� �̵�
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


// ����Ʈ�� ���� �̵�
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


// ����Ʈ�� �Ʒ��� �̵�
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

	_ftprintf(fout, _T("[Magic Plot List]\n"));
	for (i = 0; i < iCnt; i ++)
		_ftprintf(fout, _T("%s,%s,%s\n"), lvwDwg.GetItemText(i, 3), lvwDwg.GetItemText(i, 0), lvwDwg.GetItemText(i, 1));
	
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
	if (cstr.CompareNoCase(_T("[Magic Plot List]")) != 0) {
		AfxMessageBox(_T("���� �÷� ���� ����� �ƴϰų� ���� ���������� �ۼ��� ����Դϴ�\n���� ������ ȣȯ���� �����Ƿ�\n���� �߰� ������� ������ �߰��� �ֽʽÿ�"), MB_OK | MB_ICONINFORMATION);
		fclose(fin);
		return;
	}

	while (_fgetts(sData, 1024, fin)) {
		cstr = sData;
		cstr.Trim();

		// ���ϸ�,���,��Ÿ��
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


// �÷��� ���濡 ���� �������� ����
void CDlgMPL::OnCbnSelchangeCboplotter()
{
	CString sPlotterName;

	cboPaper.Clear();

	GetComboText(&cboPlotter, sPlotterName);
	if (sPlotterName.CompareNoCase(_T("����")) == 0 || sPlotterName.CompareNoCase(_T("none")) == 0) {
		cboPaper.AddString(_T("����"));
		cboPaper.SetCurSel(0);
		return;
	}

	// ������ �÷��͸� ���� �÷��ͷ�
	oLayout.put_ConfigName(sPlotterName);
	oLayout.RefreshPlotDeviceInfo();

	CStringArray sPaper;
	CString sName;
	int iCnt;
	int i;
	VARIANT var;

	// ��� ���� ���� ��
	var = oLayout.GetCanonicalMediaNames();
	Variant2Array(&var, sPaper);

	// ������ ��ȯ�ϸ鼭 �� ����� �̸��� �ٽ� �޴´�
	// �÷��� ������ Userxxxx �� �����°� ����
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
	browInfo.lpszTitle = _T("PLOT ����");
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


// ������ ����
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


// �ڵ� ����(A1����)
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
		optSpecLayout.SetWindowText(_T("Ư�� Layout"));
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
			AfxMessageBox(_T("��� Layout ����� ��� Window �÷� ���� �ɼ��� ����� �� �����ϴ�\n�ٸ� �ɼ��� �������ֽʽÿ�"), MB_OK | MB_ICONSTOP);
			CheckRadioButton(IDC_OPTFORM, IDC_OPTDRAWING, IDC_OPTFORM);
			optForm.SetCheck(TRUE);
			OnBnClickedOptform();
			return;
		}
		ControlEnable3();
	}
	else if (optModelLayout.GetCheck()) {
		optLimit.SetWindowText(_T("Limits �Ǵ� Layout"));
		if (optWindow.GetCheck()) {
			AfxMessageBox(_T("Model + ��� Layout ����� ��� Window �÷� ���� �ɼ��� ����� �� �����ϴ�\n�ٸ� �ɼ��� �������ֽʽÿ�"), MB_OK | MB_ICONSTOP);
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
		MoveDlgItem(IDC_CBSCALEVIEW, viewOX, viewOY + viewDY);
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
	// ��ġ���� Layout�� ��������X, �÷��߽�X
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


// ���� �������� �˻�
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

	// ȯ�漳�� ����
	LoadIni();

	lvwDwg.ShowScrollBar(SB_VERT);

	int sngWidth;
	CRect crec;
	lvwDwg.GetClientRect(crec);
	sngWidth = crec.Width();

	lvwDwg.ModifyStyle (0, LVS_REPORT | LVS_SHOWSELALWAYS);
	lvwDwg.SetExtendedStyle (LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	lvwDwg.InsertColumn (0, _T("����"), LVCFMT_LEFT, sngWidth * 5.8 / 10.0, 0);
	lvwDwg.InsertColumn (1, _T("��Ÿ��"), LVCFMT_LEFT, sngWidth * 3.0 / 10.0, 0);
	lvwDwg.InsertColumn (3, _T("����"), LVCFMT_CENTER, sngWidth * 1.2 / 10.0, 0);
	lvwDwg.InsertColumn (3, _T("���ϰ��"), LVCFMT_LEFT, 0, 0);
	lvwDwg.InsertColumn (4, _T("�÷Ի���"), LVCFMT_LEFT, 0, 0);

	cbScaleView.SubclassDlgItem(IDC_CBSCALEVIEW, this);
	cbScaleView.SetImage(IDB_SEARCH);

	ThumbView.SubclassDlgItem(IDC_THUMBVIEW, this);
	ThumbView.SetBkgColor(0);

	OnBnClickedChkplotcenter();
	OnBnClickedChkplt();
	OnBnClickedChkrescale();

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BOOL CDlgMPL::DestroyWindow()
{
	return CGcUiDialog::DestroyWindow();
}


void CDlgMPL::OnCbnSelchangeCbopaper()
{
}

