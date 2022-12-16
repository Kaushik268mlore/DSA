class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& arr) {
        
        unordered_map<int, vector<int>> seats{};
        int result{n * 2};
        for(const auto& s:arr) seats[s[0]].push_back(s[1]);
        for(const auto& row:seats){
            bool le{}, mi{}, ri{};
            for(const auto s:row.second){
                if(s>1 && s<6) le = true;
                if(s>5 && s<10) ri = true;
                if(s>3 && s<8) mi = true;
            }
            if(le) --result;
            if(ri) --result;
            if(le && ri && !mi) ++result;
        }
        return result;
    }
    
};