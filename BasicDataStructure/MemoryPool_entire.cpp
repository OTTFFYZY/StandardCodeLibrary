#include <stdio.h>

template<class T>
struct MemoryPool
{
	T *a,**b; int pa,pb;
	MemoryPool(int MAX)
	{
		a=new T[MAX];
		b=new T*[MAX];
		pa=pb=0;
	}
	T* add()
	{
		T *p=pb?b[--pb]:&a[pa++];
		*p=0; // T is a number
		//p->clear(); T is a class
		return p;
	}
	void del(T *x)
	{ 
		b[pb++]=x; 
	}
	int idx(T *x)
	{
		return x-a;
	}
};
MemoryPool<int> mp(5);

int main()
{
	return 0;
}