// 컴퓨터에서 형식 라이브러리 마법사의 [클래스 추가]를 사용하여 생성한 IDispatch 래퍼 클래스입니다.

//#import "D:\\PROJECTS\\GRXSDK8\\inc\\GCADVba.tlb" no_namespace
// CGcadPlot 래퍼 클래스

class CGcadPlot : public COleDispatchDriver
{
public:
	CGcadPlot(){} // COleDispatchDriver 기본 생성자를 호출합니다.
	CGcadPlot(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CGcadPlot(const CGcadPlot& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 특성
public:

	// 작업
public:


	// IGcadPlot 메서드
public:
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020000, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	BOOL get_QuietErrorMode()
	{
		BOOL result;
		InvokeHelper(0x60020001, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_QuietErrorMode(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x60020001, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_NumberOfCopies()
	{
		long result;
		InvokeHelper(0x60020003, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_NumberOfCopies(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x60020003, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_BatchPlotProgress()
	{
		BOOL result;
		InvokeHelper(0x60020005, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_BatchPlotProgress(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x60020005, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void DisplayPlotPreview(long Preview)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x60020007, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Preview);
	}
	BOOL PlotToFile(LPCTSTR plotFile, VARIANT& plotConfig)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_VARIANT ;
		InvokeHelper(0x60020008, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, plotFile, &plotConfig);
		return result;
	}
	BOOL PlotToDevice(VARIANT& plotConfig)
	{
		BOOL result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x60020009, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, &plotConfig);
		return result;
	}
	void SetLayoutsToPlot(VARIANT& layoutList)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x6002000a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &layoutList);
	}
	void StartBatchMode(long entryCount)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x6002000b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, entryCount);
	}

	// IGcadPlot 속성
public:

};
