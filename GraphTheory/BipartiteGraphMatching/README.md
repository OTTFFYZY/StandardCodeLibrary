# Bipartite Graph Matching



[TOC]



## Contents

| Contents                                           | Time           | Memory       | Code | Test |
| -------------------------------------------------- | -------------- | ------------ | ---- | ---- |
| Bipartite Graph Max Matching (Hungarian dfs)       | $O(VE)$        | $O(V\!+\!E)$ | OK!  | OK!  |
| Bipartite Graph Max Matching (Hungarian bfs)       | $O(VE)$        | $O(V\!+\!E)$ | OK!  |      |
| Bipartite Graph Max Matching (Hopcroft-Karp)       | $O(\sqrt{V}E)$ | $O(V\!+\!E)$ | OK!  |      |
| Bipartite Graph Max Matching (Network Flow)        |                |              |      |      |
| Bipartite Graph Multiple Matching                  |                |              |      |      |
| Weight Bipartite Graph Max Matching (Kuhn-Munkras) |                |              |      |      |
|                                                    |                |              |      |      |


## Konig's Theorem

Maxinum Matching = Minimum Vertex Cover Set

Vertex Cover Set: A Vertices Set which covers all the edges in the graph


Minimum Edge Cover Set = Number of Vertices - Maxinum Matching

Minimum Edge Cover Set: A Edge Set which covers all the vertices in the graph



