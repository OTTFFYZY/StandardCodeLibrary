#include <stdio.h>
#include <iostream>
using namespace std;

const int M=1e6+5;
int color[M]={0,1,2,2,1,0,1,0,2,0};

void tcs(int color[],int n)
{
	int one=0,cur=0,two=n-1;
	while(cur<=two)
	{
		if(color[cur]==0)
		{
			if(cur!=one) swap(color[one],color[cur]);
			one++;
			cur++;
		}
		else if(color[cur]==1)
			cur++;
		else // color[cur]==2
		{
			swap(color[cur],color[two]);
			two--;
		}
	}
}

int main()
{
	int n=10;
	tcs(color,n);
	for(int i=0;i<n;i++)
		cout<<color[i]<<" ";
	cout<<endl;
	return 0;
}