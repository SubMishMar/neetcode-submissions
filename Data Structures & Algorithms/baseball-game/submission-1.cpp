class Solution {
public:
    int calPoints(vector<string>& operations) {
        // Method 1
        // std::vector<int> record;
        // for(int i = 0 ; i < operations.size(); ++i) {
        //     size_t record_size = record.size();
        //     if (operations[i] == "+") {
        //         record.push_back(record[record_size-1]+record[record_size-2]);
        //     } else if (operations[i] == "C") {
        //         record.pop_back();
        //     } else if (operations[i] == "D") {
        //         record.push_back(2*record[record_size-1]);
        //     } else {
        //         record.push_back(std::stoi(operations[i]));
        //     }
        // }
        // int sum = 0;
        // for(int i = 0; i < record.size(); i++){
        //     sum += record[i];
        // }
        // return sum;
        // Method 2
        int sum = 0;
        std::vector<int> record;
        for(int i = 0 ; i < operations.size(); ++i) {
            size_t record_size = record.size();
            if (operations[i] == "+") {
                record.push_back(record[record_size-1]+record[record_size-2]);
                sum += record.back();
            } else if (operations[i] == "C") {
                sum -= record.back();
                record.pop_back();
            } else if (operations[i] == "D") {
                record.push_back(2*record[record_size-1]);
                sum += record.back();
            } else {
                record.push_back(std::stoi(operations[i]));
                sum += record.back();
            }
        }
        return sum;
    }
};