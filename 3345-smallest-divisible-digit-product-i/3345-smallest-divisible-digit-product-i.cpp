class Solution {
public:
    int smallestNumber(int n, int t) {
        int num=n;
        while(true){
            int product=1;
            n=num;
            while(n){
                product *=n%10;
                n/=10;
            }
            if(product %t==0) break;
            else num++;
        }
        return num;
    }
};