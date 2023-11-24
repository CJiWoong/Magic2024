#include "stdafx.h"
#include "MagicUtil.h"
#include "PW.h"

// change line thickness
void RunPW()
{
	gds_name ssname;
	struct resbuf rbuf;
	TCHAR sbuf[256];
	gds_name ename;
	GcDbObjectId objId;
	GcDbEntity* pEnt;
	GcDbPolyline *polEnt;
	GcDb2dPolyline *pol2dEnt;
	CString sWidth;
	double dWidth;
	int iDec;
	CString sFormat;
	CString cstr;
	double dCurW, dLstW;
	BOOL bSame;
	int iLock;
	int i3D;
	BOOL b3D;
	long len;
	long i;

	rbuf.restype = 0;
	_tcscpy(sbuf, _T("LINE,CIRCLE,ARC,POLYLINE,LWPOLYLINE"));
	rbuf.resval.rstring = sbuf;
	rbuf.rbnext = NULL;

	gcutPrintf(L"\n선두께를 변경할 객체 선택:");
	gcedSSGet(NULL, NULL, NULL, &rbuf, ssname);

	if ((gcedSSLength(ssname, &len) != RTNORM) || (len < 1)) {
		gcedSSFree (ssname);
		return;
	}

	bSame = TRUE;
	dLstW = -1;
	for (i = 0; i < len; i++) {
		if (gcedSSName(ssname, i, ename) != RTNORM)
			continue;
		if (gcdbGetObjectId(objId, ename) != Gcad::eOk)
			continue;
		if (gcdbOpenGcDbEntity(pEnt, objId, GcDb::kForWrite) != Gcad::eOk)
			continue;

		b3D = FALSE;
		if (pEnt->isKindOf(GcDbLine::desc()) ||
			pEnt->isKindOf(GcDbCircle::desc()) ||
			pEnt->isKindOf(GcDbArc::desc())) {
			dCurW = 0;
		}
		else if (pEnt->isKindOf(GcDbPolyline::desc())) {
			polEnt = GcDbPolyline::cast(pEnt);
			polEnt->getConstantWidth(dCurW);
		}
		else if (pEnt->isKindOf(GcDb2dPolyline::desc())) {
			pol2dEnt = GcDb2dPolyline::cast(pEnt);
			dCurW = 0;
		}
		else if (pEnt->isKindOf(GcDb3dPolyline::desc()))
			b3D = TRUE;

		pEnt->close();

		if (dLstW != -1 && dLstW != dCurW) {
			bSame = FALSE;
			break;
		}
		else if (!b3D)
			dLstW = dCurW;
	}

	GetVariable(_T("LUPREC"), iDec);
	sFormat = GetFormat(iDec);
	if (bSame) {
		cstr = GetFormat(iDec);
		sWidth.Format(cstr, dCurW);
	}
	else
		sWidth = _T("*다양함*");

	cstr.Format(_T("\n선 두께 입력 <현재 두께=%s>:"), sWidth);
	gcedInitGet(1 + 4, _T(""));
	if (gcedGetReal(cstr, &dWidth) != RTNORM)
		return;

	iLock = 0;
	i3D = 0;
	for (i = 0; i < len; i++) {
		if (gcedSSName(ssname, i, ename) != RTNORM)
			continue;
		if (gcdbGetObjectId(objId, ename) != Gcad::eOk)
			continue;
		if (gcdbOpenGcDbEntity(pEnt, objId, GcDb::kForWrite) != Gcad::eOk)
			continue;

		if (IsLayerLock(pEnt->layer())) {
			iLock ++;
			pEnt->close();
		}
		else {
			if (pEnt->isKindOf(GcDbLine::desc()) ||
				pEnt->isKindOf(GcDbCircle::desc()) ||
				pEnt->isKindOf(GcDbArc::desc())) {
				polEnt = ConvertPoly(pEnt, TRUE);
				polEnt->setConstantWidth(dWidth);
				polEnt->close();
			}
			else if (pEnt->isKindOf(GcDbPolyline::desc())) {
				polEnt = GcDbPolyline::cast(pEnt);
				polEnt->setConstantWidth(dWidth);
				polEnt->close();
			}
			else if (pEnt->isKindOf(GcDb2dPolyline::desc())) {
				pol2dEnt = GcDb2dPolyline::cast(pEnt);
				pol2dEnt->setThickness(dWidth);
				polEnt->close();
			}
			else if (pEnt->isKindOf(GcDb3dPolyline::desc())) {
				i3D ++;
				pEnt->close();
			}
			else
				pEnt->close();
		}
	}

	gcedSSFree (ssname);

	if (iLock > 0)
		gcutPrintf(_T("\n%d 개의 객체가 잠긴 도면층에 있어서 선두께 변경이 안되었습니다."), iLock);
	if (i3D > 0)
		gcutPrintf(_T("\n%d 개의 3D 폴리선 객체는 선두께 변경이 안되었습니다."), i3D);
}

