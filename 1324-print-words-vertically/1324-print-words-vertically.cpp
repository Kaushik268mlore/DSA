class Solution {
public:
    vector<string> printVertically(string s) {
        //at first look itself this looks like a stringstream problem because of spaces being involved in the question.
        vector<string>ws;
        istringstream iss(s);
        string word;
        int mxx=INT_MIN;
        while(iss>>word){
            ws.push_back(word);
            mxx=max(mxx,int(word.length()));
        }
        vector<string>res(mxx);
        for (int i=0;i<mxx;i++) {
            for (auto& w:ws)res[i]+=i<w.length()?w[i]:' ';
            while (res[i].back()==' ')res[i].pop_back();
        }
    return res;}
};