#include <iostream>
using namespace std;

bool Equal(double num1, double num2)
{
	if (num1 - num2 > -0.0000001 && num1 - num2 < 0.0000001)
	{
		return true;
	}

	return false;
}

double PowerWithUnsignedExponent(double base, unsigned int absExponent)
{
	if (absExponent == 0)
		return 1;
	if (absExponent == 1)
		return base;

	double result = PowerWithUnsignedExponent(base, absExponent>>1);//a(n) = a^n/2 * a^n/2
	result *= result;

	//���Ϊ���������Ի���Ҫ����һ��base,a(n) = a^n/2 * a^n/2*a
	if (absExponent & 1 == 1)
		result *= base;

	return result;
}

//���ñ�־λ�����ж����������0�����ǷǴ������0
bool g_InvalidPut = false;

double Power(double base,int exponent)
{
	g_InvalidPut = false;

	if (Equal(base, 0.0) && exponent < 0)
	{
		g_InvalidPut = true;
		return 0.0;
	}

	//ȫ��ת������ָ�����
	unsigned int absExponent = (unsigned int)exponent;
	if (exponent < 0)
	{
		absExponent = (-exponent);
	}

	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;

}