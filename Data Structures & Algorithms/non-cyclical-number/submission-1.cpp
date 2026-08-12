class Solution {
public:
    int sumOfSquaresOfDigit(int n){
        int sum = 0;
        while(n>0){
            int digit = n%10;
            sum += digit*digit;
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        std::unordered_set<int> visit;
        while(visit.find(n)==visit.end()){
            visit.insert(n);
            n = sumOfSquaresOfDigit(n);
            if(n==1){
                return true;
            }
        }
        return false;
    }
};
