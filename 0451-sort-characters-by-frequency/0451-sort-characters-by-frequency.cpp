class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;

        // Count frequency
        for(char ch : s) {
            mp[ch]++;
        }

        // Max heap: {frequency, character}
        priority_queue<pair<int, char>> pq;

        for(auto it : mp) {
            pq.push({it.second, it.first});
        }

        string ans = "";

        // Build answer
        while(!pq.empty()) {

            int freq = pq.top().first;
            char ch = pq.top().second;

            pq.pop();

            while(freq--) {
                ans += ch;
            }
        }

        return ans;
    }
};