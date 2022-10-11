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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        ListNode* ret = head;
        ListNode* temp;
        int minV;
        int index;
        while(true){
            minV = INT_MAX;
            for(int i = 0; i < lists.size(); i++){
                if(lists[i] != nullptr && lists[i]->val < minV){
                    minV = lists[i]->val;
                    index = i;
                }
            }
            if(minV == INT_MAX){
                break;
            }
            temp = new ListNode(minV);
            head->next = temp;
            head = temp;
            lists[index] = lists[index]->next;
        }
        head->next = nullptr;
        ret = ret->next;
        return ret;
    }
};