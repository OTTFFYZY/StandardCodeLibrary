#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;


const int ME=1e5+5;//number of edges
const int MV=1e5+5;//number of vertices
struct Edge
{
	int fr,to,nxt;
	int w;
	Edge(){}
	Edge(int _fr,int _to,int _nxt,int _w)
		:fr(_fr),to(_to),nxt(_nxt),w(_w) {}
}edges[ME];  // undirected -> ME*2
int head[MV],ne;
void init()
{
	ne=0;
	memset(head,-1,sizeof(head));
}
void add_edge(int fr,int to,int w) //directed
{
	edges[ne]=Edge(fr,to,head[fr],w);
	head[fr]=ne++;
}
void add_edge2(int a,int b,int w)  //undirected
{
	edges[ne]=Edge(a,b,head[a],w);
	head[a]=ne++;
	edges[ne]=Edge(b,a,head[b],w);
	head[b]=ne++;
}

int main()
{
	init();
	//traverse u's adjacent vertices
	int u=0;
	for(int e=head[u];e!=-1;e=edges[e].nxt)
	{
		int v=edges[e].to;

	}
	return 0;
}