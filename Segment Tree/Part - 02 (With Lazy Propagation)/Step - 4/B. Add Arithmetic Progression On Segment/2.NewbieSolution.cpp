#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const int N = 2e5;

struct elem {
    ll a = 0, d = 0;
};

vector<elem> t(4 * N + 1);

void update(int v, int tl, int tr, int l, int r, ll a, ll d) {
    if (l > r)
        return;
    if (tl == l && tr == r) {
        t[v] = {t[v].a + a, t[v].d + d};
    } else {
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(tm, r), a, d);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, a + d * (max(l, tm + 1) - l), d);
    }
}

ll get(int v, int tl, int tr, int pos, elem res) {
    if (tl == tr) {
        res = {res.a + t[v].a, res.d + t[v].d};
        return res.a;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            res = {res.a + t[v].a, res.d + t[v].d};
            return get(v * 2, tl, tm, pos, res);
        } else {
            res = {res.a + t[v].a, res.d + t[v].d};
            res = {res.a + res.d * (tm + 1 - tl), res.d};
            return get(v * 2 + 1, tm + 1, tr, pos, res);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, a, d;
            cin >> l >> r >> a >> d;
            update(1, 0, n - 1, l - 1, r - 1, a, d);
        } else {
            int pos;
            cin >> pos;
            ll res = get(1, 0, n - 1, pos - 1, {0, 0});
            cout << res << "\n";
        }
    }
    return 0;
}
