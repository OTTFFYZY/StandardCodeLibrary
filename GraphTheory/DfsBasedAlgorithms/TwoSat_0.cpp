#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MV=1e5+5;
vector<int> g[MV*2];
int nv;

// x==vx or y==vy
void add_clause(int x,int vx,int y,int vy)
{
	x=x*2+vx;
	y=y*2+vy;
	g[x^1].push_back(y);
	g[y^1].push_back(x);
}

int st[MV*2],stp;

int mark[MV*2];
bool dfs(int u)
{
	if(mark[u^1]) return 0;
	if(mark[u]) return 1;
	mark[u]=1;
	st[++stp]=0;
	for(int v:g[u])
		if(!dfs(v)) return 0;
	return 1;
}

bool solve()
{
	memset(mark,0,sizeof(mark));
	for(int i=0;i<nv*2;i+=2)
	{
		stp=0;
		if(!dfs(i))
		{
			while(stp)
				mark[st[stp--]]=0;
			if(!dfs(i+1)) return 0;
		}
	}
	return 1;
}
int main()
{

	return 0;
}