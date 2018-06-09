#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

const int INF=0x3f3f3f3f;
const int MV=1e5+5;
const int ME=1e5+5;
struct Edge
{
	int to,nxt,w; //undirected graph
	//int id; if we need output the edges in mst
	Edge(int to=0,int nxt=0,int w=0):to(to),nxt(nxt),w(w){}
	bool operator<(const Edge &B)const
	{
		return w>B.w;
	}
}edge[ME];
int head[MV],ne;

bool inmst[MV];
priority_queue<Edge> qu;

int prim(int nv)
{
	while(!qu.empty()) qu.pop();
	memset(inmst,0,sizeof(inmst));
	inmst[0]=1;
	for(int e=head[0];e!=-1;e=edge[e].nxt)
		qu.push(edge[e]);
	int mst=0;
	while(!qu.empty())
	{
		int u=qu.top().to,w=qu.top().w; qu.pop();
		if(inmst[u]) continue;
		mst+=w;
		for(int e=head[u];e!=-1;e=edge[e].nxt)
			if(!inmst[edge[e].to]) qu.push(edge[e]);
	}
	return mst;
}

int main()
{
	return 0;
}