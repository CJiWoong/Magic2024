#include "StdAfx.h"
#include "GcadUtil.h"
#include <dbapserv.h>
#include <dbobjptr.h>


void SwapVoidData(void* srcDat, void* dstDat, int datLen)
{
	char* tmp;

	tmp = (char*) malloc(datLen);
	memcpy(tmp, srcDat, datLen);
	memcpy(srcDat, dstDat, datLen);
	memcpy(dstDat, tmp, datLen);
}


LPTSTR FillZeroStr(int repNum)
{
	static TCHAR repStr[256];
	int i;

	if (repNum > 255)
		repNum = 255;

	for (i = 0; i < repNum; i ++)
		repStr[i] = '0';
	repStr[i] = '\0';

	return repStr;
}


LPTSTR GetFormat(int iDec)
{
	static TCHAR fmtStr[256];

	if (iDec < 0)
		iDec = 0;
	_stprintf(fmtStr, _T("%%.%df"), iDec);

	return fmtStr;
}


double DoubleAbs(double dVal)
{
	return (dVal < 0) ? (- dVal): dVal;
}


double DoubleRound(double dVal, int dNum)
{
	CString fstr;
	CString cstr;

	fstr = GetFormat(dNum);
	cstr.Format(fstr, dVal);
	dVal = _ttof(cstr);

	return dVal;
}


double DoubleDouble(double dVal)
{
	return dVal * dVal;
}


BOOL IsNumStr(LPCTSTR srcStr)
{
	const TCHAR *sPtr;
	int dotNum;

	sPtr = srcStr;
	dotNum = 0;
	while (*sPtr != '\0') {
		if (*sPtr == '+' || *sPtr == '-') {
			if (sPtr != srcStr)
				return FALSE;
		}
		else if (*sPtr == '.')
			dotNum ++;
		else if (!isdigit(*sPtr))
			return FALSE;
		sPtr ++;
	}

	if (dotNum > 1)
		return FALSE;
	else
		return TRUE;
}


LPTSTR ScanNumStr(LPCTSTR srcStr)
{
	static TCHAR retStr[256];
	const TCHAR *sPtr;
	TCHAR *dPtr;
	BOOL hasDot;

	sPtr = srcStr;
	while (*sPtr != '\0') {
		if (isdigit(*sPtr)  || *sPtr == '.' || *sPtr == '-')
			break;
		sPtr ++;
	}

	dPtr = retStr;
	hasDot = FALSE;
	while (*sPtr != '\0') {
		if (*sPtr == '-') {
			if (dPtr != retStr)
				break;
		}
		else if (*sPtr == '.') {
			if (hasDot)
				break;
			hasDot = TRUE;
		}
		else if (!isdigit(*sPtr))
			break;
		*(dPtr ++) = *(sPtr ++);
	}

	*dPtr = '\0';
	return retStr;
}


void TrimZeroStr(LPTSTR srcStr)
{
	TCHAR* srcPtr;

	if (_tcschr(srcStr, '.') == NULL)
		return;

	srcPtr = srcStr;
	while (*srcPtr)
		srcPtr ++;

	while (srcPtr > srcStr) {
		if (*(srcPtr - 1) != '0')
			break;
		srcPtr --;
	}

	if (srcPtr > srcStr && *(srcPtr - 1) == '.')
		srcPtr --;

	*srcPtr = '\0';
}


void String2Array(CString srcStr, CStringArray& strArr, LPCTSTR tokStr)
{
	CString token;
	int pos;
	
	strArr.RemoveAll();
	pos = 0;
	while ((token = srcStr.Tokenize(tokStr, pos)) != _T(""))
		strArr.Add(token);
}


void GetComboText(CComboBox* cBox, CString &cstr)
{
	int cnt;
	int sel;

	cnt = cBox->GetCount();
	sel = cBox->GetCurSel();
	if (cnt > 0) {
		if (sel < 0 || sel >= cnt)
			sel = 0;
		cBox->GetLBText(sel, cstr);
	}
	else
		cstr = _T("");
}


void SelectComboText(CComboBox* cBox, LPCTSTR sStr)
{
	int sel = cBox->SelectString(0, sStr);
	if (sel < 0)
		sel = 0;
	cBox->SetCurSel(sel);
}


BOOL IsExistCombo(LPCTSTR sName, CComboBox* cBox)
{
	CString cstr;
	int i;

	if (sName == _T(""))
		return FALSE;

	for (i = 0; i < cBox->GetCount(); i ++) {
		cBox->GetLBText(i, cstr);
		if (cstr.CompareNoCase(sName) == 0)
			return TRUE;
	}

	return FALSE;
}


double GetVecAng(GcGePoint3d cenPnt, GcGePoint3d radPnt)
{
	double ang;
	double x, y;

	x = radPnt[X] - cenPnt[X];
	y = radPnt[Y] - cenPnt[Y];

	if (x == 0) {
		if (y == 0)
			ang = 0;
		else if (y > 0)
			ang = PI2;
		else
			ang = PI + PI2;
	}
	else {
		ang = atan (y / x);
		if (x < 0)
			ang += PI;
		else if (y < 0)
			ang += TPI;
	}

	return ang;
}


double GetPntDist(gds_point bgnPnt, gds_point endPnt)
{
	double xLen, yLen;

	xLen = endPnt[X] - bgnPnt[X];
	yLen = endPnt[Y] - bgnPnt[Y];

	return sqrt(xLen * xLen + yLen * yLen);
}

int GetAngQuad(double radAng)
{
	int quad;

	while (radAng < 0)
		radAng = radAng + TPI;
	while (radAng > TPI)
		radAng = radAng - TPI;

	if (radAng >= PI2 && radAng < PI)
		quad = 2;
	else if (radAng >= PI && radAng < (PI + PI2))
		quad = 3;
	else if (radAng >= (PI + PI2) && radAng < TPI)
		quad = 4;
	else
		quad = 1;

	return quad;
}


GcGePoint3d GetRotPnt(GcGePoint3d cenPnt, double rotAng, double rotRad)
{
	GcGePoint3d rotPnt;

	rotPnt[X] = cos(rotAng) * rotRad + cenPnt[X];
	rotPnt[Y] = sin(rotAng) * rotRad + cenPnt[Y];
	rotPnt[Z];

	return rotPnt;
}


GcGePoint3d GetRotPnt(GcGePoint3d cenPnt, GcGePoint3d srcPnt, double rotAng)
{
	GcGePoint3d dstPnt;

	srcPnt[X] = srcPnt[X] - cenPnt[X];
	srcPnt[Y] = srcPnt[Y] - cenPnt[Y];
	dstPnt[X] = cos(rotAng) * srcPnt[X] - sin(rotAng) * srcPnt[Y] + cenPnt[X];
	dstPnt[Y] = sin(rotAng) * srcPnt[X] + cos(rotAng) * srcPnt[Y] + cenPnt[Y];
	dstPnt[Z] = 0;

	return dstPnt;
}


void RotCenPnt(gds_point cenPnt, gds_point srcPnt, gds_point dstPnt, double rotAng)
{
	srcPnt[X] = srcPnt[X] - cenPnt[X];
	srcPnt[Y] = srcPnt[Y] - cenPnt[Y];
	dstPnt[X] = cos(rotAng) * srcPnt[X] - sin(rotAng) * srcPnt[Y] + cenPnt[X];
	dstPnt[Y] = sin(rotAng) * srcPnt[X] + cos(rotAng) * srcPnt[Y] + cenPnt[Y];
	dstPnt[Z] = 0;
}


void Rotate(GcDbEntity *pEnt, GcGePoint3d cen, double ang)
{
	GcGeMatrix3d mat;
	GcGeVector3d vec;

	vec.normal();
	mat = mat.rotation(ang, vec, cen);

	pEnt->transformBy(mat);
}

GcGePoint3d GetMidByTwoPoint(GcGePoint3d sPnt, GcGePoint3d ePnt)
{
	GcGePoint3d cPnt;

	cPnt[X] = (sPnt[X] + ePnt[X]) / 2.0;
	cPnt[Y] = (sPnt[Y] + ePnt[Y]) / 2.0;
	cPnt[Z] = (sPnt[Z] + ePnt[Z]) / 2.0;

	return cPnt;
}

//  기능 : WCS객체를 UCS로 옮김
//         ToWCS하지 말것
//         이 코드 만들 필요 없는데 헛지랄했음....
//         암튼..삽입 점에 뭘 그리는 문자 같은것이 아닌
//         좌표를 가지고 그리는 폴리선등은 이 함 수 사용 - DLS,CIM
void TransUCSobj(GcDbEntity* oEnt)
{
/*
	if (IsWCS)
		return;

	// WCS를 만들기 위한 설정
	double dOrign(2);
	double dXVect(2);
	double dYVect(2);
	Dim vOrign As Variant;
	Dim vXVect As Variant;
	Dim vYVect As Variant;

	dOrign(0) = 0: dOrign(1) = 0: dOrign(2) = 0;
	dXVect(0) = 1: dXVect(1) = 0: dXVect(2) = 0;
	dYVect(0) = 0: dYVect(1) = 1: dYVect(2) = 0;

	vOrign = dOrign;
	vXVect = dXVect;
	vYVect = dYVect;

	Dim bSameAxis As Boolean;
	bSameAxis = True;

	// 현재 UCS
	Dim oCurUCS As GcadUCS;
	With ThisDrawing
		// UCS가 아무것도 설정되어있지 않으면
		If .GetVariable("UCSNAME") = "" Then
			Set oCurUCS = .UserCoordinateSystems.Add( _
						 .GetVariable("UCSORG"), _
						 .Utility.TranslateCoordinates(.GetVariable("UCSXDIR"), acUCS, acWorld, 0), _
						 .Utility.TranslateCoordinates(.GetVariable("UCSYDIR"), acUCS, acWorld, 0), _
						 "oUCS")

		// 아니면 현재 활성 좌표체계
		Else
			Set oCurUCS = .ActiveUCS;
		End If
	End With

	Dim vCXVect As Variant;
	Dim vCYVect As Variant;
	vCXVect = oCurUCS.XVector;
	vCYVect = oCurUCS.YVector;

	Dim i As Integer;
	for (i = 0; i < 2; i ++) {
		if (vXVect(i) <> vCXVect(i)) {
			bSameAxis = False;
			Exit For;
		}
	}

	for (i = 0; i < 2; i ++) {
		if (vYVect(i) <> vCYVect(i)) {
			bSameAxis = False;
			Exit For;
		}
	}

	// 축이 같으면 이동
	if (bSameAxis)
		oEnt.Move vOrign, oCurUCS.Origin;
	// 축이 다르면
	else {
			Dim oWCS As GcadUCS;
			Set oWCS = .UserCoordinateSystems.Add(vOrign, vXVect, vYVect, "Dream_WCS");

			vOrign = .Utility.TranslateCoordinates(vOrign, acDisplayDCS, acWorld, 0);
			vXVect = .Utility.TranslateCoordinates(vXVect, acDisplayDCS, acWorld, 0);
			vYVect = .Utility.TranslateCoordinates(vYVect, acDisplayDCS, acWorld, 0);

			Dim oUCS As GcadUCS;
			Set oUCS = .UserCoordinateSystems.Add(vOrign, vXVect, vYVect, "Dream_UCS");
			oUCS.Origin = oCurUCS.Origin;
			oEnt.TransformBy oUCS.GetUCSMatrix;
	}
*/
}


GcDbEntity* UserSelEnt(LPCTSTR prompt, GcDb::OpenMode mode)
{
	gds_name entNam;
	gds_point entPnt;
	GcDbObjectId entID;
	GcDbEntity* entPtr;
	int rt;

	gcedInitGet(RSG_NONULL, _T(""));
	while (1) {
		rt = gcedEntSel(prompt, entNam, entPnt);
		if (rt == RTCAN)
			return NULL;
		else if (rt == RTNORM) {
			gcdbGetObjectId(entID, entNam);
			gcdbOpenObject(entPtr, entID, mode);
			return entPtr;
		}
	}
}


GcDbEntity* UserSelText(LPCTSTR prompt, GcDb::OpenMode mode)
{
	gds_name entNam;
	gds_point entPnt;
	GcDbObjectId entID;
	GcDbEntity* entPtr;
	int rt;

	gcedInitGet(RSG_NONULL, _T(""));
	while (1) {
		rt = gcedEntSel(prompt, entNam, entPnt);
		if (rt == RTCAN)
			return NULL;
		else if (rt == RTNORM) {
			gcdbGetObjectId(entID, entNam);
			gcdbOpenObject(entPtr, entID, mode);
			if (entPtr->isKindOf(GcDbText::desc()) ||
				entPtr->isKindOf(GcDbMText::desc()))
				return entPtr;
			else
				entPtr->close();
		}
	}
}


GcDbEntity* UserSelPLine(LPCTSTR prompt, GcDb::OpenMode mode)
{
	gds_name entNam;
	gds_point entPnt;
	GcDbObjectId entID;
	GcDbEntity* entPtr;
	int rt;

	gcedInitGet(RSG_NONULL, _T(""));
	while (1) {
		rt = gcedEntSel(prompt, entNam, entPnt);
		if (rt == RTCAN)
			return NULL;
		else if (rt == RTNORM) {
			gcdbGetObjectId(entID, entNam);
			gcdbOpenObject(entPtr, entID, mode);
			if (entPtr->isKindOf(GcDbLine::desc()) ||
				entPtr->isKindOf(GcDbPolyline::desc()))
				return entPtr;
			else
				entPtr->close();
		}
	}
}


/*
	return 1: point input
	return 2: string input
	return 0: cancel
*/
int UserSelPStr(gds_point inpPnt, LPTSTR inpStr, LPCTSTR msgStr)
{
	int rt;

	inpPnt[X] = 0;
	inpPnt[Y] = 0;
	inpPnt[Z] = 0;
	inpStr[0] = '\0';

	gcedInitGet(RSG_OTHER, NULL);
	while (1) {
		rt = gcedGetPoint(NULL, msgStr, inpPnt);
		if (rt == RTCAN) /* escape key */
			return 0;
		else if (rt == RTNONE) /* space or enter key */
			return 0;
		else if (rt == RTNORM) /* point input */
			return 1;
		else if (rt == RTKWORD) { /* string input */
			rt = gcedGetInput(inpStr, 256);
			if (rt == RTNORM)
				return 2;
			else
				return 0;
		}
		else
			return 0;
	}
}


/*
	return 1: double input
	return 2: entity select
	return 0: cancel
*/
int UserSelRealEnt(double *dVal, GcDbObjectId &entID, LPCTSTR entMsg, LPCTSTR selMsg)
{
	int rt;
	CString cstr;
	gds_name entNam;
	gds_point entPnt;
	gds_matrix xMat;
	resbuf* rBuf;

	gcedInitGet(RSG_OTHER, _T("Select"));
	rt = gcedGetReal(entMsg, dVal);
	if (rt == RTNORM)
		return 1;
	else if (rt == RTKWORD) {
		rBuf = NULL;
		rt = gcedNEntSelP(selMsg, entNam, entPnt, 0, xMat, &rBuf);
		if (rBuf != NULL)
			gcutRelRb(rBuf);
		if (rt == RTNORM) {
			gcdbGetObjectId(entID, entNam);
			return 2;
		}
		else
			return 0;
	}
	else
		return 0;
}


int GetUcsPoint(gds_point bgnPnt, LPCTSTR prompt, gds_point inpPnt)
{
	gds_point wcsPnt;
	int rt;

	rt = gcedGetPoint(bgnPnt, prompt, wcsPnt);
	if (rt == RTNORM)
		gcdbWcs2Ucs(wcsPnt, inpPnt, ::kTrue);

	return rt;
}

LPTSTR GetObjectHandleID(GcDbObjectId objID)
{
	static TCHAR hdrStr[256];
	GcDbObject* objPtr;
	GcDbHandle objHdl;

	if (gcdbOpenGcDbObject(objPtr, objID, GcDb::kForRead) == Gcad::eOk) {
		objPtr->getGcDbHandle(objHdl);
		objHdl.getIntoAsciiBuffer(hdrStr);
		objPtr->close();
	}
	else
		hdrStr[0] = '\0';

	return hdrStr;
}


LPTSTR GetObjectHandleID(GcDbEntity* entPtr)
{
	static TCHAR hdrStr[256];
	GcDbHandle entHdl;

	entHdl = entPtr->handle();
	entHdl.getIntoAsciiBuffer(hdrStr);

	return hdrStr;
}


GcDbObjectId GetObjectByHandle(LPCTSTR hdlStr)
{
	GcDbHandle objHdl(hdlStr);
	GcDbDatabase* dBase;
	GcDbObjectId objID;

	dBase = gcdbHostApplicationServices()->workingDatabase();
	if (dBase->getGcDbObjectId(objID, false, objHdl) == Gcad::eOk)
		return objID;
	else
		return NULL;
}

void SetVariable(LPCTSTR name, LPCTSTR val)
{
	resbuf rb;

	rb.restype = RTSTR;
	rb.resval.rstring = const_cast<TCHAR*>(val);

	gcedSetVar(name, &rb);
}


void SetVariable(LPCTSTR name, double val)
{
	resbuf rb;

	rb.restype = RTREAL;
	rb.resval.rreal = val;

	gcedSetVar(name, &rb);
}


void SetVariable(LPCTSTR name, int val)
{
	resbuf rb;

	rb.restype = RTSHORT;
	rb.resval.rint = val;

	gcedSetVar(name, &rb);
}


void SetVariable(LPCTSTR name, GcGePoint3d& val)
{
	resbuf rb;
	rb.restype = RT3DPOINT;
	rb.resval.rpoint[X] = val[X];
	rb.resval.rpoint[Y] = val[Y];
	rb.resval.rpoint[Z] = val[Z];

	gcedSetVar(name, &rb);
}


void SetVariable(LPCTSTR name, GcGePoint2d& val)
{
	resbuf rb;
	rb.restype = RTPOINT;
	rb.resval.rpoint[X] = val[X];
	rb.resval.rpoint[Y] = val[Y];

	gcedSetVar(name, &rb);
}


BOOL GetVariable(LPCTSTR name, CString& val)
{
	struct resbuf rBuf;

	if (gcedGetVar(name, &rBuf) == RTNORM) {
		if (rBuf.restype == RTSTR) {
			val = rBuf.resval.rstring;
			free(rBuf.resval.rstring);
			return TRUE;
		}
	}

	return FALSE;
}


BOOL GetVariable(LPCTSTR name, double& val)
{
	struct resbuf rBuf;

	if (gcedGetVar(name, &rBuf) == RTNORM) {
		if (rBuf.restype == RTREAL) {
			val = rBuf.resval.rreal;
			return TRUE;
		}
	}

	return FALSE;
}


BOOL GetVariable(LPCTSTR name, int& val)
{
	struct resbuf rBuf;

	if (gcedGetVar(name, &rBuf) == RTNORM) {
		if (rBuf.restype == RTSHORT) {
			val = rBuf.resval.rint;
			return TRUE;
		}
	}

	return FALSE;
}


BOOL GetVariable(LPCTSTR name, GcGePoint3d& val)
{
	struct resbuf rBuf;

	if (gcedGetVar(name, &rBuf) == RTNORM) {
		if (rBuf.restype == RT3DPOINT) {
			val.set(rBuf.resval.rpoint[X], rBuf.resval.rpoint[Y], rBuf.resval.rpoint[Z]);
			return TRUE;
		}
	}

	return FALSE;
}


BOOL GetVariable(LPCTSTR name, GcGePoint2d& val)
{
	struct resbuf rBuf;

	if (gcedGetVar(name, &rBuf) == RTNORM) {
		if (rBuf.restype == RTPOINT) {
			val.set(rBuf.resval.rpoint[X], rBuf.resval.rpoint[Y]);
			return TRUE;
		}
	}

	return FALSE;
}


void Variant2Array(VARIANT* varRes, CStringArray& strArr)
{
	BSTR bStr;
	UINT nDim;
	HRESULT hr;
	long bLow, bUpp;
	long i;

	strArr.RemoveAll();

	// 문자열 배열
	ASSERT(varRes->vt == (VT_BSTR | VT_ARRAY));

	nDim = SafeArrayGetDim(varRes->parray); // 몇 차원배열인지 확인
	ASSERT(nDim == 1); // 1차원 배열

	hr = SafeArrayGetLBound(varRes->parray, nDim, &bLow); // 배열의 낮은 인덱스
	hr = SafeArrayGetUBound (varRes->parray, nDim, &bUpp); // 배열의 높은 인덱스

	// 배열의 갯수 만큼 반복
	for (i = bLow; i <= bUpp; i ++) {
		// 문자열 읽음
		hr = SafeArrayGetElement(varRes->parray, &i, &bStr);
		strArr.Add(bStr);
		SysFreeString (bStr);
	}
}


HRESULT Point2d2Array(VARIANT* pVal, const double pt[3])
{
	pVal->vt = VT_ARRAY | VT_R8;

	SAFEARRAYBOUND rgsaBound;
	rgsaBound.lLbound = 0L;
	rgsaBound.cElements = 3;

	pVal->parray = SafeArrayCreate(VT_R8, 1, &rgsaBound);
	if (!pVal->parray)
		return E_OUTOFMEMORY;

	HRESULT hr;
	for (long i = 0; i < 3; i++) {
		if ((hr = SafeArrayPutElement(pVal->parray, &i, (void*)&pt[i])) != S_OK)
			return hr;
	}

	return S_OK;
}

// VIEWTWIST된 도면에서 각도를 0으로 만들려면 얼마를 돌려야 하는지 계산
double GetTWAng()
{
	CString cstr;
	double ang;

	if (!GetVariable(_T("VIEWTWIST"), ang))
		ang = 0;

	if (ang != 0)
		ang = TPI - ang;

	return ang;
}


// 기능 : 포인트를 UCS로 변환
GcGePoint3d ToUCS(GcGePoint3d vPnt)
{
	resbuf fromRb, toRb;
	gds_point rPnt;

	fromRb.restype = RTSHORT;
	fromRb.resval.rint = GcDb::kWorldCS;

	toRb.restype = RTSHORT;
	toRb.resval.rint = GcDb::kUserCS;

	short result = gcedTrans(asDblArray(vPnt), &fromRb, &toRb, FALSE, rPnt);
	ASSERT(result == RTNORM);

	return asPnt3d(rPnt);
}


// 기능 : 포인트를 WCS로 변환
GcGePoint3d ToWCS(GcGePoint3d vPnt)
{
	resbuf fromRb, toRb;
	gds_point rPnt;

	fromRb.restype = RTSHORT;
	fromRb.resval.rint = GcDb::kUserCS;

	toRb.restype = RTSHORT;
	toRb.resval.rint = GcDb::kWorldCS;

	short result = gcedTrans(asDblArray(vPnt), &fromRb, &toRb, FALSE, rPnt);
	ASSERT(result == RTNORM);

	return asPnt3d(rPnt);
}


// 기능 : 포인트를 DCS로 변환
GcGePoint3d ToDCS(GcGePoint3d vPnt)
{
	resbuf fromRb, toRb;
	gds_point rPnt;

	fromRb.restype = RTSHORT;
	fromRb.resval.rint = GcDb::kWorldCS;

	toRb.restype = RTSHORT;
	toRb.resval.rint = GcDb::kCurDisplayCS;

	short result = gcedTrans(asDblArray(vPnt), &fromRb, &toRb, FALSE, rPnt);
	ASSERT(result == RTNORM);

	return asPnt3d(rPnt);
}


GcGePoint3d DCSToWCS(GcGePoint3d vPnt)
{
	resbuf fromRb, toRb;
	gds_point rPnt;

	fromRb.restype = RTSHORT;
	fromRb.resval.rint = GcDb::kCurDisplayCS;

	toRb.restype = RTSHORT;
	toRb.resval.rint = GcDb::kWorldCS;

	short result = gcedTrans(asDblArray(vPnt), &fromRb, &toRb, FALSE, rPnt);
	ASSERT(result == RTNORM);

	return asPnt3d(rPnt);
}


GcGePoint3d DCSToUCS(GcGePoint3d vPnt)
{
	resbuf fromRb, toRb;
	gds_point rPnt;

	fromRb.restype = RTSHORT;
	fromRb.resval.rint = GcDb::kCurDisplayCS;

	toRb.restype = RTSHORT;
	toRb.resval.rint = GcDb::kUserCS;

	short result = gcedTrans(asDblArray(vPnt), &fromRb, &toRb, FALSE, rPnt);
	ASSERT(result == RTNORM);

	return asPnt3d(rPnt);
}


BOOL IsWCS()
{
	GcGePoint3d dOrign;
	GcGePoint3d dXVect;
	GcGePoint3d dYVect;
	GcGePoint3d vCOrign;
	GcGePoint3d vCXVect;
	GcGePoint3d vCYVect;

	dOrign[X] = 0; dOrign[Y] = 0; dOrign[Z] = 0;
	dXVect[X] = 1; dXVect[Y] = 0; dXVect[Z] = 0;
	dYVect[X] = 0; dYVect[Y] = 1; dYVect[Z] = 0;

	vCOrign = dOrign;
	vCXVect = dXVect;
	vCYVect = dYVect;

	GcGePoint3d vOrign;
	GcGePoint3d vXVect;
	GcGePoint3d vYVect;
	GcGePoint3d pTemp;

	GetVariable(_T("UCSORG"), vOrign);
	GetVariable(_T("UCSXDIR"), pTemp);
	//vXVect = .Utility.TranslateCoordinates(pTemp, acUCS, acWorld, 0);
	gcdbUcs2Wcs(asDblArray(pTemp), asDblArray(vXVect), ::kTrue);
	GetVariable(_T("UCSYDIR"), pTemp);
	//vYVect = .Utility.TranslateCoordinates(pTemp, acUCS, acWorld, 0);
	gcdbUcs2Wcs(asDblArray(pTemp), asDblArray(vYVect), ::kTrue);

	int i;

	for (i = 0; i < 3; i ++) {
		if (vCOrign[i] != vOrign[i])
			return FALSE;
	}

	for (i = 0; i < 3; i ++) {
		if (vCXVect[i] != vXVect[i])
			return FALSE;
	}

	for (i = 0; i < 3; i ++) {
		if (vCYVect[i] != vYVect[i])
			return FALSE;
	}

	return TRUE;
}


// 기능 : 현재 View로 UCS 작성
void SetViewUcs(BOOL bSet)
{
	GcGePoint3d vXVect, vYVect;
	GcGePoint3d vZero;
	GcGePoint3d vOrigin;
	GcGeVector3d xAxis, yAxis;
	GcGeMatrix3d ucsMat;

	vZero.set(0, 0, 0);
	vXVect.set(1.0, 0.0, 0.0);
	vYVect.set(0.0, 1.0, 0.0);

	gcedGetCurrentUCS(ucsMat);

	ucsMat.setCoordSystem(vZero, GcGeVector3d::kXAxis, GcGeVector3d::kYAxis, GcGeVector3d::kZAxis);
	gcedSetCurrentUCS(ucsMat);

	if (bSet) {
		vXVect = DCSToWCS(vXVect);
		vYVect = DCSToWCS(vYVect);

		xAxis.set(vXVect[X], vXVect[Y], vXVect[Z]);
		yAxis.set(vYVect[X], vYVect[Y], vYVect[Z]);
		ucsMat.setCoordSystem(vZero, xAxis, yAxis, GcGeVector3d::kZAxis);
		gcedSetCurrentUCS(ucsMat);
	}
	else {
		xAxis.set(vXVect[X], vXVect[Y], vXVect[Z]);
		yAxis.set(vYVect[X], vYVect[Y], vYVect[Z]);
		ucsMat.setCoordSystem(vZero, xAxis, yAxis, GcGeVector3d::kZAxis);
		gcedSetCurrentUCS(ucsMat);
	}
}


BOOL CheckLayer(LPCTSTR layNam)
{
	GcDbLayerTable* layTbl = NULL;
	GcDbLayerTableRecord* layPtr = NULL;
	BOOL rt;

	if (gcdbHostApplicationServices()->workingDatabase()->getSymbolTable(layTbl, GcDb::kForRead) != Gcad::eOk)
		return FALSE;

	if (layTbl->getAt(layNam, layPtr, GcDb::kForRead) == Gcad::eOk) {
		layPtr->close();
		rt = TRUE;
	}
	else
		rt = FALSE;

	layTbl->close();

	return rt;
}

GcDbLayerTableRecord* AddNewLayer(LPCTSTR layNam)
{
	GcDbLayerTable* layTbl;
	GcDbLayerTableRecord* layPtr;

	gcdbHostApplicationServices()->workingDatabase()->getSymbolTable(layTbl, GcDb::kForWrite);
	if (!layTbl->has(layNam)) {
		layPtr = new GcDbLayerTableRecord;
		layPtr->setName(layNam);
		layPtr->setIsFrozen(0); // layer to THAWED
		layPtr->setIsOff(0);    // layer to ON
		layPtr->setVPDFLT(0);   // viewport default
		layPtr->setIsLocked(0); // un-locked
/*
		GcCmColor color;
		color.setColorIndex(1); // set color to red
		layPtr->setColor(color);
*/
/*
		GcDbLinetypeTable *pLinetypeTbl;
		GcDbObjectId ltId;
		gcdbHostApplicationServices()->workingDatabase()->getSymbolTable(pLinetypeTbl, GcDb::kForRead);
		if ((pLinetypeTbl->getAt(_T("DASHED"), ltId)) != Gcad::eOk) {
			gcutPrintf(_T("\nUnable to find DASHED linetype. Using CONTINUOUS"));
			pLinetypeTbl->getAt(_T("CONTINUOUS"), ltId);
		}
		pLinetypeTbl->close();
		layPtr->setLinetypeObjectId(ltId);
*/
		layTbl->add(layPtr);
	}
	else
		layPtr = NULL;

	layTbl->close();

	return layPtr;
}


GcDbLayerTableRecord* GetLayerObj(LPCTSTR layNam, GcDb::OpenMode opMode)
{
	GcDbLayerTable* layTbl = NULL;
	GcDbLayerTableRecord* layPtr = NULL;

	if (gcdbHostApplicationServices()->workingDatabase()->getSymbolTable(layTbl, opMode) != Gcad::eOk)
		return NULL;

	if (layTbl->getAt(layNam, layPtr, opMode) != Gcad::eOk)
		layPtr = NULL;

	layTbl->close();

	return layPtr;
}


// layer가 없으면 생성하고 color를 설정
void AddNewLayer(LPCTSTR layNam, int layCol)
{
	GcDbLayerTableRecord* layPtr;
	GcCmColor cmCol;

	if (!CheckLayer(layNam)) {
		layPtr = AddNewLayer(layNam);
		if (layPtr) {
			cmCol.setColorIndex(layCol);
			layPtr->setColor(cmCol);
			layPtr->close();
		}
	}
}


LPTSTR GetLayerState(LPCTSTR layNam, BOOL resMsg)
{
	GcDbLayerTable* layTbl = NULL;
	GcDbLayerTableRecord* layPtr = NULL;
	TCHAR* pLName;
	static TCHAR retMsg[256];
	TCHAR* retPtr;

	retMsg[0] = '\0';
	retPtr = retMsg;

	layPtr = GetLayerObj(layNam, GcDb::kForRead);
	if (layPtr == NULL)
		return retMsg;

	layPtr->getName(pLName);
	if (layPtr->isFrozen()) {
		_stprintf(retPtr, _T("%s 레이어 : 동결\n"), pLName); retPtr += _tcslen(retPtr);
	}
	if (layPtr->isLocked()) {
		_stprintf(retPtr, _T("%s 레이어 : 잠김\n"), pLName); retPtr += _tcslen(retPtr);
	}
	if (layPtr->isOff()) {
		_stprintf(retPtr, _T("%s 레이어 : 꺼짐\n"), pLName); retPtr += _tcslen(retPtr);
	}
	layPtr->close();

	if (retMsg[0] != '\0' && resMsg) {
		_tcscpy(retPtr, _T("기본 레이어로 설정")); retPtr += _tcslen(retPtr);
	}

	if (retPtr > retMsg && *(retPtr - 1) == '\n')
		*(retPtr - 1) = '\0';

	return retMsg;
}


BOOL IsLayerLock(LPCTSTR layNam)
{
	GcDbLayerTable* layTbl = NULL;
	GcDbLayerTableRecord* layPtr = NULL;
	BOOL ret;

	layPtr = GetLayerObj(layNam, GcDb::kForRead);
	if (layPtr == NULL)
		return FALSE;

	ret = layPtr->isLocked() ? TRUE: FALSE;

	layPtr->close();

	return ret;
}


// lock 된 layer의 목록을 문자열로 만들고, 해당 layer의 lock을 해제함
LPTSTR LockBackUp()
{
	GcDbLayerTable* layTbl = NULL;
	GcDbLayerTableRecord* layPtr = NULL;
	GcDbLayerTableIterator* layItr;
	TCHAR* layNam;
	static TCHAR layLst[1024];
	TCHAR* strPtr;

	layLst[0] = '\0';

	if (gcdbHostApplicationServices()->workingDatabase()->getSymbolTable(layTbl, GcDb::kForRead) != Gcad::eOk)
		return layLst;

	strPtr = layLst;
	layTbl->newIterator(layItr);
	for (; !layItr->done(); layItr->step()) {
		layItr->getRecord(layPtr, GcDb::kForWrite);
		if (layPtr->isLocked()) {
			layPtr->getName(layNam);
			_tcscpy(strPtr, layNam); strPtr += _tcslen(strPtr);
			_tcscpy(strPtr, _T(",")); strPtr += _tcslen(strPtr);
			layPtr->setIsLocked(FALSE);
		}
		layPtr->close();
	}
	delete layItr;
	*strPtr = '\0';
	layTbl->close();

	return layLst;
}


// 문자열로 저장된 목록의 layer를 lock 시킴
void LockRestore(LPCTSTR layLst)
{
	GcDbLayerTable* layTbl = NULL;
	GcDbLayerTableRecord* layPtr = NULL;
	CString cstr;
	CString layNam;
	int pos;

	if (gcdbHostApplicationServices()->workingDatabase()->getSymbolTable(layTbl, GcDb::kForRead) != Gcad::eOk)
		return;

	cstr = layLst;
	pos = 0;
	while (layNam = cstr.Tokenize(_T(","), pos), !layNam.IsEmpty()) {
		if (layTbl->getAt(layNam, layPtr, GcDb::kForWrite) == Gcad::eOk) {
			layPtr->setIsLocked(TRUE);
			layPtr->close();
		}
	}

	layTbl->close();
}


GcDbObjectId GetTextStyle(LPCTSTR styNam)
{
	GcDbTextStyleTable * styTbl;
	GcDbObjectId styID;

	if (gcdbHostApplicationServices()->workingDatabase()->getTextStyleTable(styTbl, GcDb::kForRead) != Gcad::eOk)
		return NULL;

	if (styTbl->getAt(styNam, styID) != Gcad::eOk)
		styTbl->getAt(_T("STANDARD"), styID);
	styTbl->close();

	return styID;
}


void GetTextStyle(GcDbObjectId styID, CString& styNam)
{
	GcDbTextStyleTableRecord* styPtr;
	TCHAR* name;

	if (gcdbOpenObject(styPtr, styID, GcDb::kForRead) == Gcad::eOk) {
		styPtr->getName(name);
		styPtr->close();
		styNam = name;
		free(name);
	}
}


void LayerList(CStringArray& sArray)
{
	GcDbLayerTable* layTbl;
	GcDbLayerTableIterator* layItr;
	GcDbLayerTableRecord* layPtr;
	TCHAR* layNam;

	sArray.RemoveAll();

	if (gcdbHostApplicationServices()->workingDatabase()->getSymbolTable(layTbl, GcDb::kForRead) != Gcad::eOk)
		return;

	layTbl->newIterator(layItr);
	for (; !layItr->done(); layItr->step()) {
		layItr->getRecord(layPtr, GcDb::kForWrite);
		layPtr->getName(layNam);
		layPtr->close();
		sArray.Add(layNam);
		free(layNam);
	}
	delete layItr;
	layTbl->close();
}

void StyleList(CStringArray& sArray)
{
	GcDbTextStyleTable *styTbl;
	GcDbTextStyleTableIterator *styItr;
	GcDbTextStyleTableRecord *styPtr;
	GCHAR *styNam;

	sArray.RemoveAll();

	if (gcdbHostApplicationServices()->workingDatabase()->getTextStyleTable(styTbl, GcDb::kForRead) != Gcad::eOk)
		return;

	styTbl->newIterator(styItr);
	for (; !styItr->done(); styItr->step()) {
		styItr->getRecord(styPtr, GcDb::kForRead);
		styPtr->getName(styNam);
		styPtr->close();
		sArray.Add(styNam);
		free(styNam);
	}
	delete styItr;
	styTbl->close();
}


int GetColorFromDlg(int initColor, BOOL bAllowMetaColor, int nCurLayerColor)
{
	int iColor;

/*
	Select Case GetAcadVer
	Case 19 '2013~
		If Not bAllowMetaColor Then
			If initColor = 0 Or initColor = 256 Then
				initColor = 1
			End If
		End If
		iColor = EvalLispExpression("(GCAD_COLORdlg " & initColor & IIf(bAllowMetaColor, " t)", " nil )"))
	Case Else
*/
		iColor = initColor;
		if (!gcedSetColorDialog(iColor, bAllowMetaColor, nCurLayerColor))
			iColor = initColor;
/*
	End Select
*/
		return iColor;
/*
	If IsEmpty(iColor) Then
		GetColorFromDlg = initColor
	Else
		GetColorFromDlg = CLng(iColor)
	End If
	Err.Clear
*/
}


GcCmColor GetColor(LPCTSTR sColor, LPCTSTR sLayer)
{
	GcCmColor cmCol;
	CString layNam;
	GcDbLayerTableRecord* layPtr;

	BOOL bLayLock = FALSE;

	if (_tcsicmp(sColor, _T("By Layer")) == 0) {
		if (sLayer == NULL)
			cmCol.setColorIndex(256);
		else {
			GetVariable(_T("CLAYER"), layNam);
			layPtr = GetLayerObj(layNam, GcDb::kForRead);
			cmCol = layPtr->color();

			if (layPtr->isLocked()) {
				bLayLock = TRUE;
				layPtr->lock(FALSE);
			}
		}
	}
	else if (_tcsicmp(sColor, _T("By Block")) == 0)
		cmCol.setColorIndex(0);
	else
		cmCol.setColorIndex(_ttoi(sColor));

	if (bLayLock)
		layPtr->lock(TRUE);

	return cmCol;
}


LPCTSTR GetColorName(int iDefault, BOOL bMeta)
{
	int iColor;
	iColor = GetColorFromDlg(iDefault, bMeta, 256);
	static TCHAR colNam[256];

	switch(iColor) {
	case 256:
		_tcscpy(colNam, _T("By Layer"));
		break;
	case 0:
		_tcscpy(colNam, _T("By Block"));
		break;
	default:
		_stprintf(colNam, _T("%d"), iColor);
	}

	return colNam;
}


void ClearXData(GcDbObject* oEnt, LPCTSTR sRegApp)
{
	resbuf* xdata = NULL;
	while ((xdata = oEnt->xData(sRegApp)) != NULL) {
		resbuf* xdata_next = xdata->rbnext;
		xdata->rbnext = NULL;
		oEnt->setXData(xdata);
		xdata->rbnext = xdata_next;
		gcutRelRb(xdata);
	}
/*
	oEnt.GetXData sRegApp, vType, vData
	If Not IsEmpty(vType) Then
		For i = LBound(vType) To UBound(vType)
			If vType(i) = 1001 Then
				// 오토캐드 자체 XDATA는 삭제하면안됨
				If Not vData(i) Like "ACAD" Then
					iNewType(0) = 1001
					vNewData(0) = vData(i)
					oEnt.SetXData iNewType, vNewData
				End If
			End If
		Next i
	End If
*/
}

void CreateSelSet()
{
	gds_name ss;
	// get the selectionset
	int res = gcedSSGet (NULL, NULL, NULL, NULL, ss);
	// if ok
	if (res == RTNORM) {
		// get the length of the selection set
		long length = 0l;
		gcedSSLength (ss, &length);
		// see what we have
		gcutPrintf(L"\nBefore ss length = %ld", length);
		// now loop round and find out which ones are in Paper space
		for (long i=0l; i<length; ++i) {
			gds_name ename;
			// extract the ename
			if (gcedSSName (ss, i, ename) != RTNORM)
				continue;
			GcDbObjectId objId;
			// convert the ename to an object id
			gcdbGetObjectId (objId, ename);
			// open the entity for read
			GcDbObjectPointer<GcDbEntity>ent (objId, GcDb::kForRead);
			// if ok
			if (ent.openStatus () == Gcad::eOk) {
				// get the owner object for this entity
				GcDbObjectId ownerId = ent->ownerId();
				// get the current dwg database
				GcDbDatabase *dwg =
					gcdbHostApplicationServices()->workingDatabase();
				// if the entity owner id is not the
				// same as the current space id
				if (dwg->currentSpaceId() != ownerId &&
					dwg->viewportTableId() != ownerId &&
					dwg->paperSpaceVportId() != ownerId) {
					// remove the entity from the selection set
					gcedSSDel (ename, ss);
				}
			}
		}
		gcedSSLength (ss, &length);
		// see what we have
		gcutPrintf(L"\nAfter ss length = %ld", length);
		// test code
		gcedCommand (RTSTR, "._SELECT", RTPICKS, ss, RTSTR, "", RTNONE);
		// free the selection set after use
		gcedSSFree (ss);
	}
}

void CheckGeomExtents(BOOL& bFirst, GcDbExtents geoExt, double& dMinX, double& dMinY, double& dMaxX, double& dMaxY)
{
	GcGePoint3d vMinPnt, vMaxPnt;

	vMinPnt = geoExt.minPoint();
	vMinPnt = ToUCS(vMinPnt);
	vMaxPnt = geoExt.maxPoint();
	vMaxPnt = ToUCS(vMaxPnt);
	
	if (bFirst) {
		dMinX = vMinPnt[X];
		dMinY = vMinPnt[Y];
		dMaxX = vMaxPnt[X];
		dMaxY = vMaxPnt[Y];
		bFirst = FALSE;
	}
	else {
		if (dMinX > vMinPnt[X])
			dMinX = vMinPnt[X];
		if (dMinY > vMinPnt[Y])
			dMinY = vMinPnt[Y];
		if (dMaxX < vMaxPnt[X])
			dMaxX = vMaxPnt[X];
		if (dMaxY < vMaxPnt[Y])
			dMaxY = vMaxPnt[Y];
	}
}

void GetSelSetBoundingBox(GcGePoint3d& vMin, GcGePoint3d& vMax, gds_name ssname)
{
	double dMaxX;
	double dMaxY;
	double dMinX;
	double dMinY;
	GcGePoint3d vPnt;
	gds_name ename;
	GcDbObjectId objId;
	GcDbEntity* pEnt;
	GcDbExtents geoExt;
	long len;
	long i, j;
	BOOL bFirst;

	if ((gcedSSLength(ssname, &len) != RTNORM) || (len < 1))
		return;

	bFirst = TRUE;
	for (i = 0; i < len; i++) {
		if (gcedSSName(ssname, i, ename) != RTNORM)
			continue;
		if (gcdbGetObjectId(objId, ename) != Gcad::eOk)
			continue;
		if (gcdbOpenGcDbEntity(pEnt, objId, GcDb::kForWrite) != Gcad::eOk)
			continue;

		if (pEnt->isKindOf(GcDbMText::desc())) {
			GcDbVoidPtrArray eSet;
			Gcad::ErrorStatus es=pEnt->explode(eSet);
			for (j = 0; j < eSet.length(); j ++) {
				GcDbEntity* pNewEnt = GcDbEntity::cast((GcRxObject*)eSet[j]);
				pNewEnt->getGeomExtents(geoExt);
				CheckGeomExtents(bFirst, geoExt, dMinX, dMinY, dMaxX, dMaxY);
				pNewEnt->close();
				delete (GcRxObject*)eSet[j];
			}
		}
		else {
			pEnt->getGeomExtents(geoExt);
			CheckGeomExtents(bFirst, geoExt, dMinX, dMinY, dMaxX, dMaxY);
		}

		pEnt->close();
	}

	vPnt[X] = dMinX; vPnt[Y] = dMinY; vPnt[Z] = 0.0;
	vMin = ToWCS(vPnt);
	vPnt[X] = dMaxX; vPnt[Y] = dMaxY; vPnt[Z] = 0.0;
	vMax = ToWCS(vPnt);
}

void SortSelZ(gds_name ssname, double dtol, double twang)
{
}
void SortSelN(gds_name ssname, double dtol, double twang)
{
}
void SortSelIN(gds_name ssname, double dtol, double twang)
{
}
void SortSelIZ(gds_name ssname, double dtol, double twang)
{
}
void SortSelZ_R(gds_name vssname, double dtol, double twang)
{
}
void SortSelN_R(gds_name ssname, double dtol, double twang)
{
}
void SortSelIN_R(gds_name ssname, double dtol, double twang)
{
}
void SortSelIZ_R(gds_name ssname, double dtol, double twang)
{
}

BOOL AddCurrSpace(GcDbEntity* entPtr)
{
/*
	TCHAR blkNam[256];
	struct resbuf rb;
	GcDbBlockTable *blkTbl;
	GcDbBlockTableRecord *blkPtr;
	GcDbObjectId objID;

	if (gcdbHostApplicationServices()->workingDatabase()->tilemode() == ::kFalse) {
		gcedGetVar(_T("cvport"), &rb);
		if (rb.resval.rint == 1)
			_tcscpy(blkNam, ACDB_PAPER_SPACE);
		else
			_tcscpy(blkNam, ACDB_MODEL_SPACE);
	}
	else
		_tcscpy(blkNam, ACDB_MODEL_SPACE);

	gcdbHostApplicationServices()->workingDatabase()->getSymbolTable(blkTbl, GcDb::kForRead);

	blkTbl->getAt(ACDB_MODEL_SPACE, blkPtr, GcDb::kForWrite);
	blkTbl->close();

	blkPtr->appendGcDbEntity(objID, entPtr);
	blkPtr->close();

	return objID;
*/
	GcDbBlockTableRecord* blkRec;
	Gcad::ErrorStatus rt;

	gcdbOpenObject(blkRec, gcdbHostApplicationServices()->workingDatabase()->currentSpaceId(), GcDb::kForWrite);
	if (blkRec == NULL)
		return FALSE;

	rt = blkRec->appendGcDbEntity(entPtr);
	blkRec->close();

	return (rt == Gcad::eOk) ? TRUE: FALSE;
}


void openSyncDocHelper(void* pData)
{
	if (gcDocManager->isApplicationContext())
		gcDocManager->appContextOpenDocument((const TCHAR*)pData);
}


BOOL OpenDwgFile(LPCTSTR filNam)
{
	static TCHAR pData[256];

	_tcscpy(pData, filNam);
	//gcDocManager->executeInApplicationContext(openSyncDocHelper, (void*)pData);
	gcDocManager->appContextOpenDocument((const TCHAR*)pData);

	return TRUE;
}


//BOOL OpenDwgFile(LPCTSTR filNam)
//{
//	//gcedCommand(RTSTR, _T("filedia"), RTSTR, _T("0"), RTNONE);
//
///*
//	gcedCommand(RTSTR, _T("._open"), RTSTR, filNam, RTNONE);
//*/
//
//	CString exeStr;
//	Gcad::ErrorStatus es;
//
//	exeStr.Format(_T("(command \"open\" \"%s\") "), filNam);
//	exeStr.Replace(_T("\\"), _T("\\\\"));
//	es = gcDocManager->sendStringToExecute(gcDocManager->curDocument(), exeStr, false, false, false);
//
//	//gcedCommand(RTSTR, _T("filedia"), RTSTR, _T("1"), RTNONE);
//
//	return TRUE;
//}


void DelLockedEnt(GcDbEntity* entPtr)
{
	GcDbEntity* delEnt;
	GcDbLayerTableRecord* layPtr;
	CString layNam;
	BOOL isLock;

	layNam = entPtr->layer();
	layPtr = GetLayerObj(layNam, GcDb::kForWrite);
	if (layPtr == NULL)
		return;

	if (layPtr->isLocked()) {
		isLock = TRUE;
		layPtr->lock(FALSE);
	}
	else
		isLock = FALSE;

	entPtr->close();
	gcdbOpenGcDbEntity(delEnt, entPtr->objectId(), GcDb::kForWrite);
	delEnt->erase();
	delEnt->close();

	if (isLock)
		layPtr->lock(TRUE);

	layPtr->close();
}


GcDbPolyline* CnvArc2Poly(GcGePoint3d cenPnt, GcGePoint3d bgnPnt, GcGePoint3d endPnt)
{
	GcDbPolyline* polEnt;
	//GcDb2dVertex *pVertex;
	GcGePoint2d vPnt;
	double bgnAng;
	double endAng;
	double incAng;
	double dBul;

	// 센터-시점 각도
	bgnAng = GetVecAng(cenPnt, bgnPnt);
	// 센터-종점 각도
	endAng = GetVecAng(cenPnt, endPnt);

	// 내각
	if (bgnAng > endAng)
		incAng = fabs(endAng + TPI - bgnAng);
	else
		incAng = fabs(endAng - bgnAng);
	// Bulge 값을 계산
	dBul = tan(incAng / 4);

	polEnt = new GcDbPolyline(2);

	//pVertex = new GcDb2dVertex;
	//pVertex->setPosition(bgnPnt);
	//pVertex->setBulge(dBul);
	//pVertex->close();
	vPnt.x = bgnPnt[X];
	vPnt.y = bgnPnt[Y];
	polEnt->addVertexAt(0, vPnt, dBul);

	//pVertex = new GcDb2dVertex;
	//pVertex->setPosition(endPnt);
	//pVertex->close();
	vPnt.x = endPnt[X];
	vPnt.y = endPnt[Y];
	polEnt->addVertexAt(1, vPnt, 0.0);

	polEnt->setElevation(bgnPnt[Z]);

	return polEnt;
}


GcDbPolyline* CnvCir2Poly(double cirRad, GcGePoint3d cenPnt)
{
	GcDbPolyline* polEnt;
	//GcGePoint3d bgnPnt, endPnt;
	//GcDb2dVertex *pVertex;
	GcGePoint2d vPnt;
	double dBul;

	//bgnPnt[X] = cenPnt[X] - cirRad;
	//bgnPnt[Y] = cenPnt[Y];
	//bgnPnt[Z] = cenPnt[Z];
	//endPnt[X] = cenPnt[X] + cirRad;
	//endPnt[Y] = cenPnt[Y];
	//endPnt[Z] = cenPnt[Z];

	// Bulge 값을 계산
	dBul = tan(PI2 / 2);

	polEnt = new GcDbPolyline(2);

	//pVertex = new GcDb2dVertex;
	//pVertex->setPosition(bgnPnt);
	//pVertex->setBulge(dBul);
	//pVertex->close();
	vPnt.x = cenPnt[X] - cirRad;
	vPnt.y = cenPnt[Y];
	polEnt->addVertexAt(0, vPnt, dBul, 0.0);

	//pVertex = new GcDb2dVertex;
	//pVertex->setPosition(endPnt);
	//pVertex->setBulge(dBul);
	//pVertex->close();
	vPnt.x = cenPnt[X] + cirRad;
	vPnt.y = cenPnt[Y];
	polEnt->addVertexAt(1, vPnt, dBul, 0.0);

	polEnt->setClosed(TRUE);
	polEnt->setElevation(cenPnt[Z]);

	return polEnt;
}

// 원, 호, 라인을 폴리선으로 변경
GcDbPolyline* ConvertPoly(GcDbEntity* entPtr, BOOL delEnt /* = TRUE */)
{
	GcDbPolyline* polEnt;
	GcDbLine *linEnt;
	GcDbArc *arcEnt;
	GcDbCircle *cirEnt;
	GcGePoint3dArray pntArr;
	CString layNam;
	CString ltyNam;
	double ltyScl;
	GcDb::LineWeight linWgt;
	GcGePoint3d cenPnt, bgnPnt, endPnt;
	GcGeVector3d norPnt;
	GcGePoint2d vPnt;
	double cirRad;
	int iCol;
	GcCmColor acCol;

	layNam = entPtr->layer();
	ltyNam = entPtr->linetype();
	ltyScl = entPtr->linetypeScale();
	linWgt = entPtr->lineWeight();
	iCol = entPtr->colorIndex();
	acCol = entPtr->color();

	if (entPtr->isKindOf(GcDbLine::desc())) {
		linEnt = GcDbLine::cast(entPtr);
		bgnPnt = linEnt->startPoint();
		endPnt = linEnt->endPoint();
		//pntArr.setLogicalLength(2);
		//pntArr[1].set(endPnt[X], endPnt[Y], 0.0);

		polEnt = new GcDbPolyline(2);

		vPnt.x = bgnPnt[X];
		vPnt.y = bgnPnt[Y];
		polEnt->addVertexAt(0, vPnt);

		vPnt.x = endPnt[X];
		vPnt.y = endPnt[Y];
		polEnt->addVertexAt(1, vPnt);
		polEnt->setElevation(0.0);
	}
	else if (entPtr->isKindOf(GcDbArc::desc())) {
		arcEnt = GcDbArc::cast(entPtr);

		cenPnt = arcEnt->center();
		arcEnt->getStartPoint(bgnPnt);
		arcEnt->getEndPoint(endPnt);
		norPnt = arcEnt->normal();
		if (norPnt.z >= 0)
			polEnt = CnvArc2Poly(cenPnt, bgnPnt, endPnt);
		else
			polEnt = CnvArc2Poly(cenPnt, endPnt, bgnPnt);
	}
	else if (entPtr->isKindOf(GcDbCircle::desc())) {
		cirEnt = GcDbCircle::cast(entPtr);

		cenPnt = cirEnt->center();
		cirRad = cirEnt->radius();
		polEnt = CnvCir2Poly(cirRad, cenPnt);
	}
	else
		return NULL;

	AddCurrSpace(polEnt);
	polEnt->setLayer(layNam);
	polEnt->setLinetype(ltyNam);
	polEnt->setLinetypeScale(ltyScl);
	polEnt->setLineWeight(linWgt);
	polEnt->setColorIndex(iCol);
	polEnt->setColor(acCol);
	//polEnt->close();
	polEnt->draw();

	if (delEnt)
		DelLockedEnt(entPtr);

	return polEnt;
}


void ReverseCoordinates(GcDbPolyline* polEnt)
{
	int pntNum;
	GcGePoint2d polPnt;
	double polBW, polEW, polBul;
	GcGePoint2dArray pntArr;
	GcGeDoubleArray bulArr;
	GcGeDoubleArray bwArr, ewArr;
	int i, j;

	pntNum = polEnt->numVerts();
	for (i = 0; i < pntNum; i ++) {
		polEnt->getPointAt(i, polPnt);
		polEnt->getBulgeAt(i, polBul);
		polEnt->getWidthsAt(i, polBW, polEW);

		pntArr.append(polPnt);
		bulArr.append(polBul);
		bwArr.append(polBW);
		ewArr.append(polEW);
	}

	if (polEnt->isClosed()) {
		polEnt->setPointAt(0, pntArr[0]);
		polEnt->setBulgeAt(0, - bulArr[pntNum - 1]);
		polEnt->setWidthsAt(0, ewArr[pntNum - 1], bwArr[pntNum - 1]);
		for (i = pntNum - 1, j = 1; i > 0; i --, j ++) {
			polEnt->setPointAt(j, pntArr[i]);
			polEnt->setBulgeAt(j, - bulArr[i - 1]);
			polEnt->setWidthsAt(j, ewArr[i - 1], bwArr[i - 1]);
		}
	}
	else {
		for (i = pntNum - 1, j = 0; i > 0; i --, j ++) {
			polEnt->setPointAt(j, pntArr[i]);
			polEnt->setBulgeAt(j, - bulArr[i - 1]);
			polEnt->setWidthsAt(j, ewArr[i - 1], bwArr[i - 1]);
		}
		polEnt->setPointAt(pntNum - 1, pntArr[0]);
	}
}


void ReverseCoordinates(GcDb2dPolyline* polEnt)
{
	GcGePoint3dArray pntArr;
	GcGeDoubleArray bulArr;
	GcDbObjectIterator* verItr;
	GcDb2dVertex* vertex;
	int loc;

	verItr = polEnt->vertexIterator();
	if (verItr == NULL)
		return;

	loc = 0;
	for (; !verItr->done(); verItr->step()) {
		if (gcdbOpenObject(vertex, verItr->objectId(), GcDb::kForRead) == Gcad::eOk) {
			if (vertex->vertexType() != GcDb::k2dSplineCtlVertex) {
				pntArr.append(vertex->position());                    // returns ECS
				bulArr.append(vertex->bulge());
				loc ++;
			}
			vertex->close();
		}
	}
	delete verItr;

	verItr = polEnt->vertexIterator();

	for (; !verItr->done(); verItr->step()) {
		if (gcdbOpenObject(vertex, verItr->objectId(), GcDb::kForWrite) == Gcad::eOk) {
			if (vertex->vertexType() != GcDb::k2dSplineCtlVertex) {
				loc --;
				vertex->setPosition(pntArr[loc]);                    // returns ECS
				vertex->setBulge(- bulArr[loc]);
			}
			vertex->close();
		}
	}
	delete verItr;
/*
	if (polEnt->isClosed()) {
		// used to be a bug in dynamic arrays (not sure if its still there??)
		GcGePoint3d tmpPt = pts[0];
		pts.append(tmpPt);
		bulges.append(0.0);
	}
*/
}


void ReverseCoordinates(GcDb3dPolyline* polEnt)
{
	GcGePoint3dArray pntArr;
	GcDbObjectIterator* verItr;
	GcDb3dPolylineVertex* vertex;
	int loc;

	verItr = polEnt->vertexIterator();
	if (verItr == NULL)
		return;

	loc = 0;
	for (; !verItr->done(); verItr->step()) {
		if (gcdbOpenObject(vertex, verItr->objectId(), GcDb::kForRead) == Gcad::eOk) {
			pntArr.append(vertex->position());
			loc ++;
			vertex->close();
		}
	}
	delete verItr;

	verItr = polEnt->vertexIterator();

	for (; !verItr->done(); verItr->step()) {
		if (gcdbOpenObject(vertex, verItr->objectId(), GcDb::kForRead) == Gcad::eOk) {
			loc ++;
			vertex->setPosition(pntArr[loc]);
			vertex->close();
		}
	}
	delete verItr;
}


int CompareAscending(const void *a, const void *b)
{
	CString* pA = (CString*)a;
	CString* pB = (CString*)b;
	return (pA->Compare(*pB));
}


int CompareDescending(const void *a, const void *b)
{
	CString* pA = (CString*)a;
	CString* pB = (CString*)b;
	return (-1 * (pA->Compare(*pB)));
}


void SortStringArray (CStringArray& csa, BOOL bDescending)
{
	int iArraySize = csa.GetSize();
	if (iArraySize <= 0)
		return;

	int iCSSize = sizeof (CString*);
	void* pArrayStart = (void *)&csa[0];

	if (bDescending)
		qsort (pArrayStart, iArraySize, iCSSize, CompareDescending);
	else
		qsort (pArrayStart, iArraySize, iCSSize, CompareAscending);
}
