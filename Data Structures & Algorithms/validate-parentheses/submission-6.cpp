class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> dict;
        dict[')'] = '(';
        dict['}'] = '{';
        dict[']'] = '[';
        std::stack<char> stk;
        for(char c : s){
            if(c=='(' || c=='[' || c =='{'){
                // if char is opening bracket then push it to stack
                stk.push(c);
            } else {
                // if stack is empty then no opening brackets have been 
                // inserted yet
                if(stk.size()==0){
                    // if stack is empty then no opening brackets have been 
                    // inserted yet but c eithe has opening or closing brackets
                    // if no opening brackets yet then it's an unbalanced closing bracket
                    return false;
                }
                char top = stk.top();
                if(top!=dict[c]){
                    return false;
                }
                stk.pop();
            }
        }
        if(stk.size()==0){
            return true;
        }
        return false;
    }
};
