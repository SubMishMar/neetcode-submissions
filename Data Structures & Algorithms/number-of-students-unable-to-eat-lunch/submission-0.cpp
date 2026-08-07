class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::vector<int> cnt(2);
        for(const auto student : students) {
            cnt[student]++;
        }
        while(sandwiches.size()>0 && cnt[sandwiches[0]]>0) {
            cnt[sandwiches[0]]--;
            sandwiches.erase(sandwiches.begin());
        }
        return sandwiches.size();
    }
};