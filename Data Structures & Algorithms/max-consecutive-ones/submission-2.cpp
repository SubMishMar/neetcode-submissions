class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            int j = i;
            while (j < n && nums[j]==1) {
                j++;
                cnt++;
            }
            res = std::max(res, cnt);
        }
        return res;
    }
};