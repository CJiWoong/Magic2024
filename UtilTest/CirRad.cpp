#include "stdafx.h"
#include <math.h>

#define PI (atan(1.0) * 4.0)
#define PI2 (atan(1.0) * 2.0)

// �� p1�� p2�� ���� ���
double Get2PtsAng(double p1x, double p1y, double p2x, double p2y)
{
	double ang;
	double x, y;

	x = p2x - p1x;
	y = p2y - p1y;

	if (x == 0.0) { // ������
		if (y == 0.0) // ��
			ang = 0.0;
		else if (y > 0.0) // +Y (90)
			ang = PI2;
		else // -Y (270)
			ang = PI + PI2;
	}
	else {
		ang = atan (y / x);
		if (x < 0.0) // 90 ~ 270
			ang += PI;
		else if (y < 0.0) // 180 ~ 360
			ang += PI * 2;
	}

	return ang;
}

// 3���� ������ ���� ������ ���
double Get3PtsRad(double p1x, double p1y, double p2x, double p2y, double p3x, double p3y)
{
	double v1x, v1y, v1a;
	double v2x, v2y, v2a;
	double v3x, v3y, v3a;
	double v4x, v4y;
	double cx, cy;
	double rad;

	// �� p1, p2�� �����̵�м� ��� => v1
	v1x = (p1x + p2x) / 2.0;
	v1y = (p1y + p2y) / 2.0;
	v1a = Get2PtsAng(p1x, p1y, p2x, p2y) + PI2;
	if (v1a > (PI * 2))
		v1a -= PI * 2;

	// �� p2, p3�� �����̵�м� ��� => v2
	v2x = (p2x + p3x) / 2.0;
	v2y = (p2y + p3y) / 2.0;
	v2a = Get2PtsAng(p2x, p2y, p3x, p3y) + PI2;
	if (v2a > (PI * 2))
		v2a -= PI * 2;

	// ����� v1, v2 ���� �������� Ȯ��
	if (v1a == v2a)
		return 0.0; // 3���� �������� ����

	// v1�� v2�� ������ ���� ����ϱ� ���� v2�� x���� �ǵ��� v1�� ȸ����Ŵ
	v3x = cos(-v2a) * (v1x - v2x) - sin(-v2a) * (v1y - v2y);
	v3y = sin(-v2a) * (v1x - v2x) + cos(-v2a) * (v1y - v2y);
	v3a = v2a - v1a;

	// ȸ���� v1�� x��� ������ �� ��� (v1�� v2�� ������)
	v4x = v3y / tan(v3a) + v3x;
	v4y = 0.0;

	// ���� �������� ������ ȸ�� => ���� �߽�
	cx = cos(v2a) * v4x - sin(v2a) * v4y + v2x;
	cy = sin(v2a) * v4x + cos(v2a) * v4y + v2y;

	// ������ ���
	rad = sqrt((cx - p1x) * (cx - p1x) + (cy - p1y) * (cy - p1y));

	return rad;
}

void TestFunc()
{
	double p1x, p1y, p2x, p2y, p3x, p3y;
	double rad;

	p1x = 2399.29; p1y = 2238.16;
	p2x = 2431.29; p2y = 2171.13;
	p3x = 2488.68; p3y = 2145.19;

	rad = Get3PtsRad(p1x, p1y, p2x, p2y, p3x, p3y);

	p1x = 0.0; p1y = 0.0;
	p2x = 200.0; p2y = 100.0;
	p3x = 400.0; p3y = 200.0;

	rad = Get3PtsRad(p1x, p1y, p2x, p2y, p3x, p3y);
}
