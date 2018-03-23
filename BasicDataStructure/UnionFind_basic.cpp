#include <iostream>

const int M=1e6+5;
int uf[M];
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