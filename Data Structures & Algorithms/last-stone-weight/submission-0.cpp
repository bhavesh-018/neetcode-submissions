class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> maxHeap;
        for(int i=0; i<stones.size(); i++){
            maxHeap.push(stones[i]);
        }

        while(maxHeap.size() >= 2){
            int stone2 = maxHeap.top();
            maxHeap.pop();
            int stone1 = maxHeap.top();
            maxHeap.pop();

            if(stone1 == stone2){
                continue;
            }
            else if(stone1 != stone2){
                maxHeap.push(stone2 - stone1);
            }
        }
        return maxHeap.size() == 1 ? maxHeap.top() : 0;  
    }
};
