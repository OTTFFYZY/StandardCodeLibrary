#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <unordered_map>
using namespace std;

class RandomizedSet {
public:
    unordered_map<int,int> ma;
    vector<int> v;
    int last;
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(0));
        ma.clear();
        v.clear();
        last=0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(ma.count(val)) return false;
        if(last==(int)v.size()) v.push_back(val);
        else v[last]=val;
        ma[val]=last++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!ma.count(val)) return false;
        int p=ma[val];
        ma.erase(val);
        if(p!=--last)
        {
            swap(v[p],v[last]);
            ma[v[p]]=p;
        } 
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(!last) return -1;
        return v[rand()%last];
    }
};

int main()
{
    return 0;
}