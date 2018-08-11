#include <iostream>
#include <string.h>
#include <bitset>
#include <math.h>
using namespace std;

#define Debug
const int M=305;
const int MB=5; // long long -> 63 int ->31
typedef long long LL;
struct VS // Vector Space
{
    LL a[M];
    int n,m,nb;
    VS(int n=0,int m=0):n(n),m(m),nb(0)
    {
        memset(a,0,sizeof(a));
    }
    void clear(int _n,int _m)
    {
        n=_n; m=_m; nb=0;
        memset(a,0,sizeof(a));
    }
    LL& operator[](const int n)
    {
        return a[n];
    }
    // use gauss elimination get linear basis
    int gauss_basis() // O(MB*N)
    {
        int r,c,mr,i,j;
        for(r=0,c=0;r<n&&c<m;r++,c++)
        {
            mr=r;
            while(mr<n&&!(a[mr]&(1<<c))) mr++;
            if(!(a[mr]&(1<<c)))
            {
                r--; continue;
            }
            swap(a[r],a[mr]);
            for(i=0;i<n;i++)
                if(i!=r&&(a[i]&(1<<c))) a[i]^=a[r];
        }
        return nb=r; // number of vector in the basis
    }
    bool add_vector(LL v) // O(MB)
    {
        n++;
        if(m==nb) return 0;
        int r;
        for(r=0;r<nb;r++)
            if(a[r]&v) v^=a[r];
        if(!v) return 0;
        for(r=0;r<nb;r++)
            if(a[r]&v) a[r]^=v;
        for(r=nb-1;r>=0;r--)
            if(a[r]>v) a[r+1]=a[r];
            else break;
        a[r+1]=v; ++nb;
        return 1;
    }
    LL get_kth(LL k) //get the kth xor sum
    {
        LL ans=0;
        int i=0;
        while(k)
        {
            if(k&1) ans^=a[i];
            i++; k>>=1;
        }
        return ans;
    }
    LL get_rank(LL v) // rank in basis
    {
        LL ans=0;
        for(int i=0;i<nb;i++)
            if(a[i]&v) ans+=(1<<i);
        return ans;
    }
    // rank in VS is get_rank(v)*2^(n-nb)
    LL qp(LL a,LL n)
    {
        LL ans=1;
        while(n)
        {
            if(n&1) ans*=a;
            a*=a; n>>=1;
        }
        return ans;
    }
    LL get_allrank(LL v)
    {
        return get_rank(v)*qp(2,n-nb);
    }
    void show(int aug=0) //printed augmented matrix
    {
        #ifdef Debug
            cout<<"Matrix:"<<endl;
            for(int i=0;i<n+aug;i++)
            {
                for(int j=0;j<m+aug;j++)
                    cout<<((a[i]>>j)&1)<<" ";
                cout<<endl;
            }
            cout<<endl;
        #endif
    }
}A;

int a[M]={1,3,15},n;

int main()
{
    n=3;
    A.clear(n,MB);
    for(int i=0;i<n;i++)
        A[i]=a[i];
    cout<<"nb "<<A.gauss_basis()<<endl;
    A.show();
    cout<<"kth 1 : "<<A.get_kth(1)<<endl;
    cout<<"kth 3 : "<<A.get_kth(3)<<endl;
    cout<<"kth 5 : "<<A.get_kth(5)<<endl;
    cout<<"kth 6 : "<<A.get_kth(6)<<endl;
    cout<<"kth 7 : "<<A.get_kth(7)<<endl;
    cout<<"----------"<<endl;
    A.clear(0,MB);
    for(int i=0;i<n;i++)
        A.add_vector(a[i]);
    A.show();
    return 0;
}