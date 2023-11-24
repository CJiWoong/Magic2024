// 컴퓨터에서 형식 라이브러리 마법사의 [클래스 추가]를 사용하여 생성한 IDispatch 래퍼 클래스입니다.

// #import "C:\\Program Files\\Dream\\DreamSub.dll" no_namespace
// CclsPub 래퍼 클래스

class CclsPub : public COleDispatchDriver
{
public:
	CclsPub(){} // COleDispatchDriver 기본 생성자를 호출합니다.
	CclsPub(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CclsPub(const CclsPub& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 특성
public:

	// 작업
public:


	// _clsPub 메서드
public:
	void putref_ThisDrawing(LPDISPATCH * newValue)
	{
		static BYTE parms[] = VTS_PDISPATCH ;
		InvokeHelper(0x68030000, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_ThisDrawing()
	{
		LPDISPATCH result;
		InvokeHelper(0x68030000, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	VARIANT CmdPrompt(BSTR * sPrompt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x60030002, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, sPrompt);
		return result;
	}
	BOOL XXX()
	{
		BOOL result;
		InvokeHelper(0x60030003, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	long DeleteDupEntity(LPDISPATCH * oSel, BSTR * sObj, BOOL * bLayer, BOOL * bZ, short * iDec, BSTR * sLayer)
	{
		long result;
		static BYTE parms[] = VTS_PDISPATCH VTS_PBSTR VTS_PBOOL VTS_PBOOL VTS_PI2 VTS_PBSTR ;
		InvokeHelper(0x60030005, DISPATCH_METHOD, VT_I4, (void*)&result, parms, oSel, sObj, bLayer, bZ, iDec, sLayer);
		return result;
	}
	CString GetVersion()
	{
		CString result;
		InvokeHelper(0x60030008, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	BOOL CheckLayer(BSTR * sLayerName)
	{
		BOOL result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x60030009, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, sLayerName);
		return result;
	}
	CString GetLayerState(LPDISPATCH * oLayer, BOOL * bFirst)
	{
		CString result;
		static BYTE parms[] = VTS_PDISPATCH VTS_PBOOL ;
		InvokeHelper(0x6003000a, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, oLayer, bFirst);
		return result;
	}
	BOOL LayerMessage(BSTR * sLayer)
	{
		BOOL result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x6003000b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, sLayer);
		return result;
	}
	BOOL CheckESC()
	{
		BOOL result;
		InvokeHelper(0x6003000c, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	VARIANT GetPnt(VARIANT * vBase, BSTR * sPrmpt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PVARIANT VTS_PBSTR ;
		InvokeHelper(0x6003000d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, vBase, sPrmpt);
		return result;
	}
	VARIANT GetPickPoint()
	{
		VARIANT result;
		InvokeHelper(0x6003000e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH GetEntityEx(BSTR * sType, BSTR * sPrmpt, BSTR * strErr)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_PBSTR VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x6003000f, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, sType, sPrmpt, strErr);
		return result;
	}
	LPDISPATCH GetEntityName(BSTR * sObjName, BSTR * sPrmpt, BSTR * sError)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_PBSTR VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x60030010, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, sObjName, sPrmpt, sError);
		return result;
	}
	LPDISPATCH GetObj(BSTR * sPrmpt)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x60030011, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, sPrmpt);
		return result;
	}
	LPDISPATCH GetArc(BSTR * sPrmpt)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x60030012, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, sPrmpt);
		return result;
	}
	LPDISPATCH GetCurve(BSTR * sPrmpt)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x60030013, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, sPrmpt);
		return result;
	}
	LPDISPATCH GetPLine(BSTR * sPrmpt, BOOL * bIncludeArc)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_PBSTR VTS_PBOOL ;
		InvokeHelper(0x60030014, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, sPrmpt, bIncludeArc);
		return result;
	}
	LPDISPATCH GetText(BSTR * sPrmpt)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x60030015, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, sPrmpt);
		return result;
	}
	LPDISPATCH GetLine(BSTR * sPrmpt)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x60030016, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, sPrmpt);
		return result;
	}
	LPDISPATCH GetCircle(BSTR * sPrmpt)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x60030017, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, sPrmpt);
		return result;
	}
	LPDISPATCH GetSubObj(BSTR * sPrmpt)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x60030018, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, sPrmpt);
		return result;
	}
	short GetCoordCount(LPDISPATCH * oPoly)
	{
		short result;
		static BYTE parms[] = VTS_PDISPATCH ;
		InvokeHelper(0x60030019, DISPATCH_METHOD, VT_I2, (void*)&result, parms, oPoly);
		return result;
	}
	LPDISPATCH CreateSelSet(BSTR * sSelSetName)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x6003001a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, sSelSetName);
		return result;
	}
	VARIANT GetRadiusFromBulge(double * dBulge, VARIANT * vSpnt, VARIANT * vEpnt)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x6003001b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dBulge, vSpnt, vEpnt);
		return result;
	}
	CString LspEnt(LPDISPATCH * obj)
	{
		CString result;
		static BYTE parms[] = VTS_PDISPATCH ;
		InvokeHelper(0x6003001c, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, obj);
		return result;
	}

	// _clsPub 속성
public:

};
