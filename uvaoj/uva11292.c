#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compgt(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int m, n;
    int i;
    int cost, cur;

    int *diameter = NULL;
    int *ability = NULL;

    while (scanf("%d%d", &n, &m) == 2) {
        if (m == 0 && n == 0)
            break;
        diameter = (int *)malloc(sizeof(int)*n);
        ability = (int *)malloc(sizeof(int)*m);

        memset(diameter, 0, sizeof(diameter));
        memset(ability, 0, sizeof(ability));

        for (i = 0; i < n; i++)
            scanf("%d", &diameter[i]);
        for (i = 0; i < m; i++)
            scanf("%d", &ability[i]);
        qsort(diameter, n, sizeof(int), compgt);
        qsort(ability, m, sizeof(int), compgt);

        /*
        printf("diameter: ");
        for (i = 0; i < n; i++)
            printf("%d ", diameter[i]);
        printf("\n");

        printf("ability: ");
        for (i = 0; i < m; i++)
            printf("%d ", ability[i]);
        printf("\n");
        */

        cost = 0;
        cur = 0;
        for (i = 0; i < m; i++)
            if (ability[i] >= diameter[cur]) {
                cost += ability[i];
                if (++cur == n)
                    break;
            }
        if (cur < n)
            printf("Loowater is doomed!\n");
        else
            printf("%d\n", cost);
    }

    return 0;
}
