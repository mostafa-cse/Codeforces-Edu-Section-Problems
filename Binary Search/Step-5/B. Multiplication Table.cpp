#include <iostream>
using namespace std;
#define int long long

int countLessEqual(int x, int n) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        count += min(x / i, n); 
    }
    return count;
}

int32_t main() {
    int n, k;
    cin >> n >> k;

    int left = 1, right = n * n, answer = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (countLessEqual(mid, n) >= k) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << answer << endl;
    return 0;
}
