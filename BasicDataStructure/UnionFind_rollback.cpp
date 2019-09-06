#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

typedef pair<int,int> PII;
const int M=1e5+5;
struct UnionFind
{
	int uf[M],sz[M];
    stack<PII> st;
 
    void init(int n)
    {
        for(int i=0;i<n;i++)
        	uf[i]=i,sz[i]=1;
    }
 
    int find(int x) 
    { // no path compression
        return x==uf[x]?x:find(uf[x]);
    }
 
    void merge(int x,int y) 
    { // union-by-rank
    	x=find(x); y=find(y);
    	if(x==y)
    	{
    		st.emplace(-1,-1);
    		return; 
    	}
    	if(sz[x]<sz[y]) swap(x,y);
    	st.emplace(x,y);
    	sz[x]+=sz[y];
    	uf[y]=x;
    }
 
    void rollback() 
    { // delete last edge added
        auto a=st.top(); st.pop();
        int x=a.first, y=a.second;
        if(x==-1) return;
        sz[x]-=sz[y]; 
        uf[y]=y;
    }
};

int main()
{
	return 0;
}