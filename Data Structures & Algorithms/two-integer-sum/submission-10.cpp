class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> dict;
        for(int i = 0; i < nums.size(); i++){
            dict[nums[i]] = i;
        }
        std::vector<int> out;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(dict.find(complement)!=dict.end() && dict[complement] != i){
                out.push_back(i);
                out.push_back(dict[complement]);
                return out;
            }
        }
        return {};
    }
};
