#include <cstring>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int hashmap[26];
        memset(hashmap, 0, sizeof(hashmap));
        for(const char& c: s){
            hashmap[c-'a']++;
        }
        for(const char& c: t){
            hashmap[c-'a']--;
        }
        for(auto it: hashmap){
            if(it != 0) return false;
        }
        return true;
    }
};
