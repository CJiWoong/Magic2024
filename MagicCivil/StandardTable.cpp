// StandardTable.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MagicCivil.h"
#include "StandardTable.h"
#include "afxdialogex.h"


// CStandardTable 대화 상자입니다.

IMPLEMENT_DYNAMIC(CStandardTable, CDialogEx)

CStandardTable::CStandardTable(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStandardTable::IDD, pParent)
{

}

CStandardTable::~CStandardTable()
{
}

void CStandardTable::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NORMALTABLE, m_normalTable);
	DDX_Control(pDX, IDC_SMALLTABLE, m_smallTable);
	DDX_Control(pDX, IDC_SHOWSMALL, m_showSmall);
}


BEGIN_MESSAGE_MAP(CStandardTable, CDialogEx)
	ON_BN_CLICKED(IDC_SHOWSMALL, &CStandardTable::OnClickedShowsmall)
END_MESSAGE_MAP()


// CStandardTable 메시지 처리기입니다.


void CStandardTable::SetShowSmall()
{
	if (m_showSmall.GetCheck()) {
		m_normalTable.ShowWindow(SW_HIDE);
		m_smallTable.ShowWindow(SW_NORMAL);
	}
	else {
		m_normalTable.ShowWindow(SW_NORMAL);
		m_smallTable.ShowWindow(SW_HIDE);
	}
}

BOOL CStandardTable::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetShowSmall();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CStandardTable::OnClickedShowsmall()
{
	SetShowSmall();
}


void CStandardTable::PostNcDestroy()
{
	CDialogEx::PostNcDestroy();
	delete this;
}


void CStandardTable::OnOK()
{
	//CDialogEx::OnOK();
	DestroyWindow();
}


void CStandardTable::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	//CDialogEx::OnCancel();
	DestroyWindow();
}
