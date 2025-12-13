class Node {
public:
    int key, value;
    Node *prev, *next;

    Node(){
        key = -1;
        value = -1;
        prev = nullptr;
        next = nullptr;
    }

    Node(int k, int v){
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    Node *head, *tail;
    int capacity;

    LRUCache(int _capacity) {
        capacity = _capacity;
        head = new Node();
        tail = new Node();
        mp.clear();

        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* ptr){
        Node* prevNode = ptr->prev;
        Node* nextNode = ptr->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertNode(Node* ptr){
        Node* nextNode = head->next;
        ptr->next = nextNode;
        ptr->prev = head;

        head->next = ptr;
        nextNode->prev = ptr;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];
        deleteNode(node);
        insertNode(node);
        return node->value;
    }
    
    void put(int key, int value) {
        Node* node;

        if (mp.find(key) == mp.end()){
            node = new Node(key, value);

            if (mp.size() == capacity){
                Node* temp = tail->prev;
                deleteNode(temp);
                mp.erase(temp->key);
                delete temp;
            }

            mp[key] = node;
        }else{
            node = mp[key];
            node->value = value;
            deleteNode(node);
        }

        insertNode(node);
    }
};