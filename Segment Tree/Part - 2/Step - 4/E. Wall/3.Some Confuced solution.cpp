#include <bits/stdc++.h>
using namespace std;

const int RIGHT = (1 << 21);
const int SIZE = (1 << 22) + 5;

int D[SIZE], U[SIZE];
int N, K;

void combine(int n, int d, int u) {
    D[n] = max(min(D[n], d), u);
    U[n] = min(max(U[n], u), d);
}
void process(int n, char t, int h){
    if (t == 'd') {
        D[n] = min(D[n], h);
        U[n] = min(U[n], h);
    } else {
        D[n] = max(D[n], h);
        U[n] = max(U[n], h);
    }
}
void update(int l, int r, char t, int h, int n, int a, int b) {
    if (a > r || b < l) {
        return;
    } else if (a >= l && b <= r) {
        process(n, t, h);
    } else {
        combine(2 * n, D[n], U[n]);
        combine(2 * n + 1, D[n], U[n]);
        D[n] = SIZE, U[n] = 0;

        int mid = (a + b) / 2;
        update(l, r, t, h, 2 * n, a, mid);
        update(l, r, t, h, 2 * n + 1, mid + 1, b);
    }
}
void complete() {
    for (int i = (1); i <= (RIGHT - 1); i++) {
        combine(2 * i, D[i], U[i]);
        combine(2 * i + 1, D[i], U[i]);
    }
}
int main() {
    scanf("%d%d", &N, &K);
    for (int i = (1); i <= (K); i++) {
        int id, l, r, h;
        scanf("%d%d%d%d", &id, &l, &r, &h);
        char t = id == 1 ? 'u' : 'd';
        update(l + 1, r + 1, t, h, 1, 1, RIGHT);
    }
    complete();
    for (int i = (RIGHT); i <= (RIGHT + N - 1); i++)
        printf("%d\n", min(D[i], U[i]));
    return 0;
}
