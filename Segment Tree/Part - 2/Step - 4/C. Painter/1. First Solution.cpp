#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node {
	int block, len, l, r;
	Node(): block(0), len(0), l(0), r(0) {}
	Node operator+(const Node &o) {
		Node res;
		res.block = block + o.block - (r & o.l);
		res.len = len + o.len;
		res.l = l;
		res.r = o.r;
		return res;
	}
	Node(int l, int r, int color) {
		this->block = color;
		this->len = (r - l + 1) * color;
		this->l = color;
		this->r = color;
	}
};
struct segment_tree {
	vector<Node> tree;
	vector<int> lazy;
	int n;
	segment_tree(int n) {
		this->n = n;
		tree.resize(4 * n + 1, Node());
		lazy.resize(4 * n + 1, -1);
	}
	void propagate(int node, int l, int r) {
		if (lazy[node] == -1) return;

		tree[node] = Node(l, r, lazy[node]);
		if (l != r) {
			lazy[node << 1] = lazy[node];
			lazy[node << 1 | 1] = lazy[node];
		}
		lazy[node] = -1;
	}
	void update(int node, int l, int r, int ql, int qr, int val) {
		propagate(node, l, r);
		if (l > qr or r < ql) {
			return;
		} else if (l >= ql and r <= qr) {
			lazy[node] = val;
			propagate(node, l, r);
		} else {
			int mid = (l + r) >> 1;
			update(node << 1, l, mid, ql, qr, val);
			update(node << 1 | 1, mid + 1, r, ql, qr, val);

			tree[node] = tree[node << 1] + tree[node << 1 | 1];
		}
	}
};
int32_t main() {
	int q;
	cin >> q;
	
	const int N =  1000000;
	const int offset =  500000;
	segment_tree a(N);

	while (q--) {
		char c;
		int l, x;
		cin >> c >> l >> x;

		l += offset; // ignore negative number
		l += 1; // 1-based
		a.update(1, 1, N, l, l + x - 1, c == 'B');
		cout << a.tree[1].block << " " << a.tree[1].len << endl;
	}
    return 0;
}
