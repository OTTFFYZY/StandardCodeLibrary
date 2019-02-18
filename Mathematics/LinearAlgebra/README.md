# Linear Algebra



[TOC]



## Contents

| Contents                          | Time                | Memory     | Code | Test |
| --------------------------------- | ------------------- | ---------- | ---- | ---- |
| Matrix Class                      | $/$                 | $O(N^2)$   | OK!  |      |
| Matrix Multiplication (block)     | $O(N^3)$            | $O(N^2)$   | OK!  |      |
| Sparse Matrix Multiplication      | $O(N^3)$            | $O(N^2)$   | OK!  |      |
| Matrix Multiplication Application | $O(N^3)$            | $O(N^2)$   |      |      |
| Fibonacci / Recursion             | $O(N_m^3logN_n)$    | $O(N_m^2)$ | OK!  |      |
| Circulant Matrix Multiplication   | $O(N^2)$            | $O(N)$     | OK!  | OK!  |
| Upper Triangularization           | $O(N^3)$            | $O(N)$     | OK!  |      |
| Gauss Elimination (basic)         | $O(N_cN_r^2)$       | $O(N^2)$   | OK!  |      |
| Gauss Elimination (Gauss-Jordan)  | $O(N_cN_r^2)$       | $O(N^2)$   | OK!  |      |
| Gauss Elimination (xor)           | $O(N_cN_r^2/W)$     | $O(N^2/W)$ | OK!  |      |
| Gauss Elimination (modular)       | $O(N_cN_r^2)$       | $O(N^2)$   |      |      |
| Gauss Elimination (int)           | $O(N_cN_r^2logN_n)$ | $O(N^2)$   |      |      |
| Linear Basis                      | $O(N_BN^2)$         | $O(N)$     | OK!  |      |
| Determinant                       | $O(N^3)$            | $O(N^2)$   | OK!  |      |
|                                   |                     |            |      |      |



## Fibonacci / Recursion

$f(m)=a_0f(0)+a_1f(1)+a_2f(2)+...+a_{m-1}f(m-1)$

$f(n)=a_0f(n-m)+a_1f(n-m+1)+a_2f(n-m+2)+...+a_{n-1}f(n-1)$

$A_{0} = \begin{bmatrix}f(0) \\ f(1) \\ f(2) \\ \vdots \\ f(m-1) \end{bmatrix} $

$B = \begin{bmatrix} 0 & 1  & 0  & \dots & 0 \\ 0  & 0 & 1 & \dots & 0 \\ \vdots  &  & & \ddots &  0 \\ 0 & \dots & & \dots & 1 \\ a_{0}  & a_{1}  & a_{2} & \dots & a_{m-1} \end{bmatrix} $

$A_{i} = \begin{bmatrix}f(i) \\ f(i+1) \\ f(i+2) \\ \vdots \\ f(i+m-1) \end{bmatrix} $

$\begin{bmatrix}f(1) \\ f(2) \\ f(3) \\ \vdots \\ f(m) \end{bmatrix}= \begin{bmatrix} 0 & 1  & 0  & \dots & 0 \\ 0  & 0 & 1 & \dots & 0 \\ \vdots  &  & & \ddots &  0 \\ 0 & \dots & & \dots & 1 \\ a_{0}  & a_{1}  & a_{2} & \dots & a_{m-1} \end{bmatrix} \begin{bmatrix}f(0) \\ f(1) \\ f(2) \\ \vdots \\ f(m-1) \end{bmatrix}$

$A_1 = B A_0$ , $A_i = B A_{i-1}$

$A_2=BA_1=B B A_0$

$ A_n=B^n A_0 $

$A^{'}_{0} = \begin{bmatrix}f(0) & 0 & \dots & 0\\ f(1) & 0 & \dots & 0 \\ f(2) & 0 & \dots & 0 \\ \vdots & \vdots & \ddots & \vdots \\ f(m-1) & 0 & \dots & 0\end{bmatrix}_{m \times m} $

$A^{'}_{i} = \begin{bmatrix}f(i) & 0 & \dots & 0\\ f(i+1) & 0 & \dots & 0 \\ f(i+2) & 0 & \dots & 0 \\ \vdots & \vdots & \ddots & \vdots \\ f(i+m-1) & 0 & \dots & 0\end{bmatrix}_{m \times m}$

 $ A^{'}_n=B^n A^{'}_{0} $

$ f(n) = A^{'}_n(i,j)$



### Problem

lrjb: UVA10870 





## Circulant Matrix Multiplication

Circulant Matrix A and B:

$A=\begin{bmatrix} a_{0}  & a_{1}  & a_{2} & \dots & a_{m-1} \\ a_{m-1}  & a_{0}  & a_{1} & \dots & a_{m-2} \\ a_{m-2}  & a_{m-1}  & a_{0} & \dots & a_{m-3} \\ \vdots  &   &  & \ddots & \vdots \\ a_{1}  & a_{2}  & a_{3} & \dots & a_{0} \end{bmatrix}_{m \times m}$

$B=\begin{bmatrix} b_{0}  & b_{1}  & b_{2} & \dots & b_{m-1} \\ b_{m-1}  & b_{0}  & b_{1} & \dots & b_{m-2} \\ b_{m-2}  & b_{m-1}  & b_{0} & \dots & b_{m-3} \\ \vdots  &   &  & \ddots & \vdots \\ b_{1}  & b_{2}  & b_{3} & \dots & b_{0} \end{bmatrix}_{m \times m}$



$(AB)_{0j}=\sum\limits_{i=0}^{m-1}{a_i}{b_{(j-i+m)\%m}}$

$(AB)_{1j}=\sum\limits_{i=0}^{m-1}{a_{(i-1+m)\%m}}{b_{(j-i+m)\%m}}​$

$(AB)_{2j}=\sum\limits_{i=0}^{m-1}{a_{(i-2+m)\%m}}{b_{(j-i+m)\%m}}$

$\begin{align} (AB)_{ij} & =\sum\limits_{k=0}^{m-1}{a_{(k-i+m)\%m}}{b_{(j-k+m)\%m}} \\ & = a_{m-i}b_{j}+ a_{(m-i+1)\%m}b_{(j-1+m)\%m} + a_{(m-i+2)\%m}b_{(j-2+m)\%m} +\dots+a_{(m-1-i)\%m}b_{(j+1)\%m}\end{align}$

$\begin{align} (AB)_{(i-1+m)\%m,(j-1+m)\%m} & =\sum\limits_{k=0}^{m-1}{a_{(k-i+1+m)\%m}}{b_{(j-1-k+m)\%m}} \\ & = a_{(m-i+1)\%m}b_{(j-1+m)\%m}+a_{(m-i+2)\%m}b_{(j-2+m)\%m} +\dots+a_{(m-1-i)\%m}b_{(j+1)\%m}+a_{m-i}b_j \end{align}$

$(AB)_{ij}=(AB)_{(i-1+m)\%m,(j-1+m)\%m}$

Matrix AB is also a Circulant Matrix.

$A_{ij}=A_{0,(j-i+n)\%n}$



### Problem

lrjb: LA3704*





## Gauss Elimination



## Linear Basis

