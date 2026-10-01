class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<int>ans(k);
        if(arr[0]>x){
            for(int i=0;i<k;i++){
                ans[i]=arr[i];
            }
            return ans;
        }
        if(x>arr[n-1]){
            int i=n-1;
            int j=k-1;
            while(j>=0){
                ans[j]=arr[i];
                i--;
                j--;
            }
             return ans;
        }
        int lo=0;
        int hi=n-1;
        bool flag=false;
        int mid=-1;
        int t=0;
        while(lo<=hi){
             mid=lo+(hi-lo)/2;
            if(arr[mid]==x){
                flag=true;
                ans[t]=arr[mid];
                t++;
                break;
            }
            else if(arr[mid]<x){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        int lb=hi;
        int up=lo;
        if(flag==true){
             lb=mid-1;
             up=mid+1;
        }
        while(t<k && lb>=0 && up<=n-1){
            int d1=abs(x-arr[lb]);
            int d2=abs(x-arr[up]);
            if(d1<=d2){
                ans[t]=arr[lb];
                lb--;
            }
            else{
                ans[t]=arr[up];
                up++;
            }
            t++;
        }
        if(lb<0){
            while(t<k){
                ans[t]=arr[up];
                up++;
                t++;
            }
        }
        if(up>n-1){
            while(t<k){
                ans[t]=arr[lb];
                lb--;
                t++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};