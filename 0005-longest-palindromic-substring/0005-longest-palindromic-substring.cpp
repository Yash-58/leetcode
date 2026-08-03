class Solution {
public:
    vector<vector<int>> dp;

    bool isPalindrome(int i, int j, string &s) {

        if (i >= j)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] != s[j])
            return dp[i][j] = false;

        return dp[i][j] = isPalindrome(i + 1, j - 1, s);
    }

    string longestPalindrome(string s) {

        int n = s.size();
        dp.assign(n, vector<int>(n, -1));

        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                if (isPalindrome(i, j, s)) {

                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};