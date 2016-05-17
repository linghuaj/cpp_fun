/*
 * Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

 For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: you may assume that n is not less than 2. 
*/

//dynamic programming;
//assumption is for f[i] stores the max product for i. 
class Solution {
    public:
        int integerBreak(int n) {
            //initialize mem for cache;
            vector<int> f(n+1);
            f[1] = 1;
            int tmp;
            for (int i = 2; i <= n; i++){
                //for each combination, calculate and find max;
                for (int j = 1; j <= i/2; j++){
                    //ie: 3 = 1*2 is max, not f[1]* f[2];
                    tmp = max(j, f[j])*max(i-j, f[i-j]);
                    f[i] = max(f[i], tmp);
                }
            }
            return f[n];
        }
};
