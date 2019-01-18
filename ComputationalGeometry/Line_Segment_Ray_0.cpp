#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;
const int M=1005;

/*================================*\
|                                  |
|  0.basic                         |
|                                  |
\*================================*/

const double EPS=1e-8;
const double PI=acos(-1.0);

inline int sgn(double x)
{
	return (x>EPS)-(x<-EPS);
}

inline double sqr(double x)
{
	return x*x;
}

/*================================*\
|                                  |
|  1.Point & Vector                |
|  2.Line & Seg & Ray              |
|                                  |
\*================================*/

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
	Point operator-() const
	{
		return Point(-x,-y);
	}
	friend double dot(const Point &A,const Point &B) //dot product
	{
		return A.x*B.x+A.y*B.y;
	}
	friend double det(const Point &A,const Point &B) //cross product
	{
		return A.x*B.y-A.y*B.x;
	}
	friend double dis(const Point &A,const Point &B)
	{
		return (A-B).length();
	}
	double dis(const Point &B)
	{
		return (*this-B).length();
	}
	double det3(const Point &B,const Point &C) const
	{
		// return det(B-*this,C-*this);
		return (B.x-x)*(C.y-y)-(B.y-y)*(C.x-x);
	}
	double dot3(const Point &B,const Point &C) const
	{
		// return dot(B-*this,C-*this);
		return (B.x-x)*(C.x-x)+(B.y-y)*(C.y-y);
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
	Point rotate(double r) // rotate r rad around origin
	{
		return Point(x*cos(r)-y*sin(r),x*sin(r)+y*cos(r));
	}
	Point rotate(const Point &o,double r) // rotate r rad around o
	{
		return (*this-o).rotate(r)+o;
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

	friend Point lineIntersection
		(const Point &a,const Point &b,const Point &c,const Point &d)
	{
		double u=a.det3(b,c),v=b.det3(a,d);
		return Point((c.x*v+d.x*u)/(u+v),(c.y*v+d.y*u)/(u+v));
	}
	bool onLine(const Point &b,const Point &c) const
	{
		return !sgn(det3(b,c));
	}
	double toLine(const Point &b,const Point &c) const
	{
		return fabs(det3(b,c)) / dis(b,c);
	}
	
	bool onSeg(const Point &b,const Point &c) const
	{
		return !sgn(det3(b,c)) 
		      &&sgn(dot3(b,c))<=0;
	}
	bool inSeg(const Point &b,const Point &c) const
	{   // without endpoint
		return !sgn(det3(b,c)) 
		      &&sgn(dot3(b,c))<0;
	}
	double toSeg(const Point &b,const Point &c) const
	{
		Point d=*this+(b-c).normal(); // ad bc
		Point p=lineIntersection(*this,d,b,c);
		if(p.onSeg(b,c)) 
			return dis(p);
		return min(dis(b),dis(c));
	}

	double onRay(const point &p,const Point &v) const
	{
		return !sgn(det3(p,p+v)) && sgn(dot(*this-p,v))>=0;
	}
	bool onLeft(const Point &p,const Point &v) const
	{
		return sgn(det(*this-p,v))>0;
	}
};
// typedef Point Vector;

bool isLineSame(const Point &a,const Point &b,const Point &c,const Point &d)
{
	return c.onSeg(a,b) && d.onSeg(a,b);
}

bool isParallel(const Point &a,const Point &b,const Point &c,const Point &d)
{
	//return !sgn(det(b-a,d-c));
	return !isSame(a,b,c,d) && !sgn(det(b-a,d-c));
}
bool isLineIntersection(const Point &a,const Point &b,const Point &c,const Point &d)
{
	return sgn(det(b-a,d-c));
}
bool isSegIntersection(const Point &a,const Point &b,const Point &c,const Point &d)
{
	// with endpoint
	// return !isParallel(a,b,c,d)
	//	    &&sgn(a.det3(b,c)*a.det3(b,d))<=0
	//	    &&sgn(c.det3(d,a)*c.det3(d,b))<=0;
	// without endpoint
	return sgn(a.det3(b,c)*a.det3(b,d))<0
		 &&sgn(c.det3(d,a)*c.det3(d,b))<0;
}

struct Line
{
	Point a,b;
	Line(double xa=0,double ya=0,double xb=0,double yb=0)
		:a(xa,ya),b(xb,yb){}
	Line(const Point &a,const Point &b)
		:a(a),b(b){}
};

int main()
{
	return 0;
}