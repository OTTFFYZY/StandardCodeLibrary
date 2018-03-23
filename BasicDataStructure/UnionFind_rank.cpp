#include <iostream>

const int M=1e6+5;
int uf[M],rank[M];
void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		uf[i]=i; rank[i]=0;
	}
}
int find(int x)
{
	return x==uf[x]?x:uf[x]=find(uf[x]);
}
int merge(int a,int b)
{
	int fa=find(a),fb=find(b);
	if(rank[fa]<rank[fb]) uf[fa]=fb;
	else
	{
		uf[fb]=fa;
		if(rank[fb]==rank[fa]) rank[fa]++;
	}
	return uf[fa];
}

int main()
{
	return 0;
}