struct Node{
    public:
    Node* Links[26];
    int end=0;
    int pre=0;
    
    Node(){
        for(int i=0;i<26;i++){
            Links[i]=nullptr;
        }
    }
    bool ck(char ch){
        return (Links[ch-'a']!=nullptr);
    }
    Node* get(char ch){
        return Links[ch-'a'];
    }
    void put(char ch,Node* node){
        Links[ch-'a']=node;
    }
    
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    int  insert(string &word){
        Node* node=root;
        int cnt=0;
        for(int i=0;i<word.size();i++){
            if(!node->ck(word[i])){
                node->put(word[i],new Node());
                cnt++;
            }
            node =node->get(word[i]);
         //   node->increasePrefix();
        }
        return cnt;
    }
    };
class Solution {
  public:
    int countSubs(string& s) {
        Trie  trie;
        int ans=0;
       for(int i=0;i<s.size();i++){
           string temp=s.substr(i);
           ans+=trie.insert(temp);
       }
       return ans;
    }
};