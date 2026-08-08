class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> dict;
        std::vector<int> output;
        for (int i = 0 ; i < nums.size(); i++) {
            int difference = target - nums[i];
            if(dict.find(difference)!=dict.end()) {
                output.push_back(dict[difference]);
                output.push_back(i);
                break;
            }
            dict[nums[i]] = i;
        }
        return output;
    }
};
