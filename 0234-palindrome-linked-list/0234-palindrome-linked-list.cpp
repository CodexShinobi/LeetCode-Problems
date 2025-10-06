// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         vector<int> vals;
//         while (head) {
//             vals.push_back(head->val);
//             head = head->next;
//         }
//         int i = 0, j = vals.size() - 1;
//         while (i < j) {
//             if (vals[i++] != vals[j--]) return false;
//         }
//         return true;
//     }
// };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* second = reverseList(slow->next);
        ListNode* first = head;

        // Step 3: Compare halves
        ListNode* copySecond = second; // to restore later if needed
        bool isPalin = true;
        while (second) {
            if (first->val != second->val) {
                isPalin = false;
                break;
            }
            first = first->next;
            second = second->next;
        }

        // Step 4: Restore the list (optional)
        slow->next = reverseList(copySecond);

        return isPalin;
    }
};
