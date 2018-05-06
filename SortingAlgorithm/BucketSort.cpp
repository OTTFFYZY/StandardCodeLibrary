#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1e5+5;
const int MB=10;

int a[M]={17,23,833,23,235,13,17};

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

const int BS=50; //Bucket Size
int nu[M],nxt[M],head[MB];
void bucket_sort(int a[],int n)
{
	for(int j=0;j<MB;j++)
		head[j]=-1;
	int minn=INT_MAX,maxn=INT_MIN;
	for(int i=0;i<n;i++)
		minn=min(minn,a[i]),maxn=max(maxn,a[i]);
	for(int i=0;i<n;i++)
	{
		
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