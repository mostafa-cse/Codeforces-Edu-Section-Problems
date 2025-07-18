#include<bits/stdc++.h>
#define int long long
using namespace std;

struct SegmentTree {
    vector<int> a, sgt;
    SegmentTree(int N) {
        a.assign(N + 1, 0);
        sgt.assign(N * 4 + 1, 0);
    }
    void merge(int node) {
        sgt[node] = sgt[node * 2] + sgt[node * 2 + 1];      // Sum
    }
    int Ans(int left, int right) {
        return left + right;
    }
    void build (int node, int l, int r) {
        if (l == r) {
            sgt[node] = a[l] * ((l & 1) ? -1 : 1);
            return;
        }
        int mid = l + (r - l) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        merge(node);
    }
    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            sgt[node] = value * ((idx & 1) ? -1 : 1);
            return;
        }
        int mid = l + (r - l) / 2;
        if(idx <= mid) {
            update(node * 2, l, mid, idx, value);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, value);
        }
        merge(node);
    }
    int query(int node, int l, int r, int ql, int qr) {
        if (l > qr or r < ql) {
            return 0; // Edit here
        }
        if (l >= ql and r <= qr) {
            return sgt[node];
        }
        int mid = l + (r - l) / 2;
        int left = query(node * 2, l, mid, ql, qr);
        int right = query(node * 2 + 1, mid + 1, r, ql, qr);
        return Ans(left, right);
    }
};
signed main() {
    int n;
    cin >> n;
    SegmentTree a(n);
    for (int i = 1; i <= n; i++) {
        cin >> a.a[i];
    }
    a.build(1, 1, n);
    
    int m;
    cin >> m;
    while (m--) {
        int c;
        cin >> c;
        if (!c) {
            int i, j;
            cin >> i >> j;
            a.update(1, 1, n, i, j);
        } else {
            int l, r;
            cin >> l >> r;

            int ans = a.query(1, 1, n, l, r);
            cout << ans * (l & 1 ? -1 : 1) << endl;
        }
    }
    return 0;
}
