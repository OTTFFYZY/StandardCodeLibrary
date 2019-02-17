#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// to_string() 
// int, unsigned, long long, unsigned long long
// float, double, long double

string to_string(string s)
{
    return '"' + s + '"';
}
string to_string(const char* s) 
{
    return to_string((string)s);
}
string to_string(bool b) 
{
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) 
{
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) 
{
    bool first = true;
    string res = "{";
    for (const auto &x : v) 
    {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() 
{ 
    cerr << endl; 
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) 
{
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef OTTFF
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) 38
#endif

int main()
{
    int a=10;
    long long b=123456789012345678L;
    double c=3.1415926;
    debug(a,b,c);

    vector<vector<int>> g(5);
    g[0].push_back(1);
    g[1].push_back(2); g[1].push_back(4);
    g[2].push_back(1); g[2].push_back(3); g[2].push_back(0);
    g[3].push_back(1); g[3].push_back(2);
    g[4].push_back(3); g[4].push_back(1);
    debug(g);

    map<int,pair<int,int>> ma;
    ma[0]=make_pair(2,3);
    ma[1]=make_pair(5,3); 
    ma[2]=make_pair(6,4); 
    ma[3]=make_pair(7,2); 
    ma[4]=make_pair(1,8);
    debug(ma);
    
    return 0;
}