#include <bits/stdc++.h>
#define int long long
using namespace std;
class DSU {
    vector<int> parent, sz;

public:
    DSU(int n) : parent(n + 1), sz(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool connected(int u, int v) {
        return find(u) == find(v);
    }
    bool unite(int u, int v) {
        int ru = find(u);
        int rv = find(v);

        if (ru == rv) return false;
        if (sz[ru] < sz[rv]) {
            swap(ru, rv);
        }
        parent[rv] = ru;
        sz[ru] += sz[rv];
        return true;
    }
    int getSize(int x) {
        return sz[find(x)];
    }
};

signed main() {
    int node, q;
    cin >> node >> q;

    DSU dsu(node);
    while (q--) {
        string s;
        cin >> s;
        
        int u, v;
        cin >> u >> v;
        if (s == "union") {
            dsu.unite(u, v);
        } else {
            cout << (dsu.connected(u, v) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}
