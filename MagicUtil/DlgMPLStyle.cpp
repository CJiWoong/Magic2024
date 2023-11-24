// DlgMPLStyle.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MagicUtil.h"
#include "DlgMPLStyle.h"
#include "afxdialogex.h"

const TCHAR* CDlgMPLStyle::PROGY_NAME = _T("플롯 스타일 변경");

// CDlgMPLStyle 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgMPLStyle, CGcUiDialog)

CDlgMPLStyle::CDlgMPLStyle(CWnd* pParent /*=NULL*/)
	: CGcUiDialog(CDlgMPLStyle::IDD, pParent)
{

}

CDlgMPLStyle::~CDlgMPLStyle()
{
}

void CDlgMPLStyle::DoDataExchange(CDataExchange* pDX)
{
	CGcUiDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CBOK, cbOK);
	DDX_Control(pDX, IDC_COBSTYLE, cobStyle);
	DDX_Control(pDX, IDC_LBLDWG, lblDwg);
	DDX_Control(pDX, IDC_LBLCURRENT, lblCurrent);
}


BEGIN_MESSAGE_MAP(CDlgMPLStyle, CGcUiDialog)
	ON_BN_CLICKED(IDC_CBOK, &CDlgMPLStyle::OnBnClickedCbok)
	ON_CBN_SELCHANGE(IDC_COBSTYLE, &CDlgMPLStyle::OnSelchangeCobstyle)
	ON_BN_CLICKED(IDC_CBCANCEL, &CDlgMPLStyle::OnBnClickedCbcancel)
	ON_BN_CLICKED(IDC_CBHELP, &CDlgMPLStyle::OnBnClickedCbhelp)
END_MESSAGE_MAP()


// CDlgMPLStyle 메시지 처리기입니다.


void CDlgMPLStyle::OnBnClickedCbok()
{
	CGcUiDialog::OnOK();
}


void CDlgMPLStyle::OnSelchangeCobstyle()
{
	GetComboText(&cobStyle, m_selStyle);

	cbOK.SetFocus();
}


void CDlgMPLStyle::OnBnClickedCbcancel()
{
	CGcUiDialog::OnCancel();
}


void CDlgMPLStyle::OnBnClickedCbhelp()
{
	//HtmlHelp ActiveDocument.hwnd, sHelp, HH_DISPLAY_TOPIC, ByVal "html\MPL.htm"
}


BOOL CDlgMPLStyle::OnInitDialog()
{
	GcArray<const TCHAR*> styLst;
	CString cstr;
	int iNum;
	int i;

	CGcUiDialog::OnInitDialog();

	lblDwg.SetWindowTextW(m_textDwg);
	lblCurrent.SetWindowTextW(m_textCurrent);

	// 플롯스타일 올리기
	gcdbHostApplicationServices()->plotSettingsValidator()->plotStyleSheetList(styLst);

	iNum = styLst.length();
	for (i = 0; i < iNum; i ++) {
		cstr = styLst[i];
		cstr = cstr.Right(4);
		if (cstr.CompareNoCase(_T(".ctb")) == 0)
			cobStyle.AddString(styLst[i]);
	}
	cobStyle.SetCurSel(0);

	//Me.cbCancle.Cancel = True

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
