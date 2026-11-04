class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result;
        std::unordered_map<int, int> dict;
        for(int i = 0; i < nums.size(); i++){
            dict[nums[i]]=i;
        }
        for(int i = 0; i < nums.size(); i++){
            int complement = target-nums[i];
            if(dict.find(complement)!=dict.end() 
            && i!=dict[complement]){
                result.push_back(i);
                result.push_back(dict[complement]);
                break;
            }
        }
        return result;
    }
};
