#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MV=1e5+5;
vector<int> g[MV*2];
int nv;
int st[MV*2],stp;
int mk[MV*2];

void init()
{
	for(int i=0;i<nv*2;i++)
		g[i].clear(),mk[i]=0;
}

// x==vx
void set_value(int x,int vx)
{
	x=x*2+vx;
	g[x^1].push_back(x);
}

// x==vx or y==vy
void add_clause(int x,int vx,int y,int vy)
{
	x=x*2+vx;
	y=y*2+vy;
	g[x^1].push_back(y);
	g[y^1].push_back(x);
}
 
 
bool dfs(int u)
{
	if(mk[u^1]) return 0;
	if(mk[u]) return 1;
	mk[u]=1;
	st[++stp]=u;
	for(int v:g[u])
		if(!dfs(v)) return 0;
	return 1;
}
 
bool twoSat()
{
	//memset(mk,0,sizeof(mk));
	for(int i=0;i<nv*2;i+=2)
	{
		stp=0;
		if(!dfs(i))
		{
			while(stp)
				mk[st[stp--]]=0;
			if(!dfs(i+1)) return 0;
		}
	}
	return 1;
}
int main()
{

	return 0;
}