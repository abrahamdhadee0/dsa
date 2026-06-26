#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Node{
    public :
    Node* list[26];
    bool flag=false;

    Node(){
        for(int i=0;i<26;i++){
            list[i]=nullptr;
        }
    }
    bool containskey(char ch){
        return list[ch-'a']!=nullptr;
    }
    void put(char ch,Node* node){
        list[ch-'a']=node;
    }
    Node* get(char ch){
        return list[ch-'a'];
    }
    void setend(){
        flag=true;
    }
    bool isend(){
        return flag;
    }
};
class Trie {
    private:
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new Node());
            }
            node= node->get(word[i]);
        }
        node->setend();
    }
    bool search(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                return false;
            }
            node= node->get(word[i]);
        }
        return node->isend();
    }
 bool startsWith(string prefix){
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containskey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }

};