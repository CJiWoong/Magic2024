// ��ǻ�Ϳ��� ���� ���̺귯�� �������� [Ŭ���� �߰�]�� ����Ͽ� ������ IDispatch ���� Ŭ�����Դϴ�.

// #import "C:\\Program Files\\Dream\\DreamSub.dll" no_namespace
// CclsExcelFile ���� Ŭ����

class CclsExcelFile : public COleDispatchDriver
{
public:
	CclsExcelFile(){} // COleDispatchDriver �⺻ �����ڸ� ȣ���մϴ�.
	CclsExcelFile(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CclsExcelFile(const CclsExcelFile& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Ư��
public:

	// �۾�
public:


	// _clsExcelFile �޼���
public:
	short CreateFile(LPCTSTR FileName)
	{
		short result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x60030002, DISPATCH_METHOD, VT_I2, (void*)&result, parms, FileName);
		return result;
	}
	short CloseFile()
	{
		short result;
		InvokeHelper(0x60030003, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	short InsertHorizPageBreak(long * lRow)
	{
		short result;
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x60030005, DISPATCH_METHOD, VT_I2, (void*)&result, parms, lRow);
		return result;
	}
	short WriteValue(long * ValueType, long * CellFontUsed, long * Alignment, long * HiddenLocked, long * lRow, long * lCol, VARIANT * value, long * CellFormat)
	{
		short result;
		static BYTE parms[] = VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PVARIANT VTS_PI4 ;
		InvokeHelper(0x60030006, DISPATCH_METHOD, VT_I2, (void*)&result, parms, ValueType, CellFontUsed, Alignment, HiddenLocked, lRow, lCol, value, CellFormat);
		return result;
	}
	short SetMargin(long * Margin, double * MarginValue)
	{
		short result;
		static BYTE parms[] = VTS_PI4 VTS_PR8 ;
		InvokeHelper(0x60030007, DISPATCH_METHOD, VT_I2, (void*)&result, parms, Margin, MarginValue);
		return result;
	}
	VARIANT SetColumnWidth(unsigned char * FirstColumn, unsigned char * LastColumn, short * WidthValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PUI1 VTS_PUI1 VTS_PI2 ;
		InvokeHelper(0x60030008, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, FirstColumn, LastColumn, WidthValue);
		return result;
	}
	short SetFont(BSTR * FontName, short * FontHeight, long * FontFormat)
	{
		short result;
		static BYTE parms[] = VTS_PBSTR VTS_PI2 VTS_PI4 ;
		InvokeHelper(0x60030009, DISPATCH_METHOD, VT_I2, (void*)&result, parms, FontName, FontHeight, FontFormat);
		return result;
	}
	short SetHeader(BSTR * HeaderText)
	{
		short result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x6003000a, DISPATCH_METHOD, VT_I2, (void*)&result, parms, HeaderText);
		return result;
	}
	short SetFooter(BSTR * FooterText)
	{
		short result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x6003000b, DISPATCH_METHOD, VT_I2, (void*)&result, parms, FooterText);
		return result;
	}
	short SetFilePassword(BSTR * PasswordText)
	{
		short result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x6003000c, DISPATCH_METHOD, VT_I2, (void*)&result, parms, PasswordText);
		return result;
	}
	void put_PrintGridLines(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x68030001, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void put_ProtectSpreadsheet(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x68030000, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	short WriteDefaultFormats()
	{
		short result;
		InvokeHelper(0x6003000d, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
		return result;
	}
	CString MKI(short * x)
	{
		CString result;
		static BYTE parms[] = VTS_PI2 ;
		InvokeHelper(0x6003000e, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, x);
		return result;
	}
	VARIANT SetDefaultRowHeight(short * HeightValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PI2 ;
		InvokeHelper(0x6003000f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, HeightValue);
		return result;
	}
	VARIANT SetRowHeight(long * lRow, short * HeightValue)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PI4 VTS_PI2 ;
		InvokeHelper(0x60030010, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, lRow, HeightValue);
		return result;
	}

	// _clsExcelFile �Ӽ�
public:

};
