#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int M=10;
int oriset[M],subset[M];
int num[M],cnt[M],now[M];
int n,nn;

void dfs(int dep)
{
	if(dep==nn)
	{
		cout<<"[ ";
		for(int i=0;i<nn;i++)
			for(int j=0;j<now[i];j++)
				cout<<num[i]<<" ";
		cout<<"]"<<endl;
		return;
	}
	for(int i=0;i<=cnt[dep];i++)
	{
		now[dep]=i;
		dfs(dep+1);
	}
}

void getsubset()
{
	sort(oriset,oriset+n);
	memcpy(num,oriset,sizeof(oriset));
	nn=unique(num,num+n)-num;
	int j=0;
	for(int i=0;i<nn;i++)
	{
		while(j<n&&oriset[j]==num[i])
		{
			cnt[i]++;
			j++;
		}
		cout<<cnt[i]<<" ";
	}
	cout<<endl;
	//we can also use counting sort to initiate the num and cnt
	//if values in oriset are small
	dfs(0);
}


int main()
{
	n=3;
	oriset[0]=1; oriset[1]=2; oriset[2]=2;
	getsubset();

	return 0;
}