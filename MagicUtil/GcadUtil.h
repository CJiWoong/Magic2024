#pragma once

#include <aced.h>
#include <dbxutil.h>
#include <dbents.h>
#include <gdscodes.h>
#include <geassign.h>
#include <acgiutil.h>
#include <acdocman.h>
#include <acaplmgr.h>
#include <grxHeaders.h>
#include <gcedCmdNF.h>

#define PI (atan(1.0) * 4.0)
#define PI2 (atan(1.0) * 2.0)
#define TPI (atan(1.0) * 8.0)

void SwapVoidData(void* srcDat, void* dstDat, int datLen);
LPTSTR FillZeroStr(int repNum);
LPTSTR GetFormat(int iDec);
double DoubleAbs(double dVal);
double DoubleRound(double dVal, int dNum);
double DoubleDouble(double dVal);
BOOL IsNumStr(LPCTSTR srcStr);
LPTSTR ScanNumStr(LPCTSTR srcStr);
void TrimZeroStr(LPTSTR srcStr);
void String2Array(CString srcStr, CStringArray& strArr, LPCTSTR tokStr);
void GetComboText(CComboBox* cBox, CString &cstr);
void SelectComboText(CComboBox* cBox, LPCTSTR sStr);
BOOL IsExistCombo(LPCTSTR sName, CComboBox* cBox);
double GetVecAng(GcGePoint3d cenPnt, GcGePoint3d radPnt);
double GetPntDist(gds_point bgnPnt, gds_point endPnt);
int GetAngQuad(double radAng);
GcGePoint3d GetRotPnt(GcGePoint3d cenPnt, double rotAng, double rotRad);
GcGePoint3d GetRotPnt(GcGePoint3d cenPnt, GcGePoint3d srcPnt, double rotAng);
void RotCenPnt(gds_point cenPnt, gds_point srcPnt, gds_point dstPnt, double rotAng);
void Rotate(GcDbEntity *pEnt, GcGePoint3d cen, double ang);
GcGePoint3d GetMidByTwoPoint(GcGePoint3d sPnt, GcGePoint3d ePnt);
void TransUCSobj(GcDbEntity* oEnt);
GcDbEntity* UserSelEnt(LPCTSTR prompt, GcDb::OpenMode mode);
GcDbEntity* UserSelText(LPCTSTR prompt, GcDb::OpenMode mode);
GcDbEntity* UserSelPLine(LPCTSTR prompt, GcDb::OpenMode mode);
int UserSelPStr(gds_point inpPnt, LPTSTR inpStr, LPCTSTR msgStr);
int UserSelRealEnt(double *dVal, GcDbObjectId &entID, LPCTSTR entMsg, LPCTSTR selMsg);
int GetUcsPoint(gds_point bgnPnt, LPCTSTR prompt, gds_point inpPnt);
LPTSTR GetObjectHandleID(GcDbObjectId objID);
LPTSTR GetObjectHandleID(GcDbEntity* entPtr);
GcDbObjectId GetObjectByHandle(LPCTSTR hdlStr);
void SetVariable(LPCTSTR name, LPCTSTR val);
void SetVariable(LPCTSTR name, double val);
void SetVariable(LPCTSTR name, int val);
void SetVariable(LPCTSTR name, GcGePoint3d& val);
void SetVariable(LPCTSTR name, GcGePoint2d& val);
BOOL GetVariable(LPCTSTR name, CString& val);
BOOL GetVariable(LPCTSTR name, double& val);
BOOL GetVariable(LPCTSTR name, int& val);
BOOL GetVariable(LPCTSTR name, GcGePoint3d& val);
BOOL GetVariable(LPCTSTR name, GcGePoint2d& val);
void Variant2Array(VARIANT* varRes, CStringArray& strArr);
HRESULT Point2d2Array(VARIANT* pVal, const double pt[3]);
double GetTWAng();
GcGePoint3d ToUCS(GcGePoint3d vPnt);
GcGePoint3d ToWCS(GcGePoint3d vPnt);
GcGePoint3d ToDCS(GcGePoint3d vPnt);
GcGePoint3d DCSToWCS(GcGePoint3d vPnt);
GcGePoint3d DCSToUCS(GcGePoint3d vPnt);
BOOL IsWCS();
void SetViewUcs(BOOL bSet);
BOOL CheckLayer(LPCTSTR layNam);
GcDbLayerTableRecord* AddNewLayer(LPCTSTR layNam);
GcDbLayerTableRecord* GetLayerObj(LPCTSTR layNam, GcDb::OpenMode opMode);
void AddNewLayer(LPCTSTR layNam, int layCol);
LPTSTR GetLayerState(LPCTSTR layNam, BOOL resMsg = FALSE);
BOOL IsLayerLock(LPCTSTR layNam);
LPTSTR LockBackUp();
void LockRestore(LPCTSTR layLst);
GcDbObjectId GetTextStyle(LPCTSTR styNam);
void GetTextStyle(GcDbObjectId styID, CString& styNam);
void LayerList(CStringArray& sArray);
void StyleList(CStringArray& sArray);
int GetColorFromDlg(int initColor, BOOL bAllowMetaColor, int nCurLayerColor);
GcCmColor GetColor(LPCTSTR sColor, LPCTSTR sLayer = NULL);
LPCTSTR GetColorName(int iDefault = 1, BOOL bMeta = TRUE);
void ClearXData(GcDbObject* oEnt, LPCTSTR sRegApp);
void CreateSelSet();
void GetSelSetBoundingBox(GcGePoint3d& vMin, GcGePoint3d& vMax, gds_name ssname);
void SortSelZ(gds_name ssname, double dtol, double twang);
void SortSelN(gds_name ssname, double dtol, double twang);
void SortSelIN(gds_name ssname, double dtol, double twang);
void SortSelIZ(gds_name ssname, double dtol, double twang);
void SortSelZ_R(gds_name vssname, double dtol, double twang);
void SortSelN_R(gds_name ssname, double dtol, double twang);
void SortSelIN_R(gds_name ssname, double dtol, double twang);
void SortSelIZ_R(gds_name ssname, double dtol, double twang);
BOOL AddCurrSpace(GcDbEntity* entPtr);
BOOL OpenDwgFile(LPCTSTR filNam);
void DelLockedEnt(GcDbEntity* entPtr);
GcDbPolyline* CnvArc2Poly(GcGePoint3d cenPnt, GcGePoint3d bgnPnt, GcGePoint3d endPnt);
GcDbPolyline* CnvCir2Poly(double cirRad, GcGePoint3d cenPnt);
GcDbPolyline* ConvertPoly(GcDbEntity* entPtr, BOOL delEnt = TRUE);
void ReverseCoordinates(GcDbPolyline* polEnt);
void ReverseCoordinates(GcDb2dPolyline* polEnt);
void ReverseCoordinates(GcDb3dPolyline* polEnt);
void SortStringArray (CStringArray& csa, BOOL bDescending);

