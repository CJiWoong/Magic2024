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

	gcutPrintf(L"\n���������� ��ȯ�� ��ü ����:");
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
		gcutPrintf(_T("\n%d ���� ��ü�� ��� �������� �־ ���������� ��ȯ�� �ȵǾ����ϴ�."), iLock);
	else
		gcutPrintf(_T("\n������ ��ü�� ���������� ��ȯ�Ǿ����ϴ�"));
}

