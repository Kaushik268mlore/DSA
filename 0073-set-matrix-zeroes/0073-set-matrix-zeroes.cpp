class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        set<int>fi;//flag registers, so that if they exist then mark that row as 0
        set<int>fj;//flag register , so that if they exist then mark that column as 0
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j]==0){
                    fi.insert(i);
                    fj.insert(j);
                }
            }
        }
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(fi.find(i)!=fi.end()||fj.find(j)!=fj.end())m[i][j]=0;
            }
        }
    }
};