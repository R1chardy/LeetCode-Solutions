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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ret = new ListNode(0);
        ListNode* tail = ret;
        stack<ListNode*> s;
        int c = k;
        while(head != nullptr){
            s.push(head);
            head = head->next;
            c--;
            if(c <= 0){
                while(!s.empty()){
                    tail->next = s.top();
                    s.pop();
                    tail = tail->next;
                }
                c = k;
            }
        }
        if(s.empty()){
            tail->next = nullptr;
        }
        else{
            ListNode* temp;
            while(!s.empty()){
                temp = s.top();
                s.pop();
            }
            tail->next = temp;
        }
        ret = ret->next;
        return ret;
    }
};