#include<bits/stdc++.h>
using namespace std;
class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        n += 1;
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};
int main() {
    int n, q;
    cin >> n >> q;

    DSU ds(n);
    while (q--) {
        string s; cin >> s;
        int a, b;
        cin >> a >> b;

        if (s == "union") {
            ds.unionSets(a, b);
        } else {
            int pa = ds.find(a);
            int pb = ds.find(b);

            cout << (pa == pb ? "YES" : "NO") << endl;
        }

    }
    return 0;
}
