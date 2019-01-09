#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

const int M=305;
const double DINF=1e20;

double sqr(double x)
{
	return x*x;
}

struct Point
{
	double x,y;
	Point(double x=0,double y=0)
		:x(x),y(y){}
	double norm()
	{
		return sqrt(sqr(x)+sqr(y));
	}
	Point operator-(const Point &B) const
	{
		return Point(x-B.x,y-B.y);
	}
	friend double det(const Point &A,const Point &B)
	{
		return A.x*B.y-A.y*B.x;
	}
	friend double dis(const Point &A,const Point &B)
	{
		return (A-B).norm();
	}
};
double area(const Point &a,const Point &b,const Point &c)
{
	return 0.5*fabs(det(b-a,c-a));
}

struct Convex
{
	Point p[M];
	int n;
	double dp[M][M];
	
	double w(int i,int j,int k)
	{
		return dis(p[i],p[j])+dis(p[i],p[k])+dis(p[j],p[k]);
	}
	double w2(int i,int j,int k)
	{
		return area(p[i],p[j],p[k]);
	}
	double OptTriangulation()
	{
		for(int l=3;l<=n;l++)
		{
			for(int st=0,ed;(ed=st+l-1)<n;st++)
			{
				dp[st][ed]=DINF;
				for(int k=st+1;k<ed;k++)
				{
					//min sum perimeter
					dp[st][ed]=min(dp[st][ed],
								   dp[st][k]+dp[k][ed]+w(st,ed,k));
					//min max area
					//dp[st][ed]=min(dp[st][ed],
					//			     max(max(dp[st][k],dp[k][ed]),w2(st,ed,k)));

				}
			}
		}
		return dp[0][n-1];
	}
}c;

int main()
{
	return 0;
}