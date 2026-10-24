class Solution {
public:
    int characterReplacement(string s, int k) {
        int charFrequency[26] = {0};
        int left = 0, maxFrequency = 0, stringLength = s.length();

        for(int right = 0; right < s.size(); right++){
            charFrequency[s[right] - 'A']++;
            maxFrequency = max(maxFrequency, charFrequency[s[right] - 'A']);
            if((right - left + 1) - maxFrequency > k) {
                charFrequency[s[left] - 'A']--;
                left++;
            }
        }
        return stringLength - left;
    }
};
