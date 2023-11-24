
// MagicRegister.cpp : 응용 프로그램에 대한 클래스 동작을 정의합니다.
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


// CMagicRegisterApp 생성

CMagicRegisterApp::CMagicRegisterApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CMagicRegisterApp 개체입니다.

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

	::MessageBoxA(NULL, _T("Magic 설정이 완료되었습니다."), _T("MAGIC"), MB_OK | MB_ICONINFORMATION);
}


// CMagicRegisterApp 초기화

BOOL CMagicRegisterApp::InitInstance()
{
	// 응용 프로그램 매니페스트가 ComCtl32.dll 버전 6 이상을 사용하여 비주얼 스타일을
	// 사용하도록 지정하는 경우, Windows XP 상에서 반드시 InitCommonControlsEx()가 필요합니다.
	// InitCommonControlsEx()를 사용하지 않으면 창을 만들 수 없습니다.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 응용 프로그램에서 사용할 모든 공용 컨트롤 클래스를 포함하도록
	// 이 항목을 설정하십시오.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	SetupMagic();

	return TRUE;
}

