#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    function<bool(int)> check = [&] (int x) -> bool {
        int cnt = 0;
        for (int i = 0, j = 0; i < n and j < n;) {
            if (a[i] + b[j] >= x) {
                j++;
            } else {
                cnt += (n - j);
                i++;
            }
        }
        return cnt < k;
    };

    int l = 1, r = 2e9 + 10;
    for (int i = 0; i < 80; i++) {
        int mid = (l + r) / 2;
        if(check(mid) ) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}
