#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

typedef pair<int,int> PII;
int solve(int end,int v,vector<int> &price, vector<int> &dis)
{
	int n=price.size(); // except end and include start there are n station
	price.push_back(0); // price = 0 for end means sold all the gas left
	dis.push_back(end);
	int ans=price[0]*v;
	deque<PII> deq;
	deq.emplace_back(v,price[0]);
	for(int i=1;i<=n;i++)
	{
		int d=dis[i]-dis[i-1];
		if(d>v) return -1; // can not get to end
		int tmp=d; // the volunm left

		// using cheaper gas first
		while(d)
		{
			if(deq.front().first<d)
			{
				d-=deq.front().first;
				deq.pop_front();
			}
			else
			{
				PII p=deq.front(); 
				deq.pop_front();
				p.first-=d;
				d=0;
				if(p.first)
					deq.push_front(p);
			}
		}

		// change expansive gas to cheap gas
		while(!deq.empty()&&deq.back().second>=price[i])
		{
			PII p=deq.back();
			deq.pop_back();
			tmp+=p.first;
			ans-=p.second*p.first;
		}

		// full
		ans+=tmp*price[i];
		deq.emplace_back(tmp,price[i]);

		//cout<<i<<" "<<ans<<endl;
	}
	return ans;
}



int main()
{
	//dis  0  3  4  6  10 15
	//real  15  2  4  8  5
	
	int v=10;
	vector<int> price({5,2,3,4,1});
	vector<int> dis({0,3,4,6,10});
	int end=15;
	cout<< solve(end,v,price,dis) <<endl;
	return 0;
}