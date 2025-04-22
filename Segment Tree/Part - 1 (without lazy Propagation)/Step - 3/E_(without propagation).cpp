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
        return left + right;
    }
    void update(int node, int start, int end, int l, int r, int value){
        if (l > r) {
            return;
        } else if (start == l and  r == end){
            sgt[node] += value;
            lazy[node] += value;
        } else {
            int mid = start + (end - start) / 2;
            update(node * 2, start, mid, l, min(r, mid), value);
            update(node * 2 + 1, mid + 1, end, max(l, mid + 1), r, value);
        }
    }
    int query(int node, int start, int end, int idx) {
        if (start > idx or end < idx) {
            return 0; // Edit here
        } else if (start == idx and end == idx) {
            return sgt[node];
        } else {
            int mid = start + (end - start) / 2;
            int left = query(node * 2, start, mid, idx);
            int right = query(node * 2 + 1, mid + 1, end, idx);
            return combine(left, right) + lazy[node];
        }
    }
    void update(int l, int r, int val) { update(1, 1, n, l, r, val); }
    int query(int idx) { return query(1, 1, n, idx); }
};  

signed main() {
    int n, q;
    cin >> n >> q;

    segment_tree a(n);
    while (q--) {
        int op, l, r, v;
        cin >> op;

        if (op & 1) {
            cin >> l >> r >> v;
            l += 1, r += 1;
            a.update(l, r - 1, v);
        } else {
            cin >> l;
            l += 1;
            cout << a.query(l) << endl;
        }
    }
    return 0;
}
