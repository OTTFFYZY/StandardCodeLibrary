#include <iostream>
#include <string>
using namespace std;

string to_debug_string(string s)
{
    return '"' + s + '"';
}
string to_debug_string(const char* s) 
{
    return to_debug_string((string)s);
}
string to_debug_string(bool b) 
{
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_debug_string(pair<A, B> p) 
{
    return "(" + to_debug_string(p.first) + ", " + to_debug_string(p.second) + ")";
}

template <typename A>
string to_debug_string(A v) 
{
    bool first = true;
    string res = "{";
    for (const auto &x : v) 
    {
        if (!first) res += ", ";
        first = false;
        res += to_debug_string(x);
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
    cerr << " " << to_debug_string(H);
    debug_out(T...);
}

#ifdef OTTFF
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) 42
#endif

int main()
{
    return 0;
}