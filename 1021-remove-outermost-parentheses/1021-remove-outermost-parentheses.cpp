class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        string str="";
        int depth=0;

        for(char ch:s){
            if(ch=='('){
                if(depth>0){
                    str+=ch;
                }
                depth++;
            }
            else{
                depth--;
                if(depth>0){
                    str+=ch;
                }
            }
        }
        return str;
    }
};