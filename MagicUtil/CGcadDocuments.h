// 컴퓨터에서 형식 라이브러리 마법사의 [클래스 추가]를 사용하여 생성한 IDispatch 래퍼 클래스입니다.

//#import "D:\\PROJECTS\\GRXSDK8\\inc\\GCADVba.tlb" no_namespace
// CGcadDocuments 래퍼 클래스

class CGcadDocuments : public COleDispatchDriver
{
public:
	CGcadDocuments(){} // COleDispatchDriver 기본 생성자를 호출합니다.
	CGcadDocuments(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CGcadDocuments(const CGcadDocuments& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 특성
public:

	// 작업
public:


	// IGcadDocuments 메서드
public:
	LPDISPATCH Item(VARIANT& Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x0, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, &Index);
		return result;
	}
	LPUNKNOWN get__NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	long get_Count()
	{
		long result;
		InvokeHelper(0x60020002, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020003, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH Add(VARIANT& TemplateName)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x60020004, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, &TemplateName);
		return result;
	}
	LPDISPATCH Open(LPCTSTR Name, VARIANT& ReadOnly, VARIANT& Password)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x60020005, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Name, &ReadOnly, &Password);
		return result;
	}
	void Close()
	{
		InvokeHelper(0x60020006, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// IGcadDocuments 속성
public:

};
