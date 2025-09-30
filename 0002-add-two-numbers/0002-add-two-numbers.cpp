// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

// class Solution {
// public:
//     ListNode* addTwoNumbers(Node* l1,Node* l2) {
//         // ListNode* dummy = new ListNode(0); // dummy head
//         // ListNode* current = dummy;
//         // int carry = 0;

//         // while (l1 != nullptr || l2 != nullptr || carry != 0) {
//         //     int sum = carry;

//         //     if (l1 != nullptr) {
//         //         sum += l1->val;
//         //         l1 = l1->next;
//         //     }

//         //     if (l2 != nullptr) {
//         //         sum += l2->val;
//         //         l2 = l2->next;
//         //     }

//         //     carry = sum / 10;
//         //     current->next = new ListNode(sum % 10);
//         //     current = current->next;
//         // }

//         // return dummy->next;
//         Node* dummtHead=new Node(-1);
//         Node* curr=dummyHead;
//         Node* temp1=l1;
//         Node*temp2=l2;
//         int carry=0;
//         while(temp1!=NULL||temp2!=NULL){
//             if(temp1)sum+=temp1->data;
//             if(temp2)sum+=temp2->data;
//             Node* newNode =new Node(sum%10);
//             carry=sum/10;

//             curr->next=newNode;
//             curr=curr->next;

//             if(temp1)temp1=temp1>next;
//             if(temp2)temp2=temp2->next;
//         }
//         if(carry){
//             Node* newNode=new Node(carry);
//             curr->next=newNode;
//         }
//         if(carry){
//             Node* newNode=new Node(carry);
//             curr->next=newNode;
//         }
//         reurn dummyHead->next;
//     }

//         }
//     }
// };
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1);  // dummy head
        ListNode* curr = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummyHead->next;
    }
};
