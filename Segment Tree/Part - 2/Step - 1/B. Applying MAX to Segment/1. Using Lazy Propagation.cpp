#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 5;

struct SegmentTree {
    int size;
    vector<int> tree, lazy;

    SegmentTree(int n) {
        size = n;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] = max(tree[node], lazy[node]);
            if (l != r) {
                lazy[node * 2] = max(lazy[node * 2], lazy[node]);
                lazy[node * 2 + 1] = max(lazy[node * 2 + 1], lazy[node]);
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        push(node, l, r);
        if (r < ql || l > qr) return;
        if (ql <= l && r <= qr) {
            lazy[node] = val;
            push(node, l, r);
            return;
        }

        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int l, int r, int idx) {
        push(node, l, r);
        if (l == r) return tree[node];
        int mid = (l + r) / 2;
        if (idx <= mid) return query(node * 2, l, mid, idx);
        else return query(node * 2 + 1, mid + 1, r, idx);
    }

    void updateRange(int l, int r, int val) {
        update(1, 0, size - 1, l, r - 1, val);
    }

    int pointQuery(int idx) {
        return query(1, 0, size - 1, idx);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    SegmentTree seg(n);

    for (int i = 0; i < m; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            seg.updateRange(l, r, v);
        } else if (type == 2) {
            int idx;
            cin >> idx;
            cout << seg.pointQuery(idx) << "\n";
        }
    }

    return 0;
}
