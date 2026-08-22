class Solution {
public:
    bool isAnagram(string s, string t) {
        // if(s.size()!=t.size()){
        //     return false;
        // }
        // std::unordered_map<char, int> dict_s;
        // std::unordered_map<char, int> dict_t;
        // for(int i = 0; i < s.size(); i++){
        //     dict_s[s[i]]++;
        //     dict_t[t[i]]++;
        // }
        // if(dict_s==dict_t){
        //     return true;
        // }
        // return false;
        if(s.size()!=t.size()){
            return false;
        }
        std::array<int, 26> char_counts{};
        for(int i = 0; i < s.size(); ++i){
            char_counts[s[i]-'a']++;
            char_counts[t[i]-'a']--;
        }
        for(int i = 0; i < 26; ++i){
            if(char_counts[i] != 0){
                return false;
            }
        }
        return true;
    }
};
