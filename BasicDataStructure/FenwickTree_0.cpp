#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1e5+5;

int bit[M];
inline int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int v) //add v at a[x]
{
	for(;x<M;x+=lowbit(x)) bit[x]+=v;
}
void init(int a[],int n) //use a[] to init bit[]
{
	memset(bit,0,sizeof(bit));
	for(int i=1;i<=n;i++) add(i,a[i]);
}
int get_sum(int x) //sum of 1~x
{
	int ans=0;
	for(;x;x-=lowbit(x)) ans+=bit[x];
	return ans;
}
int get_sum(int l,int r) //sum of l~r
{
	return get_sum(r)-get_sum(l-1);
}

//range add  single-point query
//use lowbit add getsum   above
void init2(int a[],int n)
{
	memset(bit,0,sizeof(bit));
	for(int i=1;i<=n;i++) add(i,a[i]-a[i-1]);
}
void add2(int l,int r,int v) // add v at a[l~r]
{
	add(l,v); add(r+1,-v);
}
int get_v(int x)       //value of a[x]
{
	return get_sum(x);
}

int main()
{
	return 0;
}