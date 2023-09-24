class Solution {
public:
    int bagOfTokensScore(vector<int>& t, int power) {//two pointers approach O(nlogn)
        sort(t.begin(),t.end());
        int score=0;
        int i=0,j=t.size()-1;
        while(i<=j){
            if(t[i]<=power){
             score++;
            power-=t[i];
            i++;
            }
            else if(score>=1 and i<j){
                score--;
                power+=t[j--];
            }
            else break;
        }
        return score;
    }
};