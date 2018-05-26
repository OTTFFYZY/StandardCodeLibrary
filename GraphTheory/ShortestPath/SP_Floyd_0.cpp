#include <iostream>
#include <stdio.h>
using namespace std;

const int M=305;
int g[M][M];

void floyd(int n)
{
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

int main()
{
	return 0;
}