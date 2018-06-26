typedef unsigned int UINT;

const UINT M=1e7;
const UINT MASK=32;
const UINT SHIFT=5; //2^5=32
UNIT bitmap[(M>>SHIFT)+5];

inline void setbit(UINT n)
{
	bitmap[n>>SHIFT]|=1U<<(n&MASK);
}
inline bool getbit(UINT n)
{
	return bitmap[n>>SHIFT]&(1U<<(n&MASK));
}
inline void delbit(UINT n)
{
	bitmap[n>>SHIFT]&=~(1U<<(n&MASK));
}