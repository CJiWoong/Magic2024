// 컴퓨터에서 형식 라이브러리 마법사의 [클래스 추가]를 사용하여 생성한 IDispatch 래퍼 클래스입니다.

// #import "C:\\Program Files\\Dream\\DreamSub.dll" no_namespace
// CclsFunc 래퍼 클래스

class CclsFunc : public COleDispatchDriver
{
public:
	CclsFunc(){} // COleDispatchDriver 기본 생성자를 호출합니다.
	CclsFunc(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CclsFunc(const CclsFunc& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 특성
public:

	// 작업
public:


	// _clsFunc 메서드
public:
	double Pi()
	{
		double result;
		InvokeHelper(0x60030000, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
		return result;
	}
	short GetQuadrant(double dAng)
	{
		short result;
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x60030001, DISPATCH_METHOD, VT_I2, (void*)&result, parms, dAng);
		return result;
	}
	VARIANT GetOffsetPoint(VARIANT& vIns, double dAng, double dOffset)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_R8 VTS_R8 ;
		InvokeHelper(0x60030002, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vIns, dAng, dOffset);
		return result;
	}
	VARIANT GetOffsetPointLR(VARIANT& vIns, double dAng, double dOffset, BOOL bLeft)
	{
		VARIANT result;
		static BYTE parms[] = VTS_VARIANT VTS_R8 VTS_R8 VTS_BOOL ;
		InvokeHelper(0x60030003, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, &vIns, dAng, dOffset, bLeft);
		return result;
	}
	BOOL IsEqual(VARIANT& dValue1, VARIANT& dValue2, VARIANT& dTol)
	{
		BOOL result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x60030004, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, &dValue1, &dValue2, &dTol);
		return result;
	}
	double Length(VARIANT& vSpnt, VARIANT& vEpnt)
	{
		double result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x60030005, DISPATCH_METHOD, VT_R8, (void*)&result, parms, &vSpnt, &vEpnt);
		return result;
	}
	double Length2D(VARIANT& vSpnt, VARIANT& vEpnt)
	{
		double result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x60030006, DISPATCH_METHOD, VT_R8, (void*)&result, parms, &vSpnt, &vEpnt);
		return result;
	}
	short ClockWise(VARIANT& vSpnt, VARIANT& vEpnt, VARIANT& vNpnt)
	{
		short result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x60030007, DISPATCH_METHOD, VT_I2, (void*)&result, parms, &vSpnt, &vEpnt, &vNpnt);
		return result;
	}
	double GetEncloseAng(VARIANT& vSpnt, VARIANT& vIpnt, VARIANT& vEpnt)
	{
		double result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x60030008, DISPATCH_METHOD, VT_R8, (void*)&result, parms, &vSpnt, &vIpnt, &vEpnt);
		return result;
	}
	CString REPT(LPCTSTR sNumber, short iNum)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_I2 ;
		InvokeHelper(0x60030009, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, sNumber, iNum);
		return result;
	}
	double ExMod(double dValue, double dDivide)
	{
		double result;
		static BYTE parms[] = VTS_R8 VTS_R8 ;
		InvokeHelper(0x6003000a, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dValue, dDivide);
		return result;
	}
	double RoundUp(double dValue, short * iPlace)
	{
		double result;
		static BYTE parms[] = VTS_R8 VTS_PI2 ;
		InvokeHelper(0x6003000b, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dValue, iPlace);
		return result;
	}
	double RoundDown(double dValue, short iPlace)
	{
		double result;
		static BYTE parms[] = VTS_R8 VTS_I2 ;
		InvokeHelper(0x6003000c, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dValue, iPlace);
		return result;
	}
	double FixByNumber(double dNumber, double dFix)
	{
		double result;
		static BYTE parms[] = VTS_R8 VTS_R8 ;
		InvokeHelper(0x6003000d, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dNumber, dFix);
		return result;
	}
	double MultipleNumber(double dNumber, double dMultiple)
	{
		double result;
		static BYTE parms[] = VTS_R8 VTS_R8 ;
		InvokeHelper(0x6003000e, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dNumber, dMultiple);
		return result;
	}
	VARIANT PortionNumber(double dValue, double dDivide, short * iRound)
	{
		VARIANT result;
		static BYTE parms[] = VTS_R8 VTS_R8 VTS_PI2 ;
		InvokeHelper(0x6003000f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dValue, dDivide, iRound);
		return result;
	}
	double R2D(double dRadian)
	{
		double result;
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x60030010, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dRadian);
		return result;
	}
	double D2R(double dDegree)
	{
		double result;
		static BYTE parms[] = VTS_R8 ;
		InvokeHelper(0x60030011, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dDegree);
		return result;
	}
	VARIANT SwapData(VARIANT * vFirst, VARIANT * vSecond)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x60030012, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, vFirst, vSecond);
		return result;
	}
	VARIANT SwapObj(LPDISPATCH * oFirst, LPDISPATCH * oSecond)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PDISPATCH VTS_PDISPATCH ;
		InvokeHelper(0x60030013, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, oFirst, oSecond);
		return result;
	}
	VARIANT SwapSort(SAFEARRAY * * sArray, BOOL bCaps, short Direction)
	{
		VARIANT result;
		static BYTE parms[] = VTS_UNKNOWN VTS_BOOL VTS_I2 ;
		InvokeHelper(0x60030014, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, sArray, bCaps, Direction);
		return result;
	}
	VARIANT SortTextX(LPDISPATCH * oSel, BOOL * bReverse, double * dTWAng)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PDISPATCH VTS_PBOOL VTS_PR8 ;
		InvokeHelper(0x60030015, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, oSel, bReverse, dTWAng);
		return result;
	}
	VARIANT SortTextY(LPDISPATCH * oSel, BOOL * bReverse, double * dTWAng)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PDISPATCH VTS_PBOOL VTS_PR8 ;
		InvokeHelper(0x60030016, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, oSel, bReverse, dTWAng);
		return result;
	}
	VARIANT SortTextYX(LPDISPATCH * oSel, double * dTWAng)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PDISPATCH VTS_PR8 ;
		InvokeHelper(0x60030017, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, oSel, dTWAng);
		return result;
	}
	VARIANT SortTextXY(LPDISPATCH * oSel, double * dTWAng)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PDISPATCH VTS_PR8 ;
		InvokeHelper(0x60030018, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, oSel, dTWAng);
		return result;
	}
	VARIANT SortTextTable(LPDISPATCH * oSel, double * dTol, double * dTWAng)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PDISPATCH VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030019, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, oSel, dTol, dTWAng);
		return result;
	}
	VARIANT SortTextZ(LPDISPATCH * oSel, double * dTol, double * dTWAng)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PDISPATCH VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x6003001a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, oSel, dTol, dTWAng);
		return result;
	}
	VARIANT SortAlphanumSel(LPDISPATCH * oSel, BOOL * bDesc)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PDISPATCH VTS_PBOOL ;
		InvokeHelper(0x6003001b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, oSel, bDesc);
		return result;
	}
	VARIANT RegionRULD(VARIANT * vFirst, VARIANT * vSecond)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x6003001c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, vFirst, vSecond);
		return result;
	}
	VARIANT SortListZ(VARIANT * vList, double * dTol, double * dTWAng)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PVARIANT VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x6003001d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, vList, dTol, dTWAng);
		return result;
	}
	VARIANT SortListN(VARIANT * vList, double * dTol, double * dTWAng)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PVARIANT VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x6003001e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, vList, dTol, dTWAng);
		return result;
	}
	VARIANT SortListIN(VARIANT * vList, double * dTol, double * dTWAng)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PVARIANT VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x6003001f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, vList, dTol, dTWAng);
		return result;
	}
	VARIANT SortListX(VARIANT * vList, BOOL * bReverse, double * dTWAng)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PVARIANT VTS_PBOOL VTS_PR8 ;
		InvokeHelper(0x60030020, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, vList, bReverse, dTWAng);
		return result;
	}
	VARIANT SortListY(VARIANT * vList, BOOL * bReverse, double * dTWAng)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PVARIANT VTS_PBOOL VTS_PR8 ;
		InvokeHelper(0x60030021, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, vList, bReverse, dTWAng);
		return result;
	}
	VARIANT SortSelZ(LPDISPATCH * SelSet, double * dTol, double * dTWAng)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PDISPATCH VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030022, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, SelSet, dTol, dTWAng);
		return result;
	}
	VARIANT SortSelZ_R(LPDISPATCH * SelSet, double * dTol, double * dTWAng)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PDISPATCH VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030023, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, SelSet, dTol, dTWAng);
		return result;
	}
	VARIANT SortSelIZ_R(LPDISPATCH * SelSet, double * dTol, double * dTWAng)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PDISPATCH VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030024, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, SelSet, dTol, dTWAng);
		return result;
	}
	VARIANT SortSelN_R(LPDISPATCH * SelSet, double * dTol, double * dTWAng)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PDISPATCH VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030025, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, SelSet, dTol, dTWAng);
		return result;
	}
	VARIANT SortSelIN_R(LPDISPATCH * SelSet, double * dTol, double * dTWAng)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PDISPATCH VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030026, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, SelSet, dTol, dTWAng);
		return result;
	}
	VARIANT SortSelIZ(LPDISPATCH * SelSet, double * dTol, double * dTWAng)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PDISPATCH VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030027, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, SelSet, dTol, dTWAng);
		return result;
	}
	VARIANT SortSelN(LPDISPATCH * SelSet, double * dTol, double * dTWAng)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PDISPATCH VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030028, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, SelSet, dTol, dTWAng);
		return result;
	}
	VARIANT SortSelIN(LPDISPATCH * SelSet, double * dTol, double * dTWAng)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PDISPATCH VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030029, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, SelSet, dTol, dTWAng);
		return result;
	}
	VARIANT SortCoordIX(VARIANT * vList)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PVARIANT ;
		InvokeHelper(0x6003002a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, vList);
		return result;
	}
	VARIANT SortCoordY(VARIANT * vList)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PVARIANT ;
		InvokeHelper(0x6003002b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, vList);
		return result;
	}
	CString GetRelativePath(LPCTSTR sFromPath, LPCTSTR sTargetPath)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x6003002c, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, sFromPath, sTargetPath);
		return result;
	}
	CString GetAbsolutePath(LPCTSTR sBasePath, LPCTSTR sConvertPath)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x6003002d, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, sBasePath, sConvertPath);
		return result;
	}
	CString FindFile(LPCTSTR sFileName, BSTR * sPath)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR ;
		InvokeHelper(0x60030030, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, sFileName, sPath);
		return result;
	}
	double GetAzi(VARIANT& vPnt1, VARIANT& vPnt2)
	{
		double result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x60030031, DISPATCH_METHOD, VT_R8, (void*)&result, parms, &vPnt1, &vPnt2);
		return result;
	}
	CString GetNumber(LPCTSTR sText)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60030032, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, sText);
		return result;
	}
	VARIANT StrToPnt(LPCTSTR sCoord, LPCTSTR sDelim)
	{
		VARIANT result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x60030033, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, sCoord, sDelim);
		return result;
	}
	CString GetAngleUnit(double dDeg, short iUnit)
	{
		CString result;
		static BYTE parms[] = VTS_R8 VTS_I2 ;
		InvokeHelper(0x60030034, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, dDeg, iUnit);
		return result;
	}
	void LaunchBrowser(BSTR * sURL, long * State)
	{
		static BYTE parms[] = VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x60030035, DISPATCH_METHOD, VT_EMPTY, NULL, parms, sURL, State);
	}
	VARIANT PointRotateByBase(VARIANT * vBase, VARIANT * vPoint, double * dTheta)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PVARIANT VTS_PVARIANT VTS_PR8 ;
		InvokeHelper(0x60030036, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, vBase, vPoint, dTheta);
		return result;
	}
	void AlphanumSort(SAFEARRAY * * sArray, BOOL bSortDesc)
	{
		static BYTE parms[] = VTS_UNKNOWN VTS_BOOL ;
		InvokeHelper(0x60030037, DISPATCH_METHOD, VT_EMPTY, NULL, parms, sArray, bSortDesc);
	}
	void AlphanumSortMA(SAFEARRAY * * sArray, unsigned char btColumn, BOOL bSortDesc, long iMin, long iMax)
	{
		static BYTE parms[] = VTS_UNKNOWN VTS_UI1 VTS_BOOL VTS_I4 VTS_I4 ;
		InvokeHelper(0x60030038, DISPATCH_METHOD, VT_EMPTY, NULL, parms, sArray, btColumn, bSortDesc, iMin, iMax);
	}
	void ReverseArray(SAFEARRAY * * sArray)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x6003003f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, sArray);
	}
	void ReverseArrayMA(SAFEARRAY * * sArray)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x60030040, DISPATCH_METHOD, VT_EMPTY, NULL, parms, sArray);
	}
	double DMS2DEG(BSTR * DMS)
	{
		double result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x60030042, DISPATCH_METHOD, VT_R8, (void*)&result, parms, DMS);
		return result;
	}
	CString DEG2DMS(double * dDegree, short * iDecimal, short * iOpt)
	{
		CString result;
		static BYTE parms[] = VTS_PR8 VTS_PI2 VTS_PI2 ;
		InvokeHelper(0x60030043, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, dDegree, iDecimal, iOpt);
		return result;
	}
	BOOL IsNumber(LPCTSTR sNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60030045, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, sNumber);
		return result;
	}
	CString RemoveNull(LPCTSTR sValue)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60030046, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, sValue);
		return result;
	}

	// _clsFunc 속성
public:

};
