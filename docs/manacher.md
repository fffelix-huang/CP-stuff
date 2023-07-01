---
title: Manacher's Algorithm
documentation_of: ../library/string/manacher.hpp
---

## 使用方法
```cpp
string s = "mississippi";

vector<pair<int, int>> p = enumerate_palindromes(s); // p[i] := 以 i 為中心的最長回文為 s[l, r)
```

## References
[https://snuke.hatenablog.com/entry/2014/12/02/235837](https://snuke.hatenablog.com/entry/2014/12/02/235837)
