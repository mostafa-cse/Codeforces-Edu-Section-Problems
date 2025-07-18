#include<bits/stdc++.h>
using namespace std;
struct segment_tree {
    vector<int> tree, lazy;
    int size;
    segment_tree(int n) {
        size = n;
        tree.assign(4 * n + 1, 0);
        lazy.assign(4 * n + 1, 0);
    }
    
    void propagate(int idx, int start, int end){
        if(lazy[idx] != 0){
            tree[idx] = (end - start + 1) - tree[idx];
            if(start != end){
                lazy[2 * idx] = 1 - lazy[2 * idx];
                lazy[2 * idx + 1] = 1 - lazy[2 * idx + 1];
            }
            lazy[idx] = 0;
        }
    }
    
    int query(int idx, int start, int end, int l, int r){
        propagate(idx, start, end);
        if (l > end || r < start) return 0;
        if (l <= start && r >= end) return tree[idx];

        int mid = start + (end - start) / 2;
        int leftAns = query(2 * idx, start, mid, l, r);
        int rightAns = query(2 * idx + 1, mid + 1, end, l, r);
        return leftAns + rightAns;
    }
    
    void update(int idx, int start, int end, int l, int r){
        propagate(idx, start, end);
        if (l > end || r < start) return;
        if (l <= start && r >= end) {
            lazy[idx] = 1 - lazy[idx];
            propagate(idx, start, end);
            return;
        }

        int mid = start + (end - start) / 2;
        update(2 * idx, start, mid, l, r);
        update(2 * idx + 1, mid + 1, end, l, r);
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    
    segment_tree a(n);
    
    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int l, r;
            cin >> l >> r;
            l += 1, r += 1;

            a.update(1, 1, n, l, r - 1);
        } else {
            int k;
            cin >> k;
            k++;

            int low = 1, high = n, res = -1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                int sum = a.query(1, 1, n, 1, mid);

                if (sum >= k) {
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
