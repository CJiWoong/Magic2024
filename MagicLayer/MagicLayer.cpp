#include "stdafx.h"
#include "MagicLayer.h"

#include <oaidl.h>
#include <gced.h>
#include <gdslib.h>
#include <GcExtensionModule.h>
#include "tchar.h"

#include "DlgDLF.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


void RunDLF()
{
	gcutPrintf(_T("\nDLF called."));
	CDlgDLF dlgDLF;
	dlgDLF.DoModal();
}


void initApp()
{
	gcedRegCmds->addCommand(_T("ASDK_LAYER"), _T("ASDK_DLF"), _T("DLF"), GCRX_CMD_MODAL, RunDLF);
}


void unloadApp()
{
	gcedRegCmds->removeGroup(_T("ASDK_LAYER"));
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

