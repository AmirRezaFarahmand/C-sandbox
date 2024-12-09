#include<stdio.h>

#define ll long long int
#define MAXn 10010
#define mod 1000000007

int n, m, a[MAXn];

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int pSum(int idx) {
    if (idx > m)
        return 0;
    return pSum(idx + 1) + a[idx];
}

int cMax(int idx) {
    if (idx > m)
        return -(1e9 + 10);
    return max(a[idx], cMax(idx + 1));
}

int cMin(int idx) {
    if (idx > m)
        return 1e9 + 10;
    return min(a[idx], cMin(idx + 1));
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    m--;
    printf("sum for the first %d element is: %d\n", m, pSum(0));
    printf("max for the first %d element is: %d\n", m, cMax(0));
    printf("min for the first %d element is: %d\n", m, cMin(0));
}
