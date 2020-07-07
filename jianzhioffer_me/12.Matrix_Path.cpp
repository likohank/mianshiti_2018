#include<cstdio>
#include<memory.h>

bool hasPathCore(char* matrix,int rows,int cols,int row,int col,const char* str,int& pathLength,bool* visited);

bool hasPath(char* matrix,int rows,int cols,char* str)
{
	if(matrix==nullptr || rows<1 || cols<1 || str==nullptr)
		return false;

	bool* visited = new bool[rows*cols];
	memset(visited,0,rows*cols);

	int pathLength = 0;
	for (int row=0;row<rows;++row)
	{
		for(int col=0;col<cols;++col)
		{
			printf("-------------%d\t%d\t%c\n",row,col,matrix[row*col+col]);
			if(hasPathCore(matrix,rows,cols,row,col,str,pathLength,visited))
			{
				return true;
			}
		}
	}
	delete visited;
	return false;
}

bool hasPathCore(char* matrix,int rows,int cols,int row,int col,const char* str,int&  pathLength,bool* visited)
{
	printf("%d\n",pathLength);
	if(str[pathLength] == '\0')
	{
		printf("----over\n");
		return true;
	}

	bool hasPath = false;
	if(row>=0 && row<rows && col>=0 && col<cols && (matrix[row*cols+col]==str[pathLength]) && visited[row*cols+col]==false )
	{
		++pathLength;
		visited[row*cols+col] = true;

		printf("%c\t is right\n",matrix[row*cols+col]);

		if( hasPathCore(matrix,rows,cols,row+1,col,str,pathLength,visited) || 
			hasPathCore(matrix,rows,cols,row-1,col,str,pathLength,visited) ||
				hasPathCore(matrix,rows,cols,row,col+1,str,pathLength,visited) ||
					hasPathCore(matrix,rows,cols,row,col-1,str,pathLength,visited) )
		{
			return true;
		}

		if(!hasPath)
		{
			--pathLength;
			visited[row*col+col] = false;
		}

	}
	return hasPath;
}

int main()
{
	char matrix[3][4]	= {{'a','b','t','g'},{'c','f','c','s'},{'j','d','e','h'}};
	char *path 		= "bfce";
	bool flag 		= hasPath((char*)matrix,3,4,path);
	printf("%d\n",flag);

	return 0;

}


