---
title: Sum of floor linear ($\sum_{i = 0}^{n - 1} \lfloor \frac{ai + b}{m} \rfloor$)
documentation_of: ../library/math/floor-sum.md
---

計算 $f(n, m, a, b) = \sum_{i = 0}^{n - 1} \lfloor \frac{a \times i + b}{m} \rfloor \bmod{2^{64}}$

時間複雜度：$O(\log n)$

## 題目
[AtCoder Library Practice Contest C - Floor Sum](https://atcoder.jp/contests/practice2/tasks/practice2_c)

## References
[AtCoder Library document](https://atcoder.github.io/ac-library/production/document_en/math.html)
[OI wiki - 類歐幾里得算法](https://oi-wiki.org/math/number-theory/euclidean/)
