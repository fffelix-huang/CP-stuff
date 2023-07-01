---
title: Merge Sort Tree
documentation_of: ../library/data-structure/merge-sort-tree.hpp
---

## 使用方法
```cpp
vector<int> a = {4, 8, 7, 6, 3};

merge_sort_tree<int> tree(a);

int l, r, x;

// [l, r) 區間 < / <= / > / >= x 的元素數量
int cnt_less = tree.count_less(l, r, x);
int cnt_less_eq = tree.count_less_equal(l, r, x);
int cnt_greater = tree.count_greater(l, r, x);
int cnt_greater_eq = tree.count_greater_equal(l, r, x);
```

## 題目
[SPOJ - KQUERY](https://www.spoj.com/problems/KQUERY/)

## References
[https://hitonanode.github.io/cplib-cpp/segmenttree/merge_sort_tree.hpp](https://hitonanode.github.io/cplib-cpp/segmenttree/merge_sort_tree.hpp)
