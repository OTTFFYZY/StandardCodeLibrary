#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int M=1e5+5;
const int MB=16;
const int MASK=0x10000;

int n;
int a[M],b[M];
int cnt[MASK];

inline int getd(int x,int d)
{
	return (x>>(d*MB))&(MASK-1);
}

void radixSort()
{
	int *x=a,*y=b;
	for(int d=0;d<2;d++)
	{
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++) cnt[getd(x[i],d)]++;
		for(int i=1;i<MASK;i++) cnt[i]+=cnt[i-1];
		for(int i=n-1;i>=0;i--) y[--cnt[getd(x[i],d)]]=x[i];
		swap(x,y);
	}
}

int main()
{
	//cout<<MASK<<endl;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	radixSort();
	for(int i=0;i<n;i++)
		printf("%d%c",a[i],i==n-1?'\n':' ');
	return 0;
}