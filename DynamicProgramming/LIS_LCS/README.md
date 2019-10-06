# LIS & LCS



[TOC]



## Contents

| Contents                                     | Time               | Memory  | Code | Test |
| -------------------------------------------- | ------------------ | ------- | ---- | ---- |
| Longest Increasing Subsequence (LIS)         | $O(N^2) /O(NlogN)$ | $O(N)$  | OK!  | OK!  |
| Longest Increasing Subsequence (LIS)(bit)    | $O(NlogN)$         | $O(N)$  | OK!  |      |
| Longest Common Subsequence (LCS)             | $O(NM)$            | $O(NM)$ | OK!  |      |
| LCS to LIS                                   | $O(NlogN)$         | $O(N)$  | OK!  |      |
| Longest Common Increasing Subsequence (LCIS) | $O(N^2)$           | $O(N)$  | OK!  | OK!  |
| Least Increasing Subsequence Partition       | $O(NlogN)$         | $O(N)$  | OK!  | OK!  |
|                                              |                    |         |      |      |



## Longest Increasing Subsequence (LIS)

$ dp[i] $ : lis of substring $ s[1,i] $

$ dp[i] = \max \limits_{j<i , s[j]<s[i]}(dp[j]) + 1 $



### Least Increasing Subsequence Partition

-> longest Non-Increasing Subsequence



## Longest Common Subsequence (LCS)

$dp[i][j]$ : the lcs of substring $ s1[1,i] $ and $ s2[1,j] $

$ dp[i][j]=max(dp[i-1][j],dp[i][j-1]) \quad (s1[i] \neq s2[j])$

$ dp[i][j]=dp[i-1][j-1]+1 \quad (s1[i] = s2[j]) $



## Longest Common Increasing Subsequence (LCIS)

$ dp[i][j] $ : lcis of substring $ s1[1,i] $ and $ s2[1,j] $ , end s2[j] in the subsequence.

$ dp[i][j] = dp[i-1][j] \quad (s1[i] \neq s2[j]) $

$ dp[i][j] = \max \limits_{k < j, s2[k] < s1[i]} dp[i-1][k] + 1 \quad (s1[i] = s2[j]) $

Thus, $ dp[i][] $ transfer from $ dp[i-1][] $ and $ dp[i-1][k] $ is a prefix maximum value, we can using rolling array and we can maintain the prefix max while we are calculating dp value.