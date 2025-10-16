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
        if (!head) return NULL;

        // Step 1: Create a copy node after each original node
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Step 2: Assign random pointers for the copied nodes
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // Step 3: Separate the original and copied list
        curr = head;
        Node* newHead = head->next;
        Node* copyCurr = newHead;
        while (curr) {
            curr->next = curr->next->next;
            if (copyCurr->next)
                copyCurr->next = copyCurr->next->next;
            curr = curr->next;
            copyCurr = copyCurr->next;
        }

        return newHead;
    }
};
