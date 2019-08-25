#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int M=1e6+5;
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
	for(int i=0;i<n;i++)
		qua.push(v[i]);
	int ans=0;
	for(int i=1;i<n;i++)
	{
		int tmp=getmin()+getmin();
		ans+=tmp;
		qub.push(tmp);
	}
	return ans;
}

int main()
{
	return 0;
}