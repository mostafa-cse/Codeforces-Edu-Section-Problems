#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &i : a) cin >> i;
    int ans = 0, sum = 0, j = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];

        while (sum >= k) {  // Shrinking the window efficiently
            ans += (n - i);  // Count valid subarrays ending at `i`
            sum -= a[j++];
        }
    }
    cout << ans;
    return 0;
}
