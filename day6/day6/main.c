#include<stdio.h>
#define MAX 1002
int q[MAX];
int head = 0;
int tail = 0;
void enq(int n)
{
	q[tail++] = n;
}
void deq(void)
{
	head++;
}
int empty(void)
{
	return head == tail;
}
int main()
{//noob98»úÆ÷·­Òë
	/*int m, n,i;
	scanf_s("%d %d", &m, &n);
	int s[MAX];
	for (i = 0;i < n;i++)
	{
		scanf_s("%d", &s[i]);
	}
	int j=0, k=0;
	int num = 0;
	int t =0;
	for (i = 0;i < n;i++)
	{
		j = head;
		num = 0;
		while (1)
		{
			if (q[j] == s[i])
			{
				num = 0;
				break;
			}
			else
			{
				j++;
				if (j > tail )
				{
					num = 1;
					break;
				}
			}

		}
		if (num)
		{
			if (tail - head < m)
			{
				enq(s[i]);
				t++;
			}
			else if (tail - head == m)
			{
				deq();
				enq(s[i]);
				t++;
			}

		}

	}
	
	printf("%d\n", t);*/











	return 0;
}