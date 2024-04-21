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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*> list;

        ListNode *ptr = head;
        while (ptr){
            list.push_back(ptr);
            ptr = ptr->next;
        }

        swap(list[k-1]->val, list[list.size() - k]->val);
        
        return head;
    }
};