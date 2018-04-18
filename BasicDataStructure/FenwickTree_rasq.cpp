#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1e5+5;

//range add  single-point query
int bit[M]; //Binary Index Tree
inline int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int v)
{
	for(;x<M;x+=lowbit(x)) bit[x]+=v;
}
void init(int a[],int n)      //use c[i]=a[i]-a[i-1] to initiate bit
{
	memset(bit,0,sizeof(bit));
	for(int i=1;i<=n;i++) add(i,a[i]-a[i-1]);
}
void add(int l,int r,int v) // add v at a[l~r]
{
	add(l,v); add(r+1,-v);
}
int get_v(int x)   //value of a[x]
{
	int ans=0;
	for(;x;x-=lowbit(x)) ans+=bit[x];
	return ans;
}

int main()
{
	return 0;
}