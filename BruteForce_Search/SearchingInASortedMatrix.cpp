#include <stdio.h>
#include <iostream>

using namespace std;

const int M=1e3+5;
int matrix[M][M]; //sorted by row and column

pair<int,int> find(int n,int m,int key)
{
	int i=0,j=m-1;
	while(i<n&&j>=0)
	{
		if(matrix[i][j]==key)
			return make_pair(i,j);
		else if(matrix[i][j]<key) i++;
		else j--; //matrix[i][j]>key
	}
	return make_pair(-1,-1);
}


int main()
{

	return 0;
}