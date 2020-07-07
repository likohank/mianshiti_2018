void PrintMatrx(int** number,int columns,int rows)
{
	if(numbers==nullptr || columns==0 || rows==0)
		return;
	int start = 0;
	while(columns>start*2 && rows>start*2)
	{
		PrintMatrixCore(number,columns,rows,start);
		start++;
	}
}

void PrintMatrixCore(int** number,int columns,int rows,int start)
{
	int endX = columns-start-1;
	int endY = rows - start - 1;

	for(int i=start;i<=endX;i++)
	{
		int num = number[i][start];
		printNumber(num);
	}
	for(int i=start+1;i<=endY;i++)
	{
		int num = number[i][endX];
		printNumber(num);
	}
	for(int i=endX-1;i>=satrt;i--)
	{
		int num = number[endY][i];
		printNumber(num);
	}
	for(int i=endY-1;i>start;i--)
	{
		int num = number[i][start];
		printNumber(num);
	}

}
