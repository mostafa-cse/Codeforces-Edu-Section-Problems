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
    int n, wsum;
    cin >> n >> wsum;

    struct Product{
        int weight;
        int cost;
        Product() : weight(0), cost(0) {};
        Product(int w, int p) : weight(w), cost(p) {};
    };
    vector<Product> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].weight;
    for (int i = 0; i < n; i++) cin >> a[i].cost;
    int mx_cost = 0;
    for (int l = 0, r = 0, cost = 0; r < n; r++) {
        wsum -= a[r].weight;
        cost += a[r].cost;
        while (wsum < 0) {
            wsum += a[l].weight;
            cost -= a[l].cost;
            l++;
        }
        mx_cost = max(mx_cost, cost);
    }
    cout << mx_cost;
    return 0;
}