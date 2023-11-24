// 컴퓨터에서 형식 라이브러리 마법사의 [클래스 추가]를 사용하여 생성한 IDispatch 래퍼 클래스입니다.

// #import "C:\\Program Files\\Dream\\DreamSub.dll" no_namespace
// CclsIni 래퍼 클래스

class CclsIni : public COleDispatchDriver
{
public:
	CclsIni(){} // COleDispatchDriver 기본 생성자를 호출합니다.
	CclsIni(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CclsIni(const CclsIni& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 특성
public:

	// 작업
public:


	// _clsIni 메서드
public:
	BOOL WriteIni(LPCTSTR sPath, LPCTSTR sSection, LPCTSTR sKey, LPCTSTR sValue)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x60030000, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, sPath, sSection, sKey, sValue);
		return result;
	}
	BOOL DeleteSection(BSTR * sSection, BSTR * sPath)
	{
		BOOL result;
		static BYTE parms[] = VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x60030001, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, sSection, sPath);
		return result;
	}
	BOOL DeleteKey(BSTR * sSection, BSTR * sKey, BSTR * sPath)
	{
		BOOL result;
		static BYTE parms[] = VTS_PBSTR VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x60030002, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, sSection, sKey, sPath);
		return result;
	}
	CString ReadIni(LPCTSTR sPath, LPCTSTR sSection, LPCTSTR sKey, LPCTSTR sDefault)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x60030003, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, sPath, sSection, sKey, sDefault);
		return result;
	}

	// _clsIni 속성
public:

};
