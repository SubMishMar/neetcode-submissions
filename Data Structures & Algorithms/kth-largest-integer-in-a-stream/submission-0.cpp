class KthLargest {
public:
    std::priority_queue<int> pq;
    int k_;
    KthLargest(int k, vector<int>& nums) {
        pq = {nums.begin(), nums.end()};
        k_ = k;
    }
    
    int add(int val) {
        pq.push(val);
        // assuming k starts from 1;
        std::vector<int> temp;
        for(int i = 0; i < k_; i++){
            int top = pq.top();
            temp.push_back(top);
            pq.pop();
        }
        for(const auto num : temp){
            pq.push(num);
        }
        return temp[temp.size()-1];
    }
};
