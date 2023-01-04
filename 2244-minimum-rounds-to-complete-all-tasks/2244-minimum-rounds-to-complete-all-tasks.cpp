class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>map;
        for(auto i:tasks)map[i]++;
        int rounds=0;
        for(auto i:map){
            if(i.second==1)return -1;
            else if(i.second%3==0)rounds+=i.second/3;
            else rounds+=i.second/3 +1;
        }
    return rounds;}
};