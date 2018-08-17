# Interval Dynamic Programming



[TOC]



## Contents

| Contents                              | Time     | Memory | Code | Test |
| ------------------------------------- | -------- | ------ | ---- | ---- |
| Longest Palindromic Subsequence (LPS) | $O(N^2)$ | $O(N)$ | OK!  |      |
| Number of Palindromic Subsequence     | $O(N^2)$ | $O(N)$ | OK!  |      |
|                                       |          |        |      |      |
|                                       |          |        |      |      |
|                                       |          |        |      |      |



## Longest Palindromic Subsequence (LPS)

$dp[i][j]: Longest\ Palindromic\ Subsequence\ of\ Interval\ [j,j+i)$

$dp[i][j]=max(dp[i-1][j],dp[i-1][j+1])$

$dp[i][j]=dp[i-2][j+1]+2\ (if\ s[j]==s[j+i-1])$



## Number of Palindromic Subsequence

$dp[i][j]: Number\ of\ Palindromic\ Subsequence\ of\ Interval\ [j,j+i)$

$dp[i][j]=dp[i-1][j]+dp[i-1][j+1]-dp[i-2][j+1]$

$dp[i][j]+=dp[i-2][j+1]+1\ (if\ s[j]==s[j+i-1])$

