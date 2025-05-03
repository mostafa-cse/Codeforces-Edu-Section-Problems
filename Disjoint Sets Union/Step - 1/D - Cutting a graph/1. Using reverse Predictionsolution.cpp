#include<bits/stdc++.h>
using namespace std;
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) : parent(n + 1), rank(n + 1, 0) {
        iota(parent.begin(), parent.end(), 0);
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
        if (rank[ra] == rank[rb]) {
            ++rank[ra];
        }
        return true;
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};
int main() {
	int n, m, k;
	cin >> n >> m >> k;

	while (m--) {
		int ta, tb;
		cin >> ta >> tb;
	}

	struct operation {
		string op;
		int u, v;
		operation() : op(""), u(0), v(0) {}
		operation(string s, int a, int b) : op(s), u(a), v(b) {}
	};
	vector<operation> question;
	while (k--) {
		string s;
		int u, v;
		cin >> s >> u >> v;

		question.emplace_back(operation(s, u, v));
	}

	stack<string> ans;
	DSU ds(n);
	for (int i = question.size() - 1; i >= 0; i--) {
		auto &[s, u, v] = question[i];
		if (s == "cut") {
			ds.unite(u, v);
		} else {
			if (ds.connected(u, v)) {
				ans.push("YES");
			} else {
				ans.push("NO");
			}
		}
	}

	while (!ans.empty()) {
		cout << ans.top() << endl;
		ans.pop();
	}
	return 0;
}
