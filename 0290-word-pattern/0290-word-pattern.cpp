class Solution {
public:
  /*
  "abba"
"dog dog dog dog" didnt work for this testcase
  bool wordPattern(string pattern, string s) {
        int n=pattern.size();
        unordered_map<char,string>map;
        int i=0;
        string word;
        istringstream in(s);
        for(word;in>>word;i++){
            if(map.find(pattern[i])!=map.end()){
                if(map[pattern[i]]!=word){return false;}
            }
             else {map[pattern[i]]=word;}

        }
        return true;
    }*/
    bool wordPattern(string t, string s){
        int n=t.size();
        unordered_map<char,int>m1;
        unordered_map<string,int>m2;
        istringstream in(s);
        int i=0;string word;
        for(word;in>>word;i++){
            if(i==n||m1[t[i]]!=m2[word])return false;
            else {
                m1[t[i]]=m2[word]=i+1;
            }
        }
        return i==n;
    }
};