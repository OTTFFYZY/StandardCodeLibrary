# Number Theory



[TOC]



## Contents

| Contents                           | Time          | Memory    | Code | Test |
| ---------------------------------- | ------------- | --------- | ---- | ---- |
| Modular Operator (+, -, *, ^, mod) | $/$           | $/$       | OK!  |      |
| GCD & LCM (Euclid Method)          | $O(logN)$     | $/$       | OK!  |      |
| Extend Euclid                      | $O(logN)$     | $O(1)$    | OK!  | OK!  |
| Inverse Element / Modular Division | $O(logN)$     | $O(1)$    | OK!  |      |
| Prime Table (basic, bitmap)        | $O(NloglogN)$ | $O(N)$    | OK!  |      |
| Is Prime (basic)                   | $O(\sqrt{N})$ | $O(1)$    | OK!  |      |
| Is Prime (Miller-Robin)            |               |           |      |      |
| Factorization (basic)              | $O(\sqrt{N})$ | $O(logN)$ | OK!  |      |
| Factorization (Pollard-Rho)        |               |           |      |      |
| Factorization Table                | $O(NloglogN)$ | $O(N)$    |      |      |
| Phi Function / Phi Table           |               |           |      |      |
| Power Reduction Formula            |               |           |      |      |
| Chinese Remainder Theory           |               |           |      |      |
| Modular Linear Equations           |               |           |      |      |
| Lucas Theory / Extend Lucas Theory |               |           |      |      |
|                                    |               |           |      |      |





## Modular Operator

1.  $(a + b)\%M = ((a\%M) + (b\%M))\%M$
2.  $(a-b)\%M=((a\%M)+M-(b\%M))\%M$
3.  $(ab)\%M = ((a\%M) \dot (b\%M))\%M$
4.  mod: $(a\%M+M)\%M$
5.  $\frac{a}{b} \% M=\frac{a \% (bM)}{b}$



## Euclid & Extend Euclid





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



### Fermat's Little Theorem

M is a prime

$\begin{align} a^{M-1}&\equiv1&(mod\ M)\\1&\equiv a^{M-1}&(mod\ M) \\ a^{-1}&\equiv a^{M-2} &(mod\ M)\end{align}$



### Euler Theorem

$gcd(a,n)=1$

$\begin{align} a^{\varphi(M)}&\equiv1&(mod\ M)\\1&\equiv a^{\varphi(M)}&(mod\ M) \\ a^{-1}&\equiv a^{\varphi(M)-1} &(mod\ M)\end{align}$