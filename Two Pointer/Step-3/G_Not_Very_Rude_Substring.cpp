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
    int n, c;
    cin >> n >> c;
    string s;
    cin >> s;

    int ans = 0, a = 0, b = 0, Sum_ab = 0;
    for (int l = 0, r = 0; r < n; r++) {
        if (s[r] == 'a') {
            a += 1;
        } else if (s[r] == 'b') {
            Sum_ab += a;
            b++;
        }
        while (Sum_ab > c) {
            if (s[l] == 'a') {
                a--;
                Sum_ab -= b;
            } else if (s[l] == 'b') {
                b--;
            }
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans;
    return 0;
}