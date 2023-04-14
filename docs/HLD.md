---
title: Heavy Light Decomposition
documentation_of: ../library/tree/HLD.hpp
---

## 輕重鏈剖分

使用前要先呼叫 `build(root)`。

## 使用方法
```cpp
int n;
HLD hld(n);

int u, v, root;
hld.add_edge(u, v);
hld.build(root); // 以 root 為根結點建構

int z, k;

int lca = hld.get_lca(u, v); // 回傳 u 和 v 的 LCA
bool anc = hld.is_ancestor(u, v); // 回傳 u 是不是 v 的祖先
bool btw = hld.on_path(u, v, z); // 回傳 z 是不是在 u 到 v 的路徑上
int dist = hld.get_distance(u, v); // 回傳 u 到 v 的距離
int kth_anc = hld.get_kth_ancestor(u, k); // 回傳 u 的第 k 個祖先，或 -1 如果不存在
int kth_node = hld.get_kth_node_on_path(u, v, k); // 回傳 u 到 v 路徑的第 k 個節點，或 -1 如果不存在
vector<pair<int, int>> seg = hld.get_path(u, v, z); // 回傳 u 到 v 的所有鏈的區間，z = true 代表要包含 LCA

int id = hld.id[u]; // u 的編號
int sz = hld.subtree_size[u]; // u 子樹的大小
```

## 題目
[ABC294 G - Distance Queries on a Tree](https://atcoder.jp/contests/abc294/tasks/abc294_g)
