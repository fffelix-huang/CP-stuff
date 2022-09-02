struct Node {
	long long val;
	long long sum;
	bool rev;
	int size;
	int pri;
 
	Node* l;
	Node* r;
 
	Node(long long x) : val(x), sum(x), rev(false), size(1), pri(rng()), l(NULL), r(NULL) {}
};
 
inline int size(Node*& v) {
	return (v ? v->size : 0);
}
 
void pull(Node*& v) {
	v->size = 1 + size(v->l) + size(v->r);
	v->sum = v->val + (v->l ? v->l->sum : 0) + (v->r ? v->r->sum : 0);
}
 
void push(Node*& v) {
	if(v->rev) {
		swap(v->l, v->r);
		if(v->l) {
			v->l->rev = !v->l->rev;
		}
		if(v->r) {
			v->r->rev = !v->r->rev;
		}
		v->rev = false;
	}
}
 
Node* merge(Node* a, Node* b) {
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
 
void split(Node* v, Node*& a, Node*& b, int k) {
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
