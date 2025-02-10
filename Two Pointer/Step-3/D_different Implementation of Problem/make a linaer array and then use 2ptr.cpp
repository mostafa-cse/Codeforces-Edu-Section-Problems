#include <bits/stdc++.h>
using namespace std;
int main() {
	struct Val {
		int v;
		int idx;
		Val() : v(0), idx(-1) {};
		Val(int v, int i) : v(v), idx(i){};
		bool operator<(Val &x) {
			return v < x.v;
		}
	};
	vector<Val> a;
    for (int i = 0; i < 4; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            a.push_back(Val(x, i)); // make linear => . . . . . .
        }
    }
    sort(a.begin(), a.end()); // sort according to the value
    int l = 0, ll = 0, rr = 0, cnt = 0, diff = 1e8;
    vector<int> idx(4, 0);
    for (int r = 0; r < a.size(); ++r) {
    	if (idx[a[r].idx] == 0) cnt++;

    	idx[a[r].idx]++;
    	if (cnt < 4) continue;

    	while (idx[a[l].idx] > 1) { // bad dibo because mx >= mn, mn as possible as large to mx
    		idx[a[l].idx]--;
    		l++;
    	}

    	if (a[r].v - a[l].v < diff) {
    		diff = a[r].v - a[l].v;
    		rr = r;
    		ll = l;
    	}
    }

    vector<int> ans(4, 0);
    for (int i = ll; i <= rr; i++) {
    	if (ans[a[i].idx] == 0) {
    		ans[a[i].idx] = a[i].v;
    	}
    }

    for (int i : ans) cout << i << " ";
    return 0;
}
