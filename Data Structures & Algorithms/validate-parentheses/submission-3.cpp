class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0) {
            return true;
        }
        std::vector<char> stk;
        std::unordered_map<char, char> dict;
        dict['}'] = '{';
        dict[')'] = '(';
        dict[']'] = '[';
        for(char c : s) {
            if(c=='{'||c=='['||c=='(') {
                stk.push_back(c);
            } else {
                // has to be a closing bracket.
                if(stk.size()==0){
                    return false;
                }
                char top = stk.back();
                if(top==dict[c]) {
                    stk.pop_back();
                } else {
                    return false;
                }
            }
        }
        if(stk.size()==0) {
            return true;
        }
        return false;
    }
};
