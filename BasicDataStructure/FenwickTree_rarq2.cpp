#include <iostream>
#include <string.h>
using namespace std;

const int M=1e5+5;
int bit0[M],bit1[M];

inline int lowbit(int x)
{
	return x&(-x);
}
void init()
{
	memset(bit0,0,sizeof(bit0));
	memset(bit1,0,sizeof(bit1));
}
void add(int p,int x)
{
	for(int i=p;i<M;i++)
		bit0[i]+=x,bit1[i]+=x*p;
}
void add(int l,int r,int x)
{
	add(l-1,-x);
	add(r,x);
}
int getsum(int p,int bit[])
{
	int ans=0;
	for(int i=p;i;i-=lowbit(i))
		ans+=bit[i];
	return ans;
}
int getsum(int l,int r)
{
	return getsum(r,bit1)+(getsum(M-1,bit0)-getsum(r,bit0))*r
	    -getsum(l-1,bit1)-(getsum(M-1,bit0)-getsum(l-1,bit0))*(l-1);
}

int main()
{
	return 0;
}