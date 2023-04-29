class Solution {
public:
    string largestNumber(vector<int>& nums) {
        //okay this code fails a test case that has same first digits, i didnt think of the edge cases...lol
        // priority_queue<pair<int,string>>mp;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     string temp=to_string(nums[i]);
        //     mp.push({nums[i]%10,temp});
        // }
        // string str="";
        // for(int i=0;i<n;i++){
        //     string temp=mp.top().second;
        //     mp.pop();
        //     str+=temp;
        // }
        // return str;
        int n=nums.size();
        vector<string>arr;
        for(int i=0;i<n;i++){
            arr.push_back(to_string(nums[i]));
        }
        sort(arr.rbegin(),arr.rend(),[](string&a,string&b){
            return a+b<b+a;
        });
        string res="";
        for(string s:arr){
            res+=s;
        }
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
    return res;}
};