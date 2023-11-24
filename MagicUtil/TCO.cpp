#include "stdafx.h"
#include "MagicUtil.h"
#include "TCO.h"

// copy text string
void RunTCO()
{
	gds_name ssname;
	struct resbuf rbuf;
	TCHAR sbuf[256];
	gds_name ename;
	GcDbObjectId objId;
	GcDbEntity* pEnt;
	CString sText;
	int iLock;
	int32_t len;
	long i;

	while (1) {
		pEnt = UserSelEnt(_T("\n원본 문자 선택:"), GcDb::kForWrite);
		if (pEnt == NULL)
			return;

		if (pEnt->isKindOf(GcDbText::desc())) {
			GcDbText* txtPtr = GcDbText::cast(pEnt);
			sText = txtPtr->textString();
			break;
		}
		else if (pEnt->isKindOf(GcDbMText::desc())) {
			GcDbMText* mtxtPtr = GcDbMText::cast(pEnt);
			sText = mtxtPtr->text();
			break;
		}
		else if (pEnt->isKindOf(GcDbAttribute::desc())) {
			GcDbAttribute* attPtr = GcDbAttribute::cast(pEnt);
			sText = attPtr->textString();
			break;
		}
		else if (pEnt->isKindOf(GcDbAttributeDefinition::desc())) {
			GcDbAttributeDefinition* adfPtr = GcDbAttributeDefinition::cast(pEnt);
			sText = adfPtr->textString();
			break;
		}
		else
			gcutPrintf(_T("\n* 문자 또는 치수 문자가 아닙니다. *"));
	}

	pEnt->highlight();

	rbuf.restype = 0;
	_tcscpy(sbuf, _T("TEXT,MTEXT,DIMENSION"));
	rbuf.resval.rstring = sbuf;
	rbuf.rbnext = NULL;

	gcutPrintf(L"\n문자를 복사할 대상 객체 선택:");
	gcedSSGet(NULL, NULL, NULL, &rbuf, ssname);

	pEnt->unhighlight();
	pEnt->close();

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

		if (IsLayerLock(pEnt->layer()))
			iLock ++;
		else if (pEnt->isKindOf(GcDbText::desc())) {
			GcDbText* txtPtr = GcDbText::cast(pEnt);
			txtPtr->setTextString(sText);
		}
		else if (pEnt->isKindOf(GcDbMText::desc())) {
			GcDbMText* mtxtPtr = GcDbMText::cast(pEnt);
			mtxtPtr->setContents(sText);
		}
		else if (pEnt->isKindOf(GcDbAttribute::desc())) {
			GcDbAttribute* attPtr = GcDbAttribute::cast(pEnt);
			attPtr->setTextString(sText);
		}
		else if (pEnt->isKindOf(GcDbAttributeDefinition::desc())) {
			GcDbAttributeDefinition* adfPtr = GcDbAttributeDefinition::cast(pEnt);
			adfPtr->setTextString(sText);
		}
		else if (pEnt->isKindOf(GcDbDimension::desc())) {
			GcDbDimension* dimPtr = GcDbDimension::cast(pEnt);
			dimPtr->setDimensionText(sText);
		}
		else if (pEnt->isKindOf(GcDb2LineAngularDimension::desc())) {
			GcDb2LineAngularDimension* dimPtr = GcDb2LineAngularDimension::cast(pEnt);
			dimPtr->setDimensionText(sText);
		}
		else if (pEnt->isKindOf(GcDb3PointAngularDimension::desc())) {
			GcDb3PointAngularDimension* dimPtr = GcDb3PointAngularDimension::cast(pEnt);
			dimPtr->setDimensionText(sText);
		}
		else if (pEnt->isKindOf(GcDbAlignedDimension::desc())) {
			GcDbAlignedDimension* dimPtr = GcDbAlignedDimension::cast(pEnt);
			dimPtr->setDimensionText(sText);
		}
/*
		else if (pEnt->isKindOf(GcDbArcDimension::desc())) {
			GcDbArcDimension* dimPtr = GcDbArcDimension::cast(pEnt);
			dimPtr->setDimensionText(sText);
		}
*/
		else if (pEnt->isKindOf(GcDbDiametricDimension::desc())) {
			GcDbDiametricDimension* dimPtr = GcDbDiametricDimension::cast(pEnt);
			dimPtr->setDimensionText(sText);
		}
		else if (pEnt->isKindOf(GcDbOrdinateDimension::desc())) {
			GcDbOrdinateDimension* dimPtr = GcDbOrdinateDimension::cast(pEnt);
			dimPtr->setDimensionText(sText);
		}
		else if (pEnt->isKindOf(GcDbRadialDimension::desc())) {
			GcDbRadialDimension* dimPtr = GcDbRadialDimension::cast(pEnt);
			dimPtr->setDimensionText(sText);
		}
/*
		else if (pEnt->isKindOf(GcDbRadialDimensionLarge::desc())) {
			GcDbRadialDimensionLarge* dimPtr = GcDbRadialDimensionLarge::cast(pEnt);
			dimPtr->setDimensionText(sText);
		}
*/
		else if (pEnt->isKindOf(GcDbRotatedDimension::desc())) {
			GcDbRotatedDimension* dimPtr = GcDbRotatedDimension::cast(pEnt);
			dimPtr->setDimensionText(sText);
		}
/*
		else
			sText = pEnt->isA()->name();
*/

		pEnt->close();
	}

	gcedSSFree (ssname);

	if (iLock > 0)
		gcutPrintf(_T("\n%d 개의 객체가 잠긴 도면층에 있어서 문자복사가 안되었습니다."), iLock);
}


// exchange text string
void RunTSW()
{
	GcDbEntity* pEnt1;
	GcDbEntity* pEnt2;
	GcDbText* txtPtr;
	GcDbMText* mtxtPtr;
	CString sText1, sText2;

	pEnt1 = UserSelEnt(_T("\n내용을 바꿀 첫번째 문자 선택:"), GcDb::kForWrite);
	if (pEnt1 == NULL)
		return;

	if (IsLayerLock(pEnt1->layer())) {
		gcutPrintf(_T("\n선택한 객체가 잠긴 레이어에 있습니다."));
		pEnt1->close();
		return;
	}

	if (txtPtr = GcDbText::cast(pEnt1), txtPtr)
		sText1 = txtPtr->textString();
	else if (mtxtPtr = GcDbMText::cast(pEnt1), mtxtPtr)
		sText1 = mtxtPtr->text();
	else {
		gcutPrintf(_T("\n선택한 객체는 문자가 아닙니다."));
		pEnt1->close();
		return;
	}

	pEnt1->highlight();
	pEnt2 = UserSelEnt(_T("\n내용을 바꿀 두번째 문자 선택:"), GcDb::kForWrite);
	pEnt1->unhighlight();
	if (pEnt2 == NULL) {
		pEnt1->close();
		return;
	}

	if (IsLayerLock(pEnt2->layer())) {
		gcutPrintf(_T("\n선택한 객체가 잠긴 레이어에 있습니다."));
		pEnt1->close();
		pEnt2->close();
		return;
	}

	if (txtPtr = GcDbText::cast(pEnt2), txtPtr)
		sText2 = txtPtr->textString();
	else if (mtxtPtr = GcDbMText::cast(pEnt2), mtxtPtr)
		sText2 = mtxtPtr->text();
	else {
		gcutPrintf(_T("\n선택한 객체는 문자가 아닙니다."));
		pEnt1->close();
		pEnt2->close();
		return;
	}

	if (txtPtr = GcDbText::cast(pEnt1), txtPtr)
		txtPtr->setTextString(sText2);
	else if (mtxtPtr = GcDbMText::cast(pEnt1), mtxtPtr)
		mtxtPtr->setContents(sText2);

	if (txtPtr = GcDbText::cast(pEnt2), txtPtr)
		txtPtr->setTextString(sText1);
	else if (mtxtPtr = GcDbMText::cast(pEnt2), mtxtPtr)
		mtxtPtr->setContents(sText1);

	pEnt1->close();
	pEnt2->close();
}

LPTSTR DivideNumer(LPTSTR sStr, double dAdd, int iNum)
{
	CString sCnt;
	CString sFTmp;
	CString sLTmp;
	CString sRtn;
	TCHAR bStr[256];
	TCHAR eStr[256];
	TCHAR nStr[256];
	TCHAR *sPtr;
	TCHAR *dPtr;
	BOOL bPoint;

	sPtr = sStr; // source string
	dPtr = bStr; // begin (prefix) string
	while (*sPtr && (*sPtr < '0' || *sPtr > '9'))
		*(dPtr ++) = *(sPtr ++);
	*dPtr = '\0';

	dPtr = nStr; // number string
	bPoint = FALSE;
	while (*sPtr && ((*sPtr >= '0' && *sPtr <= '9') || *sPtr == '.')) {
		if (*sPtr == '.') {
			if (bPoint)
				break;
			bPoint = TRUE;
		}
		*(dPtr ++) = *(sPtr ++);
	}
	*dPtr = '\0';

	dPtr = eStr; // end (postfix) string
	while (*sPtr)
		*(dPtr ++) = *(sPtr ++);
	*dPtr = '\0';

	dAdd += _ttof(nStr);

	static TCHAR rStr[256];

	CString fStr, dStr;
	int iPos;

	fStr.Format(_T("%%0%dd"), iNum);
	dStr.Format(fStr, (int)dAdd);
	fStr.Format(_T("%f"), dAdd - ((int)dAdd));
	iPos = fStr.Find('.');
	if (iPos >= 0)
		fStr = fStr.Right(fStr.GetLength() - iPos - 1);
	while (!fStr.IsEmpty() && fStr[fStr.GetLength() - 1] == '0')
		fStr = fStr.Left(fStr.GetLength() - 1);
	if (!fStr.IsEmpty())
		dStr += _T(".") + fStr;

	_stprintf_s(rStr, 255, _T("%s%s%s"), bStr, (TCHAR*)(LPCTSTR)dStr, eStr);

	return rStr;
}

// copy text and increase text string number
void RunTEI()
{
	gds_name ssname;
	gds_name ename;
	GcDbObjectId objId;
	GcDbEntity* pEnt;
	GcDbEntity* oEnt;
	CString sText;
	int32_t len;
	long i;
	BOOL bExist;
	CString sLock;
	TCHAR sNum[256];
	double dNum, iNum;
	int iDec;
	GcGePoint3d vSpnt;
	GcGePoint3d vEpnt;
	int32_t ret;
	GcGeMatrix3d xform;
	GcGeVector3d transVec;

	gcutPrintf(L"\n숫자가 포함된 문자 및 객체 선택:");
	gcedSSGet(NULL, NULL, NULL, NULL, ssname);

	if ((gcedSSLength(ssname, &len) != RTNORM) || (len < 1)) {
		gcedSSFree (ssname);
		return;
	}

	bExist = FALSE;
	for (i = 0; i < len; i++) {
		if (gcedSSName(ssname, i, ename) != RTNORM)
			continue;
		if (gcdbGetObjectId(objId, ename) != Gcad::eOk)
			continue;
		if (gcdbOpenGcDbEntity(pEnt, objId, GcDb::kForWrite) != Gcad::eOk)
			continue;

		if (pEnt->isKindOf(GcDbText::desc()) ||
			pEnt->isKindOf(GcDbMText::desc())) {
			bExist = TRUE;
			pEnt->close();
			break;
		}

		pEnt->close();
	}

	if (!bExist) {
		gcutPrintf(_T("\n* 선택한 객체 중에 문자가 없습니다 *"));
		gcedSSFree (ssname);
		return;
	}

	sLock = LockBackUp();

	gcedInitGet(2, NULL);
	ret = gcedGetString(FALSE, _T("\n증분 숫자 <1>:"), sNum);
	if (ret == RTNONE)
		dNum = 1;
	else if (ret == RTNORM) {
		if (sNum[0] == '\0')
			dNum = 1;
		else
			dNum = _ttof(sNum);
	}
	else
		goto ErrorHandler;

	gcedInitGet(2 + 4, NULL);
	ret = gcedGetInt(_T("\n증분 숫자 자리수 <1>:"), &iDec);
	if (ret == RTNONE)
		iDec = 1;
	else if (ret == RTNORM) {
		if (iDec < 1)
			iDec = 1;
	}
	else
		goto ErrorHandler;

	if (gcedGetPoint(NULL, _T("\n기준점 지정:"), asDblArray(vSpnt)) != RTNORM)
		goto ErrorHandler;
	vSpnt = ToUCS(vSpnt);

	iNum = dNum;
	while (1) {
		gcedInitGet(32, NULL);
		if (gcedGetPoint(asDblArray(vSpnt), _T("\n다음점 지정:"), asDblArray(vEpnt)) != RTNORM)
			break;
		vEpnt = ToUCS(vEpnt);

		transVec = vEpnt - vSpnt;
		xform.setToTranslation(transVec);

		for (i = 0; i < len; i++) {
			if (gcedSSName(ssname, i, ename) != RTNORM)
				continue;
			if (gcdbGetObjectId(objId, ename) != Gcad::eOk)
				continue;
			if (gcdbOpenGcDbEntity(pEnt, objId, GcDb::kForWrite) != Gcad::eOk)
				continue;

			oEnt = GcDbEntity::cast(pEnt->clone());
			pEnt->close();

			oEnt->transformBy(xform);

			if (pEnt->isKindOf(GcDbText::desc())) {
				GcDbText* txtPtr = GcDbText::cast(oEnt);
				sText = DivideNumer(txtPtr->textString(), iNum, iDec);
				txtPtr->setTextString(sText);
			}
			else if (pEnt->isKindOf(GcDbMText::desc())) {
				GcDbMText* mtxtPtr = GcDbMText::cast(oEnt);
				sText = DivideNumer(mtxtPtr->text(), iNum, iDec);
				mtxtPtr->setContents(sText);
			}

			AddCurrSpace(oEnt);
			oEnt->close();
		}

		iNum += dNum;
	}

ErrorHandler:
	gcedSSFree (ssname);
	LockRestore(sLock);
}

void JustifyText(GcDbText* oText, GcDb::TextHorzMode horMode, GcDb::TextVertMode verMode)
{
	GcGePoint3d vBpnt;
	GcGePoint3d vIpnt;
	GcGeMatrix3d xform;
	GcGeVector3d transVec;

	if (oText->horizontalMode() == horMode && oText->verticalMode() == verMode)
		return;

	//vBpnt = oText->alignmentPoint();
	vBpnt = oText->position();
	oText->setHorizontalMode(horMode);
	oText->setVerticalMode(verMode);
	//vIpnt = oText->alignmentPoint();
	vIpnt = oText->position();

	transVec = vIpnt - vBpnt;
	xform.setToTranslation(transVec);

	oText->transformBy(xform);
}

GcDb::TextHorzMode horizontalMode(GcDbMText* pMtext)
{
	switch (pMtext->attachment())
	{
	case GcDbMText::kTopCenter:
	case GcDbMText::kBottomCenter:
	case GcDbMText::kMiddleCenter:
		return GcDb::kTextCenter;
	case GcDbMText::kTopRight:
	case GcDbMText::kMiddleRight:
	case GcDbMText::kBottomRight:
		return GcDb::kTextRight;
	}
	return GcDb::kTextLeft;
}

GcDb::TextVertMode verticalMode(GcDbMText* pMtext)
{
	switch (pMtext->attachment())
	{
	case GcDbMText::kMiddleLeft:
	case GcDbMText::kMiddleCenter:
	case GcDbMText::kMiddleRight:
		return GcDb::kTextVertMid;

	case GcDbMText::kBottomLeft:
	case GcDbMText::kBottomCenter:
	case GcDbMText::kBottomRight:
		return GcDb::kTextBottom;
	}
	return GcDb::kTextTop;
}

void setHorizontalMode(GcDbMText* pMtext, GcDb::TextHorzMode mode)
{
	switch (mode) {
	default:
		throw Gcad::eNotApplicable;

	case GcDb::kTextLeft:
		switch (pMtext->attachment()) {
		default:  // Top
			pMtext->setAttachment(GcDbMText::kTopLeft);
			break;

		case GcDbMText::kMiddleLeft:
		case GcDbMText::kMiddleCenter:
		case GcDbMText::kMiddleRight:
			pMtext->setAttachment(GcDbMText::kMiddleLeft);
			break;
		case GcDbMText::kBottomLeft:
		case GcDbMText::kBottomCenter:
		case GcDbMText::kBottomRight:
			pMtext->setAttachment(GcDbMText::kBottomLeft);
			break;
		}
		break;

	case GcDb::kTextCenter:
		switch (pMtext->attachment()) {
		default:  // Top
			pMtext->setAttachment(GcDbMText::kTopCenter);
			break;
		case GcDbMText::kMiddleLeft:
		case GcDbMText::kMiddleCenter:
		case GcDbMText::kMiddleRight:
			pMtext->setAttachment(GcDbMText::kMiddleCenter);
			break;
		case GcDbMText::kBottomLeft:
		case GcDbMText::kBottomCenter:
		case GcDbMText::kBottomRight:
			pMtext->setAttachment(GcDbMText::kBottomCenter);
			break;
		}
		break;

	case GcDb::kTextRight:
		switch (pMtext->attachment()) {
		default:  // Top
			pMtext->setAttachment(GcDbMText::kTopRight);
			break;
		case GcDbMText::kMiddleLeft:
		case GcDbMText::kMiddleCenter:
		case GcDbMText::kMiddleRight:
			pMtext->setAttachment(GcDbMText::kMiddleRight);
			break;
		case GcDbMText::kBottomLeft:
		case GcDbMText::kBottomCenter:
		case GcDbMText::kBottomRight:
			pMtext->setAttachment(GcDbMText::kBottomRight);
			break;
		}
		break;
	}
}

void setVerticalMode(GcDbMText* pMtext, GcDb::TextVertMode mode) {
	switch (mode) {
	default:
		throw Gcad::eNotApplicable;

	case GcDb::kTextBottom:
		switch (pMtext->attachment()) {
		default:  // Left
			pMtext->setAttachment(GcDbMText::kBottomLeft);
			break;
		case GcDbMText::kTopCenter:
		case GcDbMText::kMiddleCenter:
		case GcDbMText::kBottomCenter:
			pMtext->setAttachment(GcDbMText::kBottomCenter);
			break;
		case GcDbMText::kTopRight:
		case GcDbMText::kMiddleRight:
		case GcDbMText::kBottomRight:
			pMtext->setAttachment(GcDbMText::kBottomRight);
			break;
		}
		break;

	case GcDb::kTextVertMid:
		switch (pMtext->attachment()) {
		default:  // Left
			pMtext->setAttachment(GcDbMText::kMiddleLeft);
			break;
		case GcDbMText::kTopCenter:
		case GcDbMText::kMiddleCenter:
		case GcDbMText::kBottomCenter:
			pMtext->setAttachment(GcDbMText::kMiddleCenter);
			break;
		case GcDbMText::kTopRight:
		case GcDbMText::kMiddleRight:
		case GcDbMText::kBottomRight:
			pMtext->setAttachment(GcDbMText::kMiddleRight);
			break;
		}
		break;

	case GcDb::kTextTop:
		switch (pMtext->attachment()) {
		default:  // Left
			pMtext->setAttachment(GcDbMText::kTopLeft);
			break;
		case GcDbMText::kTopCenter:
		case GcDbMText::kMiddleCenter:
		case GcDbMText::kBottomCenter:
			pMtext->setAttachment(GcDbMText::kTopCenter);
			break;
		case GcDbMText::kTopRight:
		case GcDbMText::kMiddleRight:
		case GcDbMText::kBottomRight:
			pMtext->setAttachment(GcDbMText::kTopRight);
			break;
		}
		break;
	}
}

void JustifyMText(GcDbMText* oText, GcDb::TextHorzMode horMode, GcDb::TextVertMode verMode)
{
	GcGePoint3d vBpnt;
	GcGePoint3d vIpnt;
	GcGeMatrix3d xform;
	GcGeVector3d transVec;

	if (horizontalMode(oText) == horMode && verticalMode(oText) == verMode)
		return;

	vBpnt = oText->location();
	setHorizontalMode(oText, horMode);
	setVerticalMode(oText, verMode);
	vIpnt = oText->location();

	transVec = vIpnt - vBpnt;
	xform.setToTranslation(transVec);

	oText->transformBy(xform);
}

// arrange to the center of rectangle
void RunCR()
{
	gds_name ssname;
	struct resbuf rbuf;
	TCHAR sbuf[256];
	gds_name ename;
	GcDbObjectId objId;
	GcDbEntity* pEnt;
	int32_t len;
	long i;
	GcGePoint3d vSpnt;
	GcGePoint3d vEpnt;
	GcGePoint3d varPnt;
	GcGePoint3d vInsPnt;
	GcGePoint3d vMin;
	GcGePoint3d vMax;
	GcGePoint3d vCen;
	int iLock;

	rbuf.restype = 0;
	_tcscpy(sbuf, _T("TEXT,MTEXT,ATTDEF"));
	rbuf.resval.rstring = sbuf;
	rbuf.rbnext = NULL;

	gcutPrintf(L"\n사각영역의 중심으로 이동시킬 문자 선택:");
	gcedSSGet(NULL, NULL, NULL, &rbuf, ssname);

	if ((gcedSSLength(ssname, &len) != RTNORM) || (len < 1)) {
		gcedSSFree (ssname);
		return;
	}

	if (gcedGetPoint(NULL, _T("\n첫번째 모서리 점 선택:"), asDblArray(vSpnt)) != RTNORM)
		goto ErrorHandler;
	vSpnt = ToUCS(vSpnt);

	gcedInitGet(32, NULL);
	if (gcedGetCorner(asDblArray(vSpnt), _T("\n두번째 모서리 점 선택:"), asDblArray(vEpnt)) != RTNORM)
		goto ErrorHandler;
	vEpnt = ToUCS(vEpnt);

	varPnt = GetMidByTwoPoint(vSpnt, vEpnt);

	iLock = 0;
	if (len == 1) {
		gcedSSName(ssname, 0, ename);
		gcdbGetObjectId(objId, ename);
		gcdbOpenGcDbEntity(pEnt, objId, GcDb::kForWrite);

		if (IsLayerLock(pEnt->layer()))
			iLock ++;
		else if (pEnt->isKindOf(GcDbText::desc())) {
			GcDbText* txtPtr = GcDbText::cast(pEnt);
			// if alignment mode is changed, then text position is changed to zero
			txtPtr->setHorizontalMode(GcDb::kTextCenter);
			txtPtr->setVerticalMode(GcDb::kTextVertMid);
			txtPtr->setAlignmentPoint(ToWCS(varPnt));
		}
		else if (pEnt->isKindOf(GcDbAttributeDefinition::desc())) {
			GcDbAttributeDefinition* attDef = GcDbAttributeDefinition::cast(pEnt);
			attDef->setHorizontalMode(GcDb::kTextCenter);
			attDef->setVerticalMode(GcDb::kTextVertMid);
			attDef->setAlignmentPoint(ToWCS(varPnt));
		}
		else if (pEnt->isKindOf(GcDbMText::desc())) {
			GcDbMText* mtxtPtr = GcDbMText::cast(pEnt);
			setHorizontalMode(mtxtPtr, GcDb::kTextCenter);
			setVerticalMode(mtxtPtr, GcDb::kTextVertMid);
			mtxtPtr->setLocation(ToWCS(varPnt));
		}

		pEnt->close();
	}
	else {
		GetSelSetBoundingBox(vMin, vMax, ssname);
		vMin = ToUCS(vMin);
		vMax = ToUCS(vMax);
		vCen = GetMidByTwoPoint(vMin, vMax);

		GcGeMatrix3d xform;
		GcGeVector3d transVec;
		transVec = varPnt - vCen;
		xform.setToTranslation(transVec);

		for (i = 0; i < len; i++) {
			gcedSSName(ssname, i, ename);
			gcdbGetObjectId(objId, ename);
			gcdbOpenGcDbEntity(pEnt, objId, GcDb::kForWrite);

			if (IsLayerLock(pEnt->layer()))
				iLock ++;
			else
				pEnt->transformBy(xform);

			pEnt->close();
		}
	}

	if (iLock > 0)
		gcutPrintf(_T("\n%d 개의 객체가 잠긴 도면층에 있어서 정렬이 안되었습니다."), iLock);

ErrorHandler:
	gcedSSFree (ssname);
}
