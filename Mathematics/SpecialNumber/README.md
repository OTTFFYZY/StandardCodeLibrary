# Special Number



[TOC]



## Contents

| Contents             | Time | Memory | Code | Test |
| -------------------- | ---- | ------ | ---- | ---- |
| Big Integer (array)  | $/$  | $/$    |      |      |
| Big Integer (vector) | $/$  | $/$    | OK!  |      |
| Fraction             |      |        |      |      |
|                      |      |        |      |      |
|                      |      |        |      |      |
|                      |      |        |      |      |



## Big Integer

### Big Integer (vector)

```c++
typedef long long LL;
const int BASE = 1000000000;
const int BASE_DIGITS = 9;
struct BigInt 
{
    vector<int> a;
    int sgn;

    BigInt():sgn(1){}
    BigInt(LL v);
    BigInt(const string &s);

    void operator=(const BigInt &v);
    void operator=(LL v);

    BigInt operator+(const BigInt &v) const;
    BigInt operator-(const BigInt &v) const;

    BigInt operator*=(int v);
    BigInt operator*(int v) const;

    friend pair<BigInt, BigInt> divmod(const BigInt &a1, const BigInt &b1);
    
    friend BigInt sqrt(const BigInt &a1);
    
    BigInt operator/(const BigInt &v) const;
    BigInt operator%(const BigInt &v) const;
    BigInt operator/=(int v);
    BigInt operator/(int v) const;
    int operator%(int v) const;

    BigInt operator+=(const BigInt &v);
    BigInt operator-=(const BigInt &v);
    BigInt operator*=(const BigInt &v);
    BigInt operator/=(const BigInt &v);

    bool operator<(const BigInt &v) const;
    bool operator>(const BigInt &v) const;
    bool operator<=(const BigInt &v) const;
    bool operator>=(const BigInt &v) const;
    bool operator==(const BigInt &v) const;
    bool operator!=(const BigInt &v) const;

    void trim();
    bool isZero() const;
    BigInt operator-() const;
    BigInt abs() const;
    LL longValue() const;
    friend BigInt gcd(const BigInt &a, const BigInt &b);
    friend BigInt lcm(const BigInt &a, const BigInt &b);

    void read(const string &s);
    friend istream& operator>>(istream &stream, BigInt &v);
    friend ostream& operator<<(ostream &stream, const BigInt &v);
    BigInt operator*(const BigInt &v) const;
};
```

