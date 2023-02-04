# DSU

並查集，啟發式合併 + 路徑壓縮

- 函式
    - [Constructor](##Constructor)
    - [merge](##merge)
    - [same](##same)
    - [size](##size)
    - [leader](##leader)
    - [groups](##groups)
- 相關
    - [verification](##verification)
    - [reference](##reference)

## Constructor

```cpp
DSU d(int n)
```

建立一張 $n$ 個點的無向圖。

**constraints**

- $n \geq 0$

**complexity**

- $O(n)$

## merge

```cpp
bool d.merge(int u, int v)
```

從 $u$ 連一條邊到 $v$。若 $u$ 和 $v$ 原先就在同個連通塊則回傳 `false`，否則回傳 `true`。

**constraints**

- $0 \leq u, v < n$

**complexity**

- $O(\alpha(n))$ 均攤

## same

```cpp
bool d.same(int u, int v)
```

回傳 $u$ 和 $v$ 是否在同個連通塊。

**constraints**

- $0 \leq u, v < n$

**complexity**

- $O(\alpha(n))$ 均攤

## size

```cpp
int d.size(int u)
```

回傳 $u$ 所在的連通塊大小。

**constraints**

- $0 \leq u < n$

**complexity**

- $O(\alpha(n))$ 均攤

## leader

```cpp
int d.leader(int u)
```

回傳 $u$ 所在的連通塊的代表節點。

**constraints**

- $0 \leq u < n$

**complexity**

- $O(\alpha(n))$ 均攤

## groups

```cpp
vector<vector<int>> d.groups()
```

回傳每個連通塊包含的節點。

**complexity**

- $O(n)$

---

## verification

:thumbsup: https://judge.yosupo.jp/problem/unionfind

## reference

1. https://github.com/atcoder/ac-library/blob/master/document_en/dsu.md