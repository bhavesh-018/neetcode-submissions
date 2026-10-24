class Solution {
public:
    int maxArea(vector<int>& heights) {
        /* Brute Force
        int n = heights.size();
        int maxArea = 0, currArea = 0, width = 0, ht = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                width = j - i;
                ht = min(heights[i], heights[j]);
                currArea = width * ht;
                maxArea = max(maxArea, currArea); 
            }
        }
        return maxArea;
        */

        // Optimal
        int n = heights.size();
        int left = 0, right = n - 1, maxArea = 0, currArea = 0, width = 0, height = 0;

        while(left < right){
            width = right - left;
            height = min(heights[left], heights[right]);
            currArea = width * height;
            maxArea = max(maxArea, currArea);

            heights[left] > heights[right] ? right-- : left++;
        }
        return maxArea;
    }
};
