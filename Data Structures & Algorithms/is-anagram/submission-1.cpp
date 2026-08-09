class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<int, int> dict_s;
        for(const auto c : s){
            dict_s[c]++;
        }
        std::map<int, int> dict_t;
        for(const auto c : t){
            dict_t[c]++;
        }
        if(dict_t == dict_s) {
            return true;
        }
        return false;
    }
};
