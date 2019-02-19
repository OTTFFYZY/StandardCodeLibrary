# DFS-Based Algorithms



[TOC]

## Contents

| Contents                                      | Time         | Memory       | Code | Test |
| --------------------------------------------- | ------------ | ------------ | ---- | ---- |
| Traversing Binary Tree                        | $O(N)$       | $O(N)$       | OK!  |      |
| Have Loop (undirected, undirected2, directed) | $O(V\!+\!E)$ | $O(V\!+\!E)$ | OK!  |      |
| Bi-color                                      | $O(V\!+\!E)$ | $O(V\!+\!E)$ | OK!  |      |
| 2-SAT                                         | $O(V\!+\!E)$ | $O(V\!+\!E)$ | OK!  | OK!  |
|                                               |              |              |      |      |



## Have Loop

There are several method to find loops in an undirected graph.

1. Union-find set. 
2. number of connected component + number of edges == number of vertex (no loop)
3. dfs



## 2-SAT

a -> 0 1

b -> 0 1

$(a_0 \ op \ b_0)\and(a_1 \ op \ b_1) \dots \and(a_n \ op \ b_n)​$



for $a_i \ op \ b_i​$

| $a_i=0 \ b_i=0$ | $a_i=0 \ b_i=1$ | $a_i=1 \ b_i=0$ | $a_i=1 \ b_i=1$ | op                  |
| --------------- | --------------- | --------------- | --------------- | ------------------- |
| 0               | 0               | 0               | 0               | false               |
| 0               | 0               | 0               | 1               | $a_i \and b_i$      |
| 0               | 0               | 1               | 0               | $a_i \and \neg b_i$ |
| 0               | 0               | 1               | 1               | $a_i$               |
| 0               | 1               | 0               | 0               | $\neg a_i \and b_i$ |
| 0               | 1               | 0               | 1               | $b_i$               |
| 0               | 1               | 1               | 0               | $a_i \ b_i$         |
| 0               | 1               | 1               | 1               |                     |
|                 |                 |                 |                 |                     |
|                 |                 |                 |                 |                     |
|                 |                 |                 |                 |                     |
|                 |                 |                 |                 |                     |
|                 |                 |                 |                 | false               |
|                 |                 |                 |                 |                     |
|                 |                 |                 |                 |                     |
|                 |                 |                 |                 | true                |









