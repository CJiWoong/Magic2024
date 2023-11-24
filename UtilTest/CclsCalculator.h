// 컴퓨터에서 형식 라이브러리 마법사의 [클래스 추가]를 사용하여 생성한 IDispatch 래퍼 클래스입니다.

// #import "C:\\Program Files\\Dream\\DreamSub.dll" no_namespace
// CclsCalculator 래퍼 클래스

class CclsCalculator : public COleDispatchDriver
{
public:
	CclsCalculator(){} // COleDispatchDriver 기본 생성자를 호출합니다.
	CclsCalculator(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CclsCalculator(const CclsCalculator& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 특성
public:

	// 작업
public:


	// _clsCalculator 메서드
public:
	CString Txt_Calculate(LPCTSTR sInput)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60030000, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, sInput);
		return result;
	}

	// _clsCalculator 속성
public:

};
