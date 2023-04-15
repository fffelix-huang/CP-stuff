---
title: Wavelet Tree (靜態區間第 $k$ 大)
documentation_of: ../library/data-structure/wavelet-tree.hpp
---

## 使用方法
```cpp
vector<int> v = {4, 8, 7, 6, 3};
vector<pair<int, int>> v2({make_pair(3, 1), make_pair(4, 1), make_pair(5, 9), make_pair(2, 6)});

// 初始化
wavelet_tree tree(v);
wavelet_tree tree2(v2);

int l, r, k;
int val = tree.get_kth(l, r, k); // 回傳區間 [l, r) 的第 k 大 (0-based)
int x = tree.get_kth(0, 3, 0); // 4
int y = tree.get_kth(1, 3, 1); // 8
pair<int, int> res = tree2.get_kth(1, 4, 1); // {4, 1};
```

