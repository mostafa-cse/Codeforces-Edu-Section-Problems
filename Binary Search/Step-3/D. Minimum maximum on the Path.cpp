#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Edge {
    int to, weight;
};

int n, m, d;
vector<vector<Edge>> graph;
bool canReach(int maxWeight) {
    vector<int> dist(n + 1, INT_MAX);
    queue<pair<int, int>> q; // (node, depth)
    q.push({1, 0});
    dist[1] = 0;
    
    while (!q.empty()) {
        auto [node, depth] = q.front(); q.pop();
        if (depth > d) continue;
        if (node == n) return true;
        
        for (auto [next, weight] : graph[node]) {
            if (weight > maxWeight) continue;
            if (dist[next] > depth + 1) {
                dist[next] = depth + 1;
                q.push({next, depth + 1});
            }
        }
    }
    return false;
}

void findPath(int maxWeight) {
    vector<int> parent(n + 1, -1);
    vector<int> depth(n + 1, INT_MAX);
    queue<int> q;
    q.push(1);
    depth[1] = 0;
    
    while (!q.empty()) {
        int node = q.front(); q.pop();
        if (node == n) break;
        
        for (auto [next, weight] : graph[node]) {
            if (weight > maxWeight) continue;
            if (depth[next] > depth[node] + 1) {
                depth[next] = depth[node] + 1;
                parent[next] = node;
                q.push(next);
            }
        }
    }
    
    if (parent[n] == -1) {
        cout << "-1\n";
        return;
    }
    
    vector<int> path;
    for (int cur = n; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    
    cout << path.size() - 1 << "\n";
    for (int node : path) {
        cout << node << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> d;
    graph.resize(n + 1);
    
    vector<int> weights;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    
    int l = 0, r = 1e18, answer = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (canReach(mid)) {
            answer = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    if (answer == -1) {
        cout << "-1\n";
    } else {
        findPath(answer);
    }
    
    return 0;
}
