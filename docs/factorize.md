---
title: Integer Factorization (Pollard Rho 質因數分解)
documentation_of: ../library/math/factorize.hpp
---

## 判斷質數
```cpp
long long a;
is_prime(a); // 回傳 a 是否為質數
```

## 質因數分解
```cpp
long long a;
vector<unsigned long long> factors = factorize(a); // 回傳 a 的質因數 (排序)
```

## 因數
```cpp
long long a;
vector<unsigned long long> divisors = get_divisors(a); // 回傳 a 的所有因數 (排序)
```

## 題目
[ABC293 F - Zero or One](https://atcoder.jp/contests/abc293/tasks/abc293_f)
