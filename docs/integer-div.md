---
title: Integer division ($\lfloor \frac{a}{b} \rfloor \lceil \frac{a}{b} \rceil$)
documentation_of: ../library/math/integer-div.hpp
---

`floor_div(a, b)` 回傳最大且 $\leq \frac{a}{b}$ 的整數

`ceil_div(a, b)` 回傳最小且 $\geq \frac{a}{b}$ 的整數

## 使用方法
```cpp
int x, y;

int a = floor_div(x, y);
int b = ceil_div(x, y);
int c = floor_div(-2, 4); // -1
int d = floor_div(-5, 2); // -3
int e = ceil_div(-2, 4);  //  0
```
