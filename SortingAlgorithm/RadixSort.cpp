#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1e5+5;
const int MB=10;

int a[M]={17,23,833,23,235,13,17};

int nu[M],nxt[M],head[MB];
void radix_sort(int a[],int n)
{
	int mod=10,dev=1;
	for(int i=0;i<8;i++) //sort 0~10^8
	{
		for(int j=0;j<MB;j++)
			head[j]=-1;
		for(int j=0;j<n;j++)
		{
			int b=a[j]%mod/dev; //base
			nu[j]=a[j];
			nxt[j]=head[b];
			head[b]=j;
		}
		int p=n;
		for(int j=MB-1;j>=0;j--)
			for(int k=head[j];k!=-1;k=nxt[k])
				a[--p]=nu[k];
		mod*=10; dev*=10;
	}

}

int main()
{
	int n=7;
	radix_sort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	return 0;
}