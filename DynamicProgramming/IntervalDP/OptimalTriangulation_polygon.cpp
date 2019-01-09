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
	void read()
	{
		scanf("%lf%lf",&x,&y);
	}
	double norm()
	{
		return sqrt(sqr(x)+sqr(y));
	}
	bool operator==(const Point &B) const
	{
		return x==B.x && y==B.y;
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

bool intersection(const Point &a,const Point &b,const Point &c,const Point &d)
{
	return det(b-a,c-a)*det(b-a,d-a)<=0 && det(d-c,a-c)*det(d-c,b-c)<=0;
}

struct Polygon
{
	Point p[M];
	int n;
	double dp[M][M];
	
	bool isDiagonal(const Point &a,const Point &b)
	{
		p[n]=p[0];
		for(int i=0;i<n;i++)
		{
			if(p[i]==a||p[i+1]==a||p[i]==b||p[i+1]==b) continue;
			if(intersection(a,b,p[i],p[i+1])) return 0;
		}
		return 1;
	}

	double w(int i,int j,int k)
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
				if((st!=0||ed!=n-1)&&!isDiagonal(p[st],p[ed])) continue;
				for(int k=st+1;k<ed;k++)
				{
					dp[st][ed]=min(dp[st][ed],
								   max(max(dp[st][k],dp[k][ed]),w(st,ed,k)));

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