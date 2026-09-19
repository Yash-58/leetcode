class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo=1;
        int hi=arr.size()-1;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
                return mid;
            }
            else if(arr[mid-1]<arr[mid]){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return 0;
    }
};