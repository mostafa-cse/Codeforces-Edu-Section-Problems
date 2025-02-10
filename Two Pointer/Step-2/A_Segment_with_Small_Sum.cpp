/*
ID: onceilo1
LANG: C++
TASK: 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
template<typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &x: v) in >> x; return in; }
template<typename T>ostream &operator<<(ostream &out, const vector<T> &v) { for (const T &x: v) out << x << ' ';return out;}
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif
auto setIO = [](string name = "") {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);  cout.tie(0);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    return 0;
}();
int32_t main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    cin >> a;

    int ans = 0;
    for (int i = 0,sum = 0, start = 0; i < n; i++) {
        sum += a[i];
        if (sum <= k) {
            ans = max(ans, i - start + 1);
        }
        while (sum > k and start < n) {
            sum -= a[start++];
        }
        if (sum <= k) {
            ans = max(ans, i - start + 1);
        }
    }
    cout << ans << endl;
    return 0;
}