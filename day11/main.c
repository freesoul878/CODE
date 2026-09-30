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
 * @param head ListNode类 
 * @param val int整型 
 * @return ListNode类
 */
//noob112移除链表元素

/*struct ListNode* removeElements(struct ListNode* head, int val ) {
   
   struct ListNode *n1 = head;
   struct ListNode *n2 = head -> next;
   if(head == NULL)
   return NULL;
   struct ListNode *t = removeElements(n2, val);
   if(head -> val == val)
   {
    return t;

   }
   else {
    head -> next = t;
   return head;
   }
}
   */
  //noob113链表反转
  /*struct ListNode* ReverseList(struct ListNode* head ) {
    struct ListNode *cur = head;
    struct ListNode *next;
    struct ListNode *pre = NULL;
    while (cur != NULL){
    next = cur ->next;
    cur -> next = pre;
    pre = cur;
    cur = next;
    }
    return pre;
}*/
int main() {
    printf("Hello, World!\n");
    return 0;
}