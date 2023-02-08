class Solution {
public:
    /*bool checkIfExist(vector<int>& arr) {//this code  couldn't cover the negative array valued cases as i was using the array as an hashmap  
        vector<int>freq(1000000,0);
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        int fl=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<size(arr);i++){
            if(freq[arr[i]]&&freq[2*arr[i]])fl++;
        }
        return fl>=1;
    }*/
    bool checkIfExist(vector<int>& arr){
        unordered_map<int,int>map;
        int n=size(arr);
        int zc=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=0)map[arr[i]]++;
            else zc++;
        }
        if(zc>1)return 1;
        for(int i=0;i<n;i++){
            if(map[arr[i]]&&map[2*arr[i]]||(map[arr[i]]&&map[arr[i]/2]&&!arr[i]&1))return true;
        }
    return 0;}
};