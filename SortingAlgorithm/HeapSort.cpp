#include <stdio.h>
#include <iostream>
using namespace std;

const int M=1e5+5;
int a[M]={0,7,3,8,2,5,3,7};

int n;
void sink(int p,int h[])
{
	int q=p<<1,x=h[p];
	while(q<=n)
	{
		if(q<n&&h[q+1]>h[q]) q++;
		if(h[q]<=x) break;
		h[p]=h[q];
		p=q;
		q=p<<1;
	}
	h[p]=x;
}
void heap_sort(int a[],int nn) //sort 1~nn
{
	n=nn;
	for(int i=n/2;i>0;i--) sink(i,a);
	for(int i=n;i>1;i--)
	{
		swap(a[i],a[1]); n--;
		sink(1,a);
	}
}

int main()
{
	int n=7;
	heap_sort(a,n);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;


	return 0;
}