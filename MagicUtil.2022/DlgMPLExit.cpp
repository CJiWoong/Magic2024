// DlgMPLExit.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MagicUtil.h"
#include "DlgMPLExit.h"
#include "afxdialogex.h"


// CDlgMPLExit 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgMPLExit, CGcUiDialog)

CDlgMPLExit::CDlgMPLExit(CWnd* pParent /*=NULL*/)
	: CGcUiDialog(CDlgMPLExit::IDD, pParent)
{
	m_bCancel = FALSE;
}

CDlgMPLExit::~CDlgMPLExit()
{
}

void CDlgMPLExit::DoDataExchange(CDataExchange* pDX)
{
	CGcUiDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PBPLOT, m_pbPlot);
	DDX_Control(pDX, IDC_TBCOPY, m_tbCopy);
	DDX_Control(pDX, IDC_TBDRAW, m_tbDraw);
	DDX_Control(pDX, IDC_TBLAYOUT, m_tbLayout);
	DDX_Control(pDX, IDC_TBFORM, m_tbForm);
}


BEGIN_MESSAGE_MAP(CDlgMPLExit, CGcUiDialog)
	ON_BN_CLICKED(IDC_CBCANCEL, &CDlgMPLExit::OnBnClickedCbcancel)
END_MESSAGE_MAP()


// CDlgMPLExit 메시지 처리기입니다.


void CDlgMPLExit::OnBnClickedCbcancel()
{
	m_bCancel = TRUE;
	CGcUiDialog::OnOK();
}


void CDlgMPLExit::SetRange(int num)
{
	m_pbPlot.SetRange(0, num);
	m_pbPlot.SetStep(1);
	m_pbPlot.SetPos(0);
}


void CDlgMPLExit::StepIt()
{
	m_pbPlot.StepIt();
	UpdateWindow();
}


void CDlgMPLExit::SetDraw(LPCTSTR draw)
{
	m_tbDraw.SetWindowTextW(draw);
	m_tbDraw.SetSel(-1);
	UpdateWindow();
}


void CDlgMPLExit::SetLayout(LPCTSTR layout)
{
	m_tbLayout.SetWindowTextW(layout);
	UpdateWindow();
}


void CDlgMPLExit::SetForm(LPCTSTR form)
{
	m_tbForm.SetWindowTextW(form);
	UpdateWindow();
}


void CDlgMPLExit::SetCopy(int copy, int total)
{
	CString cstr;
	cstr.Format(_T("%d/%d"), copy, total);
	m_tbCopy.SetWindowTextW(cstr);
	UpdateWindow();
}


void CDlgMPLExit::Flush()
{
	MSG Msg;
	while (PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE)) {
		if (!PreTranslateMessage(&Msg)) {
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
	}
}


void CDlgMPLExit::OnCancel()
{
	// prevent escape key
}
