#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

const int MV=1e5+5;
const int INF=0x3f3f3f3f;
struct Edge
{
	int v,d;
};
vector<Edge> g[MV];
int nv;

int d[MV],inq[MV],cnt[MV];
queue<int> qu;
bool spfa(int st)
{
	memset(inq,0,sizeof(inq));
	memset(d,INF,sizeof(d));
	memset(cnt,INF,sizeof(cnt));
	while(!qu.empty()) qu.pop();
	d[st]=0;
	inq[st]=1;
	qu.push(st);
	while(!qu.empty())
	{
		int u=qu.front(); qu.pop();
		inq[u]=0;
		for(auto e:g[u])
		{
			int v=e.v,nd=e.d;
			if(d[u]+nd<d[v])
			{
				d[v]=d[u]+nd;
				if(!inq[v])
				{
					qu.push(v);
					inq[v]=1;
					if(++cnt[v]>nv) return 0; //negative loop
				}
			}
		}
	}
	return 1;
}

int main()
{
	return 0;
}