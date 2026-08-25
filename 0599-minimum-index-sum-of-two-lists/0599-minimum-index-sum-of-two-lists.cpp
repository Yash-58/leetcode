class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int>mp;
        for(int i=0;i<list1.size();i++){
            mp[list1[i]]=i;
        }
         list1.clear();
        int Minsum=INT_MAX;
        for(int i=0;i<list2.size();i++){
            if(mp.count(list2[i])){
              int sum=mp[list2[i]]+i;
                if(sum<Minsum){
                    Minsum=sum;
                    list1.clear();
                    list1.push_back(list2[i]);
                }
                else if(sum==Minsum)
                 list1.push_back(list2[i]);
            }
        }
        return list1;
    }
};