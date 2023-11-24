// ��ǻ�Ϳ��� ���� ���̺귯�� �������� [Ŭ���� �߰�]�� ����Ͽ� ������ IDispatch ���� Ŭ�����Դϴ�.

// #import "C:\\Program Files\\Dream\\DreamSub.dll" no_namespace
// CclsIni ���� Ŭ����

class CclsIni : public COleDispatchDriver
{
public:
	CclsIni(){} // COleDispatchDriver �⺻ �����ڸ� ȣ���մϴ�.
	CclsIni(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CclsIni(const CclsIni& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Ư��
public:

	// �۾�
public:


	// _clsIni �޼���
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

	// _clsIni �Ӽ�
public:

};
