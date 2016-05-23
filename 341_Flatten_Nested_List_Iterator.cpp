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
            stk_.push(nestedList.begin());
            stk_end_.push(nestedList.end());
            expand();
        }
        //get the top pointer, and expand if needed
        void expand(){
            //Ni curIt = stk_.top();
            cout << "stk_.size()" << stk_.size() << endl << " stk_end_.size()" << stk_end_.size() << (stk_.top() == stk_end_.top()) << endl; 
            //if hits end
            while (!stk_.empty() && stk_.top() == stk_end_.top()){
                stk_.pop();
                stk_end_.pop();
                if (!stk_.empty()){
                    stk_.top() ++;
                }
            }
            if (stk_.empty()){
                return;
            }
            //if it is not hitting end;
            //if integer no need to expand
            if ((*stk_.top()).isInteger()){
                return;
            }
            //if element is nested;
            while (!(*stk_.top()).isInteger()){
                Ni newIterator = (*stk_.top()).getList().begin();
                Ni newEndIterator = (*stk_.top()).getList().end();
                stk_.push(newIterator);
                stk_end_.push(newEndIterator);
                while (!stk_.empty() && stk_.top() == stk_end_.top()){
                    stk_.pop();
                    stk_end_.pop();
                    if (!stk_.empty()){
                        stk_.top() ++;
                    }
                }
                if (stk_.empty()){
                    return;
                }
                //if it is not hitting end;
                //if integer no need to expand
                if ((*stk_.top()).isInteger()){
                    return;
                }
            }
        }

        int next() {
            int result;
            //move the most current one to next;
            Ni& lastI = stk_.top();
            result = (*lastI).getInteger();
            lastI ++;

            expand();
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
