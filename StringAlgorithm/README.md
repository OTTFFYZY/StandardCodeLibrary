# String Algorithm



[TOC]



## Contents

| Contents                      | Time              | Memory            | Code | Test |
| ----------------------------- | ----------------- | ----------------- | ---- | ---- |
| Trie (pointer)                | $O(N)$            | $O(\sum N)$       | OK!  | OK!  |
| Trie (array)                  | $O(N)$            | $O(\sum N)$       | OK!  |      |
| MP & KMP (Knuth-Morris-Pratt) | $O(T\!+\!P)$      | $O(T\!+\!P)$      | OK!  |      |
| Extend KMP                    | $O(T\!+\!P)$      | $O(T\!+\!P)$      | OK!  | OK!  |
| Aho-Corasick Automaton        | $O(T\!+\!\sum P)$ | $O(T\!+\!\sum P)$ | OK!  |      |
| Suffix Array (multiplication) | $O(NlogN)$        |                   |      |      |
| Suffix Array (DC3)            | $O(N)$            |                   |      |      |
| Suffix Array (induce sort)    | $O(N)$            |                   |      |      |
| Suffix Automaton              | $O(N)$            |                   |      |      |
| Manacher                      | $O(N)$            | $O(N)$            | OK!  | OK!  |
| Palindrome Tree               | $O(N_N log(N_B))$ | $O(N_N N_B)$      | OK!  |      |
| Shift-And / Shift-Or          | $O(T\!+\!P)$      | $O(T\!+\!P)$      | OK!  |      |
| String Minimum Representation | $O(S)$            | $O(1)$            | OK!  |      |



## Manacher

mp[i]: ms[i] is palindromic center, the max extension in ms to left or right (including ms[i])

the length of this palindrome in the original string is mp[i]-1

$\begin{matrix} s\ index: &0,&1,&2,&\dots,&i \\ ms\ index:&2,&4,&6,&\dots,&(i+1)*2 \end{matrix}$


