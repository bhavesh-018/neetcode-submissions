class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int longestLength = 0;
        unordered_map<int, int> hash;

        for(int num: nums){
            hash[num] = false;
        }

        for(int num: nums){
            if(hash[num]) continue;

            hash[num] = true;
            int currentLength = 1;
            int left = num - 1;
            int right = num + 1;

            while(hash.find(left) != hash.end()){
                hash[left] = true;
                currentLength++;
                left--;
            }
            while(hash.find(right) != hash.end()){
                hash[right] = true;
                currentLength++;
                right++;
            }

            if(currentLength > longestLength){
                longestLength = currentLength;
            }
        }
        return longestLength;
    }
};
