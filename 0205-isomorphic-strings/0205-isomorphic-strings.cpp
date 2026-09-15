class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int mp1[256]={0};
        int mp2[256]={0};

        for(int i=0;i<n;i++){
            char a=s[i];
            char b=t[i];
            
            if(mp1[a]!=mp2[b]){
                return false;
            }
            mp1[a]=i+1;
            mp2[b]=i+1;
        }
        return true;
    }
};