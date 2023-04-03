class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {//this is a two pointer problem, pretty easy 
        int n=size(people)-1;
        int i=0,ans=0;
        sort(people.begin(),people.end());
        while(i<=n){
            ans++;
            if(people[i]+people[n]<=limit){
                i++;
            }
            n--;
            }
        return ans;
        
    }
};