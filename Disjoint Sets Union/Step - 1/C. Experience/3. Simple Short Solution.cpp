#include <bits/stdc++.h>
using namespace std;
struct DSU {
private:
    vector<int> P, sz, point;

public:
    DSU(int n) : P(n + 1), sz(n + 1) , point(n + 1) {
        for (int i = 1; i <= n; ++i)
        P[i] = i, sz[i] = 1;
    }
    int get(int x) {
        return x == P[x] ? x : get(P[x]);
    }
    int getans(int x) {
        return x == P[x] ? point[x] : point[x] + getans(P[x]);
    }
    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return;
        }
        if (sz[x] < sz[y])
            swap(x, y);
        P[y] = x;
        sz[x] += sz[y];
        point[y] -= point[x];
    }
    void add(int u, int val) {
        point[get(u)] += val;
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    DSU dsu(n);
    
    while (m--) {
        string s;
        int u;
        cin >> s >> u;
        if (s[0] == 'a') {
            int v;
            cin >> v;
            dsu.add(u, v);
        } else if (s[0] == 'j') {
            int v;
            cin >> v, dsu.unite(u, v);
        } else {
            cout << dsu.getans(u) << '\n';
        }
    }
    return 0;
}
