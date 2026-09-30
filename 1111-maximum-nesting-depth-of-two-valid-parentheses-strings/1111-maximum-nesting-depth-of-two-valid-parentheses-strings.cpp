class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>v;
        int depth=0;

        for(char ch:seq){
            if(ch=='('){
                depth++;
                v.push_back((depth+1)%2);
            }
            else{
                v.push_back((depth+1)%2);
                depth--;
            }
        }
        return v;
    }
};