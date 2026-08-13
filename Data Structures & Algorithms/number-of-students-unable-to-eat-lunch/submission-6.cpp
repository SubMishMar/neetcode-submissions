class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::vector<int> count(2);
        for(const auto student:students){
            count[student]++;
        }
        int top = 0;
        int num_of_sandwiches_remaining = sandwiches.size()-top;
        int num_of_students_who_like_the_top_sandwich = count[sandwiches[top]];
        while(num_of_sandwiches_remaining > 0 && num_of_students_who_like_the_top_sandwich > 0){
            count[sandwiches[top]]--;
            top++;
            num_of_sandwiches_remaining = sandwiches.size()-top;
            num_of_students_who_like_the_top_sandwich = count[sandwiches[top]];
        }
        return num_of_sandwiches_remaining;
    }
};
