#include <cstring>
class TrieNode{
public:
    bool isCompleted = false;
    TrieNode* children[26];
    
    TrieNode(){
        isCompleted = false; // when the word is completed, mark this as true
        memset(children, 0, sizeof(children)); // for 26 possible childrens (for next letter)
    }
};
class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char ch: word){
            int index = ch - 'a';
            if(node->children[index] == NULL) node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isCompleted = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char ch: word){
            int index = ch - 'a';
            if(node->children[index] == NULL) return false;
            node = node->children[index];
        }
        return node->isCompleted;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char ch: prefix){
            int index = ch - 'a';
            if(node->children[index] == NULL) return false;
            node = node->children[index];
        }
        return true;
    }
};
