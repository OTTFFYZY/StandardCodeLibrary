# Game Theory



[TOC]



## Contents

| Contents                   | Time     | Memory      | Code | Test |
| -------------------------- | -------- | ----------- | ---- | ---- |
| Failure State              | $/$      | $O(N)$      | OK!  |      |
| Bash Game                  | $O(1)$   | $O(1)$      | OK!  |      |
| Nim Game                   | $O(N)$   | $O(N)/O(1)$ | OK!  |      |
| Staircase Nim              | $O(N)$   | $O(N)$      | OK!  |      |
| Wythoff Game               | $O(1)$   | $O(1)$      | OK!  |      |
| Sprague Grundy(SG) Theorem | $O(N^2)$ | $O(N)$      | OK!  |      |
|                            |          |             |      |      |
|                            |          |             |      |      |
|                            |          |             |      |      |



## Failure State (N/P-Position)

N(Now) Position: who do the operation now, win the game.

P(Previous) Position: who do the previous operation, win the game.



## Bash Game

### Original:

Describe: n things, pick at most m every times.

Win State: $n\%(m+1) \neq 0$

To Win: pick $n\%(m+1)$

### Pick m at most, Pick s at least

Describe: n things, pick $[s, m]$ every times.

Win State: $n\%(s+m) \le m$

To win: pick $n\%(s+m)$



## Nim Game

### original:

Describe: n piles, pick any numbers in one piles every times. Who pick up all remains win.

Win State: $p[0] \oplus  p[1] \oplus p[2] \oplus \dots \oplus p[n-1] \neq 0​$

To win: $p[0] \oplus p[1] \oplus p[2] \oplus \dots \oplus p[n-1] = a​$, pick any $p[i]-(p[i] \oplus a)​$, if $p[i] \ge (p[i] \oplus a)​$

### pick m at most:

Win State: $(p[0] \oplus p[1] \oplus p[2] \oplus \dots \oplus p[n-1])\%(m+1) \neq 0​$

To win: $(p[0] \oplus p[1] \oplus p[2] \oplus \dots \oplus p[n-1])\%(m+1)=a​$, 

​              pick any $p[i]-(p[i] \oplus a)​$, if $p[i] \ge (p[i] \oplus a)​$

### Staircase Nim

Descirbe: n piles, only can move some of the stones from i pile to i-1 pile. Stones in 0 pile cannot move to other piles.

Win State:  $p[1] \oplus  p[3] \oplus p[5] \oplus \dots \oplus p[(n+1)/2*2] \neq 0​$

To win:  $p[1] \oplus  p[3] \oplus p[5] \oplus \dots \oplus p[(n+1)/2*2] = a$ 

​	      pick any $p[i]-(p[i] \oplus a)$, if $i$ is odd and $p[i] \ge (p[i] \oplus a)$

for this problem the stones in even piles are useless



## Sprague Grundy (SG) Theorem

$mex(S)$ minimal excludant operation. Return the smallest non-negtive value from the whole set that does not belong to the subset S.

$SG(now) = 0, now \ without \ next \ state$

$SG(now) = mex({SG(s)|s \ is \ the \ next \ state \ of \ now})$

So, it is clearly that, for Nim game, $SG(i) = i$ , i state is a pile with i stones.

All impartial combinational game (ICG) can be transform to nim game.

So the sg of the sum of the games

$SG_{\sum} = SG(game_0) \oplus SG(game_1) \oplus SG(game_2) \oplus \dots \oplus SG(game_{n-1})$

