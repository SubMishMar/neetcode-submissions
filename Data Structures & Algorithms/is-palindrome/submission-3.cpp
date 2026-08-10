class Solution {
public:
    bool isPalindrome(string s) {
        std::string str;
        for (char c : s) {
            str += std::tolower(static_cast<unsigned char>(c));
        }
        int i = 0;
        int j = str.length()-1;
        while(i<j) {
            if(!std::isalnum(str[i])){
                i++;
                continue;
            }
            if(!std::isalnum(str[j])){
                j--;
                continue;
            }
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
