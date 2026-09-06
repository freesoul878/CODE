#include<stdio.h>
#define MAX 1000002
int stack[MAX];
int max[MAX];
int ans[MAX];
int s[MAX] = { 0 };
int top = -1;
int num = 0;
void push(int n)
{
	stack[++top] = n;
}
/*void pop(void)
{
	
	ans[num] = stack[top--];
	num++;
}*/
int pop(void)
{

}
int main()
{
	//noob90
	int n,i;
	scanf_s("%d", &n);
	
	for (i = 0;i <= n-1;i++)
	{
		scanf_s("%d", &s[i]);
	}
	for (i = n-1;i >= 0;i--)
	{
		if (s[i] > max[i + 1])
			max[i] = s[i];
		else
			max[i] = max[i + 1];
	}
	for (i = 0;i < n;i++)
	{
		push(s[i]);
		while (top+1&&stack[top] > max[i + 1])
			pop();
	}
	for (i = 0;i < n;i++)
	{
		printf("%d ", ans[i]);
	}









	return 0;
}