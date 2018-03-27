#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

const int M=1e3+5;
int g[M][M]; //numbers or weights of edge

void init()
{
	memset(g,0,sizeof(g));
}
void addedge(int fr,int to) //directed
{
	g[fr][to]++;
}
void addedge(int fr,int to,int w) //directed
{
	g[fr][to]=w;
}
void addedge2(int a,int b) //undirected
{
	g[a][b]=g[b][a]=1;
}
bool have_selfloop(int a)
{
	return g[a][a];
}
bool have_edge(int a,int b)
{
	return g[a][b];
}

int main()
{
	init();
	//traverse u's adjacent vertices
	int u=0;
	for(int i=0;i<M;i++)
	{
		if(g[u][i]) i;
	}
	return 0;
}