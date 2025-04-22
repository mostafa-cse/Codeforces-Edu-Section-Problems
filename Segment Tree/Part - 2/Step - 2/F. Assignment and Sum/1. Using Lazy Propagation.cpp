#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SegmentTree {
    int n;
    vector<int> tree, lazy;
    vector<bool> is_lazy;

    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        is_lazy.assign(4 * n, false);
    }

    void push(int node, int l, int r) {
        if (is_lazy[node]) {
            tree[node] = (r - l + 1) * lazy[node];
            if (l != r) {
                lazy[2 * node] = lazy[node];
                lazy[2 * node + 1] = lazy[node];
                is_lazy[2 * node] = is_lazy[2 * node + 1] = true;
            }
            is_lazy[node] = false;
        }
    }

    void update(int node, int l, int r, int ul, int ur, int val) {
        push(node, l, r);
        if (r < ul || l > ur) return;
        if (ul <= l && r <= ur) {
            lazy[node] = val;
            is_lazy[node] = true;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ul, ur, val);
        update(2 * node + 1, mid + 1, r, ul, ur, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
    }

    void update(int l, int r, int val) {
        update(1, 1, n, l, r, val);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};

signed main() {
    int n, q;
    cin >> n >> q;

    SegmentTree seg(n);

    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        l++; // shifting to 1-based inclusive

        if (op == 1) {
            int v;
            cin >> v;
            seg.update(l, r, v);
        } else {
            cout << seg.query(l, r) << '\n';
        }
    }

    return 0;
}
