#include<bits/stdc++.h>
#define int long long
using namespace std;
struct segment_tree {
	int n;
	vector<int> sum, wsum, a, lazy;
	segment_tree(int n) {
		this->n = n;
		a.resize(n + 1, 0);
		sum.assign(n << 2 | 1, 0);
		wsum.assign(n << 2 | 1, 0);
		lazy.assign(n << 2 | 1, 0);
	}
	void build(int node, int l, int r) {
		if (l == r) {
			sum[node] = a[l];
			wsum[node] = a[l] * l;
			return;
		} else {
			int mid = l + r >> 1;
			build(node << 1, l, mid);
			build(node << 1 | 1, mid + 1, r);
			sum[node] = sum[node << 1] + sum[node << 1 | 1];
			wsum[node] = wsum[node << 1] + wsum[node << 1 | 1];
		}
	}
	void propagate(int node, int l, int r) {
		if (lazy[node] == 0) return;
		int len  = (r - l + 1);
		sum[node] += lazy[node] * len;
		wsum[node] += lazy[node] * (len * (l + r)) / 2;
		if (l != r) {
			lazy[node << 1] += lazy[node];
			lazy[node << 1 | 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	void update(int node, int l, int r, int ql, int qr, int v) {
		propagate(node, l, r);
		if (l > qr or r < ql) {
			return;
		} else if (l >= ql and r <= qr) {
			lazy[node] += v;
			propagate(node, l, r);
		} else {
			int mid = l + r >> 1;
			update(node << 1, l, mid, ql, qr, v);
			update(node << 1 | 1, mid + 1, r, ql, qr, v);
			sum[node] = sum[node << 1] + sum[node << 1 | 1];
			wsum[node] = wsum[node << 1] + wsum[node << 1 | 1];
		}
	}
	pair<int ,int> query(int node, int l, int r, int ql ,int qr) {
		propagate(node, l, r);
		if (l > qr or r < ql) {
			return {0, 0};
		} else if (l >= ql and r <= qr) {
			return {sum[node], wsum[node]};
		} else {
			int mid = l + r >> 1;
			pair<int, int> left = query(node << 1, l, mid, ql, qr);
			pair<int, int> right = query(node << 1 | 1, mid + 1, r, ql, qr);
			return {left.first + right.first, left.second + right.second};
		}
	}
};
int32_t main() {
	int n, q;
	cin >> n >> q;

	segment_tree a(n);
	for (int i = 1; i <= n; i++) {
		cin >> a.a[i];
	}
	a.build(1, 1, n);
	while (q--) {
		int op, l, r;
		cin >> op >> l >> r;

		if (op & 1) {
			int v;
			cin >> v;
			a.update(1, 1, n, l, r, v);
		} else {
			pair<int, int> ans = a.query(1, 1, n, l, r);
			cout << ans.second  - (l - 1) * ans.first << endl;
		}
	}
	return 0;
}
