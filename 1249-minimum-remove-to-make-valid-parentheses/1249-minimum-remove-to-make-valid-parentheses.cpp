class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        unordered_set<int>idx;

        for(int i=0;i<s.length();i++){
            char ch=s[i];

            if(ch=='('){
                st.push(i);
            }
           else if (ch == ')'){
                if(st.empty()){
                    idx.insert(i);
                }
                else{
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            idx.insert(st.top());
            st.pop();
        }
        string ans;
        for(int i=0;i<s.length();i++){
            if(!idx.contains(i)){
                ans+=s[i];
            }
        }
        return ans;
    }
};