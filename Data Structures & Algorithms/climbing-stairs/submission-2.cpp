class Solution {
public:
    // Method 1
    int memo[46] = {0};
    int climbStairs(int n) {
        // Method 1
        if(n<=1) {
            return 1;
        } 
        if (memo[n]!=0) {
            return memo[n]; // precalculated values
        }
        memo[n] = climbStairs(n-1)+climbStairs(n-2);
        return memo[n];
    }
};
