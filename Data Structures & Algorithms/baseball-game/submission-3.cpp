class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::vector<int> record;
        for(int i = 0; i < operations.size(); i++){
            string operation = operations[i];
            int record_size = record.size();
            if(operation == "+"){
                record.push_back(record[record_size-1]+record[record_size-2]);
            } else if (operation == "D") {
                record.push_back(2*record[record_size-1]);
            } else if (operation == "C") {
                record.pop_back();
            } else {
                record.push_back(std::stoi(operation));
            }
        }
        int sum = 0;
        for(int i = 0; i < record.size(); i++){
            sum += record[i];
        }
        return sum;
    }
};