class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // Method 1
        // std::map<int, int> dict;
        // for (const auto num : nums) {
        //     dict[num]++;
        // }

        // bool hasduplicate = false;
        // for (const auto& [key, value] : dict) {
        //     if (value > 1) {
        //         hasduplicate = true;
        //         break; 
        //     }
        // }

        // return hasduplicate;

        // Method 2
        // bool has_duplicate = false;
        // std::unordered_set<int> seen;
        // for (const auto num : nums) {
        //     if(seen.count(num)) {
        //         has_duplicate = true;
        //         break;
        //     }
        //     seen.insert(num);
        // }
        // return has_duplicate;
        std::set<int> st;
        for(const auto num : nums){
            if(st.count(num)){
                return true;
            }
            st.insert(num);
        }
        return false;
    }
};