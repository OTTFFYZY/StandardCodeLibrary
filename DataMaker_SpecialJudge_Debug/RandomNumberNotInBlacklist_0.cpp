#include <iostream>
#include <stdio.h>
#include <string.h>
#include <random>
#include <chrono>
using namespace std;

mt19937 rnd;
int n;
vector<int> sum;
vector<int> fr;
void init(int _n, vector<int> blacklist) {
    rnd.seed(chrono::system_clock::now().time_since_epoch().count());
    n=_n;
    sort(blacklist.begin(),blacklist.end());
    int pre=0;
    sum.clear();
    fr.clear();
    sum.push_back(0);
    for(int i:blacklist)
    {
        fr.push_back(pre);
        sum.push_back(i-pre+sum.back());
        pre=i+1;
    }
    fr.push_back(pre);
    sum.push_back(n-pre+sum.back());
    n-=blacklist.size();
}

int pick() {
    int k=rnd()%n;
    int p=upper_bound(sum.begin(),sum.end(),k)-sum.begin()-1;
    return fr[p]+k-sum[p];
}
