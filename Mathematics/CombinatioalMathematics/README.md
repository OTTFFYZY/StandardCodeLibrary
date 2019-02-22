# Combinational Mathematics



[TOC]



## Contents

| Contents                             | Time     | Memory   | Code | Test |
| ------------------------------------ | -------- | -------- | ---- | ---- |
| Set (bit mask) & Bit Operation       |          |          |      |      |
| Generate Permutation (dfs)           |          |          | OK!  |      |
| Next Permutation                     | $O(N)$   | $O(N)$   | OK!  |      |
| Generate Subset (duplicate elements) |          |          | OK!  |      |
| Combinatorial Number                 | $/$      | $/$      | OK!  |      |
| Combinatorial Number Table           | $O(N^2)$ | $O(N^2)$ | OK!  |      |
| Cantor Expansion                     |          |          |      |      |
| Gray Code                            | $O(2^N)$ | $O(2^N)$ | OK!  | OK!  |



## Cantor Expansion

A Permutation <-> Number

$Number \ of \ Permutations \ of \ k \ Elements = k!$ 

Let $P(a_1, a_2, a_3, \dots , a_{k})​$ is one of the permutation



$P \rightarrow n(n \in \mathbb{Z}, n \in [0,K!)$

$n = b_1 (k-1)! + b_{2} (k-2)! + \cdots + b_{n-1} \cdot 1! + b_{k} \cdot 0!$

$b_i = \sum^{k}_{j=i+1}[a_{i}>a_{j}]​$

So $b_k \equiv 0$ 



$n \rightarrow P​$

$b_k=0$

$b_{k-1} = n \% 2$

$b_{k-2} = n/2 \% 3​$

$b_{k-3} = n/(3!) \% 4$

$\vdots​$

$b_{1} = n/(k-1)! ​$



Eg:

$K = 3$, $K!=6$

$(1,2,3) \rightarrow 0​$

$(1,3,2) \rightarrow 1​$

$(2,1,3) \rightarrow 2​$

$(2,3,1) \rightarrow 3$

$(3,1,2) \rightarrow 4$

$(3,2,1) \rightarrow 5$



$P (3,1,2) \rightarrow n$

$b_1=2,b_2=0,b_3=0$

$n=2 \cdot 2! + 0 \cdot 1! + 0 \cdot 0! = 4$



$3 \rightarrow P$

$b_3=0$

$b_2 = 3 \% 2 = 1$

$b_1 = 3/2 \% 3 = 1​$

$b_1=1 \rightarrow$ in $(1,2,3)$, $2 > 1 \ element(1)$ $P(2,*,*)$

$b_2 = 1 \rightarrow$ in $(1,3)$, $3 > 1 \ element(1)$ $P(2,3,*)$

$P (2,3,1)​$



$5 \rightarrow P$

$b_3=0$

$b_2 = 5 \% 2 = 1$

$b_1 = 5/2 \% 3 = 2​$

$b_1=2 \rightarrow​$ in $(1,2,3)​$, $3 > 2 \ elements(1,2)​$ $P(3,*,*)​$

$b_2 = 1 \rightarrow$ in $(1,2)$, $2 > 1 \ element(1)$ $P(3,2,*)$

$P (3,2,1)$