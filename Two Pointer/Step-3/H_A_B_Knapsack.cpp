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
    int n, m, s, a, b;
    cin >> n >> m >> s >> a >> b;
    vector<int> A(n), B(m);
    cin >> A >> B;

    sort(all(A), greater<int>());
    sort(all(B), greater<int>());

    vector<int> As(n + 1, 0), Bs(m + 1, 0);
    for (int i = 1; i <= n; i++) As[i] += A[i - 1] + As[i - 1];
    for (int i = 1; i <= m; i++) Bs[i] += B[i - 1] + Bs[i - 1];

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int rem_weight = s - (i * a);
        if (rem_weight < 0) break;
        ans = max(ans, As[i] + Bs[min(rem_weight / b, m)]);
    }
    cout << ans;
    return 0;
}