---
title: Z Algorithm
documentation_of: ../library/string/z-algorithm.hpp
---

$z[i]$ 為 $s[0, n)$ 和 $s[i, n)$ 最長共同前綴 (LCP) 的長度。

## 使用方法
```cpp
string s = "ababacaca";
vector<int> z = z_algorithm(s); // 0 0 3 0 1 0 1 0 1
```

時間複雜度：$O(n)$

## References
[Atcoder Library document](https://atcoder.github.io/ac-library/production/document_en/string.html)
