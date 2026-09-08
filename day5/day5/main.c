#include<stdio.h>
//noob95队列消数
//int timeRequiredToBuy(int* tickets, int ticketsLen, int k) {
//    int q[1000000];
//    int head, tail = 0;
//    int i, j;
//    for (i = 0;i < ticketsLen;i++)
//    {
//        q[tail++] = tickets[i];
//    }
//
//    int time = 0;
//    int num = k;
//    while (1)
//    {
//        if (head == num) {
//            if (q[head] > 1)
//            {
//                q[head]--;
//                q[tail++] = q[head];
//                head++;
//                num = tail - 1;
//                time++;
//            }
//            else {
//                time++;
//                break;
//
//            }
//        }
//        else {
//            if (q[head] > 1)
//            {
//                q[head]--;
//                q[tail++] = q[head];
//                head++;
//                time++;
//
//            }
//            else {
//                head++;
//                time++;
//            }
//        }
//
//    }
//    return time;
//
//}

//noob96双栈模拟队列
//#define MAX 1000
//int in[MAX];
//int out[MAX];
//int top1 = -1;
//int top2 = -1;
//void push(int node) {
//	in[++top1] = node;
//
//}
//int pop() {
//    int i;
//    if (top2 != -1) {
//        while (top1 != -1)
//        {
//            out[++top2] = in[top1--];
//        }
//    }
//    return out[top2--];
//
//}
//noob97参议院投票
//char* predictVictory(char* s) {
//    int q1[10000];
//    int q2[10000];
//    int head1 = 0, tail1 = 0;
//    int head2 = 0, tail2 = 0;
//    int i;
//    for (i = 0;i < strlen(s);i++)
//    {
//        if (s[i] == 'R')
//            q1[tail1++] = i;
//        else
//            q2[tail2++] = i;
//    }
//    int n = strlen(s);
//    while (!(tail1 == head1) && !(tail2 == head2)) {
//        int a = head1++;
//        int b = head2++;
//        if (q1[a] < q2[b])
//        {
//            q1[tail1++] = q1[a] + n;
//        }
//        else {
//            q2[tail2++] = q2[b] + n;
//        }
//    }
//    if (head1 == tail1)
//        return "Dark";
//    else
//        return "Red";
//}
int main()
{


	return 0;
}