class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> freq(26, 0);

        for (char ch : licensePlate) {
            if (isalpha(ch)) {
                freq[tolower(ch) - 'a']++;
            }
        }

        string ans = "";

        for (string word : words) {
            vector<int> count(26, 0);

            for (char ch : word) {
                count[ch - 'a']++;
            }

            bool valid = true;

            for (int i = 0; i < 26; i++) {
                if (count[i] < freq[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid && (ans.empty() || word.size() < ans.size())) {
                ans = word;
            }
        }

        return ans;
    }
};