class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::vector<int> cnt(2);
        for(const auto student : students) {
            cnt[student]++;
        }
        int top = 0;
        int remaining_sandwiches = sandwiches.size() - top;
        int num_of_students_liking_the_top_sandwich = cnt[sandwiches[top]];
        while(remaining_sandwiches > 0 && num_of_students_liking_the_top_sandwich > 0) {
            cnt[sandwiches[top]]--;
            top++;
            remaining_sandwiches = sandwiches.size() - top;
            num_of_students_liking_the_top_sandwich = cnt[sandwiches[top]];
        }
        return remaining_sandwiches;
    }
};