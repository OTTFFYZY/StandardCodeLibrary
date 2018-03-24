#include <stdio.h>
#include <algorithm>
using namespace std;

const int M=1e5+5;

int t[M];
inline int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int v) //add v at x
{
	for(;x<M;x+=lowbit(x))
		t[x]+=v;
}
int get_sum(int x) //sum of 1~x
{
	int ans=0;
	for(;x;x-=lowbit(x))
		ans+=t[x];
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