// ��ǻ�Ϳ��� ���� ���̺귯�� �������� [Ŭ���� �߰�]�� ����Ͽ� ������ IDispatch ���� Ŭ�����Դϴ�.

// #import "C:\\Program Files\\Dream\\DreamSub.dll" no_namespace
// CclsTable ���� Ŭ����

class CclsTable : public COleDispatchDriver
{
public:
	CclsTable(){} // COleDispatchDriver �⺻ �����ڸ� ȣ���մϴ�.
	CclsTable(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CclsTable(const CclsTable& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Ư��
public:

	// �۾�
public:


	// _clsTable �޼���
public:
	double GetLargeHeight(LPDISPATCH * oSel)
	{
		double result;
		static BYTE parms[] = VTS_PDISPATCH ;
		InvokeHelper(0x60030000, DISPATCH_METHOD, VT_R8, (void*)&result, parms, oSel);
		return result;
	}
	double GetTableRX(SAFEARRAY * * vCol, short c, double * dTol)
	{
		double result;
		static BYTE parms[] = VTS_UNKNOWN VTS_I2 VTS_PR8 ;
		InvokeHelper(0x60030001, DISPATCH_METHOD, VT_R8, (void*)&result, parms, vCol, c, dTol);
		return result;
	}
	double GetTableRY(SAFEARRAY * * vRow, short r, double * dTol)
	{
		double result;
		static BYTE parms[] = VTS_UNKNOWN VTS_I2 VTS_PR8 ;
		InvokeHelper(0x60030002, DISPATCH_METHOD, VT_R8, (void*)&result, parms, vRow, r, dTol);
		return result;
	}
	BOOL IsColLine(VARIANT * vTmpCol, VARIANT * vTmpRow, short * k, short * iSta, short * iEnd, double * dTol)
	{
		BOOL result;
		static BYTE parms[] = VTS_PVARIANT VTS_PVARIANT VTS_PI2 VTS_PI2 VTS_PI2 VTS_PR8 ;
		InvokeHelper(0x60030003, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, vTmpCol, vTmpRow, k, iSta, iEnd, dTol);
		return result;
	}
	BOOL IsRowLine(VARIANT * vTmpCol, VARIANT * vTmpRow, short * k, short * iSta, short * iEnd, double * dTol)
	{
		BOOL result;
		static BYTE parms[] = VTS_PVARIANT VTS_PVARIANT VTS_PI2 VTS_PI2 VTS_PI2 VTS_PR8 ;
		InvokeHelper(0x60030004, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, vTmpCol, vTmpRow, k, iSta, iEnd, dTol);
		return result;
	}
	short GetNextLine(SAFEARRAY * * vArr, short iNum, BOOL * bX, double * dTol)
	{
		short result;
		static BYTE parms[] = VTS_UNKNOWN VTS_I2 VTS_PBOOL VTS_PR8 ;
		InvokeHelper(0x60030005, DISPATCH_METHOD, VT_I2, (void*)&result, parms, vArr, iNum, bX, dTol);
		return result;
	}
	CString GetNumberFormat(BSTR * sText)
	{
		CString result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x60030006, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, sText);
		return result;
	}
	CString DeleteSpace(BSTR * sText)
	{
		CString result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x60030007, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, sText);
		return result;
	}
	VARIANT OneCell(BSTR * sArea, short * iRow, short * iCol)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PBSTR VTS_PI2 VTS_PI2 ;
		InvokeHelper(0x60030008, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, sArea, iRow, iCol);
		return result;
	}
	CString GetxlVertical(BSTR * sText)
	{
		CString result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x60030009, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, sText);
		return result;
	}
	CString GetMergeText(BSTR * sArea)
	{
		CString result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x6003000a, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, sArea);
		return result;
	}

	// _clsTable �Ӽ�
public:

};
