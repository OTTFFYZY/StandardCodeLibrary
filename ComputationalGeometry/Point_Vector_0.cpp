#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

const int M=1005;
const double EPS=1e-8;
const double PI=acos(-1.0);

inline int sgn(double x)
{
	if(x>EPS) return 1;
	if(x<-EPS) return -1;
	return 0;
}

inline double sqr(double x)
{
	return x*x;
}

struct Point
{
	double x,y;
	Point(double x=0,double y=0)
		:x(x),y(y){}
	bool operator<(const Point &B) const
	{
		//return sgn(x-B.x) ? x<B.x : y<B.y;
		return x==B.x ? y<B.y : x<B.x;
	}
	bool operator==(const Point &B) const
	{
		return !sgn(x-B.x) && !sgn(y-B.y);
	}
	Point operator+(const Point &B) const
	{
		return Point(x+B.x,y+B.y);
	}
	Point operator-(const Point &B) const
	{
		return Point(x-B.x,y-B.y);
	}
	Point operator*(double a) const
	{
		return Point(x*a,y*a);
	}
	Point operator/(double a) const
	{
		return Point(x/a,y/a);
	}
	friend double dot(const Point &A,const Point &B) //dot prodect
	{
		return A.x*B.x+A.y*B.y;
	}
	friend double det(const Point &A,const Point &B) //cross prodect
	{
		return A.x*B.y-A.y*B.x;
	}
	friend double dis(const Point &A,const Point &B)
	{
		return (A-B).length();
	}

	double polar() //rad
	{
		return atan2(y,x);
	}
	double length()
	{
		return sqrt(sqr(x)+sqr(y));
	}
	Point normal() // normal vector
	{
		return Point(-y,x);
	}
	Point unit() // unit vector
	{
		double l=length();
		return Point(x/l,y/l);
	}
	Point rotate(double r)
	{
		return Point(x*cos(r)-y*sin(r),x*sin(r)+y*cos(r));
	}
	Point up()
	{
		Point p(x,y);
		if(y<0)
			x=-x,y=-y;
		return p;
	}
	Point right()
	{
		Point p(x,y);
		if(x<0)
			x=-x,y=-y;
		return p;
	}
};
typedef Point Vector;

int main()
{
	return 0;
}