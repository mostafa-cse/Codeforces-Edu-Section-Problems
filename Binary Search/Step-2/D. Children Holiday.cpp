#include <bits/stdc++.h>
#define int long long
using namespace std;
int assistants, balloons;
int inflat[1000], how[1000], rest[1000], can_inflate[1000];
signed main() {
    cin >> balloons >> assistants;
    for (int i = 0; i < assistants; i++) {
        cin >> inflat[i] >> how[i] >> rest[i];
    }
    if (balloons == 0) {
        cout << 0 << endl;
        for (int i = 0; i < assistants; i++) {
            cout << 0 << " ";
        }
        return 0;
    }
    function<bool(int)> f = [&](int time) -> bool {
        int total_inflat = 0;
        for (int i = 0; i < assistants; i++) {
            int inflate_cycle = time / (inflat[i] * how[i] + rest[i]);
            int remain_time = time - inflate_cycle * (inflat[i] * how[i] + rest[i]);

            int inflate_ballons = inflate_cycle * how[i];
            
            if (remain_time / inflat[i] >= how[i]) {
                inflate_ballons += how[i];
            } else {
                inflate_ballons += remain_time / inflat[i];
            }
            can_inflate[i] = inflate_ballons;
            total_inflat += inflate_ballons;
        }
        return total_inflat >= balloons;
    };

    int l = 0, r = 1e12, req_time = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;

        if (f(mid)) {
            req_time = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << req_time << endl;
    f(req_time);
    int cur_inflats = 0;
    for (int i = 0; i < assistants; i++) {
        if (can_inflate[i] + cur_inflats <= balloons) {
            cout << can_inflate[i] << " ";
            cur_inflats += can_inflate[i];
        } else {
            cout << balloons - cur_inflats << " ";
            cur_inflats = balloons;
        }
    }
    return 0;
}
