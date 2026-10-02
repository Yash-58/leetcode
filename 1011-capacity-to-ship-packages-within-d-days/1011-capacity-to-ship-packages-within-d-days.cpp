class Solution {
public:

    bool check(int mid, vector<int>& weights, int days) {
        int count = 1;
        int capacity = mid;

        for(int i = 0; i < weights.size(); i++) {

            if(capacity >= weights[i]) {
                capacity -= weights[i];
            }
            else {
                count++;
                capacity = mid;
                capacity -= weights[i];
            }
        }

        return count <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int lo = 0;
        int hi = 0;

        for(int weight : weights) {
            lo = max(lo, weight);
            hi += weight;
        }

        while(lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if(check(mid, weights, days)) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};