class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int lo=0;
        int hi=n-1;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            int paper=n-mid;
            if(citations[mid]>=paper){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return n-lo;
    }
};