#include <iostream>

const int M=1e6+5;
int uf[M],dep[M];
void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		uf[i]=i;
		dep[i]=0;
	}
}
int find(int x)
{
	if(x==uf[x]) return x;
	int fx=find(uf[x]);
	dep[x]+=dep[uf[x]];
	return uf[x]=fx;
}
int merge(int a,int b)
{
	int fa=find(a),fb=find(b);
	if(fa!=fb)
	{
		uf[fb]=fa;
		dep[fb]=dep[a]+1;
	} 
	return fa;
}

int main()
{
	return 0;
}