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

| $a_i=0 \ b_i=0$ | $a_i=0 \ b_i=1$ | $a_i=1 \ b_i=0$ | $a_i=1 \ b_i=1$ | op                       |
| --------------- | --------------- | --------------- | --------------- | ------------------------ |
| 0               | 0               | 0               | 0               | false                    |
| 0               | 0               | 0               | 1               | $a_i \and b_i$           |
| 0               | 0               | 1               | 0               | $a_i \and \neg b_i$      |
| 0               | 0               | 1               | 1               | $a_i$                    |
| 0               | 1               | 0               | 0               | $\neg a_i \and b_i$      |
| 0               | 1               | 0               | 1               | $b_i$                    |
| 0               | 1               | 1               | 0               | $a_i \oplus b_i$         |
| 0               | 1               | 1               | 1               | $a_i \or b_i$            |
| 1               | 0               | 0               | 0               | $\neg a_i \and \neg b_i$ |
| 1               | 0               | 0               | 1               | $a_i \odot b_i$          |
| 1               | 0               | 1               | 0               | $\neg b_i$               |
| 1               | 0               | 1               | 1               | $a_i \or \neg b_i$       |
| 1               | 1               | 0               | 0               | $\neg a_i$               |
| 1               | 1               | 0               | 1               | $\neg a_i \or b_i$       |
| 1               | 1               | 1               | 0               | $\neg a_i \or \neg b_i$  |
| 1               | 1               | 1               | 1               | true                     |

case 0:

false -> false

true -> true

case 1: 

$a_i$, $\neg a_i$, $b_i$, $\neg b_i$

$a_i$ -> $edge(\neg a_i \rightarrow a_i)$

$\neg a_i$ -> $edge(a_i \rightarrow \neg a_i)$

case 2:

$\neg a_i \and \neg b_i​$, $a_i \and \neg b_i​$, $\neg a_i \and b_i​$, $a_i \and b_i​$ -> divided into 2 case 2

case 3:

$\neg a_i \or \neg b_i$, $a_i \or \neg b_i$, $\neg a_i \or b_i$, $a_i \or b_i$

$a_i \or b_i​$ -> $edge(\neg a_i \rightarrow b_i)​$ and $edge(\neg b_i \rightarrow a_i)​$

case 4:

$a_i \oplus b_i​$ -> $(a_i \or \neg b_i) \and (\neg a_i \or b_i)​$ -> case 3

case 5:

$a_i \odot b_i$ -> $(a_i \or b_i) \and (\neg a_i \or \neg b_i)$ -> case 3



If there is a path $u \rightarrow v$ in the graph, there must be a path $\neg v \rightarrow \neg u$

If there is a path $u \rightarrow \neg u​$ and a path $\neg u \rightarrow u​$ , no solution.

If there is a path $u \rightarrow \neg u$ choose $\neg u$

If there is a path $\neg u \rightarrow u$ choose $u$

Otherwise, try to choose $\neg u$ first (lexicographic order).



