#include<iostream>
using namespace std;

class Temp
{
public:
	Temp()
	{
		N++;
		Sum+=N;
	}
	static int GetSum()
	{
		return Sum;
	}
	static void Reset()
	{
		N = 0;
		Sum = 0;
	}
private:
	static int N ;
	static int Sum ;
	//static const char* temp = "hello";
	static const int vecSize = 20;
	constexpr static char* aa = nullptr;
};

int Temp::N=0;
int Temp::Sum = 0;

int main()
{
	Temp::Reset();
	Temp* tt = new Temp[5];
	cout<<Temp::GetSum()<<endl;
	return 0;
}



///////////////////////////////////////////////////
//solution 2

class A;
A* Array[2];

class A
{
public:
	virtual int sum(int n)
	{
		return 0;
	}
};

class B: public A
{
public:
	int sum(int n)
	{
		return Array[!!n]->sum(n-1) + n;
	}
};

int main()
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;
	int n = 10;

	return Array[1]->sum(n);
}


//////////////////////////
//function ptr
//
typedef unsigned int (*func)(unsigned int n);
static func f[2] = {func1,func2};

unsigned int func1(unsigned int n)
{
	return 0;
}

unsigned int func2(unsigned int n)
{
	return f[!!n](n-1)+n;
}
