#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int M=1e5+5;
int v[M];
int n;
queue<int> qua,qub;
int getmin()
{
	int ans;
	if(qub.empty()||!qua.empty()&&qua.front()<qub.front())
	{
		ans=qua.front(); qua.pop();
	}
	else
	{
		ans=qub.front(); qub.pop();
	}
	return ans;
}
int huffman()
{
	sort(v,v+n);
	int m=k-1-n%(k-1);
	for(int i=0;i<m;i++)
		qua.push(0); // add empty node (all v[i]>=0)
	for(int i=0;i<n;i++)
		qua.push(v[i]);

	int ans=0; // just consider the cost of combine
	while(qu.size()>1)
	{
		int tmp=0;
		for(int i=0;i<k;i++)
			tmp+=getmin();
		qub.push(tmp);
		ans+=tmp;
	}
	return ans;
}

int main()
{
	return 0;
}