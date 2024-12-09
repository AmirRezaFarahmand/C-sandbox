#include<stdio.h>

#define MAXn (110)

int *pdp, *pa;

int dfs(int n, int v, int par, int g[MAXn][MAXn]) {
    *(pdp + v) = *(pa + v);
    for (int i = 0; i < n; i++) {
        if (par == i)
            continue;
        if (g[v][i]) {
            *(pdp + v) += dfs(n, i, v, g);
        }
    }
    return *(pdp + v);
}

int main()
{
    int n, m;
    static int dp[MAXn], a[MAXn], g[MAXn][MAXn];
    pdp = dp;
    pa = a;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int u;
        scanf("%d%d", &u, &a[i]);
        g[u][i] = 1;
        g[i][u] = 1;
    }

    dfs(n, 0, 0, g);

    printf("%d\n", dp[m]);
}
