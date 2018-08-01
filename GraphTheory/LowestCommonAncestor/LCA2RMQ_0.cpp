#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

const int M=1e5+5;
const int MB=20;

int lg[M*2];
int st[M*2][MB];
void lg_init()
{
	lg[1]=0;
	for(int i=1;i<MB;i++)
		lg[1<<i]=1;
	for(int i=2;i<M*2;i++)
		lg[i]+=lg[i-1];
}
void rmq_init(int n)
{	
	for(int j=1;(1<<j)<n;j++)
		for(int i=0;i+(1<<j)<n;i++)
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int rmq_min(int l,int r)
{
	int j=lg[r-l+1];
	return min(st[l][j],st[r-(1<<j)+1][j]);
}

vector<int> g[M];
int nv,cdfn,dfn;
int df2v[M],pos[M];
void dfs(int u,int fa)
{
	df2v[dfn]=u;
	pos[u]=cdfn;
	int ndfn=st[cdfn++][1]=dfn++;
	for(int v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		st[cdfn++][1]=ndfn;
	}
}
void lca2rmq()
{
	cdfn=dfn=0;
	dfs(0,-1);
	rmq_init(cdfn);
}
int lca(int a,int b)
{
	return df2v[rmq_min(pos[a],pos[b])];
}

int main()
{
	return 0;
}