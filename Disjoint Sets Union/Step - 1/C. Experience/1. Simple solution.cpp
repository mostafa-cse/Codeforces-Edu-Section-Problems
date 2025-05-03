#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> par, sz, point;
    DSU(int n_size) {
        n = n_size;
        par.resize(n + 1);
        sz.resize(n + 1);
        point.resize(n + 1);
        for (int i = 0; i < n + 1; ++i) {
            par[i] = i;
            sz[i] = 1;
            point[i] = 0;
        }
    }
    int find(int u) {
        if (par[u] == u) {
            return u;
        }
        return find(par[u]);
    }
    void join(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if (ru == rv) {
            return;
        }
        if (sz[ru] < sz[rv]) {
            swap(ru, rv);
        }
        point[rv] -= point[ru];
        par[rv] = ru;
        sz[ru] += sz[rv];
        sz[rv] = 0;
    }
    void add(int u, int val) {
        int ru = find(u);
        point[ru] += val;
    }
    int get(int u) {
        int sum = point[u];
        while (u != par[u]) {
            u = par[u];
            sum += point[u];
        }
        return sum;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);
    
    while (m--) {
        string s;
        cin >> s;
        if (s == "add") {
            int x, y;
            cin >> x >> y;
            dsu.add(x, y);
        } else if (s == "join") {
            int x, y;
            cin >> x >> y;
            dsu.join(x, y);
        } else {
            int x;
            cin >> x;
            cout << dsu.get(x) << '\n';
        }
    }
    return 0;
}
