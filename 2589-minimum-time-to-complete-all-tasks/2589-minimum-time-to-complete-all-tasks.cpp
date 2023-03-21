// class Solution {
// public:
//     //mycurrent approach would be to sort the tasks based on their end time, and then maybe chech which ones
//     int findMinimumTime(vector<vector<int>>& tasks) {
//         sort(tasks.begin(),tasks.end(),[](const auto &e1,const auto &e2){
//             return e1[1]==e2[2]?e1[0]<e2[0]:e1[1]<e2[1];
//         });
//         unordered_map<int,bool>mp;//this stores which time is used
//         int count =0;
//         for(int i=0;i<tasks.size();i++){
//             int s=tasks[i][0],e=tasks[i][1],d=tasks[i][2];
//             int used=0;
//             for(int j=s;j<=e;j++) {//this is to utilise the already used time in the ith task , so that we dont use more time for the ith task than needed
//                 if(mp.count(j))used++;
//             }  
//             for(int t=e;used<d;t--){//we start assigning tasks from the end inorder to use it efficiently
//                 if(!mp.count(t)){ //here we need to take account only if there is a new time slice that wasn't used by the previous users
//                     used++;
//                     mp[t]=1;//we store that this time slice has been used 
//                     count++;
//                 }
//             }
//         }
//     return count;}
    
    
//     /// damnn i liked this problem for some reason and it was pretty challenging
// };
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](vector<int>& a,vector<int>& b){
            return (a[1]!=b[1])?a[1]<b[1]:a[0]<b[0];
        });
        unordered_map<int,bool> used;       // time_slice... used or not ... 
        
        int count=0;
        for(auto& task:tasks){
            int usedTime=0;
            for(int t=task[0];t<=task[1];t++)   if(used.count(t))   usedTime++;      // have used this time slice

            for(int t=task[1];usedTime<task[2];t--){
                if(!used.count(t)){         // this time slice is available
                    usedTime++;             // duration for which I run it
                    used[t]=1;              // use this timeslice
                    count++;                // time for which my computer is on 
                }
            }
        }
        return count;
    }
};
