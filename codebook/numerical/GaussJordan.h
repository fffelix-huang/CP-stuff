int GaussJordan(vector<vector<ld>>& a) {
	// -1 no sol, 0 inf sol
	int n = SZ(a);
	REP(i, n) assert(SZ(a[i]) == n + 1);
	REP(i, n) {
		int p = i;
		REP(j, n) {
			if(j < i && abs(a[j][j]) > EPS) continue;
			if(abs(a[j][i]) > abs(a[p][i])) p = j;
		}
		REP(j, n + 1) swap(a[i][j], a[p][j]);
		if(abs(a[i][i]) <= EPS) continue;
		REP(j, n) {
			if(i == j) continue;
			ld delta = a[j][i] / a[i][i];
			FOR(k, i, n + 1) a[j][k] -= delta * a[i][k];
		}
	}
	bool ok = true;
	REP(i, n) {
		if(abs(a[i][i]) <= EPS) {
			if(abs(a[i][n]) > EPS) return -1;
			ok = false;
		}
	}
	return ok;
}
