
class Solution {
public:
//Amazon
// 43
// LinkedIn
// 33
// Facebook
// 24
// Microsoft
// 22
// Bloomberg
// 14
// Spotify
// 13
// Apple
// 8
// Adobe
// 8
// Expedia
// 6
// Google
// 6
// Oracle
// 6
// VMware
// 5
// Cisco
// 5
// Intel
// 4
// Yandex
// 3
// tiktok
// 3
// Arista Networks
// 3
// Barclays
// 2
// ServiceNow
// 2
// Uber
// 2
// Goldman Sachs
// 2
// Booking.com
// 2
// Salesforce
// 2
// Netflix
// 2
// Dataminr
// 2
// tcs
// 2
   bool isValid(string s) {//we'll be using stack to track the parenthesis in the  string 
        stack<char> ss;
        for (auto c : s) {//traversing accross the string
            if (c == '(' || c == '{' || c == '[') {//the initial chars in the string have to be the left ones 
                ss.push(c);//in that case we push it to the stack 
            } else if (ss.empty() || !isMatch(ss.top(), c)){//then we check the coming characters to be the other pair or not 
                return false;
            } else { //if there is a match ,then we pop the stack , to remove the existing pair.
                ss.pop();
            }
        }
        return ss.empty();///if the parenthesis is valid then the result i.e the stack  is supposed to be empty.
    }
    bool isMatch(char c1, char c2) {//to check if the pairs are matched
        if ((c1 == '(' && c2 == ')') ||
            (c1 == '[' && c2 == ']') ||
            (c1 == '{' && c2 == '}'))
            return true;
        return false;
    }
};