class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* backPtr = head;
        ListNode* frontPtr = head;

        for (int i = 0; i < n; i++) {
            if (frontPtr == nullptr) {
                return head;
            }
            frontPtr = frontPtr->next;
        }
        
        if (frontPtr == nullptr) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        while (frontPtr->next != nullptr) {
            frontPtr = frontPtr->next;
            backPtr = backPtr->next;
        }
        
        ListNode* temp = backPtr->next;
        backPtr->next = temp->next;
        delete temp;
        
        return head;
    }
};