#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int32_t main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &i : a) cin >> i;

    function<bool(int)> f = [&](int x) -> bool {
        int cnt = 1; // lastone
        for (int i = 0, sum = 0; i < n; i++) {
            if (a[i] > x) return false;
            if (sum + a[i] <= x) {
                sum += a[i];
            } else {
                sum = a[i];
                cnt++;
            }
        }
        return cnt <= k;
    };

    int l = 0, r = 1e18, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (f(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
