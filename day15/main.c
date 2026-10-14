#include <stdio.h>

int main() {
    //BGN3找倍数
 /*  int l,r;
    int x;
    scanf("%d %d %d",&l,&r,&x);
    int m = -1;
    int i;
    for(i = l;i<=r;i++)
    {
        if(m!=-1)
        break;
        if(i%x == 0)
        m = i;
    }
    printf("%d\n",m);
    return 0;*/
    //BGN4买橘子（贪心算法）
  /*  int n;
    scanf("%d ",&n);
    int i;
    int num = -1;
    int num1,num2;
    int max = 9999999;
    num1 = n/8;
    for(int x = num1;x>=0;x--)
    {
        int rem = n - x*8;
        if(rem >=0 &&rem % 6==0)
        {
            num2 = rem/6;
            num = x+num2;
            break;
        }
    }
    printf("%d\n",num);
    */
    //BNG5穷哈哈
    #include <stdio.h>
#define MAX 100001

/* 求最长的「相邻字符交替」的连续子串长度（字符集只认 'a' 和 'h'） */
int main(void)
{
    char s[MAX];
    int N;

    if (scanf("%d", &N) != 1 || N <= 0) {      /* 防呆 */
        printf("0\n");
        return 0;
    }
    if (N >= MAX) N = MAX - 1;                 /* 防越界 */

    scanf("%s", s);                            /* 一次读进来, 自动跳过换行 */

    int in  = (s[0] == 'a' || s[0] == 'h');
    int cur = in ? 1 : 0;
    int max = cur;

    for (int i = 1; i < N; i++) {
        int now_in = (s[i] == 'a' || s[i] == 'h');
        if (now_in && in && s[i] != s[i - 1])
            cur++;                             /* 还在交替, 继续接长 */
        else
            cur = now_in ? 1 : 0;              /* 断了, 从当前字符重新起算 */
        in = now_in;
        if (cur > max) max = cur;
    }

    printf("%d\n", max);
    return 0;
}

    return 0;
}