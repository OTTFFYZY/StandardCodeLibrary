#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int M=1e5+5;
int v[M];
int n,k;
priority_queue<int,vector<int>,greater<int>> qu;
int huffman()
{
	for(int i=0;i<n;i++)
		qu.push(v[i]);
	int ans=0; // just consider the cost of combine
	int m=k-1-n%(k-1);
	for(int i=0;i<m;i++)
		qu.push(0); // add empty node (all v[i]>=0)
	while(qu.size()>1)
	{
		int tmp=0;
		for(int i=0;i<k;i++)
		{
			tmp+=qu.top(); qu.pop();
		}
		qu.push(tmp);
		ans+=tmp;
	}
	return ans;
}

int main()
{
	return 0;
}