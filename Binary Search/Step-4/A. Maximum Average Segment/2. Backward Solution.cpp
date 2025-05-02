#include <bits/stdc++.h>
using namespace std;
int n, d;
int leftAns, rightAns;
double pfx[100005], mnpfx[100005], idx[100005], a[100005];
bool good(double x) {
    pfx[0] = mnpfx[0] = a[0] - x;
    idx[0] = 0;
    for (int i = 1; i < n; i++) {
        pfx[i] = pfx[i - 1] + (a[i] - x);
        if (pfx[i] <= mnpfx[i - 1]) {
            mnpfx[i] = pfx[i];
            idx[i] = i;
        } else {
            mnpfx[i] = mnpfx[i - 1];
            idx[i] = idx[i - 1];
        }
    }

    for (int i = n - 1; i + 1 - d >= 0; i--) {
        if (pfx[i] >= 0) {
            leftAns = 0;
            rightAns = i;
            return true;
        }

        if (mnpfx[i - d] <= pfx[i]) {
            leftAns = idx[i - d] + 1; 
            rightAns = i;
            return true;
        }
    }
    return false;
}
int main() {
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    double l = 0, r = 101;
    for (int i = 0; i < 101; i++) {
        double mid = (l + r) / 2;
        if (good(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << leftAns + 1 << " " << rightAns + 1 << endl;
    return 0;
}
