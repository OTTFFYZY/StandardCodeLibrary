#include <bits\stdc++.h>
using namespace std;

const int M=1e5+5;

int BS=300;

int a[M];

struct Q
{
	int l,r;
	int id;
	int ans;
	void read(int i)
	{
		scanf("%d%d",&l,&r);
		id=i;
		ans=0;
	}
	bool operator<(const Q &B) const
	{
		return l/BS == B.l/BS ? r < B.r : l/BS < B.l/BS;
	}
}q[M];

bool cmp(const Q &a,const Q &b)
{
	return a.id<b.id;
}

int main()
{
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	// offline queries
	for(int i=0;i<m;i++)
		q[i].read(i);
	// sort Queries by block
	BS=sqrt(n);
	sort(q,q+m);
	
	// init a interval
	int ans=0,l=1,r=1;

	// solve queries one by one
	for(int i=0;i<m;i++)
	{
		int L=q[i].l,R=q[i].r;
		while(l<L)
		{
			// do sth. to calculate ans
			l++;
		}
		while(l>L)
		{
			l--;
			// do sth. to calculate ans
		}
		while(r<R)
		{
			r++;
			// do sth. to calculate ans
		}
		while(r>R)
		{
			// do sth. to calculate ans
			r--;
		}
		q[i].ans=ans;
	}
	sort(q,q+m,cmp);
	for(int i=0;i<m;i++)
		printf("%d\n",q[i].ans);
	return 0;
}