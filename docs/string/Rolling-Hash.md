# Rolling Hash

Polynomial Hash

- 函式
    - [Constructor](#Constructor)
    - [add_char](#add_char)
    - [substr](#substr)
    - [merge](#merge)
	- [size](#size)
- 其他
    - [Verification](#Verification)
    - [Reference](#Reference)

## Constructor

```cpp
Hash<int HASH_COUNT, bool PRECOMPUTE_POWERS = true> hs(const string& s)
```

`HASH_COUNT`：使用幾組 hash

`PRECOMPUTE_POWERS`：次方建表

如果沒有建次方表，將會使用快速冪計算，複雜度要乘以 $\log$

`s` 可以為空，再透過 `add_char` 新增字元

## add_char

```cpp
void hs.add_char(char c)
```

新增一個字元 `c` 到最後面

## substr

```cpp
array<int, HASH_COUNT> hs.substr(int l, int r)
```

回傳 $s[l, r)$ 的 hash 值

如果 $l = r$ 回傳 $0$

**constraints**

- $0 \leq l \leq r \leq n$

## merge

```cpp
array<int, HASH_COUNT> hs.merge(const vector<pair<int, int>>& seg)
```

回傳 $s[l_0, r_0) + s[l_1, r_1) + \dots + s[l_k, r_k)$ 的 hash 值

**constraints**

- $0 \leq l_i \leq r_i \leq n$

## size

```cpp
int hs.size()
```

回傳字串長度

---

## Verification

:thumbsup: https://atcoder.jp/contests/abc284/tasks/abc284_f
:thumbsup: https://cses.fi/problemset/task/1753/

## Reference
