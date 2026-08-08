class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::map<int, int> dict;
        for (const auto num : nums) {
            dict[num]++;
        }

        bool hasduplicate = false;
        for (const auto& [key, value] : dict) {
            if (value > 1) {
                hasduplicate = true;
                break; 
            }
        }

        return hasduplicate;
    }
};