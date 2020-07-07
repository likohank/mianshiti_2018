#include<cstdio>
#include<cstring>
#include<memory.h>

int movingCountCore(int theshold,int rows,int cols,int row,int col,bool* visited);
bool check(int theshold,int rows,int cols,int row,int col,bool* visited);
int getDim(int val);

int movingCount(int theshold,int rows,int cols)
{
	if(theshold<0 || rows<=0 || cols<=0)
		return 0;

	bool* visited = new bool[rows*cols];
	memset(visited,0,rows*cols);

	int count = movingCountCore(theshold,rows,cols,0,0,visited);

	delete visited;
	return count;
}

int movingCountCore(int theshold,int rows,int cols,int row,int col,bool* visited)
{
	int count = 0;
	if(check(theshold,rows,cols,row,col,visited))
	{
		printf("%d,%d\t\t%d\t%d\n",row,col,getDim(row)+getDim(col),theshold);

		visited[row*cols+col] = true;
		count = 1 +  movingCountCore(theshold,rows,cols,row+1,col,visited) + 
				movingCountCore(theshold,rows,cols,row-1,col,visited) + 
					movingCountCore(theshold,rows,cols,row,col+1,visited) + 
						movingCountCore(theshold,rows,cols,row,col-1,visited) ;
	}
	return count;
}

bool check(int theshold,int rows,int cols,int row,int col,bool* visited)
{
	if( row<rows && row>=0 && col<cols && col>=0 and !visited[row*cols+col] && getDim(row) + getDim(col) < theshold)
		return true;
	return false;
}

int getDim(int val)
{
	int res = 0;

	while(val>0)
	{
		res += val%10;
		val /= 10;
	}
	return res;
}

int main()
{
	printf("All match is %d!\n",movingCount(18,50,50));
	return 0;
}
