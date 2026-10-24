class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /* bruteforce
        int left = 0, right = 1;
        vector<int> result(temperatures.size(),0);
        for(int i=0; i<temperatures.size(); i++){
            for(int j=i+1; j<temperatures.size(); j++){
                if(temperatures[i] < temperatures[j]){
                    result[i] = j - i;
                    break;
                }
            }
        }
        return result;
        */
        // Optimized Solution
        vector<int> result(temperatures.size(),0);
        stack<int> st;

        for(int i=0; i<temperatures.size(); i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int idx = st.top();
                st.pop();
                result[idx] = i - idx;
            }
            st.push(i);
        }
        return result;
    }
};
