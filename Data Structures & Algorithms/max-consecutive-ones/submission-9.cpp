class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max_count = -100000;
        for(const auto num : nums){
            if(num == 1){
                count++;
            }else{
                count=0;
            }
            max_count = max(max_count, count);
        }
        return max_count;
    }
};