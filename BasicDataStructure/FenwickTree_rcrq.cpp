#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1e5+5;

int bit[M],bit2[M];
inline int lowbit(int x)
{
	return x&(-x);
}
void add(int bit[],int x,int v) //add v at a[x]
{
	for(;x<M;x+=lowbit(x)) bit[x]+=v;
}
void init(int a[],int n) //use a[] to init bit[], bit2[]
{
	memset(bit,0,sizeof(bit));
	memset(bit2,0,sizeof(bit2));
	for(int i=1;i<=n;i++) 
		add(bit,i,a[i]-a[i-1]),add(bit2,i,i*(a[i]-a[i-1]));
}
void add(int l,int r,int v) //add v at a[l~r]
{
	add(bit,l,v); add(bit2,l,v*l);
	add(bit,r+1,-v); add(bit2,r+1,v*(r+1));
}
int get_sum(int bit[],int x)
{
	int ans=0;
	for(;x;x-=lowbit(x)) ans+=bit[x];
	return ans;
}
int get_sum(int l,int r) //sum of a[l,r]
{
	return (r+1)*get_sum(bit,r)-l*get_sum(bit,l-1)
	       -get_sum(bit2,r)+get_sum(bit2,l-1);
}

int main()
{
	return 0;
}