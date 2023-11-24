#include "stdafx.h"
#include "MagicCivil.h"

#include <oaidl.h>
#include <gced.h>
#include <gdslib.h>
#include <GcExtensionModule.h>
#include "tchar.h"

#include "DlgDLS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


void RunDLS()
{
	CDlgDLS dlgDLS;
	dlgDLS.DoModal();
}


void initApp()
{
	gcedRegCmds->addCommand(_T("ASDK_CIVIL"), _T("ASDK_DLS"), _T("DLS"), GCRX_CMD_MODAL, RunDLS);
}


void unloadApp()
{
	gcedRegCmds->removeGroup(_T("ASDK_CIVIL"));
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

