class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> max_pq;
        for(const auto stone : stones){
            max_pq.push(stone);
        }
        while(max_pq.size()>1){
            int x = max_pq.top();
            max_pq.pop();
            int y = max_pq.top();
            max_pq.pop();
            if(y!=x){
                max_pq.push(x-y);
            }
        }
        if(max_pq.size()==1){
            return max_pq.top();
        }
        return 0;
    }
};
