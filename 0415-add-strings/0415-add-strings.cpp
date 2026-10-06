class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1=num1.size()-1;
        int len2=num2.size()-1;
        int carry=0;

        string ans;
        while(len1>=0 || len2 >=0 || carry){
            int sum=carry;
            if(len1>=0){
                sum+=num1[len1--]-'0';
            }
            if(len2>=0){
                sum+=num2[len2--]-'0';
            }
            ans+=(sum%10)+'0';
            carry=sum/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};