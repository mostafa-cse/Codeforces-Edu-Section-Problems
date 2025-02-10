#include<bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
string cdn[2] = {"YES", "NO"};
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &i : a) cin >> i;
    const int M = 1e18 + 1e17;
    a.push_back(M);

    auto f = [](int x)->int {
        return x * (x + 1) / 2;
    };
    int ans = 0;
    for (int i = 0, j = 0, sum = 0, pre = 0; i <= n; i++) {
        sum += a[i];
        if (sum > k) {
            int len = i - j;
            int bad = 0;
            if (j) bad = pre - j;
            dout(j, i, pre);
            pre = i;
            ans += f(len) - f(bad);
        }
        while (j < n and sum > k) {
            sum -= a[j++];
        }
    }
    cout << ans;
    return 0;
}
