#include <stdio.h>

const double EPS=1e-8;
double f(double m)
{
	return 0.0; //calculate a function
}

double ts(double l,double r)
{
    double m,mm;
    while(l-r>EPS)
    {
        m=(l+r)/2.0;
        mm=(m+r)/2.0;
        if(f(m)<f(mm))
            r=mm;
        else
            l=m;
    }
    return l;
}

int main()
{
	return 0;
}