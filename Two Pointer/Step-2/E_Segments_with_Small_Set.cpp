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
auto setIO = [](string name = "") {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);  cout.tie(0);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    return 0;
}();
template <class K, class V>
using ht = gp_hash_table<K, V, hash<K>, equal_to<K>, direct_mask_range_hashing<>, linear_probe_fn<>, hash_standard_resize_policy<hash_exponential_size_policy<>, hash_load_check_resize_trigger<>, true>>;
int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    cin >> a;

    ht<int, int> cnt;
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        cnt[a[i]]++;
        while (cnt.size() > m) {
            cnt[a[j]]--;
            if (cnt[a[j]] == 0) cnt.erase(a[j]);
            j++;
        }
        ans += (i - j + 1); // j'th idx will add ∑j 
    }
    cout << ans;
    return 0;
}