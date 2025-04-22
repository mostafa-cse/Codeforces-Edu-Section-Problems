#include <bits/stdc++.h>
#define int long long
using namespace std;
struct segment_tree{
    vector<pair<int, int>> sgt, lazy;
    int n;
    segment_tree(int N) {
        this->n = N;
        sgt.assign(N * 4, {0, 0});
        lazy.assign(N * 4, {0, 0});
    }
    pair<int, int> combine(pair<int, int> left, pair<int, int> right) {
        if (left.second > right.second) return left;
        return right;
    }
    void push(int node, int start, int end) {
        if (lazy[node].second != 0) {
            sgt[node] = combine(sgt[node], lazy[node]); // max-min
            if (start != end) {
                lazy[node * 2] = combine(lazy[node * 2], lazy[node]);
                lazy[node * 2 + 1] = combine(lazy[node], lazy[node * 2 + 1]);
            }
            lazy[node] = {0, 0};
        }
    }
    void update(int node, int start, int end, int l, int r, int value, int id){
        push(node, start, end);
        if (start > r or end < l) {
            return;
        }
        
        if (start >= l and  r >= end){
            lazy[node] = {value, id};
            push(node, start, end);
            return;
        }
        int mid = start + (end - start) / 2;
        update(node * 2, start, mid, l, r, value, id);
        update(node * 2 + 1, mid + 1, end, l, r, value, id);
        sgt[node] = min(sgt[2 * node], sgt[2 * node + 1]);
    }
    pair<int, int> query(int node, int start, int end, int ql, int qr) {
        push(node, start, end);
        if (start > qr or end < ql) {
            return {1e18, 0}; // Edit here
        }
        if (start >= ql and end <= qr) {
            return sgt[node];
        }
        int mid = start + (end - start) / 2;
        pair<int ,int> left = query(node * 2, start, mid, ql, qr);
        pair<int ,int> right = query(node * 2 + 1, mid + 1, end, ql, qr);
        return min(left, right);
    }
    void update(int l, int r, int val, int id) { update(1, 1, n, l, r, val, id); }
    int query(int l, int r) { return query(1, 1, n, l, r).first; }
};  
signed main() {
    int n, q;
    cin >> n >> q;

    segment_tree a(n);
    int id = 1;
    while (q--) {
        int op, l, r, v;
        cin >> op >> l >> r;
        l += 1, r += 1;

        if (op & 1) {
            cin >> v;
            a.update(l, r - 1, v, id++);
        } else {
            cout << a.query(l, r - 1) << endl;
        }
    }
    return 0;
}
