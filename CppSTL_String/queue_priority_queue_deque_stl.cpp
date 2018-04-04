#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue<int> qu;

priority_queue<int> pqu;
priority_queue<int,vector<int>,greater<int> > pqu2;

struct Node
{
	int a,b;
	Node(){}
	Node(int _a,int _b):a(_a),b(_b){}
	bool operator<(const Node &B) const
	{
		if(a==B.a)
			return b<B.b;
		return a<B.a;
	}
};
priority_queue<Node> pqn;

deque<int> dqu;

int main()
{
	qu.push(3);
	qu.push(5);
	qu.push(7);

	cout<<qu.front()<<" "<<qu.size()<<endl;
	cout<<qu.front()<<endl;
	cout<<qu.front()<<" "<<qu.size()<<endl;

	cout<<qu.front()<<endl; qu.pop();
	cout<<qu.front()<<endl; qu.pop();
	cout<<qu.front()<<" "<<qu.empty()<<endl; qu.pop();
	cout<<qu.empty()<<endl;

	qu.push(3);
	qu.push(9);
	qu.push(7);
	while(!qu.empty())
	{
		cout<<qu.front()<<" "; qu.pop();
	}
	cout<<endl<<endl;

	pqu.push(3);
	pqu.push(9);
	pqu.push(7);
	while(!pqu.empty())
	{
		cout<<pqu.top()<<" "; pqu.pop();
	}
	cout<<endl<<endl;

	pqu2.push(3);
	pqu2.push(9);
	pqu2.push(7);
	while(!pqu2.empty())
	{
		cout<<pqu2.top()<<" "; pqu2.pop();
	}
	cout<<endl<<endl;

	pqn.push(Node(1,2));
	pqn.emplace(2,2);
	pqn.emplace(2,1);
	pqn.emplace(1,1);
	pqn.emplace(0,0);
	while(!pqn.empty())
	{
		cout<<pqn.top().a<<" "<<pqn.top().b<<endl; pqn.pop();
	}
	cout<<endl;

	dqu.push_front(1);
	dqu.push_front(3);
	dqu.push_front(7);
	dqu.push_back(2);
	dqu.push_back(6);
	dqu.push_back(8);
	cout<<dqu.size()<<endl;
	while(!dqu.empty())
	{
		cout<<dqu.front()<<" "; dqu.pop_front();
	}
	cout<<endl;

	dqu.push_front(1);
	dqu.push_front(3);
	dqu.push_front(7);
	dqu.push_back(2);
	dqu.push_back(6);
	dqu.push_back(8);
	while(!dqu.empty())
	{
		cout<<dqu.back()<<" "; dqu.pop_back();
	}
	cout<<endl;

	return 0;
}