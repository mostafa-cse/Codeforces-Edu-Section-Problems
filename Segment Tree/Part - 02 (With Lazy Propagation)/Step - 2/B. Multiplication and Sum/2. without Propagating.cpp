#include <bits/stdc++.h>
#define int long long
using namespace std;
struct segment_tree{
    const int Mod = 1e9 + 7;
    vector<int> a;
    vector<int> sgt, lazy;
    int n;
    segment_tree(int N) {
        this->n = N;
        a.assign(N + 1, 0);
        sgt.assign(N * 4, 0);
        lazy.assign(N * 4, 1);
    }
    int combine(int left, int right) {
        return (left + right) % Mod;
    }
    void build(int node, int start, int end){
        if (start == end) {
            sgt[node] = a[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        sgt[node] = combine(sgt[2 * node], sgt[2 * node + 1]);
    }
    void update(int node, int start, int end, int l, int r, int value){
        if (end < l or r < start) {
            return;
        }
        if (start >= l and  r >= end) {
            (lazy[node] *= value) %= Mod;
            (sgt[node] *= value) %= Mod;
            return;
        }
        int mid = start + (end - start) / 2;
        update(node * 2, start, mid, l, r, value);
        update(node * 2 + 1, mid + 1, end, l, r, value);
        sgt[node] = (combine(sgt[2 * node], sgt[2 * node + 1]) * lazy[node]) % Mod;
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
        return (combine(left, right) * lazy[node]) % Mod;
    }
    void build() { build(1, 1, n); }
    void update(int l, int r, int val) { update(1, 1, n, l, r, val); }
    int query(int l, int r) { return query(1, 1, n, l, r); }
};  

signed main() {
    int n, q;
    cin >> n >> q;
    
    segment_tree a(n);

    // initially filled with ones
    fill(a.a.begin(), a.a.end(), 1);
    a.build();

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
