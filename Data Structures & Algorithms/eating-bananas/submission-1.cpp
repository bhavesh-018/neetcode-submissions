class Solution {
public:
    bool feasible(vector<int>& piles, int hours, int limit){
        long long hoursTaken = 0;
        for(int pile: piles){
            hoursTaken += (pile / limit);
            if(pile % limit != 0) hoursTaken++;
        }
        return hoursTaken <= hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *std::max_element(piles.begin(), piles.end()), minBananas = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(feasible(piles, h, mid)){
                minBananas = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return minBananas;
    }
};
