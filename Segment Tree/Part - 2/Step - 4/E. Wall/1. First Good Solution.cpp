#include <bits/stdc++.h>
#define int long long
using namespace std;
struct segment_tree {
	vector<pair<int, int>> lazy;
	vector<int> a;
	segment_tree(int n) {
		lazy.assign(n << 2 | 1, {0, 1e18});
		a.resize(n + 1);
	}
	void propagate(int node, int l, int r) {
		if (l == r) {
			// Addition must be Max              removal should be Min
			a[l] = min(max(lazy[node].first, a[l]), lazy[node].second);
		} else {
			if (lazy[node].first != 0) {
 				lazy[node << 1] = {max(lazy[node << 1].first, lazy[node].first), max(lazy[node << 1].second, lazy[node].first)};
 				lazy[node << 1 | 1] = {max(lazy[node << 1 | 1].first, lazy[node].first), max(lazy[node << 1 | 1].second, lazy[node].first)};
			}
			if (lazy[node].second != 1e18) {
 				lazy[node << 1] = {min(lazy[node << 1].first, lazy[node].second), min(lazy[node << 1].second, lazy[node].second)};
 				lazy[node << 1 | 1] = {min(lazy[node << 1 | 1].first, lazy[node].second), min(lazy[node << 1 | 1].second, lazy[node].second)};
			}
		}
		lazy[node] = {0, 1e18};
	}
	void update(int node, int l, int r, int ql, int qr, int val, int op) {
		propagate(node, l, r);
		if (l > qr or r < ql) {
			return;
		} else if (l >= ql and r <= qr) {
			if (op == 1) { // Adding -> Max
				lazy[node].first = max(lazy[node].first, val);
			} else { // Remove -> Min
				lazy[node].second = min(lazy[node].second, val);
			}
			propagate(node, l, r);
		} else {
			int mid = l + r >> 1;
			update(node << 1, l, mid, ql, qr, val, op);
			update(node << 1 | 1, mid + 1, r, ql, qr, val, op);
		}
	}
	void relaxation(int node, int l, int r) {
		propagate(node, l, r);
		if (l == r) {
			return;
		}
		int mid = l + r >> 1;
		relaxation(node << 1, l, mid);
		relaxation(node << 1 | 1, mid + 1, r);
	}
};
int32_t main() {
	int n, q;
	cin >> n >> q;

	segment_tree a(n);

	while (q--) {
		int t, l, r, h;
		cin >> t >> l >> r >> h;
		l += 1, r += 1;
		a.update(1, 1, n, l, r, h, t);
	}
	a.relaxation(1, 1, n);

	for (int i = 1; i <= n; i++) {
		cout << a.a[i] << " ";
	}
	return 0;
}
