#include<bits/stdc++.h>
#define int long long
using namespace std;
double a[100005], pfx[100005], idx[100005], mnpfx[100005];
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    }
    int lt = 1, rt = d;
    function<bool(double)> check = [&](double x)->bool {
    	pfx[0] = mnpfx[0] = 0.0;
    	for (int i = 1; i <= n; i++) {
    		pfx[i] = pfx[i - 1] + a[i] - x;
    		if (pfx[i] < mnpfx[i - 1]) {
    			mnpfx[i] = pfx[i];
    			idx[i] = i;
    		} else {
    			mnpfx[i] = mnpfx[i - 1];
    			idx[i] = idx[i - 1];
    		}
    	}
    	for (int i = n; i - d >= 0; i--) {
    		if (pfx[i] >= 0) {
    			lt = 1;
			rt = i;
			return true;
    		}

    		if (mnpfx[i - d] <= pfx[i]) {
    			lt = idx[i - d] + 1;
    			rt = i;
			return true;
    		}
    	}
    	return false;
    };

    double l = 0, r = 100;
    for (int i = 0; i < 100; i++) {
    	double mid = (l + r) * 0.5;
    	if (check(mid)) {
    		l = mid;
    	} else {
    		r = mid;
    	}
    }
    cout << lt << ' ' << rt;
    return 0;
}
