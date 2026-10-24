class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, maxLength = 0;
        unordered_map<int, int> lastFoundIndex;

        for(right = 0; right < s.size(); right++){
            char currentChar = s[right];
            if(lastFoundIndex.find(currentChar) != lastFoundIndex.end() && left <= lastFoundIndex[currentChar]){
                left = lastFoundIndex[currentChar] + 1;
            }
            lastFoundIndex[currentChar] = right;
            maxLength = max(maxLength, (right - left) + 1);
        }
        return maxLength;
    }
};
