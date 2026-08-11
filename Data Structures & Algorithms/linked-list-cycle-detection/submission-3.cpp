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
    bool hasCycle(ListNode* head) {
        // ListNode* curr = head;
        // if(curr==nullptr || curr->next==nullptr){
        //     return false;
        // }
        // std::unordered_set<ListNode*> st;
        // while(curr!=nullptr){
        //     if(st.count(curr) != 0){
        //         return true;
        //     }
        //     st.insert(curr);
        //     curr = curr->next;
        // }
        // return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};
