# String Algorithm



[TOC]



## Contents

| Contents                      | Code | Test |
| ----------------------------- | ---- | ---- |
| Trie (pointer)                | OK!  |      |
| MP & KMP (Knuth-Morris-Pratt) | OK!  |      |
| Extend KMP                    | OK!  | OK!  |
| Aho-Corasick Automaton        | OK!  |      |
| Suffix Array                  |      |      |
| Suffix Automaton              |      |      |
| Manacher                      | OK!  | OK!  |
| Palindrome Tree               |      |      |
| Shift-And / Shift-Or          | OK!  |      |



## Manacher

mp[i]: ms[i] is palindromic center, the max extension in ms to left or right (including ms[i])

the length of this palindrome in the original string is mp[i]-1

$\begin{matrix} s\ index: &0,&1,&2,&\dots,&i \\ ms\ index:&2,&4,&6,&\dots,&(i+1)*2 \end{matrix}$



