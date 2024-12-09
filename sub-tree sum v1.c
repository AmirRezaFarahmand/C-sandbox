#include<stdio.h>

#define MAXn (10010)

int n, dp[MAXn], g[MAXn][MAXn], a[MAXn];

int dfs(int v, int par) {

    dp[v] = a[v];
    for (int i = 0; i < n; i++) {
        if (par == i)
            continue;
        if (g[v][i]) {
            dp[v] += dfs(i, v);
        }
    }
    return dp[v];
}

int main()
{
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int u;
        scanf("%d%d", &u, &a[i]);
        g[u][i] = 1;
        g[i][u] = 1;
    }

    dfs(0, 0);

    printf("%d\n", dp[m]);
}
