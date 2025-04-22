#include <bits/stdc++.h>
#define int long long
using namespace std;
struct SegmentTree {
    vector<int> sgt;
    int n;
    SegmentTree(int N) {
        this->n = N;
        sgt.assign(N * 4 + 1, 0);
    }
    int combine(int a, int b) {
        return a + b;        // ➜ sum
    }
    void update(int node, int l, int r, int ql, int qr, int value) {
        if (ql > qr) return;
        if (ql == l and qr == r) {
            sgt[node] += value;
            return;
        }
        int mid = l + (r - l) / 2;
        update(node * 2, l, mid, ql, min(qr, mid), value);
        update(node * 2 + 1, mid + 1, r, max(ql, mid + 1), qr, value);
    }
    int query(int node, int l, int r, int idx) {
        if (l == r) {
            return sgt[node];
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            return query(node * 2, l, mid, idx) + sgt[node];
        } else {
            return query(node * 2 + 1, mid + 1, r, idx) + sgt[node];
        }
    }
    void update(int l, int r, int val) { update(1, 1, n, l, r, val); }
    int query(int l) { return query(1, 1, n, l); }
};
signed main() {
    int n, q;
    cin >> n >> q;

    SegmentTree a(n);
    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            l += 1, r += 1;
            a.update(l, r - 1, v);
        } else {
            int i;
            cin >> i;
            i += 1;
            cout << a.query(i) << endl;
        }
    }
    return 0;
}
