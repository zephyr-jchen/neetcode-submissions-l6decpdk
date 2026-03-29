class PrefixTree {
private:
    struct Node{
        Node* children[26] = {nullptr};
        bool isEnd = false;
    };
    Node* root;

    Node* findNode(string& s){
        Node* cur = root;
        for(char c:s){
            if(!cur->children[c-'a']){return nullptr;}
            cur = cur->children[c-'a'];
        }
        return cur;
    }

public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for(char c:word){
            if(!cur->children[c - 'a']){
                cur->children[c - 'a'] = new Node();
            }
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        Node* node = findNode(word);
        return (node&&node->isEnd);
    }
    
    bool startsWith(string prefix) {
        Node* node = findNode(prefix);
        return node;
    }
};
