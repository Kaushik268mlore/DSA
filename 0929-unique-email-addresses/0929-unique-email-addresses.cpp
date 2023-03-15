
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>set;
        for(string s:emails){
            string poss;
            for(char c:s){
              if(c=='+'||c=='@')break;
              if(c=='.')continue; 
              poss+=c;
            }
            poss+=s.substr(s.find('@'));
            set.insert(poss);
        }
    return set.size();
    }
};