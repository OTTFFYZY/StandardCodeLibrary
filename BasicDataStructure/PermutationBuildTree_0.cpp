#include <cstdio>

const int M=1e5+5;
int p[M];
int fa[M];
int l[M],r[M];

int vis[M];
int uf[M];
void init(int n)
{
	for(int i=1;i<=n;i++)
		uf[i]=i;
}
int find(int x)
{
	return x==uf[x]?x:uf[x]=find(uf[x]);
}
void merge(int x,int y)
{
	x=find(x); y=find(y);
	uf[y]=x;
}


int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&p[i]);
	init(n);
	for(int i=n-1;i>=0;i--)
	{
		int val=p[i];
		vis[val]=1;
		if(val!=1&&vis[val-1])
		{
			int son=find(val-1);
			fa[son]=val;
			l[val]=son;
			merge(val,son);
		}
		if(val!=n&&vis[val+1])
		{
			int son=find(val+1);
			fa[son]=val;
			r[val]=son;
			merge(val,son);
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d%c",fa[i],i==n?'\n':' ');
	for(int i=1;i<=n;i++)
		printf("%d%c",l[i],i==n?'\n':' ');
	for(int i=1;i<=n;i++)
		printf("%d%c",r[i],i==n?'\n':' ');
	return 0;
}