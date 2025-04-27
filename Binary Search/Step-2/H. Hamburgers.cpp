#include<bits/stdc++.h>
using namespace std;
#define int long long
string str;
int b, s, c;
int rubles, nb, ns, nc, pb, ps, pc;
bool f(int x){
    int ndb = max(x * b - nb, 0LL);
    int nds = max(x * s - ns, 0LL);
    int ndc = max(x * c - nc, 0LL);
    int ndr = ndb * pb + nds * ps + ndc * pc;
    return ndr <= rubles;
}
int32_t main(){
    cin >> str;
    cin >> nb >> ns >> nc ;
    cin >> pb >> ps >> pc ;
    cin >> rubles;
    b = s = c = 0;
    for(auto ele : str){
        b += ele == 'B';
        s += ele == 'S';
        c += ele == 'C';
    }
    
    int l = 0, r = 1e13;
    int ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (f(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
