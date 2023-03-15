class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       int l=flowerbed.size();
        int cnt=0;
        if(l==1 and n==1 and flowerbed[0]==0)return true;
        for(int i=0;i<l;i++){
            if(flowerbed[i]==0){
                bool checkleft= i==0||flowerbed[i-1]==0;
                bool checkright= i==l-1||flowerbed[i+1]==0;
                if(checkleft and checkright){
                    flowerbed[i]=1;
                    cnt++;
                }
            }}
        return cnt>=n;
    }
};