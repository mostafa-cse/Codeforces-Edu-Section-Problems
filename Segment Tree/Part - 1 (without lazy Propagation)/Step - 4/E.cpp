#include <bits/stdc++.h>
#define int long long
using namespace std;
struct SegmentTree {
    vector<int> sgt;
    int n;
    SegmentTree(int N) {
        this->n = N;
        sgt.assign(N * 4 + 1, INT_MAX);
    }
    int combine(int a, int b) {
        return min(a, b);    // ➜ min
    }
    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            sgt[node] = value;
            return;
        }
        int mid = l + (r - l) / 2;
        if(idx <= mid) {
            update(node * 2, l, mid, idx, value);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, value);
        }
        sgt[node] = min(sgt[2 * node], sgt[2 * node + 1]);
    }
    int query(int node, int l, int r, int ql, int qr, int val) {
        if (l > qr or r < ql or sgt[node] > val) {
            return 0; // Edit here
        }
        if (l >= ql and r <= qr) {
            if (l == r) {
                sgt[node] = INT_MAX;
                return 1;
            }
        }
        int mid = l + (r - l) / 2;
        int left = query(node * 2, l, mid, ql, qr, val);
        int right = query(node * 2 + 1, mid + 1, r, ql, qr, val);
        
        sgt[node] = min(sgt[2 * node], sgt[2 * node + 1]);
        return (left + right);
    }
    void update(int idx, int val) { update(1, 1, n, idx, val); }
    int query(int l, int r, int val) { return query(1, 1, n, l, r, val); }
};
signed main() {
    int n, q;
    cin >> n >> q;

    SegmentTree a(n);
    while (q--) {
        int c;
        cin >> c;

        if (c & 1) {
            int idx, val;
            cin >> idx >> val;
            idx += 1;
            a.update(idx, val);
        } else {
            int l, r, val;
            cin >> l >> r >> val;
            l += 1, r += 1;
            cout << a.query(l, r - 1, val) << endl;
        }
    }
    return 0;
}
