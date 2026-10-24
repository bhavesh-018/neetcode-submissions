class MinStack {
public:
    vector<long long> stack;
    long long minElement;
    MinStack() {
        minElement = LLONG_MAX;
    }
    
    void push(int val) {
        if(stack.empty()){
            stack.push_back(val);
            minElement = val;
        }else if(val < minElement){
            stack.push_back(2LL * val - minElement);
            minElement = val;
        }else{
            stack.push_back(val);
        }
    }
    
    void pop() {
        if(stack.empty()) return;
        long long topValue = stack.back();
        stack.pop_back();
        if(topValue < minElement){
            minElement = 2LL * minElement - topValue;
        }
        if(stack.empty()) minElement = LLONG_MAX;
    }
    
    int top() {
        long long topValue = stack.back();
        if(topValue < minElement){
            return (int)minElement;
        }else{
            return (int)topValue;
        }
    }
    
    int getMin() {
        return (int)minElement;
    }
};
