class Solution {
public:
    int arrangeCoins(int n) {
        long long lo=1,hi=n;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            long long coin=mid*(mid+1)/2;

            if(coin==n){
                return mid;
            }
            else if(coin<n){
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return hi;
    }
};