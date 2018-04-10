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

void add(int x,int v) //add v at x
{
	for(;x<M;x+=lowbit(x)) bit[x]+=v;
}
void init(int a[],int n) //use a[] to init bit[]
{
	memset(bit,0,sizeof(bit));
	for(int i=0;i<n;i++) add(i+1,a[i]);
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

int main()
{
	return 0;
}