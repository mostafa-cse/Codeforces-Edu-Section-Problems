#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    string t, p;
    cin >> t >> p;

    vector<int> a(t.size());
    for (int &i : a) {
        cin >> i;
        i -= 1;
    }
    
    function<bool(int)> f = [&](int val) -> bool {
        vector<int> s;
        for (int i = val; i < a.size(); i++) {
            s.push_back(a[i]);
        }
        sort(s.begin(), s.end());
        
        int cnt = 0;
        for (int i : s) {
            if (t[i] == p[cnt]) {
                cnt++;
            }
            if (cnt == p.size()) return true;
        }
        return false;
    };

    int l = 0, r = a.size(), ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (f(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
