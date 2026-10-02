#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//noob119插队但是指针链表会导致超时，需要切换数组链表
#define MAX 250000
char a[MAX][10];
struct Listnode 
{
    char* name;
    struct Listnode*next;
};
struct Listnode *chushi(char name[][10],int len)
{
    struct Listnode *head = malloc(sizeof(struct Listnode));
    head -> name = name[0];
    head -> next = NULL;
    struct Listnode *cur = head;
    int i = 0;
    for(i = 1;i<len;i++)
    {
        struct Listnode *newcode = malloc(sizeof(struct Listnode));
        cur -> next = newcode;
        newcode ->name = name[i];
        newcode ->next = NULL;
        cur = cur->next;


    }
    return head;

}
void dayin(struct Listnode *head)
{
    struct Listnode *cur = head;
    while(cur != NULL)
    {
        printf("%s ",cur->name);
        cur = cur ->next;
    }
}
struct Listnode *swap(char *a,char*b,struct Listnode *head)
{
    struct Listnode *pre,*cur,*next;
    struct Listnode *pre1,*cur1 =NULL,*next1;
    struct Listnode *pre2,*cur2 = NULL,*next2;
    struct Listnode *jnode = malloc(sizeof(struct Listnode));
    jnode ->next = head;
    pre = jnode;
    cur = head;
    next = head -> next;
    int first_found = 0;
    while(cur != NULL)
    {
        if(strcmp(a,b) == 0)
        {
            return head;
        }
        
        if(first_found == 0)
        {
        if(strcmp(cur -> name ,a) ==0)
        {
            pre1 = pre;
            cur1 = cur;
            next1 = cur->next;
            first_found = 1;
            
        }
        if(strcmp(cur ->name,b) == 0)
        {
            pre2 = pre;
            cur2 = cur;
            next2 = cur ->next;
            first_found = 2;

        }
        
    }
    else{
            if(strcmp(cur -> name ,a) ==0)
        {
            pre1 = pre;
            cur1 = cur;
            next1 = cur->next;
            
        }
        if(strcmp(cur ->name,b) == 0)
        {
            pre2 = pre;
            cur2 = cur;
            next2 = cur ->next;

        }
        }
        next = cur -> next;
        pre = cur;
        cur = next;

    }

    if(cur1 == NULL||cur2 ==NULL)
    {
        return head;
    }
    if(first_found == 1)
    return head;
    else if(first_found == 2){
  
 if(cur2 -> next ==cur1)
{
    pre2 -> next = cur1;
    cur1 -> next = cur2;
    cur2 -> next = next1;
}
else
{
    pre1 ->next = cur2;
    pre2 ->next = cur1;
    cur1 ->next = next2;
    cur2 ->next = next1;
}
    }
    return jnode->next;

}

int main() {
    int n,m;
    
    scanf("%d %d",&n,&m);
    int i;
    for(i = 0;i<n;i++)
    {
        scanf("%s",a[i]);

    }
    struct Listnode *head = chushi(a ,n);
    
    while(m--)
    {
        char a[10],b[10];
        scanf("%s %s",a,b);
        head = swap(a,b,head);
    }
    dayin(head);

    return 0;
}
