class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        //Method 1 Brute Force
        // size_t n = arr.size();
        // for(int i = 0; i < n; ++i) {
        //     int max_element = -100000;
        //     for (int j = i+1; j < n; ++j) {
        //         max_element = std::max(max_element, arr[j]);
        //     }
        //     arr[i] = max_element;
        // }
        // arr[n-1] = -1;
        // return arr;
        //Method 2 
        size_t n = arr.size();
        vector<int> arr2(n);
        int max_element = -100000;
        for (int i = n-2; i >= 0; --i) {
            max_element = std::max(max_element, arr[i+1]);
            arr2[i] = max_element;
        }
        arr2[n-1] = -1;
        return arr2;
    }
};