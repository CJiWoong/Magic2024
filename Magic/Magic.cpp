// Magic.cpp : 해당 DLL의 초기화 루틴을 정의합니다.
//

#include "stdafx.h"
#include "Magic.h"

#include <oaidl.h>
#include <gced.h>
#include <gdslib.h>
#include <GcExtensionModule.h>
#include "tchar.h"
#include "TestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void doIt()
{
	gcutPrintf(_T("\nHello World."));
	CTestDlg tDlg;
	tDlg.DoModal();
}

void initApp()
{
	gcedRegCmds->addCommand(_T("ASDK_SAMPLES_HELLOWORLD"), _T("ASDK_HELLOWORLD"),
		_T("HELLOWORLD"), GCRX_CMD_MODAL, doIt);
}


void unloadApp()
{
	gcedRegCmds->removeGroup(_T("ASDK_SAMPLES_HELLOWORLD"));
}


extern "C" GcRx::AppRetCode gcrxEntryPoint(GcRx::AppMsgCode msg, void* appId)
{
	switch(msg) {
		case GcRx::kInitAppMsg:
			gcrxDynamicLinker->unlockApplication(appId);
			gcrxDynamicLinker->registerAppMDIAware(appId);
			initApp();
			break;
		case GcRx::kUnloadAppMsg:
			unloadApp();
	}
	return GcRx::kRetOK;
}

