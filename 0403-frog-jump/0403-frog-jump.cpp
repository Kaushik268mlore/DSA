class Solution {
public:
    //cool DP problem , basically start out with drawing a recursive tree
    //then see what determines the next state and add them as parameters for the recursion
    //here the next state clearly depends on the next state...
    // my recursion aint working
    // unordered_map<int,bool>m;
    // bool helper(vector<int>&arr,int pos,int prev,int n) {
    //     // n=arr.size();
    //     if(m[pos]==false||pos>arr[n-1])return false;//breakpoints
    //     if(pos==arr[n-1])return true;
    //     bool res;
    //     if(pos==0)res=helper(arr,pos+1,1,n);
    //     else{
    //         if(prev-1>0)res=helper(arr,pos+prev-1,prev-1,n);
    //         if(res)return true;
    //         res=helper(arr,pos+prev,prev,n);
    //         if(res)return true;
    //         res=helper(arr,pos+prev+1,prev+1,n);
    //         if(res)return true;
    //     }
    //     return res;
    // }
    // bool canCross(vector<int>&arr){
    //     for(int i:arr){
    //         m[i]=true;
    //     }
    //     return helper(arr,0,1,arr.size());
    // }
    unordered_map<int,bool> mp;
    bool recursion(int pos, int prevStep, vector<int>& arr, int n, map<pair<int,int>,bool>& memo){

        if(mp[pos]== false || pos > arr[n-1]) return false;
        if(pos == arr[n-1]) return true;  
        if(memo.find({pos,prevStep}) != memo.end()) return memo[{pos,prevStep}];

        bool isPossible;

        if(pos==0){
            isPossible = recursion(pos+1,1,arr,n,memo);
        }
        else{
            if(prevStep-1>0) 
                isPossible = recursion(pos+(prevStep-1),prevStep-1,arr,n,memo);
            if(isPossible) return true;
            isPossible = recursion(pos+prevStep,prevStep,arr,n,memo);
            if(isPossible) return true;
            isPossible = recursion(pos+(prevStep+1),prevStep+1,arr,n,memo);
            if(isPossible) return true;
        }
        
        memo[{pos,prevStep}] = isPossible;
        return isPossible;

    }

    bool canCross(vector<int>& stones) {
        
        for(auto itr : stones){ 
            mp[itr] = true;
           
        }
        map<pair<int,int>,bool> memo;
        int n = stones.size();
        return recursion(0,1,stones,n,memo);
    }
};