# Game Theory



[TOC]



## Contents

| Contents | Time | Memory | Code | Test |
| -------- | ---- | ------ | ---- | ---- |
| Nim      |      |        |      |      |
|          |      |        |      |      |
|          |      |        |      |      |
|          |      |        |      |      |
|          |      |        |      |      |
|          |      |        |      |      |
|          |      |        |      |      |



## Nim Game

### original:

Win State: p[0]\^p[1]\^p[2]\^...\^p[n-1]!=0

To win: p[0]\^p[1]\^p[2]\^...\^p[n-1]=a, pick any p[i]-p[i]\^a, if p[i]>=p[i]\^a

### pick m at most:

Win State: (p[0]\^p[1]\^p[2]\^...\^p[n-1])\%(m+1)!=0

To win: (p[0]\^p[1]\^p[2]\^...\^p[n-1])\%(m+1)=a, pick any p[i]-p[i]\^a, if p[i]>=p[i]\^a
