
// UtilTest.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CUtilTestApp:
// �� Ŭ������ ������ ���ؼ��� UtilTest.cpp�� �����Ͻʽÿ�.
//

class CUtilTestApp : public CWinApp
{
public:
	CUtilTestApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CUtilTestApp theApp;