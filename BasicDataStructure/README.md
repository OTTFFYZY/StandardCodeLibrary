# Basic Data Structure


- [Basic Data Structure](#basic-data-structure)
  - [Contents](#contents)
  - [Union-Find Set](#union-find-set)
    - [Problem](#problem)
  - [Fenwick Tree / Binary Index Tree](#fenwick-tree--binary-index-tree)
    - [Problems](#problems)
  - [Monotone Stack & Monotone Queue](#monotone-stack--monotone-queue)
    - [Max Rectangle In Histogram](#max-rectangle-in-histogram)
    - [Find ACB](#find-acb)
    - [Max Value In The Sliding Window](#max-value-in-the-sliding-window)
    - [Huffman-Tree-Like Merge](#huffman-tree-like-merge)
    - [Max Extension](#max-extension)


## Contents

| Contents                                                | Time                     | Memory         | Code | Test |
| ------------------------------------------------------- | ------------------------ | -------------- | ---- | ---- |
| Stack                                                   | $O(1)$                   | $O(N)$         | OK!  |      |
| Queue                                                   | $O(1)$                   | $O(N)$         | OK!  |      |
| Linked List                                             | $/$                      | $O(N)$         | OK!  |      |
| Double-Linked List                                      | $/$                      | $O(N)$         | OK!  |      |
| Memory Pool (id, pointer, entire)                       | $O(1)$                   | $O(N)$         | OK!  |      |
| Union-Find Set (basic, depth, rank, mod)                | $O(\alpha(N))$           | $O(N)$         | OK!  |      |
| Union-Find Set (rollback)                               | $O(log(N))$              | $O(N)$         | OK!  |      |
| Binary Heap (basic, template, entire)                   | $O(logN)$                | $O(N)$         | OK!  |      |
| Range Minimum Query Sparse-Table (basic)                | $O(NlogN) \sim O(1)$     | $O(NlogN)$     | OK!  |      |
| Range Minimum Query Sparse-Table (2d0)                  | $O(N^2logN) \sim O(N)$   | $O(N^2logN)$   | OK!  |      |
| Range Minimum Query Sparse-Table (2d1)                  | $O(N^2log^2N) \sim O(1)$ | $O(N^2log^2N)$ | OK!  |      |
| Fenwick Tree / Binary Index Tree (basic)                | $O(\log N)$              | $O(N)$         | OK!  |      |
| Fenwick Tree / Binary Index Tree (rasq)                 | $O(\log N)$              | $O(N)$         | OK!  |      |
| Fenwick Tree / Binary Index Tree (rarq)                 | $O(\log N)$              | $O(\log N)$    | OK!  | OK!  |
| Fenwick Tree / Binary Index Tree (2d, 2d-rasq, 2d-rarq) | $O(\log^2N)$             | $O(N^2)$       | OK!  |      |
| Prefix Sum                                              | $O(N) \sim O(1)$         | $O(N)$         | OK!  |      |
| Bitmap                                                  | $O(1)$                   | $O(N)$         | OK!  |      |
| Monotone Stack / Queue                                  | $O(N)$                   | $O(N)$         | OK!  |      |
| Permutation Build Tree                                  | $O(N \alpha(N))$         | $O(N)$         | OK!  |      |



## Union-Find Set

### Problem

lrjb: LA3644 LA3027* LA4487* UVA11987* 



## Fenwick Tree / Binary Index Tree

rasq -> Range Add Single-Point Query

rarq -> Range Add Range Query

For range change and range query we can use difference, or we can maintain the changes directly.



### Sum

add (+, -)

query (prefix sum -> range sum) -> (point value -> point set)

### prefix min

init (bit[i] -> INF)

set smaller (v <= a[i])

query (prefix min)



### Problems

lrjb: LA4329



## Monotone Stack & Monotone Queue

### Max Rectangle In Histogram

### Find ACB

### Max Value In The Sliding Window

### Huffman-Tree-Like Merge

### Max Extension
