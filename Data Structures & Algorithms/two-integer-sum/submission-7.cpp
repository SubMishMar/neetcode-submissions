class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); i++) {
            dict[nums[i]] = i;
        }
        std::vector<int> out(2);
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(dict.find(complement)!=dict.end() && i<dict[complement]){
                out[0] = i;
                out[1] = dict[complement];
            }
        }
        return out;
    }
};
