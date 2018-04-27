#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int M=1e5+5;

int a[M]={7,3,8,2,5,3,7};

void bubble_sort(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
			if(a[j]>a[j+1]) swap(a[j],a[j+1]);
	}
}


int main()
{
	int n=7;
	bubble_sort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;


	return 0;
}