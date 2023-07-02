# Treap

Treeeap

- 客製化
	- [Variables](#Variables)
	- [node::Constructor](#nodeConstructor)
	- [node::push_stuff](#nodepush_stuff)
	- [node::unsafe_apply](#nodeunsafe_apply)
	- [node::pull](#nodepull)
	- [debug_node](#debug_node)
- 函式
	- [find](##find)
	- [get_leftmost](#get_leftmost)
	- [get_rightmost](#get_rightmost)
	- [get_kth](#get_kth)
	- [get_position](#get_position)
	- [get_bst_root](#get_bst_root)
	- [split](#split)
	- [split_leftmost_k](#split_leftmost_k)
	- [merge](#merge)
	- [count_left](#count_left)
	- [add](#add)
	- [remove](#remove)
	- [next](#next)
	- [prev](#prev)
	- [get_size](#get_size)
	- [Apply](#Apply)
	- [reverse](#reverse)
- 其他
	- [Verification](#Verification)
	- [Reference](#Reference)

## Variables

`int id`：編號 (debug 用)

`node* l`：左節點

`node* r`：右節點

`node* p`：父節點

`bool rev`：翻轉區間 tag

`int sz`：子樹大小

`int P`：節點的 priority

其他根據需求自己增加變數

## node::Constructor

```cpp
node(int id, ...)
```

`id` 為必須，其他自己增加的變數記得要初始化

## node::push_stuff

把懶標推到子樹，並清除標記。

## node::unsafe_apply

把懶標更新到此節點，更新答案並合併懶標。

## node::pull

把子樹的答案更新到此節點。

## debug_node

把 treap 印出來，樹根在最左邊。

---

## find

```cpp
pair<node*, int> find(node* v, const function<int(node*)> &go_to)
```

**parameter**

`node* v`：樹根

`const function<int(node*)>& go_to`：要往哪個方向走 (-1：往走左、0：找到、+1：往右走)

**return value**

回傳停在的節點，和他的方向。

## get_leftmost

```cpp
node* get_leftmost(node* v)
```

**parameter**

`node* v`：樹根

**return value**

回傳 inorder 順序中第一個節點。

## get_rightmost

```cpp
node* get_rightmost(node* v)
```

**parameter**

`node* v`：樹根

**return value**

回傳 inorder 順序中最後一個節點。

## get_kth

```cpp
node* get_kth(node* v, int k)
```

**parameter**

`node* v`：樹根

**return value**

回傳 inorder 順序中第 $k$ 個節點 (0-based)。

## get_position

```cpp
int get_position(node* v)
```

**parameter**

`node* v`：樹上某個節點

**return value**

回傳此節點在樹中 inorder 順序中的位置 (0-based)。

## get_bst_root

```cpp
node* get_bst_root(node* v)
```

**parameter**

`node* v`：樹上某個節點

**return value**

回傳此節點所在的樹的樹根。

## split

```cpp
pair<node*, node*> split(node* v, const function<bool(node*)> &is_right)
```

**parameter**

`node* v`：樹根

`const function<bool(node*)> &is_right`：怎麼切 (回傳 `true` 代表此節點要被切到右邊)

**return value**

回傳一組 pair 代表左樹和右樹的樹根。

## split_leftmost_k

```cpp
pair<node*, node*> split_leftmost_k(node* v, int k)
```

**parameter**

`node* v`：樹根

`int k`：左樹大小

**return value**

切割最左邊 $k$ 個到左樹，剩下到右樹，並回傳一組 pair 代表左樹和右樹的樹根。

## merge

```cpp
node* merge(node* v, node* u)
```

**parameter**

`node* v`：左樹樹根

`node* u`：右樹樹根

**return value**

合併左樹和右樹，並回傳樹根。

## count_left

```cpp
int count_left(node* v, const function<bool(node*)> &is_right)
```

**parameter**

`node* v`：樹根

`const function<bool(node*)> &is_right`：屬於哪邊 (回傳 `true` 代表此節點屬於右邊)

**return value**

回傳屬於左邊的數量 (沒用用到 `split` 所以常數比較小)

## add

```cpp
node* add(node* r, node* v, const function<bool(node*)> &go_left)
```

**parameter**

`node* r`：樹根

`node* v`：要加入的節點

`const function<bool(node*)> &go_left`：往哪個方向走 (回傳 `true` 代表 `v` 要往左走)

**return value**

回傳合併後的樹根。

## remove

```cpp
node* remove(node* v)
```

**parameter**

`node* v`：要刪掉的節點

**return value**

回傳刪除 `v` 後的樹根。

## next

```cpp
node* next(node* v)
```

**parameter**

`node* v`：樹上某個節點

**return value**

回傳 inorder 順序中 `v` 的下一個順位。

## prev

```cpp
node* prev(node* v)
```

**parameter**

`node* v`：樹上某個節點

**return value**

回傳 inorder 順序中 `v` 的上一個順位。

## get_size

```cpp
int get_size(node* v)
```

**parameter**

`node* v`：樹根

**return value**

回傳 `v` 子樹的大小。

## Apply

```cpp
template<class... T>
void Apply(node* v, T... args)
```

**parameter**

`node* v`：樹根

把以 `v` 為樹根的子樹打上懶標。

## reverse

void reverse(node* v)

**parameter**

`node* v`：樹根

把以 `v` 為樹根的子樹翻轉。

---

## Verification

## Reference
1. https://codeforces.com/contest/1737/submission/175025650