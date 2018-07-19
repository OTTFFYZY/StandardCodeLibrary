# Dynamic Programming



[TOC]



## Contents

| Contents                                     | Time               | Memory   | Code | Test |
| -------------------------------------------- | ------------------ | -------- | ---- | ---- |
| Longest Increasing Subsequence (LIS)         | $O(N^2) /O(NlogN)$ | $O(N)$   | OK!  | OK!  |
| Longest Common Subsequence (LCS)             | $O(NM)$            | $O(NM)$  | OK!  |      |
| LCS to LIS                                   | $O(NlogN)$         | $O(N)$   | OK!  |      |
| Longest Common Increasing Subsequence (LCIS) | $O(N^2)$           | $O(N)$   |      |      |
| Zero One Pack                                | $O(NV)$            | $O(V)$   | OK!  |      |
| Complete Pack                                | $O(NV)$            | $O(V)$   | OK!  |      |
| Multiple Pack (binary)                       | $O(NVlogV)$        | $O(V)$   | OK!  |      |
| Multiple Pack (monotone queue)               | $O(NV)$            | $O(V)$   |      |      |
| Double Volume Pack                           | $O(NV^2)$          | $O(V^2)$ |      |      |
|                                              |                    |          |      |      |
|                                              |                    |          |      |      |



## Longest Increasing Subsequence (LIS)

$dp[i]=\max\limits_{j<i\&s[j]<s[i]}(dp[j])+1$



## Longest Common Subsequence (LCS)

$dp[i][j]=max(dp[i-1][j],dp[i][j-1])$

$dp[i][j]=dp[i-1][j-1]+1 \ (if \ s[i]==s[j])$

