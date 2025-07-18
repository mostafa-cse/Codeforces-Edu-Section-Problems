#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
struct Node {
    int l, r;
    int sum = 0, add = 0;
} s[200005 << 2];

void calc(int idx) { s[idx].sum = s[idx * 2].sum + s[idx * 2 + 1].sum; }

void build(int idx, int l, int r) {
    s[idx].l = l, s[idx].r = r;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(2 * idx, l, mid);
    build(idx * 2 + 1, mid + 1, r);
}

void pushdown(int idx) {
    if (s[idx].add) {
        s[idx << 1].sum += s[idx].add * (s[idx << 1].r - s[idx << 1].l + 1);
        s[idx << 1].add += s[idx].add;

        s[idx << 1 | 1].sum += s[idx].add * (s[idx << 1 | 1].r - s[idx << 1 | 1].l + 1);
        s[idx << 1 | 1].add += s[idx].add;
    }
    s[idx].add = 0;
}

void update(int idx, int l, int r, int x) {
    if (s[idx].l >= l && s[idx].r <= r) {
        s[idx].sum += x * (s[idx].r - s[idx].l + 1);
        s[idx].add += x;
        return;
    }
    pushdown(idx);
    int mid = (s[idx].l + s[idx].r) >> 1;
    if (mid >= l)
        update(2 * idx, l, r, x);
    if (mid + 1 <= r)
        update(idx * 2 + 1, l, r, x);
    calc(idx);
}

int query(int idx, int l, int r) {
    if (s[idx].l >= l && s[idx].r <= r)
        return s[idx].sum;
    pushdown(idx);
    int mid = (s[idx].l + s[idx].r) >> 1;
    int ans = 0;
    if (mid >= l)
        ans += query(2 * idx, l, r);
    if (mid + 1 <= r)
        ans += query(idx * 2 + 1, l, r);
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    build(1, 1, n);
    string ans;
    for (int i = 0; i < m; ++i) {
        int t, l, r, x, a, d;
        cin >> t;
        if (t == 1) {
            cin >> l >> r >> a >> d;
            update(1, l, l, a);
            if (r > l)
                update(1, l + 1, r, d);
            if (r + 1 <= n)
                update(1, r + 1, r + 1, -(int)d * (r - l) - a);
        } else {
            cin >> x;
            int ans = query(1, 1, x);
            cout << ans << endl;
        }
    }
}
