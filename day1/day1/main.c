#include<stdio.h>
#include<string.h>
//简介数据结构题目练习
#define MAX 100000
char stack[MAX];
int top = -1;
void push(char a) 
{
	stack[++top] = a;
}
char pop(void)
{
	return stack[top--];

}

int main()
{
	/*char s[MAX];
	scanf_s("%s", s,MAX);
	int len = strlen(s);
	int i;
	for (i = 0;i < len;i++)
	{
		if (s[i] == 'a')
		{
			push(s[i]);
		}
		else if (s[i] == 'b')
		{
			if (top == -1)
			{
				printf("Bad\n");
				return 0;
			}
			char t = pop();
			if (t != 'a')
			{
				printf("Bad\n");
				return 0;
			}
			

		}
	}
	if (top == -1)
		printf("Good\n");
	else printf("Bad\n");*/
	int T;
	scanf_s("%d", &T);
	char s[10][MAX];
	int i,j;
	int t[10];

	for (i = 0;i < T;i++)
	{
		scanf_s("%s", s[i],MAX);
		t[i] = strlen(s[i]);
	}
	for (i = 0;i < T;i++)
	{
		for (j = 0;j < t[i];j++)
		{
			if (top == -1)
			{
				push(s[i][j]);

			}
			else
			{
				push(s[i][j]);
				if (s[i][j] == 'o')
				{
					if (stack[top - 1] == 'o')
					{
						top--;
						stack[top] = 'O';
						if (stack[top - 1] == 'O')
						{
							top = top - 2;
						}
					}
				}
				else
				{
					if (stack[top - 1] == 'O')
					{
						top = top - 2;

					}
				}
			}
		}
		if (top == -1)
		{
			printf("\n");
		}
		else
		{
			for (int k = 0;k < top;k++)
			{
				printf("%c", stack[k]);

			}
			printf("%c\n", stack[top]);
		}

		top = -1;
	}
	
	











	return 0;
}