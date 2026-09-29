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
 * @return ListNode类
 */
//noob111用递归实现链表两两交换

struct ListNode* swapPairs(struct ListNode* head ) {
    struct ListNode *p = head;
    int t;
    
    
    if(head == NULL || head -> next == NULL)
    return head;
  
    else  {
        struct ListNode *n1 = head;
        struct ListNode *n2 = head -> next;
        struct ListNode *rest = swapPairs(n2 -> next);
        n2 -> next = n1;
        n1 -> next = rest;
        return n2;
        
    }
     

}