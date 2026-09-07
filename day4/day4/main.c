#include<stdio.h>
//#define MAX 100002
//int pushed[MAX];
//int popped[MAX];
//int stack[MAX];
//int c[MAX];
//int top = -1;
//void push(int n)
//{
//	stack[++top] = n;
//}
//void pop(void)
//{
//	top--;
//}

int q[100005];
int head = 0, tail = 0;
void enq(int n)
{
	q[tail++] = n;
}
int deq(void)
{
	return q[head++];
}
int empty(void)
{
	return tail == head;
}
//noob94无法吃午餐学生数量
//int countStudents(int* students, int studentsLen, int* sandwiches, int sandwichesLen) {
//	int top = 0;
//	int head = 0, tail = 0;
//	int q[1000];
//	int i;
//
//	for (int i = 0;i < studentsLen;i++)
//		q[tail++] = students[i];
//	while (head < tail && top < sandwichesLen)
//	{
//		int cnt = 0;
//		int len = tail - head;
//		while (cnt < len) {
//			if (sandwiches[top] == q[head])
//			{
//				head++;
//				top++;
//				break;
//			}
//			else {
//				q[tail++] = q[head];
//				head++;
//				cnt++;
//
//			}
//		}
//		if (cnt == len)
//			break;
//
//
//	}
//	return tail - head;
//}
int main()
{
	//noob92验证栈序列
	/*int q = 0,n = 0;
	scanf_s("%d", &q);
	int i = 0, j = 0;
	int k = 0;
	while (q--)
	{
		top = -1;
		j = 0;
		scanf_s("%d", &n);
		for (i = 0;i < n;i++)
			scanf_s("%d", &pushed[i]);
		for (i = 0;i < n;i++)
			scanf_s("%d", &popped[i]);
		for (i = 0;i < n;i++) {
			push(pushed[i]);
			while (top != -1 && stack[top] == popped[j])
			{
				top--;
				j++;
			}
		}
		if (j == n)
			c[k] = 1;
		else c[k] = 0;
		k++;

	}
	for (i = 0;i < k;i++)
	{
		if (c[i] == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}*/
	//noob93队列操作
	/*int n;
	scanf("%d", &n);
	int a;
	int x;
	while (n--)
	{
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			scanf("%d", &x);
			enq(x);
			break;
		case 2:
			if (empty() != 1)
				head++;
			else
				printf("ERR_CANNOT_POP\n");
			break;
		case 3:
			if (empty() != 1)
				printf("%d\n", q[head]);
			else
				printf("ERR_CANNOT_QUERY\n");
			break;
		case 4:
			printf("%d\n", tail - head);
		}

	}*/

	return 0;
}