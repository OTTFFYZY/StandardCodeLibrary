# Sorting Algorithm



[TOC]



## Contents

| Contents            | Time                | Memory           | Extra Space      | Stable | Code | Test |
| ------------------- | ------------------- | ---------------- | ---------------- | ------ | ---- | ---- |
| Bubble Sort         | $O(N^2)$            | $O(N)$           | $O(1)$           | Yes    | OK!  |      |
| Selection Sort      | $O(N^2)$            | $O(N)$           | $O(1)$           | Yes    | OK!  |      |
| Insertion Sort      | $O(N^2)$            | $O(N)$           | $O(1)$           | Yes    | OK!  |      |
| Merge Sort          | $O(NlogN)$          | $O(N)$           | $O(N)$           | Yes    | OK!  |      |
| Quick Sort          | $O(NlogN) / O(N^2)$ | $O(N)$           | $O(1)$           | No     | OK!  |      |
| Heap Sort           | $O(NlogN)$          | $O(N)$           | $O(1)$           | No     | OK!  |      |
| Counting Sort       | $O(N_N\!+\!N_B)$    | $O(N_N\!+\!N_B)$ | $O(N_N\!+\!N_B)$ | Yes    | OK!  |      |
| Radix Sort          | $O(N_N N_B)$        | $O(N)$           | $/$              | Yes    | OK!  |      |
| Radix Sort (string) | $O(\sum L)$         | $O(\sum L)$      | $$O(\sum L)$$    | Yes    | OK!  |      |
| Bucket Sort         | $/$                 | $O(N)$           | $O(N)$           | Yes    | OK!  |      |
| Shell Sort          | $O(N^2)$            | $O(N)$           | $O(1)$           | Yes    |      |      |
| Three-Color Sorting | $O(N)$              | $O(N)$           | $O(1)$           | No     | OK!  | OK!  |
| Gnome Sort          | $O(N^2)$            | $O(N)$           | $O(1)$           | Yes    | OK!  | OK!  |

## Strict Weak Ordering

incomparability not A<B, not B<A -> A==B

irreflexivity A==B -> A<B false B<A false

asymmetry A<B -> not B<A

transitivity A<B, B<C -> A<C

transitivity of incomparability A==B, B==C -> A==C