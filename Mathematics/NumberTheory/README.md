# Number Theory



[TOC]



## Contents

| Contents                           | Time          | Memory | Code | Test |
| ---------------------------------- | ------------- | ------ | ---- | ---- |
| Modular Operator (+, -, *, ^, mod) | $/$           | $/$    | OK!  |      |
| GCD & LCM (Euclid Method)          | $O(logN)$     | $/$    | OK!  |      |
| Extend Euclid                      | $O(logN)$     | /      |      |      |
| Inverse Element / Modular Division | $O(logN)$     | $O(1)$ |      |      |
| Prime Table (basic, bitmap)        | $O(NloglogN)$ | $O(N)$ | OK!  |      |
| Is Prime (basic, Miller-Robin)     | $O(\sqrt{N})$ | $O(1)$ |      |      |
| Factorization                      | $O(\sqrt{N})$ |        |      |      |
| Phi Function / Phi Table           |               |        |      |      |
| Power Reduction Formula            |               |        |      |      |
| Chinese Remainder Theory           |               |        |      |      |
| Modular Linear Equations           |               |        |      |      |
| Lucas Theory / Extend Lucas Theory |               |        |      |      |
|                                    |               |        |      |      |





## Modular Operator

1.  $(a \pm b)\%M = ((a\%M) \pm (b\%M))\%M$
2.  $(ab)\%M = ((a\%M) \dot (b\%M))\%M$
3.  
