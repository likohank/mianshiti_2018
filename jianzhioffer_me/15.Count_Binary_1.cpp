#include <cstdio>
#include <cstring>

#include <bitset>
#include <iostream>
using namespace std;

int NumberOf1(int n)
{
	int count = 0;
	unsigned int flag = 1;

	while(flag)
	{
		if(n&flag)
			count++;
		flag =  flag<<1;
	}
	return count;
}

int NumberOf1_2(int n)
{
	int count = 0;
	while(n)
	{
		n = n&(n-1);
		count++;
	}
	return count;
}

int main()
{
	std::cout<<"bit: "<< std::bitset<sizeof(int)*8>(-3) <<std::endl;
	std::bitset<sizeof(int)*8> t1(-3);
	printf("t1 1 count:%d\n",t1.count());

	printf("%d\n",NumberOf1_2(-3));
	return 0;
}
