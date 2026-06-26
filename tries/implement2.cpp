struct Node{
    public:
    Node* Links[26];
    int end=0;
    int pre=0;
    
    Node(){
        for(int i=0;i<26;i++){
            Links[26]=nullptr;
        }
    }
    bool ck(char c){
        return (Links[ch-'a']!=nullptr);
    }
    Node* get(char ch,Node* node){
        return Links[ch-'a'];
    }
    void put(char ch,Node* node){
        Links[ch-"a"]=node;
    }
    void incend(){
        end++;
    }
    void decend(){
        end--;
    }
    void incpre(){
        pre++;
    }
    void decpre(){
        pre--;
    }
    
};
class Trie{
    private Node* root;
    
    Trie(){
        root=new Node();
    }
    void insert(String &word){
        for(int i=0;i<word.size();i++){
            if(!node->ck(word[i])){
                node->put(word[i],new Node());
            }
            node =node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    int count(String &word){
        Node* node=root;
        for(int i=0;i<word.size();i++{
            if(node->ck(word[i])){
                node=node->get(word[i]);
            }
            else return 0;
        }
        node->getEnd();
    
    }
    int countword(String &word){
        Node* node=root;
        for(int i=0;i<word.size();i++{
            if(node->ck(word[i])){
                node=node->get(word[i]);
            }
            else return 0;
        }
        node->getprefix();
    
    }
    void erase(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node.ck(word[i])){
                node=node->get(word[i]);
                node->reducePrefix();
            }
            else{
                return;
            }
            node->deleteEnd();
        }
    }
};
