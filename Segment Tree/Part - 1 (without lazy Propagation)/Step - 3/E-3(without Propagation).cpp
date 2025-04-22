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
    void update(int idx, int sl, int sr, int l, int r, int val) {
        if (sl > r or sr < l) {
            return;
        } else if(sl >= l and sr <= r) {
            sgt[idx] += val;
            lazy[idx] += val;
        } else {
            int mid = (sl + sr) / 2;
            update(2 * idx, sl, mid, l, r, val);
            update(2 * idx + 1, mid + 1, sr, l, r, val);
        }
    }
    int query(int node, int start, int end, int idx) {
        if (start == end) {
            return sgt[node];
        } 
        int mid = (start + end) / 2;
        
        int ans = 0;
        if(idx > mid) {
            ans = query(2 * node + 1, mid + 1, end, idx);
        } else {
            ans = query(2 * node, start, mid, idx);
        }
        return combine(ans, lazy[node]);
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
