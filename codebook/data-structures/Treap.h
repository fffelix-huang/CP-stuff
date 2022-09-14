template<class S,
         S (*e)(),
         S (*op)(S, S),
         class F,
         F (*id)(),
         S (*mapping)(F, S),
         F (*composition)(F, F)>
class Treap {
public:
	struct Node {
		S val;
		S range;
		F tag;
		bool rev;
		int size;
		int pri;
		Node* l;
		Node* r;

		Node() : Node(e()) {}
		Node(const S& s) : val(s), range(s), tag(id()), rev(false), size(1), pri(rng()), l(NULL), r(NULL) {}
	};

	static int size(Node*& v) {
		return (v ? v->size : 0);
	}

	static Node* merge(Node* a, Node* b) {
		if(!a || !b) {
			return (a ? a : b);
		}
		push(a);
		push(b);
		if(a->pri > b->pri) {
			a->r = merge(a->r, b);
			pull(a);
			return a;
		} else {
			b->l = merge(a, b->l);
			pull(b);
			return b;
		}
	}

	static void split(Node* v, Node*& a, Node*& b, int k) {
		if(k == 0) {
			a = NULL;
			b = v;
			return;
		}
		push(v);
		if(size(v->l) >= k) {
			b = v;
			split(v->l, a, v->l, k);
			pull(b);
		} else {
			a = v;
			split(v->r, v->r, b, k - size(v->l) - 1);
			pull(a);
		}
	}

	// static void print(Node* v) {
	// 	if(!v) {
	// 		return;
	// 	}
	// 	push(v);
	// 	print(v->l);
	// 	cout << v->val << " ";
	// 	print(v->r);
	// }

private:
	static void pull(Node*& v) {
		v->size = 1 + size(v->l) + size(v->r);
		v->range = v->val;
		if(v->l) {
			v->range = op(v->l->range, v->range);
		}
		if(v->r) {
			v->range = op(v->range, v->r->range);
		}
	}

	static void push(Node*& v) {
		if(v->rev) {
			swap(v->l, v->r);
			if(v->l) {
				v->l->rev ^= 1;
			}
			if(v->r) {
				v->r->rev ^= 1;
			}
			v->rev = false;
		}
		if(v->tag != id()) {
			v->val = mapping(v->tag, v->val);
			if(v->l) {
				v->l->tag = composition(v->tag, v->l->tag);
			}
			if(v->r) {
				v->r->tag = composition(v->tag, v->r->tag);
			}
			v->tag = id();
		}
	}
};

using TP = Treap<S, e, op, F, id, mapping, composition>;
