class Solution {
public:
    int trap(vector<int>& height) {
    /* BruteForce
        if(height.empty()){
            return 0;
        }
        int n = height.size();
        int res = 0;

        for(int i=0; i<n; i++){
            int leftMax = height[i];
            int rightMax = height[i];

            for(int j=0; j<i; j++){
                leftMax = max(leftMax, height[j]);
            }

            for(int j = i + 1; j<n; j++){
                rightMax = max(rightMax, height[j]);
            }

            res += min(leftMax, rightMax) - height[i];
        }
        return res;
    */

    /* Better Approach
        int n = height.size();
        int res = 0;
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);
        
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];

        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        for(int i=0; i<n; i++){
            res += min(leftMax[i], rightMax[i]) - height[i]; 
        }

        return res;
    */
    // Optimal
        int left = 0, right = height.size() - 1;
        int sum = 0, leftMax = 0, rightMax = 0;
        
        while(left < right){
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            if(leftMax < rightMax){
                sum += leftMax - height[left];
                left++;
            }else{
                sum += rightMax - height[right];
                right--;
            }
        }
        return sum;
    }
};
