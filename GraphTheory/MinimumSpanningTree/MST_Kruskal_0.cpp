#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MV=1e5+5;
const int ME=1e5+5;
struct Edge
{
	int fr,to,w; //undirected graph
	Edge(int fr=0,int to=0,int w=0):fr(fr),to(to),w(w){}
	bool operator<(const Edge &B)const
	{
		return w<B.w;
	}
}edge[ME];
int ne;

int uf[MV];
int find(int x)
{
	return x==uf[x]?x:uf[x]=find(uf[x]);
}
int mst[MV];
void kruskal(int nv)
{
	sort(edge,edge+ne);
	for(int i=0;i<nv;i++)
		uf[i]=i;
	int cnt=0;
	for(int i=0;i<ne;i++)
	{
		Edge &e=edge[i];
		if(find(e.fr)==find(e.to)) continue;
		uf[uf[e.fr]]=e.to;
		mst[cnt++]=i;
		if(cnt==nv-1) return;
	}
}

int main()
{
	return 0;
}