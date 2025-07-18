#include<bits/stdc++.h>
using namespace std;
#define int long long
struct segment_tree {
    vector<int> tree, lazy;
    segment_tree (int n) {
        tree.assign(4 * n + 1, 0);
        lazy.assign(4 * n + 1, 0);
    }
    void propagate(int idx, int start, int end){
        if(lazy[idx] != 0){
            tree[idx] += lazy[idx];
            if(start != end){
                lazy[2 * idx] += lazy[idx];
                lazy[2 * idx + 1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }
    
    int query(int idx, int start, int end, int l, int r){
        propagate(idx, start, end);
        if (l > end || r < start) {
            return -1e18;
        }
        if (l <= start && r >= end) {
            return tree[idx];
        }
    
        int mid = start + (end - start) / 2;
        int leftAns = query(2 * idx, start, mid, l, r);
        int rightAns = query(2 * idx + 1, mid + 1, end, l, r);
        return max(leftAns, rightAns);
    }
    
    void update(int idx, int start, int end, int l, int r, int val){
        propagate(idx, start, end);
        if (l > end || r < start)
            return;
        if (l <= start && r >= end) {
            lazy[idx] += val;
            propagate(idx, start, end);
            return;
        }
        int mid = start + (end - start) / 2;
        update(2 * idx, start, mid, l, r, val);
        update(2 * idx + 1, mid + 1, end, l, r, val);
        tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
    }
};

int32_t main() {
    int n, q;
    cin >> n >> q;

    segment_tree a(n);
    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int l, r, val;
            cin >> l >> r >> val;
            l += 1, r += 1;
            
            a.update(1, 1, n, l, r - 1, val);
        } else {
            int x, l;
            cin >> x >> l;
            l += 1;

            int low = l, high = n, res = 0;
            while(low <= high){
                int mid = low + (high - low) / 2;
                int mx = a.query(1, 1, n, l, mid);
                if(mx >= x){
                    res = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            cout << res - 1 << endl;
        }
    }
    return 0;
}
