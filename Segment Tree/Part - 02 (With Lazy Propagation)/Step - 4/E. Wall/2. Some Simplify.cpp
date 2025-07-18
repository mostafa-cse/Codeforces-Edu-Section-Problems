#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MX = 1e5;
int n, m, ql, qr;
array<int, 2> st[1 << 22];
array<int, 2> operation(array<int, 2> a, array<int, 2> b) {
    if (a[0] == -1) {
        return b;
    } else {
        a[0] = max(a[0], b[0]), a[1] = max(a[1], b[0]);
        a[0] = min(a[0], b[1]), a[1] = min(a[1], b[1]);
        return a;
    }
}
void push(int u, int l, int r) {
    if (st[u][0] ^ -1 && l ^ r) {
        st[2 * u] = operation(st[2 * u], st[u]);
        st[2 * u + 1] = operation(st[2 * u + 1], st[u]);
        st[u] = {-1, -1};
    }
}
void update(array<int, 2> x, int u = 1, int l = 0, int r = n - 1) {
    push(u, l, r);
    if (l > qr || r < ql) {
        return;
    } else if (ql <= l && r <= qr) {
        st[u] = operation(st[u], x);
        push(u, l, r);
    } else {
        int mid = (l + r) / 2;
        update(x, 2 * u, l, mid);
        update(x, 2 * u + 1, mid + 1, r);
    }
}
void print(int u = 1, int l = 0, int r = n - 1) {
    push(u, l, r);
    if (l == r) {
        cout << (st[u][0] == -1 ? 0 : st[u][0]) << "\n";
    } else {
        int mid = (l + r) / 2;
        print(2 * u, l, mid);
        print(2 * u + 1, mid + 1, r);
    }
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(st, -1, sizeof(st));
    cin >> n >> m;
    while (m--) {
        int t, h;
        cin >> t >> ql >> qr >> h;
        update(t == 1 ? array<int, 2>{h, MX} : array<int, 2>{0, h});
    }
    print();
    return 0;
}
