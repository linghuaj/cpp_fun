/*
   Given a nested list of integers, implement an iterator to flatten it.

   Each element is either an integer, or a list -- whose elements may also be integers or other lists.

   Example 1:
   Given the list [[1,1],2,[1,1]],

   By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

   Example 2:
   Given the list [1,[4,[6]]],

   By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6]. 
   */


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
typedef vector<NestedInteger>::iterator Ni;
typedef vector<NestedInteger> NList;

class NestedIterator {
    public:
        NestedIterator(vector<NestedInteger> &nestedList) {
            expand(nestedList);
            cout <<'n';
        }

        void expand(NList &nestedList){
            Ni f = nestedList.begin();
            Ni e = nestedList.end();
            if (f == e){
                return;
            }

            while (true){
                stk_.push(f);
                stk_end_.push(e);

                NestedInteger& fn = *(f);
                if (fn.isInteger() == true){
                    break;
                }
                NList& list = fn.getList();
                f = list.begin();
                e = list.end();
                if (f == e){
                    break;
                }
            }
        }

        int next() {
            int result;
            //move the most current one to next;
            Ni& lastI = stk_.top();
            result = (*lastI).getInteger();
            //stack stores all the iterator
            while (stk_.top() + 1 == stk_end_.top()){
                stk_.pop();
                stk_end_.pop();
            }
            cout <<'n2';
            stk_.top() ++;
            Ni& newLastI = stk_.top();
            cout <<'n3';
            // Ni& lastI = stk_.top();
            if ((*newLastI).isInteger() == true){
                stk_.push(newLastI);
            }else{
                expand((*newLastI).getList());
            }
            return result;
        }

        bool hasNext() {
            return !stk_.empty();
        }

    private:
        //index, size;
        stack<Ni> stk_;
        stack<Ni> stk_end_;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
