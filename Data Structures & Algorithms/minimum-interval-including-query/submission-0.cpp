class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();
        vector<int> result(n, -1);
        
        vector<pair<int, int>> sortedQueries;
        for(int i=0; i<n; i++) sortedQueries.push_back({queries[i], i});

        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a[0] < b[0];
        });

        sort(sortedQueries.begin(), sortedQueries.end());

        priority_queue<pair<int, int>, 
                       vector<pair<int, int>>, 
                       greater<pair<int, int>>> minHeap;

        int intervalIndex = 0;

        for(auto& q: sortedQueries){
            int query = q.first;
            int queryIndex = q.second;

            while(intervalIndex < intervals.size() && intervals[intervalIndex][0] <= query){
                int left = intervals[intervalIndex][0];
                int right = intervals[intervalIndex][1];

                if(right >= query){
                    int length = right - left + 1;
                    minHeap.push({length, right});
                }
                intervalIndex++;
            }

            while(!minHeap.empty() && minHeap.top().second < query){
                minHeap.pop();
            }

            if(!minHeap.empty()){
                result[queryIndex] = minHeap.top().first;
            }
        }
        return result;
    }
};
