#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" // dummy

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cassert>
#include "../../../library/random/rng.hpp"
#include "../../../library/data-structure/treap.hpp"
using namespace std;
using namespace felix;

using S = int;

S e() { return 0; }
S op(S a, S b) { return a + b; }
S reversal(S s) { return s; }

using F = tuple<>;

F id() { return {}; }
S mapping(F, S s) { return s; }
F composition(F, F) { return {}; }

using Treap = treap<S, e, op, reversal, F, id, mapping, composition>;

void check(Treap tree, vector<int> a) {
	tree.clear_tag();
	assert(tree.size() == (int) a.size());
	reverse(a.begin(), a.end());
	for(auto x : tree) {
		assert(x == a.back());
		a.pop_back();
	}
}

void TEST() {
	{
		cerr << "Testing insert" << endl;
		Treap tree;
		vector<int> a = {4, 8, 7, 6, 3};
		for(auto x : a) {
			tree.insert(x);
		}
		sort(a.begin(), a.end());
		check(tree, a);;
	}

	{
		cerr << "Testing insert iterator" << endl;
		Treap tree;
		tree.insert(tree.end(), 3);
		auto it = tree.insert(tree.end(), 5);
		it = tree.insert(it, 6);
		vector<int> a = {3, 6, 5};
		check(tree, a);
		tree.insert(it, 10);
		a = {3, 10, 6, 5};
		check(tree, a);
	}

	{
		cerr << "Testing insert k" << endl;
		Treap tree;
		vector<int> a;
		for(int i = 0; i < 100; i++) {
			int k = rng() % (i + 1);
			S x = rng();
			tree.insert_k(k, x);
			a.insert(a.begin() + k, x);
			check(tree, a);
		}
	}

	{
		cerr << "Testing erase" << endl;
		Treap tree;
		vector<int> a = {4, 8, 7, 6, 3};
		for(auto x : a) {
			tree.insert(x);
		}
		sort(a.begin(), a.end());
		tree.erase(3);
		a.erase(find(a.begin(), a.end(), 3));
		check(tree, a);
		tree.erase(10);
		check(tree, a);
		tree.erase(4);
		a.erase(find(a.begin(), a.end(), 4));
		check(tree, a);
		tree.erase(7);
		a.erase(find(a.begin(), a.end(), 7));
		check(tree, a);
		tree.erase(8);
		a.erase(find(a.begin(), a.end(), 8));
		check(tree, a);
		tree.erase(6);
		a.erase(find(a.begin(), a.end(), 6));
		check(tree, a);
		assert(tree.size() == 0 && tree.empty());
	}

	{
		cerr << "Testing erase iterator" << endl;
		Treap tree;
		vector<int> a;
		vector<Treap::iterator> iters;
		for(int i = 0; i < 10; i++) {
			S x = rng();
			auto it = tree.insert(tree.end(), x);
			a.push_back(x);
			iters.push_back(it);
		}
		while(!tree.empty()) {
			tree.erase(iters.back());
			iters.pop_back();
			a.pop_back();
			check(tree, a);
		}
	}

	{
		cerr << "Testing erase k" << endl;
		Treap tree;
		vector<int> a;
		for(int i = 0; i < 100; i++) {
			S x = rng();
			tree.insert(tree.end(), x);
			a.push_back(x);
		}
		while(!tree.empty()) {
			int k = rng() % tree.size();
			tree.erase_k(k);
			a.erase(a.begin() + k);
			check(tree, a);
		}
	}

	{
		cerr << "Testing lower_bound" << endl;
		Treap tree;
		vector<int> a = {4, 8, 7, 6, 3};
		for(auto x : a) {
			tree.insert(x);
		}
		auto it = tree.lower_bound(1);
		assert(*it == 3);
		it = tree.lower_bound(3);
		assert(*it == 3);
		it = tree.lower_bound(8);
		assert(*it == 8);
		it = tree.lower_bound(9);
		assert(it == tree.end());
	}

	{
		cerr << "Testing upper_bound" << endl;
		Treap tree;
		vector<int> a = {4, 8, 7, 6, 3};
		for(auto x : a) {
			tree.insert(x);
		}
		auto it = tree.upper_bound(1);
		assert(*it == 3);
		it = tree.upper_bound(3);
		assert(*it == 4);
		it = tree.upper_bound(8);
		assert(it == tree.end());
	}

	{
		cerr << "Testing find" << endl;
		Treap tree;
		vector<int> a = {4, 8, 7, 6, 3};
		for(auto x : a) {
			tree.insert(x);
		}
		sort(a.begin(), a.end());
		for(int i = 0; i < 10; i++) {
			auto it = tree.find(i);
			bool X = it != tree.end();
			bool Y = binary_search(a.begin(), a.end(), i);
			assert(X == Y);
		}
	}

	{
		cerr << "Testing reverse" << endl;
		Treap tree;
		vector<int> a = {4, 8, 7, 6, 3};
		for(auto x : a) {
			tree.insert(tree.end(), x);
		}
		tree.reverse(2, 4);
		reverse(a.begin() + 2, a.begin() + 4);
		check(tree, a);
		tree.reverse();
		reverse(a.begin(), a.end());
		check(tree, a);
	}

	{
		cerr << "Testing merge" << endl;
		Treap tree;
		vector<int> a = {4, 8, 7, 6, 3};
		for(auto x : a) {
			tree.insert(tree.end(), x);
		}
		vector<int> b = {3, 1, 4, 1, 5};
		Treap tree2;
		for(auto x : b) {
			tree2.insert(tree2.end(), x);
		}
		a.insert(a.end(), b.begin(), b.end());
		tree.merge(tree2);
		check(tree, a);
	}

	{
		cerr << "Testing get_index" << endl;
		Treap tree;
		for(int i = 0; i < 100; i++) {
			int k = rng() % (i + 1);
			auto it = tree.insert_k(k, (S) rng());
			assert(tree.get_index(it) == k);
		}
	}

	{
		cerr << "Testing split k" << endl;
		Treap tree;
		vector<int> a;
		for(int i = 0; i < 100; i++) {
			S x = rng();
			tree.insert(tree.end(), x);
			a.push_back(x);
		}
		int k = rng() % (tree.size() + 1);
		auto [t1, t2] = tree.split_k(k);
		vector<int> b(a.begin(), a.begin() + k);
		vector<int> c(a.begin() + k, a.end());
		check(t1, b);
		check(t2, c);
		assert(tree.size() == 0 && tree.empty());
	}

	{
		cerr << "Testing split_range" << endl;
		Treap tree;
		vector<int> a = {3, 1, 4}, b = {1, 5, 9}, c = {2, 6, 5};
		for(auto v : {a, b, c}) {
			for(auto x : v) {
				tree.insert(tree.end(), x);
			}
		}
		auto [L, M, R] = tree.split_range(3, 6);
		check(L, a);
		check(M, b);
		check(R, c);
		assert(tree.size() == 0 && tree.empty());
	}

	{
		cerr << "Testing clear" << endl;
		Treap tree;
		for(int i = 0; i < 100; i++) {
			tree.insert((S) rng());
		}
		tree.clear();
		assert(tree.size() == 0 && tree.empty());
	}
	cerr << "Passed test." << endl;
}
int main() {
	TEST();

	int a, b;
	cin >> a >> b;
	cout << a + b << "\n";
	return 0;
}
