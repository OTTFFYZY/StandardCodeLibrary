#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

const int M=1005;
const double EPS=1e-8;
const double PI=acos(-1.0);

int sgn(double x)
{
	if(x>EPS) return 1;
	if(x<-EPS) return -1;
	return 0;
}

struct Point
{
	double x,y;
	Point(double x=0,double y=0)
		:x(x),y(y){}
	bool operator<(const Point &B) const
	{
		return x==B.x ? y<B.y : x<B.x;
	}
	bool operator==(const Point &B) const
	{
		return x==B.x && y==B.y;
	}
	Point operator+(const Point &B) const
	{
		return Point(x+B.x,y+B.y);
	}
	Point operator-(const Point &B) const
	{
		return Point(x-B.x,y-B.y);
	}
	friend double dot(const Point &A,const Point &B)
	{
		return A.x*B.x+A.y*B.y;
	}
	friend double det(const Point &A,const Point &B)
	{
		return A.x*B.y-A.y*B.x;
	}
};
typedef Point Vector;

int main()
{
	return 0;
}