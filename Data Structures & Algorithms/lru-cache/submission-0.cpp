class LRUCache {
private:
    struct Node{
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr){}
    };
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

public:
    LRUCache(int capacity) {
        head = new Node(0,0);
        tail = new Node(0,0);
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(Node* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){return -1;}
        Node* node = cache[key];
        remove(node);
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* updateNode = cache[key];
            updateNode->value = value;
            remove(updateNode);
            moveToHead(updateNode);
            
        }else{
            if(cache.size() == capacity){
            Node* last = tail->prev;
            cache.erase(last->key);
            remove(last);
            delete last;
            }
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            moveToHead(newNode);
            
        }

                
        
    }
};
