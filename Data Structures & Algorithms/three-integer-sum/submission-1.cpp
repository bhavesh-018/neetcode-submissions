class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       int n = nums.size();
       vector<vector<int>> res;

       sort(nums.begin(), nums.end());

       for(int i=0; i<n-2; i++){
            int left = i + 1;
            int right = n - 1;

            if(i > 0 && nums[i] == nums[i - 1]) continue;

            while(left < right){
                int total = nums[i] + nums[left] + nums[right];
                if(total == 0){
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});

                    // for duplicates
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if(total < 0){
                    left++;
                }else{
                    right--;
                }
            }
       }
       return res;
    }
};
