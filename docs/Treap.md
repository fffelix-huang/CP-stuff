---
title: treap
documentation_of: ../library/data-structure/treap.hpp
---

## 使用方法
```cpp
using S = long long;

S e() { return 0; }
S op(S a, S b) { return a + b; }
S reversal(S s) { return s; }

using F = tuple<>;

F id() { return {}; }
S mapping(F, S s) { return s; }
F composition(F, F) { return {}; }

using Treap = treap<S, e, op, reversal, F, id, mapping, composition>;

Treap tree, tree2, L, M, R;
Treap::iterator it;
S val;
int l, r, k;

tree.clear_tag();
tree.merge(tree2);

// std::multiset
int sz = tree.size();
bool empty = tree.empty();
tree.clear();
it = tree.insert(val);
it = tree.insert(it, val);
tree.erase(val);
tree.erase(it);
it = tree.lower_bound(val);
it = tree.upper_bound(val);
it = tree.find(val);

// sequence
int index = tree.get_position(it);
it = tree.insert_k(k, val);
tree.erase_k(k);
tie(L, R) = tree.split_k(k); // tree == empty
tie(L, M, R) = tree.split_range(l, r); // tree == empty
tree.reverse();
tree.reverse(l, r);

for(auto x : tree) {
	cout << x << endl; // call clear_tag() before iterating
}
```

https://atcoder.jp/contests/abc306/submissions/43177331

## References
[hitonanode's library](https://hitonanode.github.io/cplib-cpp/data_structure/lazy_rbst.hpp)
[tourist's treap template](https://codeforces.com/contest/1737/submission/175025650)
