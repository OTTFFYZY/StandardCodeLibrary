#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
using namespace std;

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());

const int M=1e5+5;
int a[M];
int n;
void shuffling(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        int j=rnd()%(i+1);
        swap(a[i],a[j]);
    }
}

int main()
{
    return 0;
}