# String Algorithm



[TOC]



## Contents

| Contents                       | Time              | Memory            | Code | Test |
| ------------------------------ | ----------------- | ----------------- | ---- | ---- |
| Trie (pointer)                 | $O(N)$            | $O(\sum N)$       | OK!  | OK!  |
| Trie (array)                   | $O(N)$            | $O(\sum N)$       | OK!  |      |
| MP & KMP (Knuth-Morris-Pratt)  | $O(T\!+\!P)$      | $O(T\!+\!P)$      | OK!  |      |
| Extend KMP                     | $O(T\!+\!P)$      | $O(T\!+\!P)$      | OK!  | OK!  |
| Aho-Corasick Automaton         | $O(T\!+\!\sum P)$ | $O(T\!+\!\sum P)$ | OK!  | OK!  |
| Trie Graph                     | $O(T\!+\!\sum P)$ | $O(T\!+\!\sum P)$ | OK!  | OK!  |
| Suffix Array (multiplication)  | $O(NlogN)$        | $O(N)$            | OK!  |      |
| Suffix Array (DC3)             | $O(N)$            | $O(N)$            |      |      |
| Suffix Array (induce sort)     | $O(N)$            | $O(N)$            |      |      |
| Height Array                   | $O(N)$            | $O(N)$            | OK!  |      |
| Suffix Automaton               | $O(N)$            | $O(N)$            | OK!  | OK!  |
| Suffix Tree (suffix automaton) | $O(N)$            | $O(N)$            |      |      |
| Manacher                       | $O(N)$            | $O(N)$            | OK!  | OK!  |
| Palindrome Tree                | $O(N_N log(N_B))$ | $O(N_N N_B)$      | OK!  |      |
| Shift-And / Shift-Or           | $O(T\!+\!P)$      | $O(T\!+\!P)$      | OK!  |      |
| String Minimum Representation  | $O(S)$            | $O(1)$            | OK!  | OK!  |



## Manacher

$mp[i]$: $ms[i]$ is palindromic center, the max extension in ms to left or right (including $ms[i]$)

the length of this palindrome in the original string $s[]$ is $mp[i]-1$

$\begin{matrix} s\ index: &0,&1,&2,&\dots,&i \\ ms\ index:&2,&4,&6,&\dots,&(i+1)*2 \end{matrix}$

The max range of palindrome in s, centered at $i$ in ms:

$ \begin{align} & [\frac{i-1}{2} - \frac{mp[i]-1}{2}, \frac{i}{2} + \frac{mp[i]-1}{2} -1] \\ = &  [\frac{i-mp[i]}{2},\frac{i+mp[i]-3}{2}] \end{align}$



## String Smallest Cyclic Shift

Lyndon Decomposition

Duval Algorithm