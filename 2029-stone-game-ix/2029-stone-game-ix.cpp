class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt0=0,cnt1=0,cnt2=0;
        for(int x: stones){
            int n=x%3;
            if(n==0) cnt0++;
            else if(n==1) cnt1++;
            else cnt2++;
        }
        if(cnt0%2==0){
            return cnt1>=1 && cnt2>=1;
        }
        return cnt1-cnt2>2 || cnt2-cnt1>2;
    }
};