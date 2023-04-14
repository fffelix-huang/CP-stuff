---
title: random_t
documentation_of: ../library/random/random.hpp
---

## 使用方法
```cpp
long long seed = std::chrono::steady_clock::now().time_since_epoch().count();
random_t rnd(seed);

long long low, high;
long long n = rnd.next(low, high); // [low, high]

vector<int> a;
rnd.shuffle(a.begin(), a.end());

int n;
vector<int> perm = rnd.permutation(n); // [0, n - 1]
string str = rnd.string(n, 'A', 'Z'); // 長度為 n，字元集為 ['A', 'Z']
```

## References
[XOR shift](https://xoshiro.di.unimi.it/xoshiro256starstar.c)
