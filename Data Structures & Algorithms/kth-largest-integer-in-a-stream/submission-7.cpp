class KthLargest {
public:
    int k_;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for(const auto num : nums){
            minHeap.push(num);
            if(minHeap.size()>k_){
                minHeap.pop();
            }
        }    
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>k_){
            minHeap.pop();
        }
        return minHeap.top();
    }
};
