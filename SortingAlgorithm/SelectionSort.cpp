#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1e5+5;

int a[M]={7,3,8,2,5,3,7};

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


int main()
{
	int n=7;
	selection_sort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;


	return 0;
}