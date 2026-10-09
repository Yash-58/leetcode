
class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                open++;
            }
            else {
                // If the next character is also ')',
                // we already have a complete pair.
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                }
                else {
                    // Insert one ')' to complete the pair.
                    ans++;
                }

                // Match this pair with an opening bracket.
                if (open > 0) {
                    open--;
                }
                else {
                    // No opening bracket exists, insert '('.
                    ans++;
                }
            }
        }

        ans += 2 * open;

        return ans;
    }
};