#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int M=1e5+5;
int v[M];
int n;
priority_queue<int,vector<int>,greater<int>> qu;
int huffman()
{
	for(int i=0;i<n;i++)
		qu.push(v[i]);
	int ans=0; // just consider the cost of combine
	while(qu.size()>1)
	{
		int tmp=qu.top(); qu.pop();
		tmp+=qu.top(); qu.pop();
		qu.push(tmp);
		ans+=tmp;
	}
	return ans;
}

int main()
{
	return 0;
}