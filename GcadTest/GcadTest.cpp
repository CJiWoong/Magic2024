#include "stdafx.h"
#include "GcadTest.h"

#include <oaidl.h>
#include <gced.h>
#include <gdslib.h>
#include <GcExtensionModule.h>
#include "tchar.h"
#include "../MagicUtil/GcadUtil.h"
#include <dbapserv.h>
#include <dbobjptr.h>
#include <rxmfcapi.h>
#include "CGcadApplication.h"
#include "CGcadDocument.h"
#include "CGcadLayout.h"
#include "CGcadLayouts.h"
#include "CGcadPlot.h"
#include "TestDlg.h"


/*
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
*/


/*
void RunGTEST()
{
	gcutPrintf(_T("\nDLF called."));
	GcDbEntity* entPtr;
	entPtr = UserSelEnt(_T("\nSelect Entity"));
	if (entPtr == NULL) {
		::MessageBox(NULL, _T("selected:cancel"), _T("Check"), MB_OK);
		return;
	}
	if (entPtr->isKindOf(GcDbLine::desc()))
		::MessageBox(NULL, _T("selected:Line"), _T("Check"), MB_OK);
	else if (entPtr->isKindOf(GcDbText::desc()))
		::MessageBox(NULL, _T("selected:Text"), _T("Check"), MB_OK);
	else if (entPtr->isKindOf(GcDbPolyline::desc()))
		::MessageBox(NULL, _T("selected:Polyline"), _T("Check"), MB_OK);
	else if (entPtr->isKindOf(GcDbText::desc()))
		::MessageBox(NULL, _T("selected:Text"), _T("Check"), MB_OK);
	else if (entPtr->isKindOf(GcDbMText::desc()))
		::MessageBox(NULL, _T("selected:MText"), _T("Check"), MB_OK);
	else
		::MessageBox(NULL, _T("selected:unknown"), _T("Check"), MB_OK);
	entPtr->close();
}
*/

/*
void RunGTEST()
{
	GcDbEntity* entPtr;
	CString cstr;

	entPtr = UserSelText(_T("\nSelect Text Entity"));
	if (entPtr == NULL) {
		::MessageBox(NULL, _T("selected:cancel"), _T("Check"), MB_OK);
		return;
	}
	if (entPtr->isKindOf(GcDbText::desc())) {
		GcDbText* txtPtr  = GcDbText::cast(entPtr);
		cstr.Format(_T("Text Height = %f"), txtPtr->height());
		::MessageBox(NULL, cstr, _T("Check"), MB_OK);
	}
	else if (entPtr->isKindOf(GcDbMText::desc())) {
		GcDbMText* mtxtPtr  = GcDbMText::cast(entPtr);
		cstr.Format(_T("MText Height = %f"), mtxtPtr->textHeight());
		::MessageBox(NULL, cstr, _T("Check"), MB_OK);
	}
	entPtr->close();
}
*/

/*
void RunGTEST()
{
	gds_point inpPnt;
	TCHAR inpStr[256];
	int rt;
	CString cstr;
	while (rt = UserSelPStr(inpPnt, inpStr, _T("\nEnter Point or String")), rt > 0) {
		if (rt == 1)
			cstr.Format(_T("Point : %f, %f, %f"), inpPnt[X], inpPnt[Y], inpPnt[Z]);
		else if (rt == 2)
			cstr.Format(_T("String : '%s'"), inpStr);
		::MessageBox(NULL, cstr, _T("Check"), MB_OK);
	}
}
*/

/*
void RunGTEST()
{
	gds_point p1, p2;
	CString cstr, sstr;
	LPTSTR tstr;

	p1[X] = 1; p1[Y] = 2; p1[Z] = 3;
	p2[X] = 11; p2[Y] = 12; p2[Z] = 13;

	cstr.Format(_T("before : %f,%f,%f - %f,%f,%f"), p1[X], p1[Y], p1[Z], p2[X], p2[Y], p2[Z]);
	::MessageBox(NULL, cstr, _T("Check"), MB_OK);

	SwapVoidData(p1, p2, sizeof(p1));

	cstr.Format(_T("after  : %f,%f,%f - %f,%f,%f"), p1[X], p1[Y], p1[Z], p2[X], p2[Y], p2[Z]);
	::MessageBox(NULL, cstr, _T("Check"), MB_OK);

	tstr = FillZeroStr(5);
	cstr.Format(_T("repeat by %d = '%s'"), 5, tstr);
	::MessageBox(NULL, cstr, _T("Check"), MB_OK);

	cstr = _T("abc1234.56def");
	tstr = ScanNumStr(cstr); sstr.Format(_T("numstr = '%s' -> '%s'"), cstr, tstr); ::MessageBox(NULL, sstr, _T("Check"), MB_OK);
	cstr = _T("abc-1234.56.def");
	tstr = ScanNumStr(cstr); sstr.Format(_T("numstr = '%s' -> '%s'"), cstr, tstr); ::MessageBox(NULL, sstr, _T("Check"), MB_OK);
	cstr = _T("1234.56.");
	tstr = ScanNumStr(cstr); sstr.Format(_T("numstr = '%s' -> '%s'"), cstr, tstr); ::MessageBox(NULL, sstr, _T("Check"), MB_OK);
	cstr = _T("abc.def");
	tstr = ScanNumStr(cstr); sstr.Format(_T("numstr = '%s' -> '%s'"), cstr, tstr); ::MessageBox(NULL, sstr, _T("Check"), MB_OK);
	cstr = _T("abc-def");
	tstr = ScanNumStr(cstr); sstr.Format(_T("numstr = '%s' -> '%s'"), cstr, tstr); ::MessageBox(NULL, sstr, _T("Check"), MB_OK);
	cstr = _T("abcdef");
	tstr = ScanNumStr(cstr); sstr.Format(_T("numstr = '%s' -> '%s'"), cstr, tstr); ::MessageBox(NULL, sstr, _T("Check"), MB_OK);
}
*/

/*
void RunGTEST()
{
	GcDbPolyline *pLin;
	pLin->numVerts();

	CString cstr;
	IsLayerExist(_T("0"));
	cstr = GetLayerState(_T("Abc"), FALSE);
	::MessageBox(NULL, L"'" + cstr + L"'", _T("Check"), MB_OK);

	CString sstr, mstr;
	TCHAR cstr[256];
	_tcscpy(cstr, _T("123.456000")); sstr = cstr; TrimZeroStr(cstr); mstr.Format(_T("'%s' -> '%s'"), sstr, cstr); ::MessageBox(NULL, mstr, _T("Check"), MB_OK);
	_tcscpy(cstr, _T("123.000")); sstr = cstr; TrimZeroStr(cstr); mstr.Format(_T("'%s' -> '%s'"), sstr, cstr); ::MessageBox(NULL, mstr, _T("Check"), MB_OK);
	_tcscpy(cstr, _T("123456000")); sstr = cstr; TrimZeroStr(cstr); mstr.Format(_T("'%s' -> '%s'"), sstr, cstr); ::MessageBox(NULL, mstr, _T("Check"), MB_OK);
	_tcscpy(cstr, _T("0.000")); sstr = cstr; TrimZeroStr(cstr); mstr.Format(_T("'%s' -> '%s'"), sstr, cstr); ::MessageBox(NULL, mstr, _T("Check"), MB_OK);
	_tcscpy(cstr, _T(".000")); sstr = cstr; TrimZeroStr(cstr); mstr.Format(_T("'%s' -> '%s'"), sstr, cstr); ::MessageBox(NULL, mstr, _T("Check"), MB_OK);
	_tcscpy(cstr, _T("")); sstr = cstr; TrimZeroStr(cstr); mstr.Format(_T("'%s' -> '%s'"), sstr, cstr); ::MessageBox(NULL, mstr, _T("Check"), MB_OK);
}
*/

/*
void RunGTEST()
{
	GcDbObjectId entID;
	GcDbEntity* entPtr;
	GcDbPolyline *polEnt;

	entID = UserSelEnt(_T("\n변환할 도형 선택:"));
	if (entID == NULL)
		return;
	gcdbOpenObject(entPtr, entID, GcDb::kForRead);
	entPtr->close();

	polEnt = ConvertPoly(entPtr, TRUE);
	if (polEnt == NULL)
		return;
	polEnt->close();
}
*/

/*
void RunGTEST()
{
	GcDbObjectId entID;
	GcDbEntity* entPtr;
	CString hdrStr;

	entPtr = UserSelEnt(_T("\n확인할 도형 선택:"), GcDb::kForRead);
	if (entPtr == NULL)
		return;
	entID = entPtr->objectId();
	entPtr->close();

	hdrStr = GetObjectHandleID(entID);
	entID = NULL;
	entPtr = NULL;

	entID = GetObjectByHandle(hdrStr);
	gcdbOpenObject(entPtr, entID, GcDb::kForWrite);
	entPtr->setColorIndex(3);
	entPtr->close();
}
*/

/*
void RunGTEST()
{
	AddNewLayer(_T("PLAN"), 7);
	AddNewLayer(_T("COMM"), 3);
	AddNewLayer(_T("GRID"), 1);
}
*/

/*
void RunGTEST()
{
	GcDbEntity* entPtr;
	GcDbPolyline* srcPol;
	GcDbPolyline* dstPol1;
	GcDbPolyline* dstPol2;
	GcGePoint3dArray pntArr;
	GcGePoint3d pnt1, pnt2;

	entPtr = UserSelEnt(_T("\n기준 폴리선 선택:"), GcDb::kForRead);
	if (entPtr == NULL)
		return;
	srcPol = GcDbPolyline::cast(entPtr);
	if (srcPol == NULL)
		return;

	entPtr = UserSelEnt(_T("\n대상 폴리선1 선택:"), GcDb::kForRead);
	if (entPtr == NULL)
		return;
	dstPol1 = GcDbPolyline::cast(entPtr);
	if (dstPol1 == NULL)
		return; 

	entPtr = UserSelEnt(_T("\n대상 폴리선2 선택:"), GcDb::kForRead);
	if (entPtr == NULL)
		return;
	dstPol2 = GcDbPolyline::cast(entPtr);
	if (dstPol2 == NULL)
		return;

	pntArr.clear();
	if (srcPol->intersectWith(dstPol1, GcDb::kExtendThis, pntArr) != Gcad::eOk)
		return;
	if (pntArr.isEmpty())
		return;
	pnt1 = pntArr[0];
	pntArr.clear();
	if (srcPol->intersectWith(dstPol2, GcDb::kExtendThis, pntArr) != Gcad::eOk)
		return;
	if (pntArr.isEmpty())
		return;
	pnt2 = pntArr[0];
}
*/

/*
void openDwg()
{
	gcedCommand(RTSTR, _T("FILEDIA"), RTSTR, _T("0"), RTNONE);
	gcedCommand(RTSTR, _T("._open"), RTSTR, _T("C:\\test1.dwg"), RTSTR, _T("\n"), RTNONE);
	gcedCommand(RTSTR, _T("FILEDIA"), RTSTR, _T("1"), RTNONE);
}

void fBatchPlotLayouts1()
{
	try {
		IDispatch *pDisp;
		CGcadApplication IApp;
		CGcadDocument IDoc;
		CGcadLayout ILayout;
		CGcadLayouts ILayOuts;
		CGcadLayout ILayOut;
		long mNumberOflayouts;


		//CGcadPlotConfiguration IPltCfg;

		pDisp = gcedGetGcadWinApp()->GetIDispatch(TRUE);
		IApp.AttachDispatch(pDisp);
		//IApp.SetVisible(true);
		pDisp = IApp.get_ActiveDocument();
		IDoc.AttachDispatch(pDisp);
		pDisp = IDoc.get_ActiveLayout(); 
		ILayout.AttachDispatch(pDisp);
		pDisp = IDoc.get_Layouts();
		ILayOuts.AttachDispatch(pDisp);
		mNumberOflayouts = ILayOuts.get_Count();

		//get the AutoCAD application
		//CGcadApplication* pApp = NULL;
		//pApp = (CGcadApplication*)gcedGetGcadWinApp()->GetIDispatch(TRUE);
		//get the Active Document
		//CGcadDocument* pDoc = NULL;
		//pDoc = (CGcadDocument*)pApp->get_ActiveDocument();
		//CGcadLayouts* pLayOuts;
		//CGcadLayout* pLayOut;
		//long mNumberOflayouts;
		//get the layouts collection and the number of layouts
		//pLayOuts = (CGcadLayouts*)pDoc->get_Layouts();
		//mNumberOflayouts = pLayOuts->get_Count();
		//create the variant array that will hold the layout names
		VARIANT mLayArr;
		SAFEARRAYBOUND mSAB;
		mSAB.lLbound = 0;
		mSAB.cElements = mNumberOflayouts;
		VariantInit(&mLayArr);
		mLayArr.vt = VT_ARRAY | VT_BSTR;
		mLayArr.parray = SafeArrayCreate(VT_BSTR,1,&mSAB);
		//populate the variant array
		long mCtr;
		//note that array here has zero based index
		for(mCtr = 0; mCtr < mNumberOflayouts; mCtr ++) {
			//pLayOut = (CGcadLayout*)pLayOuts->Item(_variant_t(mCtr));
			pDisp = ILayOuts.Item(_variant_t(mCtr));
			ILayout.AttachDispatch(pDisp);
			BSTR bstr;
			CString strName;
			strName = ILayout.get_Name();
			bstr = strName.AllocSysString();
			SafeArrayPutElement(mLayArr.parray, &mCtr, bstr);
		}
		//print the layout names that are being plotted
		BSTR bstrName;
		gcutPrintf(_T("\nLayouts to be plotted:"));
		for(mCtr = 0; mCtr < mNumberOflayouts;mCtr ++) {
			SafeArrayGetElement(mLayArr.parray,&mCtr,&bstrName);
			gcutPrintf(_T("\n%s"),(TCHAR*)(_bstr_t)bstrName);
		}
		gcutPrintf(_T("\nPlotting started...\n"));
		//plot the layouts
		CGcadPlot IPlot;
		pDisp = IDoc.get_Plot();
		IPlot.AttachDispatch(pDisp);
		//set the number of plots and error mode to quiet
		IPlot.put_NumberOfCopies(2);
		IPlot.put_QuietErrorMode(VARIANT_TRUE);
		//number of layouts to be plotted
//		IPlot.StartBatchMode(1);
		//set the layouts to plot
		//IPlot.SetLayoutsToPlot(mLayArr);

		//IPlot.DisplayPlotPreview(1);

		//VARIANT_BOOL returnBool;
		//returnBool = IPlot.PlotToDevice(_variant_t("DWF6 ePlot.pc3"));
		VARIANT plotConfig;
		plotConfig.vt = VT_BSTR;
		plotConfig.bstrVal = _T("\\\\modoo-pc\\HP Color LaserJet CP2020 Series PCL6");
		IPlot.PlotToDevice(plotConfig);

		//clean up
		VariantClear(&mLayArr);
	}
	catch (_com_error &e) {
		gcutPrintf(_T("\nError while batch plotting. %s"),e.ErrorMessage());
	}
}

void RunGTEST()
{
//	openDoc();

	//CString cstr;
	//Gcad::ErrorStatus es;
	//cstr = _T("C:\\Temp\\0000\\Draw11\\801-0202.DWG");
	//es = gcDocManager->appContextOpenDocument(cstr);
	//cstr = _T("C:\\Temp\\0000\\Draw11\\801-0308.DWG");
	//es = gcDocManager->appContextOpenDocument(cstr);
	//cstr = _T("C:\\Temp\\0000\\Draw11\\801-0508.DWG");
	//es = gcDocManager->appContextOpenDocument(cstr);
}
*/

void fBatchPlotLayouts2()
{
	try {
		IDispatch *pDisp;
		pDisp = gcedGetGcadWinApp()->GetIDispatch(TRUE);
		CGcadApplication IApp;
		IApp.AttachDispatch(pDisp);
		pDisp = IApp.get_ActiveDocument();
		CGcadDocument IDoc;
		IDoc.AttachDispatch(pDisp);
		pDisp = IDoc.get_ActiveLayout(); 
		CGcadLayout ILayout;
		ILayout.AttachDispatch(pDisp);

		ILayout.put_ConfigName(_T("\\\\modoo-pc\\HP LaserJet P2035n"));
		ILayout.put_CanonicalMediaName(_T("A4"));
		ILayout.put_StyleSheet(_T("monochrome.ctb"));
		ILayout.put_PlotWithPlotStyles(TRUE);
		ILayout.put_PlotWithLineweights(TRUE);
		ILayout.RefreshPlotDeviceInfo();

		ILayout.put_PlotType(acLimits);
		ILayout.put_StandardScale(acScaleToFit);
		ILayout.put_UseStandardScale(TRUE);
		ILayout.put_PlotRotation(ac0degrees);
		ILayout.put_CenterPlot(TRUE);
		ILayout.put_PaperUnits(acInches);
		ILayout.RefreshPlotDeviceInfo();

		IDoc.Regen(acAllViewports);

		CGcadPlot IPlot;
		pDisp = IDoc.get_Plot();
		IPlot.AttachDispatch(pDisp);

		IPlot.DisplayPlotPreview(acFullPreview); // 플롯 미리보기
	}
	catch (_com_error &e) {
		gcutPrintf(_T("\nError while batch plotting. %s"),e.ErrorMessage());
	}
}

void fBatchPlotLayouts()
{
	try {
		IDispatch *pDisp;
		pDisp = gcedGetGcadWinApp()->GetIDispatch(TRUE);
		CGcadApplication IApp;
		IApp.AttachDispatch(pDisp);
		pDisp = IApp.get_ActiveDocument();
		CGcadDocument IDoc;
		IDoc.AttachDispatch(pDisp);
		pDisp = IDoc.get_ActiveLayout(); 
		CGcadLayout ILayout;
		ILayout.AttachDispatch(pDisp);
		CGcadPlot IPlot;
		pDisp = IDoc.get_Plot();
		IPlot.AttachDispatch(pDisp);

		IPlot.DisplayPlotPreview(acFullPreview); // 플롯 미리보기
	}
	catch (_com_error &e) {
		gcutPrintf(_T("\nError while batch plotting. %s"),e.ErrorMessage());
	}
}

void RunGTEST()
{
	gds_point bpnt, epnt;
	gcedGetPoint(NULL, _T("\n인쇄할 영역의 첫번째 모서리 점 지정:"), bpnt);
	gcedGetCorner(bpnt, _T("\n인쇄할 영역의 두번째 모서리 점 지정:"), epnt);

//	fBatchPlotLayouts();
/*
	gds_point vSpnt, vEpnt;
	int rt;

	rt = gcedGetPoint(NULL, _T("인쇄할 영역의 첫번째 모서리 점 지정:"), vSpnt);
	if (rt != RTNORM) {
		return;
	}

	rt = gcedGetCorner(vSpnt, _T("인쇄할 영역의 두번째 모서리 점 지정:"), vEpnt);
	if (rt != RTNORM) {
		return;
	}
*/
}

/*
void RunGTEST()
{
	GcDbEntity* entPtr;

	entPtr = UserSelEnt(_T("\n변경할 도형 선택:"), GcDb::kForWrite);
	if (entPtr == NULL)
		return;

    if (entPtr->isKindOf(GcDb2dPolyline::desc())) {
		::MessageBox(NULL, L"GcDb2dPolyline", _T("Check"), MB_OK);
		GcDb2dPolyline *pol;
		pol = GcDb2dPolyline::cast(entPtr);
		if (pol == NULL)
			return;
		ReverseCoordinates(pol);
	}
    else if (entPtr->isKindOf(GcDb3dPolyline::desc())) {
		::MessageBox(NULL, L"GcDb3dPolyline", _T("Check"), MB_OK);
		GcDb3dPolyline *pol;
		pol = GcDb3dPolyline::cast(entPtr);
		if (pol == NULL)
			return;
		ReverseCoordinates(pol);
	}
    else if (entPtr->isKindOf(GcDbPolyline::desc())) {
		::MessageBox(NULL, L"GcDbPolyline", _T("Check"), MB_OK);
		GcDbPolyline *pol;
		pol = GcDbPolyline::cast(entPtr);
		if (pol == NULL)
			return;
		ReverseCoordinates(pol);
	}
	else
		::MessageBox(NULL, L"Other", _T("Check"), MB_OK);

	entPtr->close();
}
*/

/*
void RunGTEST()
{
	CString cstr;
	cstr.Format(GetFormat(0), 12.34);
	cstr.Format(GetFormat(1), 12.34);
	cstr.Format(GetFormat(2), 12.34);
	cstr.Format(GetFormat(3), 12.34);
	cstr.Format(GetFormat(4), 12.34);
}
*/

/*
void RunGTEST()
{
	int rt;
	double dVal;
	GcDbObjectId entID;
	GcDbEntity* entPtr;
	CString cstr;

	rt = UserSelRealEnt(&dVal, entID, _T("Enter Z Value (Select) "), _T("Select Text Entity "));
	if (rt == 1)
		cstr.Format(_T("Z Value = %f"), dVal);
	else if (rt == 2) {
		gcdbOpenObject(entPtr, entID, GcDb::kForRead);
		if (entPtr->isKindOf(GcDbText::desc()) ||
			entPtr->isKindOf(GcDbMText::desc()))
			cstr.Format(_T("Text Entity selected"));
		else
			cstr.Format(_T("Other Entity selected"));
		entPtr->close();
	}
	else
		cstr.Format(_T("Input canceled"));

	::MessageBox(NULL, cstr, _T("Check"), MB_OK);
}
*/

/*
void RunGTEST()
{
	CString sStr, mStr;
	BOOL rt;

	sStr = _T("1234"); rt = IsNumStr(sStr); mStr.Format(_T("'%s' => %s"), sStr, (rt) ? _T("TRUE"): _T("FALSE")); ::MessageBox(NULL, mStr, _T("Check"), MB_OK);
	sStr = _T("12.34"); rt = IsNumStr(sStr); mStr.Format(_T("'%s' => %s"), sStr, (rt) ? _T("TRUE"): _T("FALSE")); ::MessageBox(NULL, mStr, _T("Check"), MB_OK);
	sStr = _T("12.3.4"); rt = IsNumStr(sStr); mStr.Format(_T("'%s' => %s"), sStr, (rt) ? _T("TRUE"): _T("FALSE")); ::MessageBox(NULL, mStr, _T("Check"), MB_OK);
	sStr = _T("12.34."); rt = IsNumStr(sStr); mStr.Format(_T("'%s' => %s"), sStr, (rt) ? _T("TRUE"): _T("FALSE")); ::MessageBox(NULL, mStr, _T("Check"), MB_OK);
	sStr = _T("+12.34"); rt = IsNumStr(sStr); mStr.Format(_T("'%s' => %s"), sStr, (rt) ? _T("TRUE"): _T("FALSE")); ::MessageBox(NULL, mStr, _T("Check"), MB_OK);
	sStr = _T("12.3+4"); rt = IsNumStr(sStr); mStr.Format(_T("'%s' => %s"), sStr, (rt) ? _T("TRUE"): _T("FALSE")); ::MessageBox(NULL, mStr, _T("Check"), MB_OK);
	sStr = _T("-12.34"); rt = IsNumStr(sStr); mStr.Format(_T("'%s' => %s"), sStr, (rt) ? _T("TRUE"): _T("FALSE")); ::MessageBox(NULL, mStr, _T("Check"), MB_OK);
	sStr = _T("-1-2.34"); rt = IsNumStr(sStr); mStr.Format(_T("'%s' => %s"), sStr, (rt) ? _T("TRUE"): _T("FALSE")); ::MessageBox(NULL, mStr, _T("Check"), MB_OK);
	sStr = _T("a12.34"); rt = IsNumStr(sStr); mStr.Format(_T("'%s' => %s"), sStr, (rt) ? _T("TRUE"): _T("FALSE")); ::MessageBox(NULL, mStr, _T("Check"), MB_OK);
	sStr = _T("12a34"); rt = IsNumStr(sStr); mStr.Format(_T("'%s' => %s"), sStr, (rt) ? _T("TRUE"): _T("FALSE")); ::MessageBox(NULL, mStr, _T("Check"), MB_OK);
	sStr = _T("12.34a"); rt = IsNumStr(sStr); mStr.Format(_T("'%s' => %s"), sStr, (rt) ? _T("TRUE"): _T("FALSE")); ::MessageBox(NULL, mStr, _T("Check"), MB_OK);
}
*/

/*
void RunGTEST()
{
	GcGePoint3dArray pntArr;
	GcDb2dPolyline* pol2d;
	GcDbPolyline* pol;
	GcDb3dPolyline* pol3;
	GcGePoint2d pt;

	pntArr.setLogicalLength(2);
	pntArr[0].set(0.0, 0.0, 0.0);
	pntArr[1].set(200.0, 0.0, 0.0);
	pol2d = new GcDb2dPolyline(GcDb::k2dSimplePoly, pntArr, 0.0);
	Add2CSpace(pol2d);
	pol2d->close();

	pol = new GcDbPolyline(2);
	pt.set(0.0, 100.0); pol->addVertexAt(0, pt);
	pt.set(200.0, 100.0); pol->addVertexAt(1, pt);
	Add2CSpace(pol);
	pol->close();

	pntArr[0].set(0.0, 200.0, 0.0);
	pntArr[1].set(200.0, 200.0, 0.0);
	pol3 = new GcDb3dPolyline(GcDb::k3dSimplePoly, pntArr);
	Add2CSpace(pol3);
	pol3->close();
}
*/

void initApp()
{
	gcedRegCmds->addCommand(_T("ASDK_TEST"), _T("ASDK_GTEST"), _T("GTEST"), GCRX_CMD_MODAL, RunGTEST);
}


void unloadApp()
{
	gcedRegCmds->removeGroup(_T("ASDK_TEST"));
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

