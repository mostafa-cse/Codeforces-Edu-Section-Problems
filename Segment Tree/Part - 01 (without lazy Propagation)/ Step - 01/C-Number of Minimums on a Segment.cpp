#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Node {
    int val, cnt;
    Node() : val(1e10), cnt(0) {}
    Node(int x) : val(x), cnt(1) {}
    Node(int x, int y) {
        this->val = x;
        this->cnt = y;
    }
    Node operator+(const Node &o) {
        Node res(0, 0);
        if (val < o.val) {
            res = Node(val, cnt);
        } else if (o.val < val) {
            res = o;
        } else if (o.val == val) {
            res = val;
            res.cnt = cnt + o.cnt;
        }
        return res;
    }
};
struct SegmentTree {
    vector<Node> sgt;
    vector<int> a;
    int n;
    SegmentTree(int N) {
        this->n = N;
        a.assign(N + 1, 0);
        sgt.resize(4 * N + 1);
    }
    Node combine(Node a, Node b) {
        return a + b; // ➜ sum
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
    Node query(int l, int r) { return query(1, 1, n, l, r); }
};
signed main() {
    int n, q;
    cin >> n >> q;

    SegmentTree a(n);
    for (int i = 1; i <= n; i++) {
        cin >> a.a[i];
    }
    a.build();

    while(q--) {
        int op;
        cin >> op;

        if (op & 1) { // update
            int i, v;
            cin >> i >> v;
            i += 1;
            a.update(i, v);
        } else {      // Query 
            int l, r;
            cin >> l >> r;
            l += 1, r += 1;
            Node ans = a.query(l, r - 1);
            cout << ans.val << " " << ans.cnt << endl;
        }
    }
    return 0;
}
