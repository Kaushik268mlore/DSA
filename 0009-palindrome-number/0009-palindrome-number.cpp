class Solution {
public:
    //O(n) solution
    // bool isPalindrome(int x) {
    //     string s=to_string(x);
    //     string r=s;
    //     reverse(s.begin(),s.end());
    //     return r==s;
    // }
    bool isPalindrome(int x) { //good way to check a number is a palindrome or not in O(logn) time.
        if(x<0||(x%10==0&&x!=0))return false;
        int reverse=0;
        while(x>reverse){// this is the condition that checks whether u are halfway yet or not
            reverse*=10;
            reverse+=x%10;
            x/=10;
        }
    return x==reverse||x==reverse/10;}
};