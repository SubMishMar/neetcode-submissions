class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> dict;
        for(int i = 0; i < nums.size(); ++i){
            dict[nums[i]] = i; // storing indices for each entry, key=number, value = index
        }
        std::vector<int> out;
        for(int i = 0; i < nums.size(); ++i){
            int complement = target - nums[i];
            if(dict.find(complement)!=dict.end() && i!=dict[complement]){
                out.push_back(i);
                out.push_back(dict[complement]);
                break;
            }
        }
        return out;
    }
};
