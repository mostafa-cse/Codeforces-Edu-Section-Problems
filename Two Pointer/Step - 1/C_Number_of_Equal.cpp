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
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    cin >> a >> b;

    int j = 0;
    int sum = 0;
    vector<int> cnt_each(m,0);
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        while (j < n and a[j] < b[i]) j++;
        while (j < n and a[j] == b[i]) j++, cnt++;
        cnt_each[i] = cnt;
        if (i and b[i] == b[i - 1]) cnt_each[i] += cnt_each[i - 1];
    }
    sum = accumulate(all(cnt_each), 0ll);
    cout << sum;
    return 0;
}