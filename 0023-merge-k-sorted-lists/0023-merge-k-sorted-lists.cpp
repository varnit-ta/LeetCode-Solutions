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
    vector<int> data;

    void captureData(vector<ListNode*> &c){
        for (int i = 0; i < c.size(); i++){
            ListNode *ptr =  c[i];

            while (ptr != NULL){
                data.push_back(ptr->val);
                ptr = ptr->next;
            }
        }
    }

    ListNode* createLinkedList(vector<int> data){
        ListNode* root = NULL;
        ListNode* current = root;

        for (int val : data) {
            if (root == NULL) {
                root = new ListNode(val);
                current = root;
            } else {
                current->next = new ListNode(val);
                current = current->next;
            }
        }

        return root;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        captureData(lists);
        sort(data.begin(), data.end());
        return createLinkedList(data);
    }
};
