#include "stdafx.h"
#include "MagicUtil.h"
#include "RegEdit.h"

#include <oaidl.h>
#include <gced.h>
#include <gdslib.h>
#include <GcExtensionModule.h>
#include "tchar.h"

#include "DlgMPL.h"
#include "CTP.h"
#include "PW.h"
#include "TCO.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CDlgMPL* m_dlgMPL = NULL;

void RunMPL()
{
	// modaless·Î ½ÇÇà
	if (m_dlgMPL == NULL) {
		m_dlgMPL = new CDlgMPL;
		m_dlgMPL->Create(CDlgMPL::IDD);
	}

	m_dlgMPL->ShowWindow(SW_SHOWNORMAL);

	//dlgMPL.DoModal();
	//dlgMPL->DestroyWindow();
}

void StopMPL()
{
	m_dlgMPL = NULL;
}

void LoadMenu()
{
	CRegEdit m_regEdit;
	m_regEdit.SetKey(HKEY_CURRENT_USER, _T("Software\\Magic\\MagicUtil\\MENU"));
	if (!m_regEdit.GetBoolean(_T("Loaded"), FALSE)) {
		// load menu file
		CString menuFile;
		::GetModuleFileName((HINSTANCE)&__ImageBase, menuFile.GetBuffer(_MAX_PATH), _MAX_PATH);
		menuFile.ReleaseBuffer();
		int loc = menuFile.ReverseFind('\\');
		if (loc >= 0)
			menuFile = menuFile.Left(loc);
		menuFile += _T("\\Magic.cuix");
		gcedCommand(RTSTR, _T("menuload"), RTSTR, menuFile, RTNONE);
		m_regEdit.SetBoolean(_T("Loaded"), TRUE);
	}
}

void initApp()
{
	gcedRegCmds->addCommand(_T("ASDK_UTIL"), _T("ASDK_MPL"), _T("MPL"), GCRX_CMD_MODAL, RunMPL);
	gcedRegCmds->addCommand(_T("ASDK_UTIL"), _T("ASDK_CTP"), _T("CTP"), GCRX_CMD_MODAL, RunCTP);
	gcedRegCmds->addCommand(_T("ASDK_UTIL"), _T("ASDK_PW"), _T("PW"), GCRX_CMD_MODAL, RunPW);
	gcedRegCmds->addCommand(_T("ASDK_UTIL"), _T("ASDK_TCO"), _T("TCO"), GCRX_CMD_MODAL, RunTCO);
	gcedRegCmds->addCommand(_T("ASDK_UTIL"), _T("ASDK_TSW"), _T("TSW"), GCRX_CMD_MODAL, RunTSW);
	gcedRegCmds->addCommand(_T("ASDK_UTIL"), _T("ASDK_TEI"), _T("TEI"), GCRX_CMD_MODAL, RunTEI);
	gcedRegCmds->addCommand(_T("ASDK_UTIL"), _T("ASDK_CR"), _T("CR"), GCRX_CMD_MODAL, RunCR);

	LoadMenu();
}


void unloadApp()
{
	gcedRegCmds->removeGroup(_T("ASDK_UTIL"));
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

