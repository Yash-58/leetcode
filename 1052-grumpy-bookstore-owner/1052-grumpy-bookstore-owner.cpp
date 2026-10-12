
class Solution {
public:
    int maxSatisfied(vector<int>& customers,
                     vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int satisfied = 0;

        // Customers already satisfied
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                satisfied += customers[i];
            }
        }

        // Extra satisfied customers in the first window
        int windowSum = 0;

        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                windowSum += customers[i];
            }
        }

        int maxExtra = windowSum;

        // Sliding window
        for (int i = minutes; i < n; i++) {
            if (grumpy[i] == 1) {
                windowSum += customers[i];
            }

            if (grumpy[i - minutes] == 1) {
                windowSum -= customers[i - minutes];
            }

            maxExtra = max(maxExtra, windowSum);
        }

        return satisfied + maxExtra;
    }
};