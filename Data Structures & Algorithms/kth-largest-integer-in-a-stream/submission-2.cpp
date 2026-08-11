class KthLargest {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;    
    int k_;
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for(const auto num : nums){
            min_pq.push(num);
            if(min_pq.size()>k){
                min_pq.pop();
            }
        }
    }
    
    int add(int val) {
        // pq.push(val);
        // // assuming k starts from 1;
        // std::vector<int> temp;
        // for(int i = 0; i < k_; i++){
        //     int top = pq.top();
        //     temp.push_back(top);
        //     pq.pop();
        // }
        // for(const auto num : temp){
        //     pq.push(num);
        // }
        // return temp[temp.size()-1];
        min_pq.push(val);
        if(min_pq.size() > k_){
            min_pq.pop();
        }
        return min_pq.top();
    }
};
