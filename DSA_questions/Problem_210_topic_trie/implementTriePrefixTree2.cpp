#include<iostream>
#include<string>
using namespace std;
// time complexity : O(length of word) and space complexity : O(1)
struct Node{
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    bool containskey(char ch){
        return links[ch-'a']!=nullptr;
    }
    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void increaseEndWith(){
        cntEndWith++;
    }
    int getPrefix(){
        return cntPrefix;
    }
    int getEndWith(){
        return cntEndWith;
    }
    void decreasePrefix(){
        cntPrefix--;
    }
    void decreaseEndWith(){
        cntEndWith--;
    }

};
class Trie{
    private : Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i = 0;i<word.size();i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEndWith();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i = 0;i<word.size();i++){
            if(node->containskey(word[i])){
                node = node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getEndWith();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i = 0;i<word.size();i++){
            if(node->containskey(word[i])){
                node = node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(string &word){
        Node* node = root;
        for(int i = 0;i<word.size();i++){
            if(node->containskey(word[i])){
                node = node->get(word[i]);
                node->decreasePrefix();
            }
            else{
                return;
            }
        }
        node->decreaseEndWith();
    }
};

int main(){
    Trie trie;
    string apple = "apple";
    string banana = "banana";
    string orange = "orange";
    string a = "a";
    string b = "b";
    string o = "o";
    
    trie.insert(apple);
    trie.insert(banana);
    trie.insert(orange);

    cout << "Number of words equal to apple: " << trie.countWordsEqualTo(apple) << endl;
    cout << "Number of words starting with a: " << trie.countWordsStartingWith(a) << endl;
    cout << "Number of words starting with b: " << trie.countWordsStartingWith(b) << endl;
    cout << "Number of words starting with o: " << trie.countWordsStartingWith(o) << endl;
    cout << "Number of words equal to orange: " << trie.countWordsEqualTo(orange) << endl;

    trie.erase(apple);
    cout << "Number of words starting with a: " << trie.countWordsStartingWith(a) << endl;
    cout << "Number of words starting with b: " << trie.countWordsStartingWith(b) << endl;
    cout << "Number of words starting with o: " << trie.countWordsStartingWith(o) << endl;
    cout << "Number of words equal to orange: " << trie.countWordsEqualTo(orange) << endl;

    return 0;
}