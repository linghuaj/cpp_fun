/*

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion? 
*/

//power of 4 means there are even 0 after 1 in bits;
class Solution {
    public:
        bool isPowerOfFour(int num) {
            //(num-1) & num) : make sure there is only one 1 and all rest are 0. 
            //4 % 3 = 1 and 4^2  = 4* (3+1) so mod is 1;
            return ((num-1) & num) == 0 && num % 3 == 1;

        }
};
