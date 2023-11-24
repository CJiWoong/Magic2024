#include "stdafx.h"
#include "MagicUtil.h"
#include "CTP.h"

// convert circle or arc to polyline
void RunCTP()
{
	gds_name ssname;
	struct resbuf rbuf;
	TCHAR sbuf[256];
	gds_name ename;
	GcDbObjectId objId;
	GcDbEntity* pEnt;
	GcDbPolyline *polEnt;
	int iLock;
	Gsoft::Int32 len;
	long i;

	rbuf.restype = 0;
	_tcscpy(sbuf, _T("CIRCLE,ARC"));
	rbuf.resval.rstring = sbuf;
	rbuf.rbnext = NULL;

	gcutPrintf(L"\n폴리선으로 변환할 객체 선택:");
	gcedSSGet(NULL, NULL, NULL, &rbuf, ssname);

	if ((gcedSSLength(ssname, &len) != RTNORM) || (len < 1)) {
		gcedSSFree (ssname);
		return;
	}

	iLock = 0;
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
			polEnt = ConvertPoly(pEnt, TRUE);
			if (polEnt == NULL)
				continue;
			polEnt->close();
		}
	}

	gcedSSFree (ssname);

	if (iLock > 0)
		gcutPrintf(_T("\n%d 개의 객체가 잠긴 도면층에 있어서 폴리선으로 변환이 안되었습니다."), iLock);
	else
		gcutPrintf(_T("\n선택한 객체가 폴리선으로 변환되었습니다"));
}

