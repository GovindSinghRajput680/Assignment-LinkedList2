#include<iostream>
using namespace std;
class ListNode{//User defined data type
public:
    int val;
    ListNode *next;
    ListNode(int val){
        this->val = val;
        next = NULL;
    }
};
void display(ListNode *head){
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
//Q 1->LEETCODE->2095
ListNode* deleteMiddle(ListNode* head) {
        ListNode *s = head,*f = head->next;
        if(f == NULL) return NULL;
        f = f->next;
        while(f != NULL && f->next != NULL){
            s = s->next;
            f=f->next->next;
        }
        s->next = s->next->next;
        return head;
    }

//Q 2->LEETCODE->1669
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp = list1;
        ListNode *ptra = list1;
        for(int i =1;i<=b+1;i++) {temp = temp->next;
            if(i == a-1) ptra = temp;
        }
        ptra->next = list2;
        ListNode *t2 = list2;
        while(t2->next != NULL) t2 = t2->next;
        t2->next= temp;
        return list1;
    }

//Q 3 ->LEETCODE ->1721
ListNode* swapNodes(ListNode* head, int k) {ListNode* temp = head;
        for(int i =1;i<k;i++) temp =temp->next;
      ListNode *s = head,*f = temp;
       while(f->next != NULL ){
           s=s->next;
           f= f->next;
       }
        int t = temp->val;
        temp->val = s->val;
        s->val = t;
    return head;
    }
//Q 4
ListNode* deleteNode(ListNode* head,int val){
    ListNode* temp = head;
    while(temp != NULL && temp ->next != NULL){
        if(temp->next->val == val) temp->next = temp->next->next;
        else temp = temp->next;
    }
if( head != NULL && head->val ==  val) return head->next;
return head;
}

//Q 5
//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct ListNode *head)
{ListNode *s = head,*f = head;
bool flag = false;
   while(f != NULL && f->next != NULL){
       s = s->next;
       f = f->next->next;
       if(s == f){
           flag = true;
           break;
       }
   }
   if(!flag) return 0;
   ListNode *temp = head;
   while(temp != s) temp = temp->next,s = s->next;
   int len =0;
   while(true) {len++,s = s->next;
                if(s == temp) break;}
   
   return len;
   
}
int main(){ListNode* a = new ListNode(10);
    ListNode *b = new ListNode(10);
    ListNode *c = new ListNode(10);
    ListNode *d = new ListNode(5);
    a->next = b;
    b->next = c;
    c->next = d;

    display(deleteNode(a,10));

}