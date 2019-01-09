# Interval Dynamic Programming



[TOC]



## Contents

| Contents                                  | Time     | Memory   | Code | Test |
| ----------------------------------------- | -------- | -------- | ---- | ---- |
| Longest Palindromic Subsequence (LPS)     | $O(N^2)$ | $O(N)$   | OK!  |      |
| Number of Palindromic Subsequence         | $O(N^2)$ | $O(N)$   | OK!  |      |
| Regular Brackets Sequence                 | $O(N^3)$ | $O(N^2)$ |      |      |
| Matrix Chain Multiplication (MCM)         | $O(N^3)$ | $O(N^2)$ | OK!  |      |
| Optimal Triangulation                     | $O(N^3)$ | $O(N^2)$ | OK!  |      |
| Stones Merging (basic)                    | $O(N^3)$ | $O(N^2)$ | OK!  | OK!  |
| Stones Merging (quadrilateral inequality) | $O(N^2)$ |          |      |      |
|                                           |          |          |      |      |
|                                           |          |          |      |      |



## Longest Palindromic Subsequence (LPS)

$dp[i][j]: Longest\ Palindromic\ Subsequence\ of\ Interval\ [j,j+i)$

$dp[0][j]=0$

$dp[i][j]=max(dp[i-1][j],dp[i-1][j+1])$

$dp[i][j]=dp[i-2][j+1]+2\ (if\ s[j]==s[j+i-1])$



## Number of Palindromic Subsequence

$dp[i][j]: Number\ of\ Palindromic\ Subsequence\ of\ Interval\ [j,j+i)$

$dp[0][j]=0$

$dp[i][j]=dp[i-1][j]+dp[i-1][j+1]-dp[i-2][j+1]$

$dp[i][j]+=dp[i-2][j+1]+1\ (if\ s[j]==s[j+i-1])$



## Matrix Chain Multiplication (MCM)

$A_i$ -> $(si[i],si[i+1])$

$dp[i][j] : Minimum \ Number \ of \ Operations \  of A_i A_{i+1} \cdots A_{j}$

$dp[i][i]=0$

$dp[i][j]=min(dp[i][k]+dp[k+1][j]+si[i]*si[k+1]*si[j+1])$ , for $i<=k<j$



## Optimal Triangulation

A Convex -> $P_0 P_{1} \cdots P_{n-1}$

$w(i,j,k) : Perimeter \ of \ Triangle \ P_{i} P_{j} P_{k}$

$dp[i][j] : Minimum \ Sum \ of \ w \ of \ Convex \ P_i P_{i+1} \cdots P_{j}$

$dp[i][i+1]=0$

$dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+w(i,j,k))$ , for $i<k<j$



## Stones Merging 

Merge n piles of stones into 1 pile. Each step, merge two adjoining piles to a new pile and the cost is the number of the stones in the new pile. Compute the minimum total cost.

Initially, stone[i] stones in i-th pile.

### Basic

$sum[0]=0$

$sum[i]=\sum_{1}^{i} stone[i]$

$dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+sum[j]-sum[i])$ , for $i<k<j$



### Quadrilateral Inequality