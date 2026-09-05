#include<stdio.h>
#include<string.h>
#define MAX 10000
char stack[MAX];
int top = -1;
void push(char n)
{
	stack[++top] = n;
}
char pop(void)
{
	return stack[top--];
}
//noob88后缀表达式
// 注意所有数据都用long long防止溢出
//long long legalExp(char* str) {
//
//	char temp[MAX];
//	int idx = 0;
//	long long ans;
//	long long a, b;
//	for (int i = 0;i < strlen(str);i++)
//	{
//		if (str[i] >= 48 && str[i] <= 57)
//		{
//			temp[idx] = str[i];
//			idx++;
//
//		}
//		if (str[i] == '#')
//		{
//			temp[idx] = '\0';
//			long long n = atoll(temp);
//			push(n);
//			idx = 0;
//		}
//		if (str[i] == '+')
//		{
//			a = pop();
//			b = pop();
//			ans = a + b;
//			push(ans);
//		}
//		if (str[i] == '-')
//		{
//			a = pop();
//			b = pop();
//			ans = b - a;
//			push(ans);
//		}
//		if (str[i] == '*')
//		{
//			a = pop();
//			b = pop();
//			ans = b * a;
//			push(ans);
//		}
//
//	}
//	return ans;
//}

//nood89表达式求值
// 注意要采用双栈求值
//#define MAX 10000
//
//int stk_num[MAX];
//char stk_op[MAX];
//int top_num = -1;
//int top_op = -1;
//
//void push_num(int n) { stk_num[++top_num] = n; }
//int pop_num(void) { return stk_num[top_num--]; }
//void push_op(char n) { stk_op[++top_op] = n; }
//char pop_op(void) { return stk_op[top_op--]; }
//
//int pri(char op) {
//    if (op == '*' || op == '/') return 2;
//    if (op == '+' || op == '-') return 1;
//    return 0; // 左括号
//}
//
//int answer(int a, int b, char x) {
//    switch (x) {
//    case '+': return a + b;
//    case '-': return a - b;
//    case '*': return a * b;
//    case '/': return b ? a / b : 0; // 简单处理
//    }
//    return 0;
//}
//
//int solve(char* s) {
//    int i = 0;
//    while (s[i] != '\0') {
//        if (s[i] == ' ') { i++; continue; }
//
//        // 读取数字（支持多位数）
//        if (s[i] >= '0' && s[i] <= '9') {
//            int num = 0;
//            while (s[i] >= '0' && s[i] <= '9') {
//                num = num * 10 + (s[i] - '0');
//                i++;
//            }
//            push_num(num);
//        }
//        // 左括号直接入栈
//        else if (s[i] == '(') {
//            push_op(s[i]);
//            i++;
//        }
//        // 右括号：处理直到遇到左括号
//        else if (s[i] == ')') {
//            while (stk_op[top_op] != '(') {
//                char op = pop_op();
//                int b = pop_num();
//                int a = pop_num();
//                push_num(answer(a, b, op));
//            }
//            pop_op(); // 弹出左括号
//            i++;
//        }
//        // 运算符
//        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
//            // 如果当前操作符优先级 <= 栈顶操作符，先算栈内的
//            while (top_op != -1 && pri(stk_op[top_op]) >= pri(s[i])) {
//                char op = pop_op();
//                int b = pop_num();
//                int a = pop_num();
//                push_num(answer(a, b, op));
//            }
//            push_op(s[i]);
//            i++;
//        }
//        else {
//            // 非法字符，忽略或报错
//            i++;
//        }
//    }
//
//    // 处理剩余操作符
//    while (top_op != -1) {
//        char op = pop_op();
//        int b = pop_num();
//        int a = pop_num();
//        push_num(answer(a, b, op));
//    }
//
//    return stk_num[top_num];
//}
int main()
{
	//noob87有效括号序列
	/*char s[MAX];
	scanf_s("%s", s, MAX);
	for (int i = 0;i < strlen(s);i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			push(s[i]);
		}
		else if (s[i] == ')')
		{
			if (top == -1)
			{
				printf("false");
				return 0;

			}
			char t = pop();
			if (t != '(')
			{
				printf("false");
				return 0;
			}
		}
		else if (s[i] == ']')
		{
			if (top == -1)
			{
				printf("false");
				return 0;

			}
			char t = pop();
			if (t != '[')
			{
				printf("false");
				return 0;
			}
		}
				else if (s[i] == '}')
				{
					if (top == -1)
					{
						printf("false");
						return 0;

					}
					char t = pop();
					if (t != '{')
					{
						printf("false");
						return 0;
					}
		}
	}
	if (top == -1)
	{
		printf("true");
	}
	else
		printf("false");*/





	return 0;
}