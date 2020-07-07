#include <cstdio>
#include <cstring>

bool Find(int matrix[][4],int rows,int columns,int number)
{
	bool isFound = false;

	if(matrix==nullptr || rows<1 || columns<1)
		return false;

	int row = 0 ;
	int column = columns-1;
	while(row<rows && column>=0)
	{
		if(matrix[row][column] == number)
		{
			isFound = true;
			break;
		}
		else if(matrix[row][column]>number)
			--column;
		else
			++row;
	}

	return isFound;
}

int main()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};

	bool flag = Find(matrix,4,4,5);
	printf("%s\n", flag?"true":"false");

	int aa[] = {1,2,3,4};
	int (&r)[4] =aa;
	r[2] = 0;
	printf("%d\n",aa[2]);

	const int (&bb)[] = {1,2,3,4};
	printf("%d\n",bb[3]);

	return 0;
}
