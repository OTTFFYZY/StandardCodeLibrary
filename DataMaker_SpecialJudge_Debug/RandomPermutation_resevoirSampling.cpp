#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
using namespace std;

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());

const int M=1e5+5;
int a[M];
int res[M];
int n, k;

// n elements in the sample space
// k elements in the results
// k <= n

// k = 1
int get_random_one(int a[], int n)
{
    int ans;
    for(int i=0;i<n;i++)
    {
        if(rnd()%(i+1)==0)
            ans=a[i];
    }
    return ans;
}

void get_permutation(int a[], int n, int res[], int k)
{
    for(int i=0;i<k;i++)
        res[i]=a[i];
    for(int i=k;i<n;i++)
    {
        int j=rnd()%(i+1);
        if(j < k)
            res[j]=a[i];
    }
}

int main()
{
    return 0;
}