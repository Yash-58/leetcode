
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long count = 1;
        long long len = 1;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] - prices[i] == 1) {
                len++;
            } else {
                len = 1;
            }

            count += len;
        }

        return count;
    }
};
