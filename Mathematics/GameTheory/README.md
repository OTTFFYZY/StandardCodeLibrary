# Game Theory



[TOC]



## Contents

| Contents                   | Time     | Memory      | Code | Test |
| -------------------------- | -------- | ----------- | ---- | ---- |
| Bash Game                  | $O(1)$   | $O(1)$      |      |      |
| Nim Game                   | $O(N)$   | $O(N)/O(1)$ |      |      |
| Wythoff                    | $O(1)$   | $O(1)$      |      |      |
| Sprague Grundy(SG) Theorem | $O(N^2)$ | $O(N)$      |      |      |
|                            |          |             |      |      |
|                            |          |             |      |      |
|                            |          |             |      |      |



## Bash Game

Describe: n things, pick at most m every times.

Win State: $n\%(m+1)!=0$

To Win: pick $n\%(m+1)$



## Nim Game

### original:

Describe: n piles, pick any numbers in one piles every times. Who pick up all remains win.

Win State: $p[0] \oplus  p[1] \oplus p[2] \oplus \dots \oplus p[n-1]=0​$

To win: $p[0] \oplus p[1] \oplus p[2] \oplus \dots \oplus p[n-1] = a$, pick any $p[i] \oplus a$, if $p[i]>=(p[i] \oplus a)$

### pick m at most:

Win State: $(p[0] \oplus p[1] \oplus p[2] \oplus \dots \oplus p[n-1])\%(m+1)=0$

To win: $(p[0] \oplus p[1] \oplus p[2] \oplus \dots \oplus p[n-1])\%(m+1)=a$, 

​              pick any $p[i] \oplus a$, if $p[i]>=(p[i] \oplus a)​$



## Sprague Grundy (SG) Theorem

$mex(S)$ minimal excludant operation. Return the smallest non-negtive value from the whole set that does not belong to the subset S.

For impartial combinational game (ICG), 