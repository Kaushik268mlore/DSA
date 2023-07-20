class Solution {
public:
//     very likely a stack problem..
//      
    // vector<int> asteroidCollision(vector<int>& arr) {
    //     int n=arr.size();
    //     vector<int>s;
    //     for(int i=0;i<n;i++){
    //         if(s.size()==0||(s.back()<0&&arr[i]<0)||(s.back()>0&&arr[i]>0))s.push_back(arr[i]);
    //         else {
    //             while(s.size()!=0&&s.back()<0&&arr[i]>0||s.back()>0&&arr[i]<0){
    //                 if(abs(s.back())==abs(arr[i]))s.pop_back();
    //                 else if(abs(s.back())<abs(arr[i])){
    //                     s.pop_back();
    //                     s.push_back(arr[i]);
    //                 }
    //                 else break;
    //             }
    //         }
    //     }
    // return s;}
            vector<int> asteroidCollision(vector<int>& asteroids) {
	            vector<int> res;
	            for(int a : asteroids) {
		        bool destroyed = false;
		        while(res.size() && res.back() > 0 && a < 0 && !destroyed) {
			        if(res.back() >= -a) destroyed = true;
			        if(res.back() <= -a) res.pop_back();
		        }
		        if(!destroyed) res.push_back(a);
	            }
	                return res;
                }
};