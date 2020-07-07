#include<cstdio>
#include<cstring>

void MergeTwoArry(int arry1[],int arry2[],int lengthOfArray1,int lengthOfArray2)
{
	if(arry1==nullptr || arry2==nullptr || lengthOfArray2<=0)
		return;

	int indexOfNew = lengthOfArray1 + lengthOfArray2 - 1;
	int indexOfArray1 = lengthOfArray1 - 1;
	int indexOfArray2 = lengthOfArray2 - 1;

	while( indexOfArray2>=0)
	{
		if(indexOfArray1>=0 && arry1[indexOfArray1]>arry2[indexOfArray2])
		{
			arry1[indexOfNew--] = arry1[indexOfArray1--];
		}
		else
		{
			arry1[indexOfNew--] = arry2[indexOfArray2--];
		}
	}

}
void Test1()
{
	int a1[10] = {3,5,7};
	int a2[4] = {1,2,4,8};

	MergeTwoArry(a1,a2,3,4);

	for(int i=0;i<10;i++)
		printf("%d ",a1[i]);
	printf("\n");
}

void Test2()
{
	int a1[10] = {0};
	int a2[4] = {1,2,4,8};

	MergeTwoArry(a1,a2,0,4);

	for(int i=0;i<10;i++)
		printf("%d ",a1[i]);
	printf("\n");
}

void Test3()
{
	int a1[10] = {3,5,7};

	MergeTwoArry(a1,nullptr,3,0);

	for(int i=0;i<10;i++)
		printf("%d ",a1[i]);
	printf("\n");
}


int main()
{
	Test1();
	Test2();
	Test3();
	return 0;
}
