// 컴퓨터에서 형식 라이브러리 마법사의 [클래스 추가]를 사용하여 생성한 IDispatch 래퍼 클래스입니다.

// #import "C:\\Program Files\\Dream\\DreamSub.dll" no_namespace
// CclsCLO 래퍼 클래스

class CclsCLO : public COleDispatchDriver
{
public:
	CclsCLO(){} // COleDispatchDriver 기본 생성자를 호출합니다.
	CclsCLO(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CclsCLO(const CclsCLO& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 특성
public:

	// 작업
public:


	// _clsCLO 메서드
public:
	double GetClothoidA(double * dblR, double * dblL)
	{
		double result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030000, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dblR, dblL);
		return result;
	}
	double GetTL(double * dblIA, double * dblR)
	{
		double result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030001, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dblIA, dblR);
		return result;
	}
	double GetCL(double * dblIA, double * dblR)
	{
		double result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030002, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dblIA, dblR);
		return result;
	}
	double GetClothoidL(double * dblA, double * dblR)
	{
		double result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030003, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dblA, dblR);
		return result;
	}
	double GetClothoidX(double * dblL, double * dblR)
	{
		double result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030004, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dblL, dblR);
		return result;
	}
	double GetClothoidY(double * dblL, double * dblR)
	{
		double result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030005, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dblL, dblR);
		return result;
	}
	double GetClothoidT(double * dblL, double * dblR)
	{
		double result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030006, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dblL, dblR);
		return result;
	}
	double GetClothoidXM(double * dblX, double * dblR, double * dblT)
	{
		double result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030007, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dblX, dblR, dblT);
		return result;
	}
	double GetClothoidDR(double * dblY, double * dblR, double * dblT)
	{
		double result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030008, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dblY, dblR, dblT);
		return result;
	}
	double GetClothoidW(double * dblR, double * dblDR, double * dblIA)
	{
		double result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030009, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dblR, dblDR, dblIA);
		return result;
	}
	double GetClothoidZ(double * dblDR2, double * dblDR1, double * dblIA, short * iClass)
	{
		double result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PR8 VTS_PI2 ;
		InvokeHelper(0x6003000a, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dblDR2, dblDR1, dblIA, iClass);
		return result;
	}
	double GetClothoidLC(double * dblR, double * dblIA, double * dblT1, double * dblT2)
	{
		double result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x6003000b, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dblR, dblIA, dblT1, dblT2);
		return result;
	}
	double GetClothoidD(double * dblXM, double * dblW, double * dblZ, short * iClass)
	{
		double result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PR8 VTS_PI2 ;
		InvokeHelper(0x6003000c, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dblXM, dblW, dblZ, iClass);
		return result;
	}
	double GetClothoidAE(double * dR1, double * dR2, double * dM1M2, double * dA)
	{
		double result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x6003000d, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dR1, dR2, dM1M2, dA);
		return result;
	}
	double GetClothoidADE(double * dblR1, double * dblR2, double * dA)
	{
		double result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x6003000e, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dblR1, dblR2, dA);
		return result;
	}
	double GetClothoidADER(double * dblR1, double * dblR2, double * dA, double * dRatio)
	{
		double result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x6003000f, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dblR1, dblR2, dA, dRatio);
		return result;
	}
	VARIANT GetDistBetweenRDE(double * dblR1, double * dblR2, double * dblDR1, double * dblDR2, double * dXMR1, double * dXMR2)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PR8 VTS_PR8 VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030010, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblR1, dblR2, dblDR1, dblDR2, dXMR1, dXMR2);
		return result;
	}
	double GetClothoidAS(double * dblR1, double * dblR2, double * dA)
	{
		double result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030011, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dblR1, dblR2, dA);
		return result;
	}
	double GetClothoidASR(double * dblR1, double * dblR2, double * dA, double * dRatio)
	{
		double result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030012, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dblR1, dblR2, dA, dRatio);
		return result;
	}
	VARIANT GetDistBetweenRS(double * dblR1, double * dblR2, double * dblDR1, double * dblDR2, double * dXMR1, double * dXMR2)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PR8 VTS_PR8 VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030013, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblR1, dblR2, dblDR1, dblDR2, dXMR1, dXMR2);
		return result;
	}
	VARIANT GetGoalSeek(double * dRad1, double * dRad2, double * dM1M2, VARIANT * vInit, VARIANT * vTarget, VARIANT * vGuess, VARIANT * vAccuracy, VARIANT * bPositive)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PR8 VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x60030014, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dRad1, dRad2, dM1M2, vInit, vTarget, vGuess, vAccuracy, bPositive);
		return result;
	}
	VARIANT GetGoalSeekDE(double * dRad1, double * dRad2, VARIANT * vInit, VARIANT * vTarget, VARIANT * vGuess, VARIANT * vAccuracy, VARIANT * bPositive, double * dRatio)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PR8 ;
		InvokeHelper(0x60030015, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dRad1, dRad2, vInit, vTarget, vGuess, vAccuracy, bPositive, dRatio);
		return result;
	}
	VARIANT GetGoalSeekS(double * dRad1, double * dRad2, VARIANT * vInit, VARIANT * vTarget, VARIANT * vGuess, VARIANT * vAccuracy, VARIANT * bPositive, double * dRatio)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PR8 ;
		InvokeHelper(0x60030016, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dRad1, dRad2, vInit, vTarget, vGuess, vAccuracy, bPositive, dRatio);
		return result;
	}
	double FindDR(double * dblR, double * dblL)
	{
		double result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x60030017, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dblR, dblL);
		return result;
	}
	VARIANT FindA(VARIANT * dRad, VARIANT * vInit, VARIANT * vResult, VARIANT * vTarget, VARIANT * vGuess, VARIANT * vAccuracy, VARIANT * bPositive)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x60030018, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dRad, vInit, vResult, vTarget, vGuess, vAccuracy, bPositive);
		return result;
	}
	VARIANT FindAN(VARIANT * dRad, VARIANT * dIA, VARIANT * dN, VARIANT * vInit, VARIANT * vTarget, VARIANT * vGuess, VARIANT * vAccuracy, VARIANT * bPositive)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x60030019, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dRad, dIA, dN, vInit, vTarget, vGuess, vAccuracy, bPositive);
		return result;
	}
	double FindDRCalc(VARIANT * dRad, VARIANT * vValue)
	{
		double result;
		static BYTE parms[] = VTS_PVARIANT VTS_PVARIANT ;
		InvokeHelper(0x6003001a, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dRad, vValue);
		return result;
	}
	VARIANT GetClothoidE1(double * dblXM1, double * dblXM2, double * dblR1, double * dblR2, double * dblDR1, double * dblDR2, double * dblT1)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PR8 VTS_PR8 VTS_PR8 VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x6003001b, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblXM1, dblXM2, dblR1, dblR2, dblDR1, dblDR2, dblT1);
		return result;
	}
	VARIANT GetClothoidE(double * dblXM1, double * dblXM2, double * dblR1, double * dblR2, double * dblDR1, double * dblDR2)
	{
		VARIANT result;
		static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PR8 VTS_PR8 VTS_PR8 VTS_PR8 ;
		InvokeHelper(0x6003001c, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, dblXM1, dblXM2, dblR1, dblR2, dblDR1, dblDR2);
		return result;
	}
	double GetFactorial(short * iValue)
	{
		double result;
		static BYTE parms[] = VTS_PI2 ;
		InvokeHelper(0x6003001d, DISPATCH_METHOD, VT_R8, (void*)&result, parms, iValue);
		return result;
	}

	// _clsCLO 속성
public:

};
