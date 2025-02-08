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
    ListNode* reversePartList(ListNode* head){
        ListNode *back = nullptr, *front = head;

        while (front){
            ListNode* temp = front->next;
            front->next = back;
            back = front;
            front = temp;
        }

        return head;
    }

    ListNode* reverseList(ListNode* head, int k){
        if (!head) return head;

        ListNode *ptr = head, *part = ptr;

        for (int i = 0; i < k; i++){
            if (!ptr->next && i < k-1) return head;
            part = ptr;
            ptr = ptr->next;
        }

        ListNode *nextHead = reverseList(ptr, k);
        part->next = nullptr;

        ListNode* newList = reversePartList(head);
        newList->next = nextHead;
        return part;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseList(head, k);
    }
};