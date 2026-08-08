class Solution {
public:
    // // Method 1 using insertion sort
    // void insertionSort(vector<int>& arr) {
    //     for(int i = 0; i < arr.size(); i++) {
    //         int j = i-1;
    //         while(j>=0 && arr[j+1] < arr[j]) {
    //             int temp = arr[j];
    //             arr[j] = arr[j+1];
    //             arr[j+1] = temp;
    //             j--;
    //         }
    //     }
    // }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Method 1 using insertion sort
        // int j=0;
        // for(int i = m; i < m+n; i++) {
        //     nums1[i] = nums2[j];
        //     j++;
        // }
        // insertionSort(nums1);   
        // Method 2 using merge sort logic but from the back 
        // choosing the largest number
        int i = m-1;
        int j = n-1;
        int lastid = m+n-1;
        while(j>=0) {
            if (i>=0 && nums1[i] >= nums2[j]) {
                nums1[lastid] = nums1[i];
                lastid--;
                i--;
            } else {
                nums1[lastid] = nums2[j];
                lastid--;
                j--;
            }
        }
    }
};