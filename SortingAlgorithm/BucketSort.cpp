#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1e5+5;

int a[M]={17,23,835,23,235,13,17};

void selection_sort(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		int minp=i;
		for(int j=i+1;j<n;j++)
			if(a[j]<a[minp]) minp=j;
		swap(a[i],a[minp]);
	}
}

const int NB=50; //number of buckets
int nu[M],nxt[M],head[NB];
void bucket_sort(int a[],int n)
{
	for(int j=0;j<NB;j++)
		head[j]=-1;
	int minn=INT_MAX,maxn=INT_MIN;
	for(int i=0;i<n;i++)
		minn=min(minn,a[i]),maxn=max(maxn,a[i]);
	int eb=(maxn-minn)/NB+1;
	//cout<<eb<<endl;
	for(int i=0;i<n;i++)
	{
		nu[i]=a[i];
		int b=(nu[i]-minn)/eb;
		//cout<<nu[i]<<" "<<b<<endl;
		nxt[i]=head[b];
		head[b]=i;
	}
	int k=0;
	for(int i=0;i<NB;i++)
	{
		int j=0;
		for(int now=head[i];now!=-1;now=nxt[now])
			a[k+(j++)]=nu[now];
		//cout<<k<<" "<<j<<endl;
		selection_sort(a+k,j);
		k+=j;
	}
}

int main()
{
	int n=7;
	bucket_sort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	return 0;
}