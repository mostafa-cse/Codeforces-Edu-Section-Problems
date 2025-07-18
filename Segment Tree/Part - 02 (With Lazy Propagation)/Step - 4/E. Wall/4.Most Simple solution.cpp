#include <bits/stdc++.h>
using namespace std;
int n, k, opt, l, r, x, inf;
int ADD[8050000], DEL[8050000];
void pushdown(int k)
{
    if (ADD[k] != 0)
    {
        int son = k + k, x = ADD[k];
        if (ADD[son] < x)
            ADD[son] = x;
        if (DEL[son] < x)
            DEL[son] = x;
        son++;
        if (ADD[son] < x)
            ADD[son] = x;
        if (DEL[son] < x)
            DEL[son] = x;
        ADD[k] = 0;
    }
    if (DEL[k] != inf)
    {
        int son = k + k, x = DEL[k];
        if (ADD[son] > x)
            ADD[son] = x;
        if (DEL[son] > x)
            DEL[son] = x;
        son++;
        if (ADD[son] > x)
            ADD[son] = x;
        if (DEL[son] > x)
            DEL[son] = x;
        DEL[k] = inf;
    }
}
void add(int x, int y, int z, int l, int r, int k)
{
    if ((l == x) && (r == y))
    {
        if (ADD[k] < z)
            ADD[k] = z;
        if (DEL[k] < z)
            DEL[k] = z;
        return;
    }
    pushdown(k);
    int mid = (l + r) >> 1;
    if (y <= mid)
        add(x, y, z, l, mid, k + k);
    else if (x > mid)
        add(x, y, z, mid + 1, r, k + k + 1);
    else
        add(x, mid, z, l, mid, k + k), add(mid + 1, y, z, mid + 1, r, k + k + 1);
}
void del(int x, int y, int z, int l, int r, int k)
{
    if ((l == x) && (r == y))
    {
        if (ADD[k] > z)
            ADD[k] = z;
        if (DEL[k] > z)
            DEL[k] = z;
        return;
    }
    pushdown(k);
    int mid = (l + r) >> 1;
    if (y <= mid)
        del(x, y, z, l, mid, k + k);
    else if (x > mid)
        del(x, y, z, mid + 1, r, k + k + 1);
    else
        del(x, mid, z, l, mid, k + k), del(mid + 1, y, z, mid + 1, r, k + k + 1);
}
void getans(int l, int r, int k)
{
    if (l == r)
    {
        printf("%d\n", ADD[k]);
        return;
    }
    pushdown(k);
    int mid = (l + r) >> 1;
    getans(l, mid, k + k);
    getans(mid + 1, r, k + k + 1);
}
int main()
{
    inf = 100005;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n << 2; i++)
        DEL[i] = inf;
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d%d%d", &opt, &l, &r, &x);
        l++;
        r++;
        if (opt == 1)
            add(l, r, x, 1, n, 1);
        if (opt == 2)
            del(l, r, x, 1, n, 1);
    }
    getans(1, n, 1);
}
