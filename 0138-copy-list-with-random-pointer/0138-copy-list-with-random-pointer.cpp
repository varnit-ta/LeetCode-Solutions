class Solution {
public:
    void printNodes(Node* node){
        while (node) {
            cout << node->val << " ";
            node = node->next;
        }
    }

    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Create the new nodes and interleave them with the original list
        Node* ptr = head;
        while (ptr) {
            Node* newNode = new Node(ptr->val);
            newNode->next = ptr->next;
            ptr->next = newNode;
            ptr = ptr->next->next;
        }

        // Step 2: Assign the random pointers for the new nodes
        ptr = head;
        while (ptr) {
            Node* newNode = ptr->next;
            newNode->random = (ptr->random) ? ptr->random->next : nullptr;
            ptr = ptr->next->next;
        }

        ptr = head;
        Node* dummy = head->next;
        Node* copyPtr = dummy;

        while (ptr) {
            ptr->next = ptr->next->next;
            if (copyPtr->next) {
                copyPtr->next = copyPtr->next->next; 
                copyPtr = copyPtr->next;
            }
            ptr = ptr->next;
        }

        printNodes(dummy);
        
        return dummy;
    }
};
