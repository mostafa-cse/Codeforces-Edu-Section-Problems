#include<bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
template<typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &x: v) in >> x; return in; }
template<typename T>ostream &operator<<(ostream &out, const vector<T> &v) { for (const T &x: v) out << x << ' ';return out;}
int32_t main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    cin >> a;
    /**
     * the boys will see each other only if they are on distance not more than k meters
     * See each other at equal or less then k meters
     * 1..(3, 5) <= k(distance = 2, 4)
     * 1 - 8, 3 - 8 > k
    */
    int ans = 0;
    for (int l = 0, r = 0; l < n; l++) {
        while (r < n and a[r] - a[l] <= k) r++;
        ans += n - r;
       
    }
    cout << ans;
    return 0;
}