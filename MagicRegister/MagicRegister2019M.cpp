
// MagicRegister.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "MagicRegister.h"
#include "RegEdit.h"
#include <stdio.h>
#include <sys/stat.h>
#include <direct.h>
#include <io.h>
#include "Aclapi.h"
#include "Sddl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMagicRegisterApp

BEGIN_MESSAGE_MAP(CMagicRegisterApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMagicRegisterApp ����

CMagicRegisterApp::CMagicRegisterApp()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CMagicRegisterApp ��ü�Դϴ�.

CMagicRegisterApp theApp;

void AllowEveryone(CString path) 
{
    PACL pDacl,pNewDACL;
    EXPLICIT_ACCESS ExplicitAccess;
    PSECURITY_DESCRIPTOR ppSecurityDescriptor;
    PSID psid;

    LPTSTR lpStr;
    CString str = path;
    lpStr = str.GetBuffer();

    GetNamedSecurityInfo(lpStr, SE_FILE_OBJECT,DACL_SECURITY_INFORMATION, NULL, NULL, &pDacl, NULL, &ppSecurityDescriptor);
    ConvertStringSidToSid("S-1-1-0", &psid);

    ExplicitAccess.grfAccessMode = SET_ACCESS;
    ExplicitAccess.grfAccessPermissions = GENERIC_ALL;
    ExplicitAccess.grfInheritance = CONTAINER_INHERIT_ACE | OBJECT_INHERIT_ACE;
    ExplicitAccess.Trustee.MultipleTrusteeOperation = NO_MULTIPLE_TRUSTEE;
    ExplicitAccess.Trustee.pMultipleTrustee = NULL;
    ExplicitAccess.Trustee.ptstrName = (LPTSTR) psid;
    ExplicitAccess.Trustee.TrusteeForm = TRUSTEE_IS_SID;
    ExplicitAccess.Trustee.TrusteeType = TRUSTEE_IS_UNKNOWN;

    SetEntriesInAcl(1, &ExplicitAccess, pDacl, &pNewDACL);
    SetNamedSecurityInfo(lpStr,SE_FILE_OBJECT,DACL_SECURITY_INFORMATION,NULL,NULL,pNewDACL,NULL);

    LocalFree(pNewDACL);
    LocalFree(psid);

    str.ReleaseBuffer();
}

void SetupMagic()
{
	CRegEdit regEdit;
	CString keyPath;

	// Magic Install Path (written by Install Program)
	keyPath = _T("Software\\Magic");
	regEdit.SetKey(HKEY_CURRENT_USER, keyPath);
	CString appPath = regEdit.GetString(_T("PATH"), _T(""));

	// HKEY_CURRENT_USER\Software\Gstarsoft\GstarCAD_2\R18\ko-KR\Profiles\GstarMech2018Pro\Dialogs\Appload\Startup
	keyPath = _T("Software\\Gstarsoft\\GstarCAD_2\\R18\\ko-KR\\Profiles");
	regEdit.SetKey(HKEY_CURRENT_USER, keyPath);
	CString proNam = regEdit.GetString(_T(""), _T(""));

	// get number of Startups
	keyPath += _T("\\") + proNam + _T("\\Dialogs\\Appload\\Startup");
	regEdit.SetKey(HKEY_CURRENT_USER, keyPath);
	int appNum = regEdit.GetDWord(_T("NumStartup"), 0);

	// get list of Startups
	CStringArray appList;
	CString numStr, appNam, filNam;
	int loc;
	int i;
	for (i = 0; i < appNum; i ++) {
		numStr.Format(_T("%dStartup"), i);
		appNam = regEdit.GetString(numStr, _T(""));
		if (!appNam.IsEmpty()) {
			loc = appNam.ReverseFind('\\');
			if (loc > 0)
				filNam = appNam.Right(appNam.GetLength() - loc - 1);
			else
				filNam = appNam;
			if (filNam.CompareNoCase(_T("MagicUtil.grx")) != 0 &&
				filNam.CompareNoCase(_T("MagicCivil.grx")) != 0)
				appList.Add(appNam);
			regEdit.DeleteValue(numStr);
		}
	}

	// append startup dlls
	appList.Add(_T(appPath + "\\MagicUtil.grx"));
	appList.Add(_T(appPath + "\\gCAD_Calc.dll"));
	appList.Add(_T(appPath + "\\gCAD_Calc.lsp"));

	// write list of Startups
	for (i = 0; i < appList.GetCount(); i ++) {
		numStr.Format(_T("%dStartup"), i);
		regEdit.SetString(numStr, appList[i]);
	}
	regEdit.SetDWord(_T("NumStartup"), i);

	// delete Software\Magic\MagicUtil\MENU Loaded 1
	keyPath = _T("Software\\Magic\\MagicUtil\\MENU");
	regEdit.SetKey(HKEY_CURRENT_USER, keyPath);
	regEdit.DeleteValue(_T("Loaded"));

	// create and set sub directory for data writing
	_mkdir(_T(appPath + "\\Data"));
	_chmod(_T(appPath + "\\Data"), _S_IWRITE);
	AllowEveryone(_T(appPath + "\\Data"));

	::MessageBoxA(NULL, _T("Magic ������ �Ϸ�Ǿ����ϴ�."), _T("MAGIC"), MB_OK | MB_ICONINFORMATION);
}


// CMagicRegisterApp �ʱ�ȭ

BOOL CMagicRegisterApp::InitInstance()
{
	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControlsEx()�� �ʿ��մϴ�.
	// InitCommonControlsEx()�� ������� ������ â�� ���� �� �����ϴ�.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ���� ���α׷����� ����� ��� ���� ��Ʈ�� Ŭ������ �����ϵ���
	// �� �׸��� �����Ͻʽÿ�.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	SetupMagic();

	return TRUE;
}

