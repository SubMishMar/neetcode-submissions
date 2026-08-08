class Solution {
public:
    void sortColors(vector<int>& nums) {
        // using bucket sort 
        // question mentions in-place but if the counting array size
        // is predermined then it is considered in-place.
        std::vector<int> colors(3);
        for(int i = 0; i < nums.size(); i++) {
            colors[nums[i]]++;
        }
        int k = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < colors[i]; j++) {
                nums[k] = i;
                k++;
            }
        }
    }
};