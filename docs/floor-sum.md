---
title: Sum of floor linear ($\sum_{i = 0}^{n - 1} \lfloor \frac{ai + b}{m} \rfloor$)
documentation_of: ../library/math/floor-sum.hpp
---

$f(a, b, c, n) = \sum_{i = 0}^{n - 1} \lfloor \frac{ai + b}{c} \rfloor$

## 使用方法
```cpp
int a, b, c, n;
long long ans = floor_sum(a, b, c, n);
```

$g(a, b, c, n) = \sum_{i = 0}^{n - 1} i \lfloor \frac{ai + b}{c} \rfloor$

$h(a, b, c, n) = \sum_{i = 0}^{n - 1} \lfloor \frac{ai + b}{c} \rfloor^2$

$g$ 和 $h$ 變形的做法請參考 Reference 裡 OI wiki 的文章。

時間複雜度：$O(\log n)$

## 題目
[AtCoder Library Practice Contest C - Floor Sum](https://atcoder.jp/contests/practice2/tasks/practice2_c)

## References
[AtCoder Library document](https://atcoder.github.io/ac-library/production/document_en/math.html)

[OI wiki - 類歐幾里得算法](https://oi-wiki.org/math/number-theory/euclidean/)
