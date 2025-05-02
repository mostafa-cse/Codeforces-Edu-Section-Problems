#include <bits/stdc++.h>
using namespace std;
vector<pair<int, long double>> g[100005];
long double dist[100005];
int path[100005];
int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        long double w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    long double r = 100, l = 0;
    for (int op = 0; op < 100; op++) {
        long double mid = (l + r) / 2.0;
        for (int i = 2; i <= n; i++) {
            dist[i] = 1e9;
        }

        for (int par = 1; par < n; par++) {
            for (auto &[nbr, w] : g[par]) {
                dist[nbr] = min(dist[nbr], dist[par] + (w - mid));
            }
        }
        if (dist[n] <= 0) {
            r = mid;
        } else {
            l = mid;
        }
    }
    for (int i = 2; i <= n; i++) {
        dist[i] = 1e9;
    }

    for (int par = 1; par < n; par++) {
        for (auto &[nbr, w] : g[par]) {
            if (dist[nbr] > dist[par] + (w - r)) {
                dist[nbr] = dist[par] + (w - r); // We go here and discover agin
                path[nbr] = par;
            }
        }
    }

    stack<int> ans;
    ans.push(n);
    int par = n;
    while (par > 1) {
        par = path[par];
        ans.push(par);
    }

    cout << ans.size() - 1 << '\n';
    while (ans.empty() == 0) {
        cout << ans.top() << ' ';
        ans.pop();
    }
    return 0;
}
