---
title: Suffix Array
documentation_of: ../library/string/suffix-array.hpp
---

## 使用方法
```cpp
string s = "mississippi";
vector<int> sa = suffix_array(s); // 10 7 4 1 0 9 8 6 3 5 2
```

時間複雜度：$O(n)$

## References
[SA-IS 論文](https://local.ugene.unipro.ru/tracker/secure/attachment/12144/Linear+Suffix+Array+Construction+by+Almost+Pure+Induced-Sorting.pdf)
[Atcoder Library document](https://atcoder.github.io/ac-library/production/document_en/string.html)
