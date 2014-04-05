#include <stdio.h>
#include <stdlib.h>

struct bj {
    int b;
    int j;
    int s;
};

int comp(const void *a, const void *b)
{
    return (int)((int *)a - (int *)b);
}

int main()
{
    int i;
    int N;
    struct bj *bj;
    int time;
    while((scanf("%d", &N) != EOF) && (0 != N)) {
        bj = (struct bj *)malloc(sizeof(struct bj)*N);
        for (i = 0; i < N; i++) {
            scanf("%d%d", bj[i].b, bj[i].j);
            bj[i].s = bj[i].b + bj[i].j;
        }
        //qsort();
    }

    return 0;
}
