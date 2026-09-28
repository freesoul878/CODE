#include<stdio.h>
#define MAX 2000005          /* ★ 唯一的重要修改:数组开够 */

int size = 0;
long heap[MAX];

void push(long x)
{
    int index = size;
    heap[size++] = x;
    while(index > 0)                        /* ★ 用 index 判断,不是 size */
    {
        int father = (index - 1) / 2;

        if(heap[index] <= heap[father])
        {
            long t = heap[index];
            heap[index] = heap[father];
            heap[father] = t;
        }
        else break;
        index = father;
    }
}

void min(void)                              /* 堆顶变大后,下沉一次恢复小根堆 */
{
    int index = 0;
    while(1)
    {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int smallest = index;
        if(left < size && heap[smallest] >= heap[left])
            smallest = left;
        if(right < size && heap[smallest] >= heap[right])
            smallest = right;
        if(smallest == index)
            break;
        long t = heap[index];               /* ★ long,不是 int */
        heap[index] = heap[smallest];
        heap[smallest] = t;
        index = smallest;
    }
}

int main()
{
    int n, m, i;
    scanf("%d %d", &n, &m);

    long max_score = 0;
    long v;

    for(i = 0; i < n; i++)
    {
        scanf("%ld", &v);
        if(v > max_score)
            max_score = v;
        push(v);
    }

    for(i = 0; i < m; i++)
    {
        long add;
        scanf("%ld", &add);

        heap[0] += add;                     /* 最低分账号加分 */

        if(heap[0] > max_score)             /* 只有它可能刷新最高分 */
            max_score = heap[0];

        printf("%ld\n", max_score);         /* ★ 边读边输出 */

        min();                              /* 恢复堆性质 */
    }

    return 0;
}