#include <bits/stdc++.h>
#define int long long
using namespace std;

class SegmentTree {
private:
    vector<int> segTree;
    int size;

public:
    SegmentTree(vector<int>& arr) {
        size = arr.size();
        segTree.resize(2 * size);

        for (int i = 0; i < size; i++) 
            segTree[size + i] = arr[i];

        for (int i = size - 1; i > 0; i--) 
            segTree[i] = gcd(segTree[2 * i], segTree[2 * i + 1]);
    }

    void update(int idx, int val) {
        idx += size;
        segTree[idx] = val;

        for (idx /= 2; idx > 0; idx /= 2) 
            segTree[idx] = gcd(segTree[2 * idx], segTree[2 * idx + 1]);
    }

    int getGCD(int l, int r) {
        l += size; 
        r += size;
        int result = 0;

        while (l <= r) {
            if (l % 2 == 1) result = gcd(result, segTree[l++]); 
            if (r % 2 == 0) result = gcd(result, segTree[r--]); 
            l /= 2;
            r /= 2;
        }
        return result;
    }
};

int32_t main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    SegmentTree ds(arr);

    int ans = n + 1;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j <= i && ds.getGCD(j, i) == 1) {
            ans = min(ans, i - j + 1);
            j++;
        }
    }

    if (ans == n + 1) ans = -1;
    cout << ans;
    return 0;
}
