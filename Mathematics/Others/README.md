# Others



[TOC]



## Contents

| Contents                    | Time              | Memory   | Code | Test |
| --------------------------- | ----------------- | -------- | ---- | ---- |
| Generate Palindromic Number | $O(N_B \sqrt{N})$ | $O(1)$   | OK!  | OK!  |
| Expression (polynomial)     | $/$               | $O(N^2)$ | OK!  | OK!  |
| Digit Sum                   | $O(1)$            | $O(1)$   | OK!  |      |
|                             |                   |          |      |      |
|                             |                   |          |      |      |



## Digit Sum

Get the sum of digits of a number recursively, until there is a single digit.

$ans=\left\{
\begin{aligned} 0 &\quad ,n=0 \\ 9 &\quad ,n\%9=0\\ n\%9 & \quad, otherwise \end{aligned}
\right.$



$ N=a_0 \cdot 10^0 + a_1 \cdot 10^1 + a_2 \cdot 10^2 + a_k \cdot 10^k $

$\because 10^i \% 9 = 1$

$(\sum_{i=0}^{k} a_i)\%9 = \sum a_i \cdot 10^i \% 9 = N \% 9$

If $N>0$ , $ans>0$ 

So, if $N\%9=0$ , $ans=9$