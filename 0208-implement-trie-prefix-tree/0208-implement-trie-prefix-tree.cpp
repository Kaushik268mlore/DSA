struct TN{
    struct TN * child[26];
    bool end;
    
} *node;
class Trie {
public:
    
    Trie() {
        node=new TN();
    }
    
    void insert(string word) {
        TN *temp=node;
        for(char c:word){
            c-='a';
            if(!temp->child[c]){
                temp->child[c]=new TN();
            }
            temp=temp->child[c];
        }
    temp->end=true;
    }
    
    
    bool search(string word) {
    TN *temp=node;
        for(char c:word){
            c-='a';
            if(!temp->child[c])return false;
            temp=temp->child[c];
        }
          return (temp->end);

    }
    
    bool startsWith(string word) {
        TN *temp=node;
        for(char c:word){
            c-='a';
            if(!temp->child[c])return false;
            temp=temp->child[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */