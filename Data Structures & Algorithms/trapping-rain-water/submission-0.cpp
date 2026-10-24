class Solution {
public:
    int trap(vector<int>& height) {
        /* Better approach
        int n = height.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];
        int ans = 0;

        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        for(int i=0; i<n; i++){
            ans += (min(leftMax[i], rightMax[i]) - height[i]);
        }
        return ans;
        */

        // Optimal
        int left = 0, right = height.size()-1;
        int leftMax = 0, rightMax = 0, sum = 0;

        while(left <= right){
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            if(height[left] < height[right]){
                sum += (leftMax - height[left]);
                left++;
            }else{
                sum += (rightMax - height[right]);
                right--;
            }
        }
        return sum;
    }
};
