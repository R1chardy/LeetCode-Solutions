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
    void reorderList(ListNode* head) {
        list<ListNode*> nodes;
        ListNode* temp = head;
        while(temp != nullptr){
            nodes.push_front(temp);
            temp = temp->next;
        }
        nodes.pop_back();
        int alt = 0;
        while(!nodes.empty()){
            cout << alt << " ";
            if(alt%2 == 0){
                head->next = nodes.front();
                nodes.pop_front();
            }
            else{
                head->next = nodes.back();
                nodes.pop_back();
            }
            head = head->next;
            alt++;
        }
        head->next = nullptr;
    }
};