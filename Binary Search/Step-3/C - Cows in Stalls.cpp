#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    function<bool(int)> f = [&](int d) -> bool {
        int cnt = 1, f = a[0];
        for(int i = 1; i < n; i++) {
            if (a[i] - f >= d) {
                cnt++;
                f = a[i];
            }
        }
        return cnt >= k;
    };
    int l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (f(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
