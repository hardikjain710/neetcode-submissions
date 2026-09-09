/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len=1;
        ListNode* curr=head;
        while(curr->next!=NULL){
            len++;
            curr=curr->next;
        }
        if(len==n){
            return head->next;
        }
        if(head->next==NULL && n==1){
            return NULL;
        }
     
        int node=len-n;
        int t=1;
        curr=head;
        while(t!=node){
            curr=curr->next;
            t++;
        }

        ListNode* temp=curr->next->next;
        curr->next=temp;
   
        return head;
    }
};
