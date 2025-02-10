#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	vector<set<int>>a(4);
	set<int> all_color;
	for (int typs = 0; typs < 4; typs++) {
		int n;
		cin >> n;
		for (int clr = 0; clr < n; clr++) {
			int x;
			cin >> x;
			a[typs].insert(x);
			all_color.insert(x);
		}
	}

	vector<int> idx(4, 0), ans(4, 0);
	int dif = 1e8;
	for (auto target : all_color) {
		vector<int> cur(4, 0);
		int mx = 0;
		for (int typs = 0; typs < 4; typs++) {
			auto val = a[typs].lower_bound(target);
			if (val == a[typs].end()) mx = 1e10;
			cur[typs] = *val;
			mx = max(mx, *val);
		}

		if (mx - target < dif) {
			dif = mx - target;
			ans = cur;
		}
	}
	for (int &i : ans) {
		cout << i << " ";
	}
    return 0;
}
