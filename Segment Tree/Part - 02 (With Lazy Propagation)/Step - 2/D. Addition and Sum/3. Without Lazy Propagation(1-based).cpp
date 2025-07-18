#include<bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
string cdn[2] = {"YES", "NO"};
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif
struct segment_tree {
	int size;
	vector<int> operation;
	vector<int> values;

	int NEUTRAL_ELEMENT = 0;

	int modify_op(int a, int b, int len) {
		return a + b * len;
	}

	int calc_op(int a, int b) {
		return a + b;
	}

	void apply_mod_op(int &a, int b, int len) {
		a = modify_op(a, b, len);
	}

	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		operation.assign(size * 2 + 1, 0);
		values.assign(size * 2 + 1, 0);
	}

	void Modify(int node, int l, int r, int ql, int qr, int val) {
		if (l > qr or r < ql) {
			return;
		} else if (l >= ql and r <= qr) {
			apply_mod_op(operation[node], val, 1);
			apply_mod_op(values[node], val, r - l + 1);
		} else {
			int mid = (l + r) / 2;
			Modify(node * 2, l, mid, ql, qr, val);
			Modify(node * 2 + 1, mid + 1, r, ql, qr, val);
			values[node] = calc_op(values[2 * node], values[2 * node + 1]);
			apply_mod_op(values[node], operation[node], r - l + 1);
		}
	}

	int query(int node, int l, int r, int ql, int qr) {
		if (l > qr or r < ql) {
			return NEUTRAL_ELEMENT;
		} else if (l >= ql and r <= qr) {
			return values[node];
		} else {
			int mid = (l + r) / 2;
			int left = query(node * 2, l, mid, ql, qr);
			int right = query(node * 2 + 1, mid + 1, r, ql, qr);
			int ans = calc_op(left, right);
			apply_mod_op(ans, operation[node],min(qr, r) - max(ql, l) + 1);
			return ans;
		}
	}
};
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
    int n, q;
    cin >> n >> q;

    segment_tree a;
    a.init(n);

    while (q--) {
    	int op, l, r, v;
    	cin >> op >> l >> r;

    	l += 1, r += 1;

    	if (op & 1) {
    		cin >> v;
    		a.Modify(1, 1, n, l, r - 1, v);
    	} else {
    		cout << a.query(1, 1, n, l, r - 1) << endl;
    	}
    }
    return 0;
}
