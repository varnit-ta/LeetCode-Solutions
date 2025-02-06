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
    ListNode* recuFunction(ListNode* curr, ListNode* prev){
        if (curr){
            ListNode* nextCur = curr->next;
            curr->next = prev;

            return recuFunction(nextCur, curr);
        }

        return prev;
    }


    ListNode* reverseList(ListNode* head) {
        return recuFunction(head, nullptr);
    }
};