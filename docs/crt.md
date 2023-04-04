---
title: crt (中國剩餘定理)
documentation_of: ../library/math/crt.hpp
---

## 中國剩餘定理

找 $x$ 使得

$$x \equiv r[i] \pmod m[i]$$。

如果無解的話回傳 $(0, 0)$。

時間複雜度：$O(n \log{\mathrm{lcm}(m[i])})$

## References
[AtCoder Library document](https://atcoder.github.io/ac-library/production/document_en/math.html)
