#include<cstdio>

void FindContinuousSequence(int sum)
{
	if(sum<3)
		return;
	int behind = 1;
	int ahead = 2;
	int middle = sum/2;
	int curSum = behind + ahead;

	while(behind<=middle)
	{
		if(curSum==sum)
		{
			printf("%d~%d\n",behind,ahead);
			curSum -= behind;
			behind++;
		}
		else if(curSum>sum)
		{
			curSum -= behind;
			behind++;
		}
		else
		{
			ahead++;
			curSum += ahead;
		}
	}
}

int main()
{
	FindContinuousSequence(15);
}
