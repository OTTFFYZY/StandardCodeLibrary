#include <iostream>

const int M=1e6+5;
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
int merge(int a,int b)
{
	int fa=find(a),fb=find(b);
	if(fa!=fb) uf[fb]=fa;
	return fa;
}

int main()
{
	return 0;
}