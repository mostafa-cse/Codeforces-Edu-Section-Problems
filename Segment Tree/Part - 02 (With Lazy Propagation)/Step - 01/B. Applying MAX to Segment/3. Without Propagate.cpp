#include <bits/stdc++.h> 
using namespace std;

struct segtree {
    int size;
    vector<int> ops;
    segtree(int n) {
        size = n;
        ops.resize(4 * n + 1);
    }
    void add(int node, int l, int r, int ql, int qr, int v) {
        if (ql > r or qr < l) return;
        if (l >= ql and r <= qr) {
            ops[node] = max(v, ops[node]);
            return;
        }
        int m = (l + r) / 2;
        add(2 * node, l, m, ql, qr, v);
        add(2 * node + 1, m + 1, r, ql, qr, v);
    }

    long long get(int node, int l, int r,int idx) {
        if (l == r) {
            return ops[node];
        }
        int res;
        int m = (l + r) / 2;
        if (idx <= m) {
            res = get(2 * node, l, m, idx);
        } else {
            res = get(2 * node + 1, m + 1, r, idx);
        }
        return max(res, ops[node]);
    }
};
 
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
 
    int n, m;
    cin >> n >> m;
    segtree st(n);

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            l += 1, r += 1;
            st.add(1, 1, n, l, r - 1, v);
        } else {
            int i;
            cin >> i;
            i += 1;
            cout << st.get(1, 1, n, i) << endl;
        }
    }
    return 0;
}
