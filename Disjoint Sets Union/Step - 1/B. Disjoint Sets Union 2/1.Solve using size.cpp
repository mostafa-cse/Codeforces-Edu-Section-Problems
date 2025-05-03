#include <bits/stdc++.h>
#define int long long
using namespace std;
class DSU {
    vector<int> parent, sz, mn, mx;

public:
    DSU(int n) : parent(n + 1), sz(n + 1, 1), mn(n + 1), mx(n + 1) {
        iota(parent.begin(), parent.end(), 0);
        for (int i = 1; i <= n; i++) {
            mn[i] = mx[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return false;

        if (sz[ra] < sz[rb]) {
            swap(ra, rb);
        }
        parent[rb] = ra;
        mn[ra] = min(mn[rb], mn[ra]);
        mx[ra] = max(mx[rb], mx[ra]);
        sz[ra] += sz[rb];

        return true;
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
    int size(int x) {
        return sz[find(x)];
    }
    array<int, 3> get(int node) {
        int rnode = find(node);
        return {mn[rnode], mx[rnode], sz[rnode]};
    }
};

signed main() {
    int n, q;
    cin >> n >> q;

    DSU dsu(n);
    while (q--) {
        string op;
        cin >> op;

        if (op == "union") {
            int u, v;
            cin >> u >> v;
            dsu.unite(u, v);
        } else {
            int node;
            cin >> node;

            array<int, 3> ans = dsu.get(node);
            cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
        }
    }
    return 0;
}
