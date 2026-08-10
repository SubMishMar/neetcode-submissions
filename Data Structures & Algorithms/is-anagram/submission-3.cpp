class Solution {
public:
    bool isAnagram(string s, string t) {
        // std::map<int, int> dict_s;
        // for(const auto c : s){
        //     dict_s[c]++;
        // }
        // std::map<int, int> dict_t;
        // for(const auto c : t){
        //     dict_t[c]++;
        // }
        // if(dict_t == dict_s) {
        //     return true;
        // }
        // return false;
        if(s.size()!=t.size()){
            return false;
        }
        std::array<int, 26> arr{};
        for(int i = 0; i < s.size(); ++i){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        for(int i = 0; i < arr.size(); ++i){
            if(arr[i]!=0){
                return false;
            }
        }
        return true;
    }
};
