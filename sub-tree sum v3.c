#include<stdio.h>

#define MAXn (110)

struct ans {
    int *pdp, *pa, *pg;
    int dpv;
};

struct ans dfs(int n, int v, int par, struct ans ans) {
    *(ans.pdp + v) = *(ans.pa + v);
    for (int i = 0; i < n; i++) {
        if (par == i)
            continue;
        if (*(ans.pg + v * MAXn + i)) {
            struct ans c = dfs(n, i, v, ans);
            *(ans.pdp + v) += c.dpv;
        }
    }
    ans.dpv = *(ans.pdp + v);
    return ans;
}

int main()
{
    int n, m;
    static int dp[MAXn], a[MAXn], g[MAXn][MAXn];
    struct ans ans;
    ans.pdp = dp;
    ans.pa = a;
    ans.pg = g[0];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int u;
        scanf("%d%d", &u, &a[i]);
        g[u][i] = 1;
        g[i][u] = 1;
    }

    dfs(n, 0, 0, ans);

    printf("%d\n", dp[m]);
}
