#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1e5+5;

int a[M]={7,3,8,2,5,3,7};

int partition(int a[],int l,int r)
{
	int j=l+1;
	for(int i=l+1;i<=r;i++)
	{
		if(a[i]<a[l])
		{
			swap(a[i],a[j]);
			j++;
		}
	}
	j--;
	swap(a[l],a[j]);
	return j;
}
void quick_sort(int a[],int l,int r)
{
	if(l>=r) return;
	int mid=partition(a,l,r);
	quick_sort(a,l,mid-1);
	quick_sort(a,mid+1,r);
}


int main()
{
	int n=7;
	quick_sort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;


	return 0;
}