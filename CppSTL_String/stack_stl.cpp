#include <stdio.h>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

stack<int> st;

int main()
{
	st.push(3);
	st.push(5);
	st.push(7);

	cout<<st.top()<<" "<<st.size()<<endl;
	cout<<st.top()<<endl;
	cout<<st.top()<<" "<<st.size()<<endl;

	cout<<st.top()<<endl; st.pop();
	cout<<st.top()<<endl; st.pop();
	cout<<st.top()<<" "<<st.empty()<<endl; st.pop();
	cout<<st.empty()<<endl;

	st.push(3);
	st.push(5);
	st.push(7);
	while(!st.empty())
	{
		cout<<st.top()<<endl; st.pop();
	}

	return 0;
}