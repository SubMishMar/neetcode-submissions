class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::vector<int> cnt(2);
        for(const auto student : students) {
            cnt[student]++;
        }
        int top = 0;
        while(sandwiches.size() - top> 0 && cnt[sandwiches[top]]>0) {
            cnt[sandwiches[top]]--;
            top++;
        }
        return sandwiches.size() - top;
    }
};