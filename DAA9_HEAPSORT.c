#include <stdio.h>
#define max 10
int h[max];

void heapify(int n)
{
    int i, heap, k, v, j;
    for (i = n / 2; i >= 1; i--)
    {
        k = i;
        v = h[k];
        heap = 0;
        while (!heap && 2 * k <= n)
        {
            j = 2 * k;
            if (j < n)
            {
                if (h[j] < h[j + 1])
                {
                    j = j + 1;
                }
            }
            if (v >= h[j])
            {
                heap = 1;
            }
            else
            {
                h[k] = h[j];
                k = j;
            }
        }
        h[k] = v;
    }
}

void heapsort(int n)
{
    int i, temp;
    for (i = n; i >= 1; i--)
    {
        temp = h[1];
        h[1] = h[i];
        h[i] = temp;
        heapify(i-1);
    }
}

int main()
{
    int n, i;
    printf("Enter N\n");
    scanf("%d", &n);
    printf("Enter the elemnts:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &h[i]);
    }
    heapify(n);
    printf("Before sorting  contents are: ");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", h[i]);
    }
    printf("\nAfter sorting  contents are: ");
    heapsort(n);
    for (i = 1; i <= n; i++)
    {
        printf("%d ", h[i]);
    }
    return 0;
}