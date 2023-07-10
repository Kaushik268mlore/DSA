class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>res(num_people,0);
        int n=num_people;
        int i=0,ded=1;
        while(candies!=0){
            ded=min(candies,ded);
            res[i]+=ded;
            candies-=ded;
            ded++;
            i=(i+1)%n;
        }
    return res;}
};