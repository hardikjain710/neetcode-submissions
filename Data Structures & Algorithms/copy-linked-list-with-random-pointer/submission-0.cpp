/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        Node* newhead = new Node(1);

        Node* ans = newhead;
        Node* curr = head;

        unordered_map<Node*, Node*> mp;

        while (curr != NULL) {
            int value = curr->val;
            Node* temp = new Node(value);
            newhead->next = temp;
            mp[curr] = temp;
            newhead = newhead->next;
            curr = curr->next;
        }
        curr = head;
        newhead = ans->next;

        while (curr != NULL) {
            Node* x = mp[curr->random];

            newhead->random = x;
            newhead=newhead->next;

            curr = curr->next;
        }

        return ans->next;
    }
};
