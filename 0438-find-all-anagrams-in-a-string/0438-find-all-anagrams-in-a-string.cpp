class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();
        
        vector<int>ans;
        if(m>n) return ans;
        vector<int>sCount(26,0);
        vector<int>pCount(26,0);

        for(int i=0;i<m;i++){
            sCount[s[i]-'a']++;
            pCount[p[i]-'a']++;
        }
        if(sCount==pCount) ans.push_back(0);

        for(int i=1;i<=n-m;i++){
            sCount[s[i-1]-'a']--;
            sCount[s[i+m-1]-'a']++;

            if(sCount==pCount) ans.push_back(i);
        }
        return ans;
    }
};