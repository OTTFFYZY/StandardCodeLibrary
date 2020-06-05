#include <bits/stdc++.h>
using namespace std;

namespace CG
{
	/*=======*\
	|  Basic  |
	\*=======*/ 
	const double EPS=1e-8;
	const double PI=acos(-1.0);

	inline int sgn(double x) { return (x>EPS)-(x<-EPS); }
	inline double sqr(double x) { return x*x; }

	/*=======*\
	|  Point  |
	\*=======*/ 
	struct Point
	{
		double x,y;
		Point(double x=0.0,double y=0.0) :x(x),y(y) {}
		void read() { scanf("%lf%lf",&x,&y); }
		void print() { printf("(%f, %f)",x,y); }

		Point operator+(const Point &B) const { return Point(x+B.x,y+B.y); }
		Point operator-(const Point &B) const { return Point(x-B.x,y-B.y); }
		Point operator*(double d) const { return Point(x*d,y*d); }
		Point operator/(double d) const { return Point(x/d,y/d); }
		Point operator-() const { return Point(-x,-y); }
		
		double operator*(const Point &B) const { return x*B.x+y*B.y; } // dot
		double operator^(const Point &B) const { return x*B.y-y*B.x; } // det

		double len() const { return sqrt(sqr(x)+sqr(y)); }
		double len2() const { return x*x+y*y; }
		void norm() { double l=len(); x/=l; y/=l; }
		Point get_norm() const { double l=len(); return Point(x/l,y/l); }

		double polar() const { return atan2(y,x); } // [-PI,PI)
		int quad() const { return sgn(y)==1 || (sgn(y)==0 && sgn(x)>=0); }
		bool operator<(const Point &B) const
		{ return quad()!=B.quad() ? quad()<B.quad() : sgn(*this^B)==-1; }

		// sort by pair
		// bool operator<(const Point &B) const 
		// { return sgn(x-B.x) ? sgn(x-B.x)<0 : sgn(y-B.y)<0; }

		Point rotate(double A) const { return Point(x*cos(A)-y*sin(A), x*sin(A)+y*cos(A)); }
		Point rotate90() const { return Point(-y,x); }
	};
	double dis(const Point &a,const Point &b) { return (a-b).len(); }

	Point mid(const Point &a,const Point &b) { return Point((a.x+b.x)/2.0,(a.y+b.y)/2.0); }
	Point symmetry(const Point &o,const Point &a) { return o*2-a; } // o is the center

	Point rotate(const Point &o,const Point &a,double A) { return (a-o).rotate(A)+o; }

	// get <a,b>
	Point rad(const Point &a,const Point &b) { return atan2l(a^b,a*b); } 

	/*================*\
	|  Line & Segmemt  |
	\*================*/
	double cross(const Point &o,const Point &a,const Point &b)
	{ return (a-o)^(b-o); }
	double cross_sgn(const Point &o,const Point &a,const Point &b) 
	{ return sgn((a-o)^(b-o)); }

	struct Line
	{
		Point a,b;
		Line(double xa=0.0,double ya=0.0,double xb=0.0,double yb=0.0)
			:a(xa,ya),b(xb,yb) {}
		Line(Point a,Point b) :a(a),b(b) {}
		void read() { scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y); }
		void print() { printf("[(%f, %f), (%f, %f)]",a.x,a.y,b.x,b.y); }

		bool operator==(const Line &B) const
		{ return cross_sgn(a,b,B.a)==0 && cross_sgn(a,b,B.b)==0; }

		// 1-d p on [l,r] or [r,l] seg
		bool on_seg(double l,double r,double p) const
		{ return sgn(l-p)==0 || sgn(r-p)==0 || (l<p)!=(r<p); }
		// check p on Line a,b
		bool on_line(const Point &p) const
		{ return cross_sgn(a,b,p)==0; }
		// check p on segment a,b;
		bool on_seg(const Point &p) const
		{ return cross_sgn(a,b,p)==0 && on_seg(a.x,b.x,p.x) && on_seg(a.y,b.y,p.y); }
		bool on_seg_strict(const Point &p) const
		{
			return cross_sgn(a,b,p)==0
				&& sgn((p-a)*(a-b))*sgn((p-b)*(a-b)) < 0;
		}

		// make a project of p on line
		Point proj(const Point &p) const
		{
			Point dir=b-a;
			return a+dir*(dir*(p-a))/dir.len2();
		}
		Point reflect(const Point &p) const { return proj(p)*2-p; }
		double point_line_dis(const Point &p) const { return dis(p,proj(p)); }

		// min distance between point and segment
		double point_seg_dis(const Point &p) const
		{
			Point q=proj(p);
			// if(on_seg(a.x,b.x,q.x)&&on_seg(a.y,b.y,q.y)) return dis(p,q);
			if(on_seg(q)) return dis(p,q);
			return min(dis(a,q),dis(b,q));
		}
		
	};
	// parallel or same
	bool parallel(const Line &l1,const Line &l2) { return sgn((l1.b-l1.a)^(l2.b-l2.a))==0; }
	// check non-parallel first
	// line line intersection
	Point ll_intersection(const Line &l1,const Line &l2)
	{
		double sa=cross(l2.a,l2.b,l1.a), sb=-cross(l2.a,l2.b,l1.b);
		return (l1.a*sb+l1.b*sa)/(sa+sb);
	}

	// segment intersection
	// 1-d intervals intersection
	bool intersection(double l1,double r1,double l2,double r2)
	{
		if(l1>r1) swap(l1,r1); 
		if(l2>r2) swap(l2,r2);
		return sgn(r1-l2)>=0 && sgn(r2-l1)>=0;
	}
	bool is_ss_intersection(const Line &l1,const Line &l2)
	{
		return intersection(l1.a.x,l1.b.x,l2.a.x,l2.b.x)
			&& intersection(l1.a.y,l1.b.y,l2.a.y,l2.b.y)
			&& cross_sgn(l1.a,l1.b,l2.a)*cross_sgn(l1.a,l1.b,l2.b)<=0
			&& cross_sgn(l2.a,l2.b,l1.a)*cross_sgn(l2.a,l2.b,l1.b)<=0;
	}
	bool is_ss_strict_intersection(const Line &l1,const Line &l2)
	{
		return cross_sgn(l1.a,l1.b,l2.a)*cross_sgn(l1.a,l1.b,l2.b)<0
			&& cross_sgn(l2.a,l2.b,l1.a)*cross_sgn(l2.a,l2.b,l1.b)<0;
	}

	// min distance between segment and segment
	double seg_seg_dis(const Line &s1,const Line &s2)
	{
		if(is_ss_intersection(s1,s2)) return 0;
		return min(min(s1.point_seg_dis(s2.a),s1.point_seg_dis(s2.b)),
				   min(s2.point_seg_dis(s1.a),s2.point_seg_dis(s1.b)));
	}
}
using namespace CG;

int main()
{
	
	return 0;
}