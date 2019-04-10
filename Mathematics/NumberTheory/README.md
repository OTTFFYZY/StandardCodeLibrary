# Number Theory



[TOC]



## Contents

| Contents                           | Time                | Memory      | Code | Test |
| ---------------------------------- | ------------------- | ----------- | ---- | ---- |
| Modular Operator (+, -, *, ^, mod) | $/$                 | $/$         | OK!  | OK!  |
| GCD & LCM (Euclid Method)          | $O(\log N)$         | $/$         | OK!  |      |
| Extend Euclid                      | $O(\log N)$         | $O(1)$      | OK!  | OK!  |
| Inverse Element / Modular Division | $O(\log N)$         | $O(1)$      | OK!  |      |
| Prime Table (basic, bitmap)        | $O(N \log(\log N))$ | $O(N)$      | OK!  |      |
| Is Prime (basic)                   | $O(\sqrt{N})$       | $O(1)$      | OK!  |      |
| Is Prime (Miller-Robin)            | $O(N_T \log N_N)$   | $O(1)$      | OK!  |      |
| Factorization (basic)              | $O(\sqrt{N})$       | $O(\log N)$ | OK!  | OK!  |
| Factorization (Pollard-Rho)        |                     |             |      |      |
| Factorization Table                | $O(N)$              | $O(N)$      | OK!  | OK!  |
| Phi Function $\varphi(x)$          | $O(\sqrt{N})$       | $O(1)$      | OK!  |      |
| Phi Table                          | $O(N \log(\log N))$ | $O(N)$      | OK!  |      |
| Power Reduction Formula            | $O(N_L+\sqrt{N_M})$ | $O(1)$      | OK!  | OK!  |
| Chinese Remainder Theory           | $O(N \log N)$       | $O(1)$      | OK!  |      |
| Modular Linear Equations           |                     |             |      |      |
| Modular Combinatorial Number       | $/$                 | $/$         | OK!  |      |
| Lucas Theory / Extend Lucas Theory |                     |             |      |      |
| Linear Sieve (prime, phi, mu)      | $O(N)$              | $O(N)$      | OK！ |      |
| Mobius Inversion                   |                     |             |      |      |
| Pell Function                      |                     |             |      |      |
|                                    |                     |             |      |      |





## Modular Operator

1.  $(a + b)\%M = ((a\%M) + (b\%M))\%M$
2.  $(a-b)\%M=((a\%M)+M-(b\%M))\%M$
3.  $(ab)\%M = ((a\%M) \dot (b\%M))\%M$
4.  mod: $(a\%M+M)\%M$
5.  $\frac{a}{b} \% M=\frac{a \% (bM)}{b}$



## GCD LCM & Euclid & Extend Euclid

gcd -> greatest common divisor

lcm -> least common multiple



$A=p_{1}^{a_1}\cdot p_{2}^{a_2}\cdots p_{k}^{a_k}$

$B=p_{1}^{b_1}\cdot p_{2}^{b_2}\cdots p_{k}^{b_k}$

$gcd(A,B)=p_{1}^{min(a_1,b_1)}\cdot p_{2}^{min(a_2,b_2)}\cdots p_{k}^{min(a_k,b_k)}$

$lcm(A,B)=p_{1}^{max(a_1,b_1)}\cdot p_{2}^{max(a_2,b_2)}\cdots p_{k}^{max(a_k,b_k)}$

$gcd(A,B)lcm(A,B)=AB$



$gcd(a,b)=gcd(b,a\%b)$

$gcd(a,0)=a$



### Extend Euclid

$ax+by=c=gcd(a,b)$

$\begin{align} gcd(a,b)&=c=ax+by \\ gcd(b,a\%b)&=c=ax+by \\ \end{align}$



## Inverse Element

$ab\equiv1(mod\ m)$

$a^{-1}\equiv b(mod\ m)$

### Using Extend Euclid Algorithm

$ab\equiv1(mod\ m)$ 

$ab+mk=1 => exgcd\ b$



### Inverse Element Table

M is a prime, $a<M$

$a^{-1}\equiv (M-\lfloor\frac{M}{a}\rfloor)(M\%a)^{-1}(mod\ M)$

$\begin{align}M=ka+r&\equiv0&(mod\ M)\\kr^{-1}+a^{-1}&\equiv0&(mod\ M)\\a^{-1}&\equiv-kr^{-1}&(mod\ M)\\a^{-1}&\equiv M-\lfloor\frac{M}{a}\rfloor(M\%a)^{-1}&(mod\ M)\\a^{-1}&\equiv (M-\lfloor\frac{M}{a}\rfloor)(M\%a)^{-1}&(mod\ M)\end{align}$



### Using Fermat's Little Theorem

M is a prime

$\begin{align} a^{M-1}&\equiv1&(mod\ M)\\1&\equiv a^{M-1}&(mod\ M) \\ a^{-1}&\equiv a^{M-2} &(mod\ M)\end{align}$



### Using Euler Theorem

$gcd(a,n)=1$

$\begin{align} a^{\varphi(M)}&\equiv1&(mod\ M)\\1&\equiv a^{\varphi(M)}&(mod\ M) \\ a^{-1}&\equiv a^{\varphi(M)-1} &(mod\ M)\end{align}$



## Euler Phi Function $\varphi(x)$

$n=p_{1}^{a_1}\cdot p_{2}^{a_2}\cdots p_{k}^{a_k}$

$\begin{align} \varphi(n)=&\sum\limits_{S\subseteq\{p_1,p_2,\cdots ,p_k\}} (-1)^{|S|}\frac{n}{\prod\limits_{p_i\in S}p_i}\\=&n\prod\limits_{i=1}^{k}(1-\frac{1}{p_i}) \end{align}$





## Power Reduction Formula

$A^B \equiv A^{B \% \varphi(C)+\varphi(C)}(mod\ C)\ (B \ge \varphi(C))$



## Modular Combinatorial Number

### $n,m<10^6$



### $m<10^6$



### $p<10^6$



