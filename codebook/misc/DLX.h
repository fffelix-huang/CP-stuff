// modified from OI-wiki
struct DLX {
	int n, m, tot, ans;
	vector<int> first, siz, L, R, U, D, col, row, stk;

	DLX(int _n, int _m) : n(_n), m(_m), tot(_m) {
		int sz = n * m;
		first.resize(sz);
		siz.resize(sz);
		L.resize(sz);
		R.resize(sz);
		U.resize(sz);
		D.resize(sz);
		col.resize(sz);
		row.resize(sz);
		stk.resize(sz);
		for(int i = 0; i <= m; i++) {
			L[i] = i - 1, R[i] = i + 1;
			U[i] = D[i] = i;
		}
		L[0] = m, R[m] = 0;
	}

	void insert(int r, int c) {
		r++, c++;
		col[++tot] = c, row[tot] = r, ++siz[c];
		D[tot] = D[c], U[D[c]] = tot, U[tot] = c, D[c] = tot;
		if(!first[r]) {
			first[r] = L[tot] = R[tot] = tot;
		} else {
			R[tot] = R[first[r]], L[R[first[r]]] = tot;
			L[tot] = first[r], R[first[r]] = tot;
		}
	}

	void remove(int c) {
		int i, j;
		L[R[c]] = L[c], R[L[c]] = R[c];
		for(i = D[c]; i != c; i = D[i]) {
			for(j = R[i]; j != i; j = R[j]) {
				U[D[j]] = U[j], D[U[j]] = D[j];
				siz[col[j]]--;
			}
		}
	}

	void recover(int c) {
		int i, j;
		for(i = U[c]; i != c; i = U[i]) {
			for(j = L[i]; j != i; j = L[j]) {
				U[D[j]] = D[U[j]] = j;
				siz[col[j]]++;
			}
		}
		L[R[c]] = R[L[c]] = c;
	}

	bool dance(int dep) {
		if(!R[0]) {
			ans = dep;
			return true;
		}
		int i, j, c = R[0];
		for(i = R[0]; i != 0; i = R[i]) {
			if(siz[i] < siz[c]) {
				c = i;
			}
		}
		remove(c);
		for(i = D[c]; i != c; i = D[i]) {
			stk[dep] = row[i];
			for(j = R[i]; j != i; j = R[j]) {
				remove(col[j]);
			}
			if(dance(dep + 1)) {
				return true;
			}
			for(j = L[i]; j != i; j = L[j]) {
				recover(col[j]);
			}
		}
		recover(c);
		return false;
	}

	vector<int> solve() {
		if(!dance(1)) {
			return {};
		}
		return vector<int>(stk.begin() + 1, stk.begin() + ans);
	}
};
