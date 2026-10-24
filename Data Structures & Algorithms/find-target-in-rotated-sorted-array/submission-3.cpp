class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, boundaryIndex = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[low] <= nums[mid]){
                if(target >= nums[low] && target < nums[mid])
                    high = mid - 1; // target in left half
                else
                    low = mid + 1; // target in righ half
            }else{ 
                if(target > nums[mid] && target <= nums[high])
                    low = mid + 1; // target in right half
                else
                    high = mid - 1; // target in low half
            }
        }
        return -1;
    }
};
