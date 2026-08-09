class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> dict;
        for(int i = 0; i < nums.size(); i++) {
            dict[nums[i]] = i;
        }
        std::vector<int> ids;
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(dict.find(complement)!=dict.end() && 
               i != dict[complement] && 
               i < dict[complement]) {
                ids.push_back(i);
                ids.push_back(dict[complement]);
                break;
            }
        }
        return ids;
    }
};
