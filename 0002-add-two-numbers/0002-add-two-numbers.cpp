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
        ListNode* head = new ListNode();
        ListNode* temp = head;
        int carry = 0, sum;
        while(l1 != nullptr && l2 != nullptr){
            sum = l1->val + l2->val + carry;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
            carry = sum/10;
        }
        while(l1 != nullptr){
            sum = l1->val + carry;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            l1 = l1->next;
            carry = sum/10;
        }
        while(l2 != nullptr){
            sum = l2->val + carry;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            l2 = l2->next;
            carry = sum/10;
        }
        if(carry){
            temp->next = new ListNode(carry);
        }
        head = head->next;
        return head;
    }
};