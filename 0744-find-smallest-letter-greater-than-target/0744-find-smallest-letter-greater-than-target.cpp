class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {//binary search with definition
        int l=0,r=letters.size()-1;
        if(letters.back()<=target)return letters.front();
        while(l<r){
            int mid=l+(r-l)/2;
            if(letters[mid]>target){
                r=mid;
            }
            else l=mid+1;
            
        }
        return letters[l];
    }
};