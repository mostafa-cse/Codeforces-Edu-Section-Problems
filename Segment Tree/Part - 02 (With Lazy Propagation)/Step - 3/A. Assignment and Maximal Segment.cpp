#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
    int sum;
    int pref;
    int suff;
    int mx;
    Node() { sum = pref = suff = mx = 0; }
    Node(int v) { sum = pref = suff = mx = v; }
    Node (int val, int start, int end) {
        int v = val * (end - start + 1);
        this->sum = v;
        this->pref = max(v, 0ll);
        this->suff = max(v, 0ll);
        this->mx = max(v, 0ll);
    }
    Node operator+(const Node &o) {
        Node res;
        res.sum = sum + o.sum;
        res.pref = max(pref, sum + o.pref);
        res.suff = max(o.suff, o.sum + suff);
        res.mx = max({mx, o.mx, suff + o.pref});
        return res;
    }
};

struct segment_tree {
    vector<Node> tree;
    vector<int> lazy;
    segment_tree(int n) {
        tree.resize(4 * n + 1, Node());
        lazy.assign(n * 4 + 1, 1e10);
    }
    void propagate(int idx, int start, int end){
        if(lazy[idx] != 1e10){
            tree[idx] = Node(lazy[idx], start, end);
            if(start != end){
                lazy[2 * idx] = lazy[idx];
                lazy[2 * idx + 1] = lazy[idx];
            }
            lazy[idx] = 1e10; //initialize value can be -1e9≤x≤1e9
        }
    }
    Node query(int idx, int start, int end, int l, int r){
        propagate(idx, start, end);
        if (l > end || r < start) return Node();
        if (l <= start && r >= end) return tree[idx];

        int mid = start + (end - start) / 2;
        Node left = query(2 * idx, start, mid, l, r);
        Node right = query(2 * idx + 1, mid + 1, end, l, r);
        return left + right;
    }

    void update(int idx, int start, int end, int l, int r, int val){
        propagate(idx, start, end);
        if (l > end || r < start) return;
        if (l <= start && r >= end) {
            lazy[idx] = val;
            propagate(idx, start, end);
            return;
        }

        int mid = start + (end - start) / 2;
        update(2 * idx, start, mid, l, r, val);
        update(2 * idx + 1, mid + 1, end, l, r, val);
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }
};

int32_t main() {
    int n, q;
    cin >> n >> q;
    
    segment_tree a(n);
    
    while(q--){
        int l, r, val;
        cin >> l >> r >> val;
        l += 1, r += 1;
        a.update(1, 1, n, l, r - 1, val);
        Node ans = a.query(1, 1, n, 1, n);
        cout << max(ans.mx, 0ll) << endl;
    }
    return 0;
}
