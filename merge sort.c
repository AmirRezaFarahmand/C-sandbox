#include<stdio.h>

#define ll long long int
#define MAXn 10010
#define mod 1000000007

int n, a[MAXn];

void merge_sort(int l, int r) {
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    int L[MAXn], R[MAXn];
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    for (int i = l; i <= mid; i++)
        L[i] = a[i];
    for (int i = mid + 1; i <= r; i++)
        R[i] = a[i];
    int p1 = l, p2 = mid + 1, idx = l;
    while (p1 <= mid && p2 <= r) {
        if (L[p1] <= R[p2])
            a[idx++] = L[p1++];
        else
            a[idx++] = R[p2++];
    }
    while (p1 <= mid)
        a[idx++] = L[p1++];
    while (p2 <= r)
        a[idx++] = R[p2++];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    merge_sort(0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
