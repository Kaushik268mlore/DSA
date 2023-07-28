class Solution {
public:
    string reversePrefix(string word, char ch) {
        int id=find(word.begin(),word.end(),ch)-word.begin();
        // cout<<id<<endl;
        if(id==word.length())return word;
        reverse(word.begin(),word.begin()+id+1);
        return word;
    }
};