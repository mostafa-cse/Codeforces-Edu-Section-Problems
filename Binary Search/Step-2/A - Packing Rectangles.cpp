
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int w, h, n;
    cin >> w >> h >> n;

    auto f = [&](int N) -> bool {
        __int128_t ln = N / w;
        __int128_t wn = N / h;
        return ln * wn >= n;
    };

    int l = 1, r = 1e15, ans = -1;
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
