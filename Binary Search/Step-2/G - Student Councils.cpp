#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int k, n;
    cin >> k >> n;

    vector<int> a(n);
    for (int &i : a) cin >> i;
    
    function<bool(int)> f = [&](int council) -> bool {
        int sum = 0;
        for (int i : a) {
            sum += min(i, council);
        }
        return sum / council >= k;
    };

    int l = 1, r = 1e18, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (f(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
