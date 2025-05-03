#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> parent, sz;
    vector<int> up;
    vector<int> comp;

    DSU(int _n): n(_n) {
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n+1, 1);
        up.assign(n+1, 0);
        comp.assign(n+1, 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        int p = parent[x];
        int r = find(p);
        up[x] += up[p];
        return parent[x] = r;
    }

    void add(int x, int V) {
        int r = find(x);
        comp[r] += V;
    }

    int get(int x) {
        int r = find(x);
        return comp[r] + up[x];
    }

    void join(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        parent[ry] = rx;
        up[ry] = comp[ry] - comp[rx];
        sz[rx] += sz[ry];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    DSU dsu(n);

    while (m--) {
        string cmd;
        cin >> cmd;
        if (cmd == "join") {
            int x, y;
            cin >> x >> y;
            dsu.join(x, y);
        } else if (cmd == "add") {
            int x; int v;
            cin >> x >> v;
            dsu.add(x, v);
        } else { 
            int x;
            cin >> x;
            cout << dsu.get(x) << endl;
        }
    }
    return 0;
}
