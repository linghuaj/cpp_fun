/*
   Write a function that takes a string as input and reverse only the vowels of a string.

   Example 1:
   Given s = "hello", return "holle".

   Example 2:
   Given s = "leetcode", return "leotcede". 
   */

class Solution {
    public:
        string reverseVowels(string s) {
            string::iterator i = s.begin();
            string::iterator j = s.end() - 1;
            map<char, bool> m;
            m['a'] = true;
            m['e'] = true;
            m['i'] = true;
            m['o'] = true;
            m['u'] = true;

            //TODO: probably int interate string;
            while (i != j+1 && i!= j){
                if (m.find(tolower(*i)) == m.end()){
                    i++;
                    continue;
                }
                if (m.find(tolower(*j)) == m.end()){
                    j--;
                    continue;
                }

                //swap
                char tmp;
                tmp = *i;
                *i = *j;
                *j = tmp;
                i++;
                j--;
            }

            return s;
        }
};
