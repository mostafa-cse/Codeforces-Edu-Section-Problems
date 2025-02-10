#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
    int n;
    cin >> n;
    vector<int>a(n);
    for (int &i : a) cin >> i;
    sort(a.begin(), a.end());

    int m;
	cin >> m;
	vector<int>b(m);
	for (int &i : b) cin >> i;
	sort(b.begin(), b.end());

	int k;
	cin >> k;
	vector<int> c(k);
	for (int &i : c) cin >> i;
	sort(c.begin(), c.end());

	int l;
	cin >> l;
	vector<int> d(l);
	for (int &i : d) cin >> i;
	sort(d.begin(), d.end());

	const int M = 1e18;
	a.push_back(M),b.push_back(M),c.push_back(M), d.push_back(M);

	int i = 0, j = 0, p = 0, q = 0;
	array<int, 4> ans = {0, 0, 0, 0};
	int dif = M;
	while (a[i] != M or b[j] != M or c[p] != M or d[q] != M) {
		int mn = min({a[i], b[j], c[p], d[q]});
		int mx = max({a[i], b[j], c[p], d[q]});
		if (mx - mn < dif) {
			ans = {a[i], b[j], c[p], d[q]};
			dif = cur_dif;
		}
		i += mn == a[i];
		j += mn == b[j];
		p += mn == c[p];
		q += mn == d[q];
	}
	for (auto i : ans) {
		cout << i << " ";
	}
    return 0;
}
