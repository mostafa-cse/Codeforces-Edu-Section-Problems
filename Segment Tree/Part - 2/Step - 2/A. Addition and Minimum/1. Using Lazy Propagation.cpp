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
    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            // sgt[node] += (end - start + 1) * lazy[node]; // Sum
            sgt[node] += lazy[node];                     // max-min
            if (start != end) {
                lazy[node * 2]     += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    int combine(int left, int right) {
        return min(left ,right);
    }
    void update(int node, int start, int end, int l, int r, int value){
        push(node, start, end);
        if (start > r or end < l) {
            return;
        }
        
        if (start >= l and  r >= end){
            lazy[node] += value;
            push(node, start, end);
            return;
        }
        int mid = start + (end - start) / 2;
        update(node * 2, start, mid, l, r, value);
        update(node * 2 + 1, mid + 1, end, l, r, value);
        sgt[node] = combine(sgt[2 * node], sgt[2 * node + 1]);
    }
    int query(int node, int start, int end, int ql, int qr) {
        push(node, start, end);
        if (start > qr or end < ql) {
            return 1e19; // Edit here
        }
        if (start >= ql and end <= qr) {
            return sgt[node];
        }
        int mid = start + (end - start) / 2;
        int left = query(node * 2, start, mid, ql, qr);
        int right = query(node * 2 + 1, mid + 1, end, ql, qr);
        return combine(left, right);
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
            int l, r;
            cin >> l >> r;
            l += 1, r += 1;
            cout << a.query(l, r - 1) << endl;
        }
    }
    return 0;
}
