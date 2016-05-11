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

	//如果为奇数，所以还需要乘以一个base,a(n) = a^n/2 * a^n/2*a
	if (absExponent & 1 == 1)
		result *= base;

	return result;
}

//设置标志位，来判断是正常输出0，还是非错误输出0
bool g_InvalidPut = false;

double Power(double base,int exponent)
{
	g_InvalidPut = false;

	if (Equal(base, 0.0) && exponent < 0)
	{
		g_InvalidPut = true;
		return 0.0;
	}

	//全部转化成正指数求解
	unsigned int absExponent = (unsigned int)exponent;
	if (exponent < 0)
	{
		absExponent = (-exponent);
	}

	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;

}