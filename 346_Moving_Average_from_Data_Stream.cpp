/*
   Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

   For example,

   MovingAverage m = new MovingAverage(3);
   m.next(1) = 1
   m.next(10) = (1 + 10) / 2
   m.next(3) = (1 + 10 + 3) / 3
   m.next(5) = (10 + 3 + 5) / 3
 */

class MovingAverage {
    private:
        int total_;
        int size_;
        queue<int> q_;

    public:
        /** Initialize your data structure here. */
        MovingAverage(int size) {
            total_ = 0;
            size_ = size;
        }

        double next(int val) {
            if (q_.size() == size_){
                total_ = total_ - q_.front();
                q_.pop(); 
            }

            q_.push(val);
            total_ += val;
            return (double)total_/q_.size();

        }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
