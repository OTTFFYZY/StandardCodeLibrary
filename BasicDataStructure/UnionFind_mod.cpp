#include <iostream>

const int M=1e6+5;
const int MO=3;
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
	dep[x]%=MO;
	return uf[x]=fx;
}
bool merge(int a,int b)
{
	int fa=find(a),fb=find(b);
	if(fa!=fb)
	{
		uf[fb]=a;
		dep[fb]=(1-dep[b]+MO)%MO;
		return 1;
	}
	else
		return dep[b]==(dep[a]+1)%MO;
}

int main()
{
	return 0;
}
