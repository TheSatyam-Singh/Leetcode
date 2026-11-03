class Trie {
public:
    struct Node{
        Node* a[26];
        bool flag;
        Node(){
            flag = false;
            for(int i=0;i<26;i++){
                a[i]=nullptr;
            }
        }
    };
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* temp=root;
        for(char i:word){
            int idx=i-'a';
            if(temp->a[idx]==nullptr){
                temp->a[idx]=new Node();
            }
            temp=temp->a[idx];
        }
        temp->flag=true;
    }
    
    bool search(string word) {
        Node* temp=root;
        for(char i:word){
            int idx=i-'a';
            if(temp->a[idx]==nullptr){
                return false;
            }
            temp=temp->a[idx];
        }
        return temp->flag;
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        for(char i:prefix){
            int idx=i-'a';
            if(temp->a[idx]==nullptr){
                return false;
            }
            temp=temp->a[idx];
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