class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int i=0,j=0;
        int sum=0;
        int count=0;
        while(j!=k){
            sum+=arr[j];
            j++;
        }
        if(sum/k>=threshold) count++;
        for(int start=k;start<n;start++){
             sum+=arr[start]-arr[i];
            //  sum-=arr[i];
             i++;
             if(sum/k>=threshold){
                count++;
             }
        }
       return count; 
    }
};