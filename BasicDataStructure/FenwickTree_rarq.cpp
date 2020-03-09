#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long LL;
const int M=1e5+5;
LL a[M];

LL bit1[M],bit2[M];//Binary Index Tree
inline int lowbit(int x)
{
	return x&(-x);
}
void add(LL bit[],int x,LL v)
{
	for(;x<M;x+=lowbit(x)) bit[x]+=v;
}
void init(LL a[],int n)
{
	memset(bit1,0,sizeof(bit1));
	memset(bit2,0,sizeof(bit2));
	for(int i=1;i<=n;i++) 
		add(bit2,i,a[i]);
}
void add(int l,int r,LL v) //add v at a[l~r]
{
	add(bit1,l,v); add(bit2,l,v*(1-l));
	add(bit1,r+1,-v); add(bit2,r+1,v*(r));
}
LL get_sum(LL bit[],int x)
{
	LL ans=0;
	for(;x;x-=lowbit(x)) ans+=bit[x];
	return ans;
}
LL get_sum(int l,int r) //sum of a[l,r]
{
	return r*get_sum(bit1,r)-(l-1)*get_sum(bit1,l-1)
	       +get_sum(bit2,r)-get_sum(bit2,l-1);
}

int main()
{
	return 0;
}