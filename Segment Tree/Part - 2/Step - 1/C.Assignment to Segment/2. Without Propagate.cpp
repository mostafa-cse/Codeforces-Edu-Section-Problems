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
    void update(int node, int start, int end, int l, int r, int value, int id){
        if (start > r or end < l) {
            return;
        }
        if (start >= l and  r >= end){
            sgt[node] = combine({value, id}, sgt[node]);
            lazy[node] = combine({value, id}, lazy[node]);
            return;
        }
        int mid = start + (end - start) / 2;
        update(node * 2, start, mid, l, min(r, mid), value, id);
        update(node * 2 + 1, mid + 1, end, max(l, mid + 1), r, value, id);
    }
    pair<int, int> query(int node, int start, int end, int idx) {
        if (start > idx or end < idx) {
            return {0, 0}; // Edit here
        }
        if (start >= idx and end <= idx) {
            return sgt[node];
        }
        int mid = start + (end - start) / 2;
        pair<int, int> left = query(node * 2, start, mid, idx);
        pair<int, int> right = query(node * 2 + 1, mid + 1, end, idx);
        return combine(combine(left, right), lazy[node]);
    }
    void update(int l, int r, int val, int id) { update(1, 1, n, l, r, val, id); }
    pair<int, int> query(int idx) { return query(1, 1, n, idx); }
};  

signed main() {
    int n, q;
    cin >> n >> q;

    int id = 1;
    segment_tree a(n);
    while (q--) {
        int op;
        cin >> op;

        if (op & 1) {
            int l, r, v;
            cin >> l >> r >> v;
            a.update(l + 1, r, v, id++);
        } else {
            int i;
            cin >> i;
            cout << a.query(i + 1).first << endl;
        }
    }
    return 0;
}
