class Solution {
public:
//     amazing problem tbh ,enjoyed solving and also learnt a lot from this!!!!
  string longestDupSubstring(string S)
    {
        std::string_view longest;
        std::unordered_set<std::string_view> set; // here string_view is a class that has an operator that returns a pointer to the data , rather than the string
        size_t beg = 1;
        size_t end = S.size() - 1;
        while (beg <= end)// binary search on the length of the string 
        {
            auto len = beg + (end - beg) / 2;
            bool found = false;
            for (size_t i = 0; i != S.size() - len + 1; ++i)
            {
                const auto [it, inserted] = set.emplace(S.data() + i, len);//checks for any other substring's view who's length is ==len
                if (!inserted)
                {
                    found = true;
                    longest = *it;
                    break;   
                }
            }
            
            if (found)
                beg = len + 1;
            else
                end = len - 1;
            
            set.clear();      
        }
            
        return {longest.begin(), longest.end()};
    }
};