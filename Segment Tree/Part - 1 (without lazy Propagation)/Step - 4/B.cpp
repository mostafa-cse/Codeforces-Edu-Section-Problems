#include <bits/stdc++.h>
#define int long long
using namespace std;
const int SZ = 5e5 + 123;
int R;
struct matrix {
    int r1c1, r1c2, r2c1, r2c2;
    matrix operator*(const matrix &o) const {
        matrix res;
        res.r1c1 = (r1c1 * o.r1c1 % R + r1c2 * o.r2c1 % R) % R;
        res.r1c2 = (r1c1 * o.r1c2 % R + r1c2 * o.r2c2 % R) % R;
        res.r2c1 = (r2c1 * o.r1c1 % R + r2c2 * o.r2c1 % R) % R;
        res.r2c2 = (r2c1 * o.r1c2 % R + r2c2 * o.r2c2 % R) % R;
        return res;
    }    
};
vector<matrix> a(SZ), sgt(4 * SZ);
void merge(int node) {
    sgt[node] = (sgt[node * 2] * sgt[node * 2 + 1]) ; // Sum
}
matrix Ans(matrix left, matrix right) {
    return left * right;
}
void build (int node, int l, int r) {
    if (l == r) {
        sgt[node] = a[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    merge(node);
}
matrix query(int node, int l, int r, int ql, int qr) {
    if (l > qr or r < ql) {
        return {1, 0, 0, 1};
    }
    if (l >= ql and r <= qr) {
        return sgt[node];
    }
    int mid = l + (r - l) / 2;
    matrix left = query(node * 2, l, mid, ql, qr);
    matrix right = query(node * 2 + 1, mid + 1, r, ql, qr);
    return Ans(left, right);
}
signed main() {
    int n, m;
    cin >> R >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].r1c1 >> a[i].r1c2 >> a[i].r2c1 >> a[i].r2c2;
    }
    build(1, 1, n);

    while (m--) {
        int l, r;
        cin >> l >> r;

        matrix ans = query(1, 1, n, l, r);
        cout << ans.r1c1 << " " << ans.r1c2 << endl;
        cout << ans.r2c1 << " " << ans.r2c2 << endl;
        cout << endl;
    }
    return 0;
}
