#include <iostream>
#include <vector>
using namespace std;

const int M=1e5+5;
vector<int> g[M];
int nv;
int d[M];
int maxl;

void max2(int &a,int &b,int c)
{
	if(a>b)
		if(b<c) b=c;
	else
		if(a<c) a=c;
}

void dfs(int u,int fa)
{
	int maxd=0,max2d=0;
	for(int v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		max2(maxd,max2d,d[v]);
	}
	maxl=max(maxl,maxd+max2d+1);
	d[u]=max(maxd,max2d)+1;
}

int longestPathOfTree()
{
	maxl=0;
	dfs(0,-1);
	return maxl;
}

int main()
{
	return 0;
}