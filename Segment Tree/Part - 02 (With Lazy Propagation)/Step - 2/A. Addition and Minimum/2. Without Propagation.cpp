#include <bits/stdc++.h>
#define int long long
using namespace std;
struct segment_tree{
    vector<int> sgt, lazy;
    int n;
    segment_tree(int N) {
        this->n = N;
        sgt.assign(N * 4, 0);
        lazy.assign(N * 4, 0);
    }
    int combine(int left, int right) {
        return min(left, right);
    }
    int update_combine(int left, int right) {
        return left + right;
    }
    void update(int node, int start, int end, int l, int r, int value){
        if (l > r) {
            return;
        }
        if (start == l and  r == end){
            sgt[node] += value;
            lazy[node] += value;
            return;
        }
        int mid = start + (end - start) / 2;
        update(node * 2, start, mid, l, min(r, mid), value);
        update(node * 2 + 1, mid + 1, end, max(l, mid + 1), r, value);
        sgt[node] = update_combine(combine(sgt[2 * node], sgt[2 * node + 1]), lazy[node]); // additive associative property
    }
    int query(int node, int start, int end, int ql, int qr) {
        if (ql > qr) {
            return 1e18; // Edit here
        }
        if (start == ql and end == qr) {
            return sgt[node];
        }
        int mid = start + (end - start) / 2;
        int left = query(node * 2, start, mid, ql, min(qr, mid));
        int right = query(node * 2 + 1, mid + 1, end, max(ql, mid + 1), qr);
        return update_combine(combine(left, right), lazy[node]);
    }
    void update(int l, int r, int val) { update(1, 1, n, l, r, val); }
    int query(int l, int r) { return query(1, 1, n, l, r); }
};  

signed main() {
    int n, q;
    cin >> n >> q;

    segment_tree a(n);
    while (q--) {
        int op, l, r, v;
        cin >> op >> l >> r;
        l += 1, r += 1;
        if (op & 1) {
            cin >> v;
            a.update(l, r - 1, v);
        } else {
            cout << a.query(l, r - 1) << endl;
        }
    }
    return 0;
}
