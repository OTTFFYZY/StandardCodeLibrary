#include <iostream>

typedef unsigned long long ULL;

ULL BKDR_hash(char str[])
{
	register ULL hash=0;
	ULL ch;
	while(ch=(ULL)*str++)
		hash=hash*131+ch;
	//  hash=(hash<<7)+(hash<<1)+hash+ch;
	return hash;
}

ULL SDBM_hash(char str[])
{
	register ULL hash=0;
	ULL ch;
	while(ch=(ULL)*str++)
		hash=hash*65599+ch;
	//  hash=(hash<<6)+(hash<<16)-hash+ch;
	return hash;
}

ULL RS_hash(char str[])
{
	register ULL hash=0;
	ULL magic=63689,ch;
	while(ch=(ULL)*str++)
	{
		hash=hash*magic+ch;
		magic*=378551;
	}
	return hash;
}

ULL AP_hash(char str[])
{
	register ULL hash=0;
	ULL ch;
	for(int i=0;ch=(ULL)*str++;i^=1)
	{
		if(i)
			hash^=(~((hash<<11)^ch^(hash>>5)));
		else
			hash^=((hash<<7)^ch^(hash>>3)); 
	}
	return hash;
}

ULL JS_hash(char str[])
{
	register ULL hash=1315423911L;
	ULL ch;
	while(ch=(ULL)*str++)
		hash^=((hash<<5)+ch+(hash>>2));
	return hash;
}

ULL DEK_hash(char str[])
{
	register ULL hash=1315423911L;
	ULL ch;
	while(ch=(ULL)*str++)
		hash=((hash<<5)^(hash>>27))^ch;
	return hash;
}

ULL FNV_hash(char str[])
{
	register ULL hash=2166136261L;
	ULL ch;
	while(ch=(ULL)*str++)
	{
		hash*=16777619;  
        hash^=ch;  
	}
	return hash;
}

ULL DJB_hash(char str[])
{
	register ULL hash=5381;
	ULL ch;
	while(ch=*str++)
		hash+=(hash<<5)+ch;
	return hash;
}

ULL DJB2_hash(char str[])
{
	register ULL hash=5381;
	ULL ch;
	while(ch=*str++)
		hash+=(hash<<5)+ch;
	return hash;
}

ULL PJW_hash(char str[])
{
	static const ULL TotalBits     =sizeof(ULL)*8;  
    static const ULL ThreeQuarters =(TotalBits*3)/4;  
    static const ULL OneEighth     =TotalBits/8;  
    static const ULL HighBits      =((ULL)-1)<<(TotalBits-OneEighth);      
    register ULL hash=0;  
    ULL magic=0;
    while (ULL ch=(ULL)*str++)  
    {  
        hash=(hash<<OneEighth)+ch;  
        if ((magic=hash&HighBits)!=0)  
            hash=((hash^(magic>>ThreeQuarters))&(~HighBits));  
    }  
    return hash;  
}

ULL ELFHash(char str[])  
{  
    static const ULL TotalBits     =sizeof(ULL)*8;  
    static const ULL ThreeQuarters =(TotalBits*3)/4;  
    static const ULL OneEighth     =TotalBits/8;  
    static const ULL HighBits      =((ULL)-1)<<(TotalBits-OneEighth);      
    register ULL hash=0;
    ULL magic=0;  
    while (ULL ch=(ULL)*str++)  
    {  
        hash=(hash<<OneEighth)+ch;  
        if ((magic=hash&HighBits)!=0)  
        {  
            hash^=(magic>>ThreeQuarters);  
            hash&=~magic;  
        }         
    }  
    return hash;  
}  

int main()
{
	return 0;
}