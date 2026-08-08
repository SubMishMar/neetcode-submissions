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
    int partition(vector<Pair>& pairs, int low, int high) {
        Pair pivot = pairs[high];
        int i = low-1;
        for(int j = low; j < high; j++) {
            if(pairs[j].key < pivot.key) {
                i++;
                Pair temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
            } 
        }
        Pair temp = pairs[i+1];
        pairs[i+1] = pairs[high];
        pairs[high] = temp;
        return i+1;
    }

    vector<Pair> implementQuickSort(vector<Pair>& pairs, int low, int high) {
        if (pairs.size()==0) {
            return pairs;
        }
        if (high-low+1<=1) {
            return pairs;
        }

        int p = partition(pairs, low, high);

        implementQuickSort(pairs, low, p-1); // p-1 because element at index p is already sorted
        implementQuickSort(pairs, p+1, high);

        return pairs;
    }

    vector<Pair> quickSort(vector<Pair>& pairs) {
        return implementQuickSort(pairs, 0, pairs.size()-1);
    }
};
