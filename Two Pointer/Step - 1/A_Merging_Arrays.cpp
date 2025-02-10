/*
ID: onceilo1
LANG: C++
TASK:  Merging Arrays,
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
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    cin >> a >> b;

    int i = 0, j = 0;
    while (i < n and j < m) {
        if (a[i] < b[j]) cout << a[i ++] << " ";
        else cout << b[j++] << " ";
    }
    while (i < n) cout << a[i++] << " ";
    while (j < m) cout << b[j++] << " ";
    return 0;
}