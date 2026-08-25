class Solution {
public:
    int distributeCandies(vector<int>& candy) {
        unordered_set<int>s(candy.begin(),candy.end());
        int n=candy.size();
        int eat=n/2;
        if(s.size()>eat) return eat;
        else return s.size();

        
    }
};