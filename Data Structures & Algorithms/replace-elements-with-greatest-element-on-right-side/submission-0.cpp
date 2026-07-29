class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        size_t n = arr.size();
        for(int i = 0; i < n; ++i) {
            int max_element = -100000;
            for (int j = i+1; j < n; ++j) {
                max_element = std::max(max_element, arr[j]);
            }
            arr[i] = max_element;
        }
        arr[n-1] = -1;
        return arr;
    }
};