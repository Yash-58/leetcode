class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if(n%2!=0) return false;
        int open=0,freqZ=0;
       //check left to right
        for(int i=0;i<n;i++){
            if(locked[i]=='0') freqZ++;
            else if(s[i]=='(') open++;
            else open--;
        if(freqZ+open<0) return false;
        }
        freqZ=0;
        open=0;
        //check right to left
        for(int i=n-1;i>=0;i--){
            if(locked[i]=='0') freqZ++;
            else if(s[i]==')') open++;
            else open--;
        if(open +freqZ<0) return false;
        }

        return true;
    }
};