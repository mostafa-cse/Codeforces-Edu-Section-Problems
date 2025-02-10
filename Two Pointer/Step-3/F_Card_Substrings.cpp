/*
ID: onceilo1
LANG: C++
TASK: 
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
template <class K, class V>
using ht = gp_hash_table<K, V, hash<K>, equal_to<K>, direct_mask_range_hashing<>, linear_probe_fn<>, hash_standard_resize_policy<hash_exponential_size_policy<>, hash_load_check_resize_trigger<>, true>>;
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
    string s, ms;
    cin >> s >> ms;
    ht<char, int> cnt;
    for (char c : ms) cnt[c]++;
    int ans = 0;
    for (int l = 0, r = 0; l < n; l++) {
        while (r < n and cnt[s[r]] > 0) cnt[s[r++]]--;
        ans += (r - l);
        cnt[s[l]]++;
    }
    cout << ans;
    return 0;
}