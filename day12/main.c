#include<stdio.h>
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param arr int整型一维数组 
 * @param arrLen int arr数组长度
 * @return ListNode类
 */
#include <stdlib.h>
//noob115链表序列化
/*struct ListNode* vectorToListnode(int* arr, int arrLen ) {
    int i = 0;
    if(arrLen == 0)
    {
    
    return NULL;
    }
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head ->val = *arr;
    
    struct ListNode *cur;
    cur = head;
    for(i = 1;i<arrLen;i++)
    {
        arr++;
        struct ListNode *newnode = malloc(sizeof(struct ListNode));
        cur -> next = newnode;
        newnode -> val = *arr;
        cur = cur ->next;



    }
    return head;
}*/
//noob116合并链表
/*struct ListNode* Merge(struct ListNode* pHead1, struct ListNode* pHead2 ) {
    struct ListNode *head =malloc(sizeof(struct ListNode));
    struct ListNode *cur1 = pHead1;
    struct ListNode *cur2 = pHead2;
    struct ListNode *cur = head;
    while(cur1 != NULL ||cur2 != NULL )
    {
        struct ListNode *newnode =malloc(sizeof(struct ListNode));
        cur -> next = newnode;
        if(cur1 !=  NULL &&cur2 != NULL){
        if(cur1 ->val <= cur2 -> val)
        {
            newnode->val = cur1 -> val;
            cur1 = cur1 -> next;
        }
        else 
        {
            newnode ->val = cur2 ->val;
            cur2 = cur2 -> next;
        }
        }
        else if(cur1 == NULL)
        {
            newnode -> val = cur2 ->val;
            cur2 = cur2 ->next;
        }
        else{
            newnode -> val =cur1 -> val;
            cur1 = cur1 ->next;
        }
        cur = cur ->next;
    }
    return head->next;
}*/
//noob118判断回文数链表，采用快慢指针防止malloc调用保证空间复杂度为O(1)
bool isPail(struct ListNode* head ) {
    if(head ==NULL)
    return false;
    if(head->next == NULL)
    {
        return true;
    }
    struct ListNode *slow = head ;
    struct ListNode *fast = head ;
    int count = 0;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
       count++;
        
    }
    struct ListNode *pre = NULL;
    struct ListNode *next ;
    struct ListNode *cur = slow;
    while(cur != NULL)
    {
        next = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = next;
    }
    struct ListNode *cur1 = pre;
    struct ListNode *cur2 = head;
    
    while(count--)
    {
        if(cur1 -> val != cur2 -> val)
        {
            return false;
        }
        cur1 = cur1 -> next;
        cur2 = cur2 -> next;
    }
    return true;


   
}
int main() {
    printf("Hello, World!\n");
    return 0;
}