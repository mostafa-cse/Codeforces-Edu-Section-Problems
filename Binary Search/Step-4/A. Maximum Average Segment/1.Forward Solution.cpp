#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const double EPS = 1e-7;
int n, d;
double a[MAXN], prefix[MAXN];
bool check(double avg, int &start, int &end) {
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + (a[i] - avg);
    }

    double min_prefix = 0.0;
    int min_index = 0;

    for (int i = d; i <= n; ++i) {
        if (prefix[i] - min_prefix >= -EPS) {
            start = min_index + 1; // prefix sum = s[r] - s[l - 1]
            end = i;
            return true;
        }
        if (prefix[i - d + 1] < min_prefix) {
            min_prefix = prefix[i - d + 1];
            min_index = i - d + 1;
        }
    }
    return false;
}

int main() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    double low = 0.0, high = 100.0;
    int best_l = 1, best_r = d;
    for (int iter = 0; iter < 60; ++iter) {
        double mid = (low + high) / 2.0;
        int l = -1, r = -1;
        if (check(mid, l, r)) {
            best_l = l;
            best_r = r;
            low = mid;
        } else {
            high = mid;
        }
    }
    cout << best_l << " " << best_r << endl;
    return 0;
}
