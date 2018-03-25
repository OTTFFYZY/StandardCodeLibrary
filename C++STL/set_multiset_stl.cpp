#include <stdio.h>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;



int a[6]={1,4,2,3,5,2};
set<int> se(a,a+6);

multiset<int> mlse(a,a+6);

int main()
{

	for(int i:se)
		cout<<i<<" ";
	cout<<endl<<endl;

	se.clear();

	se.insert(3);
	se.insert(7);
	se.insert(9);
	se.insert(5);
	se.insert(1);
	se.insert(1);
	cout<<se.size()<<" "<<se.empty()<<endl;
	se.erase(5); se.erase(3);
	cout<<se.size()<<" "<<se.empty()<<endl<<endl;

	se.clear();
	se.insert(a,a+6);

	for(set<int>::iterator it=se.begin();it!=se.end();it++)
		cout<<*it<<" ";
	cout<<endl<<endl;

	cout<<se.count(1)<<" "<<se.count(3)<<" "<<se.count(6)<<endl<<endl;

	cout<<*se.lower_bound(2)<<" "<<*se.upper_bound(2)<<endl;
	//lower_bound returns an iterator to the first element 
	//greater than or equal to a certain value 
	//upper_bound returns an iterator to the first element 
	//greater than a certain value 
	cout<<(se.upper_bound(10)==se.end())<<endl<<endl;

	for(auto i:mlse)
		cout<<i<<" ";
	cout<<endl<<endl;

	cout<<mlse.size()<<" "<<mlse.empty()<<endl<<endl;
	cout<<mlse.count(1)<<" "<<mlse.count(2)<<" "<<mlse.count(6)<<endl<<endl;

	mlse.erase(2);
	for(auto i:mlse)
		cout<<i<<" ";
	cout<<endl<<endl;

	return 0;
}