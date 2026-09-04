class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char ch : s) {

            if (ch == '(') {
                low++;
                high++;
            }
            else if (ch == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;   // '*' can act as ')'
                high++;  // '*' can act as '('
            }

            // Too many ')'
            if (high < 0) {
                return false;
            }

            // low cannot be negative
            low = max(low, 0);
        }

        return low == 0;
    }
};