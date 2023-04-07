---
title: Discrete Log (離散對數 $a^x \equiv b \pmod m$)
documentation_of: ../library/math/discrete-log.hpp
---

給定 $a, b, m$，找出 $x$ 使得 $a^x \equiv b \pmod m$。

如果無解回傳 $-1$。

## 使用方法
```cpp
int a, b, m;
int x = discrete_log(a, b, m);
```

時間複雜度：$O(\sqrt{m})$

## References
[OI wiki - 離散對數](https://oi-wiki.org/math/number-theory/discrete-logarithm/#%E5%A4%A7%E6%AD%A5%E5%B0%8F%E6%AD%A5%E7%AE%97%E6%B3%95)
