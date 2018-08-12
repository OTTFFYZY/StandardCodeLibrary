#include <stdio.h>
#include <iostream>
using namespace std;

const int M=1005;
int a[M]={3,1,5,2,4,6,7,8};
int b[M]={1,4,3,5,2,8,7,6};

int nlis[M];
int lis(int a[],int n)
{
	int nn=0;
	for(int i=0;i<n;i++)
	{
		int k=lower_bound(nlis,nlis+nn,a[i])-nlis;
		if(k==nn) nn++;
		nlis[k]=a[i];
	}
	return nn;
}
int h[M]; //there are duplicate elements in b;
int lcs(int a[],int n,int b[],int m) //O(nlogn)
{
	for(int i=0;i<m;i++) h[b[i]]=i;
	for(int i=0;i<n;i++) a[i]=h[a[i]];
	return lis(a,n);
}

int main()
{
	cout<<lcs(a,8,b,8)<<endl;
	return 0;
}