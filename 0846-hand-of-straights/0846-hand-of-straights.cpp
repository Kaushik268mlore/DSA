class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {//a very weird hashing problem ,and possibly will be hard to come with the implementation for this problem
        int n=size(hand);
        if(n%k!=0)return false;
        map<int,int>mp;
        for(int i=0;i<n;i++)mp[hand[i]]++;
        for(;mp.size();){
            int first=mp.begin()->first;//because it sorts the keys(BST)
            int last=first+k-1;
            for(int i=first;i<=last;i++){
                if(mp.count(i)==0)return false;
                else if(--mp[i]==0)mp.erase(i);
            }
        }
    return true;}
};