/*
 *  Given a non-empty array of integers, return the k most frequent elements.
 *
 *  For example,
 *  Given [1,1,1,2,2,3] and k = 2, return [1,2].
 *
 *  Note:
 *
 *  - You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 *  - Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */ 

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            //loop through nums, do the count to hash table, key by number
            map<int, int> numHash;
            map<int, vector<int> > countHash;
            vector<int> result;
            for (auto& v:nums){
                numHash[v]++;
            }

            //loop through hash table, build second hash, key by count
            for (auto& pair : numHash){
                int count = pair.second;
                int num = pair.first;
                countHash[count].push_back(num);
            }

            //reverse iterator
            map<int, vector<int> >::reverse_iterator it = countHash.rbegin();
            int count = 0;

            while (count < k){
                //without & it uses vector as copy of another vector, which use extra time and space. 
                vector<int>& arr = (*it).second;
                for (auto &v: arr){
                    result.push_back(v);
                    count ++;
                    if (count == k) {
                        break;
                    }
                }
                it ++;
            }
            return result;
        }
};
