// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    void merge(vector<Pair>& arr, int s, int m, int e) {
        // iterator end is not inclusive, need to add 1
        std::vector<Pair> arr1 = {arr.begin() + s, arr.begin() + m + 1};
        std::vector<Pair> arr2 = {arr.begin() + m + 1, arr.begin() + e + 1};
        int i = 0;
        int size1 = m-s+1;
        int j = 0;
        int size2 = e-m;
        int k = s;
        while(i < size1 && j < size2) {
            // <= is necessary to ensure stable sorting.
            if (arr1[i].key <= arr2[j].key) {
                arr[k] = arr1[i];
                i++;
            } else {
                arr[k] = arr2[j];
                j++;
            }
            k++;
        }
        // i == size1 then arr1 ran out, arr2 remains
        // fill contents of arr2 int arr
        // j == size2 then arr2 ran out, arr1 remains
        // fill contents of arr1 int arr
        if(i==size1) {
            int remaining_j = j;
            for(int l = k; l <= e; l++) {
                arr[l] = arr2[remaining_j];
                remaining_j++;
            }
        } 
        if(j==size2) {
            int remaining_i = i;
            for(int l = k; l <= e; l++) {
                arr[l] = arr1[remaining_i];
                remaining_i++;
            }
        }
    }

    vector<Pair> performMergeSort(vector<Pair>& arr, int s, int e){
        int size = e-s+1;
        if(size<=1) {
            return arr;
        }
        int m = (s+e)/2;
        
        performMergeSort(arr, s, m);
        performMergeSort(arr, m+1, e);

        merge(arr, s, m, e);

        return arr;
    }

    vector<Pair> mergeSort(vector<Pair>& pairs) {
        if(pairs.size()==0) {
            return pairs;
        }
        return performMergeSort(pairs, 0, pairs.size()-1);
    }
};
