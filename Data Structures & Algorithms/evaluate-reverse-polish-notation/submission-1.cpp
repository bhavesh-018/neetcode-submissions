class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                s.push(stoi(tokens[i]));
            } else {
                int operand2 = s.top(); s.pop();
                int operand1 = s.top(); s.pop();

                if (tokens[i] == "+") s.push(operand1 + operand2);
                else if (tokens[i] == "-") s.push(operand1 - operand2);
                else if (tokens[i] == "*") s.push(operand1 * operand2);
                else if (tokens[i] == "/") s.push(operand1 / operand2);
            }
        }

        return s.top();
    }
};
