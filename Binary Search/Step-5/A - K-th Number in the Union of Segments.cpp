#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, k;
    cin >> n >> k;

    int l = 1e18, r = -1e18, ans = 0;
    vector<pair<int, int>> a(n);
    for (auto &[left, right] : a) {
        cin >> left >> right;
        l = min(l, left);
        r = max(right, r);
    }

    function<int(int)> check = [&](int val) -> int {
        int pos = 0;
        for (const auto &[x, y] : a) {
            if (x > val) {
                pos += 0;
            } else if (y < val) {
                pos += (y - x + 1);
            } else {
                pos += val - x;
            }
        }
       return pos;
    };
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid) <= k) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
