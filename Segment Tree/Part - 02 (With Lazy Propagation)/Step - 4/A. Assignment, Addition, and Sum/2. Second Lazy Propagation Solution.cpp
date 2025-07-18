#include <bits/stdc++.h>
using namespace std;
#define int long long
int tree[1000000], op[1000000], lazy[1000000];
void propagate(int node, int l, int r) {
    if (op[node] == 1) { // assignment
        tree[node] = 0;
        lazy[node << 1] = lazy[node << 1 | 1] = 0;
        op[node << 1] = op[node << 1 | 1] = 1;
    }
    tree[node] += lazy[node] * (r - l + 1);
    lazy[node << 1] += lazy[node];
    lazy[node << 1 | 1] += lazy[node];
    op[node] = lazy[node] = 0;
}
void update(int node, int l, int r, int ql, int qr, int val, int type) {
    propagate(node, l, r);
    if (l > qr || r < ql) {
        return;
    } else if (l >= ql && r <= qr) {
        lazy[node] += val;
        op[node] = type;
        propagate(node, l, r);
    } else {
        int mid = (l + r) >> 1;
        update(node << 1, l, mid, ql, qr, val, type);
        update(node << 1 | 1, mid + 1, r, ql, qr, val, type);
        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }
}
int get(int node, int l, int r, int ql, int qr) {
    propagate(node, l, r);
    if (l > qr || r < ql) {
        return 0;
    } else if (l >= ql && r <= qr) {
        return tree[node];
    } else {
        int mid = (l + r) >> 1;
        int left = get(node << 1, l, mid, ql, qr);
        int right = get(node << 1 | 1, mid + 1, r, ql, qr);
        return left + right;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int t, l, r, v;
        cin >> t;
        if (t == 3) {
            cin >> l >> r;
            cout << get(1, 1, n, l + 1, r) << endl;
        } else {
            cin >> l >> r >> v;
            update(1, 1, n, l + 1, r, v, t);
        }
    }
    return 0;
}
