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
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        int sum, carry = 0;
        ListNode* head = nullptr;
        while(l1 != nullptr && l2 != nullptr){
            sum = l1->val + l2->val + carry;
            carry = sum/10;
            ListNode* curr = new ListNode(sum%10);
            curr->next = head;
            head = curr;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr){
            sum = l1->val + carry;
            carry = sum/10;
            ListNode* curr = new ListNode(sum%10);
            curr->next = head;
            head = curr;
            l1 = l1->next;
        }
        while(l2 != nullptr){
            sum = l2->val + carry;
            carry = sum/10;
            ListNode* curr = new ListNode(sum%10);
            curr->next = head;
            head = curr;
            l2 = l2->next;
        }
        if(carry){
            ListNode* curr = new ListNode(carry);
            curr->next = head;
            head = curr;
        }
        return head;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        stack<ListNode*> nodes;
        while(head != nullptr){
            nodes.push(head);
            head = head->next;
        }
        head = nodes.top();
        ListNode* temp = nodes.top();
        nodes.pop();
        while(!nodes.empty()){
            temp->next = nodes.top();
            temp = temp->next;
            nodes.pop();
        }
        temp->next = nullptr;
        return head;
    }
};