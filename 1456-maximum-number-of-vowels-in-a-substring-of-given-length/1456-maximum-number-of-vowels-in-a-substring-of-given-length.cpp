class Solution {
public:
    int maxVowels(string s, int k) {
        int maxLen=0;
        int len=0;
        for(int i=0;i<k;i++){
           if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            len++;
           }
        }
        maxLen=len;
        for(int i=k;i<s.size();i++){
            if(s[i-k]=='a'||s[i-k]=='e'||s[i-k]=='i'||s[i-k]=='o'||s[i-k]=='u'){
                len--;
            }
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                len++;
            }
            maxLen=max(maxLen,len);
            if(maxLen==k){
                return k;
            }
        }
        return maxLen;
    }
};