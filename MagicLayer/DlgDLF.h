#pragma once


// CDlgDLF ��ȭ �����Դϴ�.

class CDlgDLF : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgDLF)

public:
	CDlgDLF(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgDLF();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DLF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
