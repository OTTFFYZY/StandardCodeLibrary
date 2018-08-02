# Linear Algebra



[TOC]



## Contents

| Contents                 | Time          | Memory     | Code | Test |
| ------------------------ | ------------- | ---------- | ---- | ---- |
| Matrix Class             | $/$           | $O(N^2)$   | OK!  |      |
| Matrix Multiplication () |               |            |      |      |
| Fibonacci / Recursion    | $N_m^3logN_n$ | $O(N_m^2)$ | OK!  |      |
| Guess Elimination        | $O(N^3)$      | $O(N^2)$   |      |      |
|                          |               |            |      |      |
|                          |               |            |      |      |
|                          |               |            |      |      |



## Fibonacci / Recursion

$f(m)=a_0f(0)+a_1f(1)+a_2f(2)+...+a_{m-1}f(m-1)$

$f(n)=a_0f(n-m)+a_1f(n-m+1)+a_2f(n-m+2)+...+a_{n-1}f(n-1)$

$\begin{bmatrix}f(n) \\ f(n-1) \\ f(n-2) \\ \vdots \\ f(n-m+1) \end{bmatrix} = \begin{bmatrix}a_{m-1}  & a_{m-2}  & a_{m-3} & \dots & a_0 \\ 1  & 0 & 0 & \dots & 0 \\ 0  & 1 & 0& \dots & 0 \\ \vdots  &  & \ddots &  & 0 \\ 0 & \dots & & 1 & 0\end{bmatrix} \begin{bmatrix}f(n-1) \\ f(n-2) \\ f(n-3) \\ \vdots \\ f(n-m) \end{bmatrix}$

$\begin{bmatrix}f(n) \\ f(n-1) \\ f(n-2) \\ \vdots \\ f(n-m+1) \end{bmatrix} = \begin{bmatrix}a_{m-1}  & a_{m-2}  & a_{m-3} & \dots & a_0 \\ 1  & 0 & 0 & \dots & 0 \\ 0  & 1 & 0& \dots & 0 \\ \vdots  &  & \ddots &  & 0 \\ 0 & \dots & & 1 & 0\end{bmatrix} ^{n-m+1} \begin{bmatrix}f(m-1) \\ f(m-2) \\ f(m-3) \\ \vdots \\ f(0) \end{bmatrix}$

