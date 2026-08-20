class Solution {
public:
    bool isValid(string s) {
        std::map<char, char> dict;
        dict[')'] = '(';
        dict['}'] = '{';
        dict[']'] = '[';
        std::stack<char> stk;
        for(char c : s) {
            if (c=='(' || c=='{' || c=='[') {
                stk.push(c);
            } else {
                if(stk.empty()){
                    return false;
                }
                char top = stk.top();
                if (dict[c] != top) {
                    return false;
                }
                stk.pop();
            }
        }
        if(stk.empty()) {
            return true;
        }
        return false;
    }
};
