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
    bool hasCycle(ListNode *head) {
        set<ListNode*> visited;
        while(head != nullptr){
            if(visited.count(head)){
                return true;
            }
            visited.emplace(head);
            head = head->next;
        }
        return false;
    }
};