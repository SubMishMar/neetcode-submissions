class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // Method 1
        // int res = 0;
        // int n = nums.size();
        // for (int i = 0; i < n; i++) {
        //     int cnt = 0;
        //     int j = i;
        //     while (j < n && nums[j]==1) {
        //         j++;
        //         cnt++;
        //     }
        //     res = std::max(res, cnt);
        // }
        // return res;
        // Method 2
        int count = 0;
        int res = -10000;
        for (const auto num : nums) {
            if(num == 1) {
                count++;
            } else {
                count = 0;
            }
            res = std::max(res, count);
        }
        return res;
    }
};