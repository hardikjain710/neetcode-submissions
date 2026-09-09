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
    void reorderList(ListNode* head) {
        ListNode* curr = head;

        ListNode* temp = head->next;

        while (curr->next != NULL) {
            ListNode* last = temp;
            ListNode* prev = NULL;
            if (last->next != NULL) {
                while (last->next != NULL) {
                    prev = last;
                    last = last->next;
                }
                curr->next = last;
                last->next = temp;
                prev->next = NULL;
                curr = curr->next->next;
                if (curr->next == NULL) {
                    break;
                }
                temp = curr->next;
            }
            else{
                break;
            }
            
        }
    }
};
