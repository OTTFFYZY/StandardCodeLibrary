#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef long long LL;

const int BASE = 1000000000;
const int BASE_DIGITS = 9;

struct BigInt 
{
    vector<int> a;
    int sgn;

    BigInt():sgn(1){}
    BigInt(LL v)
    {
        *this = v;
    }
    BigInt(const string &s)
    {
        read(s);
    }

    void operator=(const BigInt &v) 
    {
        sgn = v.sgn; a = v.a;
    }

    void operator=(LL v) 
    {
        sgn=1;
        if(v < 0)
        {
            sgn = -1; v = -v;
        }
        a.clear();
        for (; v > 0; v = v / BASE)
            a.push_back(v % BASE);
    }

    BigInt operator+(const BigInt &v) const 
    {
        if (sgn != v.sgn)
            return *this - (-v);
        BigInt res = v;
        for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) 
        {
            if (i == (int) res.a.size())
                res.a.push_back(0);
            res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
            carry = res.a[i] >= BASE;
            if (carry) res.a[i] -= BASE;
        }
        return res;
    }

    BigInt operator-(const BigInt &v) const 
    {
        if (sgn != v.sgn)
            return *this + (-v);
        if (abs() < v.abs()) 
            return -(v - *this);
        BigInt res = *this;
        for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) 
        {
            res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
            carry = res.a[i] < 0;
            if (carry) res.a[i] += BASE;
        }
        res.trim();
        return res;
    }

    BigInt operator*=(int v) 
    {
        if (v < 0)
            sgn = -sgn, v = -v;
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) 
        {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / BASE);
            a[i] = (int) (cur % BASE);
            //asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(BASE));
        }
        trim();
        return *this;
    }

    BigInt operator*(int v) const 
    {
        BigInt res = *this;
        return res *= v;
    }

    friend pair<BigInt, BigInt> divmod(const BigInt &a1, const BigInt &b1) 
    {
        int norm = BASE / (b1.a.back() + 1);
        BigInt a = a1.abs() * norm;
        BigInt b = b1.abs() * norm;
        BigInt q, r;
        q.a.resize(a.a.size());

        for (int i = a.a.size() - 1; i >= 0; i--) 
        {
            r *= BASE;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long) BASE * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0) r += b, --d;
            q.a[i] = d;
        }

        q.sgn = a1.sgn * b1.sgn;
        r.sgn = a1.sgn;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }

    friend BigInt sqrt(const BigInt &a1) 
    {
        BigInt a = a1;
        while (a.a.empty() || a.a.size() % 2 == 1)
            a.a.push_back(0);

        int n = a.a.size();

        int firstDigit = (int) sqrt((double) a.a[n - 1] * BASE + a.a[n - 2]);
        int norm = BASE / (firstDigit + 1);
        a *= norm;
        a *= norm;
        while (a.a.empty() || a.a.size() % 2 == 1)
            a.a.push_back(0);

        BigInt r = (LL) a.a[n - 1] * BASE + a.a[n - 2];
        firstDigit = (int) sqrt((double) a.a[n - 1] * BASE + a.a[n - 2]);
        int q = firstDigit;
        BigInt res;

        for(int j = n / 2 - 1; j >= 0; j--) 
        {
            for(; ; --q) 
            {
                BigInt r1 = (r - (res * 2 * BASE + q) * q) * BASE * BASE 
                          + (j > 0 ? (LL) a.a[2 * j - 1] * BASE + a.a[2 * j - 2] : 0);
                if (r1 >= 0) 
                {
                    r = r1;
                    break;
                }
            }
            res *= BASE;
            res += q;

            if (j > 0) 
            {
                int d1 = res.a.size() + 2 < r.a.size() ? r.a[res.a.size() + 2] : 0;
                int d2 = res.a.size() + 1 < r.a.size() ? r.a[res.a.size() + 1] : 0;
                int d3 = res.a.size() < r.a.size() ? r.a[res.a.size()] : 0;
                q = ((LL) d1 * BASE * BASE + (LL) d2 * BASE + d3) / (firstDigit * 2);
            }
        }

        res.trim();
        return res / norm;
    }

    BigInt operator/(const BigInt &v) const 
    {
        return divmod(*this, v).first;
    }

    BigInt operator%(const BigInt &v) const 
    {
        return divmod(*this, v).second;
    }

    BigInt operator/=(int v) 
    {
        if (v < 0)
            sgn = -sgn, v = -v;
        for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) 
        {
            LL cur = a[i] + rem * (LL) BASE;
            a[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
        return *this;
    }

    BigInt operator/(int v) const 
    {
        BigInt res = *this;
        return res /= v;
    }

    int operator%(int v) const 
    {
        if (v < 0)
            v = -v;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (LL) BASE) % v;
        return m * sgn;
    }

    BigInt operator+=(const BigInt &v) 
    {
        *this = *this + v;
        return *this;
    }
    BigInt operator-=(const BigInt &v) 
    {
        *this = *this - v;
        return *this;
    }
    BigInt operator*=(const BigInt &v) 
    {
        *this = *this * v;
        return *this;
    }
    BigInt operator/=(const BigInt &v) 
    {
        *this = *this / v;
        return *this;
    }

    bool operator<(const BigInt &v) const 
    {
        if (sgn != v.sgn)
            return sgn < v.sgn;
        if (a.size() != v.a.size())
            return a.size() * sgn < v.a.size() * sgn;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sgn < v.a[i] * sgn;
        return false;
    }
    bool operator>(const BigInt &v) const 
    {
        return v < *this;
    }
    bool operator<=(const BigInt &v) const 
    {
        return !(v < *this);
    }
    bool operator>=(const BigInt &v) const 
    {
        return !(*this < v);
    }
    bool operator==(const BigInt &v) const 
    {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const BigInt &v) const 
    {
        return *this < v || v < *this;
    }

    void trim() 
    {
        while (!a.empty() && !a.back()) a.pop_back();
        if (a.empty()) sgn = 1;
    }

    bool isZero() const 
    {
        return a.empty() || (a.size() == 1 && !a[0]);
    }

    BigInt operator-() const 
    {
        BigInt res = *this;
        res.sgn = -sgn;
        return res;
    }

    BigInt abs() const {
        BigInt res = *this;
        res.sgn = 1;
        return res;
    }

    LL longValue() const 
    {
        LL res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * BASE + a[i];
        return res * sgn;
    }

    friend BigInt gcd(const BigInt &a, const BigInt &b) 
    {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend BigInt lcm(const BigInt &a, const BigInt &b) 
    {
        return a / gcd(a, b) * b;
    }

    void read(const string &s) 
    {
        sgn = 1;
        a.clear();
        int pos = 0;
        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) 
        {
            if (s[pos] == '-')
                sgn = -sgn;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= BASE_DIGITS) 
        {
            int x = 0;
            for (int j = max(pos, i - BASE_DIGITS + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }

    friend istream& operator>>(istream &stream, BigInt &v) 
    {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream& operator<<(ostream &stream, const BigInt &v) 
    {
        if (v.sgn == -1 && !v.isZero())
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            stream << setw(BASE_DIGITS) << setfill('0') << v.a[i];
        return stream;
    }

    static vector<int> convert_BASE(const vector<int> &a, int old_digits, int new_digits) 
    {
        vector<LL> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        LL cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) 
        {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }

    typedef vector<LL> VLL;

    static VLL karatsubaMultiply(const VLL &a, const VLL &b) 
    {
        int n = a.size();
        VLL res(n + n);
        if (n <= 32) 
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        VLL a1(a.begin(), a.begin() + k);
        VLL a2(a.begin() + k, a.end());
        VLL b1(b.begin(), b.begin() + k);
        VLL b2(b.begin() + k, b.end());

        VLL a1b1 = karatsubaMultiply(a1, b1);
        VLL a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        VLL r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }

    BigInt operator*(const BigInt &v) const //O(n^log(3))
    {
        vector<int> a6 = convert_BASE(this->a, BASE_DIGITS, 6);
        vector<int> b6 = convert_BASE(v.a, BASE_DIGITS, 6);
        VLL a(a6.begin(), a6.end());
        VLL b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        VLL c = karatsubaMultiply(a, b);
        BigInt res;
        res.sgn = sgn * v.sgn;
        for (int i = 0, carry = 0; i < (int) c.size(); i++) 
        {
            LL cur = c[i] + carry;
            res.a.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.a = convert_BASE(res.a, 6, BASE_DIGITS);
        res.trim();
        return res;
    }
};

int main()
{

    return 0;
}