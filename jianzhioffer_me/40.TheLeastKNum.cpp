//Solution 1  ,o(n)
void GetLeastNumbers(int* input,int n,int* output,int k)
{
	if(input==nullptr || output==nullptr || n<=0 || k<=0 || k>n)
		return;

	int start = 0;
	int end = n-1;
	int index = Partition(input,n,start,end);

	while(index != k-1)
	{
		if(index>k-1)
		{
			end = index-1;
			Partition(input,n,start,end);
		}
		else
		{
			start = index+1;
			index = Partition(input,n,start,end);
		}
	}
	for(int i=0;i<k;i++)
	{
		*(output+i) = *(input+i);
	}
}

//Solution 2
//

typedef multiset<int,greater<int>> inSet;
typedef multiset<int,greater<int>>::iterator setIterator;

void GetLeastNumbers(const vector<int>& data,intSet& leastNumbers,it k )
{
	leastNumbers.clear();

	if(k<1 || data.size()==0)
		return;

	vector<int>::const_iterator iter=data.begin();
	for(;iter!=data.end();iter++)
	{
		if(leastNumbers.size()<k)
			leastNumbers.insert(*iter);
		else
		{
			setIterator iterGreatest = leaseNumbers.begin();
			if(*iter<*(leastNumbers.begin()))
			{
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(*iter);
			}
		}
	}
}
