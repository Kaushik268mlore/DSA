class Solution {
public://using lowerbpund of the success value /spell
    // we spell*potion>=success
    //instead we do search for the index where potion>=success/spell[i]
    //which would basically be looking for the lowerbound()
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        int n=potions.size();
        long long extr=potions[n-1];
        for(int i=0;i<spells.size();i++){
            long long prod=ceil(1.0*success/spells[i]);
            //if(prod>potions[n-1]){ans.push_back(0);continue;}//totally unnecessary
            int id=abs(lower_bound(potions.begin(),potions.end(),prod)-potions.end());
            ans.push_back(id);
        }
    return ans;}
};