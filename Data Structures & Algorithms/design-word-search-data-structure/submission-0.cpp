class WordDictionary {
private:
    struct Node{
        Node* children[26] = {nullptr};
        bool isEnd = false;
    };

    Node* root;

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = root;
        for(char c:word){
            if(!cur->children[c-'a']){
                cur->children[c-'a'] = new Node();
            }
            cur = cur->children[c-'a'];
        }
        cur->isEnd = true;
        return;
    }
    
    bool search(string word) {
        Node* cur = root;
        return dfs(word,0,root);
    }

    bool dfs(string& word,int i,Node* cur){
        if (!cur) return false;
        if(i == word.size()){return cur->isEnd;}
        char c = word[i];
        if(c != '.'){
            if(cur->children[c-'a']){
                return dfs(word,i+1,cur->children[c-'a']);
            }else{
                return false;
            }        
        }else{
            for(int j = 0;j<26;j++){
                if(dfs(word,i+1,cur->children[j])) {
                    return true;
                }
            }

        }
        
        return false;

    }
};
