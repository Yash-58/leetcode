class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int count=0;
        unordered_set<string> s;
        for(string x:words){
            string rev=x;
            reverse(rev.begin(),rev.end());
            if(s.find(rev)!=s.end()) count++;
            else s.insert(x);
        }
        return count;
    }
};