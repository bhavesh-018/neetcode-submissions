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
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
       root = new TrieNode(); 
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char ch: word){
            int index = ch - 'a';
            if(node->children[index] == NULL) node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isCompleted = true;
    }
    bool searchHelper(string word, TrieNode* node){
        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            if(ch == '.'){
                for(auto c: node->children)
                    if(c && searchHelper(word.substr(i+1), c)) return true;
                return false;
            }
            int index = ch - 'a';
            if(node->children[index] == NULL) return false;
            node = node->children[index];
        }
        return node->isCompleted;
    }
    bool search(string word) {
        return searchHelper(word, root);
    }
};
