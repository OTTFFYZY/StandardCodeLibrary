#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

const int M=1e5+5;
int bs,belong[M],nb,l[M],r[M],n,q;
int a[M],ma[M];

void build()
{
	bs=sqrt(n);
	nb=n/bs; if(n%bs) nb++;
	for(int i=1;i<=nb;i++)
		l[i]=(i-1)*bs+1,r[i]=i*bs;
	r[nb]=n;
	for(int i=1;i<=n;i++)
		belong[i]=(i-1)/bs+1;

	for(int i=1;i<=nb;i++)
		for(int j=l[i];j<=r[i];j++)
			ma[i]=max(ma[i],a[j]);
}

void update(int x,int y)
{
	a[x]+=y;
	ma[belong[x]]=max(ma[belong[x]],a[x]);
}

int query(int x,int y)
{
	int ans=0;
	if(belong[x]==belong[y])
	{
		for(int i=x;i<=y;i++)
			ans=max(ans,a[i]);
		return ans;
	}
	for(int i=x;i<=r[belong[x]];i++)
		ans=max(ans,a[i]);
	for(int i=belong[x]+1;i<belong[y];i++)
		ans=max(ans,ma[i]);
	for(int i=l[belong[y]];i<=y;i++)
		ans=max(ans,a[i]);
	return ans;
}