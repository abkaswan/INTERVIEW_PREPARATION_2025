#include<iostream>
#include<string>
using namespace std;

// time complexity : O(len) for each operation and space complexity : O(len) for insert operation , O(1) for search and startsWith

// trie : class or struct , two variables Trie{Node* links[26];bool flag;}
// 0 -> a, 1 -> b ....
// see the striver introduction video for this : https://youtu.be/dBGUmUQhjaM?si=cKbOFk4D8SMgXOVB

struct Node {
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
private: Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    // inserts a word into the trie
    // tc : O(len)
    void insert(string word) {
        Node* node = root;
        // need to insert the whole word here
        for(int i = 0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            // move to the reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    // returns if the word is in the trie
    // tc : O(len)
    bool search(string word) {
        Node* node = root;
        for(int i = 0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            // move to the reference
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    // reutrns if there is any word in the trie that starts with the given
    // tc : O(len)
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            // move to the reference
            node = node->get(prefix[i]);
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
int main(){
    Trie* obj = new Trie();
    obj->insert("apple");
    bool param_2 = obj->search("apple"); // return true
    bool param_3 = obj->startsWith("app"); // return true
    obj->insert("app");
    bool param_4 = obj->search("app"); // return true
    cout<<param_2<<endl;
    cout<<param_3<<endl;
    cout<<param_4<<endl;
    return 0;
}