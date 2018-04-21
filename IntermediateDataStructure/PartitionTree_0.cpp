#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int MB=20;
const int M=1e5+5;

int pt[MB][M],inleft[MB][M]; //partition tree pt[][] and
int a[M],sorted[M]; // origin array a[] and sorted array sorted[]
int n,q;

void build(int l,int r,int dep)
{
	if(l>=r) return;
	int mid=(l+r)/2;
	int midv=sorted[mid];//cout<<mid<<" midv "<<midv<<endl;
	int eqmid=0;
	for(int i=l;i<=r;i++) eqmid+=(pt[dep][i]==midv);
	int lp=l,rp=mid+1;
	for(int i=l;i<=r;i++)
	{
		inleft[dep][i]=i==l?0:inleft[dep][i-1];
		if(pt[dep][i]<midv||pt[dep][i]==midv&&eqmid)
		{
			pt[dep+1][lp++]=pt[dep][i];
			inleft[dep][i]++;
			eqmid-=(pt[dep][i]==midv);
		}
		else
			pt[dep+1][rp++]=pt[dep][i];
	}
	build(l,mid,dep+1);
	build(mid+1,r,dep+1);
}

void build()
{
	for(int i=1;i<=n;i++)
		pt[0][i]=a[i];
	memcpy(sorted,a,sizeof(a));
	sort(sorted+1,sorted+n+1);
	build(1,n,0);
}

int query(int l,int r,int dep,int ql,int qr,int k)
{
    //cout<<l<<" "<<r<<" "<<ql<<" "<<qr<<endl;
	if(l==r&&k==1) return pt[dep][l];
	if(l>=r) return -1;
	int mid=(l+r)/2;
	int prel=(ql==l?0:inleft[dep][ql-1]);
	int inl=inleft[dep][qr]-prel;
	//int inr=qr-ql+1-inl;
	if(inl>=k)
		return query(l,mid,dep+1,
		             l+(ql==l?0:inleft[dep][ql-1]),l-1+inleft[dep][qr],k);
	else
		return query(mid+1,r,dep+1,
			         mid+1+ql-l-prel,mid+1+qr-l-inleft[dep][qr],
			         k-inl);
}
int query(int l,int r,int k)
{
	return query(1,n,0,l,r,k);
}


int main()
{
	
	return 0;
}