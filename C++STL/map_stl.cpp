#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<int,int> mapi2i;
map<string,int> maps2i;

int main()
{
	mapi2i.insert(make_pair(3,5));
	mapi2i.emplace(5,3);
	mapi2i[6]=2;
	for(auto i:mapi2i)
		cout<<i.first<<" "<<i.second<<endl;
	cout<<endl;

	mapi2i[5]=1;
	for(auto i:mapi2i)
		cout<<i.first<<" "<<i.second<<endl;
	cout<<endl;

	cout<<mapi2i.lower_bound(4)->second<<endl;
	cout<<mapi2i.upper_bound(4)->second<<endl<<endl;

	cout<<(mapi2i.find(2)==mapi2i.end())<<endl<<endl;

	mapi2i.erase(5);
	for(map<int,int>::iterator it=mapi2i.begin();it!=mapi2i.end();it++)
		cout<<it->first<<" "<<it->second<<endl;
	cout<<endl;

	cout<<mapi2i.size()<<" "<<mapi2i.empty()<<endl;
	mapi2i.clear();
	cout<<mapi2i.size()<<" "<<mapi2i.empty()<<endl;

	return 0;
}