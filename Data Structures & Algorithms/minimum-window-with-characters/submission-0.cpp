class Solution {
public:
    void increaseCharCounts(char c, unordered_map<char, int>& charCounts){
        charCounts[c]++;
    }
    unordered_map<char, int> getCharCounts(string s){
        unordered_map<char, int> charCounts;
        for(char c: s){
            increaseCharCounts(c, charCounts);
        }
        return charCounts;
    }
    vector<int> getSmallerBounds(int i1, int i2, int j1, int j2){
        return (long long)i2 - i1 < (long long)j2 - j1 ? vector<int>{i1,i2} : vector<int>{j1,j2};
    }
    vector<int> getSubstringBounds(string s, unordered_map<char, int> targetCounts){
        unordered_map<char, int> windowCounts;
        vector<int> bounds = {0, INT_MAX};
        int required = targetCounts.size();
        int formed = 0;
        int left = 0, right = 0;

        while(right < s.size()){
            char c = s[right];
            if(targetCounts.count(c)){
                increaseCharCounts(c, windowCounts);
                if(windowCounts[c] == targetCounts[c]) formed++;
            }
            while(formed == required && left <= right){
                bounds = getSmallerBounds(left, right, bounds[0], bounds[1]);
                char lChar = s[left];

                if(targetCounts.count(lChar)){
                    if(windowCounts[lChar] == targetCounts[lChar])
                        formed--;
                    windowCounts[lChar]--;
                }
                left++;
            }
            right++;
        }
        return bounds;
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> targetCharCounts = getCharCounts(t);
        vector<int> bounds = getSubstringBounds(s, targetCharCounts);

        int start = bounds[0];
        int end = bounds[1];
        if(end == INT_MAX) return "";
        return s.substr(start, end - start + 1);
    }
};