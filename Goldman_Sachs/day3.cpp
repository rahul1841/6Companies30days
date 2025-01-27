2526. Find Consecutive Integers from a Data Stream

class DataStream {
private:
    const int value_;
    const int k_;
    int count_ = 0;

public:
    DataStream(int value, int k) : value_(value), k_(k) {
    }
    
    bool consec(int num) {
        if (num == value_) ++count_; else count_ = 0;
        return count_ >= k_;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */


GFG Q1 - Number following a pattern

        int n = S.size();
        string result;
        stack<int> stk;

        for (int i = 0; i <= n; ++i) {
            stk.push(i + 1);

            if (i == n || S[i] == 'I') {
                while (!stk.empty()) {
                    result += to_string(stk.top());
                    stk.pop();
                }
            }
        }

        return result;


