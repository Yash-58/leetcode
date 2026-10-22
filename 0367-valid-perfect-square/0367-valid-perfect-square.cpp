class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1 || num==0) return true;
        int lo=0;
        int hi=num;

        while(lo<hi){
            long long mid=lo+(hi-lo)/2;

            if(mid*mid==(long long)num) return true;
            else if(mid*mid>(long long)num) hi=mid;
            else lo=mid+1;
        }
        return false;
    }
};