// ��ǻ�Ϳ��� ���� ���̺귯�� �������� [Ŭ���� �߰�]�� ����Ͽ� ������ IDispatch ���� Ŭ�����Դϴ�.

// #import "C:\\Program Files\\Dream\\DreamSub.dll" no_namespace
// CclsTriangle ���� Ŭ����

class CclsTriangle : public COleDispatchDriver
{
public:
	CclsTriangle(){} // COleDispatchDriver �⺻ �����ڸ� ȣ���մϴ�.
	CclsTriangle(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CclsTriangle(const CclsTriangle& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Ư��
public:

	// �۾�
public:


	// _clsTriangle �޼���
public:
	VARIANT ArcSin(double * dblX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 ;
		InvokeHelper(0x60030000, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX);
		return result;
	}
	VARIANT Sec(double * dblX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 ;
		InvokeHelper(0x60030001, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX);
		return result;
	}
	VARIANT Cosec(double * dblX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 ;
		InvokeHelper(0x60030002, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX);
		return result;
	}
	VARIANT Cotan(double * dblX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 ;
		InvokeHelper(0x60030003, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX);
		return result;
	}
	VARIANT ArcCos(double * dblX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 ;
		InvokeHelper(0x60030004, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX);
		return result;
	}
	VARIANT ArcSec(double * dblX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 ;
		InvokeHelper(0x60030005, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX);
		return result;
	}
	VARIANT ArcCosec(double * dblX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 ;
		InvokeHelper(0x60030006, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX);
		return result;
	}
	VARIANT ArcCotan(double * dblX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 ;
		InvokeHelper(0x60030007, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX);
		return result;
	}
	VARIANT HSin(double * dblX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 ;
		InvokeHelper(0x60030008, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX);
		return result;
	}
	VARIANT HCos(double * dblX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 ;
		InvokeHelper(0x60030009, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX);
		return result;
	}
	VARIANT HTan(double * dblX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 ;
		InvokeHelper(0x6003000a, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX);
		return result;
	}
	VARIANT HSec(double * dblX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 ;
		InvokeHelper(0x6003000b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX);
		return result;
	}
	VARIANT HCosec(double * dblX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 ;
		InvokeHelper(0x6003000c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX);
		return result;
	}
	VARIANT HCotan(double * dblX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 ;
		InvokeHelper(0x6003000d, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX);
		return result;
	}
	VARIANT HArcSin(double * dblX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 ;
		InvokeHelper(0x6003000e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX);
		return result;
	}
	VARIANT HArcCos(double * dblX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 ;
		InvokeHelper(0x6003000f, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX);
		return result;
	}
	VARIANT HArcTan(double * dblX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 ;
		InvokeHelper(0x60030010, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX);
		return result;
	}
	VARIANT HArcSec(double * dblX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 ;
		InvokeHelper(0x60030011, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX);
		return result;
	}
	VARIANT HArcCosec(double * dblX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 ;
		InvokeHelper(0x60030012, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX);
		return result;
	}
	VARIANT HArcCotan(double * dblX)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 ;
		InvokeHelper(0x60030013, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX);
		return result;
	}
	VARIANT LogN(double * dblX, double * dblN)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030014, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblX, dblN);
		return result;
	}

	// _clsTriangle �Ӽ�
public:

};
