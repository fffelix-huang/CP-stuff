#pragma once
#include <vector>
#include <set>
#include <iterator>
#include <cassert>

namespace felix {

std::vector<std::pair<int, int>> prufer(const std::vector<int>& a) {
	assert(!a.empty());
	int n = (int) a.size() + 2;
	std::vector<int> deg(n);
	for(auto x : a) {
		deg[x]++;
	}
	std::set<int> leaf;
	for(int i = 0; i < n; i++) {
		if(deg[i] == 0) {
			leaf.insert(leaf.end(), i);
		}
	}
	std::vector<std::pair<int, int>> edges;
	for(auto u : a) {
		auto v = *leaf.begin();
		leaf.erase(leaf.begin());
		edges.emplace_back(u, v);
		deg[u]--;
		if(deg[u] == 0) {
			leaf.insert(u);
		}
	}
	assert(leaf.size() == 2);
	edges.emplace_back(*leaf.begin(), *std::next(leaf.begin()));
	return edges;
}

} // namespace felix
