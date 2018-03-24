#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

struct Node
{
	int a,b;
	Node(){}
	Node(int _a,int _b):a(_a),b(_b){}
};
vector<Node> vec2;

int main()
{
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(4);
	vec.push_back(17);
	vec.push_back(2);
	cout<<vec.size()<<endl;
	
	for(int i=0;i<vec.size();i++)
		cout<<vec[i]<<" ";
	cout<<endl;
	
	sort(vec.begin(),vec.end());

	for(int i:vec)
		cout<<i<<" ";
	cout<<endl;

	vec2.emplace(vec2.end(),1,3);
	vec2.emplace_back(4,2);

	for(auto i:vec2)
		cout<<i.a<<" "<<i.b<<endl;

	return 0;
}