#include<bits/stdc++.h>
#define int long long
using namespace std;
double a[100005], pfx[100005];;
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
    	for (int i = 1; i <= n; i++) {
    		pfx[i] = pfx[i - 1] + a[i] - x;
    	}

    	double mnpfx = 0.0;
    	int idx = 0;
    	for (int i = d; i <= n; i++) {
    		if (pfx[i] - mnpfx >= 0) {
    			lt = idx + 1;
    			rt = i;
    			return true;
    		}

    		if (pfx[i - d + 1] < mnpfx) {
    			mnpfx = pfx[i - d + 1];
    			idx = i - d + 1;
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
