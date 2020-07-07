#include<cstdio>

bool g_InvalidInput = false;

double Power(double base,int exponent)
{
	g_InvalidInput = false;
	if(equal(base,0.0) && exponent<=0)
	{
		g_InvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = (unsigned int) exponent;
	if (exponent<0)
		absExponent =  (unsigned int)(-exponent);

	double result = PowerWithUnsignedExponent(base,absExponent);
	if(exponent<0)
		result = 1.0/result;
	return result;
}

double PowerWithUnsignedExponent(double base,unsigned int absExponent)
{
	double result = 1.0;
	for (int i=1;i<=absExponent,i++)
		result *= base;
	return base;
}


double PowerWithUnsignedExponent(double base,unsigned int exponent)
{
	if(exponent==0)
		return 1;
	if(exponent==1)
		return base;

	double result = PowerWithUnsignedExponent(base,exponent>>1);
	result *= result;
	if(exponent&0x1)
		result *= base;

	return result;
}

int main()
{
	int t= -1;
	printf("%d\n");
	return 0;
}
