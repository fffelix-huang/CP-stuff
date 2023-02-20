# Treap

Treeeap

- 客製化
	- [node::Variable](#node::Variables)
	- [node::Constructor](#node::Constructor)
	- [node::push_stuff](#node::push_stuff)
	- [node::unsafe_apply](#node::unsafe_apply)
	- [node::push](#node::push)
	- [node::pull](#node::pull)
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

## node::Variables

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

## node::unsafe_apply

## node::push

## node::pull

## debug_node

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

---

## Verification

## Reference
1. https://codeforces.com/contest/1737/submission/175025650