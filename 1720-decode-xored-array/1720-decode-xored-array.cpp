class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>res(size(encoded)+1);
        res[0]=first;
        for(int i=0;i<size(encoded);i++){
            res[i+1]=res[i]^encoded[i];
        }
    return res;}
};