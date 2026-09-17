class Solution {
public:
    char repeatedCharacter(string s) {
        bool seen[26]={false};

        for(char ch:s){
            int index=ch-'a';

            if(seen[index]){
                return ch;
            }
            seen[index]=true;
        }
        return '\0';
    }
};