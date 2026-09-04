class Solution {
public:
    void solve(string digits,int idx,string s,vector<string>&mapping,vector<string> &ans){
        if(idx==digits.size()){
            ans.push_back(s);
            return;
        }
        int digit=digits[idx]-'0';
        for(char ch:mapping[digit]){
            s.push_back(ch);

            solve(digits,idx+1,s,mapping,ans);

            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        vector<string>mapping={
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        solve(digits,0,"",mapping,ans);
        return ans;
        
    }
};