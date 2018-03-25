#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<double,int> P;
typedef pair<int,int> PII;
PII PP(2,3);

pair<int,pair<int,int> > PIII;

vector<PII> vp;

int main()
{
	P=make_pair(1.5,3);
	cout<<P.first<<" "<<P.second<<endl;
	cout<<PP.first<<" "<<PP.second<<endl;

	PIII=make_pair(3,make_pair(5,7));
	cout<<PIII.first<<" "<<PIII.second.first<<" "<<PIII.second.second<<endl;

	vp.push_back(make_pair(1,3));
	vp.emplace_back(2,7);
	vp.emplace_back(3,8);
	for(auto i:vp)
	{
		cout<<i.first<<" "<<i.second<<endl;
	}

	return 0;
}