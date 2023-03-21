class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>m;
        for(char c:text)m[c]++;
        return min({m['a'],m['b'],m['l']/2,m['o']/2,m['n']});
    }
};