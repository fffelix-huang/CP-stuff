---
title: Integer division ($\lfloor \frac{a}{b} \rfloor \lceil \frac{a}{b} \rceil$)
documentation_of: ../library/math/integer-div.hpp
---

`floor_div(a, b)` 回傳最大且 $\leq \frac{a}{b}$ 的整數

`ceil_div(a, b)` 回傳最小且 $\geq \frac{a}{b}$ 的整數

## 使用方法
```cpp
int a = floor_div(-2, 4); // -1
int b = floor_div(-5, 2); // -3
int c = ceil_div(-2, 4);  //  0
```
