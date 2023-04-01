class Solution {
    // int numMatchingSubseq(string s, vector<string>& words) { //I wonder this implementation wasnt working , was a good use of the multiset
    //     unordered_multiset<char>main(s.begin(),s.end());
    //     int cnt=0;
    //     for(int i=0;i<words.size();i++){
    //         auto temp=main;
    //         bool flag=true;
    //         // for(int j=0;j<words[i].size();j++){
    //         //     if(temp.count(!words[i][j]))flag=false;
    //         //     else temp.erase(temp.find(words[i][j]));
    //         // }
    //         for(char c:words[i]){
    //             if(temp.count(c)==0)flag=false;
    //             else temp.erase(temp.find(c));
    //         }
    //         if(flag)cnt++;
    //     }
    // return cnt;}
        // okay just figured out that the relative order of the occurence of the substring also matters hence , this wont work, multiset is a hash map implementation and even using an iterator wont give us an order
private:                                //this infact is a much costlier implementation which on the other hand uses a bruteforce string matching algorithm , which is of O(n) and relative order is maintained
     bool help(string s,string word)
    {
        int k=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==word[k])k++;
            if(k==word.size())
                return true;
        }
        return false;
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int>m;
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            m[words[i]]++;
        }
        for(auto it:m)
        {
            if(help(s,it.first))
                ans+=it.second;
        }
        return ans;
    }
};