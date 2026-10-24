class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0, i = 0, sell = 0, profit = 0;
        int length = prices.size() - 1;

        while(i < length){
            while(i < length && prices[i + 1] <= prices[i]){
                i++;
            }
            buy = prices[i];

            while(i < length && prices[i + 1] > prices[i]){
                i++;
            }
            sell = prices[i];

            profit += sell - buy;
        }
        return profit;
    }
};