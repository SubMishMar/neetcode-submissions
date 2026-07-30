class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // Method 1
        // size_t n = nums.size();
        // vector<int> ans(2*n);
        // for(int i = 0; i < n; ++i) {
        //     ans[i] = nums[i];
        //     ans[i+n] = nums[i];
        // }
        // return ans;
        // Method 2
        // vector<int> ans;
        // for(int i = 0; i < 2; ++i) {
        //     for(const auto num : nums) {
        //         ans.push_back(num);
        //     }
        // }
        // return ans;
        //Method 3
        vector<int> ans;
        ans.insert(ans.end(), nums.begin(), nums.end());
        ans.insert(ans.end(), nums.begin(), nums.end());
        return ans;
    }
};