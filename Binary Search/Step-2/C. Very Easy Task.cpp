#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int n, x, y;
    cin >> n >> x >> y;
    
    if (x > y) swap(x, y);

    function<bool(int)> f = [&](int times) -> bool {
        int tot = n;
        tot -= 1;
        times -= x;
        tot -= (int) (times / x);
        tot -= (int) (times / y);
        return tot <= 0;
    };
    int l = x, r = 1e18, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (f(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}
