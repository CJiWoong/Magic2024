
// MagicRegister.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMagicRegisterApp:
// �� Ŭ������ ������ ���ؼ��� MagicRegister.cpp�� �����Ͻʽÿ�.
//

class CMagicRegisterApp : public CWinApp
{
public:
	CMagicRegisterApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMagicRegisterApp theApp;