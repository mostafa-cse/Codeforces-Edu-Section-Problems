#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (int &i : a) cin >> i;
	sort(a.begin(), a.end());

	auto search = [&](int x) ->bool{
		int l = 0, r = n - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (a[mid] == x) return true;
			if (a[mid] < x) l = mid + 1;
			else r = mid - 1;
		}
		return false;
	};
	while (q--) {
		int x;
		cin >> x;
		if (search(x)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
