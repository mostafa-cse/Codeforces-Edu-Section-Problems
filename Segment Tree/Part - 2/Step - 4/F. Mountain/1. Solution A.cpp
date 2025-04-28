#include <bits/stdc++.h>
using namespace std;


#define lpos pos*2
#define rpos pos*2+1

const int INF = 2e9;
const int SIZE = 2e5 + 5;

int n, q;
vector<int> lis;
tuple<int, int, int> ask[SIZE >> 1];
struct Node {
    int sum, mx, lazy;
    Node operator + (const Node &r) const {
        Node re;
        re.sum = sum + r.sum;
        re.mx = max(mx, sum + r.mx);
        re.lazy = INF;
        return re;
    }
} node[SIZE << 2];
void push(int pos, int l, int r) {
    if (node[pos].lazy == INF) return;
    node[pos].sum = node[pos].lazy * (lis[r + 1] - lis[l]);
    node[pos].mx = max(node[pos].lazy, node[pos].sum);
    if (l == r) return;
    node[lpos].lazy = node[rpos].lazy = node[pos].lazy;
    node[pos].lazy = INF;
}
void pull(int pos, int l, int r) {
    int mid = (l + r) / 2;
    push(lpos, l, mid);
    push(rpos, mid + 1, r);
    node[pos] = node[lpos] + node[rpos];
}

void update(int pos, int l, int r, int L, int R, int x) {
    if (l == L && r == R) {
        node[pos].lazy = x;
        return;
    }
    int mid = (L + R) / 2;
    push(pos, L, R);
    if (r <= mid) update(lpos, l, r, L, mid, x);
    else if (l > mid) update(rpos, l, r, mid + 1, R, x);
    else {
        update(lpos, l, mid, L, mid, x);
        update(rpos, mid + 1, r, mid + 1, R, x);
    }
    pull(pos, L, R);
}
int question(int pos, int l, int r, int x) {
    push(pos, l, r);
    if (node[pos].mx < x) return lis.back();
    if (l == r) return lis[l] + (x - 1) / node[pos].lazy;
    int mid = (l + r) / 2;
    push(lpos, l, mid);
    if (node[lpos].mx >= x) return question(lpos, l, mid, x);
    else return question(rpos, mid + 1, r, x - node[lpos].sum);
}
int main() {
    cin >> n;
    lis.emplace_back(0), lis.emplace_back(n + 1);
    char c;
    while (cin >> c && c != 'E') {
        auto &[a, b, x] = ask[++q];
        if (c == 'Q') cin >> a, a++;
        else {
            cin >> a >> b >> x;
            lis.emplace_back(a), lis.emplace_back(b + 1);
        }
    }
    sort(lis.begin(), lis.end());
    lis.erase(unique(lis.begin(), lis.end()), lis.end());

    n = lis.size() - 2;
    for (int i = 1; i <= q; i++) {
        auto &[a, b, x] = ask[i];
        if (b == 0) {
            if (a == 0) {
                cout << "0\n";
                continue;
            }
            if (n == 0) {
                cout << lis.back() - 1 << '\n';
                continue;
            }
            cout << question(1, 1, n, a) - 1 << '\n';
        } else {
            a = lower_bound(lis.begin(), lis.end(), a) - lis.begin();
            b = lower_bound(lis.begin(), lis.end(), b + 1) - lis.begin() - 1;
            update(1, a, b, 1, n, x);
        }
    }
    return 0;
}
