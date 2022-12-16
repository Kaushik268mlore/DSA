class Solution {
public:
    int romanToInt(string s) {//hashmap solution
        unordered_map<char,int>map;
        int value=0;
        map['I']=1;
        map['V']=5;
        map['X']=10;
        map['L']=50;
        map['C']=100;
        map['D']=500;
        map['M']=1000;
        for(int i=0;i<s.length();i++){
            if(map[s[i]]<map[s[i+1]])value-=map[s[i]];
            else value+=map[s[i]];
        }
        return value;
    }
};