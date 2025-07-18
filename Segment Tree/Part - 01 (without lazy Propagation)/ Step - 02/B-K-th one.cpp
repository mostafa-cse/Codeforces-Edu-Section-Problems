#include <bits/stdc++.h>
#define int long long
using namespace std;
struct SegmentTree {
    vector<int> sgt;
    vector<int> a;
    int n;
    SegmentTree(int N) {
        this->n = N;
        a.assign(N + 1, 0);
        sgt.assign(N * 4 + 1, 0);
    }
    int combine(int a, int b) {
        return a + b;        // ➜ sum
    }
    void build (int node, int l, int r) {
        if (l == r) {
            sgt[node] = a[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        sgt[node] = combine(sgt[2 * node], sgt[2 * node + 1]);
    }
    void update(int node, int l, int r, int idx) {
        if (l == r) {
            sgt[node] = sgt[node] ^ 1;
            return;
        }
        int mid = l + (r - l) / 2;
        if(idx <= mid) {
            update(node * 2, l, mid, idx);
        } else {
            update(node * 2 + 1, mid + 1, r, idx);
        }
        sgt[node] = combine(sgt[2 * node], sgt[2 * node + 1]);
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
        return combine(left, right);
    }
    void build() { build(1, 1, n); }
    void update(int idx) { update(1, 1, n, idx); }
    int query(int l, int r) { return query(1, 1, n, l, r); }
};
signed main() {
    int n, q;
    cin >> n >> q;

    SegmentTree a(n);
    for (int i = 1; i <= n; i++) {
        cin >> a.a[i];
    }
    a.build();
    while (q--) {
        int op;
        cin >> op;

        if (op & 1) {
            int idx;
            cin >> idx;
            idx += 1;
            a.update(idx);
        } else {
            int k;
            cin >> k;
            k += 1;

            int l = 1, r = n, ans = n;
            while (l <= r) {
                int mid = (l + r) / 2;
                int midth = a.query(1, mid);
                if (midth >= k) {
                    r = mid - 1;
                    ans = mid;
                } else {
                    l = mid + 1;
                }
            }
            cout << ans - 1 << endl;
        }
    }
    return 0;
}
