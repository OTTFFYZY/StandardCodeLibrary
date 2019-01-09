# Theorem

[TOC]



## Handshaking Lemma

Every finite undirected graph has an even number of vertices with odd degree.
$$
\sum _ {v \in V} deg(v) = 2|E|
$$

$$
\sum _ {v \in V} deg(v)[deg(v)\%2==1] = 2k \quad (k \in N)
$$



### For k-ary tree

$$
L=(k-1)*I+1
$$

L: number of leaf nodes

I: number of internal nodes



### For binary tree

$$
L=T+1
$$

L: number of leaf nodes

T: number of nodes with two children





## Graph & Digraph & Bipartite Realization Problem

### Erdős-Gallai Theorem

It provides one of two known approaches to solving the graph realization problem, i.e. it gives a necessary and sufficient condition for a finite sequence of natural numbers to be the degree sequence of a simple graph. A sequence obeying these conditions is called "graphic".

A sequence of non-negative integers $ d_{1} \geq \cdots \geq d_{n} $ can be represented as the degree sequence of a finite simple graph on n vertices if and only if $d_1+\cdots+d_n$ is even and
$$
\sum_{i=1}^{k} d_i \leq k(k-1)+\sum_{i=k+1}^{n} min(d_i,k)
$$
for every k in $1 \leq k \leq n$.



### Fulkerson–Chen–Anstee Theorem

It provides one of two known approaches solving the digraph realization problem, i.e. it gives a necessary and sufficient condition for pairs of nonnegative integers $ ((a_{1},b_{1}),\ldots ,(a_{n},b_{n}))$ to be the indegree-outdegree pairs of a simple directed graph; a sequence obeying these conditions is called "digraphic".

A sequence $((a_{1},b_{1}),\ldots ,(a_{n},b_{n}))$ of nonnegative integer pairs with $a_{1}\geq \cdots \geq a_{n}$ is digraphic if and only if $\sum _{i=1}^{n}a_{i}=\sum _{i=1}^{n}b_{i}$ and the following inequality holds for k such that $1\leq k\leq n$:
$$
\sum_{i=1}^{k} a_{i} \leq \sum_{i=1}^{k} min(b_{i},k-1) + \sum_{i=k+1}^{n} min(b_{i},k)
$$


### Gale–Ryser theorem

It provides one of two known approaches to solving the bipartite realization problem, i.e. it gives a necessary and sufficient condition for two finite sequences of natural numbers to be the degree sequence of a labeled simple bipartite graph; a sequence obeying these conditions is called "bigraphic". It is an analog of the Erdős–Gallai theorem for simple graphs.

A sequence $((a_{1},b_{1}),\ldots ,(a_{n},b_{n}))$ of nonnegative integer pairs with $a_{1}\geq \cdots \geq a_{n}$ is bigraphic if and only if $\sum _{i=1}^{n}a_{i}=\sum _{i=1}^{n}b_{i}$ and the following inequality holds for k such that $1\leq k\leq n$:
$$
\sum_{i=1}^{k} a_{i} \leq \sum_{i=1}^{n} min(b_{i},k)
$$
