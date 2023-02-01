template<class S, bool (*op)(S, S)>
class SkewHeap {
public:
	struct Node {
		S val;
		Node* l;
		Node* r;

		Node() : l(NULL), r(NULL) {}
		Node(const S& s) : Node(s, NULL, NULL) {}
		Node(const S& s, Node* L, Node* R) : val(s), l(L), r(R) {}
	};

	static Node* merge(Node* a, Node* b) {
		if(!a || !b) {
			return (a ? a : b);
		}
		if(!op(a->val, b->val)) {
			swap(a, b);
		}
		swap(a->l, a->r);
		a->l = merge(a->l, b);
		return a;
	}

	static void pop(Node*& a) {
		a = merge(a->l, a->r);
	}
};

using S = int;

inline bool op(S a, S b) {
	return a < b;
}

using Heap = SkewHeap<S, op>;
