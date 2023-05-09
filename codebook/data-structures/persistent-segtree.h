// https://codeforces.com/contest/1824/submission/205101895
template<class S, S (*e)(), S (*op)(S, S)>
struct persistent_segtree {
    struct Root {
        int id;
    };

    persistent_segtree() : persistent_segtree(0) {}
    explicit persistent_segtree(int _n) : persistent_segtree(std::vector<S>(_n, e())) {}
    explicit persistent_segtree(const std::vector<S> &v) : n(v.size()) {
        lg = std::__lg(2 * n - 1);
        size = 1 << lg;
        d = std::vector<S>(2 * size, e());
        left = right = std::vector<int>(2 * size, -1);
        for(int i = 0; i < n; i++) {
            d[size + i] = v[i];
        }
        for(int i = size - 1; i >= 1; i--) {
            left[i] = 2 * i;
            right[i] = 2 * i + 1;
            d[i] = op(d[2 * i], d[2 * i + 1]);
        }
    }
 
    Root set(const Root &root, int p, const S &x) {
        assert(0 <= p && p < n);
        static std::vector<int> ids;
        if((int) ids.size() < lg + 1) {
            ids.resize(lg + 1, -1);
        }
        ids[lg] = root.id;
        for(int i = lg - 1; i >= 0; i--) {
            ids[i] = (p >> i & 1) ? right[ids[i + 1]] : left[ids[i + 1]];
        }
        int copy_cur = (int) d.size();
        d.push_back(x);
        left.push_back(-1);
        right.push_back(-1);
        for(int i = 1; i <= lg; i++) {
            const int par = ids[i], cur = ids[i - 1];
            const int copy_par = d.size();
            left.push_back(left[par] == cur ? copy_cur : left[par]);
            right.push_back(right[par] == cur ? copy_cur : right[par]);
            d.push_back(op(d[left.back()], d[right.back()]));
            copy_cur = copy_par;
        }
        return Root{copy_cur};
    }
 
    S prod(const Root &root, int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        auto rec = [&](auto&& self, int v, int low, int high) -> S {
            if(r <= lo || hi <= l) {
                return e();
            }
            if(l <= lo && hi <= r) {
                return d[v];
            }
            int mid = (low + high) / 2;
            return op(self(self, left[v], low, mid), self(self, right[v], mid, high));
        };
        return rec(rec, root.id, 0, size);
    }
 
    S all_prod(const Root &root) const { return d[root.id]; }
 
    Root get_root() const { return {1}; }
 
private:
    int n, size, lg;
    std::vector<S> d;
    std::vector<int> left, right;
};