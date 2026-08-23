class Solution {
public:
    bool closeStrings(string str1, string str2) {
        if(str1.size() != str2.size()) return false;
        unordered_map<char,int>mp1,mp2;
        for(int i=0;i<str1.size();i++){
            mp1[str1[i]]++;
            mp2[str2[i]]++;
        }
        for(auto x:mp1){
            char s=x.first;
            if(mp2.find(s) ==mp2.end()) return false;
        }
       unordered_map<int,int>h1,h2;
       for(auto x: mp1){
        int freq=x.second;
        h1[freq]++;
       }
       for(auto x: mp2){
        int freq=x.second;
        h2[freq]++;
       }

       for(auto x:h1){
            int s=x.first;
            if(h2.find(s) ==h2.end()) return false;
            if(h1[s]!=h2[s]) return false;
        }
      return true;
        
    }
};