#include <bits/stdc++.h>
#define int long long
using namespace std;
class DSU {
    vector<int> parent, rank, mx, mn, size;

public:
    DSU(int n) : parent(n + 1), rank(n + 1, 0), mx(n + 1), mn(n + 1), size(n + 1) {
        iota(parent.begin(), parent.end(), 0);
        for (int i = 1; i <= n; i++) {
            mn[i] = mx[i] = i;
            size[i] = 1;
        }
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) return false;
        if (rank[ra] < rank[rb]) swap(ra, rb);

        parent[rb] = ra;
        mn[ra] = min(mn[ra], mn[rb]);
        mx[ra] = max(mx[ra], mx[rb]);
        size[ra] += size[rb];
        if (rank[ra] == rank[rb]) {
            ++rank[ra];
        }
        return true;
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
    array<int, 3> get(int node) {
        int rnode = find(node);
        return {mn[rnode], mx[rnode], size[rnode]};
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
