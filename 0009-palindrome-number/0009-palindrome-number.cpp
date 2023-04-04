class Solution {
public:
    //O(n) solution
    bool isPalindrome(int x) {
        string s=to_string(x);
        string r=s;
        reverse(s.begin(),s.end());
        return r==s;
    }
};