/*
   Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:

Each element in the result must be unique.
The result can be in any order.
*/

class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            map<int, bool> m;
            set<int> s;
            for (auto& v: nums1){
                m[v] = true;
            }
            for (auto& v: nums2){
                if (m.find(v) != m.end()){
                    s.insert(v);
                }
            }
            //create a new vector and copy stuff from the set over;
            return vector<int> ( s.begin(), s.end() );
        }
};
