
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> cnt1(26, 0), cnt2(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }

        if (cnt1 == cnt2) return true;

        int left = 0;

        for (int right = s1.size(); right < s2.size(); right++) {
            cnt2[s2[right] - 'a']++;
            cnt2[s2[left] - 'a']--;
            left++;

            if (cnt1 == cnt2) return true;
        }

        return false;
    }
};
