/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* slow2 = head;
        ListNode* fast = head;
        while(slow != nullptr && fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }
        if(slow == nullptr || fast == nullptr || fast->next == nullptr){
            return NULL;
        }
        while(slow2->val != slow->val){
            slow = slow->next;
            slow2 = slow2->next;
        }
        return slow;
    }
};