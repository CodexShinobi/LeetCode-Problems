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
    ListNode* reverseList(ListNode* head) {
//         ListNode* prev= NULL;
//         ListNode* curr=head;
//         ListNode* next=NULL;

//         while(curr != NULL){
//             next=curr->next;
//             curr->next=prev;

//             prev=curr;
//             curr=next;
//         }
//         return prev;
        
//     }
// };
ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextnode = curr->next; // save next
            curr->next = prev;               // reverse link
            prev = curr;                     // move prev forward
            curr = nextnode;                 // move curr forward
        }
        return prev;
    }
}; 