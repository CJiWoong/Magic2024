// StandardTable.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MagicCivil.h"
#include "StandardTable.h"
#include "afxdialogex.h"


// CStandardTable ��ȭ �����Դϴ�.

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


// CStandardTable �޽��� ó�����Դϴ�.


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
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
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
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	//CDialogEx::OnCancel();
	DestroyWindow();
}
