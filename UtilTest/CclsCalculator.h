// ��ǻ�Ϳ��� ���� ���̺귯�� �������� [Ŭ���� �߰�]�� ����Ͽ� ������ IDispatch ���� Ŭ�����Դϴ�.

// #import "C:\\Program Files\\Dream\\DreamSub.dll" no_namespace
// CclsCalculator ���� Ŭ����

class CclsCalculator : public COleDispatchDriver
{
public:
	CclsCalculator(){} // COleDispatchDriver �⺻ �����ڸ� ȣ���մϴ�.
	CclsCalculator(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CclsCalculator(const CclsCalculator& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Ư��
public:

	// �۾�
public:


	// _clsCalculator �޼���
public:
	CString Txt_Calculate(LPCTSTR sInput)
	{
		CString result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60030000, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, sInput);
		return result;
	}

	// _clsCalculator �Ӽ�
public:

};
