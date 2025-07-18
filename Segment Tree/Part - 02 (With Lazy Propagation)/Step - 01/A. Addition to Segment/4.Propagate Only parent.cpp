#include <bits/stdc++.h> 
using namespace std;

struct segtree {
    int size;
    vector<long long> ops;
    segtree(int n) {
        size = n;
        ops.resize(4 * n + 1);
    }
    void add(int l, int r, int v, int x, int lx, int rx) {
        if (l > rx || r < lx) return;
        if (lx >= l && rx <= r) {
            ops[x] += v;
            return;
        }
        int m = (lx + rx) / 2;
        add(l, r, v, 2 * x, lx, m);
        add(l, r, v, 2 * x + 1, m + 1, rx);
    }

    long long get(int i, int x, int l, int r) {
        if (l == r) {
            return ops[x];
        }
        long long res;
        int m = (l + r) / 2;
        if (i <= m) {
            res = get(i, 2 * x, l, m);
        } else {
            res = get(i, 2 * x + 1, m + 1, r);
        }
        return res + ops[x];
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
            st.add(l, r - 1, v, 1, 1, n);
        } else {
            int i;
            cin >> i;
            i += 1;
            cout << st.get(i, 1, 1, n) << endl;
        }
    }
    return 0;
}
