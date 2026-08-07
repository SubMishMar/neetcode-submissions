class Solution {
public:
    void sort(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            int j = i-1;
            while(j>=0 && arr[j+1] < arr[j]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                j--;
            }
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=0;
        for(int i = m; i < m+n; i++) {
            nums1[i] = nums2[j];
            j++;
        }
        sort(nums1);   
    }
};