---
title: Van Emde Boas Tree
documentation_of: ../library/data-structure/VEBtree.hpp
---

## 簡介

操作與 `std::set<int>` 相同，但操作的複雜度為 $O(\log \log n)$，其中 $n$ 是數字的值域。

## 使用方法
```cpp
VEBtree<24> tree; // [0, 2^24)

int a;

tree.insert(a);
tree.erase(a);
bool has_a = tree.contains(a);
bool is_empty = tree.empty();
tree.clear();

int prev = tree.find_prev(a); // <= a 的最大元素 (-1 代表不存在)
int next = tree.find_next(a); // >= a 的最小元素 (N 代表不存在)
```

## Reference
[算法导论-van Emde Boas树](https://blog.csdn.net/hxlove123456/article/details/78324114)
