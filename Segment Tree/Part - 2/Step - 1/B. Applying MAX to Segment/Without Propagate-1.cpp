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
        return max(left, right);
    }
    void update(int node, int start, int end, int l, int r, int value){
        if (start > r or end < l) {
            return;
        }
        if (start >= l and  r >= end){
            sgt[node] = combine(value, sgt[node]);
            lazy[node] = combine(value, lazy[node]);
            return;
        }
        int mid = start + (end - start) / 2;
        update(node * 2, start, mid, l, min(r, mid), value);
        update(node * 2 + 1, mid + 1, end, max(l, mid + 1), r, value);
    }
    int query(int node, int start, int end, int ql, int qr) {
        if (start > qr or end < ql) {
            return 0; // Edit here
        }
        if (start >= ql and end <= qr) {
            return sgt[node];
        }
        int mid = start + (end - start) / 2;
        int left = query(node * 2, start, mid, ql, qr);
        int right = query(node * 2 + 1, mid + 1, end, ql, qr);
        return combine(combine(left, right), lazy[node]);
    }
    void update(int l, int r, int val) { update(1, 1, n, l, r, val); }
    int query(int l, int r) { return query(1, 1, n, l, r); }
};  

signed main() {
    int n, q;
    cin >> n >> q;
    
    segment_tree a(n);
    
    while (q--) {
        int op;
        cin >> op;

        if (op & 1) {
            int l, r, v;
            cin >> l >> r >> v;

            l += 1, r += 1;
            a.update(l, r - 1, v);
        } else {
            int i;
            cin >> i;
            i += 1;
            cout << a.query(i, i) << endl;
        }
    }
    return 0;
}
