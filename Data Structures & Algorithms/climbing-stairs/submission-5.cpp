class Solution {
public:
    // Method 1
    // int memo[46] = {0};
    int climbStairs(int n) {
        // Method 1
        // if(n<=1) {
        //     return 1;
        // } 
        // if (memo[n]!=0) {
        //     return memo[n]; // precalculated values
        // }
        // memo[n] = climbStairs(n-1)+climbStairs(n-2);
        // return memo[n];
        // Method 2
        // if(n<=1) {
        //     return 1;
        // }
        // int arr[n+1];
        // arr[0] = 1;
        // arr[1] = 1;
        // for(int i = 2; i < n+1; i++) {
        //     arr[i] = arr[i-1]+arr[i-2];
        // }
        // return arr[n];
        // Method 3
        if(n<=1) {
            return 1;
        }
        int a = 1;
        int b = 1;
        int c;
        for(int i = 2; i < n+1; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
