#include<cstdio>

//剑指offer 的方式
int Partition(int data[],int length,int start,int end)
{
	if(data==nullptr || lenght<=0 || start<0 || end>=lenght)
		throw std::exception("Invalid Parameters");

	int index = RandomInRange(start,end);
	Swap(&data[index],&data[end]);

	int small = start -1;
	for (index = start ; index<end ; index++)
	{
		if(data[index]<data[end])
		{
			small++;
			if(small!=index)
				Swap(&data[small],&data[index]);
		}
	}
	++small;
	Swap(&data[small],&data[end]);
	return small;
}

void QuicSort(int data[],int length,int start = 0,int end = length-1)
{
	if(start == end)
		return;

	int index = Partition(data,length,start,end);

	if(index>start)
		QuicSort(data,length,start,index-1);
	if(index<end)
		QuicSort(data,length,index+1,end);
}


//百度百科的方式
//
//

void Qsort(int a[],int low,int high)
{
	if(low>=high)
		return;

	int first = low;
	int last = high;
	int key = a[first];  // 永第一个元素作为参照数字

	while(first<last)
	{
		while(first<last && a[last]>=key)
			--last;
		a[first] = a[last];

		while(first<last && a[first]<=key)
			++first;
		a[last] = a[first];
	}

	a[first] = key;
	Qsort(a,low,first-1);
	Qsort(a,first+1 ,high);
}

int main()
{
	int a[] = {5,1,7,4,8,9,2,3,10,6};
	Qsort(a,0,sizeof(a)/sizeof(a[0]) - 1);

	for (int i=0;i<sizeof(a)/sizeof(a[0]); i++)
	{
		cout<< a[i] << "";
	}
	return 0;
}



