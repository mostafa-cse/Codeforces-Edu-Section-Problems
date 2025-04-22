#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Node {
    int pfx, sfx, sum, mx;
    Node() : pfx(0), sfx(0), sum(0), mx(0) {}
    Node(int x) : pfx(x), sfx(x), sum(x), mx(x) {}
    Node operator+(const Node &o) {
        Node ans(0);
        ans.pfx = max(pfx, sum + o.pfx);
        ans.sfx = max(o.sfx, sfx + o.sum);
        ans.sum = sum + o.sum;
        ans.mx = max({mx, o.mx, sfx + o.pfx});
        return ans;
    }
};
struct SegmentTree {
    vector<Node> sgt;
    vector<int> a;
    int n;
    SegmentTree(int N) {
        this->n = N;
        a.assign(N + 1, 0);
        sgt.resize(N * 4 + 1, Node());
    }
    Node combine(Node a, Node b) {
        return a + b;        // ➜ sum
    }
    void build (int node, int l, int r) {
        if (l == r) {
            sgt[node] = Node(a[l]);
            return;
        }
        int mid = l + (r - l) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        sgt[node] = combine(sgt[2 * node], sgt[2 * node + 1]);
    }
    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            sgt[node] = Node(value);
            return;
        }
        int mid = l + (r - l) / 2;
        if(idx <= mid) {
            update(node * 2, l, mid, idx, value);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, value);
        }
        sgt[node] = combine(sgt[2 * node], sgt[2 * node + 1]);
    }
    Node query(int node, int l, int r, int ql, int qr) {
        if (l > qr or r < ql) {
            return Node(); // Edit here
        }
        if (l >= ql and r <= qr) {
            return sgt[node];
        }
        int mid = l + (r - l) / 2;
        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);
        return combine(left, right);
    }
    void build() { build(1, 1, n); }
    void update(int idx, int val) { update(1, 1, n, idx, val); }
    int query(int l, int r) { return query(1, 1, n, l, r).mx; }
};
signed main() {
    int n, q;
    cin >> n >> q;
    
    SegmentTree a(n);
    for (int i = 1; i <= n; i++) {
        cin >> a.a[i];
    }
    a.build();
    cout << max(a.query(1, n), 0ll) << endl;
    while (q--) {
        int i, v;
        cin >> i >> v;
        a.update(i + 1, v);
        cout << max(a.query(1, n), 0ll) << endl;
    }
    return 0;
}
